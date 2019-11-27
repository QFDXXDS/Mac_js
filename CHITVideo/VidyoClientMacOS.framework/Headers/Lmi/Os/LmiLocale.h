/**
{file:
    {name: LmiLocale.h}
    {description: Objects to provide locale information.}
    {copyright:
    	(c) 2017 Vidyo, Inc.,
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
#ifndef LMI_LOCALE_H_
#define LMI_LOCALE_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Utils/LmiString.h>
#include <Lmi/Utils/LmiWideString.h>

/** 
	{type:
		{name: LmiLocale}
		{parent: Os}
		{include: Lmi/Os/LmiLocale.h}
		{description: A representation of rules and conventions that are specific to a specific
			language or region.}
	}
*/

#if defined(LMI_HAVE_ISVALIDLOCALENAME)
/* Windows */
#include <winsock2.h>

typedef struct {
	LPWSTR localeName;
	LmiSizeT localeNameSize;
	LmiAllocator* a;
} LmiLocale;

#define LMI_LOCALE_IMPL_WINDOWS_

#elif defined(LMI_HAVE_COREFOUNDATION_CFLOCALE_H)
/* macOS / iOS */
#include <CoreFoundation/CFLocale.h>

typedef CFLocaleRef LmiLocale;

#define LMI_LOCALE_IMPL_APPLE_

#elif defined(ANDROID)
/* Android.  Actually just uses java.* classes so in theory could work for any JNI. */
#include <jni.h>
#include <Lmi/Os/LmiAndroid.h>

typedef struct {
	jobject collator;
	LmiAndroid a;
	LmiAllocator* alloc;
} LmiLocale;

#define LMI_LOCALE_IMPL_JNI_
#define LMI_LOCALE_NEED_INIT_

#elif defined(LMI_HAVE_LOCALE_H) && defined(LMI_HAVE_WCSCOLL_L)
/* POSIX. */
#include <locale.h>

typedef locale_t LmiLocale;

#define LMI_LOCALE_IMPL_POSIX_

#else

/* No known locale implementation */

typedef int LmiLocale;

#define LMI_LOCALE_IMPL_NONE_

#endif

LMI_BEGIN_EXTERN_C

/**
	{function:
		{name: LmiLocaleConstruct}
		{parent: LmiLocale}
		{description: Construct an LmiLocale object for a specified locale.}
		{prototype: LmiLocale* LmiLocaleConstruct(LmiLocale* l, const char* name, LmiAllocator* a)}
		{parameter:
			{name: l}
			{description: The locale object to construct.}}
		{parameter:
			{name: name}
			{description: The name of the locale to construct.}}
		{parameter:
			{name: a}
			{description: An allocator for dynamically-allocated memory.}}
		{return: The constructed locale object, or NULL on failure.}
		{note: Locale names are system-dependent, but on most platforms their format is a
			variation of the format defined by BCP 47 for language tags (i.e., names like "en_US").
			(On Android and on Microsoft Windows, the language and region must be separated by a hyphen
			rather than an underscore, e.g. "en-US".)}
		{note: Whether unknown names return failure, or whether they construct a default
			locale, is system-dependent.}
	}
*/
LmiLocale* LmiLocaleConstruct(LmiLocale* l, const char* name, LmiAllocator* a);


/**
	{function:
		{name: LmiLocaleConstructSystem}
		{parent: LmiLocale}
		{description: Construct an LmiLocale object corresponding to the system's base locale,
			in the absence of user configuration.}
		{prototype: LmiLocale* LmiLocaleConstructSystem(LmiLocale* l, LmiAllocator* a)}
		{parameter:
			{name: l}
			{description: The locale object to construct}}
		{parameter:
			{name: a}
			{description: An allocator for dynamically-allocated memory.}}
		{return: The constructed locale object, or NULL on failure.}
	}
*/
LmiLocale* LmiLocaleConstructSystem(LmiLocale* l, LmiAllocator* a);


/**
	{function:
		{name: LmiLocaleConstructUser}
		{parent: LmiLocale}
		{description: Construct an LmiLocale object corresponding to the user's configured
			default locale.}
		{prototype: LmiLocale* LmiLocaleConstructUser(LmiLocale* l, LmiAllocator* a)}
		{parameter:
			{name: l}
			{description: The locale object to construct.}}
		{parameter:
			{name: a}
			{description: An allocator for dynamically-allocated memory.}}
		{return: The constructed locale object, or NULL on failure.}
	}
*/
LmiLocale* LmiLocaleConstructUser(LmiLocale* l, LmiAllocator* a);


/**
	{function:
		{name: LmiLocaleConstructCopy}
		{parent: LmiLocale}
		{description: Construct an LmiLocale object to be the same as an existing one.}
		{prototype: LmiLocale* LmiLocaleConstructCopy(LmiLocale* l, const LmiLocale* orig)}
		{parameter:
			{name: l}
			{description: The locale object to construct.}}
		{parameter:
			{name: orig}
			{description: An existing locale object.}}
		{return: The constructed locale object, or NULL on failure.}
	}
*/
LmiLocale* LmiLocaleConstructCopy(LmiLocale* l, const LmiLocale* orig);


/**
	{function:
		{name: LmiLocaleDestruct}
		{parent: LmiLocale}
		{description: Destruct an LmiLocale object.}
		{prototype: void LmiLocaleDestruct(LmiLocale* l)}
		{parameter:
			{name: l}
			{description: The locale object to destruct.}}
	}
*/
void LmiLocaleDestruct(LmiLocale* l);


/**
	{function:
		{name: LmiLocaleAssign}
		{parent: LmiLocale}
		{description: Assign an LmiLocale object to be the same as an existing one.}
		{prototype: LmiLocale* LmiLocaleAssign(LmiLocale* l, const LmiLocale* orig)}
		{parameter:
			{name: l}
			{description: The locale object to construct.}}
		{parameter:
			{name: orig}
			{description: An existing locale object.}}
		{return: The assigned-to locale object, or NULL on failure.}
	}
*/
LmiLocale* LmiLocaleAssign(LmiLocale* l, const LmiLocale* orig);


/**
	{function:
		{name: LmiLocaleSwap}
		{parent: LmiLocale}
		{description: Swap the contents of two LmiLocale objects.}
		{prototype: LmiBool LmiLocaleSwap(LmiLocale* a, LmiLocale* b)}
		{parameter:
			{name: a}
			{description: The first locale object to be swapped.}}
		{parameter:
			{name: b}
			{description: The second locale object to be swapped.}}
		{return: LMI_TRUE if the swap was successful, else LMI_FALSE.}
	}
*/
LmiBool LmiLocaleSwap(LmiLocale* a, LmiLocale* b);


/**
	{function:
		{name: LmiLocaleCompareCStr}
		{parent: LmiLocale}
		{description: Compare two UTF-8 encoded C strings, using a locale's collation function.}
		{prototype: LmiInt LmiLocaleCompareCStr(const LmiLocale* l, const char* x, const char* y)}
		{parameter:
			{name: l}
			{description: The locale to use to compare the strings.}}
		{parameter:
			{name: x}
			{description: The first UTF-8 encoded string to compare.}}
		{parameter:
			{name: y}
			{description: The second UTF-8 encoded string to compare.}}
		{return: A value <0, 0, or >0, depending on whether x collates
			less than, equal to, or greater than y, respectively.}
	}
*/
LmiInt LmiLocaleCompareCStr(const LmiLocale* l, const char* x, const char* y);


/**
	{function:
		{name: LmiLocaleCompareUcs4}
		{parent: LmiLocale}
		{description: Compare two UCS-4 encoded wide strings, using a locale's collation function.}
		{prototype: LmiInt LmiLocaleCompareUcs4(const LmiLocale* l, const LmiWideChar* x, const LmiWideChar* y)}
		{parameter:
			{name: l}
			{description: The locale to use to compare the strings.}}
		{parameter:
			{name: x}
			{description: The first UCS-4 encoded wide string to compare}}
		{parameter:
			{name: y}
			{description: The second UCS-4 encoded wide string to compare.}}
		{return: A value <0, 0, or >0, depending on whether x collates
			less than, equal to, or greater than y, respectively.}
	}
*/
LmiInt LmiLocaleCompareUcs4(const LmiLocale* l, const LmiWideChar* x, const LmiWideChar* y);


/**
	{function:
		{name: LmiLocaleCompareString}
		{parent: LmiLocale}
		{description: Compare two UTF-8 encoded strings, using a locale's collation function.}
		{prototype: LmiInt LmiLocaleCompareString(const LmiLocale* l, const LmiString* x, const LmiString* y)}
		{parameter:
			{name: l}
			{description: The locale to use to compare the strings.}}
		{parameter:
			{name: x}
			{description: The first string to compare.}}
		{parameter:
			{name: y}
			{description: The second string to compare.}}
		{return: A value <0, 0, or >0, depending on whether x collates
			less than, equal to, or greater than y, respectively.}
	}
*/
LmiInt LmiLocaleCompareString(const LmiLocale* l, const LmiString* x, const LmiString* y);


/**
	{function:
		{name: LmiLocaleCompareWideString}
		{parent: LmiLocale}
		{description: Compare two wide strings, using a locale's collation function.}
		{prototype: LmiInt LmiLocaleCompareWideString(const LmiLocale* l, const LmiWideString* x, const LmiWideString* y)}
		{parameter:
			{name: l}
			{description: The locale to use to compare the strings.}}
		{parameter:
			{name: x}
			{description: The first wide string to compare.}}
		{parameter:
			{name: y}
			{description: The second wide string to compare.}}
		{return: A value <0, 0, or >0, depending on whether x collates
			less than, equal to, or greater than y, respectively.}
	}
*/
LmiInt LmiLocaleCompareWideString(const LmiLocale* l, const LmiWideString* x, const LmiWideString* y);

LMI_END_EXTERN_C

#if defined(LMI_LOCALE_NEED_INIT_)
LmiBool LmiLocaleInitialize(void);
void LmiLocaleUninitialize(void);
#endif

#endif /* LMI_LOCALE_H_ */
