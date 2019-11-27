/**
{file:
{name: VidyoMeetingInline.h}
{description: Meeting Entity Library. }
{copyright:
	(c) 2013-2015 Vidyo, Inc.,
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
Define_LmiSharedPtrWrapper_NoCompare(VidyoMeetingFeedback, VidyoMeetingFeedbackImpl)
Define_LmiWeakPtrWrapper(VidyoMeetingFeedbackHandle, VidyoMeetingFeedback, VidyoMeetingFeedbackImpl)
Define_LmiSharedPtrWrapper_NoCompare(VidyoMeeting, VidyoMeetingImpl)
Define_LmiWeakPtrWrapper(VidyoMeetingHandle, VidyoMeeting, VidyoMeetingImpl)