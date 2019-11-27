/**
{file:
	{name: VidyoMeetingInfo.h}
	{description: Vidyo Meeting Descriptive Information. }
	{copyright:
		(c) 2014-2015 Vidyo, Inc.,
		433 Hackensack Avenue, 6th Floor,
		Hackensack, NJ  07601.
		All rights reserved.
		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.}
}
*/
#ifndef VIDYO_MEETINGINFO_H_
#define VIDYO_MEETINGINFO_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiStringVector.h>
#include <Lmi/Os/LmiTime.h>
#include <Lmi/Utils/LmiMap.h>
#include <Lmi/Utils/LmiUnordered.h>
#include "VidyoMeeting.h" 


LMI_BEGIN_EXTERN_C


/**
{type visibility="public":
	{name: VidyoMeetingInfo}
	{parent: Meeting}
	{include: Lmi/VidyoClient/VidyoMeetingInfo.h}
	{description: descriptive details of a meeting.}
	{member:
		{name: isVidyoMeeting}
		{type: LmiBool}
		{description: Indicates whether the meeting contains Vidyo specific meeting information or not.}
	}
	{member:
		{name: id}
		{type: LmiString}
		{description: Unique id that identifies a conference meeting at the service which the meeting is created through.}
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
		{name: body}
		{type: LmiString}
		{description: Body contents for the meeting (only up to 2K of string data). }
	}
	{member:
		{name: totalBodyLength}
		{type: LmiUint}
		{description: Total number of bytes in the body. Useful if the body is larger than 2K.}
	}
	{member:
		{name: vidyoMeetingRoomLink}
		{type: LmiString}
		{description: Contains key information (URL, Meeting JID, etc) for the Vidyo Meeting that the meeting is being held in if the meeting type is VIDYO_MEETING_TYPE_VIDYO.
						Otherwise it contains an empty string.
		}
	}
	{member:
		{name: numOfAttendees}
		{type: LmiUint}
		{description: Total number of attendees that exist for this meeting.
			
			IMPORTANT - This member reflects the *actual total* number of attendees that exist for the meeting .  The attendee vector (below) will
							be limited to 20 attendees.  
		}
	}
	{member:
		{name: attendees}
		{type: LmiVector(VidyoMeetingAttendee) }
		{description: List of up to 20 attendees for the meeting.
			NOTE... 
				This list will only hold up to 20 attendees  If the user would like to retrieve all attendees for the meeting (above 20) they will
				need to independently construct a VidyoMeeting from this type to retrieve the entire set of attendees.		
		}
	}
}
*/
typedef struct{
	LmiBool	  isVidyoMeeting;	
	LmiString id;
	LmiString startDateTime;
	LmiString endDateTime;
	LmiString ownerName;
	LmiString ownerEmail;
	LmiString subject;
	LmiString location;
	LmiString body;
	LmiUint totalBodyLength;
	LmiString vidyoMeetingRoomLink;
	LmiUint numOfAttendees;
	LmiVector(VidyoMeetingAttendee) attendees;
}VidyoMeetingInfo;


/**
{function visibility="private":
	{name: VidyoMeetingInfoConstructDefault}
	{parent: VidyoMeetingInfo}
	{description: Constructs a VidyoMeetingInfo object.}
	{prototype: VidyoMeetingInfo* VidyoMeetingInfoConstructDefault(VidyoMeetingInfo *info, LmiAllocator *alloc)}
	{parameter: {name: info} {description: The VidyoMeetingInfo object to construct.}}
	{parameter: {name: alloc} {description: An allocator to use for miscellaneous items.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoMeetingInfo *VidyoMeetingInfoConstructDefault(VidyoMeetingInfo* info, LmiAllocator *alloc);

/**
{function visibility="private":
	{name: VidyoMeetingInfoConstruct}
	{parent: VidyoMeetingInfo}
	{description: Constructs a VidyoMeetingInfo object.}
	{prototype: VidyoMeetingInfo *VidyoMeetingInfoConstruct(VidyoMeetingInfo* info,
												LmiBool isVidyoMeeting,
												LmiString * id,
												LmiString * startTime,
												LmiString * endTime,
												LmiString * ownerName,
												LmiString * ownerEmail,
												LmiString * subject,
												LmiString * location,
												LmiString * body,
												LmiUint totalBodyLength,
												LmiString * vidyoMeetingRoomLink,
												LmiInt numOfAttendees,
												LmiAllocator *alloc)
	}
	{parameter: {name: info} {description: The VidyoMeetingInfo object to construct.}}
	{parameter: {name: isVidyoMeeting} {description: type of Meeting.}}
	{parameter: {name: id} {description: id of Meeting.}}
	{parameter: {name: startTime} {description: start time of Meeting.}}
	{parameter: {name: endTime} {description: end time of Meeting.}}
	{parameter: {name: ownerName} {description: display name of owner of Meeting.}}
	{parameter: {name: ownerEmail} {description: email for owner of Meeting.}}
	{parameter: {name: subject} {description: subject of Meeting.}}
    {parameter: {name: location} {description: location string of meeting.}}
	{parameter: {name: body} {description: total number of users of the Meeting.}}
	{parameter: {name: totalBodyLength} {description: Total number of bytes in the Meeting body.}}
	{parameter: {name: vidyoMeetingRoomLink} {description: owners of the Meeting.}}
	{parameter: {name: numOfAttendees} {description: few users of Meeting.}}
	{parameter: {name: alloc} {description: An allocator to use for miscellaneous items.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoMeetingInfo *VidyoMeetingInfoConstruct(VidyoMeetingInfo* info, 
												LmiBool     isVidyoMeeting,
												LmiString * id,
												LmiString * startTime,
												LmiString * endTime,
												LmiString * ownerName,
												LmiString * ownerEmail,
												LmiString * subject,
												LmiString * location,
												LmiString * body,
												LmiUint totalBodyLength,
												LmiString * vidyoMeetingRoomLink,
												LmiInt numOfAttendees,
												LmiAllocator *alloc);


/**
{function visibility="private":
	{name: VidyoMeetingInfoConstructCopy}
	{parent: VidyoMeetingInfo}
	{description: Constructs a VidyoMeetingInfo object as a copy of an existing object.}
	{prototype: VidyoMeetingInfo* VidyoMeetingInfoConstructCopy(VidyoMeetingInfo *d, const VidyoMeetingInfo *s)}
	{parameter: {name: d} {description: The VidyoMeetingInfo object to construct.}}
	{parameter: {name: s} {description: The existing VidyoMeetingInfo object to copy.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoMeetingInfo *VidyoMeetingInfoConstructCopy(VidyoMeetingInfo *d, const VidyoMeetingInfo *s);

/**
{function visibility="private":
	{name: VidyoMeetingInfoDestruct}
	{parent: VidyoMeetingInfo}
	{description: Destructs an VidyoMeetingInfo object.}
	{prototype: void VidyoMeetingInfoDestruct(VidyoMeetingInfo *p)}
	{parameter: {name: p} {description: The VidyoMeetingInfo object to destruct.}}
}
*/
void VidyoMeetingInfoDestruct(VidyoMeetingInfo *p);

/**
{function visibility="private":
	{name: VidyoMeetingInfoAssign}
	{parent: VidyoMeetingInfo}
	{description: Assign the contents of one VidyoMeetingInfo to another.}
	{prototype: VidyoMeetingInfo *VidyoMeetingInfoAssign(VidyoMeetingInfo *d, const VidyoMeetingInfo *s)}
	{parameter: {name: d} {description: The object to assign to.}}
	{parameter: {name: s} {description: The object to copy.}}
	{return: A pointer to the assigned object on success, or NULL on failure.}
}
*/
VidyoMeetingInfo *VidyoMeetingInfoAssign(VidyoMeetingInfo *d, const VidyoMeetingInfo *s);

/**
{function visibility="private":
	{name: VidyoMeetingInfoEqual}
	{parent: VidyoMeetingInfo}
	{description: Check the equality of VidyoMeetingInfo object.}
	{prototype: LmiBool VidyoMeetingInfoEqual(const VidyoMeetingInfo *a, const VidyoMeetingInfo *b)}
	{parameter: {name: a} {description: The VidyoMeetingInfo object to compare.}}
	{parameter: {name: b} {description: The VidyoMeetingInfo object to compare.}}
	{return: LMI_TRUE if equal LMI_FALSE otherwise.}
}
*/
LmiBool VidyoMeetingInfoEqual(const VidyoMeetingInfo *a, const VidyoMeetingInfo *b);

Declare_LmiVector(VidyoMeetingInfo)

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoMeetingInfoInline.h"
#endif

#endif /* VIDYO_MeetingINFO_H_ */
