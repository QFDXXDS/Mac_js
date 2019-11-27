/**
{file:
	{name: VidyoMeetingInfoInline.h}
	{description: }
	{copyright:
		(c) 2014-2015 Vidyo, Inc.,
		433 Hackensack Avenue,
		Hackensack, NJ  07601.

		All rights reserved.

		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.
		                  ***** CONFIDENTIAL *****
	}
}
*/

LMI_INLINE const LmiBool *VidyoMeetingInfoGetIsVidyoMeeting(const VidyoMeetingInfo *info)
{
	return &info->isVidyoMeeting;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetId(const VidyoMeetingInfo *info)
{
	return &info->id;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetStartTime(const VidyoMeetingInfo *info)
{
	return &info->startDateTime;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetEndTime(const VidyoMeetingInfo *info)
{
	return &info->endDateTime;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetOwnerName(const VidyoMeetingInfo *info)
{
	return &info->ownerName;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetOwnerEmail(const VidyoMeetingInfo *info)
{
	return &info->ownerEmail;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetSubject(const VidyoMeetingInfo *info)
{
	return &info->subject;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetLocation(const VidyoMeetingInfo *info)
{
	return &info->location;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetBody(const VidyoMeetingInfo *info)
{
	return &info->body;
}

LMI_INLINE const LmiString *VidyoMeetingInfoGetVidyoMeetingRoomLink(const VidyoMeetingInfo *info)
{
	return &info->vidyoMeetingRoomLink;
}

LMI_INLINE LmiInt VidyoMeetingInfoGetNumOfAttendees(const VidyoMeetingInfo *info)
{
	return info->numOfAttendees;
}
