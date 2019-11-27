/**
 {file:
	{name: VidyoProperty.h}
	{description: High level client library. }
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

#ifndef VidyoProperty_h
#define VidyoProperty_h

#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiString.h>
#include <Lmi/Utils/LmiProperty.h>

LMI_BEGIN_EXTERN_C

/**
 {type visibility="public":
	{name: VidyoProperty}
	{parent: Endpoint}
 	{include: Lmi/VidyoClient/VidyoProperty.h}
	{description: This class implements a Property.}
	{member:
 		{name: name}
 		{type: LmiString}
 		{description: }
	}
	{member:
 		{name: value}
 		{type: LmiString}
 		{description: }
	}
 }
 */

typedef struct {
    LmiString name;
    LmiString value;
} VidyoProperty;

/**
 {function visibility="private":
	{name: VidyoPropertyConstruct}
	{parent: VidyoProperty}
	{description: }
	{prototype: VidyoProperty* VidyoPropertyConstruct(VidyoProperty *p, const LmiString* name, const LmiString* value)}
         {parameter: {name: p} {description: The VidyoProperty object to construct.}}
         {parameter: {name: name} {description: Name of the property.}}
         {parameter: {name: value} {description: Value of the property.}}
     {return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoProperty* VidyoPropertyConstruct(VidyoProperty *p, const LmiString* name, const LmiString* value);

/**
 {function visibility="private":
	{name: VidyoPropertyConstructDefault}
	{parent: VidyoProperty}
	{description: }
	{prototype: VidyoProperty* VidyoPropertyConstructDefault(VidyoProperty *p, LmiAllocator *alloc)}
        {parameter: {name: p} {description: The VidyoProperty object to construct.}}
        {parameter: {name: alloc} {description: The allocator object to be used.}}
    {return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoProperty* VidyoPropertyConstructDefault(VidyoProperty *p, LmiAllocator *alloc);

/**
 {function visibility="private":
	{name: VidyoPropertyDestruct}
	{parent: VidyoProperty}
	{description: }
	{prototype: void VidyoPropertyDestruct(VidyoProperty *p)}
        {parameter: {name: p} {description: The VidyoProperty object to destruct.}}
 }
 */
void VidyoPropertyDestruct(VidyoProperty *p);

/**
 {function visibility="private":
     {name: VidyoPropertyConstructCopy}
     {parent: VidyoProperty}
     {description: Constructs an VidyoProperty object as a copy of an existing object.}
     {prototype: VidyoProperty* VidyoPropertyConstructCopy(VidyoProperty *p, const VidyoProperty *o)}
         {parameter: {name: p} {description: The VidyoProperty object to construct.}}
         {parameter: {name: o} {description: The existing VidyoProperty object to copy.}}
     {return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */
VidyoProperty* VidyoPropertyConstructCopy(VidyoProperty *p, const VidyoProperty *o);

/**
{function visibility="private":
	{name: VidyoPropertyConstructCStr}
	{parent: VidyoProperty}
	{description: Constructor with initial values (in CStr format).}
	{prototype: VidyoProperty* VidyoPropertyConstructCStr(VidyoProperty* p, const char* name, const char* value, LmiAllocator* a)}
		{parameter:
			{name: p}
			{description: The VidyoProperty object to be constructed.}
		}
		{parameter:
			{name: name}
			{description: The name of the property.}
		}
		{parameter:
			{name: value}
			{description: The value of the property.}
		}
		{parameter:
			{name: a}
			{description: The allocator to be used.}
		}
	{return: p if the construct operation was successful; NULL otherwise.}
}
*/
VidyoProperty* VidyoPropertyConstructCStr(VidyoProperty* p, const char* name, const char* value, LmiAllocator* a);

/**
 {function visibility="private":
     {name: VidyoPropertyAssign}
     {parent: VidyoProperty}
     {description: Assign the contents of one VidyoProperty to another.}
     {prototype: VidyoProperty *VidyoPropertyAssign(VidyoProperty *p, const VidyoProperty *o)}
         {parameter: {name: p} {description: The object to assign to.}}
         {parameter: {name: o} {description: The object to copy.}}
     {return: A pointer to the assigned object on success, or NULL on failure.}
 }
 */
VidyoProperty* VidyoPropertyAssign(VidyoProperty *p, const VidyoProperty *o);

/**
{function visibility="private":
	{name: VidyoPropertyIsEqualCStr}
	{parent: VidyoProperty}
	{description: To check whether the name of the VidyoProperty object matches the given string (in CStr format).}
	{prototype: LmiBool VidyoPropertyIsEqualCStr(const VidyoProperty* p, const char* name)}
		{parameter:
			{name: p}
			{description: The VidyoProperty object.}
		}
		{parameter:
			{name: name}
			{description: The name string to be matched against.}
		}
	{return: LMI_TRUE if the name of the property matches with the given name; LMI_FALSE otherwise.}
}
*/
LmiBool VidyoPropertyIsEqualCStr(const VidyoProperty* p, const char* name);

/**
{function visibility="private":
	{name: VidyoPropertyGetValueCStr}
	{parent: VidyoProperty}
	{description: To get the value of an LmiProperty object in CStr format.}
	{prototype: const char* VidyoPropertyGetValueCStr(const VidyoProperty* p)}
		{parameter:
			{name: p}
			{description: The VidyoProperty object.}
		}
	{return: The value of the object.}
}
*/
const char* VidyoPropertyGetValueCStr(const VidyoProperty* p);

/* Dummy operation -- no doc block */
LmiBool VidyoPropertyEqual(const VidyoProperty *p, const VidyoProperty *o);
LmiBool VidyoPropertyLess(const VidyoProperty *p, const VidyoProperty *o);

Declare_LmiVector(VidyoProperty)

/**
 {function visibility="private":
     {name: VidyoPropertyUpdateFromLmiProperty}
     {parent: VidyoProperty}
     {description: Assign the contents of a LmiProperty to a VidyoProperty.}
     {prototype: VidyoProperty *VidyoPropertyUpdateFromLmiProperty(VidyoProperty *p, const LmiProperty *o)}
         {parameter: {name: p} {description: The object to assign to.}}
         {parameter: {name: o} {description: The object to copy.}}
     {return: A pointer to the assigned object on success, or NULL on failure.}
 }
 */
VidyoProperty* VidyoPropertyUpdateFromLmiProperty(VidyoProperty *p, const LmiProperty *o);


/**
 {function visibility="private":
     {name: VidyoPropertyListConstructFromLmiPropertyList}
     {parent: VidyoProperty}
     {description: Assign the contents of a LmiProperty list to a VidyoProperty list.}
     {prototype: void VidyoPropertyListConstructFromLmiPropertyList(LmiVector(VidyoProperty) *p, LmiVector(LmiProperty) *o, LmiAllocator* a)}
         {parameter: {name: p} {description: The object to assign to.}}
         {parameter: {name: o} {description: The object to copy.}}
         {parameter: {name: a} {description: The allocator object to be used.}}
 }
 */
void VidyoPropertyListConstructFromLmiPropertyList(LmiVector(VidyoProperty) *p, LmiVector(LmiProperty) *o, LmiAllocator* a);

/**
 {function visibility="private":
     {name: VidyoPropertyListConvertToLmiPropertyList}
     {parent: VidyoProperty}
     {description: Assign the contents of a VidyoProperty list to a LmiProperty list.}
     {prototype: void VidyoPropertyListConvertToLmiPropertyList(LmiVector(VidyoProperty)* vPropList, LmiVector(LmiProperty)* lpropList, LmiAllocator* a)}
         {parameter: {name: vPropList} {description: The object to assign to.}}
         {parameter: {name: lpropList} {description: The object to copy.}}
         {parameter: {name: a} {description: The allocator object to be used.}}
 }
 */
void VidyoPropertyListConvertToLmiPropertyList(LmiVector(VidyoProperty)* vPropList, LmiVector(LmiProperty)* lpropList, LmiAllocator* a);

LMI_END_EXTERN_C

#endif /* VidyoProperty_h */
