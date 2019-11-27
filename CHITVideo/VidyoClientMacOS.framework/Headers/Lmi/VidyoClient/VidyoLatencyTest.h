/**
{file:
	{name: VidyoLatencyTest.h}
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
		without the express written consent of Vidyo, Inc.
		                  ***** CONFIDENTIAL *****
	}
}
*/
#ifndef VIDYO_LATENCYTEST_H
#define VIDYO_LATENCYTEST_H

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include "VidyoForwardDecl.h"
#include "VidyoTransport.h"
#include "VidyoStatistics.h"

LMI_BEGIN_EXTERN_C

struct VidyoLatencyTestDataImpl_;
typedef struct VidyoLatencyTestDataImpl_ VidyoLatencyTestDataImpl;
Declare_LmiSharedPtr(VidyoLatencyTestDataImpl)
Declare_LmiSharedPtrWrapper(VidyoLatencyTestData, VidyoLatencyTestDataImpl)
Declare_LmiWeakPtrWrapper(VidyoLatencyTestDataHandle, VidyoLatencyTestData, VidyoLatencyTestDataImpl)
Declare_LmiVector(VidyoLatencyTestData)

struct VidyoLatencyTestImpl_;
typedef struct VidyoLatencyTestImpl_ VidyoLatencyTestImpl;
Declare_LmiSharedPtr(VidyoLatencyTestImpl)
Declare_LmiSharedPtrWrapper(VidyoLatencyTest, VidyoLatencyTestImpl)
Declare_LmiWeakPtrWrapper(VidyoLatencyTestHandle, VidyoLatencyTest, VidyoLatencyTestImpl)

/**
{type visibility="private":
	{name: VidyoLatencyTestData}
	{parent: VidyoLatencyTest}
	{description: }
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestDataConstruct}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: VidyoLatencyTestData *VidyoLatencyTestDataConstruct(VidyoLatencyTestData *td, VidyoLatencyTest* t, VidyoTransport *transport, const LmiString *name, const LmiString *address, LmiUint port, LmiFloat64 latitude, LmiFloat64 longitude, LmiAllocator *alloc)}
	{parameter:
		{name: td}
		{description: }
	}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: transport}
		{description: }
	}
	{parameter:
		{name: name}
		{description: }
	}
	{parameter:
		{name: address}
		{description: }
	}
	{parameter:
		{name: port}
		{description: }
	}
	{parameter:
		{name: latitude}
		{description: }
	}
	{parameter:
		{name: longitude}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLatencyTestData *VidyoLatencyTestDataConstruct(VidyoLatencyTestData *td, VidyoLatencyTest* t, VidyoTransport *transport, const LmiString *name, const LmiString *address, LmiUint port, LmiFloat64 latitude, LmiFloat64 longitude, LmiAllocator *alloc);


/**
{function visibility="private":
	{name: VidyoLatencyTestDataConstructCopy}
	{parent: VidyoLatencyTestData}
	{description: Constructs an VidyoLatencyTestData object as a copy of another.}
	{prototype: VidyoLatencyTestData *VidyoLatencyTestDataConstructCopy(VidyoLatencyTestData *obj, const VidyoLatencyTestData *other)}
	{parameter: {name: obj} {description: The VidyoLatencyTestData object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestDataDestruct}
	{parent: VidyoLatencyTestData}
	{description: Destructs an VidyoLatencyTestData object.}
	{prototype: void VidyoLatencyTestDataDestruct(VidyoLatencyTestData *obj)}
	{parameter: {name: obj} {description: The VidyoLatencyTestData object to destruct.}}
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestDataAssign}
	{parent: VidyoLatencyTestData}
	{description: Assigns one VidyoLatencyTestData object the value of another. }
	{prototype: VidyoLatencyTestData *VidyoLatencyTestDataAssign(VidyoLatencyTestData *obj, const VidyoLatencyTestData *other)}
	{parameter: {name: obj} {description: The VidyoLatencyTestData object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetDestinationName}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiString *VidyoLatencyTestDataGetDestinationName(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiString *VidyoLatencyTestDataGetDestinationName(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetDestinationAddress}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiString *VidyoLatencyTestDataGetDestinationAddress(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiString *VidyoLatencyTestDataGetDestinationAddress(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataHasResults}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiBool VidyoLatencyTestDataHasResults(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLatencyTestDataHasResults(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetReportedAddress}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiString *VidyoLatencyTestDataGetReportedAddress(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiString *VidyoLatencyTestDataGetReportedAddress(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetLatency}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiTime VidyoLatencyTestDataGetLatency(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiTime VidyoLatencyTestDataGetLatency(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetLatitude}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiFloat64 VidyoLatencyTestDataGetLatitude(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiFloat64 VidyoLatencyTestDataGetLatitude(VidyoLatencyTestData *td);

/**
{function visibility="private":
	{name: VidyoLatencyTestDataGetLongitude}
	{parent: VidyoLatencyTestData}
	{description: }
	{prototype: LmiFloat64 VidyoLatencyTestDataGetLongitude(VidyoLatencyTestData *td)}
	{parameter:
		{name: td}
		{description: }
	}
	{return: }
}
*/
LmiFloat64 VidyoLatencyTestDataGetLongitude(VidyoLatencyTestData *td);

/**
{type visibility="private":
	{name: VidyoLatencyTest}
	{parent: VidyoClient}
	{include: Lmi/VidyoClient/VidyoLatencyTest.h}
	{description: }
}
*/

/**
{callback visibility="private":
	{name: VidyoLatencyTestOnComplete}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: void (*VidyoLatencyTestOnComplete)(VidyoLatencyTest* t, LmiVector(VidyoLatencyTestData) *data, LmiBool timeout, void* userData)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: data}
		{description: }
	}
	{parameter:
		{name: timeout}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLatencyTestOnComplete)(VidyoLatencyTest* t, LmiVector(VidyoLatencyTestData) *data, LmiBool timeout, void* userData);

/**
{callback visibility="private":
	{name: VidyoLatencyTestOnFirstResponse}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: void (*VidyoLatencyTestOnFirstResponse)(VidyoLatencyTest* t, VidyoLatencyTestData *data, void* userData)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: data}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLatencyTestOnFirstResponse)(VidyoLatencyTest* t, VidyoLatencyTestData *data, void* userData);

/**
{function visibility="private":
	{name: VidyoLatencyTestConstruct}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: VidyoLatencyTest *VidyoLatencyTestConstruct(VidyoLatencyTest *t, VidyoTransport *transport, LmiAllocator *alloc)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: transport}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLatencyTest *VidyoLatencyTestConstruct(VidyoLatencyTest *t, VidyoTransport *transport, LmiAllocator *alloc);


/**
{function visibility="private":
	{name: VidyoLatencyTestConstructCopy}
	{parent: VidyoLatencyTest}
	{description: Constructs an VidyoLatencyTest object as a copy of another.}
	{prototype: VidyoLatencyTest *VidyoLatencyTestConstructCopy(VidyoLatencyTest *obj, const VidyoLatencyTest *other)}
	{parameter: {name: obj} {description: The VidyoLatencyTest object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestDestruct}
	{parent: VidyoLatencyTest}
	{description: Destructs an VidyoLatencyTest object.}
	{prototype: void VidyoLatencyTestDestruct(VidyoLatencyTest *obj)}
	{parameter: {name: obj} {description: The VidyoLatencyTest object to destruct.}}
}
*/

/**
{function visibility="private":
	{name: VidyoLatencyTestAssign}
	{parent: VidyoLatencyTest}
	{description: Assigns one VidyoLatencyTest object the value of another. }
	{prototype: VidyoLatencyTest *VidyoLatencyTestAssign(VidyoLatencyTest *obj, const VidyoLatencyTest *other)}
	{parameter: {name: obj} {description: The VidyoLatencyTest object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/


/**
{function visibility="private":
	{name: VidyoLatencyTestGetConfigAndRun}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: LmiBool VidyoLatencyTestGetConfigAndRun(VidyoLatencyTest* t, const LmiString *uriStr, LmiTime timeout, const VidyoTlsConfig *tlsConfig, VidyoLatencyTestOnFirstResponse onFirstResponse, VidyoLatencyTestOnComplete onComplete)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: uriStr}
		{description: }
	}
	{parameter:
		{name: timeout}
		{description: }
	}
	{parameter:
		{name: tlsConfig}
		{description: }
	}
	{parameter:
		{name: onFirstResponse}
		{description: }
	}
	{parameter:
		{name: onComplete}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLatencyTestGetConfigAndRun(VidyoLatencyTest* t, const LmiString *uriStr, LmiTime timeout, const VidyoTlsConfig *tlsConfig, VidyoLatencyTestOnFirstResponse onFirstResponse, VidyoLatencyTestOnComplete onComplete);

/**
{function visibility="private":
	{name: VidyoLatencyTestRun}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: LmiBool VidyoLatencyTestRun(VidyoLatencyTest* t, LmiVector(LmiString) *addresses, LmiUint port, LmiTime timeout, VidyoLatencyTestOnFirstResponse onFirstRespoinse, VidyoLatencyTestOnComplete onComplete)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: addresses}
		{description: }
	}
	{parameter:
		{name: port}
		{description: }
	}
	{parameter:
		{name: timeout}
		{description: }
	}
	{parameter:
		{name: onFirstRespoinse}
		{description: }
	}
	{parameter:
		{name: onComplete}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLatencyTestRun(VidyoLatencyTest* t, LmiVector(LmiString) *addresses, LmiUint port, LmiTime timeout, VidyoLatencyTestOnFirstResponse onFirstRespoinse, VidyoLatencyTestOnComplete onComplete);

/**
{function visibility="private":
	{name: VidyoLatencyTestStop}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: void VidyoLatencyTestStop(VidyoLatencyTest* t)}
	{parameter:
		{name: t}
		{description: }
	}
}
*/
void VidyoLatencyTestStop(VidyoLatencyTest* t);

/**
{function visibility="private":
	{name: VidyoLatencyTestSetUserData}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: void VidyoLatencyTestSetUserData(VidyoLatencyTest* t, LmiVoidPtr userData)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
void VidyoLatencyTestSetUserData(VidyoLatencyTest* t, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoLatencyTestGetUserData}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: LmiVoidPtr VidyoLatencyTestGetUserData(const VidyoLatencyTest* t)}
	{parameter:
		{name: t}
		{description: }
	}
	{return: }
}
*/
LmiVoidPtr VidyoLatencyTestGetUserData(const VidyoLatencyTest* t);

/**
{function visibility="private":
	{name: VidyoLatencyTestGetStats}
	{parent: VidyoLatencyTest}
	{description: }
	{prototype: void VidyoLatencyTestGetStats(VidyoLatencyTest* t, VidyoLatencyTestStats *stats)}
	{parameter:
		{name: t}
		{description: }
	}
	{parameter:
		{name: stats}
		{description: }
	}
}
*/
void VidyoLatencyTestGetStats(VidyoLatencyTest* t, VidyoLatencyTestStats *stats);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoLatencyTestInline.h"
#endif

#endif
