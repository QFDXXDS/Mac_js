/** {file:
      {name: LmiBattery.h}
      {description: OS independent interface to battery information.}
      {copyright:
      	(c) 2006-2017 Vidyo, Inc.,
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
#ifndef LMI_BATTERY_H_
#define LMI_BATTERY_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Utils/LmiString.h>

LMI_BEGIN_EXTERN_C

typedef struct {
	LmiAllocator* a;
#if TARGET_OS_IPHONE
	LmiBool wasEnabled;
#endif
} LmiBattery;

LmiBattery* LmiBatteryConstructDefault(LmiBattery* x, LmiAllocator* a);
void LmiBatteryDestruct(LmiBattery* x);
LmiBool LmiBatteryIsActive(const LmiBattery* x);
LmiFloat64 LmiBatteryGetLevel(const LmiBattery* x);

/* OS dependent interface */
LmiBattery* LmiBatteryConstructDefault_(LmiBattery* x, LmiAllocator* a);
void LmiBatteryDestruct_(LmiBattery* x);
LmiBool LmiBatteryIsActive_(const LmiBattery* x);
LmiFloat64 LmiBatteryGetLevel_(const LmiBattery* x);

LMI_END_EXTERN_C

#endif /* LMI_BATTERY_H_ */
