/**
{file:
	{name: VidyoRoomInfo.h}
	{description: Vidyo Room Descriptive Information. }
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
#ifndef VIDYO_MEETING_PROPERTIES_H_
#define VIDYO_MEETING_PROPERTIES_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiStringVector.h>
#include <Lmi/Os/LmiTime.h>
#include "VidyoUser.h"

LMI_BEGIN_EXTERN_C

/* TODO: WARNING: See "VidyoRoomInfo.h" for conflicting 'VidyoRoomInfo' struct.
	The one defined below most likely needs to be deleted/renamed.
*/
typedef struct
{
	LmiString id;
	VidyoUser organizer;
	LmiString subject;
	LmiString language;
	LmiVector(LmiString) attendeeList;
	LmiTime creationTime;
} VidyoRoomInfo;

Declare_LmiVector(VidyoRoomInfo)

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoRoomInfoInline.h"
#endif

#endif /* VIDYO_ROOMINFO_H_ */
