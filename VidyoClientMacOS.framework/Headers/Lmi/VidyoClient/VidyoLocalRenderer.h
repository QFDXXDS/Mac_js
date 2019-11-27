/** 
{file:
	{name: VidyoLocalRenderer.h}
	{description: Renderer device. }
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
#ifndef VIDYO_LOCALRENDERER_H_ 
#define VIDYO_LOCALRENDERER_H_ 

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Utils/LmiSet.h>
#include <Lmi/Utils/LmiUnorderedStringVoidPtrMap.h>
#include <Lmi/Os/LmiSharedPtr.h>
#include <Lmi/Os/LmiWindowId.h>

LMI_BEGIN_EXTERN_C

struct VidyoLocalRendererParticipantImpl_;
typedef struct VidyoLocalRendererParticipantImpl_ VidyoLocalRendererParticipantImpl;
Declare_LmiSharedPtr(VidyoLocalRendererParticipantImpl)
Declare_LmiSharedPtrWrapper(VidyoLocalRendererParticipant, VidyoLocalRendererParticipantImpl)
Declare_LmiUnorderedMap(LmiString, VidyoLocalRendererParticipant)

struct VidyoLocalRendererImpl_;
typedef struct VidyoLocalRendererImpl_ VidyoLocalRendererImpl;
Declare_LmiSharedPtr(VidyoLocalRendererImpl)
Declare_LmiSharedPtrWrapper(VidyoLocalRenderer, VidyoLocalRendererImpl)
Declare_LmiWeakPtrWrapper(VidyoLocalRendererHandle, VidyoLocalRenderer, VidyoLocalRendererImpl)
Declare_LmiVector(VidyoLocalRenderer)
Declare_LmiList(VidyoLocalRenderer)
Declare_LmiUnorderedMap(LmiString, VidyoLocalRenderer)

struct VidyoLocalRendererStreamImpl_;
typedef struct VidyoLocalRendererStreamImpl_ VidyoLocalRendererStreamImpl;
Declare_LmiSharedPtr(VidyoLocalRendererStreamImpl)
Declare_LmiSharedPtrWrapper(VidyoLocalRendererStream, VidyoLocalRendererStreamImpl)
Declare_LmiWeakPtrWrapper(VidyoLocalRendererStreamHandle, VidyoLocalRendererStream, VidyoLocalRendererStreamImpl)
Declare_LmiList(VidyoLocalRendererStream)
Declare_LmiSet(VidyoLocalRendererStreamHandle)

/**
{type apigroup="simple" reference-counted="yes":
	{name: VidyoLocalRenderer}
	{parent: Device}
	{include: Lmi/VidyoClient/VidyoLocalRenderer.h}
	{description: }
	{member:
		{name: id}
		{type: LmiString}
		{description: }
	}
	{member:
		{name: name}
		{type: LmiString}
		{description: }
	}
}
*/

/**
{type visibility="private":
	{name: VidyoLocalRendererHandle}
	{parent: VidyoLocalRenderer}
	{description: }
}
*/

/**
 {type apigroup="simple" visibility="public":
	{name: VidyoLocalRendererViewStyle}
	{parent: VidyoLocalRenderer}
	{description: Styles of the composite renderer, which apply to its layout and behaviour.}
	{value: {name: VIDYO_LOCALRENDERERVIEWSTYLE_Default}
		{description: The default style.}}
	{value: {name: VIDYO_LOCALRENDERERVIEWSTYLE_Tiles}
		{description: Participants are shown in sizes that best reflect their order of importance.}}
 	{value: {name: VIDYO_LOCALRENDERERVIEWSTYLE_TilesWithRemoteCameraControlV2}
 		{description: Participants are shown in sizes that best reflect their order of importance, with large Remote Camera Control buttons if applicable.}}
	{note: The default is currently VIDYO_LOCALRENDERERVIEWSTYLE_Tiles.}
}
*/
typedef enum
{
	VIDYO_LOCALRENDERERVIEWSTYLE_Default,
	VIDYO_LOCALRENDERERVIEWSTYLE_Tiles,
	VIDYO_LOCALRENDERERVIEWSTYLE_TilesWithRemoteCameraControlV2
} VidyoLocalRendererViewStyle;

/**
{type visibility="public" experimental="yes":
	{name: VidyoLocalRendererBorderStyle}
	{parent: VidyoLocalRenderer}
	{description: Controls the use of tile borders in the scene.}
	{value: {name: VIDYO_LOCALRENDERERBORDERSTYLE_None} {description: Do not put a border on any tiles.}}
	{value: {name: VIDYO_LOCALRENDERERBORDERSTYLE_Same} {description: Put the same colored border on each tile.}}
	{value: {name: VIDYO_LOCALRENDERERBORDERSTYLE_Highlight} {description: Put a border on each tile, but tiles
		associated with the highest ranked participant (as told to LmiConferenceSceneSetPreference) will
		have a different colored border than the others.}}
	{value: {name: VIDYO_LOCALRENDERERBORDERSTYLE_Flash} {description: Tiles associated with the highest ranked
		participant have a different colored border than the others. When the highest ranked participant changes,
		the border of the new highest ranked participant flashes momentarily.}}
}
*/
typedef enum
{
	VIDYO_LOCALRENDERERBORDERSTYLE_None,
	VIDYO_LOCALRENDERERBORDERSTYLE_Same,
	VIDYO_LOCALRENDERERBORDERSTYLE_Highlight,
	VIDYO_LOCALRENDERERBORDERSTYLE_Flash
} VidyoLocalRendererBorderStyle;

/**
 {type visibility="public" experimental="yes":
 {name: VidyoLocalRendererPipPosition}
 {parent: VidyoLocalRenderer}
 {description: Indicates the position of the preview with respect to one dimension.}
 {value: {name: VIDYO_LOCALRENDERERPIPPOSITION_MIN} {description: The preview is at its minimum value along this dimension.
 This means to the left for the horizontal position and down for the vertical position.}}
 {value: {name: VIDYO_LOCALRENDERERPIPPOSITION_CENTER} {description: The preview is centered with respect to this dimension.}}
 {value: {name: VIDYO_LOCALRENDERERPIPPOSITION_MAX} {description: The preview is at its maximum value along this dimension.
 This means to the right for the horizontal position and up for the vertical position.}}
 }
 */
typedef enum
{
    VIDYO_LOCALRENDERERPIPPOSITION_MIN,
    VIDYO_LOCALRENDERERPIPPOSITION_CENTER,
    VIDYO_LOCALRENDERERPIPPOSITION_MAX
} VidyoLocalRendererPipPosition;


LMI_END_EXTERN_C

#include "VidyoRoom.h"
#include "VidyoLocalMonitor.h"
#include "VidyoForwardDecl.h"
#include "VidyoStatistics.h"
#include "VidyoDevice.h"
#include "VidyoParticipant.h"

LMI_BEGIN_EXTERN_C

/**
{callback visibility="private":
	{name: VidyoLocalRendererCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererCallback)(const VidyoLocalRenderer* r, const VidyoLmiVideoFrame* videoFrame)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: videoFrame}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererCallback)(const VidyoLocalRenderer* r, const VidyoLmiVideoFrame* videoFrame);

/**
{callback visibility="private":
	{name: VidyoLocalRendererVirtualConstructCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer* (*VidyoLocalRendererVirtualConstructCallback)(VidyoLocalRenderer* s, LmiString* viewId, LmiVoidPtr virtualUserData, LmiAllocator *alloc)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: viewId}
		{description: }
	}
	{parameter:
		{name: virtualUserData}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
typedef VidyoLocalRenderer* (*VidyoLocalRendererVirtualConstructCallback)(VidyoLocalRenderer* s, LmiString* viewId, LmiVoidPtr virtualUserData, LmiAllocator *alloc);

/**
{callback visibility="private":
	{name: VidyoLocalRendererVirtualDestructCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererVirtualDestructCallback)(LmiString* viewId, LmiVoidPtr virtualUserData)}
	{parameter:
		{name: viewId}
		{description: }
	}
	{parameter:
		{name: virtualUserData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererVirtualDestructCallback)(LmiString* viewId, LmiVoidPtr virtualUserData);

/**
{function visibility="private":
	{name: VidyoLocalRendererRegisterVirtualCallbacks}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiBool VidyoLocalRendererRegisterVirtualCallbacks(VidyoLocalRendererVirtualConstructCallback onConstruct, VidyoLocalRendererVirtualDestructCallback onDestruct, LmiVoidPtr userData)}
	{parameter:
		{name: onConstruct}
		{description: }
	}
	{parameter:
		{name: onDestruct}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLocalRendererRegisterVirtualCallbacks(VidyoLocalRendererVirtualConstructCallback onConstruct, VidyoLocalRendererVirtualDestructCallback onDestruct, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStartCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererStartCallback)(const VidyoLocalRenderer* s, LmiSizeT width, LmiSizeT height, LmiTime frameInterval, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: width}
		{description: }
	}
	{parameter:
		{name: height}
		{description: }
	}
	{parameter:
		{name: frameInterval}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererStartCallback)(const VidyoLocalRenderer* s, LmiSizeT width, LmiSizeT height, LmiTime frameInterval, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStopCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererStopCallback)(const VidyoLocalRenderer* s, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererStopCallback)(const VidyoLocalRenderer* s, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererSetPositionCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererSetPositionCallback)(const VidyoLocalRenderer* s, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: x}
		{description: }
	}
	{parameter:
		{name: y}
		{description: }
	}
	{parameter:
		{name: width}
		{description: }
	}
	{parameter:
		{name: height}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererSetPositionCallback)(const VidyoLocalRenderer* s, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererLoudestParticipantCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererLoudestParticipantCallback)(const VidyoLocalRenderer* s, VidyoParticipant *participant, VidyoRemoteCamera *remoteCameras, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participant}
		{description: }
	}
	{parameter:
		{name: remoteCameras}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererLoudestParticipantCallback)(const VidyoLocalRenderer* s, VidyoParticipant *participant, VidyoRemoteCamera *remoteCameras, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererDynamicParticipantsCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererDynamicParticipantsCallback)(const VidyoLocalRenderer* s, LmiVector(VidyoParticipant) *participants, LmiVector(VidyoRemoteCamera) *remoteCameras, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participants}
		{description: }
	}
	{parameter:
		{name: remoteCameras}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererDynamicParticipantsCallback)(const VidyoLocalRenderer* s, LmiVector(VidyoParticipant) *participants, LmiVector(VidyoRemoteCamera) *remoteCameras, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStreamAddedCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiVoidPtr (*VidyoLocalRendererStreamAddedCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participant}
		{description: }
	}
	{parameter:
		{name: device}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
	{return: streamUserData}
}
*/
typedef LmiVoidPtr (*VidyoLocalRendererStreamAddedCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStreamRemovedCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererStreamRemovedCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participant}
		{description: }
	}
	{parameter:
		{name: device}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
	{parameter:
		{name: streamUserData}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererStreamRemovedCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStreamAddVideoFrameCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererStreamAddVideoFrameCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData, const VidyoLmiVideoFrame *videoFrame)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participant}
		{description: }
	}
	{parameter:
		{name: device}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
	{parameter:
		{name: streamUserData}
		{description: }
	}
	{parameter:
		{name: videoFrame}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererStreamAddVideoFrameCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData, const VidyoLmiVideoFrame *videoFrame);

/**
{callback visibility="private":
	{name: VidyoLocalRendererStreamSetLabelCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void (*VidyoLocalRendererStreamSetLabelCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData, const LmiString *label)}
	{parameter:
		{name: s}
		{description: }
	}
	{parameter:
		{name: participant}
		{description: }
	}
	{parameter:
		{name: device}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
	{parameter:
		{name: streamUserData}
		{description: }
	}
	{parameter:
		{name: label}
		{description: }
	}
}
*/
typedef void (*VidyoLocalRendererStreamSetLabelCallback)(const VidyoLocalRenderer* s, const VidyoParticipant *participant, const VidyoDevice *device, LmiVoidPtr userData, LmiVoidPtr streamUserData, const LmiString *label);


/**
{function visibility="private":
	{name: VidyoLocalRendererConstruct}
	{parent: VidyoLocalRenderer}
	{description: VidyoLocalRenderer object constructed from conference scene should also get notified about stream/slot changes by calling VidyoLocalRendererSetStreamParameters API.}
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstruct(VidyoLocalRenderer* r, VidyoLmiConferenceScene* conferenceScene, VidyoLocalMonitor* monitor, const LmiViewId* viewId, LmiUint width, LmiUint height, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: conferenceScene}
		{description: }
	}
	{parameter:
		{name: monitor}
		{description: }
	}
	{parameter:
		{name: viewId}
		{description: }
	}
	{parameter:
		{name: width}
		{description: }
	}
	{parameter:
		{name: height}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstruct(VidyoLocalRenderer* r, VidyoLmiConferenceScene* conferenceScene, VidyoLocalMonitor* monitor, const LmiViewId* viewId, LmiUint width, LmiUint height, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructFromMonitor}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstructFromMonitor(VidyoLocalRenderer* r, VidyoLocalMonitor* monitor, LmiUint width, LmiUint height, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: monitor}
		{description: }
	}
	{parameter:
		{name: width}
		{description: }
	}
	{parameter:
		{name: height}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
    }
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstructFromMonitor(VidyoLocalRenderer* r, VidyoLocalMonitor* monitor, LmiUint width, LmiUint height, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructFullScreen}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstructFullScreen(VidyoLocalRenderer* r, VidyoLocalMonitor* monitor, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: monitor}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstructFullScreen(VidyoLocalRenderer* r, VidyoLocalMonitor* monitor, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructMultiScreen}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstructMultiScreen(VidyoLocalRenderer* r, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstructMultiScreen(VidyoLocalRenderer* r, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructFromConferenceScene}
	{parent: VidyoLocalRenderer}
	{description: VidyoLocalRenderer object constructed from conference scene using this constructor should also get notified about stream/slot changes by calling VidyoLocalRendererSetStreamParameters API.}
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstructFromConferenceScene(VidyoLocalRenderer* r, VidyoLmiConferenceScene* conferenceScene, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: conferenceScene}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstructFromConferenceScene(VidyoLocalRenderer* r, VidyoLmiConferenceScene* conferenceScene, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructFromViewId}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer* VidyoLocalRendererConstructFromViewId(VidyoLocalRenderer* r, const LmiViewId* viewId, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiUint maxCropPctW, LmiUint maxCropPctH, LmiBool allowZoom, LmiBool useExpandedCameraControls, const LmiString *fontFileName, LmiAllocator* alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: viewId}
		{description: A platform specific parent view ID where the rendering window will be added as a child window.}
	}
	{parameter:
		{name: x}
		{description: X coordinate of the child window within the parent view ID. }
	}
	{parameter:
		{name: y}
		{description: Y coordinate of the child window within the parent view ID. }
	}
	{parameter:
		{name: width}
		{description: Width of the child window within the parent view ID. }
	}
	{parameter:
		{name: height}
		{description: Height of the child window within the parent view ID. }
	}
	{parameter:
		{name: maxCropPctW}
		{description: When fitting a video into a tile, this sets the maximum percentage of its width that can be cropped to achieve a better fit. }
	}
	{parameter:
		{name: maxCropPctH}
		{description: When fitting a video into a tile, this sets the maximum percentage of its height that can be cropped to achieve a better fit. }
	}
	{parameter:
		{name: allowZoom}
		{description: Indicates whether zooming in/out of the tile should be enabled. }
	}
 	{parameter:
 		{name: useExpandedCameraControls}
 		{description: Specifies whether to use expanded camera controls. If true, a separate button is provided for each direction. If false, a directional pad and zoom bar are used.}
 	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer* VidyoLocalRendererConstructFromViewId(VidyoLocalRenderer* r, const LmiViewId* viewId, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiUint maxCropPctW, LmiUint maxCropPctH, LmiBool allowZoom, LmiBool useExpandedCameraControls, const LmiString *fontFileName, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructVirtual}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer *VidyoLocalRendererConstructVirtual(VidyoLocalRenderer *r, const LmiString *id, const LmiString *name, VidyoLocalRendererStartCallback onStart, VidyoLocalRendererStopCallback onStop, VidyoLocalRendererSetPositionCallback onSetPosition, VidyoLocalRendererLoudestParticipantCallback onLoudestParticipant, VidyoLocalRendererDynamicParticipantsCallback onDynamicParticipants, VidyoLocalRendererStreamAddedCallback onStreamAdded, VidyoLocalRendererStreamRemovedCallback onStreamRemoved, VidyoLocalRendererStreamAddVideoFrameCallback onStreamAddVideoFrame, VidyoLocalRendererStreamSetLabelCallback onStreamSetLabel, LmiVoidPtr virtualUserData, const LmiString *fontFileName, LmiAllocator *alloc)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: id}
		{description: }
	}
	{parameter:
		{name: name}
		{description: }
	}
	{parameter:
		{name: onStart}
		{description: }
	}
	{parameter:
		{name: onStop}
		{description: }
	}
	{parameter:
		{name: onSetPosition}
		{description: }
	}
	{parameter:
		{name: onLoudestParticipant}
		{description: }
	}
	{parameter:
		{name: onDynamicParticipants}
		{description: }
	}
	{parameter:
		{name: onStreamAdded}
		{description: }
	}
	{parameter:
		{name: onStreamRemoved}
		{description: }
	}
	{parameter:
		{name: onStreamAddVideoFrame}
		{description: }
	}
	{parameter:
		{name: onStreamSetLabel}
		{description: }
	}
	{parameter:
		{name: virtualUserData}
		{description: }
	}
    {parameter:
        {name: fontFileName}
        {description: Path to the font file.}
    }
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer *VidyoLocalRendererConstructVirtual(VidyoLocalRenderer *r, const LmiString *id, const LmiString *name, VidyoLocalRendererStartCallback onStart, VidyoLocalRendererStopCallback onStop, VidyoLocalRendererSetPositionCallback onSetPosition, VidyoLocalRendererLoudestParticipantCallback onLoudestParticipant, VidyoLocalRendererDynamicParticipantsCallback onDynamicParticipants, VidyoLocalRendererStreamAddedCallback onStreamAdded, VidyoLocalRendererStreamRemovedCallback onStreamRemoved, VidyoLocalRendererStreamAddVideoFrameCallback onStreamAddVideoFrame, VidyoLocalRendererStreamSetLabelCallback onStreamSetLabel, LmiVoidPtr virtualUserData, const LmiString *fontFileName, LmiAllocator *alloc);

/**
{function:
	{name: VidyoLocalRendererConstructCopy}
	{parent: VidyoLocalRenderer}
	{description: Constructs an VidyoLocalRenderer object as a copy of another.}
	{prototype: VidyoLocalRenderer *VidyoLocalRendererConstructCopy(VidyoLocalRenderer *obj, const VidyoLocalRenderer *other)}
	{parameter: {name: obj} {description: The VidyoLocalRenderer object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoLocalRendererDestruct}
	{parent: VidyoLocalRenderer}
	{description: Destructs an VidyoLocalRenderer object.}
	{prototype: void VidyoLocalRendererDestruct(VidyoLocalRenderer *obj)}
	{parameter: {name: obj} {description: The VidyoLocalRenderer object to destruct.}}
}
*/

/**
{function visibility="private":
	{name: VidyoLocalRendererAssign}
	{parent: VidyoLocalRenderer}
	{description: Assigns one VidyoLocalRenderer object the value of another. }
	{prototype: VidyoLocalRenderer *VidyoLocalRendererAssign(VidyoLocalRenderer *obj, const VidyoLocalRenderer *other)}
	{parameter: {name: obj} {description: The VidyoLocalRenderer object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function:
	{name: VidyoLocalRendererDisable}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiBool VidyoLocalRendererDisable(VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLocalRendererDisable(VidyoLocalRenderer* r);

/**
{function visibility="private":
	{name: VidyoLocalRendererGetHandle}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRendererHandle* VidyoLocalRendererGetHandle(VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRendererHandle* VidyoLocalRendererGetHandle(VidyoLocalRenderer* r);

/**
{function visibility="private":
	{name: VidyoLocalRendererGetHandleConst}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype:const VidyoLocalRendererHandle *VidyoLocalRendererGetHandleConst(const VidyoLocalRenderer *r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
const VidyoLocalRendererHandle *VidyoLocalRendererGetHandleConst(const VidyoLocalRenderer *r);

/**
{function apigroup="simple":
	{name: VidyoLocalRendererGetId}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: const LmiString* VidyoLocalRendererGetId(const VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
const LmiString* VidyoLocalRendererGetId(const VidyoLocalRenderer* r);

/**
{function  apigroup="simple":
	{name: VidyoLocalRendererGetName}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: const LmiString* VidyoLocalRendererGetName(const VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
const LmiString* VidyoLocalRendererGetName(const VidyoLocalRenderer* r);

/**
{function visibility="private":
	{name: VidyoLocalRendererSetUserData}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void VidyoLocalRendererSetUserData(VidyoLocalRenderer* r, LmiVoidPtr userData)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
void VidyoLocalRendererSetUserData(VidyoLocalRenderer* r, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoLocalRendererGetUserData}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiVoidPtr VidyoLocalRendererGetUserData(const VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
LmiVoidPtr VidyoLocalRendererGetUserData(const VidyoLocalRenderer* r);

/**
{function visibility="private":
	{name: VidyoLocalRendererSetCallback}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void VidyoLocalRendererSetCallback(VidyoLocalRenderer* r, VidyoLocalRendererCallback callback)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: callback}
		{description: }
	}
}
*/
void VidyoLocalRendererSetCallback(VidyoLocalRenderer* r, VidyoLocalRendererCallback callback);

/**
{function:
	{name: VidyoLocalRendererIsPaused}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiBool VidyoLocalRendererIsPaused(const VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLocalRendererIsPaused(const VidyoLocalRenderer* r);

/**
{function:
	{name: VidyoLocalRendererPause}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void VidyoLocalRendererPause(VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
}
*/
void VidyoLocalRendererPause(VidyoLocalRenderer* r);

/**
{function:
	{name: VidyoLocalRendererResume}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void VidyoLocalRendererResume(VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: }
	}
}
*/
void VidyoLocalRendererResume(VidyoLocalRenderer* r);

/**
{function:
	{name: VidyoLocalRendererSetPosition}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: LmiBool VidyoLocalRendererSetPosition(VidyoLocalRenderer* r, LmiInt x, LmiInt y, LmiUint width, LmiUint height)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: x}
		{description: }
	}
	{parameter:
		{name: y}
		{description: }
	}
	{parameter:
		{name: width}
		{description: }
	}
	{parameter:
		{name: height}
		{description: }
	}
	{return: }
}
*/
LmiBool VidyoLocalRendererSetPosition(VidyoLocalRenderer* r, LmiInt x, LmiInt y, LmiUint width, LmiUint height);

/**
{function visibility="private":
	{name: VidyoLocalRendererSetStreamParameters}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: void VidyoLocalRendererSetStreamParameters(VidyoLocalRenderer* r, const VidyoLmiConferenceSceneStreamChange* streamChanges, LmiUint numStreamChanges, const VidyoLmiConferenceSceneSlotChange* slotChanges, LmiUint numSlotChanges)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: streamChanges}
		{description: }
	}
	{parameter:
		{name: numStreamChanges}
		{description: }
	}
	{parameter:
		{name: slotChanges}
		{description: }
	}
	{parameter:
		{name: numSlotChanges}
		{description: }
	}
}
*/
void VidyoLocalRendererSetStreamParameters(VidyoLocalRenderer* r, const VidyoLmiConferenceSceneStreamChange* streamChanges, LmiUint numStreamChanges, const VidyoLmiConferenceSceneSlotChange* slotChanges, LmiUint numSlotChanges);

/**
{function visibility="public":
	{name: VidyoLocalRendererSetMaxStreams}
	{parent: VidyoLocalRenderer}
	{description: Sets the maximum number of streams that can be displayed in the renderer.}
	{prototype: LmiBool VidyoLocalRendererSetMaxStreams(VidyoLocalRenderer *r, LmiUint numStreams)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: numStreams}
		{description: }
	}
	{return: }
	{note: This API will return failure if the conference scene has been constructed externally. }
}
*/
LmiBool VidyoLocalRendererSetMaxStreams(VidyoLocalRenderer *r, LmiUint numStreams);

/**
{function:
	{name: VidyoLocalRendererSetMaxStreamsMultiScreen}
	{parent: VidyoLocalRenderer}
	{description: Sets the maximum number of streams that can be displayed in the renderer.}
	{prototype: LmiBool VidyoLocalRendererSetMaxStreamsMultiScreen(VidyoLocalRenderer *r, LmiUint numStreams, LmiUint displayIndex)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: numStreams}
		{description: }
	}
	{parameter:
		{name: displayIndex}
		{description: }
	}
	{return: }
	{note: This API will return failure if the conference scene has been constructed externally. }
}
*/
LmiBool VidyoLocalRendererSetMaxStreamsMultiScreen(VidyoLocalRenderer *r, LmiUint numStreams, LmiUint displayIndex);

/**
{function:
	{name: VidyoLocalRendererSetPriorityMultiScreen}
	{parent: VidyoLocalRenderer}
	{description: Sets the priority of one of the screens.  Screens that have a smaller priority value will be considered higher priority,
		and will be	given more important items to display.}
	{prototype: LmiBool VidyoLocalRendererSetPriorityMultiScreen(VidyoLocalRenderer *r, LmiUint priority, LmiUint displayIndex)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: priority}
		{description: }
	}
	{parameter:
		{name: displayIndex}
		{description: }
	}
	{return: }
	{note: This API will return failure if the conference scene has been constructed externally. }
}
*/
LmiBool VidyoLocalRendererSetPriorityMultiScreen(VidyoLocalRenderer *r, LmiUint priority, LmiUint displayIndex);

/**
{function:
	{name: VidyoLocalRendererSetAllowPreviewMultiScreen}
	{parent: VidyoLocalRenderer}
	{description: Set whether preview tiles are allowed on the screen.}
	{prototype: LmiBool VidyoLocalRendererSetAllowPreviewMultiScreen(VidyoLocalRenderer *r, LmiBool allow, LmiUint displayIndex)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: allow}
		{description: }
	}
	{parameter:
		{name: displayIndex}
		{description: }
	}
	{return: }
	{note: This API will return failure if the conference scene has been constructed externally. }
}
*/
LmiBool VidyoLocalRendererSetAllowPreviewMultiScreen(VidyoLocalRenderer *r, LmiBool allow, LmiUint displayIndex);

/**
{function:
	{name: VidyoLocalRendererSetAllowContentMultiScreen}
	{parent: VidyoLocalRenderer}
	{description: Set whether content tiles are allowed on the screen.}
	{prototype: LmiBool VidyoLocalRendererSetAllowContentMultiScreen(VidyoLocalRenderer *r, LmiBool allow, LmiUint displayIndex)}
	{parameter:
		{name: r}
		{description: }
	}
	{parameter:
		{name: allow}
		{description: }
	}
	{parameter:
		{name: displayIndex}
		{description: }
	}
	{return: }
	{note: This API will return failure if the conference scene has been constructed externally. }
}
*/
LmiBool VidyoLocalRendererSetAllowContentMultiScreen(VidyoLocalRenderer *r, LmiBool allow, LmiUint displayIndex);

/**
{function visibility="private":
	{name: VidyoLocalRendererSetWatermark}
	{parent: VidyoLocalRenderer}
	{description: Fills the renderer with the watermark.}
	{prototype: LmiBool VidyoLocalRendererSetWatermark(VidyoLocalRenderer *renderer, const VidyoLmiVideoFrame *videoFrame)}
	{parameter: 
		{name: renderer}
		{description: The local renderer object.}
	}
	{parameter:
		{name: videoFrame}
		{description: The videoFrame to use as the watermark.}
	}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererSetWatermark(VidyoLocalRenderer *renderer, const VidyoLmiVideoFrame *videoFrame);

/**
{function visibility="private":
	{name: VidyoLocalRendererConstructFromDevice}
	{parent: VidyoLocalRenderer}
	{description: }
	{prototype: VidyoLocalRenderer *VidyoLocalRendererConstructFromDevice(VidyoLocalRenderer* vidyoLocalRenderer, VidyoDevice *device, LmiAllocator* alloc)}
	{parameter:
		{name: vidyoLocalRenderer}
		{description: }
	}
	{parameter:
		{name: device}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoLocalRenderer *VidyoLocalRendererConstructFromDevice(VidyoLocalRenderer* vidyoLocalRenderer, VidyoDevice *device, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoLocalRendererGetStats}
	{parent: VidyoLocalRenderer}
	{description: Fill in data in VidyoLocalRendererStats from a local renderer.}
	{prototype: LmiBool VidyoLocalRendererGetStats(VidyoLocalRenderer *renderer, VidyoLocalRendererStats *stats)}
	{parameter: {name: renderer} {description: The local renderer object to extract stats.}}
	{parameter: {name: stats} {description: The stats object to fill.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererGetStats(VidyoLocalRenderer *renderer, VidyoLocalRendererStats *stats);

/**
{function visibility="public":
	{name: VidyoLocalRendererShowDebugStats}
	{parent: VidyoLocalRenderer}
	{description: Shows debuggin statistics in the renderer window.}
	{prototype: LmiBool VidyoLocalRendererShowDebugStats(VidyoLocalRenderer *renderer, LmiBool showStats)}
	{parameter: {name: renderer} {description: The local renderer object to extract stats.}}
	{parameter: {name: showStats} {description: Show or hide statistics.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererShowDebugStats(VidyoLocalRenderer *r, LmiBool showStats);

/**
{function visibility="public":
	{name: VidyoLocalRendererShowLabel}
	{parent: VidyoLocalRenderer}
	{description: Shows a label with the participant name.}
	{prototype: LmiBool VidyoLocalRendererShowLabel(VidyoLocalRenderer *renderer, LmiBool showLabel)}
	{parameter: {name: renderer} {description: The local renderer object to show or hide the label.}}
	{parameter: {name: showLabel} {description: Show or hide participant label.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererShowLabel(VidyoLocalRenderer *r, LmiBool showLabel);

/**
{function visibility="public":
	{name: VidyoLocalRendererShowAudioMeters}
	{parent: VidyoLocalRenderer}
	{description: Shows or hides the audio meters.}
	{prototype: LmiBool VidyoLocalRendererShowAudioMeters(VidyoLocalRenderer *renderer, LmiBool showMeters)}
	{parameter: {name: renderer} {description: The local renderer object to show or hide the audio meters.}}
	{parameter: {name: showMeters} {description: Show or hide audio meters.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererShowAudioMeters(VidyoLocalRenderer *r, LmiBool showMeters);

/**
{function visibility="public":
	{name: VidyoLocalRendererSetAnimationSpeed}
	{parent: VidyoLocalRenderer}
	{description: If supported, sets the speed of transition animaiton 100 for slow, 0 for instant transition.}
	{prototype: LmiBool VidyoLocalRendererSetAnimationSpeed(VidyoLocalRenderer *renderer, LmiUint speedPercentage)}
	{parameter: {name: renderer} {description: The local renderer object to extract stats.}}
	{parameter: {name: speedPercentage} {description: Percentage of animation speed.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererSetAnimationSpeed(VidyoLocalRenderer *r, LmiUint speedPercentage);

/**
{function visibility="public":
	{name: VidyoLocalRendererSetBackgroundColor}
	{parent: VidyoLocalRenderer}
	{description: Sets the background color of the renderer.}
	{prototype: LmiBool VidyoLocalRendererSetBackgroundColor(VidyoLocalRenderer *renderer, LmiUint8 red, LmiUint8 green, LmiUint8 blue)}
	{parameter: {name: renderer} {description: The local renderer object to extract stats.}}
	{parameter: {name: red} {description: Red component of the color 0-255.}}
	{parameter: {name: green} {description: Green component of the color 0-255.}}
	{parameter: {name: blue} {description: Blue component of the color 0-255.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererSetBackgroundColor(VidyoLocalRenderer *r, LmiUint8 red, LmiUint8 green, LmiUint8 blue);

/**
{function visibility="public":
	{name: VidyoLocalRendererSetTilesBackgroundColor}
	{parent: VidyoLocalRenderer}
	{description: Sets the background color of the tiles.}
	{prototype: LmiBool VidyoLocalRendererSetTilesBackgroundColor(VidyoLocalRenderer *renderer, LmiUint8 red, LmiUint8 green, LmiUint8 blue)}
	{parameter: {name: renderer} {description: The local renderer object.}}
	{parameter: {name: red} {description: Red component of the color 0-255.}}
	{parameter: {name: green} {description: Green component of the color 0-255.}}
	{parameter: {name: blue} {description: Blue component of the color 0-255.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererSetTilesBackgroundColor(VidyoLocalRenderer *r, LmiUint8 red, LmiUint8 green, LmiUint8 blue);

/**
{function visibility="public":
	{name: VidyoLocalRendererSetCropped}
	{parent: VidyoLocalRenderer}
	{description: Sets the video screams to be croped in the renderer.}
	{prototype: LmiBool VidyoLocalRendererSetCropped(VidyoLocalRenderer *renderer, LmiBool cropped)}
	{parameter: {name: renderer} {description: The local renderer object to extract stats.}}
	{parameter: {name: cropped} {description: Crop if LMI_TRUE, letter box if LMI_FALSE.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoLocalRendererSetCropped(VidyoLocalRenderer *r, LmiBool cropped);

/**
{function:
	{name: VidyoLocalRendererEnableSelfViewCustomLayout}
	{parent: VidyoLocalRenderer}
	{description: Enable or disable the displaying of picture-in-picture in a custom way.}
	{prototype: void VidyoLocalRendererEnableSelfViewCustomLayout(VidyoLocalRenderer *renderer, LmiBool enable)}
	{parameter: {name: renderer} {description: The local renderer object.}}
	{parameter: {name: enable} {description: LMI_TRUE to always show picture-in-picture, LMI_FALSE to show picture-in-picture with two tiles.}}
}
*/
void VidyoLocalRendererEnableSelfViewCustomLayout(VidyoLocalRenderer *renderer, LmiBool enable);

/**
{function visibility="public" experimental="yes":
	{name: VidyoLocalRendererSetBorderStyle}
	{parent: VidyoLocalRenderer}
	{description: Controls the use of tile borders in the scene. See VidyoLocalRendererBorderStyle.}
	{prototype: void VidyoLocalRendererSetBorderStyle(VidyoLocalRenderer *ct, VidyoLocalRendererBorderStyle style)}
	{parameter: {name: ct} {description: The VidyoLocalRenderer object.}}
	{parameter: {name: style} {description: The new border style.}}
}
*/
void VidyoLocalRendererSetBorderStyle(VidyoLocalRenderer *ct, VidyoLocalRendererBorderStyle style);

/**
{callback:
	{name: VidyoLocalRendererOnPipLocationChanged}
	{parent: VidyoLocalRenderer}
	{description: Callback that is triggerred when picture-in-picture view size is changed.}
	{prototype: void VidyoLocalRendererOnPipLocationChanged(VidyoLocalRenderer* renderer, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiBool isExpanded)}
	{parameter:
		{name: renderer}
		{description: Pointer to the VidyoLocalRenderer that triggered the callback. }
	}
	{parameter:
		{name: x}
		{description: The horizontal position of the picture-in-picture view.}
	}
	{parameter:
		{name: y}
		{description: The vertical position of the picture-in-picture view.}
	}
	{parameter:
		{name: width}
		{description: Width of the picture-in-picture view.}
	}
	{parameter:
		{name: height}
		{description: Height of the picture-in-picture view.}
	}
	{parameter:
		{name: isExpanded}
		{description: LMI_TRUE if picture-in-picture is expanded and LMI_FALSE if collapsed.}
	}
}
*/
typedef void (*VidyoLocalRendererOnPipLocationChanged)(VidyoLocalRenderer* renderer, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiBool isExpanded);

/**
 {function apigroup="simple":
	{name: VidyoLocalRendererRegisterPipEventListener}
	{parent: VidyoLocalRenderer}
	{description: Registers to get notified when a a call is being recorded.}
	{prototype: LmiBool VidyoLocalRendererRegisterPipEventListener(VidyoLocalRenderer* r, VidyoLocalRendererOnPipLocationChanged onPipLocationChanged)}
	{parameter:
		{name: r}
		{description: The VidyoLocalRenderer object.}
	}
	{parameter:
		{name: onPipLocationChanged}
		{description: .}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
 }
*/
LmiBool VidyoLocalRendererRegisterPipEventListener(VidyoLocalRenderer* r, VidyoLocalRendererOnPipLocationChanged onPipLocationChanged);

/**
 {function apigroup="simple":
	{name: VidyoLocalRendererUnregisterPipEventListener}
	{parent: VidyoLocalRenderer}
	{description: Unregisters recorder in call event notifications.}
	{prototype: LmiBool VidyoLocalRendererUnregisterPipEventListener(VidyoLocalRenderer* r)}
	{parameter:
		{name: r}
		{description: The VidyoLocalRenderer object.}
	}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
 }
*/
LmiBool VidyoLocalRendererUnregisterPipEventListener(VidyoLocalRenderer* r);

/**
{function apigroup="simple":
	{name: VidyoLocalRendererIsSelectedTileControllingRemoteCamera}
	{parent: VidyoLocalRenderer}
	{description: Query whether the currently-selected tile, if any, is in far-end camera-control (FECC) mode.}
	{prototype: LmiBool VidyoLocalRendererIsSelectedTileControllingRemoteCamera(VidyoLocalRenderer *r)}
	{parameter: {name: r} {description: The VidyoLocalRenderer object.}}
	{return: LMI_TRUE if a tile is selected and it's in FECC mode; otherwise, LMI_FALSE.}
}
*/
LmiBool VidyoLocalRendererIsSelectedTileControllingRemoteCamera(VidyoLocalRenderer *r);


/**
{function apigroup="simple":
 	{name: VidyoLocalRendererSetParametersForHighDPIDevice}
 	{parent: VidyoLocalRenderer}
 	{description: Set renderer parameters for high DPI devices.}
 	{prototype: LmiBool VidyoLocalRendererSetParametersForHighDPIDevice(const VidyoLocalRenderer* r, LmiFloat32 pixelsPerInch, LmiFloat32 viewingDistance, LmiBool isTouchInputDevice)}
 	{parameter: {name: r} {description: The VidyoLocalRenderer object.}}
 	{parameter: {name: pixelsPerInch} {description: The number of pixels per inch.}}
 	{parameter: {name: viewingDistance} {description: The distance between user's eye to the device (in foot).}}
 	{parameter: {name: isTouchInputDevice} {description: To indicate input method of this device is TOUCH (vs default MOUSE input).}}
 	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoLocalRendererSetParametersForHighDPIDevice(const VidyoLocalRenderer* r, LmiFloat32 pixelsPerInch, LmiFloat32 viewingDistance, LmiBool isTouchInputDevice);


/**
{function apigroup="simple":
       {name: VidyoLocalRendererPinParticipant}
       {parent: VidyoLocalRenderer}
       {description: Pin or un-pin target participant camera. Pinned participant camera stream is always displayed unless muted. A single participant can be pinned at a time; subsequent pin will unpin previously pinned participant.}
       {prototype: LmiBool VidyoLocalRendererPinParticipant(const VidyoLocalRenderer* r, const VidyoParticipant* p, LmiBool pin)}
       {parameter: {name: r} {description: The VidyoLocalRenderer object.}}
       {parameter: {name: p} {description: The target participant.}}
       {parameter: {name: pin} {description: LMI_TRUE enable, LMI_FALSE for disable participant pin.}}
       {return: LMI_TRUE if pin setting was successfully applied, otherwise LMI_FALSE.}
}
*/
LmiBool VidyoLocalRendererPinParticipant(const VidyoLocalRenderer* r, const VidyoParticipant* p, LmiBool pin);

/**
{function visibility="public":
    {name: VidyoLocalRendererSetPipPosition}
    {parent: VidyoLocalRenderer}
    {description: Sets the position of the preview when it is displayed using picture-in-picture mode.}
    {prototype: LmiBool VidyoLocalRendererSetPipPosition(VidyoLocalRenderer *r, VidyoLocalRendererPipPosition x, VidyoLocalRendererPipPosition y, LmiBool lockPip)}
    {parameter: {name: r} {description: The VidyoLocalRenderer object.}}
    {parameter: {name: x} {description: The horizontal position of the preview.}}
    {parameter: {name: y} {description: The vertical position of the preview.}}
    {parameter: {name: lockPip} {description: A boolean indicating whether to lock the preview in this position. When false, the user may drag the preview
    to another location using the mouse or a touch.}}
    {return: LMI_TRUE if position was set successfully, otherwise LMI_FALSE.}
    {note: The picture-in-picture preview is in the bottom right and unlocked by default.}
    {note: This setting has no effect when the preview is shown as a regular tile (that is not overlapped).}
}
*/
LmiBool VidyoLocalRendererSetPipPosition(VidyoLocalRenderer *r, VidyoLocalRendererPipPosition x, VidyoLocalRendererPipPosition y, LmiBool lockPip);

/**
 {function visibility="public":
 {name: VidyoLocalRendererSetRemoteWindowSharePinMode}
 {parent: VidyoLocalRenderer}
 {description: Set if renderer will automatically pin the share when added and pin/unpin share if already exist.}
 {prototype: LmiBool VidyoLocalRendererSetRemoteWindowSharePinMode(VidyoLocalRenderer* r, LmiBool autoPin)}
 {parameter: {name: r} {description: The VidyoLocalRenderer object.}}
 {parameter: {name: autoPin} {description: LMI_TRUE to automatically pin the share when added and pin the first share from list if exist.
 LMI_FALSE to do not pin the share automatically when added and unpin the share if exist and already pinned.}}
 {return: LMI_TRUE on success, otherwise LMI_FALSE.}
 }
 */
LmiBool VidyoLocalRendererSetRemoteWindowSharePinMode(VidyoLocalRenderer* r, LmiBool autoPin);


LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoLocalRendererInline.h"
#endif

#endif /* VIDYO_LOCALRENDERER_H_ */
