/**
{file:
	{name: VidyoMeeting.h}
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

#ifndef VIDYO_MEETING_H_ 
#define VIDYO_MEETING_H_ 

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiUri.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Os/LmiLog.h>
#include "VidyoMeetingAttendee.h"
#include "VidyoForwardDecl.h"

LMI_BEGIN_EXTERN_C

struct VidyoMeetingFeedbackImpl_;
typedef struct VidyoMeetingFeedbackImpl_ VidyoMeetingFeedbackImpl;
Declare_LmiSharedPtr(VidyoMeetingFeedbackImpl)
Declare_LmiSharedPtrWrapper(VidyoMeetingFeedback, VidyoMeetingFeedbackImpl)
Declare_LmiWeakPtrWrapper(VidyoMeetingFeedbackHandle, VidyoMeetingFeedback, VidyoMeetingFeedbackImpl)
Declare_LmiList(VidyoMeetingFeedbackHandle)

struct VidyoMeetingImpl_;
typedef struct VidyoMeetingImpl_ VidyoMeetingImpl;
Declare_LmiSharedPtr(VidyoMeetingImpl)
Declare_LmiSharedPtrWrapper(VidyoMeeting, VidyoMeetingImpl)
Declare_LmiWeakPtrWrapper(VidyoMeetingHandle, VidyoMeeting, VidyoMeetingImpl)
Declare_LmiList(VidyoMeetingHandle)
Declare_LmiList(VidyoMeeting)
Declare_LmiVector(VidyoMeeting)

/* =================================*/
/* ========== PACKAGES ============ */
/* =================================*/


/**
{package:
	{name: Meeting}
	{parent: VidyoClient}
	{include: Lmi/VidyoClient/VidyoMeeting.h}
	{description: Represents a meeting or appointment.  The meeting may have information in it to identify it as 
				a Vidyo specific meeting.
	}
}
*/

/* =================================*/
/* ======== OBJECT TYPES ========== */
/* =================================*/

/**
{type visibility="public":
	{name: VidyoMeetingActionResult}
	{parent: Meeting}
	{include: Lmi/VidyoClient/VidyoMeeting.h}
	{description: This type indicates the result of an attempt to create a meeting.}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_Ok}
		{description: The meeting was created successfully.}
	}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_NoRecord}
		{description: Could not find an existing record to create the meeting object from.}
	}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_NoResponse}
		{description: The calendar resource did not respond in a reasonable amount of time for the intended action.}
	}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_Unauthorized}
		{description: The user is not allowed to create a meeting.}
	}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_MiscLocalError}
		{description: The server is rejecting the request to perform an action on the meeting due to some miscellaneous problem with the request.}
	}
	{value:
		{name: VIDYO_MEETINGACTIONRESULT_MiscRemoteError}
		{description: The server is rejecting the request to perform an action on the meeting due to some miscellaneous problem of its own.}
	}
}
*/
typedef enum
{
	VIDYO_MEETINGACTIONRESULT_Ok,
	VIDYO_MEETINGACTIONRESULT_NoRecord,
	VIDYO_MEETINGACTIONRESULT_NoResponse,
	VIDYO_MEETINGACTIONRESULT_Unauthorized,
	VIDYO_MEETINGACTIONRESULT_MiscLocalError,
	VIDYO_MEETINGACTIONRESULT_MiscRemoteError
} VidyoMeetingActionResult;


/**
{type visibility="public":
	{name: VidyoMeetingAttendeesSearchResult}
	{parent: Meeting}
	{include: Lmi/VidyoClient/VidyoMeeting.h}
	{description: This type indicates the result of a search for a meeting(s).}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_Ok}
		{description: The search operation was successful.}
	}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_IndexOutOfRange}
		{description: Starting index is beyond number of result records.}
	}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_NoRecords}
		{description: No records found for the search.}
	}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_NoResponse}
		{description: The search result failed due to request timeout.}
	}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_MiscLocalError}
		{description: The search result failed due to some miscellaneous local problem.}
	}
	{value:
		{name: VIDYO_MEETINGATTENDEESSEARCHRESULT_MiscRemoteError}
		{description: The search result failed due to some miscellaneous remote problem.}
	}
}
*/
typedef enum
{
	VIDYO_MEETINGATTENDEESSEARCHRESULT_Ok,
	VIDYO_MEETINGATTENDEESSEARCHRESULT_IndexOutOfRange,
	VIDYO_MEETINGATTENDEESSEARCHRESULT_NoRecords,
	VIDYO_MEETINGATTENDEESSEARCHRESULT_NoResponse,
	VIDYO_MEETINGATTENDEESSEARCHRESULT_MiscLocalError,
	VIDYO_MEETINGATTENDEESSEARCHRESULT_MiscRemoteError
} VidyoMeetingAttendeesSearchResult;


/**
{type reference-counted="yes":
	{name: VidyoMeeting}
	{parent: Meeting}	
	{include: Lmi/VidyoClient/VidyoMeeting.h}
	{description: Represents a meeting and all the related attributes.}
	{member:
		{name: id}
		{type: LmiString}
		{description: Unique id that identifies a conference meeting at the service which the meeting is created through.  
					This id must also be unique for each individual meeting within a recurring series
		}
	}
	{member:
		{name: isVidyoMeeting}
		{type: LmiBool}
		{description: Indicates whether the meeting contains Vidyo specific meeting information or not.}
	}

	{member:
		{name: startDateTime}
		{type: LmiString}
		{description: Date and time that the meeting is scheduled for }
	}
	{member:
		{name: endDateTime}
		{type: LmiString}
		{description: Date and time that the meeting is scheduled for }
	}
	{member:
		{name: subject}
		{type: LmiString}
		{description: Subject for the meeting. }
	}
	{member:
		{name: location}
		{type: LmiString}
		{description: Subject for the meeting. }
	}
	{member:
		{name: ownerName}
		{type: LmiString}
		{description: Owner name for the meeting. }
	}
	{member:
		{name: ownerEmail}
		{type: LmiString}
		{description: Email for owner the meeting. }
	}
	{member:
		{name: vidyoMeetingRoomLink}
		{type: LmiString}
		{description: Contains key information (URL, Room JID, etc) for the Vidyo room that the meeting is being held in if the meeting type is VIDYO_MEETING_TYPE_VIDYO.
						Otherwise it contains an empty string.
		}
	}
	{member:
		{name: body}
		{type: LmiString}
		{description: Body contents for the meeting. }
	}
	{member:
		{name: numberOfAttendees}
		{type: LmiInt}
		{description: Count of attendees for the meeting. }
	}
}
*/

/**
{type visibility="private":
	{name: VidyoMeetingHandle}
	{parent: VidyoMeeting}
	{description: Weak reference to VidyoMeeting object.}
}
*/

/**
{type reference-counted="yes":
	{name: VidyoMeetingFeedback}
	{parent: Meeting}
	{include: Lmi/VidyoClient/VidyoMeeting.h}
	{description: Interface for registering callbacks that notify an application about events on the VidyoMeeting object. Multiple feedbacks can be registered on the same VidyoMeeting.}
}
*/

/**
{type visibility="private":
	{name: VidyoMeetingFeedbackHandle}
	{parent: VidyoMeetingFeedback}
	{description: Weak reference to the VidyoMeetingFeedback interface.}
}
*/


/**** -----------------------****/
/**** ---- CONSTRUCTORS -----****/
/**** -----------------------****/


/**
{function:
	{name: VidyoMeetingConstructCopy}
	{parent: VidyoMeeting}
	{description: Constructs an VidyoMeeting object as a copy of another.}
	{prototype: VidyoMeeting *VidyoMeetingConstructCopy(VidyoMeeting *obj, const VidyoMeeting *other)}
	{parameter: {name: obj} {description: The VidyoMeeting object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoMeetingDestruct}
	{parent: VidyoMeeting}
	{description: Destructs an VidyoMeeting object.}
	{prototype: void VidyoMeetingDestruct(VidyoMeeting *obj)}
	{parameter: {name: obj} {description: The VidyoMeeting object to destruct.}}
}
*/

/**
{function visibility="private":
	{name: VidyoMeetingAssign}
	{parent: VidyoMeeting}
	{description: Assigns one VidyoMeeting object the value of another. }
	{prototype: VidyoMeeting *VidyoMeetingAssign(VidyoMeeting *obj, const VidyoMeeting *other)}
	{parameter: {name: obj} {description: The VidyoMeeting object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoMeetingGetHandle}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const VidyoMeetingHandle*VidyoMeetingGetHandle(const VidyoMeeting* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
const VidyoMeetingHandle* VidyoMeetingGetHandle(const VidyoMeeting* r);

 
/* =================================*/
/* =========== METHODS ============ */
/* =================================*/

/**
{function visibility="private":
	{name: VidyoMeetingAddAttendee}
	{parent: VidyoMeeting}
	{description:
		{p: Adds an attendee to the meeting }
		{p: }
		{p: Triggers callback(s):  VidyoMeetingFeedbackAttendeeAdded  }
	}
	{prototype: LmiBool VidyoMeetingAddAttendee(VidyoMeeting* m, VidyoMeetingAttendee *a)}
	{parameter:
		{name: m}
		{description: Meeting to add the attendee to}
	}
	{parameter:
		{name: a}
		{description: Attendee to add }
	}
	{return: }
}
*/
LmiBool VidyoMeetingAddAttendee(VidyoMeeting* m, VidyoMeetingAttendee *a);


/**
{function visibility="private":
	{name: VidyoMeetingRemoveAttendee}
	{parent: VidyoMeeting}
	{description:
		{p: Removes an attendee from the meeting }
		{p: }
		{p: Triggers callback(s):  VidyoMeetingFeedbackAttendeeRemoved  }
	}
	{prototype: LmiBool VidyoMeetingRemoveAttendee(VidyoMeeting* m, VidyoMeetingAttendee *a)}
	{parameter:
		{name: m}
		{description: Meeting to remove the attendee from }
	}
	{parameter:
		{name: a}
		{description: Attendee to remove }
	}
	{return: }
}
*/
LmiBool VidyoMeetingRemoveAttendee(VidyoMeeting* m, VidyoMeetingAttendee *a);


/**
{function visibility="private":
	{name: VidyoMeetingRespondToInvite}
	{parent: VidyoMeeting}
	{description:
		{p: Respond to a meeting invite}
	}
	{prototype: LmiBool VidyoMeetingRespondToInvite(VidyoMeeting* m, VidyoMeetingAttendee *a, VidyoAttendeeParticipationStatus s )}
	{parameter:
		{name: m}
		{description: Meeting to send an invite response for}
	}
	{parameter:
		{name: a}
		{description: Attendee that the response is associated with }
	}
	{parameter:
		{name: s}
		{description: The participation status for the meeting - typically accepted-declined-tentative. }
	}
	{return: r}
}
*/
LmiBool VidyoMeetingRespondToInvite(VidyoMeeting* m, VidyoMeetingAttendee *a, VidyoAttendeeParticipationStatus s);

/**
{function:
	{name: VidyoMeetingGetAttendees}
	{parent: VidyoMeeting}
	{description:
		{p: Retrieve attendees for the meeting using an index and a page size }
		{p: }
		{p: Results will be returned through the feedback : }
		{p:		- VidyoMeetingFeedbackGetMeetingAttendeeResults }
	}
	{prototype: LmiBool VidyoMeetingGetAttendees(VidyoMeeting* m, LmiUint index, LmiUint pageSize)}
	{parameter:
		{name: m}
		{description: Meeting to retrieve attendees from}
	}
	{parameter:
		{name: index}
		{description: Zero based index of the starting record in the retrieval results, to use when returning the callback data. }
	}
	{parameter:
		{name: pageSize}
		{description: Number of records to return in the callback results, based off of the starting record index argument.
		
			NOTE...
			A value of zero will return all records starting from the index
		}		
	}
	{return: }
}
*/
LmiBool VidyoMeetingGetAttendees(VidyoMeeting* m, LmiUint index, LmiUint pageSize);



/**
{function visibility="private":
	{name: VidyoMeetingGetAttendeesByRole}
	{parent: VidyoMeeting}
	{description:
		{p: Retrieve all attendees for the meeting}
	}
	{prototype: LmiBool VidyoMeetingGetAttendeesByRole(VidyoMeeting* m, LmiVector(VidyoMeetingAttendee) *a, VidyoAttendeeParticipationRole r )}
	{parameter:
		{name: m}
		{description: Meeting to retrieve attendees from}
	}
	{parameter:
		{name: a}
		{description: List of attendees for the meeting as per the role argument }
	}
	{parameter:
		{name: r}
		{description: The participation role to filter the attendee list by. }
	}
	{return: }
}
*/
LmiBool VidyoMeetingGetAttendeesByRole(VidyoMeeting* m, LmiVector(VidyoMeetingAttendee) *a, VidyoAttendeeParticipationRole r);



/**
{function visibility="private":
	{name: VidyoMeetingSetUserData}
	{parent: VidyoMeeting}
	{description: Sets a user data pointer that can be retreived later.}
	{prototype: void VidyoMeetingSetUserData(VidyoMeeting* m, LmiVoidPtr userData)}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeeting object.}
	}
	{parameter:
		{name: userData}
		{description: Void pointer that holds opaque application data.}
	}
}
*/
void VidyoMeetingSetUserData(VidyoMeeting* m, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoMeetingGetUserData}
	{parent: VidyoMeeting}
	{description: Retreives the user data pointer that was previousely set by Meetinging VidyoMeetingSetUserData.}
	{prototype: LmiVoidPtr VidyoMeetingGetUserData(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: Pointer to the VidyoMeeting object.}
	}
	{return: Void pointer that holds opaque application data.}
}
*/
LmiVoidPtr VidyoMeetingGetUserData(const VidyoMeeting* m);


/**
{function:
	{name: VidyoMeetingGetIsVidyoMeeting}
	{parent: VidyoMeeting}
	{description: }
	{prototype: LmiBool VidyoMeetingGetIsVidyoMeeting(const VidyoMeeting* m) }
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoMeetingGetIsVidyoMeeting(const VidyoMeeting* m);


/**
{function:
	{name: VidyoMeetingGetSubject}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetSubject(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetSubject(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetEndDateTime}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetEndDateTime(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetEndDateTime(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetStartDateTime}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetStartDateTime(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetStartDateTime(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetId}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetId(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetId(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetOwnerName}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetOwnerName(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetOwnerName(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetOwnerEmail}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetOwnerEmail(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetOwnerEmail(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetLocation}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetLocation(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetLocation(const VidyoMeeting* m);


/**
{function :
	{name: VidyoMeetingGetVidyoMeetingRoomLink}
	{parent: VidyoMeeting}
	{description: }
	{prototype: const LmiString * VidyoMeetingGetVidyoMeetingRoomLink(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetVidyoMeetingRoomLink(const VidyoMeeting* m);

/**
{function :
	{name: VidyoMeetingGetNumberOfAttendees}
	{parent: VidyoMeeting}
	{description: }
	{prototype: LmiInt VidyoMeetingGetNumberOfAttendees(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: VidyoMeeting object instance to retrieve value from}
	}
	{return: }
}
*/
LmiInt VidyoMeetingGetNumberOfAttendees(const VidyoMeeting* m);



/**
{function :
	{name: VidyoMeetingGetBody}
	{parent: VidyoMeeting}
	{description: Retrieve up to 2K bytes of body data from a Vidyo meeting }
	{prototype: const LmiString * VidyoMeetingGetBody(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingGetBody(const VidyoMeeting* m);



/**
{function :
	{name: VidyoMeetingRetrieveBody}
	{parent: VidyoMeeting}
	{description: To retrieve entire body from a Vidyo meeting }
	{prototype: const LmiString * VidyoMeetingRetrieveBody(const VidyoMeeting* m)}
	{parameter:
		{name: m}
		{description: }
	}
	{return: }
}
*/
const LmiString * VidyoMeetingRetrieveBody(const VidyoMeeting* m);


/* ===================================*/
/* =========== CALLBACKS ============ */
/* ===================================*/


/**
{callback:
	{name: VidyoMeetingFeedbackGetMeetingAttendeeResults}
	{parent: VidyoMeetingFeedback}
	{description:
		{p: Provides results from a request to retrieve MeetingAttendees from the VidyoMeetingGetAttendees method call.   }
		{p: }
		{p: Triggered by:  VidyoMeetingGetAttendees }
	}
	{prototype: 
		void(*VidyoMeetingFeedbackGetMeetingAttendeeResults)(VidyoMeetingFeedback* f, VidyoMeeting* meeting, const LmiVector(VidyoMeetingAttendee) * attendeeList, VidyoMeetingAttendeesSearchResult searchResult, const LmiUint currentIndex, const LmiUint numRecords)
	}
	{parameter:
		{name: f}
		{description: Pointer to the VidyoCalendarFeedback object.}
	}
	{parameter:
		{name: meeting}
		{description: Pointer to the VidyoMeeting that the callback was triggered against.}
	}
	{parameter:
		{name: attendeeList}
		{description: A vector of meeting attendee objects based on the results of the triggering method. }
	}
	{parameter:
		{name: searchResult}
		{description: Indicates the reason code for the results.}
	}
	{parameter:
		{name: currentIndex}
		{description: Current starting index for the returned list, within the full set of attendee records that exist for this meeting.}
	}
	{parameter:
		{name: numRecords}
		{description: Total number of attendee records that exist for this meeting.}
	}

}
*/
typedef void(*VidyoMeetingFeedbackGetMeetingAttendeeResults)(VidyoMeetingFeedback* f, VidyoMeeting* meeting, const LmiVector(VidyoMeetingAttendee) * attendeeList, VidyoMeetingAttendeesSearchResult searchResult, const LmiUint currentIndex, const LmiUint numRecords);


/**
{function:
	{name: VidyoMeetingFeedbackConstruct}
	{parent: VidyoMeetingFeedback}
	{description: }
	{prototype: VidyoMeetingFeedback* VidyoMeetingFeedbackConstruct(VidyoMeetingFeedback* f,
																	VidyoMeetingFeedbackGetMeetingAttendeeResults getAttendeeResults,
																	LmiAllocator* alloc)}
	{parameter:
		{name: f}
		{description: }
	}
	{parameter:
		{name: getAttendeeResults}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoMeetingFeedback* VidyoMeetingFeedbackConstruct(  VidyoMeetingFeedback* f, 
												VidyoMeetingFeedbackGetMeetingAttendeeResults getAttendeeResults,
												LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoMeetingFeedbackConstructCopy}
	{parent: VidyoMeetingFeedback}
	{description: Constructs an VidyoMeetingFeedback object as a copy of another.}
	{prototype: VidyoMeetingFeedback *VidyoMeetingFeedbackConstructCopy(VidyoMeetingFeedback *obj, const VidyoMeetingFeedback *other)}
	{parameter: 
		{name: obj} 
		{description: The VidyoMeetingFeedback object to construct.}
	}
	{parameter: 
		{name: other} 
		{description: The Meeting feedback object to make a copy of.}
	}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoMeetingFeedbackDestruct}
	{parent: VidyoMeetingFeedback}
	{description: Destructs an VidyoMeetingFeedback object.}
	{prototype: void VidyoMeetingFeedbackDestruct(VidyoMeetingFeedback *obj)}
	{parameter:	
		{name: obj} 
		{description: The VidyoMeetingFeedback object to destruct.}
	}
}
*/

/**
{function visibility="private":
	{name: VidyoMeetingFeedbackAssign}
	{parent: VidyoMeetingFeedback}
	{description: Assigns one VidyoMeetingFeedback object the value of another. }
	{prototype: VidyoMeetingFeedback *VidyoMeetingFeedbackAssign(VidyoMeetingFeedback *obj, const VidyoMeetingFeedback *other)}
	{parameter: 
		{name: obj} 
		{description: The VidyoMeetingFeedback object.}
	}
	{parameter: 
		{name: other} 
		{description: The Meeting feedback object to make a copy of.}
	}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/


/**
{function visibility="private":
	{name: VidyoMeetingFeedbackSetUserData}
	{parent: VidyoMeetingFeedback}
	{description: Sets a user data pointer that can be retreived later.}
	{prototype: void VidyoMeetingFeedbackSetUserData(VidyoMeetingFeedback* c, LmiVoidPtr userData)}
	{parameter:
	{name: c}
	{description: Pointer to the VidyoMeetingFeedback object.}
	}
	{parameter:
	{name: userData}
	{description: Void pointer that holds opaque application data.}
	}
}
*/
void VidyoMeetingFeedbackSetUserData(VidyoMeetingFeedback* c, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoMeetingFeedbackGetUserData}
	{parent: VidyoMeetingFeedback}
	{description: Retreives the user data pointer that was previousely set by meeting VidyoMeetingFeedbackSetUserData.}
	{prototype: LmiVoidPtr VidyoMeetingFeedbackGetUserData(const VidyoMeetingFeedback* c)}
	{parameter:
		{name: c}
		{description: Pointer to the VidyoMeetingFeedback object.}
	}
	{return: Void pointer that holds opaque application data.}
}
*/
LmiVoidPtr VidyoMeetingFeedbackGetUserData(const VidyoMeetingFeedback* c);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoMeetingInline.h"
#endif

#endif /* VIDYO_MEETING_H_ */
