/** {file:
	  {name: LmiCom.h}
	  {description: Interface for wrapper around Microsoft COM functions.}
	  {copyright:
	  	(c) 2013-2014 Vidyo, Inc.,
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

#ifndef LMI_COM_H
#define LMI_COM_H

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Os/LmiLog.h>

LMI_BEGIN_EXTERN_C

/**
{type:
	{name: LmiComApartmentMode}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: COM apartment modes.}
	{value:
		{name: LMI_COMAPARTMENTMODE_Single}
		{description: Single Threaded Apartment (STA) COM apartment mode.  See Microsoft explanation of COM for details. }
	}
	{value:
		{name: LMI_COMAPARTMENTMODE_Multi}
		{description:  Multi-Threaded Apartment (MTA) COM apartment mode.  See Microsoft explanation of COM for details. }
	}
}
*/
typedef enum {
	LMI_COMAPARTMENTMODE_Single,
	LMI_COMAPARTMENTMODE_Multi
} LmiComApartmentMode;

LmiBool LmiComInitialize(void);
void LmiComUninitialize(void);

/**
{function:
{name: LmiComEnter}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: Initializes the current thread to the specified COM apartment mode. }
	{prototype: LmiBool LmiComEnter(LmiComApartmentMode mode)}
	{parameter:
		{name: mode}
		{description: The desired apartment mode.}
	}
	{return: Returns LMI_TRUE on success or LMI_FALSE on error. A return value of LMI_FALSE typically implies the thread is already configured to an apartment mode.}
}
*/
LmiBool LmiComEnter(LmiComApartmentMode mode);

/**
{function:
{name: LmiComLeave}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: Unconfigures the current thread\'s COM apartment mode. }
	{prototype: void LmiComLeave(void)}
}
*/
void LmiComLeave(void);
/**
{function:
{name: LmiComIsThreadInitialized}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: Determines if the current thread has been initialized to a COM apartment mode. }
	{prototype: LmiBool LmiComIsThreadInitialized(void)}
	{return: Returns LMI_TRUE if the current thread has been initialied to a COM apartment mode or LMI_FALSE otherwise.}
}
*/
LmiBool LmiComIsThreadInitialized(void);

/**
{type:
	{name: LmiComGuardMode}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: COM apartment modes for LmiComGuard.}
	{value:
		{name: LMI_COMGUARDMODE_Single}
		{description: Single Threaded Apartment (STA) COM apartment mode.  See Microsoft explanation of COM for details. }
	}
	{value:
		{name: LMI_COMGUARDMODE_Multi}
		{description:  Multi-Threaded Apartment (MTA) COM apartment mode.  See Microsoft explanation of COM for details. }
	}
		{value:
		{name: LMI_COMGUARDMODE_Any}
		{description: Any COM apartment mode.}
	}
}
*/
typedef enum {
	LMI_COMGUARDMODE_Single,
	LMI_COMGUARDMODE_Multi,
	LMI_COMGUARDMODE_Any
} LmiComGuardMode;

/**
{type:
	{name: LmiComGuard}
	{parent: Os}
	{include: Lmi/Os/LmiCom.h}
	{description: A COM guard.  The COM guard is used to protect calls to Microsoft COM functions that require a specific COM apartment mode to insure that the functions 
	  are not called from a thread with an incompatibile COM apartment mode.  COM guards maybe nested.}
}
*/
typedef struct {
	LmiBool any;
} LmiComGuard;

/**
{function:
{name: LmiComGuardConstructWithMode}
	{parent: LmiComGuard}
	{description: Constructs a COM guard insuring the current thread is in the specified COM apartment mode. }
	{prototype: LmiComGuard* LmiComGuardConstructWithMode(LmiComGuard* x, LmiComGuardMode mode)}
		{parameter:
		{name: x}
		{description: The LmiComGuard to construct.}
	}
	{parameter:
		{name: mode}
		{description: The desired apartment mode.}
	}
	{return: Returns a pointer to the constructed COM guard on success or NULL on error. A return value of NULL implies the current thread is configured to an apartment mode other than the desired mode.}
}
*/
LmiComGuard* LmiComGuardConstructWithMode(LmiComGuard* x, LmiComGuardMode mode);
/**
{function:
{name: LmiComGuardConstruct}
	{parent: LmiComGuard}
	{description: Constructs a COM guard insuring the current thread is in a particular COM apartment mode.  The desired apartment mode is {code:LMI_COMGUARDMODE_Multi} by default,
	  but this can be changed by setting the environment variable VIDYO_COM_MODE to \"single\" or \"any\". Setting the enviroment variable in strongly discouraged as many Vidyo APIs will fail to work properly. }
	{prototype: LmiComGuard* LmiComGuardConstruct(LmiComGuard* x)}
	{parameter:
		{name: x}
		{description: The LmiComGuard to construct.}
	}
	{return: Returns a pointer to the constructed COM guard on success or NULL on error. A return value of NULL implies the current thread is configured to an apartment mode other than the desired mode.}
}
*/
LmiComGuard* LmiComGuardConstruct(LmiComGuard* x);

/**
{function:
{name: LmiComGuardDestruct}
	{parent: LmiComGuard}
	{description: Destructs a COM guard. }
	{prototype: void LmiComGuardDestruct(LmiComGuard* x)}
	{parameter:
		{name: x}
		{description: The LmiComGuard to destruct.}
	}
}
*/
void LmiComGuardDestruct(LmiComGuard* x);

LMI_END_EXTERN_C

#endif

