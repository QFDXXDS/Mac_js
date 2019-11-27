/**
{file:
	{name: VidyoCalendar.h}
	{description: User Entity Library. }
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
}
*/

#ifndef VIDYO_CALENDAR_SERVICE_H_
#define VIDYO_CALENDAR_SERVICE_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiUri.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Os/LmiLog.h>
#include "VidyoFormField.h"
#include "VidyoMeetingInfo.h"
#include "VidyoCalendarConnProps.h"

LMI_BEGIN_EXTERN_C
struct VidyoCalendarFeedbackImpl_;
typedef struct VidyoCalendarFeedbackImpl_ VidyoCalendarFeedbackImpl;
Declare_LmiSharedPtr(VidyoCalendarFeedbackImpl)
Declare_LmiSharedPtrWrapper(VidyoCalendarFeedback, VidyoCalendarFeedbackImpl)
Declare_LmiWeakPtrWrapper(VidyoCalendarFeedbackHandle, VidyoCalendarFeedback, VidyoCalendarFeedbackImpl)
Declare_LmiList(VidyoCalendarFeedbackHandle)

struct VidyoCalendarImpl_;
typedef struct VidyoCalendarImpl_ VidyoCalendarImpl;
Declare_LmiSharedPtr(VidyoCalendarImpl)
Declare_LmiSharedPtrWrapper(VidyoCalendar, VidyoCalendarImpl)
Declare_LmiWeakPtrWrapper(VidyoCalendarHandle, VidyoCalendar, VidyoCalendarImpl)
Declare_LmiList(VidyoCalendar)

/* =================================*/
/* ========== PACKAGES ============ */
/* =================================*/


/**
{package:
	{name: CalendarSchedule}
	{parent: VidyoClient}
	{include: Lmi/VidyoClient/VidyoCalendar.h}
	{description: Contains a schedule of meetings that the client wishes to operate against. Note that there is a separate,
	              but different calendar package defined in under the Lmi related objects called Calendar.
	}
}
*/

/* =================================*/
/* ======== OBJECT TYPES ========== */
/* =================================*/


/**
{type visibility="public":
	{name: VidyoCalendarConnectResult}
	{parent: CalendarManager}
	{description: Indicates the result code for the creation of the calendar instance .}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_Ok}
		{description: Connected to calendar resource .}
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_NoService}
		{description: Service plugin for the calendar could not attach or commect to the underlying application.}
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_ConnectionFailed}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_ConnectionLost}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_ConnectionTimeout}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_InvalidCredentials}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_InvalidCalendarId}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_Disconnected}
		{description:   }
	}
	{value:
		{name: VIDYO_CALENDARCONNECTRESULT_GeneralError}
		{description:   }
	}

}
*/
typedef enum
{
	VIDYO_CALENDARCONNECTRESULT_Ok,
	VIDYO_CALENDARCONNECTRESULT_NoService,
	VIDYO_CALENDARCONNECTRESULT_ConnectionFailed,
	VIDYO_CALENDARCONNECTRESULT_ConnectionLost,
	VIDYO_CALENDARCONNECTRESULT_ConnectionTimeout,
	VIDYO_CALENDARCONNECTRESULT_InvalidCredentials,
	VIDYO_CALENDARCONNECTRESULT_InvalidCalendarId,
	VIDYO_CALENDARCONNECTRESULT_Disconnected,
	VIDYO_CALENDARCONNECTRESULT_GeneralError
} VidyoCalendarConnectResult;


/**
{type visibility="public":
{name: VidyoCalendarCreateCode}
{parent: CalendarSchedule}
{description: This type indicates the result of an attempt to log in to some service.}
	{value:
		{name: VIDYO_CALENDARCREATECODE_Ok}
		{description: The calendar instance was created successfully.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_SvcNotRegistered}
		{description: Service name not found in the list of registered services.  Must be added first using VidyoCalendarManagerRegisterCalendarService }
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_LibraryLoadFailed}
		{description: Problems occured trying to load the calendar plugin library module.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_ExistingInstance}
		{description: Found an existing instance with the same calendar service ID (plugin library) and calendar name (folder).}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_CalendarPluginConstructFailure}
		{description: Failure occured constructing the calendar plugin object.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_CalendarPluginInvalidCredentials}
		{description: The credentials required .}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_CalendarPluginInvalidCalendarId}
		{description: The calendar Id provided was not known to the plugin service.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_VidyoCalendarConstructFailure}
		{description: Failure occured constructing the VidyoCalendar object.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_VidyoCalendarDestroyed}
		{description: VidyoCalendar instance was successfully destroyed.}
	}
	{value:
		{name: VIDYO_CALENDARCREATECODE_GeneralError}
		{description: The login failed for some other miscellaneous error.}
	}
}
*/
typedef enum
{
	VIDYO_CALENDARCREATECODE_Ok,
	VIDYO_CALENDARCREATECODE_SvcNotRegistered,
	VIDYO_CALENDARCREATECODE_LibraryLoadFailed,
	VIDYO_CALENDARCREATECODE_InvalidLibraryVersion,
	VIDYO_CALENDARCREATECODE_ExistingInstance,
	VIDYO_CALENDARCREATECODE_CalendarPluginConstructFailure,
	VIDYO_CALENDARCREATECODE_CalendarPluginInvalidCredentials,
	VIDYO_CALENDARCREATECODE_CalendarPluginInvalidCalendarId,
	VIDYO_CALENDARCREATECODE_VidyoCalendarConstructFailure,
	VIDYO_CALENDARCREATECODE_VidyoCalendarDestroyed,
	VIDYO_CALENDARCREATECODE_GeneralError,
} VidyoCalendarCreateCode;


/**
{type visibility="public":
	{name: VidyoCalendarState}
	{parent: CalendarSchedule}
	{description: Types of services available to reference for calendar specific data and events.}
	{value:
		{name: VIDYO_CALENDARSTATE_Unavailable}
		{description: Indicates that the service is not available in the environmemt due to either an unreachable server, or by lack of an installed product.}
	}
	{value:
		{name: VIDYO_CALENDARSTATE_Initialized}
		{description: Verified that the service is available to attempt a connection against.}
	}
	{value:
		{name: VIDYO_CALENDARSTATE_Connecting}
		{description: }
	}
	{value:
		{name: VIDYO_CALENDARSTATE_Connected}
		{description: }
	}
	{value:
		{name: VIDYO_CALENDARSTATE_Disconnecting}
		{description: }
	}
	{value:
		{name: VIDYO_CALENDARSTATE_Disconnected}
		{description: }
	}
}
*/
typedef enum
{
	VIDYO_CALENDARSTATE_Unavailable,	// Possible next state(s): <none>
	VIDYO_CALENDARSTATE_Initialized,	// Possible next state(s): VIDYO_CALENDARSTATE_Connecting
	VIDYO_CALENDARSTATE_Connecting,		// Possible next state(s): VIDYO_CALENDARSTATE_Connected, VIDYO_CALENDARSTATE_Disconnected
	VIDYO_CALENDARSTATE_Connected,		// Possible next state(s): VIDYO_CALENDARSTATE_Disconnected, VIDYO_CALENDARSTATE_Disconnecting
	VIDYO_CALENDARSTATE_Disconnecting,	// Possible next state(s): VIDYO_CALENDARSTATE_Disconnected
	VIDYO_CALENDARSTATE_Disconnected,	// Possible next state(s): VIDYO_CALENDARSTATE_Connecting
} VidyoCalendarState;


/**
{type visibility="public":
	{name: VidyoCalendarCapabilityKey}
	{parent: CalendarSchedule}
	{description: These are keys that indicate plugin-specific capbilities. To keep things super simple, the standard capabilities have the EXACT SAME enum values as in CalendarPlugin.h.}
	{value:
		{name: VIDYO_CALENDARCAPABILITYKEY_SSO}
		{description: The Calendar service supports authentication by SSO. Has no value.}}
	{value:
		{name: VIDYO_CALENDARCAPABILITYKEY_WebUrl}
		{description: The Calendar service supports web auth. Value is a predicted url based on the environment.}}
	{value:
		{name: VIDYO_CALENDARCAPABILITYKEY_WebUrlAutodiscovery}
		{description: The Calendar service supports discovering the web url based on the username. Has no value.}}
	{value:
		{name: VIDYO_CALENDARCAPABILITYKEY_Username}
		{description: The Calendar service supports authentication with username. Value is a predicted username based on the environment.}}
	{value:
		{name: VIDYO_CALENDARCAPABILITYKEY_Password}
		{description: The Calendar service supports authentication by password. Has no value.}}
}
*/
typedef enum
{
	VIDYO_CALENDARCAPABILITYKEY_SSO = 1,
	VIDYO_CALENDARCAPABILITYKEY_WebUrl = 2,
	VIDYO_CALENDARCAPABILITYKEY_WebUrlAutodiscovery = 3,
	VIDYO_CALENDARCAPABILITYKEY_Username = 4,
	VIDYO_CALENDARCAPABILITYKEY_Password = 5
} VidyoCalendarCapabilityKey;


VidyoCalendarCapabilityKey* VidyoCalendarCapabilityKeyConstructCopy(VidyoCalendarCapabilityKey* dst, const VidyoCalendarCapabilityKey* src);
void VidyoCalendarCapabilityKeyDestruct(VidyoCalendarCapabilityKey*);


Declare_LmiVector(VidyoCalendarCapabilityKey)


/**
{type visibility="public":
	{name: VidyoMeetingSearchResult}
	{parent: CalendarSchedule}
	{description: This type indicates the result of a search for a meeting(s).}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_Ok}
		{description: The search operation was successful.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_Processing}
		{description: Request to perform search contains proper values and is being processed.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_NoRecords}
		{description: No records found for the search.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_InvalidIndex}
		{description: Index for search does not fall within total number of records of existing search set, based on page size.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_InvalidDateTimeRange}
		{description: Date range has either, invalid begin or end date values, or end date is before begin date .}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_NoResponse}
		{description: The search result failed due to request timeout.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_NotConnected}
		{description: Could not execute the search due to the calendar not being in a connected state.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_PluginError}
		{description: Error returned by the plugin trying to initiate the search.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_MiscLocalError}
		{description: The search result failed due to some miscellaneous local problem.}
	}
	{value:
		{name: VIDYO_MEETINGSEARCHRESULT_MiscRemoteError}
		{description: The search result failed due to some miscellaneous remote problem.}
	}

}
*/
typedef enum
{
	VIDYO_MEETINGSEARCHRESULT_Ok,
	VIDYO_MEETINGSEARCHRESULT_Processing,
	VIDYO_MEETINGSEARCHRESULT_NoRecords,
	VIDYO_MEETINGSEARCHRESULT_InvalidIndex,
	VIDYO_MEETINGSEARCHRESULT_InvalidDateTimeRange,
	VIDYO_MEETINGSEARCHRESULT_NoResponse,
	VIDYO_MEETINGSEARCHRESULT_NotConnected,
	VIDYO_MEETINGSEARCHRESULT_PluginError,
	VIDYO_MEETINGSEARCHRESULT_MiscLocalError,
	VIDYO_MEETINGSEARCHRESULT_MiscRemoteError
} VidyoMeetingSearchResult;


/**
{type reference-counted="yes":
	{name: VidyoCalendar}
	{parent: CalendarSchedule}
	{description:
		{p: Represents an instance of a calendar service. }
		{p: }
		{p: General concepts: }
		{p: 	- Each instance is identifiable through the combination of the service type and the id }
		{p: }
		{p: Lifecycle of an calendar service instance: }
		{p: 	- Create/construct an instance of the service through the VidyoCalendarManager based on a VidyoCalendarManagerDefaultServices }
		{p: 		- Constructor will take a vector of connection parameters, the content of which will also be dictated by the VidyoCalendarManagerDefaultServices }
		{p: 	- Recieve the constructed instance back through the VidyoCalendarManager callback method VidyoCalendarManagerFeedbackCreateServiceResult. }
		{p: 	- Connect the service to it's resource using the VidyoCalendarConnect method }
		{p: 	- Receive the connect result through the calendar service callback for that service through VidyoCalendarFeedbackConnectResult }
		{p: 	- Upon successful connection result, the user will be able to create, update, read and delete meetings from the service }
		{p: 		as well as receive reminder events }
	}
	{member:
		{name: serviceType}
		{type: LmiString}
		{description: Types of calendar services supported through this interface.}
	}
	{member:
		{name: serviceState}
		{type: VidyoCalendarState}
		{description: Enumeration for the states that a calendar service can transition through.}
	}
	{member:
		{name: id}
		{type: LmiString}
		{description: Uniquely identifies the calendar service instance.}
	}
	{example:
		TODO -

		VidyoCalendar myVidyoCalendar;
		VidyoCalendarFeedback myVidyoCalendarFeedback;
		LmiAllocator* alloc;

	}
}
*/


/**
{type visibility="private":
	{name: VidyoCalendarHandle}
	{parent: VidyoCalendar}
	{description: Weak reference to the VidyoCalendar object.}
}
*/

/**
{type reference-counted="yes":
	{name: VidyoCalendarFeedback}
	{parent: CalendarSchedule}
	{description: Interface for registering callbacks that notify an application about events on the VidyoCalendar object. Multiple feedbacks can be registerd on the same VidyoCalendar. }
}
*/

/**
{type visibility="private":
	{name: VidyoCalendarFeedbackHandle}
	{parent: VidyoCalendarFeedback}
	{description: Weak reference to the VidyoCalendarFeedback object.}
}
*/



/**** -----------------------****/
/**** ---- CONSTRUCTORS -----****/
/**** -----------------------****/


/* =================================*/
/* =========== METHODS ============ */
/* =================================*/

/**
{function:
	{name: VidyoCalendarConstructCopy}
	{parent: VidyoCalendar}
	{description: Constructs an VidyoCalendar object as a copy of another.}
	{prototype: VidyoCalendar *VidyoCalendarConstructCopy(VidyoCalendar *obj, const VidyoCalendar *other)}
	{parameter: {name: obj} {description: The VidyoCalendar object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoCalendarDestruct}
	{parent: VidyoCalendar}
	{description: Destructs an VidyoCalendar object.}
	{prototype: void VidyoCalendarDestruct(VidyoCalendar *obj)}
	{parameter:
		{name: obj}
		{description: The VidyoCalendar object to destruct.}
	}
}
*/

/**
{function visibility="private":
	{name: VidyoCalendarAssign}
	{parent: VidyoCalendar}
	{description: Assigns one VidyoCalendar object the value of another. }
	{prototype: VidyoCalendar *VidyoCalendarAssign(VidyoCalendar *obj, const VidyoCalendar *other)}
	{parameter: {name: obj} {description: The VidyoCalendar object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoCalendarGetHandle}
	{parent: VidyoCalendar}
	{description: }
	{prototype: const VidyoCalendarHandle* VidyoCalendarGetHandle(const VidyoCalendar* c)}
	{parameter:
		{name: c}
		{description: }
	}
	{return: }
}
*/
const VidyoCalendarHandle* VidyoCalendarGetHandle(const VidyoCalendar* c);


/**
{function visibility="private":
	{name: VidyoCalendarSetUserData}
	{parent: VidyoCalendar}
	{description: Sets a user data pointer that can be retreived later.}
	{prototype: void VidyoCalendarSetUserData(VidyoCalendar* c, LmiVoidPtr userData)}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar object.}
	}
	{parameter:
		{name: userData}
		{description: Void pointer that holds opaque application data.}
	}
}
*/
void VidyoCalendarSetUserData(VidyoCalendar* c, LmiVoidPtr userData);



/**
{function visibility="private":
	{name: VidyoCalendarGetUserData}
	{parent: VidyoCalendar}
	{description: Retreives the user data pointer that was previousely set by Calendaring VidyoCalendarSetUserData.}
	{prototype: LmiVoidPtr VidyoCalendarGetUserData(const VidyoCalendar* c)}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar object.}
	}
	{return: Void pointer that holds opaque application data.}
}
*/
LmiVoidPtr VidyoCalendarGetUserData(const VidyoCalendar* c);


/**
{function:
	{name: VidyoCalendarGetServiceType}
	{parent: VidyoCalendar}
	{description: Retreives the service type for the calendar.}
	{prototype: const LmiString * VidyoCalendarGetServiceType(const VidyoCalendar* c)}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar object.}
	}
	{return: Value for the service type .}
}
*/
const LmiString * VidyoCalendarGetServiceType(const VidyoCalendar* c);


/**
{function:
	{name: VidyoCalendarGetServiceState}
	{parent: VidyoCalendar}
	{description: Retreives the service state for the calendar.}
	{prototype: VidyoCalendarState VidyoCalendarGetServiceState(const VidyoCalendar* c)}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar object.}
	}
	{return: state of the calendar.}
}
*/
VidyoCalendarState VidyoCalendarGetServiceState(const VidyoCalendar* c);


/**
{function :
	{name: VidyoCalendarGetId}
	{parent: VidyoCalendar}
	{description:
		Retrieve unique calendar id value
	}
	{prototype: const LmiString * VidyoCalendarGetId(const VidyoCalendar* c)}
	{parameter:
		{name: c}
		{description: VidyoCalendar object}
	}
	{return: Id value as a string }
}
*/
const LmiString * VidyoCalendarGetId(const VidyoCalendar* c);


/**
{function :
{name: VidyoCalendarCreateMeetingWithId}
	{parent: VidyoCalendar}
	{description: Create a meeting using an id value returned in a VidyoMeetingInfo object.  VidyoMeeting object is returned in the VidyoCalendarFeedbackMeetingCreated callback }
	{prototype: LmiBool VidyoCalendarCreateMeetingWithId(const VidyoCalendar* c, const char *id, const VidyoMeetingFeedback *feedback, const char *createToken) }
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar object.}
	}
	{parameter:
		{name: id}
		{description: The id value given in the VidyoMeetingInfo structure that uniquely identifies the meeting}
	}
	{parameter:
		{name: feedback}
		{description: }
	}
	{parameter:
		{name: createToken}
		{description: }
	}
	{return: True if no errors occur on initiating the object creation, false if errors occurred .}
}
*/
LmiBool VidyoCalendarCreateMeetingWithId(const VidyoCalendar* c, const char *id, const VidyoMeetingFeedback *feedback, const char *createToken);


/**
{function:
	{name: VidyoCalendarFeedbackConstructCopy}
	{parent: VidyoCalendarFeedback}
	{description:
		Constructs a VidyoCalendarFeedback object as a copy of another.
	}
	{prototype:
		VidyoCalendarFeedback *VidyoCalendarFeedbackConstructCopy(VidyoCalendarFeedback *obj, const VidyoCalendarFeedback *other)
	}
	{parameter:
		{name: obj}
		{description: The VidyoCalendarFeedback object to construct.}
	}
	{parameter:
		{name: other}
		{description: The feedback object to make a copy of.}
	}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoCalendarFeedbackDestruct}
	{parent: VidyoCalendarFeedback}
	{description: Destructs an VidyoCalendarFeedback object.}
	{prototype: void VidyoCalendarFeedbackDestruct(VidyoCalendarFeedback *obj)}
	{parameter:
		{name: obj}
		{description: The VidyoCalendarFeedback object to destruct.}
	}
}
*/

/**
{function visibility="private":
	{name: VidyoCalendarFeedbackAssign}
	{parent: VidyoCalendarFeedback}
	{description: Assigns one VidyoCalendarFeedback object the value of another. }
	{prototype: VidyoCalendarFeedback *VidyoCalendarFeedbackAssign(VidyoCalendarFeedback *obj, const VidyoCalendarFeedback *other)}
	{parameter:
		{name: obj}
		{description: The VidyoCalendarFeedback object.}
	}
	{parameter:
		{name: other}
		{description: The callers VidyoCalendarFeedback object to make a copy of.}
	}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/


/**
{function:
	{name: VidyoCalendarConnect}
	{parent: VidyoCalendar}
	{description:
		{p: Initiates a connection of the calendar service to its resource for data.  This can include both a local resource or a server based one. }
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackConnectResult  }
	}
	{prototype: LmiBool VidyoCalendarConnect(const VidyoCalendar* c,
											const LmiVector(VidyoCalendarConnProps)* connProperties)
	}
	{parameter:
		{name: c}
		{description: }
	}
	{parameter:
		{name: connProperties}
		{description: Property values  }
	}
	{return: }
}
*/
LmiBool VidyoCalendarConnect(const VidyoCalendar* c, const LmiVector(VidyoCalendarConnProps)*  connProperties);


/**
{function:
	{name: VidyoCalendarDisconnect}
	{parent: VidyoCalendar}
	{description:
		{p: Initiates a connection of the calendar service to its resource for data.  This can include both a local resource or a server based one. }
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackDisconnected  }
	}
	{prototype:
		LmiBool VidyoCalendarDisconnect(VidyoCalendar* c)
	}
	{parameter:
		{name: c}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoCalendarDisconnect(VidyoCalendar* c);


/**
{function:
	{name: VidyoCalendarGetCapabilities}
	{parent: VidyoCalendar}
	{description: Gets capabilities from the CalendarPlugin. If requestedCapabilities is empty, this causes the feedback to just return a list of the plugin's capabilities with no values list. If requestedCapabilities is a list of capabilities, the plugin will respond with values it has for those capabilities.}
	{prototype:
		LmiBool VidyoCalendarGetCapabilities(VidyoCalendar* c, const LmiVector(VidyoCalendarCapabilityKey)* requestedCapabilities)}
	{parameter:
		{name: c}
		{description: The CalendarPlugin's calendar.}}
	{parameter:
		{name: requestedCapabilities}
		{description: Empty to get just the capability keys. Set with capability keys to get associated values.}}
	{return: }
}
*/
LmiBool VidyoCalendarGetCapabilities(VidyoCalendar* c, const LmiVector(VidyoCalendarCapabilityKey)* requestedCapabilities);


/**
{function:
	{name: VidyoCalendarSetSingleSignOn}
	{parent: VidyoCalendar}
	{description: Enables SSO in the CalendarPlugin.}
	{prototype:
		LmiBool VidyoCalendarSetSingleSignOn(VidyoCalendar* c, LmiBool setSingleSignOn)}
	{parameter:
		{name: c}
		{description: VidyoCalendar to enbale SSO on.}}
	{parameter:
		{name: setSingleSignOn}
		{description: Whether or not to sign on using SSO.}}
	{return: }
}
*/
LmiBool VidyoCalendarSetSingleSignOn(VidyoCalendar* c, LmiBool setSingleSignOn);


/**
{function visibility="private":
	{name: VidyoCalendarUpdateMeeting}
	{parent: VidyoCalendar}
	{description:
		{p: Updates a calendar meeting }
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackMeetingUpdated  }
	}
	{prototype: LmiBool VidyoCalendarUpdateMeeting(VidyoCalendar* c, VidyoCalendarFeedback *feedback, VidyoMeeting *meeting, LmiString *createToken)}
	{parameter:
		{name: c}
		{description: Calendar service to update the meeting against}
	}
	{parameter:
		{name: feedback}
		{description: Instance belonging to this calendar service}
	}
	{parameter:
		{name: meeting}
		{description: Meeting object to update}
	}
	{parameter:
		{name: createToken}
		{description: A unique string token to match this method call with the resulting asynchronous callback}
	}
	{return: r}
}
*/
LmiBool VidyoCalendarUpdateMeeting(VidyoCalendar* c, VidyoCalendarFeedback *feedback, VidyoMeeting *meeting, LmiString *createToken);


/**
{function visibility="private":
	{name: VidyoCalendarRemoveMeeting}
	{parent: VidyoCalendar}
	{description:
		{p: Removes a meeting from the calendar}
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackMeetingRemoved  }
	}
	{prototype: LmiBool VidyoCalendarRemoveMeeting(VidyoCalendar* c, VidyoCalendarFeedback *feedback, VidyoMeeting *meeting, LmiString *createToken)}
	{parameter:
		{name: c}
		{description: Calendar service to update the meeting against}
	}
	{parameter:
		{name: feedback}
		{description: Instance belonging to this calendar service}
	}
	{parameter:
		{name: meeting}
		{description: Meeting object to update}
	}
	{parameter:
		{name: createToken}
		{description: A unique string token to match this method call with the resulting asynchronous callback}
	}
	{return: r}
}
*/
LmiBool VidyoCalendarRemoveMeeting(VidyoCalendar* c, VidyoCalendarFeedback *feedback, VidyoMeeting *meeting, LmiString *createToken);


/**
{function:
{name: VidyoCalendarSearchMeetings}
	{parent: VidyoCalendar}
	{description:
		{p: Search a calendar for meetings based on a search string and a begin - end date.}
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackGetMeetingsResult  }

	}
	{prototype: VidyoMeetingSearchResult VidyoCalendarSearchMeetings(VidyoCalendar* c, LmiString * searchText, LmiString * beginDateTime, LmiString * endDateTime, LmiUint index, LmiUint pageSize)}
	{parameter:
		{name: c}
		{description: }
	}
	{parameter:
		{name: searchText}
		{description: If a string is supplied here, the resulting records will be filtered by this string if it is contained within any of the following meeting fields:
						- Subject
						- Location
						- Body
						- Meeting Owner email and name
						- Required attendees name and email
						- Optional attendees name and email
		}
	}
	{parameter:
		{name: beginDateTime}
		{description: Date and time to start search from}
	}
	{parameter:
		{name: endDateTime}
		{description: End date and time for search}
	}
	{parameter:
		{name: index}
		{description: Zero based index of the starting record in the search results, to use when returning the callback results. }
	}
	{parameter:
		{name: pageSize}
		{description: Number of records to return in the callback results, based off of the starting record index argument.

			NOTE... A value of zero will return all records starting from the index
		}
	}
	{return: }
}
*/
VidyoMeetingSearchResult VidyoCalendarSearchMeetings(VidyoCalendar* c, LmiString * searchText, LmiString * beginDateTime, LmiString * endDateTime, LmiUint index, LmiUint pageSize);


/**
{function:
	{name: VidyoCalendarSearchMeetingsByDay}
	{parent: VidyoCalendar}
	{description:
		{p: Get a list of meetings by day. }
		{p: }
		{p: Triggers callback(s):  VidyoCalendarFeedbackGetMeetingsResult  }
	}
	{prototype: LmiBool VidyoCalendarSearchMeetingsByDay(VidyoCalendar* c, LmiUint year, LmiUint month, LmiUint day, LmiString *createToken)}
	{parameter:
		{name: c}
		{description: Vidyo calendar service object.}
	}
	{parameter:
		{name: year}
		{description: 4 digit year to search for the meetings within - (yyyy).}
	}
	{parameter:
		{name: month}
		{description: 1-2 digit month to search for the meetings within - ((mm) - no zero padding required).}
	}
	{parameter:
		{name: day}
		{description: 1-2 digit day to search for meetings within - ((dd) - no zero padding required).}

	}
	{parameter:
		{name: createToken}
		{description: A unique string token to match this method call with the resulting asynchronous callback}
	}
	{return: }
}
*/
LmiBool VidyoCalendarSearchMeetingsByDay(VidyoCalendar *c, LmiUint year, LmiUint month, LmiUint day, LmiString *createToken);


/* =================================*/
/* ========= CALLBACKS ============ */
/* =================================*/

/**
{callback:
	{name: VidyoCalendarFeedbackConnectResult}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when service is connected. }
		{p: }
		{p: Triggered through method(s):  VidyoCalendarConnect  }
	}
	{prototype: void (*VidyoCalendarFeedbackConnectResult)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoCalendarCreateCode result)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: result}
		{description: Indication on whether the connection attempt was successful or not. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackConnectResult)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoCalendarCreateCode result);


/**
{callback:
	{name: VidyoCalendarFeedbackDisconnected}
	{parent: VidyoCalendarFeedback}
	{description: Callback that is triggered when service is disconnected.
		{p: Triggered when service is disconnected through VidyoCalendarDisconnect method. }
		{p: }
		{p: Triggered through event(s):  user will be notified through this method when the connection to the calendar service becomes unavailable.   }
	}
	{prototype: void (*VidyoCalendarFeedbackDisconnected)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoCalendarCreateCode result)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: result}
		{description: Reason for the disconnect. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackDisconnected)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoCalendarCreateCode result);

/**
{callback:
	{name: VidyoCalendarFeedbackGetCapabilitiesResult}
	{parent: VidyoCalendarFeedback}
	{description: Callback that is triggered when calendar capabilities are gotten.}
	{prototype: void (*VidyoCalendarFeedbackGetCapabilitiesResult)(VidyoCalendarFeedback* f, VidyoCalendar* c, LmiVector(VidyoCalendarCapabilityKey)* capabilities, LmiVector(LmiString)* values)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object.}}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback.}}
	{parameter:
		{name: capabilities}
		{description: List of the capabilities the calendar supports.}}
	{parameter:
		{name: values}
		{description: If the capabilities are gotten with requestedCapabilities, this will be a list of the corresponding values.}}
}
*/
typedef void(*VidyoCalendarFeedbackGetCapabilitiesResult)(VidyoCalendarFeedback* f, VidyoCalendar* c, LmiVector(VidyoCalendarCapabilityKey)* capabilities, LmiVector(LmiString)* values);

/**
{callback:
	{name: VidyoCalendarFeedbackMeetingReminder}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting event occurs. }
		{p: }
		{p: Triggered through event(s):  user will be notified through this method when the start time for a scheduled meeting occurs.   }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingReminder)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar used to generate the callback through. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeetingInfo that the callback was triggered for. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingReminder)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m);


/**
{callback:
	{name: VidyoCalendarFeedbackGetMeetingsResult}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered from a meeting search request. }
		{p: }
		{p: Triggered through method(s): }
		{p:		- VidyoCalendarSearchMeetingsByDay }
		{p:		- VidyoCalendarSearchMeetings }
	}
	{prototype: void (*VidyoCalendarFeedbackGetMeetingsResult)(VidyoCalendarFeedback *f,
																	  VidyoCalendar* c,
																	  VidyoMeetingSearchResult searchResult,
																	  const LmiVector(VidyoMeetingInfo) *meetings,
																	  const LmiUint currentIndex,
																	  const LmiUint numRecords )

	}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that the callback was triggered against. }
	}
	{parameter:
		{name: searchResult}
		{description: Indicates the reason code for the results. }
	}
	{parameter:
		{name: meetings}
		{description: A vector of meeting objects based on the results of the triggering method. }
	}
	{parameter:
		{name: currentIndex}
		{description: Current starting index for the returned list, within the full set of records found. }
	}
	{parameter:
		{name: numRecords}
		{description: Total number of records found for the search criteria. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackGetMeetingsResult)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingSearchResult searchResult, const LmiVector(VidyoMeetingInfo) *meetings, LmiUint currentIndex, LmiUint numRecords);


/**
{callback:
	{name: VidyoCalendarFeedbackMeetingCreatedByService}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting is created through the receipt of an invite by a remote user. }
		{p: }
		{p: Triggered by an event for creating a meeting that originated from the calendar service }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingCreatedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar used to generate the callback through. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the meeting that was created.}
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingCreatedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m);




/**
{callback:
	{name: VidyoCalendarFeedbackMeetingCreatedById}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting is created by the user using a known meeting ID. }
		{p: }
		{p: Triggered through method(s): VidyoCalendarCreateMeetingById }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingCreatedById)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting* m, VidyoMeetingActionResult r, LmiString* createToken)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar used to generate the callback. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the meeting that was created. }
	}
	{parameter:
		{name: r}
		{description: Result to indicate whether creating the meeting was successful or not . }
	}
	{parameter:
		{name: createToken}
		{description: Token corresponding to the one given to VidyoCalendarCreateMeetingById().}
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingCreatedById)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting* m, VidyoMeetingActionResult r, LmiString* createToken);


/**
{callback:
	{name: VidyoCalendarFeedbackMeetingUpdatedByService}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting is updated from an event originating through the calendar service. }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingUpdatedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that callback was triggered through. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeetingInfo object that was updated. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingUpdatedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo* m);


/**
{callback visibility="private":
	{name: VidyoCalendarFeedbackMeetingUpdated}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting is updated. }
		{p: }
		{p: Triggered from the method VidyoCalendarUpdateMeeting}
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingUpdated)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting* m, VidyoMeetingActionResult r, LmiString * updatedToken)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the meeting that was created. }
	}
	{parameter:
		{name: r}
		{description: Result to indicate whether creating the meeting was successful or not . }
	}
	{parameter:
		{name: updatedToken}
		{description: A unique string provided by the triggering method.  Used to correlate the method that triggered this callback. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingUpdated)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting* m, VidyoMeetingActionResult r, LmiString * updatedToken);


/**
{callback:
	{name: VidyoCalendarFeedbackMeetingRemovedByService}
	{parent: VidyoCalendarFeedback}
	{description:
		{p: Triggered when a meeting is removed from the calendar schedule by the service connected to. }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingRemovedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo *m)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeetingInfo object removed for the callback. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingRemovedByService)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeetingInfo *m);


/**
{callback visibility="private":
	{name: VidyoCalendarFeedbackMeetingRemoved}
	{parent: VidyoCalendarFeedback}
	{description:
	{p: Triggered when a meeting is removed from the calendar schedule. }
	{p: }
	{p: Triggered through method(s): VidyoCalendarRemoveMeeting.  }
	{p: The value of the VidyoMeetingActionResult will indicate if any errors occured trying to remove the meeting.  }
	}
	{prototype: void (*VidyoCalendarFeedbackMeetingRemoved)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting *m, VidyoMeetingActionResult r, LmiString * removedToken)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeeting object removed for the callback. }
	}
	{parameter:
		{name: r}
		{description: Result to indicate whether the meeting was being removed by an action from the local user or the remote owner. }
	}
	{parameter:
		{name: removedToken}
		{description: A unique string provided by the triggering method.  Used to correlate the method that triggered this callback. }
	}
}
*/
typedef void(*VidyoCalendarFeedbackMeetingRemoved)(VidyoCalendarFeedback *f, VidyoCalendar* c, VidyoMeeting *m, VidyoMeetingActionResult r, LmiString * removedToken);


/**
{callback:
	{name: VidyoCalendarFeedbackSeriesUpdate}
	{parent: VidyoCalendarFeedback}
	{description: Triggered when the plugin has updated a meeting that was updated that was a part of a series. There are no guarantees that the plugin will be able to reconstruct the series from the master and attachments, so a new search should be performed when this is called.}
	{prototype: void (*VidyoCalendarFeedbackSeriesUpdate)(VidyoCalendarFeedback* f, VidyoCalendar* c, VidyoMeetingInfo* m)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object. }
	}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoCalendar that triggered the callback. }
	}
	{parameter:
		{name: m}
		{description: The meeting that triggered the update}
	}
}
*/
typedef void(*VidyoCalendarFeedbackSeriesUpdate)(VidyoCalendarFeedback* f, VidyoCalendar* c, VidyoMeetingInfo* m);


/**
{function visibility="private":
	{name: VidyoCalendarFeedbackSetUserData}
	{parent: VidyoCalendarFeedback}
	{description: Sets a user data pointer that can be retreived later or in VidyoCalendarFeedback callbacks. }
	{prototype: void VidyoCalendarFeedbackSetUserData(VidyoCalendarFeedback* f, LmiVoidPtr userData)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object.}
	}
	{parameter:
		{name: userData}
		{description: Pointer that holds opaque application data. }
	}
}
*/
void VidyoCalendarFeedbackSetUserData(VidyoCalendarFeedback* f, LmiVoidPtr userData);


/**
{function visibility="private":
	{name: VidyoCalendarFeedbackGetUserData}
	{parent: VidyoCalendarFeedback}
	{description: Retreives a user data pointer that was previousely set by calling VidyoCalendarFeedbackSetUserData. }
	{prototype: LmiVoidPtr VidyoCalendarFeedbackGetUserData(const VidyoCalendarFeedback* f)}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object.}
	}
	{return: Pointer that holds opaque application data.}
}
*/
LmiVoidPtr VidyoCalendarFeedbackGetUserData(const VidyoCalendarFeedback* f);


/**
{function:
	{name: VidyoCalendarFeedbackConstruct}
	{parent: VidyoCalendarFeedback}
	{description: Construct the calendar feedback instance. }
	{prototype: VidyoCalendarFeedback* VidyoCalendarFeedbackConstruct(VidyoCalendarFeedback* f,
																					VidyoCalendarFeedbackConnectResult connectState,
																					VidyoCalendarFeedbackDisconnected disconnected,
																					VidyoCalendarFeedbackGetCapabilitiesResult capabilities,
																					VidyoCalendarFeedbackMeetingReminder meetingReminder,
																					VidyoCalendarFeedbackMeetingCreatedById meetingCreatedById,
																					VidyoCalendarFeedbackMeetingCreatedByService meetingCreatedByService,
																					VidyoCalendarFeedbackMeetingUpdatedByService meetingUpdatedByService,
																					VidyoCalendarFeedbackMeetingRemovedByService meetingRemovedByService,
																					VidyoCalendarFeedbackGetMeetingsResult getMeetingResults,
																					VidyoCalendarFeedbackSeriesUpdate seriesUpdate,
																					LmiAllocator* alloc)
	}
	{parameter:
		{name: f}
		{description: Feedback structure to hold registered member functions}
	}
	{parameter:
		{name: connectState}
		{description: Indicates any state transitions against the connection for the calendar service}
	}
	{parameter:
		{name: disconnected}
		{description: Indicates tha the connection for the calendar service has been disconnected. }
	}
	{parameter:
		{name: capabilities}
		{description: Listener for the calendar plugin's specific capabilities.}
	}
	{parameter:
		{name: meetingReminder}
		{description: Alert event to indicate that a reminder has been triggered for the meeting}
	}
	{parameter:
		{name: meetingCreatedById}
		{description: Returns the meeting object that was constructed through a meeting ID}
	}
	{parameter:
		{name: meetingCreatedByService}
		{description: Returns a meeting info object indicating that a meeting was created triggered by an event within the calendar service }
	}
	{parameter:
		{name: meetingUpdatedByService}
		{description: Returns a meeting info object indicating that a meeting was updated triggered by an event within the calendar service }
	}
	{parameter:
		{name: meetingRemovedByService}
		{description: Returns a meeting info object indicating that a meeting was removed or cancelled triggered by an event within the calendar service }
	}
	{parameter:
		{name: getMeetingResults}
		{description: }}
	{parameter:
		{name: seriesUpdate}
		{description: Notifies that a series was updated and the series will probably not be reconstructed. Perform a new search when this happens.}}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoCalendarFeedback* VidyoCalendarFeedbackConstruct(VidyoCalendarFeedback* f,
	VidyoCalendarFeedbackConnectResult connectState,
	VidyoCalendarFeedbackDisconnected disconnected,
	VidyoCalendarFeedbackGetCapabilitiesResult capabilities,
	VidyoCalendarFeedbackMeetingReminder meetingReminder,
	VidyoCalendarFeedbackMeetingCreatedById meetingCreatedById,
	VidyoCalendarFeedbackMeetingCreatedByService meetingCreatedByService,
	VidyoCalendarFeedbackMeetingUpdatedByService meetingUpdatedByService,
	VidyoCalendarFeedbackMeetingRemovedByService meetingRemovedByService,
	VidyoCalendarFeedbackGetMeetingsResult getMeetingResults,
	VidyoCalendarFeedbackSeriesUpdate seriesUpdate,
	LmiAllocator* alloc);


LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoCalendarInline.h"
#endif

#endif /* VIDYO_CALENDAR_SERVICE_H_ */
