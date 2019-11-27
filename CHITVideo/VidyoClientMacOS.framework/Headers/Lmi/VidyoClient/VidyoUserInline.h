/** 
{file:
	{name: VidyoUserInline.h}
	{description: User Entity Library. }
	{copyright:
		(c) 2013-2014 Vidyo, Inc.,
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

Define_LmiSharedPtrWrapper_NoCompare(VidyoUser, VidyoUserImpl)
Define_LmiWeakPtrWrapper(VidyoUserHandle, VidyoUser, VidyoUserImpl)

LMI_INLINE VidyoUserAuthenticationInfo* VidyoUserAuthenticationInfoConstructCopy(VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o)
{
	a->authType = o->authType;
	VidyoPropertyConstructCopy(&a->property, &o->property);
	
	return a;
}

LMI_INLINE VidyoUserAuthenticationInfo* VidyoUserAuthenticationInfoAssign(VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o)
{
	a->authType = o->authType;
	VidyoPropertyAssign(&a->property, &o->property);
	
	return a;
}

LMI_INLINE LmiBool VidyoUserAuthenticationInfoEqual(const VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o)
{
	return a->authType == o->authType;
}

LMI_INLINE LmiBool VidyoUserAuthenticationInfoLess(const VidyoUserAuthenticationInfo* a, const VidyoUserAuthenticationInfo* o)
{
	return a->authType < o->authType;
}

LMI_INLINE void VidyoUserAuthenticationInfoDestruct(VidyoUserAuthenticationInfo* authType)
{
	VidyoPropertyDestruct(&authType->property);
}
