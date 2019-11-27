/**
{file:
	{name: LmiStackTrace.h}
	{description: Utilities for capturing the current call stack.}
	{copyright:
		(c) 2006-2018 Vidyo, Inc.,
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
#ifndef LMI_STACKTRACE_H
#define LMI_STACKTRACE_H

#include <Lmi/Utils/LmiTypes.h>

LMI_BEGIN_EXTERN_C

/**
{package:
	{name: StackTrace}
	{parent: Utils}
	{include: Lmi/Utils/LmiStackTrace.h}
	{library: LmiUtils}
	{description: Utilities for capturing the current call stack.}
}
*/

/**
{function visibility="private":
	{name: LmiStackTraceCapture}
	{parent: StackTrace}
	{description: Capture the current call stack.}
	{prototype: LmiSizeT LmiStackTraceCapture(void **callStack, LmiSizeT size, LmiSizeT skip)}
	{parameter: {name: callStack} {description: The call stack will be written into this array.}}
	{parameter: {name: size} {description: The number of elements the array can hold.}}
	{parameter: {name: skip} {description: The number of lowest stack frames to skip.}}
	{return: The number of addresses written into the array.}
}
*/
LmiSizeT LmiStackTraceCapture(void **callStack, LmiSizeT size, LmiSizeT skip);

/**
{function visibility="private":
	{name: LmiStackTraceResolve}
	{parent: StackTrace}
	{description: Resolve a captured stack trace into symbolic names.}
	{prototype: void LmiStackTraceResolve(void **callStack, LmiSizeT size, char *buffer, LmiSizeT bufferLength, const char *separator)}
	{parameter: {name: callStack} {description: The call stack.}}
	{parameter: {name: size} {description: The number of addresses in the call stack.}}
	{parameter: {name: buffer} {description: A buffer to write the symbolic names into.}}
	{parameter: {name: bufferLength} {description: The size of the buffer in bytes.}}
	{parameter: {name: separator} {description: A string to write between the encodings of stack frames.}}
	{note: this can be a very expensive operation on some platforms, and is not always possible.}
}
*/
void LmiStackTraceResolve(void **callStack, LmiSizeT size, char *buffer, LmiSizeT bufferLength, const char *separator);

/**
{function visibility="private":
	{name: LmiStackTrace}
	{parent: StackTrace}
	{description: Fills out the buffer of the specified length with the stack trace info.}
	{prototype: char* LmiStackTrace(char* buffer, LmiSizeT bufferLength, LmiUint depth, LmiBool resolve, const char* separator)}
	{parameter: {name: buffer} {description: Pointer to the buffer into which stack trace is to be written.}}
	{parameter: {name: bufferLength} {description: The size of the buffer in bytes.}}
	{parameter: {name: depth} {description: The maximum number of stack frames to trace.}}
	{parameter: {name: resolve} {description: Whether to resolve the addresses to symbols.  Note this can be a very expensive operation on some platforms, and is not always possible.}}
	{parameter: {name: separator} {description: Separator string to use between consecutive stack trace entries.}}
	{return: Pointer to the buffer passed in as a parameter on success, or {code: NULL} on failure.}
}
*/
char* LmiStackTrace(char* buffer, LmiSizeT bufferLength, LmiUint depth, LmiBool resolve, const char* separator);

/**
{function visibility="private":
	{name: LmiStackTraceInitialize}
	{parent: StackTrace}
	{description: Initializes the Stack Trace module.}
	{prototype: LmiBool LmiStackTraceInitialize(void)}
	{return: {code: LMI_TRUE} on success, or {code: LMI_FALSE} on failure.}
}
*/
LmiBool LmiStackTraceInitialize(void);

/**
{function visibility="private":
	{name: LmiStackTraceUninitialize}
	{parent: StackTrace}
	{description: Uninitializes the Stack Trace module.}
	{prototype: void LmiStackTraceUninitialize(void)}
}
*/
void LmiStackTraceUninitialize(void);

LMI_END_EXTERN_C

#endif
