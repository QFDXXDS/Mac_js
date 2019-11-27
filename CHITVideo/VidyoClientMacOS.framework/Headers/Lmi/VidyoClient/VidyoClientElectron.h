/**
 {file:
	{name: VidyoClientElectron.h}
	{description: Vidyo Client Library interface for "Electron" software framework. }
	{copyright:
		(c) 2014-2016 Vidyo, Inc.,
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

#ifndef VIDYOCLIENTELECTRON_H_
#define VIDYOCLIENTELECTRON_H_

#include "Lmi/Utils/LmiString.h"

LMI_BEGIN_EXTERN_C

LmiBool VidyoClientElectronInit(void);
void VidyoClientElectronUninit(void);
LmiBool VidyoClientElectronDispatch(const LmiString* request, LmiString* response);
LmiBool VidyoClientElectronInitialized(void);

LMI_END_EXTERN_C

#endif
