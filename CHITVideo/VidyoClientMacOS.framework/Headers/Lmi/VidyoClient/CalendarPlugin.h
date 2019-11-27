/**
{file:
	{name: CalendarPlugin.h}
	{description: Definitions and interface for VidyoCalendar plug-in Library. }
	{copyright:
		(c) 2013-2016 Vidyo, Inc.,
		433 Hackensack Avenue,
		Hackensack, NJ  07601.
		All rights reserved.
		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.}
	{note:
		- Implementor Notes
			- All callbacks must not happen on calling thread.
			- All argument values must be persisted until the application returns from all callbacks.
			- After connect, plugin must ensure connection or access to the service stays alive.
				Within reasonable limits like if authentication changes we can't reconnect.
			- CalendarConnectedCallback will be also be issued when the plugins status on access
				to the underlying service changes.  See CalendarConnectedCallback notes for more details.
	}
}
*/
#ifndef CALENDAR_PLUGIN_H_
#define CALENDAR_PLUGIN_H_

#ifdef DLL_EXPORTS
	#define DLL_API __declspec(dllexport)
#elif __GNUC__ >= 4
	#define DLL_API __attribute__((visibility("default")))
#else
	#define DLL_API
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/* bool based on platform word */
#define CALENDAR_BOOL unsigned int
#define TRUE 1
#define FALSE 0

/* platform int based on platform word */
#define UINT unsigned int
#define INT int

#define UINT32 uint32_t
#define INT32  int32_t

/* Default structure sizes */
#define MEETING_ATTENDEE_EMAIL_SIZE 256
#define MEETING_ATTENDEE_NAME_SIZE 256

#define MEETING_SUBJECT_SIZE 256
#define MEETING_LOCATION_SIZE 256
#define MEETING_ID_SIZE 256
#define MEETING_TIME_SIZE 64

/**
{package:
	{name: VidyoCalendarPluginPackage}
	{parent: Lmi}
	{include: Lmi/VidyoClient/CalendarPlugin.h}
	{library: VidyoCalendarPluginLibrary}
	{description: The CalenderPlugin Interface Package}
}
*/

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
{type:
	{name: CalendarConnectCode}
	{parent: VidyoCalendarPluginPackage}
	{description: Return codes for connection status of the Calendar.}
	{value:
		{name: CALENDAR_CONNECTCODE_OK}
		{description: The operation was successful.}}
	{value:
		{name: CALENDAR_CONNECTCODE_NoService}
		{description: The service is not available.}}
	{value:
		{name: CALENDAR_CONNECTCODE_ConnectionLost}
		{description: The connection was lost.}}
	{value:
		{name: CALENDAR_CONNECTCODE_ConnectionTimeout}
		{description: The connection timed out.}}
	{value:
		{name: CALENDAR_CONNECTCODE_InvalidCredentials}
		{description: Invalid credentials where used.}}
	{value:
		{name: CALENDAR_CONNECTCODE_InvalidCalendarId}
		{description: An invalid calendar id was used.}}
	{value:
		{name: CALENDAR_CONNECTCODE_InvalidPermissions}
		{description: Invalid permissions occurred trying to connect to the calendar resource.}}
	{value:
		{name: CALENDAR_CONNECTCODE_GeneralError}
		{description: A general error occurred.}}
}
*/
typedef enum
{
	CALENDAR_CONNECTCODE_OK = 0,
	CALENDAR_CONNECTCODE_NoService = 1,
	CALENDAR_CONNECTCODE_ConnectionFailed = 2,
	CALENDAR_CONNECTCODE_ConnectionLost = 3,
	CALENDAR_CONNECTCODE_ConnectionTimeout = 4,
	CALENDAR_CONNECTCODE_InvalidCredentials = 5,
	CALENDAR_CONNECTCODE_InvalidCalendarId = 6,
	CALENDAR_CONNECTCODE_InvalidPermissions = 7,
	CALENDAR_CONNECTCODE_GeneralError = 8
} CalendarConnectCode;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
{type:
	{name: CalendarCapability}
	{parent: VidyoCalendarPluginPackage}
	{description: Keys to various capabilities of the CalendarPlugin.}
	{note: Renamed this enumerated type from "CalendarCapabilityKey", in order to conform to naming conventions,
		while preserving the names of the enumerated values.}
	{value:
		{name: CALENDAR_CAPABILITY_NULL}
		{description: The termination key. Has no associated value.}}
	{value:
		{name: CALENDAR_CAPABILITY_SSO}
		{description: The Calendar service supports authentication by SSO. Has no value.}}
	{value:
		{name: CALENDAR_CAPABILITY_WebUrl}
		{description: The Calendar service supports web auth. Value is a predicted url based on the environment.}}
	{value:
		{name: CALENDAR_CAPABILITY_WebUrlAutodiscovery}
		{description: The Calendar service supports discovering the web url based on the username. Has no value.}}
	{value:
		{name: CALENDAR_CAPABILITY_Username}
		{description: The Calendar service supports authentication with username. Value is a predicted username based on the environment.}}
	{value:
		{name: CALENDAR_CAPABILITY_Password}
		{description: The Calendar service supports authentication by password. Has no value.}}
}
*/
typedef enum
{
	CALENDAR_CAPABILITY_NULL = 0,
	CALENDAR_CAPABILITY_SSO = 1,
	CALENDAR_CAPABILITY_WebUrl = 2,
	CALENDAR_CAPABILITY_WebUrlAutodiscovery = 3,
	CALENDAR_CAPABILITY_Username = 4,
	CALENDAR_CAPABILITY_Password = 5
} CalendarCapability;

/* Alias for practical reasons:
  - 'CalendarCapabilityKey' did not conform to DocBlock naming conventions for enums,
    but other code references it, so we need to preserve its name, at least for now.
  - 'CalendarCapability' (and its enum values) conform to DocBlock naming conventions.
*/
typedef CalendarCapability CalendarCapabilityKey;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Does not follow Vidyo SDK naming conventions, but likely referenced by other code.
{type:
	{name: VidyoCalendarPluginStatus}
	{parent: VidyoCalendarPluginPackage}
	{description: Return codes for CalendarPlugin CONSTRUCTION.}
	{value:
		{name: VIDYO_CALENDARPLUGIN_STATUS_OK}
		{description: The plugin was successfully constructed.}}
	{value:
		{name: VIDYO_CALENDARPLUGIN_STATUS_ERROR}
		{description: An error occurred.}}
	{value:
		{name: VIDYO_CALENDARPLUGIN_STATUS_UNAVAILABLE}
		{description: The underlying service is unavailable.}}
	{value:
		{name: VIDYO_CALENDARPLUGIN_STATUS_NOT_STARTED}
		{description: The underlying service is not started.}}
	{value:
		{name: VIDYO_CALENDARPLUGIN_STATUS_INVALID_PERMISSIONS}
		{description: Invalid permissions occurred trying to construct the calendar resource.}}
}
*/
typedef enum
{
	VIDYO_CALENDARPLUGIN_STATUS_OK = 0,
	VIDYO_CALENDARPLUGIN_STATUS_ERROR = 1,
	VIDYO_CALENDARPLUGIN_STATUS_UNAVAILABLE = 2,
	VIDYO_CALENDARPLUGIN_STATUS_NOT_STARTED = 3,
	VIDYO_CALENDARPLUGIN_STATUS_INVALID_PERMISSIONS = 4,
} VidyoCalendarPluginStatus;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
{type:
	{name: MeetingSearchResult}
	{parent: VidyoCalendarPluginPackage}
	{description: Search Result Enumerations.}
	{value:
		{name: MEETING_SEARCHRESULT_OK}
		{description: Search resulted in success with records.}
	}
	{value:
		{name: MEETING_SEARCHRESULT_NoRecords}
		{description: Search resulted in success but no records.}
	}
	{value:
		{name: MEETING_SEARCHRESULT_NoResponse}
		{description: Search received no response.}
	}
	{value:
		{name: MEETING_SEARCHRESULT_MiscLocalError}
		{description: Search resulted in a local error.}
	}
	{value:
		{name: MEETING_SEARCHRESULT_MiscRemoteError}
		{description: Search resulted in a remote error.}
	}
}
*/
typedef enum
{
	MEETING_SEARCHRESULT_OK = 0,
	MEETING_SEARCHRESULT_NoRecords = 1,
	MEETING_SEARCHRESULT_NoResponse = 2,
	MEETING_SEARCHRESULT_MiscLocalError = 3,
	MEETING_SEARCHRESULT_MiscRemoteError = 4
} MeetingSearchResult;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Does not follow Vidyo SDK naming conventions, but likely referenced by other code.
{type:
	{name: MeetingAttendeeRole}
	{parent: VidyoCalendarPluginPackage}
	{description: Meeting attendeeRoles.}
	{value:
		{name: MEETING_ATTENDEE_ROLE_CHAIR}
		{description: The attendee's role is Meeting Chair.}}
	{value:
		{name: MEETING_ATTENDEE_ROLE_REQUIRED}
		{description: The attendee's role is Required.}}
	{value:
		{name: MEETING_ATTENDEE_ROLE_OPTIONAL}
		{description: The attendee's role is Optional.}}
	{value:
		{name: MEETING_ATTENDEE_ROLE_INFORMATIONAL}
		{description: The attendee's role is Informational.}}
}
*/
typedef enum
{
	MEETING_ATTENDEE_ROLE_CHAIR = 0,
	MEETING_ATTENDEE_ROLE_REQUIRED = 1,
	MEETING_ATTENDEE_ROLE_OPTIONAL = 2,
	MEETING_ATTENDEE_ROLE_INFORMATIONAL = 3
} MeetingAttendeeRole;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Does not follow Vidyo SDK naming conventions, but likely referenced by other code.
{type:
	{name: MeetingAttendeeStatus}
	{parent: VidyoCalendarPluginPackage}
	{description: Meeting Attendee status.}
	{value:
		{name: MEETING_ATTENDEE_STATUS_NEEDSACTION}
		{description: The attendee needs action.}}
	{value:
		{name: MEETING_ATTENDEE_STATUS_ORGANIZED}
		{description: The attendee organized the meeting.}}
	{value:
		{name: MEETING_ATTENDEE_STATUS_ACCEPTED}
		{description: The attendee accepted the meeting.}}
	{value:
		{name: MEETING_ATTENDEE_STATUS_DECLINED}
		{description: The attendee declined the meeting.}}
	{value:
		{name: MEETING_ATTENDEE_STATUS_TENTATIVE}
		{description: The attendee tentatively accepted the meeting.}}
	{value:
		{name: MEETING_ATTENDEE_STATUS_DELEGATED}
		{description: The attendee delegated the meeting.}}
}
*/
typedef enum
{
	MEETING_ATTENDEE_STATUS_NEEDSACTION = 0,
	MEETING_ATTENDEE_STATUS_ORGANIZED = 1,
	MEETING_ATTENDEE_STATUS_ACCEPTED = 2,
	MEETING_ATTENDEE_STATUS_DECLINED = 3,
	MEETING_ATTENDEE_STATUS_TENTATIVE = 4,
	MEETING_ATTENDEE_STATUS_DELEGATED = 5
} MeetingAttendeeStatus;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
{type:
	{name: CalString}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: String helper. }
		{p: String helper for CalendarPlugin objects. CalString's are immutable. }
		{p: The CalString implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _CalString CalString;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
{type:
	{name: MeetingAttendee}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: Meeting Attendee }
		{p: An object representing the meeting attendee. }
		{p: The MeetingAttendee implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _MeetingAttendee MeetingAttendee;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Conflicts with 'Meeting' declared by VidyoClient API (see "VidyoMeeting.h").
{type:
	{name: Meeting}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: Meeting  }
		{p: An object representing a meeting. }
		{p: The Meeting implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _Meeting Meeting;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
{type:
	{name: MeetingList}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: Meeting List }
		{p: An object representing a list of meeting returned by a search result. }
		{p: The MeetingList implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _MeetingList MeetingList;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Conflicts with 'Calendar' declared by Vidyo SDK (see "LmiCalendar.h").
{type:
	{name: Calendar}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: Calendar }
		{p: An object representing the remote calendar. }
		{p: The Calendar implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _Calendar Calendar;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
{type:
	{name: CalendarDateTime}
	{parent: VidyoCalendarPluginPackage}
	{description:
		{p: CalendarDateTime }
		{p: An object representing a date and time. }
		{p: The CalendarDateTime implementation is up to the CalendarPlugin implementor. }
	}
}
*/
typedef struct _CalendarDateTime CalendarDateTime;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'Calendar', whose DocBlock declaration was disabled due to a name conflict.
	- Revisit this DocBlock declaration after the problems with 'Calendar' itself are resolved.
	{callback:
		{name: CalendarConnectedCallback}
		{parent: VidyoCalendarPluginPackage}
		{description: Called under the following conditions:
				- To notify layer above that the CalendarConnect call has completed.
				- Plugin is in a transient state while trying to regain access to the underlying service.
					- Result codes will reflect the issue
					- OK will be returned once access to the service is restored.
		 Notes:
		   - Keep connected to the external system if connection is lost. Outlook, ical office 365
		   - When connection is lost this callback will be issues with ConnectionLost or Timeout
		   - If connection cannot be re-establish because of too many tries NoService
		   - When connection is established or re-established this callback will be sent with OK
		}
		{prototype: void (*CalendarConnectedCallback)(Calendar* calendar, CalendarConnectCode result, CalString * resultDetails, void* appData)}
		{parameter:
			{name: calendar}
			{description: An object representing the remote calendar.}}
		{parameter:
			{name: result}
			{description: Result code for the connection.}}
		{parameter:
			{name: resultDetails}
			{description: Descriptive text for the result.}}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
	}
*/
typedef void (*CalendarConnectedCallback)(Calendar* calendar, CalendarConnectCode result, CalString * resultDetails, void* appData);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'Calendar', whose DocBlock declaration was disabled due to a name conflict.
	- Revisit this DocBlock declaration after the problems with 'Calendar' itself are resolved.
	{callback:
		{name: CalendarDisconnectCallback}
		{parent: VidyoCalendarPluginPackage}
		{description: Notify layer above that the disconnect has completed.}
		{prototype: void (*CalendarDisconnectCallback)(Calendar* calendar, CalendarConnectCode result, CalString * resultDetails, void* appData)}
		{parameter:
			{name: calendar}
			{description: An object representing the remote calendar.}}
		{parameter:
			{name: result}
			{description: Result code for the disconnection.}}
		{parameter:
			{name: resultDetails}
			{description: Descriptive text for the result.}}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
	}
*/
typedef void (*CalendarDisconnectCallback)(Calendar* calendar, CalendarConnectCode result, CalString * resultDetails, void* appData);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'Calendar', whose DocBlock declaration was disabled due to a name conflict.
	- Revisit this DocBlock declaration after the problems with 'Calendar' itself are resolved.
	{callback:
		{name: CalendarGetCapabilitiesCallback}
		{parent: VidyoCalendarPluginPackage}
		{description: Notify layer above of plugin-specific calendar capabilities. This can be called before CalendarConnect.}
		{prototype: void (*CalendarGetCapabilitiesCallback)(Calendar* calendar, CalendarCapabilityKey* keys, void** values, void* appData)}
		{parameter:
			{name: calendar}
			{description: An object representing the remote calendar.}}
		{parameter:
			{name: keys}
			{description: String of capability keys terminated by a null capability element. The plugin should return an array of all the elements it supports if requestedCapabilities is NULL. Certain capabilities have values as documented. If a capability is passed in requestedCapabilities, it should have its value set in values. If requestedCapabilities is set, the keys returned must be a SUBSET of the requestedCapabilities.}}
		{parameter:
			{name: values}
			{description: NULL means empty. Only set if requestedCapabilities is set on GetCapabilities(). Array of values associated with each key. Indices correspond with keys.}}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
	}
*/
typedef void (*CalendarGetCapabilitiesCallback)(Calendar* calendar, CalendarCapabilityKey* keys, CalString** values, void* appData);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
	{type:
		{name: MeetingCallbacks}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define meeting related callbacks.
			This structure should be accessed directly. All callbacks must be defined.}
		{member:
			{callback:
			{name: CalendarSearchMeetingResultsCallback}
			{type: bool () (Calendar* calendar, MeetingSearchResult searchResult, const MeetingList* meetingData, int numRecords, void* appData)}
			{description: This callback is called when a meeting search has been completed.  The search result indicates whether there were any issues
							retrieving the elements returned.
			}
			{returns: TRUE if meetingData and all it's Meetings should be considered released by the application
			 returns: FALSE if meetingData and all it's Meetings should be considered held by application. Application must explicitly release the MeetingList    }
			}
		}
		{member:
			{name: CalendarMeetingReminderCallback}
			{type: void () (Calendar* calendar, const CalString *meetingId, const Meeting* meetingData, void* appData)
			{description: This callback is called when a meeting is due.}
			{returns: TRUE if Meeting should be considered released by the application }
			 returns: FALSE if Meeting should be considered held by the application. The application must explicitly release the Meeting }
			}
		{member:
			{name: CalendarMeetingCreatedCallback}
			{type: void () (Calendar* calendar, const Meeting* meetingData, void* appData)
			{description: This callback is called when a meeting is created.}
			{returns: TRUE if Meeting should be considered released by the application }
			 returns: FALSE if Meeting should be considered held by the application. The application must explicitly release the Meeting }
			}
		{member:
			{name: CalendarMeetingUpdatedCallback}
			{type: void () (Calendar* calendar, const Meeting* meetingData, void* appData)
			{description: This callback is called when a meeting is updated.}
			{returns: TRUE if Meeting should be considered released by the application }
			 returns: FALSE if Meeting should be considered held by the application. The application must explicitly release the Meeting }
			 }
		{member:
			{name: CalendarMeetingRemovedCallback}
			{type: void () (Calendar* calendar, const Meeting* meetingData, void* appData)
			{description: This callback is called when a meeting is removed.}
			{returns: TRUE if Meeting should be considered released by the application }
			 returns: FALSE if Meeting should be considered held by the application. The application must explicitly release the Meeting }
			}
		{member:
			{name: CalendarSeriesUpdateCallback}
			{type: void () (Calendar* calendar, const Meeting* meeting, void* appData)}
			{description: This callback is called when there is an update to a meeting that is a part of a series. Rather than doing a reconstruction of the series in the plugin, the application should listen here and perform a new search.}}
	}
*/
typedef struct _MeetingCallbacks
{
	CALENDAR_BOOL (*CalendarSearchMeetingResultsCallback)(Calendar* calendar, MeetingSearchResult searchResult, const MeetingList* meetingData, UINT numRecords, void* appData);
	CALENDAR_BOOL (*CalendarMeetingReminderCallback)(Calendar* calendar, const CalString* meetingId, const Meeting* meetingData, void* appData);
	CALENDAR_BOOL (*CalendarMeetingCreatedCallback)(Calendar* calendar, const Meeting* meetingData, void* appData);
	CALENDAR_BOOL (*CalendarMeetingUpdatedCallback)(Calendar* calendar, const Meeting* meetingData, void* appData);
	CALENDAR_BOOL (*CalendarMeetingRemovedCallback)(Calendar* calendar, const Meeting* meetingData, void* appData);
	void (*CalendarSeriesUpdateCallback)(Calendar* calendar, const Meeting* meetingData, void* appData);
} MeetingCallbacks;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
	{type:
		{name: MeetingAttendeePlugin}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define the meeting attendee accessors.
			This structure should be accessed directly. All members must be defined.}
		{member:
			{name: MeetingAttendeeGetName}
			{type: const CalString* () (const MeetingAttendee* m)}
			{description: This function is called to get an attendee's name.}}
		{member:
			{name: MeetingAttendeeGetEmail}
			{type: const CalString* () (const MeetingAttendee* m)}
			{description: This function is called to get an attendee's e-mail address.}}
		{member:
			{name: MeetingAttendeeGetRole}
			{type: MeetingAttendeeRole () (const MeetingAttendee* m)}
			{description: This function is called to get an attendee's role.}}
		{member:
			{name: MeetingAttendeeGetStatus}
			{type: MeetingAttendeeGetStatus () (const MeetingAttendee* m)}
			{description: This function is called to get an attendee's status.}}
	}
*/
typedef struct _MeetingAttendeePlugin
{
	const CalString* (*MeetingAttendeeGetName)(const MeetingAttendee* m);
	const CalString* (*MeetingAttendeeGetEmail)(const MeetingAttendee* m);
	MeetingAttendeeRole (*MeetingAttendeeGetRole)(const MeetingAttendee* m);
	MeetingAttendeeStatus (*MeetingAttendeeGetStatus)(const MeetingAttendee* m);
} MeetingAttendeePlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
	{type:
		{name: CalendarDateTimePlugin}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define the calendar date time accessors.  Timezone must be GMT.
			This structure should be accessed directly. All members must be defined.}
		{member:
			{name: CalendarDateTimeConstruct}
			{type: CalendarDateTime* () (UINT32 year, UINT32 month, UINT32 day, UINT32 hour, UINT32 minutes, UINT32 seconds)}
			{description: This funciton is called to construct a calendar date time.}}
		{member:
			{name: CalendarDateTimeDestruct}
			{type: void () (CalendarDateTime* datetime)}
			{description: This function is called to destruct a calendar date time.}}
		{member:
			{name: CalendarDateTimeGetYear}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the year.}}
		{member:
			{name: CalendarDateTimeGetMonth}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the month.}}
		{member:
			{name: CalendarDateTimeGetDay}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the day.}}
		{member:
			{name: CalendarDateTimeGetHour}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the hour.}}
		{member:
			{name: CalendarDateTimeGetMinute}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the minute.}}
		{member:
			{name: CalendarDateTimeGetSecond}
			{type: UINT32 () (CalendarDateTime* datetime)}
			{description: This function is called to get the second.}}
	}
*/
typedef struct _CalendarDateTimePlugin
{
	CalendarDateTime* (*CalendarDateTimeConstruct)(UINT32 year, UINT32 month, UINT32 day, UINT32 hour, UINT32 minutes, UINT32 seconds);
	void (*CalendarDateTimeDestruct)(CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetYear)(const CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetMonth)(const CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetDay)(const CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetHour)(const CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetMinute)(const CalendarDateTime* datetime);
	UINT32 (*CalendarDateTimeGetSecond)(const CalendarDateTime* datetime);
} CalendarDateTimePlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
	{type:
		{name: MeetingListPlugin}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define the meeting list accessors.
			This structure should be accessed directly. All members must be defined.}
		{member:
			{name: MeetingListGetSize}
			{type: UINT () (MeetingList* m)}
			{description: This function is called to get the size of the meeting list.}}
		{member:
			{name: MeetingListGetMeeting}
			{type: const Meeting* () (MeetingList* m, UINT pos)}
			{description: This function is called to get the meeting at the specified position.}
			{note: Assuming a zero based position offset on retreival of the items.}}
	}
*/
typedef struct _MeetingListPlugin
{
	UINT (*MeetingListGetSize)(const MeetingList* m);
	const Meeting* (*MeetingListGetMeeting)(const MeetingList* m, UINT pos);
} MeetingListPlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
	{type:
		{name: CalStringPlugin}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define the calendar string accessors.
			This structure should be accessed directly. All members must be defined.}
		{member:
			{name: CalStringConstruct}
			{type: CalString* () (const char* cstring, const UINT length)}
			{description: This function is called to construct a calendar string.}}
		{member:
			{name: CalStringDestruct}
			{type: void () (CalString* string)}
			{description: This function is called to destruct a calendar string.}}
		{member:
			{name: CalStringGetLength}
			{type: UINT () (const CalString* string)}
			{description: This function is called to get the length of the calendar string.}}
		{member:
			{name: CalStringGetCStr}
			{type: const char* () (const CalString* string)}
			{description: This function is called to C char pointer associated with the calendar string.}}
	}
*/
typedef struct _CalStringPlugin
{
	CalString* (*CalStringConstruct)(const char* cstring, const UINT length);
	void (*CalStringDestruct)(CalString* string);
	UINT (*CalStringGetLength)(const CalString* string);
	const char* (*CalStringGetCStr)(const CalString* string);
} CalStringPlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
	{type:
		{name: MeetingPlugin}
		{parent: VidyoCalendarPluginPackage}
		{description: Structure used to define the meeting accessors.
					This structure should be accessed directly. All members must be defined.
					The returned CalString and CalendarDateTime objects in getters need to be destructed when user is done with them.
					The objects returned from the getters will only exist while the meeting exists.
		}
		{member:
			{name: MeetingGetId}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting id.}}
		{member:
			{name: MeetingGetStartTime}
			{type: const CalendarDateTime* () (const Meeting* meeting)}
			{description: This function is called to get the meeting start time.  The timezone must be GMT.}}
		{member:
			{name: MeetingGetEndTime}
			{type: const CalendarDateTime* () (const Meeting* meeting)}
			{description: This function is called to get the meeting end time.  The timezone must be GMT.}}
		{member:
			{name: MeetingGetOwnerName}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting owner name.}}
		{member:
			{name: MeetingGetOwnerEmail}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting owner e-mail address.}}
		{member:
			{name: MeetingGetSubject}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting subject.}}
		{member:
			{name: MeetingGetLocation}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting location.}}
		{member:
			{name: MeetingGetBody}
			{type: const CalString* () (const Meeting* meeting)}
			{description: This function is called to get the meeting body.}}
		{member:
			{name: MeetingGetAttendeeListSize}
			{type: UINT () (const Meeting* meeting)}
			{description: This function is called to get the size of the attendee list.}}
		{member:
			{name: MeetingGetAttendee}
			{type: const MeetingAttendee* () (const Meeting* meeting, UINT32 pos)}
			{description: This function is called to get the attendee at the specified position.}}
	}
*/
typedef struct _MeetingPlugin
{
	const CalString* (*MeetingGetId)(const Meeting* meeting);
	const CalendarDateTime* (*MeetingGetStartTime)(const Meeting* meeting);
	const CalendarDateTime* (*MeetingGetEndTime)(const Meeting* meeting);
	const CalString* (*MeetingGetOwnerName)(const Meeting* meeting);
	const CalString* (*MeetingGetOwnerEmail)(const Meeting* meeting);
	const CalString* (*MeetingGetSubject)(const Meeting* meeting);
	const CalString* (*MeetingGetLocation)(const Meeting* meeting);
	const CalString* (*MeetingGetBody)(const Meeting* meeting);
	UINT (*MeetingGetAttendeeListSize)(const Meeting* meeting);
	const MeetingAttendee* (*MeetingGetAttendee)(const Meeting* meeting, const UINT32 pos);
} MeetingPlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
	{type:
		{name: CalendarPlugin}
		{parent: VidyoCalendarPluginPackage}
		{include: Lmi/VidyoClient/CalendarPlugin.h}
		{description: Structure used to define the calendar plugin.
			This structure should be accessed directly. All members must be defined.}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarConstruct}
			{type: Calendar* (*CalendarConstruct)(MeetingCallbacks* callbacks, void* appData)}
			{description: This function is called to construct a calendar plugin.
				The plugin must use the callbacks set here to indicate status.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarGetCapabilities}
			{type: CALENDAR_BOOL (*CalendarGetCapabilities)(Calendar* calendar, CalendarCapabilityKey* requestedCapabilities, CalendarGetCapabilitiesCallback getCapsCallback)}
			{description: Get plugin-specific calendar capabilities. This can be called before CalendarConnect. requestedCapabilities causes at most those capabilities to return their values if the plugin supports it.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarSetProfile}
			{type: CALENDAR_BOOL (*CalendarSetProfile)(Calendar* calendar, CalString* profile, CalString* profilePassword )}
			{description: This function is called to optional profile information for calendaring systems which allow multiple profiles. Specifically Outlook connections.
				The plugin must use the callbacks set here to indicate status.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarSetPollingInterval}
			{type: CALENDAR_BOOL (*CalendarSetPollingInterval)(Calendar* calendar, const unsigned int pollingIntervalSeconds )}
			{description: This function is called to specify a polling interval in seconds, for the plugin to use when polling for events against the calendar resource.
				* Must be set prior to connect
				* Default value will be 30 seconds if this call is not made prior to the connect.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarSetSingleSignOn}
			{type: CALENDAR_BOOL (*CalendarSetUseSSO)(Calendar* calendar, CALENDAR_BOOL sso)}
			{description: This function is called to tell the calendaring system whether to use single signon or the user password. The implementation may ignore it.
				The plugin must use the callbacks set here to indicate status.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarDestruct}
			{type: void () (Calendar* calendar)}
			{description: This function is called to destruct a calendar plugin.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarConnect}
			{type: CALENDAR_BOOL () (Calendar* calendar, CalendarConnectedCallback connectCallback)}
			{description: This function is called to connect the calendar plugin.
				* The plugin must call the connectCallback with the result.
				* The plugin will be considered connected upon success connection until disconnect is called.
				* The plugin will ensure that service is connected until disconnect is called. See ConnectedCallback.
				* When connection status changes after a successful connect the ConnectedCallback will be called with representing what has happened.
		 }}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarDisconnect}
			{type: CALENDAR_BOOL () (Calendar* calendar, CalendarDisconnectCallback disconnectCallback)}
			{description: This function is called to connect the calendar plugin.
				The plugin must call the disconnectCallback with the result.}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarSearchMeetings}
			{type: CALENDAR_BOOL () (Calendar* calendar, const CalString* searchString, const CalendarDateTime* beginDateTime, const CalendarDateTime* endDateTime, int index, int pageSize)}
			{description: This function is called to search for meetings.
				The plugin must call the SearchMeetingResultsCallback in the MeetingsCallbacks with the result.
				Implementation Notes:
				 - Each call to this method will establish a date time range, based on the begin and end date, that that the plugin
						must maintain until the next method call.
				 - The date time range, along with the search string value (if not empty), will be applied to meeting events and actions as follows:
					* Subsequent searches will establish a new date time range, as well as the search string filter, and clear the prior values.
					* The most current date time range and search string criteria must be applied to all actions and events that occur for a meeting.
						If the meeting action or event falls within the range and search criteria, then the plugin must issue the necessary
						callback for the event, otherwise, no callback will be triggered (see MeetingCallbacks for related API calls).
				 - The searchString shall be used to substring match meetings on the following fields:
					* Subject
					* Location
					* Body
					* Meeting Owner email and name
					* Required attendees name and email
					* Optional attendees name and email
				}}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarReleaseMeetingList}
			{type: CALENDAR_BOOL () (Calendar* calendar, MeetingList * meetingList)}
			{description: This function is called to release a meetingList object and all it's meetings. }
			{returns: TRUE if MeetingList is known and released. FALSE if MeetingList is unknown.}
		}
		{member:
			{parent: CalendarPlugin}
			{name: CalendarReleaseMeeting}
			{type: CALENDAR_BOOL () (Calendar* calendar, Meeting * meeting)}
			{description: This function is called to release a meeting. }
			{returns: TRUE if Meeting is known and released. FALSE if Meeting is unknown.}
		}
	}
*/
typedef struct _CalendarPlugin
{
	Calendar* (*CalendarConstruct)(MeetingCallbacks* callbacks, void* appData);
	void (*CalendarDestruct)(Calendar* calendar);
	CALENDAR_BOOL (*CalendarGetCapabilities)(Calendar* calendar, CalendarCapabilityKey* requestedCapabilities, CalendarGetCapabilitiesCallback getCapsCallback);
	CALENDAR_BOOL (*CalendarSetPollingInterval)(Calendar* calendar, const unsigned int pollingIntervalSeconds );
	CALENDAR_BOOL (*CalendarSetProfile)(Calendar* calendar, const CalString* profile, const CalString* profilePassword );
	CALENDAR_BOOL (*CalendarSetUseSSO)(Calendar* calendar, const CALENDAR_BOOL sso);
	CALENDAR_BOOL (*CalendarConnect)(Calendar* calendar, const CalString* user,  const CalString* password, const CalString* calendarName, const CalString* webServiceUrl, CalendarConnectedCallback connectCallback);
	CALENDAR_BOOL (*CalendarDisconnect)(Calendar* calendar, CalendarDisconnectCallback disconnectCallback);
	CALENDAR_BOOL (*CalendarSearchMeetings)(Calendar* calendar, const CalString* searchString, const CalendarDateTime* beginDateTime, const CalendarDateTime* endDateTime, const UINT index, const UINT pageSize);
	CALENDAR_BOOL (*CalendarReleaseMeetingList)(Calendar* calendar, const MeetingList* meetingList );
	CALENDAR_BOOL (*CalendarReleaseMeeting)(Calendar* calendar, Meeting* meeting);
} CalendarPlugin;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
	{type:
		{name: VidyoCalendarPlugin}
		{parent: VidyoCalendarPluginPackage}
		{include: Lmi/VidyoClient/CalendarPlugin.h}
		{description: Structure used to define the calendar plugin.
			This structure should be accessed directly. All members must be implemented.}
		{member:
			{name: calendarPlugin}
			{type: CalendarPlugin}
			{description: This structure is used to define the meeting attendee accessors.}}
		{member:
			{name: meetingAttendeePlugin}
			{type: MeetingAttendeePlugin}
			{description: This structure is used to define the meeting attendee accessors.}}
		{member:
			{name: calendarDateTimePlugin}
			{type: CalendarDateTimePlugin}
			{description: This structure is used to define the meeting calendar date time accessors.
				Timezone for all times must be GMT.}}
		{member:
			{name: MeetingPlugin}
			{type: meetingPlugin}
			{description: This structure is used to define the meeting accessors.}}
		{member:
			{name: CalStringPlugin}
			{type: calStringPlugin}
			{description: This structure is used to define the calendar string accessors.}}
	}
*/
typedef struct _VidyoCalendarPlugin
{
	CalendarPlugin           calendarPlugin;
	MeetingListPlugin        meetingListPlugin;
	MeetingPlugin            meetingPlugin;
	MeetingAttendeePlugin    meetingAttendeePlugin;
	CalendarDateTimePlugin   calendarDateTimePlugin;
	CalStringPlugin          calStringPlugin;
} VidyoCalendarPlugin;

/* Service registration API method names
  (Will be used to by VidyoClient calendar modules to identify exported registration methods using GetProcAddress)
*/
#define GET_VERSION_FUNC_NAME    	"VidyoCalendarPluginGetVersion"
#define PLUGIN_CONSTRUCT_FUNC_NAME	"VidyoCalendarPluginConstruct"
#define PLUGIN_GET_FUNC_NAME	    "VidyoCalendarPluginGet"
#define PLUGIN_DESTRUCT_FUNC_NAME	"VidyoCalendarPluginDestruct"

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Does not follow Vidyo SDK naming conventions, but maybe referenced by other code.
	{type:
		{name: VidyoCalendarPluginLogLevel}
		{parent: VidyoCalendarPluginPackage}
		{description: }
		{value:
			{name: CALENDAR_LOGLEVEL_Fatal}
			{description: }}
		{value:
			{name: CALENDAR_LOGLEVEL_Error}
			{description: }}
		{value:
			{name: CALENDAR_LOGLEVEL_Warning}
			{description: }}
		{value:
			{name: CALENDAR_LOGLEVEL_Info}
			{description: }}
		{value:
			{name: CALENDAR_LOGLEVEL_Debug}
			{description: }}
	}
*/
typedef enum _VidyoCalendarPluginLogLevel
{
	CALENDAR_LOGLEVEL_Fatal = 0,
	CALENDAR_LOGLEVEL_Error,
	CALENDAR_LOGLEVEL_Warning,
	CALENDAR_LOGLEVEL_Info,
	CALENDAR_LOGLEVEL_Debug
} VidyoCalendarPluginLogLevel;

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
	{callback:
		{parent: VidyoCalendarPluginPackage}
		{name: VidyoCalendarPluginLogCallback}
		{description: Plugin can use this callback to write to application's main log.}
		{prototype: void (*VidyoCalendarPluginLogCallback)(VidyoCalendarPluginLogLevel logLevel, const char* file, int line, const char* func, const char* msg)}
		{parameter:
			{name: logLevel}
			{description: }}
		{parameter:
			{name: file}
			{description: }}
		{parameter:
			{name: line}
			{description: }}
		{parameter:
			{name: func}
			{description: }}
		{parameter:
			{name: msg}
			{description: message (null terminated) to log.}}
	}
*/
typedef void(*VidyoCalendarPluginLogCallback)(VidyoCalendarPluginLogLevel logLevel, const char* file, int line, const char* func, const char* msg);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock validation errors.
	{callback:
		{parent: VidyoCalendarPluginPackage}
		{name: VidyoCalendarPluginConstructCallback}
		{description: The callback to indicate the result of the plugin construction.}
		{prototype: void (*VidyoCalendarPluginConstructCallback)(UINT result, void* appData)}
		{parameter:
			{name: result}
			{description: The status of the calendar plugin after construction.}}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
	}
*/
typedef void(*VidyoCalendarPluginConstructCallback)(VidyoCalendarPluginStatus result, void* appData);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'UINT', which has no DocBlock declaration (and probably never should).
	- Revisit this DocBlock declaration after the problems with 'UINT' itself are resolved.
	{callback:
		{name: VidyoCalendarPluginDestructCallback}
		{parent: VidyoCalendarPluginPackage}
		{description: Implementation must always clear out memory and release any references.
			Application must clear all references before calling destruct.}
		{prototype: void (*VidyoCalendarPluginDestructCallback)(UINT result, void* appData)}
		{parameter:
			{name: result}
			{description: The result is a notification of anything that possibly went wrong
				application will always proceed after error.}}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
	}
*/
typedef void(*VidyoCalendarPluginDestructCallback)(UINT result, void* appData);

// Exported functions below

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'DLL_API', which has no DocBlock declaration (and probably never should).
	- Revisit this DocBlock declaration after the problems with 'DLL_API' itself are resolved.
	{function:
		{name: VidyoCalendarPluginGetVersion}
		{parent: VidyoCalendarPluginPackage}
		{description: Returns: the version number defined in the header file used to implement the plugin.}
		{prototype: DLL_API UINT CalendarPluginGetVersion(void)}
		{return: must be VIDYO_CALENDAR_PLUGIN_VERSION.}
	}
*/
DLL_API UINT VidyoCalendarPluginGetVersion(void);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'DLL_API', which has no DocBlock declaration (and probably never should).
	- Revisit this DocBlock declaration after the problems with 'DLL_API' itself are resolved.
	{function:
		{name: VidyoCalendarPluginConstruct}
		{parent: VidyoCalendarPluginPackage}
		{description: This function is called to construct the calendar plugin.}
		{prototype: DLL_API void VidyoCalendarPluginConstruct(void* appData, VidyoCalendarPluginConstructCallback constructCallback)}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
		{parameter:
			{name: constructCallback}
			{description: initialize anything you need to before we get the vtable.
				This callback must be called with the result of the construction.}}
		{return: }
	}
*/
DLL_API void VidyoCalendarPluginConstruct(void* appData, VidyoCalendarPluginConstructCallback constructCallback, VidyoCalendarPluginLogCallback logCallback);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'DLL_API', which has no DocBlock declaration (and probably never should).
	- Revisit this DocBlock declaration after the problems with 'DLL_API' itself are resolved.
	{function:
		{name: VidyoCalendarPluginGet}
		{parent: VidyoCalendarPluginPackage}
		{description: This function is called to get the calendar plugin service calls.}
		{prototype: DLL_API void VidyoCalendarPluginGet(VidyoCalendarPlugin* serviceCalls)}
		{parameter:
			{name: serviceCalls}
			{description: Available after Construct.}}
		{return: FALSE if called before construct.}
	}
*/
DLL_API CALENDAR_BOOL VidyoCalendarPluginGet(VidyoCalendarPlugin* serviceCalls);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Refers to 'DLL_API', which has no DocBlock declaration (and probably never should).
	- Revisit this DocBlock declaration after the problems with 'DLL_API' itself are resolved.
	{function:
		{name: VidyoCalendarPluginDestruct}
		{parent: VidyoCalendarPluginPackage}
		{description: This function is called to destruct the calendar plugin.}
		{prototype: DLL_API void VidyoCalendarPluginDestruct(void* appData, VidyoCalendarPluginDestructCallback destructCallback)}
		{parameter:
			{name: appData}
			{description: Information provided by application to pass back to application.}}
		{parameter:
			{name: destructCallback}
			{description: This callback must be called with the result of the destruction.}}
		{return: }
	}
*/
DLL_API void VidyoCalendarPluginDestruct(void* appData, VidyoCalendarPluginDestructCallback destructCallback);

/* -*** TODO: WARNING: NOT A DOCBLOCK COMMENT ***-
	- Problem: Causes DocBlock error "does not match actual type or is not found in include file".
{type:
	{name: VIDYO_CALENDAR_PLUGIN_VERSION}
	{parent: VidyoCalendarPluginPackage}
	{description: The version number of the CalenderPlugin interface.}
}
*/
#define VIDYO_CALENDAR_PLUGIN_VERSION 1

#if defined(__cplusplus)
}
#endif

#endif /* CALENDAR_PLUGIN_H_ */
