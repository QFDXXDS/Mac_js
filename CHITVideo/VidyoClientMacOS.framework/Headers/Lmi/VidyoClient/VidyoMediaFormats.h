/**
{file:
	{name: VidyoVideoCapability.h}
	{description: Video Capability. }
	{copyright:
		(c) 2015 Vidyo, Inc.,
		433 Hackensack Avenue, 6th Floor,
		Hackensack, NJ  07601.
		All rights reserved.
		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.}
}
*/
#ifndef VIDYO_MEDIAFORMATS_H_
#define VIDYO_MEDIAFORMATS_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiMediaFormat.h>
#include <Lmi/Os/LmiTime.h>
#include <Lmi/Video/Common/LmiVideoFrame.h>

LMI_BEGIN_EXTERN_C

/**
{type apigroup="connector,simple" visibility="public":
	{name: VidyoMediaFormat}
	{parent: Endpoint}
	{include: Lmi/VidyoClient/VidyoMediaFormats.h}
	{description: Represents the media format.}
	{value: {name: VIDYO_MEDIAFORMAT_IN16}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_FL32}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_NULL}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_I420}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_YU12}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_YUYV}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_YUY2}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_yuvs}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_2vuy}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_UYVY}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_HDYC}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_yuv2}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_yuvu}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_NV12}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_NV21}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_24BG}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_raw}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_BGRA}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_RGBA}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_ARGB}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_BYR1}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_BYR2}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_JPEG}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_MJPG}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_dmb1}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_avc1}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_hvc1}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_M420}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_420f}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_420v}
			{description:}
	}
	{value: {name: VIDYO_MEDIAFORMAT_Y8}
			{description:}
	}
}
*/
typedef enum
{
	VIDYO_MEDIAFORMAT_IN16,
	VIDYO_MEDIAFORMAT_FL32,
	VIDYO_MEDIAFORMAT_NULL,
	VIDYO_MEDIAFORMAT_I420,
	VIDYO_MEDIAFORMAT_YU12,
	VIDYO_MEDIAFORMAT_YUYV,
	VIDYO_MEDIAFORMAT_YUY2,
	VIDYO_MEDIAFORMAT_yuvs,
	VIDYO_MEDIAFORMAT_2vuy,
	VIDYO_MEDIAFORMAT_UYVY,
	VIDYO_MEDIAFORMAT_HDYC,
	VIDYO_MEDIAFORMAT_yuv2,
	VIDYO_MEDIAFORMAT_yuvu,
	VIDYO_MEDIAFORMAT_NV12,
	VIDYO_MEDIAFORMAT_NV21,
	VIDYO_MEDIAFORMAT_24BG,
	VIDYO_MEDIAFORMAT_raw,
	VIDYO_MEDIAFORMAT_BGRA,
	VIDYO_MEDIAFORMAT_RGBA,
	VIDYO_MEDIAFORMAT_ARGB,
	VIDYO_MEDIAFORMAT_BYR1,
	VIDYO_MEDIAFORMAT_BYR2,
	VIDYO_MEDIAFORMAT_JPEG,
	VIDYO_MEDIAFORMAT_MJPG,
	VIDYO_MEDIAFORMAT_dmb1,
	VIDYO_MEDIAFORMAT_avc1,
	VIDYO_MEDIAFORMAT_hvc1,
	VIDYO_MEDIAFORMAT_M420,
	VIDYO_MEDIAFORMAT_420f,
	VIDYO_MEDIAFORMAT_420v,
	VIDYO_MEDIAFORMAT_Y8
} VidyoMediaFormat;

/**
{type visibility="public":
	{name: VidyoVideoPlane}
	{parent: Endpoint}
	{include: Lmi/VidyoClient/VidyoMediaFormats.h}
	{description: Describes a plane of a video frame.}
	{member:
		{name: buffer}
		{type: LmiUint8*}
		{description: pointer to the plane buffer.}
	}
	{member:
		{name: size}
		{type: LmiSizeT}
		{description: The size in bytes of the buffer.}
	}
	{member:
		{name: width}
		{type: LmiSizeT}
		{description: The width in pixels of the plane.}
	}
	{member:
		{name: height}
		{type: LmiSizeT}
		{description: The number of pitch sized rows in the plane buffer.}
	}
	{member:
		{name: pitch}
		{type: LmiSizeT}
		{description: The number of bytes in each row of the plane buffer.}
	}
	{member:
		{name: offset}
		{type: LmiSizeT}
		{description: The number of bytes of padding before any rows of the image.}
	}
}
*/
typedef struct {
	LmiUint8* buffer;
	LmiSizeT size;
	LmiSizeT width;
	LmiSizeT height;
	LmiSizeT pitch;
	LmiSizeT pixelPitch;
	LmiSizeT offset;
} VidyoVideoPlane;

Declare_LmiSimpleStruct(VidyoVideoPlane);

Declare_LmiVector(VidyoVideoPlane)

LmiBool VidyoMediaFormatLess(const VidyoMediaFormat* x, const VidyoMediaFormat* y);
LmiBool VidyoMediaFormatEqual(const VidyoMediaFormat* x, const VidyoMediaFormat* y);
VidyoMediaFormat* VidyoMediaFormatConstructCopy(VidyoMediaFormat* x, const VidyoMediaFormat* y);
void VidyoMediaFormatDestruct(VidyoMediaFormat* x);
VidyoMediaFormat* VidyoMediaFormatAssign(VidyoMediaFormat* x, const VidyoMediaFormat* y);
VidyoMediaFormat VidyoMediaFormatConvertLmiMediaFormat(LmiMediaFormat format);
LmiMediaFormat VidyoMediaFormatConvertToLmiMediaFormat(VidyoMediaFormat format);

LmiVideoPlane VidyoVideoPlaneConvertToLmiVideoPlane(VidyoVideoPlane plane);

Declare_LmiVector(VidyoMediaFormat)
Declare_LmiVectorEqual(VidyoMediaFormat)

LMI_END_EXTERN_C

#endif /* VIDYO_MEDIAFORMATS_H_ */
