/**
{file:
	{name: VidyoEventSchedule.h}
	{description: Vidyo Event Schedule. }
	{copyright:
		(c) 2014-2017 Vidyo, Inc.,
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
#ifndef VIDYO_EVENTSCHEDULE_H_
#define VIDYO_EVENTSCHEDULE_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiStringVector.h>
#include <Lmi/Os/LmiTime.h>

LMI_BEGIN_EXTERN_C

/**
{type visibility="public":
	{name: VidyoEventSchedule}
	{parent: VidyoClient}
	{include: Lmi/VidyoClient/VidyoEventSchedule.h}
	{description: Room schedule describes the scheduling of a room.
		This is modeled based off iCalendar. Please refer to the
		iCalendar specification (RFC 2445) for more details.}
	{member:
		{name: eventId}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: startTime}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: endTime}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: duration}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: frequency}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: interval}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: count}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: until}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: byDay}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: byMonthDay}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: byMonth}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: byYearDay}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: byWeekNum}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: bySetPos}
		{type: LmiString}
		{description:}
	}
	{member:
		{name: weekStartDay}
		{type: LmiString}
		{description:}
	}
}
*/
typedef struct {
	LmiString eventId;
	LmiString startTime;
	LmiString endTime;
	LmiString duration;
	LmiString frequency;
	LmiString interval;
	LmiString count;
	LmiString until;
	LmiString byDay;
	LmiString byMonthDay;
	LmiString byMonth;
	LmiString byYearDay;
	LmiString byWeekNum;
	LmiString bySetPos;
	LmiString weekStartDay;
} VidyoEventSchedule;

/**
{function visibility="private":
	{name: VidyoEventScheduleConstructDefault}
	{parent: VidyoEventSchedule}
	{description: Constructs an VidyoEventSchedule object.}
	{prototype: VidyoEventSchedule *VidyoEventScheduleConstructDefault(VidyoEventSchedule *s, LmiAllocator *alloc)}
	{parameter: {name: s} {description: The VidyoEventSchedule object to construct.}}
	{parameter: {name: alloc} {description: An allocator to use for miscellaneous items.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoEventSchedule *VidyoEventScheduleConstructDefault(VidyoEventSchedule *s, LmiAllocator *alloc);

/**
{function visibility="private":
	{name: VidyoEventScheduleConstructCopy}
	{parent: VidyoEventSchedule}
	{description: Constructs an VidyoEventSchedule object as a copy of an existing object.}
	{prototype: VidyoEventSchedule *VidyoEventScheduleConstructCopy(VidyoEventSchedule *d, const VidyoEventSchedule *s)}
	{parameter: {name: d} {description: The VidyoEventSchedule object to construct.}}
	{parameter: {name: s} {description: The existing VidyoEventSchedule object to copy.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoEventSchedule *VidyoEventScheduleConstructCopy(VidyoEventSchedule *d, const VidyoEventSchedule *s);

/**
{function visibility="private":
	{name: VidyoEventScheduleDestruct}
	{parent: VidyoEventSchedule}
	{description: Destructs an VidyoEventSchedule object.}
	{prototype: void VidyoEventScheduleDestruct(VidyoEventSchedule *s)}
	{parameter: {name: s} {description: The VidyoEventSchedule object to destruct.}}
}
*/
void VidyoEventScheduleDestruct(VidyoEventSchedule *s);

/**
{function visibility="private":
	{name: VidyoEventScheduleAssign}
	{parent: VidyoEventSchedule}
	{description: Assign the contents of one VidyoEventSchedule to another.}
	{prototype: VidyoEventSchedule *VidyoEventScheduleAssign(VidyoEventSchedule *d, const VidyoEventSchedule *s)}
	{parameter: {name: d} {description: The object to assign to.}}
	{parameter: {name: s} {description: The object to copy.}}
	{return: A pointer to the assigned object on success, or NULL on failure.}
}
*/
VidyoEventSchedule *VidyoEventScheduleAssign(VidyoEventSchedule *d, const VidyoEventSchedule *s);

/**
{function visibility="private":
	{name: VidyoEventScheduleEqual}
	{parent: VidyoEventSchedule}
	{description: Check the equality of VidyoEventSchedule object.}
	{prototype: LmiBool VidyoEventScheduleEqual(const VidyoEventSchedule *a, const VidyoEventSchedule *b)}
	{parameter: {name: a} {description: The VidyoEventSchedule object to compare.}}
	{parameter: {name: b} {description: The VidyoEventSchedule object to compare.}}
	{return: LMI_TRUE if equal LMI_FALSE otherwise.}
}
*/
LmiBool VidyoEventScheduleEqual(const VidyoEventSchedule *a, const VidyoEventSchedule *b);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoEventScheduleInline.h"
#endif

#endif /* VIDYO_EVENTSCHEDULE_H_ */
