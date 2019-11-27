/**
{file:
	{name: VidyoApplication.h}
	{description: Class definitions for a VidyoApplication.}
	{copyright:
		(c) 2010-2016 Vidyo, Inc.,
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
#ifndef VIDYO_APPLICATION_H_
#define VIDYO_APPLICATION_H_

#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Os/LmiTimer.h>
#include <Lmi/Signaling/LmiCredentials.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Transport/LmiTransportAddress.h>
#include <Lmi/Web/LmiWebProxyResolver.h>
#include "VidyoEndpoint.h"
#include "VidyoEndpoint_.h"

LMI_BEGIN_EXTERN_C

struct VidyoApplicationImpl_;
typedef struct VidyoApplicationImpl_ VidyoApplicationImpl;
Declare_LmiSharedPtr(VidyoApplicationImpl)
Declare_LmiSharedPtrWrapper(VidyoApplication, VidyoApplicationImpl)
Declare_LmiWeakPtrWrapper(VidyoApplicationHandle, VidyoApplication, VidyoApplicationImpl)

/**
 {type apigroup="simple" reference-counted="yes":
 	{name: VidyoApplication}
 	{parent: Endpoint}
 	{include: Lmi/VidyoClient/VidyoApplication.h}
 	{description: }
 }
*/

/**
 {type visibility="private":
 	{name: VidyoApplicationHandle}
 	{parent: VidyoApplication}
 	{description: }
 }
*/

/**
 {function apigroup="simple":
 	{name: VidyoApplicationConstruct}
 	{parent: VidyoApplication}
 	{description: }
 	{prototype: VidyoApplication* VidyoApplicationConstruct(VidyoApplication* application, VidyoEndpoint* endpoint, LmiAllocator* alloc)}
 	{parameter:
 		{name: application}
 		{description: }
 	}
 	{parameter:
 		{name: endpoint}
 		{description: }
 	}
 	{parameter:
 		{name: alloc}
 		{description: }
 	}
 	{return: }
 }
 */
VidyoApplication* VidyoApplicationConstruct(VidyoApplication* application, VidyoEndpoint* endpoint, LmiAllocator* alloc);

/**
 {function apigroup="simple":
 	{name: VidyoApplicationConstructCopy}
 	{parent: VidyoApplication}
 	{description: Constructs an VidyoApplication object as a copy of another.}
 	{prototype: VidyoApplication *VidyoApplicationConstructCopy(VidyoApplication *obj, const VidyoApplication *other)}
 	{parameter: {name: obj} {description: The VidyoApplication object to construct.}}
 	{parameter: {name: other} {description: The call object to make a copy of.}}
 	{return: A pointer to a constructed object on success, or NULL on failure.}
 }
 */

/**
 {function apigroup="simple":
 	{name: VidyoApplicationDestruct}
 	{parent: VidyoApplication}
 	{description: Destructs an VidyoApplication object.}
 	{prototype: void VidyoApplicationDestruct(VidyoApplication *obj)}
 	{parameter: {name: obj} {description: The VidyoApplication object to destruct.}}
 }
 */

/**
 {function visibility="private":
 	{name: VidyoApplicationAssign}
 	{parent: VidyoApplication}
 	{description: Assigns one VidyoApplication object the value of another. }
 	{prototype: VidyoApplication *VidyoApplicationAssign(VidyoApplication *obj, const VidyoApplication *other)}
 	{parameter: {name: obj} {description: The VidyoApplication object.}}
 	{parameter: {name: other} {description: The call object to make a copy of.}}
 	{return: A pointer to the destination object on success, or NULL on failure.}
 }
 */


/**
 {function visibility="private":
 	{name: VidyoApplicationSetUserData}
 	{parent: VidyoApplication}
 	{description: }
 	{prototype: void VidyoApplicationSetUserData(VidyoApplication* a, LmiVoidPtr userData)}
 	{parameter:
		{name: a}
 		{description: }
 	}
 	{parameter:
 		{name: userData}
 		{description: }
 	}
 }
 */
void VidyoApplicationSetUserData(VidyoApplication* u, LmiVoidPtr userData);

/**
 {function visibility="private":
 	{name: VidyoApplicationGetUserData}
 	{parent: VidyoApplication}
 	{description: }
 	{prototype: LmiVoidPtr VidyoApplicationGetUserData(const VidyoApplication* u)}
 	{parameter:
 		{name: u}
 		{description: }
 	}
 	{return: }
 }
 */
LmiVoidPtr VidyoApplicationGetUserData(const VidyoApplication* u);

/**
 {callback:
 	{name: VidyoApplicationDownloadCompletedCallback}
 	{parent: VidyoApplication}
 	{description: }
 	{prototype: void (*VidyoApplicationDownloadCompletedCallback)(VidyoApplication* app, LmiString* version, LmiString* downloadedFile)}
 	{parameter: {name: app} {description: }}
 	{parameter: {name: version} {description: upon completion, this is set to the client version on the server.}}
 	{parameter: {name: downloadedFile} {description: Should be set to the full URI of the installer on the server.}}
 }
 */
typedef void (*VidyoApplicationDownloadCompletedCallback)(VidyoApplication* app, LmiString* version, LmiString* downloadedFile);

/**
 {type visibility="public":
 	{name: VidyoApplicationDownloadFailedReason}
 	{parent: VidyoApplication}
 	{description: The reason of failed update check}
 	{value:
 		{name: VIDYO_APPLICATION_DOWNLOADFAILEDREASON_WebProxyAuthenticationRequired}
 		{description: Check for update failed because of webproxy authentication failure}
 	}
 	{value:
 		{name: VIDYO_APPLICATION_DOWNLOADFAILEDREASON_MiscError}
 		{description: Check for update failed because of misc error}
 	}
 }
 */
typedef enum {
	VIDYO_APPLICATION_DOWNLOADFAILEDREASON_WebProxyAuthenticationRequired,
	VIDYO_APPLICATION_DOWNLOADFAILEDREASON_MiscError,
} VidyoApplicationDownloadFailedReason;

/**
 {callback:
 	{name: VidyoApplicationDownloadFailedCallback}
 	{parent: VidyoApplication}
 	{description: .}
 	{prototype: void (*VidyoApplicationDownloadFailedCallback)(VidyoApplication* app, VidyoApplicationDownloadFailedReason reason)}
 	{parameter: {name: app} {description: }}
 	{parameter: {name: reason} {description: }}
 }
 */
typedef void (*VidyoApplicationDownloadFailedCallback)(VidyoApplication* app, VidyoApplicationDownloadFailedReason reason);

/**
 {function apigroup="simple":
 	{name: VidyoApplicationRegisterUpdaterEventListener}
 	{parent: VidyoApplication}
 	{description: Registers to get notified about software updater events.}
 	{prototype: LmiBool VidyoApplicationRegisterUpdaterEventListener(VidyoApplication* app, VidyoApplicationDownloadCompletedCallback onDownloadCompleted, VidyoApplicationDownloadFailedCallback onDownloadFailed)}
 	{parameter:
 		{name: app}
 		{description: The VidyoApplication object.}
 	}
 	{parameter:
 		{name: onDownloadCompleted}
 		{description: }
 	}
 	{parameter:
 		{name: onDownloadFailed}
 		{description: }
 	}
 	{return: LMI_TRUE on success, LMI_FALSE on failure.}
 }
 */
LmiBool VidyoApplicationRegisterUpdaterEventListener(VidyoApplication* app, VidyoApplicationDownloadCompletedCallback onDownloadCompleted, VidyoApplicationDownloadFailedCallback onDownloadFailed);

/**
 {function:
 	{name: VidyoApplicationStartUpdateService}
 	{parent: VidyoApplication}
 	{description: Start checking for client software updates on the server.}
	{prototype: LmiBool VidyoApplicationStartUpdateService(VidyoApplication* app, const char* currentVersion, const char* workingDirectory, const char* server, const char *caFilePath, const char* webProxyUsername, const char* webProxyPassword)}
 	{parameter: {name: app} {description: The endpoint object.}}
 	{parameter: {name: currentVersion} {description: Current version of this application.}}
 	{parameter: {name: workingDirectory} {description: The working directory used to store the installer.}}
 	{parameter: {name: server} {description: The server to be polled.}}
 	{parameter: {name: caFilePath} {description: }}
 	{parameter: {name: webProxyUsername} {description: User name for connecting to web proxy.}}
 	{parameter: {name: webProxyPassword} {description: Password for connecting to web proxy.}}
 	{return: LMI_TRUE on success, LMI_FALSE on failure.}
 }
 */
LmiBool VidyoApplicationStartUpdateService(VidyoApplication* app, const char* currentVersion, const char* workingDirectory, const char* server, const char *caFilePath, const char* webProxyUsername, const char* webProxyPassword);

/**
 {function:
 	{name: VidyoApplicationStopUpdateService}
 	{parent: VidyoApplication}
 	{description: Stop checking for client software updates on the server.}
 	{prototype: void VidyoApplicationStopUpdateService(VidyoApplication* app)}
 	{parameter: {name: app} {description: The application object.}}
 }
 */
void VidyoApplicationStopUpdateService(VidyoApplication* app);

/**
 {function:
 	{name: VidyoApplicationSetWebProxyCredentials}
 	{parent: VidyoApplication}
 	{description: }
 	{prototype: void VidyoApplicationSetWebProxyCredentials(VidyoApplication* app, const char* webProxyUserName, const char* webProxyPassword)}
 	{parameter: {name: app} {description: The application object.}}
 	{parameter: {name: webProxyUserName} {description: }}
 	{parameter: {name: webProxyPassword} {description: }}
 }
 */
void VidyoApplicationSetWebProxyCredentials(VidyoApplication* app, const char* webProxyUserName, const char* webProxyPassword);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoApplicationInline.h"
#endif

#endif /* VIDYO_APPLICATION_H */


