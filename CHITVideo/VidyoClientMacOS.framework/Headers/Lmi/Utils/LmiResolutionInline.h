/**
{file:
	{name: LmiResolutionInline.h}
	{description: Resolution object (width and height).}
	{copyright:
		(c) 2007-2013 Vidyo, Inc.,
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
LMI_INLINE LmiResolution* LmiResolutionConstruct(LmiResolution* r, LmiSizeT width, LmiSizeT height, LmiAllocator* a)
{
	r->width = width;
	r->height = height;
	return r;
}

LMI_INLINE void LmiResolutionDestruct(LmiResolution* r)
{
}

LMI_INLINE LmiResolution* LmiResolutionConstructCopy(LmiResolution* r, const LmiResolution* o)
{
	r->height = o->height;
	r->width = o->width;
	return r;
}

LMI_INLINE LmiResolution* LmiResolutionAssign(LmiResolution* r, const LmiResolution* o)
{
	r->height = o->height;
	r->width = o->width;
	return r;
}

LMI_INLINE LmiSizeT LmiResolutionGetWidth(const LmiResolution* r)
{
	return r->width;
}

LMI_INLINE LmiSizeT LmiResolutionGetHeight(const LmiResolution* r)
{
	return r->height;
}

LMI_INLINE void LmiResolutionSetWidth(LmiResolution* r, LmiSizeT width)
{
	r->width = width;
}

LMI_INLINE void LmiResolutionSetHeight(LmiResolution* r, LmiSizeT height)
{
	r->height = height;
}

LMI_INLINE void LmiResolutionSetSize(LmiResolution* r, LmiSizeT width, LmiSizeT height)
{
	r->width = width;
	r->height = height;
}

LMI_INLINE LmiBool LmiResolutionEqual(const LmiResolution* r, const LmiResolution* s)
{
	return (r->width == s->width) && (r->height == s->height);
}

LMI_INLINE LmiBool LmiResolutionLess(const LmiResolution* r, const LmiResolution* s)
{
	/* arbitrary total order for key comparisons */
	return r->width < s->width || (r->width == s->width && r->height < s->height);
}

LMI_INLINE LmiBool LmiResolutionLessArea(const LmiResolution* r, const LmiResolution* s)
{
	return r->width * r->height < s->width * s->height;
}

LMI_INLINE LmiBool LmiResolutionLessAspect(const LmiResolution* r, const LmiResolution* s)
{
	return r->width *s->height < s->width * r->height;
}
