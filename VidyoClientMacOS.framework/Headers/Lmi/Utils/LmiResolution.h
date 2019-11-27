/**
{file:
	{name: LmiResolution.h}
	{description: Resolution object (width and height).}
	{copyright:
		(c) 2009-2015 Vidyo, Inc.,
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
#ifndef LMI_RESOLUTION_H
#define LMI_RESOLUTION_H

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>

LMI_BEGIN_EXTERN_C

/**
{type:
	{name: LmiResolution}
	{parent: Utils}
	{include: Lmi/Utils/LmiResolution.h}
	{description: Represents the dimensions of a rectangle.}
}
*/
typedef struct {
	LmiSizeT width;
	LmiSizeT height;
} LmiResolution;

/**
   {function:
     {name: LmiResolutionConstruct}
     {parent: LmiResolution}
     {description: To construct an instance of an LmiResolution object.}
     {prototype: LmiResolution* LmiResolutionConstruct(LmiResolution* r, LmiSizeT width, LmiSizeT height, LmiAllocator* a)}
    {parameter:
       {name: r}
       {description: Pointer to a LmiResolution to be constructed.}
     }
    {parameter:
       {name: width}
       {description: Width.}
     }
    {parameter:
       {name: height}
       {description: Height.}
     }
    {parameter:
       {name: a}
       {description: Allocator.}
     }
     {return: Pointer to the constructed LmiResolution object.}
   }
*/
LMI_INLINE_DECLARATION LmiResolution* LmiResolutionConstruct(LmiResolution* r, LmiSizeT width, LmiSizeT height, LmiAllocator* a);

/**
   {function:
     {name: LmiResolutionDestruct}
     {parent: LmiResolution}
     {description: To destruct a LmiResolution.}
     {prototype: void LmiResolutionDestruct(LmiResolution* r)}
     {parameter:
       {name: r}
       {description: Pointer to an object of type LmiResolution}
     }
   }
*/
LMI_INLINE_DECLARATION void LmiResolutionDestruct(LmiResolution* r);

/**
   {function:
     {name: LmiResolutionConstructCopy}
     {parent: LmiResolution}
     {description: Construct a LmiResolution object from another instance.}
     {prototype: LmiResolution* LmiResolutionConstructCopy(LmiResolution* r, const LmiResolution* o)}
     {parameter:
       {name: r}
       {description: The object to be constructed.}
     }
     {parameter:
       {name: o}
       {description: The object to initialize from.}
     }
     {return: Pointer to the newly created copy or NULL on error.}
   }
*/
LMI_INLINE_DECLARATION LmiResolution* LmiResolutionConstructCopy(LmiResolution* r, const LmiResolution* o);

/**
   {function:
     {name: LmiResolutionAssign}
     {parent: LmiResolution}
     {description: To assign an instance of LmiResolution to another instance}
     {prototype: LmiResolution* LmiResolutionAssign(LmiResolution* r, const LmiResolution* o)}
     {parameter:
       {name: r}
       {description: Pointer to the target instance.}
     }
     {parameter:
       {name: o}
       {description: const Pointer to the source instance.}
     }
     {return: A pointer to the assigned-to instance; NULL in case of error.}
   }
*/
LMI_INLINE_DECLARATION LmiResolution* LmiResolutionAssign(LmiResolution* r, const LmiResolution* o);

/**
   {function:
     {name: LmiResolutionGetWidth}
     {parent: LmiResolution}
     {description: Get width from LmiResolution.}
     {prototype: LmiSizeT LmiResolutionGetWidth(const LmiResolution* r)}
     {parameter:
       {name: r}
       {description: Pointer to a LmiResolution object.}
     }
     {return: Width. }
   }
*/
LMI_INLINE_DECLARATION LmiSizeT LmiResolutionGetWidth(const LmiResolution* r);

/**
   {function:
     {name: LmiResolutionGetHeight}
     {parent: LmiResolution}
     {description: Get height from LmiResolution.}
     {prototype: LmiSizeT LmiResolutionGetHeight(const LmiResolution* r)}
     {parameter:
       {name: r}
       {description: Pointer to a LmiResolution object.}
     }
     {return: Height.}
   }
*/
LMI_INLINE_DECLARATION LmiSizeT LmiResolutionGetHeight(const LmiResolution* r);

/**
   {function:
     {name: LmiResolutionSetWidth}
     {parent: LmiResolution}
     {description: To modify width in a LmiResolution}
     {prototype: void LmiResolutionSetWidth(LmiResolution* r, LmiSizeT width)}
     {parameter:
       {name: r}
       {description: Pointer to a LmiResolution object.}
     }
     {parameter:
       {name: width}
       {description: The new width to be set. }
     }
   }
*/
LMI_INLINE_DECLARATION void LmiResolutionSetWidth(LmiResolution* r, LmiSizeT width);

/**
   {function:
     {name: LmiResolutionSetHeight}
     {parent: LmiResolution}
     {description: To modify height in a LmiResolution}
     {prototype: void LmiResolutionSetHeight(LmiResolution* r, LmiSizeT height)}
     {parameter:
       {name: r}
       {description: Pointer to a LmiResolution object.}
     }
     {parameter:
       {name: height}
       {description: The new height to be set.}
     }
   }
*/
LMI_INLINE_DECLARATION void LmiResolutionSetHeight(LmiResolution* r, LmiSizeT height);

/**
    {function:
      {name: LmiResolutionSetSize}
      {parent: LmiResolution}
      {description: To modify the width and height in a LmiResolution}
      {prototype: void LmiResolutionSetSize(LmiResolution* r, LmiSizeT width, LmiSizeT height)}
      {parameter:
        {name: r}
        {description: Pointer to a LmiResolution object.}
      }
      {parameter:
        {name: width}
        {description: The new width to be set.}
      }
      {parameter:
        {name: height}
        {description: The new height to be set.}
      }
 }
 */

LMI_INLINE_DECLARATION void LmiResolutionSetSize(LmiResolution* r, LmiSizeT width, LmiSizeT height);

LMI_INLINE_DECLARATION LmiBool LmiResolutionEqual(const LmiResolution* r, const LmiResolution* s);

LMI_INLINE_DECLARATION LmiBool LmiResolutionLess(const LmiResolution* r, const LmiResolution* s);
LMI_INLINE_DECLARATION LmiBool LmiResolutionLessArea(const LmiResolution* r, const LmiResolution* s);
LMI_INLINE_DECLARATION LmiBool LmiResolutionLessAspect(const LmiResolution* r, const LmiResolution* s);

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include <Lmi/Utils/LmiResolutionInline.h>
#endif

LMI_END_EXTERN_C

#endif
