/** 
{file:
	{name: VidyoVideoFrame.h}
	{description: Monitor available for sharing. }
	{copyright:
		(c) 2013-2016 Vidyo, Inc.,
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
#ifndef VIDYO_VIDEOFRAME_H_ 
#define VIDYO_VIDEOFRAME_H_ 

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Video/Common/LmiVideoFrame.h>
#include "VidyoMediaFormats.h"


LMI_BEGIN_EXTERN_C

struct VidyoVideoFrameImpl_;
typedef struct VidyoVideoFrameImpl_ VidyoVideoFrameImpl;
Declare_LmiSharedPtr(VidyoVideoFrameImpl)
Declare_LmiSharedPtrWrapper(VidyoVideoFrame, VidyoVideoFrameImpl)
Declare_LmiWeakPtrWrapper(VidyoVideoFrameHandle, VidyoVideoFrame, VidyoVideoFrameImpl)
Declare_LmiVector(VidyoVideoFrame)
Declare_LmiList(VidyoVideoFrame)

/**
{type apigroup="connector,simple" reference-counted="yes":
	{name: VidyoVideoFrame}
	{parent: Device}
	{include: Lmi/VidyoClient/VidyoVideoFrame.h}
	{description: This object represents a video frame.}
	{member:
		{name: data}
		{type: LmiUint8*}
		{description: Pointer to the frame\'s payload.}
	}
	{member:
		{name: size}
		{type: LmiSizeT}
		{description: Size in bytes of the frame\'s payload.}
	}
	{member:
		{name: width}
		{type: LmiSizeT}
		{description: Width of the video frame.}
	}
	{member:
		{name: height}
		{type: LmiSizeT}
		{description: Height of the video frame.}
	}
	{member:
		{name: dataY}
		{type: LmiVoidPtr}
		{description: Pointer to the frame\'s payload.}
	}
	{member:
		{name: offsetY}
		{type: LmiSizeT}
		{description: Number of bytes from the plane\'s payload to the start of the pixel data.}
	}
	{member:
		{name: sizeY}
		{type: LmiSizeT}
		{description: Size in bytes of the plane\'s payload.}
	}
	{member:
		{name: pitchY}
		{type: LmiSizeT}
		{description: Number of bytes between consecutive pixels in a row of the plane.}
	}
	{member:
		{name: widthY}
		{type: LmiSizeT}
		{description: Width in bytes of the frame\'s Y pixel data.}
	}
	{member:
		{name: heightY}
		{type: LmiSizeT}
		{description: Height in bytes of the frame\'s Y pixel data.}
	}
	{member:
		{name: dataCb}
		{type: LmiVoidPtr}
		{description: Pointer to the frame\'s payload.}
	}
	{member:
		{name: offsetCb}
		{type: LmiSizeT}
		{description: Number of bytes from the plane\'s payload to the start of the pixel data.}
	}
	{member:
		{name: sizeCb}
		{type: LmiSizeT}
		{description: Size in bytes of the plane\'s payload.}
	}
	{member:
		{name: pitchCb}
		{type: LmiSizeT}
		{description: Number of bytes between consecutive pixels in a row of the plane.}
	}
	{member:
		{name: widthCb}
		{type: LmiSizeT}
		{description: Width in bytes of the frame\'s Cb pixel data.}
	}
	{member:
		{name: heightCb}
		{type: LmiSizeT}
		{description: Height in bytes of the frame\'s Cb pixel data.}
	}
	{member:
		{name: dataCr}
		{type: LmiVoidPtr}
		{description: Pointer to the frame\'s payload.}
	}
	{member:
		{name: offsetCr}
		{type: LmiSizeT}
		{description: Number of bytes from the plane\'s payload to the start of the pixel data.}
	}
	{member:
		{name: sizeCr}
		{type: LmiSizeT}
		{description: Size in bytes of the plane\'s payload.}
	}
	{member:
		{name: pitchCr}
		{type: LmiSizeT}
		{description: Number of bytes between consecutive pixels in a row of the plane.}
	}
	{member:
		{name: widthCr}
		{type: LmiSizeT}
		{description: Width in bytes of the frame\'s Cr pixel data.}
	}
	{member:
		{name: heightCr}
		{type: LmiSizeT}
		{description: Height in bytes of the frame\'s Cr pixel data.}
	}
	{member:
		{name: format}
		{type: LmiString}
		{description: Format of the video frame.}
	}
	{member:
		{name: elapsedTime}
		{type: LmiTime}
		{description: Elapsed time since the beginning of frame capture that is increased by the duration of each frame.}
	}
	{member:
		{name: timestamp}
		{type: LmiTime}
		{description: Wallclock timestamp associated with the creation of the audio frame object.}
	}
}
*/

/**
{callback:
	{name: VidyoVideoFrameReleaseCallback}
	{parent: VidyoVideoFrame}
	{description: Describes a callback used to release externally allocated buffer memory of an VidyoVideoFrame.}
	{prototype: void (*VidyoVideoFrameReleaseCallback)(void* buffer, LmiSizeT size, LmiAllocator* alloc)}
	{parameter:	{name: buffer} {description: The buffer to be released.}}
	{parameter:	{name: size} {description: The size of the buffer.}}
	{parameter:	{name: alloc}{description: The allocator used to allocate the buffer. {code:alloc} can be NULL, for example, if the buffer memory was statically allocated.}}
}
*/

typedef void(*VidyoVideoFrameReleaseCallback)(void* buffer, LmiSizeT size, LmiAllocator* alloc);

/**
{function visibility="public":
	{name: VidyoVideoFrameConstructFromKnownFormatWithExternalBuffer}
	{parent: VidyoVideoFrame}
	{description: Constructs a video frame with externally-allocated memory to hold the frame\'s pixel data.}
	{prototype: VidyoVideoFrame* VidyoVideoFrameConstructFromKnownFormatWithExternalBuffer(VidyoVideoFrame* x, const VidyoMediaFormat format, LmiUint8* buffer, LmiSizeT size, LmiAllocator* bufferAlloc, VidyoVideoFrameReleaseCallback releaseCallback, LmiSizeT width, LmiSizeT height, LmiAllocator* alloc)}
	{parameter: {name: x} {description: A video frame object to construct.}}
	{parameter: {name: format} {description: The media format of the video frame.}}
	{parameter: {name: buffer} {description: A pointer to externally allocated memory that holds the pixel data.}}
	{parameter: {name: size} {description: The size, in bytes, of the frame data.}}
	{parameter: {name: bufferAlloc} {description: External allocator for frame-buffer data.}}
	{parameter: {name: releaseCallback}{description: A callback to be called on when external buffer may be reclaimed.}}
	{parameter: {name: width} {description: The width of the video media frame in pixels.}}
	{parameter: {name: height} {description: The height of the video media frame in pixels.}}
	{parameter: {name: alloc} {description: An allocator for non-frame-buffer data.}}
	{return: Returns a pointer to a constructed object on success, or NULL on failure.}
	{note: This constructor will not make an internal copy of the frame buffer.}
}
*/
VidyoVideoFrame* VidyoVideoFrameConstructFromKnownFormatWithExternalBuffer(VidyoVideoFrame* x, const VidyoMediaFormat format, LmiUint8* buffer, LmiSizeT size, LmiAllocator* bufferAlloc, VidyoVideoFrameReleaseCallback releaseCallback, LmiSizeT width, LmiSizeT height, LmiAllocator* alloc);

/**
{function apigroup="connector,simple":
	{name: VidyoVideoFrameConstructCopy}
	{parent: VidyoVideoFrame}
	{description: Constructs an VidyoVideoFrame object as a copy of another.}
	{prototype: VidyoVideoFrame *VidyoVideoFrameConstructCopy(VidyoVideoFrame *obj, const VidyoVideoFrame *other)}
	{parameter: {name: obj} {description: The VidyoVideoFrame object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVideoFrameDestruct}
	{parent: VidyoVideoFrame}
	{description: Destructs an VidyoVideoFrame object.}
	{prototype: void VidyoVideoFrameDestruct(VidyoVideoFrame *obj)}
	{parameter: {name: obj} {description: The VidyoVideoFrame object to destruct.}}
}
*/

/**
{function apigroup="connector,simple" visibility="private":
	{name: VidyoVideoFrameAssign}
	{parent: VidyoVideoFrame}
	{description: Assigns one VidyoVideoFrame object the value of another. }
	{prototype: VidyoVideoFrame *VidyoVideoFrameAssign(VidyoVideoFrame *obj, const VidyoVideoFrame *other)}
	{parameter: {name: obj} {description: The VidyoVideoFrame object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoVideoFrameSetUserData}
	{parent: VidyoVideoFrame}
	{description: }
	{prototype: void VidyoVideoFrameSetUserData(VidyoVideoFrame* f, LmiVoidPtr userData)}
	{parameter:
		{name: f}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
void VidyoVideoFrameSetUserData(VidyoVideoFrame* f, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoVideoFrameGetUserData}
	{parent: VidyoVideoFrame}
	{description: }
	{prototype: LmiVoidPtr VidyoVideoFrameGetUserData(const VidyoVideoFrame* f)}
	{parameter:
		{name: f}
		{description: }
	}
	{return: }
}
*/
LmiVoidPtr VidyoVideoFrameGetUserData(const VidyoVideoFrame* f);

/**
{function apigroup="connector,simple":
	{name: VidyoVideoFrameGetWidth}
	{parent: VidyoVideoFrame}
	{description: Gets the width of the frame.}
	{prototype: LmiSizeT VidyoVideoFrameGetWidth(const VidyoVideoFrame* f)}
	{parameter:
		{name: f}
		{description: The VidyoVideoFrame object. }
	}
	{return: Width of the frame.}
}
*/
LmiSizeT VidyoVideoFrameGetWidth(const VidyoVideoFrame* f);

/**
{function apigroup="connector,simple":
	{name: VidyoVideoFrameGetHeight}
	{parent: VidyoVideoFrame}
	{description: Gets the height of the frame.}
	{prototype: LmiSizeT VidyoVideoFrameGetHeight(const VidyoVideoFrame* f)}
	{parameter:
		{name: f}
		{description: The VidyoVideoFrame object. }
	}
	{return: Height of the frame.}
}
*/
LmiSizeT VidyoVideoFrameGetHeight(const VidyoVideoFrame* f);

/**
{function apigroup="connector,simple":
	{name: VidyoVideoFrameGetFormat}
	{parent: VidyoVideoFrame}
	{description: Gets the format of the frame.}
	{prototype: const LmiString* VidyoVideoFrameGetFormat(const VidyoVideoFrame* f)}
	{parameter:
		{name: f}
		{description: The VidyoVideoFrame object. }
	}
	{return: Format of the video frame.}
}
*/
const LmiString* VidyoVideoFrameGetFormat(const VidyoVideoFrame* f);

/**
 {function apigroup="connector,simple" visibility="private":
 {name: VidyoVideoFrameGetData}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiUint8* VidyoVideoFrameGetData(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiUint8* VidyoVideoFrameGetData(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetSize}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetSize(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetSize(const VidyoVideoFrame *f);

/**
{function apigroup="connector,simple":
{name: VidyoVideoFrameGetDataY}
{parent: VidyoVideoFrame}
{description: }
{prototype: LmiVoidPtr VidyoVideoFrameGetDataY(const VidyoVideoFrame *f)}
{parameter:
{name: f}
{description: The VidyoVideoFrame object. }
}
{return:}
}
*/
LmiVoidPtr VidyoVideoFrameGetDataY(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetOffsetY}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetOffsetY(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetOffsetY(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetSizeY}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetSizeY(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetSizeY(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetPitchY}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetPitchY(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetPitchY(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetWidthY}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetWidthY(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetWidthY(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetHeightY}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetHeightY(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetHeightY(const VidyoVideoFrame *f);

/**
{function apigroup="connector,simple":
{name: VidyoVideoFrameGetDataCb}
{parent: VidyoVideoFrame}
{description: }
{prototype: LmiVoidPtr VidyoVideoFrameGetDataCb(const VidyoVideoFrame *f)}
{parameter:
{name: f}
{description: The VidyoVideoFrame object. }
}
{return:}
}
*/
LmiVoidPtr VidyoVideoFrameGetDataCb(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetOffsetCb}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetOffsetCb(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetOffsetCb(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetSizeCb}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetSizeCb(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetSizeCb(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetPitchCb}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetPitchCb(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetPitchCb(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetWidthCb}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetWidthCb(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetWidthCb(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetHeightCb}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetHeightCb(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetHeightCb(const VidyoVideoFrame *f);

/**
{function apigroup="connector,simple":
{name: VidyoVideoFrameGetDataCr}
{parent: VidyoVideoFrame}
{description: }
{prototype: LmiVoidPtr VidyoVideoFrameGetDataCr(const VidyoVideoFrame *f)}
{parameter:
{name: f}
{description: The VidyoVideoFrame object. }
}
{return:}
}
*/
LmiVoidPtr VidyoVideoFrameGetDataCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetOffsetCr}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetOffsetCr(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetOffsetCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetSizeCr}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetSizeCr(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetSizeCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetPitchCr}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetPitchCr(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetPitchCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetWidthCr}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetWidthCr(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetWidthCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetHeightCr}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiSizeT VidyoVideoFrameGetHeightCr(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiSizeT VidyoVideoFrameGetHeightCr(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetElapsedTime}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiTime VidyoVideoFrameGetElapsedTime(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiTime VidyoVideoFrameGetElapsedTime(const VidyoVideoFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoVideoFrameGetTimestamp}
 {parent: VidyoVideoFrame}
 {description: }
 {prototype: LmiTime VidyoVideoFrameGetTimestamp(const VidyoVideoFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoVideoFrame object. }
 }
 {return:}
 }
 */
LmiTime VidyoVideoFrameGetTimestamp(const VidyoVideoFrame *f);


/**
{function visibility="private":
	{name: VidyoVideoFrameGetVideoFrame}
	{parent: VidyoVideoFrame}
	{description: }
	{prototype: LmiVideoFrame* VidyoVideoFrameGetVideoFrame(const VidyoVideoFrame *f)}
	{parameter:
		{name: f}
		{description: The VidyoVideoFrame object. }
	}
	{return:}
}
*/
LmiVideoFrame* VidyoVideoFrameGetVideoFrame(const VidyoVideoFrame *f);


#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoVideoFrameInline.h"
#endif

LMI_END_EXTERN_C

#endif /* VIDYO_VIDEOFRAME_H_ */
