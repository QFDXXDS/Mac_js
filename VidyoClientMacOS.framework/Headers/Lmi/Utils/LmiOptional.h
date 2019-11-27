/**
{file:
	{name: LmiOptional.h}
	{description: }
	{copyright:
		(c) 2018 Vidyo, Inc.,
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
#ifndef LMI_OPTIONAL_H
#define LMI_OPTIONAL_H

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiTemplate.h>

#define LmiOptional(T)              LmiTemplate1(LmiOptional, T)
#define LmiOptionalConstruct(T)     LmiClassFunc(LmiOptional(T), Construct)
#define LmiOptionalConstructCopy(T) LmiClassFunc(LmiOptional(T), ConstructCopy)
#define LmiOptionalDestruct(T)      LmiClassFunc(LmiOptional(T), Destruct)
#define LmiOptionalAssign(T)        LmiClassFunc(LmiOptional(T), Assign)
#define LmiOptionalSwap(T)          LmiClassFunc(LmiOptional(T), Swap)
#define LmiOptionalEqual(T)         LmiClassFunc(LmiOptional(T), Equal)
#define LmiOptionalLess(T)          LmiClassFunc(LmiOptional(T), Less)
#define LmiOptionalSetValue(T)      LmiClassFunc(LmiOptional(T), SetValue)
#define LmiOptionalReset(T)         LmiClassFunc(LmiOptional(T), Reset)
#define LmiOptionalHasValue(T)      LmiClassFunc(LmiOptional(T), HasValue)
#define LmiOptionalGetValue(T)      LmiClassFunc(LmiOptional(T), GetValue)
#define LmiOptionalGetValueConst(T) LmiClassFunc(LmiOptional(T), GetValueConst)

#define Declare_LmiOptional_Struct_(T) \
	typedef struct \
	{ \
		T value; \
		LmiBool valid; \
	} LmiOptional(T);

#define Define_LmiOptional_InlineBodies_(T, I) \
	I LmiOptional(T) *LmiOptionalConstruct(T)(LmiOptional(T) *opt) \
	{ \
		opt->valid = LMI_FALSE; \
		return opt; \
	} \
	\
	I LmiOptional(T) *LmiOptionalConstructCopy(T)(LmiOptional(T) *opt, const LmiOptional(T) *other) \
	{ \
		if(other->valid && LmiConstructCopy(T)(&opt->value, &other->value) == NULL) \
			return NULL; \
		opt->valid = other->valid; \
		return opt; \
	} \
	\
	I void LmiOptionalDestruct(T)(LmiOptional(T) *opt) \
	{ \
		if(opt->valid) \
			LmiDestruct(T)(&opt->value); \
	} \
	\
	I LmiOptional(T) *LmiOptionalSetValue(T)(LmiOptional(T) *opt, const T *value) \
	{ \
		if(opt->valid) \
			return LmiAssign(T)(&opt->value, value) != NULL ? opt : NULL; \
		if(LmiConstructCopy(T)(&opt->value, value) == NULL) \
			return NULL; \
		opt->valid = LMI_TRUE; \
		return opt; \
	} \
	\
	I void LmiOptionalReset(T)(LmiOptional(T) *opt) \
	{ \
		if(opt->valid) \
		{ \
			LmiDestruct(T)(&opt->value); \
			opt->valid = LMI_FALSE; \
		} \
	} \
	\
	I LmiBool LmiOptionalHasValue(T)(const LmiOptional(T) *opt) \
	{ \
		return opt->valid; \
	} \
	\
	I T *LmiOptionalGetValue(T)(LmiOptional(T) *opt) \
	{ \
		if (!opt->valid) return NULL; \
		return &opt->value; \
	} \
	\
	I const T *LmiOptionalGetValueConst(T)(const LmiOptional(T) *opt) \
	{ \
		if (!opt->valid) return NULL; \
		return &opt->value; \
	}

#define Define_LmiOptional_Bodies_(T, I) \
	I LmiOptional(T) *LmiOptionalAssign(T)(LmiOptional(T) *opt, const LmiOptional(T) *other) \
	{ \
		if(opt->valid) \
		{ \
			if(other->valid) \
			{ \
				if(LmiAssign(T)(&opt->value, &other->value) == NULL) \
					opt = NULL; \
			} \
			else \
			{ \
				LmiDestruct(T)(&opt->value); \
				opt->valid = LMI_FALSE; \
			} \
		} \
		else if(other->valid) \
		{ \
			if(LmiConstructCopy(T)(&opt->value, &other->value) == NULL) \
				opt = NULL; \
			else \
				opt->valid = LMI_TRUE; \
		} \
		return opt; \
	}

#define Define_LmiOptionalSwap_(T, I) \
	I LmiBool LmiOptionalSwap(T)(LmiOptional(T) *opt, LmiOptional(T) *other) \
	{ \
		LmiBool ok = LMI_TRUE; \
		if(opt->valid) \
		{ \
			if(other->valid) \
				ok = LmiSwap(T)(&opt->value, &other->value); \
			else \
			{ \
				if(LmiConstructCopy(T)(&other->value, &opt->value) == NULL) \
					ok = LMI_FALSE; \
				else \
				{ \
					LmiDestruct(T)(&opt->value); \
					opt->valid = LMI_FALSE; \
					other->valid = LMI_TRUE; \
				} \
			} \
		} \
		else if(other->valid) \
		{ \
			if(LmiConstructCopy(T)(&opt->value, &other->value) == NULL) \
				ok = LMI_FALSE; \
			else \
			{ \
				LmiDestruct(T)(&other->value); \
				other->valid = LMI_FALSE; \
				opt->valid = LMI_TRUE; \
			} \
		} \
		return ok; \
	}

#define Define_LmiOptionalEqual_(T, I) \
	I LmiBool LmiOptionalEqual(T)(const LmiOptional(T) *opt, const LmiOptional(T) *other) \
	{ \
		return opt->valid == other->valid && (!opt->valid || LmiEqual(T)(&opt->value, &other->value)); \
	}

#define Define_LmiOptionalLess_(T, I) \
	I LmiBool LmiOptionalLess(T)(const LmiOptional(T) *opt, const LmiOptional(T) *other) \
	{ \
		return other->valid && (!opt->valid || LmiLess(T)(&opt->value, &other->value)); \
	}

#define Declare_LmiOptional(T) \
	Declare_LmiOptional_Struct_(T) \
	LMI_INLINE_DECLARATION LmiOptional(T) *LmiOptionalConstruct(T)(LmiOptional(T) *opt); \
	LMI_INLINE_DECLARATION LmiOptional(T) *LmiOptionalConstructCopy(T)(LmiOptional(T) *opt, const LmiOptional(T) *other); \
	LMI_INLINE_DECLARATION void LmiOptionalDestruct(T)(LmiOptional(T) *opt); \
	LmiOptional(T) *LmiOptionalAssign(T)(LmiOptional(T) *opt, const LmiOptional(T) *other); \
	LMI_INLINE_DECLARATION LmiOptional(T) *LmiOptionalSetValue(T)(LmiOptional(T) *opt, const T *value); \
	LMI_INLINE_DECLARATION void LmiOptionalReset(T)(LmiOptional(T) *opt); \
	LMI_INLINE_DECLARATION LmiBool LmiOptionalHasValue(T)(const LmiOptional(T) *opt); \
	LMI_INLINE_DECLARATION T *LmiOptionalGetValue(T)(LmiOptional(T) *opt); \
	LMI_INLINE_DECLARATION const T *LmiOptionalGetValueConst(T)(const LmiOptional(T) *opt);

#define Define_LmiOptional_Inline(T) \
	Define_LmiOptional_InlineBodies_(T, LMI_INLINE)

#define Define_LmiOptional(T) \
	Define_LmiOptional_Bodies_(T, LMI_NO_INLINE)

#define Define_LmiOptional_Static(T) \
	Declare_LmiOptional_Struct_(T) \
	Define_LmiOptional_InlineBodies_(T, LMI_POSSIBLY_UNUSED LMI_STATIC_INLINE) \
	Define_LmiOptional_Bodies_(T, LMI_POSSIBLY_UNUSED static)

#define Declare_LmiOptionalSwap(T) \
	LmiBool LmiOptionalSwap(T)(LmiOptional(T) *opt, LmiOptional(T) *other);
#define Define_LmiOptionalSwap(T)        Define_LmiOptionalSwap_(T, LMI_NO_INLINE)
#define Define_LmiOptionalSwap_Static(T) Define_LmiOptionalSwap_(T, static)

#define Declare_LmiOptionalEqual(T) \
	LMI_INLINE_DECLARATION LmiBool LmiOptionalEqual(T)(const LmiOptional(T) *opt, const LmiOptional(T) *other);
#define Define_LmiOptionalEqual_Inline(T) Define_LmiOptionalEqual_(T, LMI_INLINE)
#define Define_LmiOptionalEqual_Static(T) Define_LmiOptionalEqual_(T, LMI_STATIC_INLINE)

#define Declare_LmiOptionalLess(T) \
	LMI_INLINE_DECLARATION LmiBool LmiOptionalLess(T)(const LmiOptional(T) *opt, const LmiOptional(T) *other);
#define Define_LmiOptionalLess_Inline(T) Define_LmiOptionalLess_(T, LMI_INLINE)
#define Define_LmiOptionalLess_Static(T) Define_LmiOptionalLess_(T, LMI_STATIC_INLINE)

#endif
