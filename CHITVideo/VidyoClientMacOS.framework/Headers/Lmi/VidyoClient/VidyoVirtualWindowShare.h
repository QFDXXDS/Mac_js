#ifndef VIDYO_VIRTUALWINDOWSHARE_H_
#define VIDYO_VIRTUALWINDOWSHARE_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Os/LmiSharedPtr.h>



LMI_BEGIN_EXTERN_C

struct VidyoVirtualWindowShareImpl_;
typedef struct VidyoVirtualWindowShareImpl_ VidyoVirtualWindowShareImpl;
Declare_LmiSharedPtr(VidyoVirtualWindowShareImpl)
Declare_LmiSharedPtrWrapper(VidyoVirtualWindowShare, VidyoVirtualWindowShareImpl)
Declare_LmiWeakPtrWrapper(VidyoVirtualWindowShareHandle, VidyoVirtualWindowShare, VidyoVirtualWindowShareImpl)
Declare_LmiVector(VidyoVirtualWindowShare)
Declare_LmiList(VidyoVirtualWindowShare)

LMI_END_EXTERN_C

#include "VidyoMediaFormats.h"
#include "VidyoVideoFrame.h"
#include "VidyoLocalRenderer.h"
#include "VidyoRemoteRenderer.h"


LMI_BEGIN_EXTERN_C

/**
{type reference-counted="yes":
	{name: VidyoVirtualWindowShare}
	{parent: Device}
	{include: Lmi/VidyoClient/VidyoVirtualWindowShare.h}
	{description: This object represents a virtual window share on the local endpoint. }
	{member:
		{name: id}
		{type: LmiString}
		{description: Unique ID.}
	}
	{member:
		{name: name}
		{type: LmiString}
		{description: Name of the virtual window share.}
	}
	{member:
		{name: applicationName}
		{type: LmiString}
		{description: Name of the application that assumes the ownership of virtual window. }
	}
}
*/

/**
{type:
	{name: VidyoVirtualWindowShareHandle}
	{parent: VidyoVirtualWindowShare}
	{description: }
}
*/

/**
{type:
	{name: VidyoVirtualWindowShareState}
	{parent: VidyoVirtualWindowShare}
	{description: State of the window share.}
	{value: {name: VIDYO_VIRTUALWINDOWSHARESTATE_Ok} {description: The window is visible and has been fully captured.}}
	{value: {name: VIDYO_VIRTUALWINDOWSHARESTATE_NotVisible} {description: The window exists but is not "visible".}}
	{value: {name: VIDYO_VIRTUALWINDOWSHARESTATE_Minimized} {description: The window is minimized and "visible" but its content may not be accessible.}}
	{value: {name: VIDYO_VIRTUALWINDOWSHARESTATE_Closed} {description: The window is closed and is no longer accessible.}}
	{value: {name: VIDYO_VIRTUALWINDOWSHARESTATE_MiscError} {description: Miscellaneous error has occured trying to capture the frame.}}
}
*/
typedef enum {
	VIDYO_VIRTUALWINDOWSHARESTATE_Ok,
	VIDYO_VIRTUALWINDOWSHARESTATE_NotVisible,
	VIDYO_VIRTUALWINDOWSHARESTATE_Minimized,
	VIDYO_VIRTUALWINDOWSHARESTATE_Closed,
	VIDYO_VIRTUALWINDOWSHARESTATE_MiscError
}
VidyoVirtualWindowShareState;

/**
{callback:
	{name: VidyoVirtualWindowShareStartCallback}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void (*VidyoVirtualWindowShareStartCallback)(const VidyoVirtualWindowShare* w, LmiTime frameInterval, VidyoMediaFormat mediaFormat, LmiVoidPtr userData)}
	{parameter:
		{name: w}
		{description: The VidyoVirtualWindowShare object. }
	}
	{parameter:
		{name: frameInterval}
		{description: }
	}
	{parameter:
		{name: mediaFormat}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void(*VidyoVirtualWindowShareStartCallback)(const VidyoVirtualWindowShare* w, LmiTime frameInterval, VidyoMediaFormat mediaFormat, LmiVoidPtr userData);

/**
{callback:
	{name: VidyoVirtualWindowShareReconfigureCallback}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void (*VidyoVirtualWindowShareReconfigureCallback)(const VidyoVirtualWindowShare* w, LmiTime frameInterval, const VidyoMediaFormat mediaFormat, LmiVoidPtr userData)}
	{parameter:
		{name: w}
		{description: The VidyoVirtualWindowShare object. }
	}
	{parameter:
		{name: frameInterval}
		{description: }
	}
	{parameter:
		{name: mediaFormat}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void(*VidyoVirtualWindowShareReconfigureCallback)(const VidyoVirtualWindowShare* w, LmiTime frameInterval, const VidyoMediaFormat mediaFormat, LmiVoidPtr userData);

/**
{callback:
	{name: VidyoVirtualWindowShareStopCallback}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void (*VidyoVirtualWindowShareStopCallback)(const VidyoVirtualWindowShare* c, LmiVoidPtr userData)}
	{parameter:
		{name: c}
		{description: }
	}
	{parameter:
		{name: userData}
		{description: }
	}
}
*/
typedef void(*VidyoVirtualWindowShareStopCallback)(const VidyoVirtualWindowShare* c, LmiVoidPtr userData);

/**
{function:
	{name: VidyoVirtualWindowShareConstruct}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: VidyoVirtualWindowShare* VidyoVirtualWindowShareConstruct(VidyoVirtualWindowShare* w, LmiString *id, LmiString *windowName, LmiString *applicationName, VidyoVirtualWindowShareStartCallback onStart, VidyoVirtualWindowShareReconfigureCallback onReconfigure, VidyoVirtualWindowShareStopCallback onStop, LmiAllocator* alloc)}
	{parameter:
		{name: w}
		{description: The VidyoVirtualWindowShare object. }
	}
	{parameter:
		{name: id}
		{description: }
	}
	{parameter:
		{name: windowName}
		{description: }
	}
	{parameter:
		{name: applicationName}
		{description: }
	}
	{parameter:
		{name: onStart}
		{description: }
	}
	{parameter:
		{name: onReconfigure}
		{description: }
	}
	{parameter:
		{name: onStop}
		{description: }
	}
	{parameter:
		{name: alloc}
		{description: }
	}
	{return: }
}
*/
VidyoVirtualWindowShare* VidyoVirtualWindowShareConstruct(VidyoVirtualWindowShare* w, LmiString *id, LmiString *windowName, LmiString *applicationName, VidyoVirtualWindowShareStartCallback onStart, VidyoVirtualWindowShareReconfigureCallback onReconfigure, VidyoVirtualWindowShareStopCallback onStop, LmiAllocator* alloc);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareConstructCopy}
	{parent: VidyoVirtualWindowShare}
	{description: Constructs a VidyoVirtualWindowShare object as a copy of another.}
	{prototype: VidyoVirtualWindowShare *VidyoVirtualWindowShareConstructCopy(VidyoVirtualWindowShare *obj, const VidyoVirtualWindowShare *other)}
	{parameter: {name: obj} {description: The VidyoVirtualWindowShare object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareDestruct}
	{parent: VidyoVirtualWindowShare}
	{description: Destructs an VidyoVirtualWindowShare object.}
	{prototype: void VidyoVirtualWindowShareDestruct(VidyoVirtualWindowShare *obj)}
	{parameter: {name: obj} {description: The VidyoVirtualWindowShare object to destruct.}}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareAssign}
	{parent: VidyoVirtualWindowShare}
	{description: Assigns one VidyoVirtualWindowShare object the value of another. }
	{prototype: VidyoVirtualWindowShare *VidyoVirtualWindowShareAssign(VidyoVirtualWindowShare *obj, const VidyoVirtualWindowShare *other)}
	{parameter: {name: obj} {description: The VidyoVirtualWindowShare object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareOnFrame}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void VidyoVirtualWindowShareOnFrame(VidyoVirtualWindowShare *w, const VidyoVideoFrame *videoFrame, VidyoMediaFormat mediaFormat)}
	{parameter:{name: w}{description: }}
	{parameter:{name: videoFrame}{description: }}
	{parameter:{name: mediaFormat}{description: }}
}
*/
void VidyoVirtualWindowShareOnFrame(VidyoVirtualWindowShare *w, const VidyoVideoFrame *videoFrame, VidyoMediaFormat mediaFormat);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareGetApplicationName}
	{parent: VidyoVirtualWindowShare}
	{description: Gets the name of the application that owns the window.}
	{prototype: const LmiString* VidyoVirtualWindowShareGetApplicationName(const VidyoVirtualWindowShare* w)}
	{parameter:	{name: w}	{description: The VidyoVirtualWindowShare object. }}
	{return: The name of the application that owns the window}
}
*/
const LmiString* VidyoVirtualWindowShareGetApplicationName(const VidyoVirtualWindowShare* w);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareGetName}
	{parent: VidyoVirtualWindowShare}
	{description: Gets the name of the window share.}
	{prototype: const LmiString* VidyoVirtualWindowShareGetName(const VidyoVirtualWindowShare* w)}
	{parameter:	{name: w}	{description: The VidyoVirtualWindowShare object. }}
	{return: Name of the window share.}
}
*/
const LmiString* VidyoVirtualWindowShareGetName(const VidyoVirtualWindowShare* w);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareGetId}
	{parent: VidyoVirtualWindowShare}
	{description: Gets the unique ID of the window share.}
	{prototype: const LmiString* VidyoVirtualWindowShareGetId(const VidyoVirtualWindowShare* w)}
	{parameter:	{name: w} {description: The VidyoVirtualWindowShare object. }}
	{return: Unique ID of the window share.}
}
*/
const LmiString* VidyoVirtualWindowShareGetId(const VidyoVirtualWindowShare* w);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareGetPreviewLabel}
	{parent: VidyoVirtualWindowShare}
	{description: Gets the preview label of the window share. }
	{prototype: const LmiString* VidyoVirtualWindowShareGetPreviewLabel(const VidyoVirtualWindowShare* w)}
	{parameter:	{name: w} {description: The VidyoVirtualWindowShare object.}}
	{return: Display name of the window share.}
}
*/
const LmiString* VidyoVirtualWindowShareGetPreviewLabel(const VidyoVirtualWindowShare* w);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareSetPreviewLabel}
	{parent: VidyoVirtualWindowShare}
	{description: Set the preview label of the window share. }
	{prototype: LmiBool VidyoVirtualWindowShareSetPreviewLabel(VidyoVirtualWindowShare* w, const LmiString* previewLabel)}
	{parameter:	{name: w} {description: The VidyoVirtualWindowShare object.}}
	{parameter: {name: previewLabel} {description: Display name to set on the window share.}}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoVirtualWindowShareSetPreviewLabel(VidyoVirtualWindowShare* w, const LmiString* previewLabel);

/**
{function visibility="private":
	{name: VidyoVirtualWindowShareSetCapability}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareSetCapability(VidyoVirtualWindowShare* w, LmiTime frameInterval)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: frameInterval} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareSetCapability(VidyoVirtualWindowShare* w, LmiTime frameInterval);


/**
{function apigroup="connector,simple" visibility="private":
	{name: VidyoVirtualWindowShareSetUserData}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void VidyoVirtualWindowShareSetUserData(VidyoVirtualWindowShare* w, LmiVoidPtr userData)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: userData} {description: }}
}
*/
void VidyoVirtualWindowShareSetUserData(VidyoVirtualWindowShare* w, LmiVoidPtr userData);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareGetUserData}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiVoidPtr VidyoVirtualWindowShareGetUserData(const VidyoVirtualWindowShare* w)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{return: }
}
*/
LmiVoidPtr VidyoVirtualWindowShareGetUserData(const VidyoVirtualWindowShare* w);

/**
{function:
	{name: VidyoVirtualWindowShareSetBoundsConstraints}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareSetBoundsConstraints(VidyoVirtualWindowShare* w, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint maxWidth, LmiUint minWidth, LmiUint maxHeight, LmiUint minHeight)}
	{parameter: {name: w} {description: }}
	{parameter: {name: maxFrameInterval} {description: }}
	{parameter: {name: minFrameInterval} {description: }}
	{parameter: {name: maxWidth} {description: }}
	{parameter: {name: minWidth} {description: }}
	{parameter: {name: maxHeight} {description: }}
	{parameter: {name: minHeight} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareSetBoundsConstraints(VidyoVirtualWindowShare* w, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint maxWidth, LmiUint minWidth, LmiUint maxHeight, LmiUint minHeight);

/**
{function:
	{name: VidyoVirtualWindowShareSetDiscrerteConstraints}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareSetDiscrerteConstraints(VidyoVirtualWindowShare* w, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint width, LmiUint height, LmiFloat32 scaleFactor)}
	{parameter: {name: w} {description: }}
	{parameter: {name: maxFrameInterval} {description: }}
	{parameter: {name: minFrameInterval} {description: }}
	{parameter: {name: width} {description: }}
	{parameter: {name: height} {description: }}
	{parameter: {name: scaleFactor} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareSetDiscrerteConstraints(VidyoVirtualWindowShare* w, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint width, LmiUint height, LmiFloat32 scaleFactor);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualWindowShareSetFrameInterval}
	{parent: VidyoVirtualWindowShare}
	{description: Sets the maximum frame interval that will be used to scrapte the window share}
	{prototype: LmiBool VidyoVirtualWindowShareSetFrameInterval(VidyoVirtualWindowShare* w, LmiTime frameInterval)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: frameInterval} {description: The interval in nanoseconds between consecutive frames. Default is 333333333 which is 3 frames per second. }}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
	{note: To set 3 frames per seconds use 1000000000/3 as the value.}
}
*/
LmiBool VidyoVirtualWindowShareSetFrameInterval(VidyoVirtualWindowShare* w, LmiTime frameInterval);

/**
{function:
	{name: VidyoVirtualWindowShareSetScaleFactor}
	{parent: VidyoVirtualWindowShare}
	{description: Sets the scale factor by which to down-scale the window share.}
	{prototype: LmiBool VidyoVirtualWindowShareSetScaleFactor(VidyoVirtualWindowShare* w, LmiFloat32 scaleFactor)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: scaleFactor} {description: }}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoVirtualWindowShareSetScaleFactor(VidyoVirtualWindowShare* w, LmiFloat32 scaleFactor);

/**
{function apigroup="connector,simple,beta":
	{name: VidyoVirtualWindowShareSetLowLatencyProfile}
	{parent: VidyoVirtualWindowShare}
	{description: Sets the low latency profile of the window share which treats the stream as a regular video source. This prioritizes latency over quality.}
	{prototype: LmiBool VidyoVirtualWindowShareSetLowLatencyProfile(VidyoVirtualWindowShare* w, LmiBool profile)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: profile} {description: Low latency profile toggle. Default is LMI_FALSE. }}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoVirtualWindowShareSetLowLatencyProfile(VidyoVirtualWindowShare* w, LmiBool profile);


/**
{function:
	{name: VidyoVirtualWindowShareClearConstraints}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: void VidyoVirtualWindowShareClearConstraints(VidyoVirtualWindowShare* w)}
	{parameter:	{name: w} {description: }}
}
*/
void VidyoVirtualWindowShareClearConstraints(VidyoVirtualWindowShare* w);

/**
{function:
	{name: VidyoVirtualWindowShareAddToRemoteRenderer}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareAddToRemoteRenderer(VidyoVirtualWindowShare* w, const VidyoRemoteRenderer* remoteRenderer)}
	{parameter:	{name: w}{description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: remoteRenderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareAddToRemoteRenderer(VidyoVirtualWindowShare* w, const VidyoRemoteRenderer* remoteRenderer);

/**
{function:
	{name: VidyoVirtualWindowShareRemoveFromRemoteRenderer}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareRemoveFromRemoteRenderer(VidyoVirtualWindowShare* w, const VidyoRemoteRenderer* remoteRenderer)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: remoteRenderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareRemoveFromRemoteRenderer(VidyoVirtualWindowShare* w, const VidyoRemoteRenderer* remoteRenderer);

/**
{function:
	{name: VidyoVirtualWindowShareAddToLocalRenderer}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiVoidPtr VidyoVirtualWindowShareAddToLocalRenderer(VidyoVirtualWindowShare* w, const VidyoLocalRenderer* renderer)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: renderer} {description: }}
	{return: }
}
*/
LmiVoidPtr VidyoVirtualWindowShareAddToLocalRenderer(VidyoVirtualWindowShare* w, const VidyoLocalRenderer* renderer);

/**
{function:
	{name: VidyoVirtualWindowShareRemoveFromLocalRenderer}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareRemoveFromLocalRenderer(VidyoVirtualWindowShare* w, const VidyoLocalRenderer* renderer)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: renderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareRemoveFromLocalRenderer(VidyoVirtualWindowShare* w, const VidyoLocalRenderer* renderer);

/**
{function:
	{name: VidyoVirtualWindowShareSetPositionInLocalRenderer}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: LmiBool VidyoVirtualWindowShareSetPositionInLocalRenderer(VidyoVirtualWindowShare *w, const VidyoLocalRenderer *localRenderer, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiTime frameInterval)}
	{parameter: {name: w} {description: The VidyoVirtualWindowShare object. }}
	{parameter: {name: localRenderer} {description: }}
	{parameter: {name: x} {description: }}
	{parameter: {name: y} {description: }}
	{parameter: {name: width} {description: }}
	{parameter: {name: height} {description: }}
	{parameter: {name: frameInterval} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualWindowShareSetPositionInLocalRenderer(VidyoVirtualWindowShare *w, const VidyoLocalRenderer *localRenderer, LmiInt x, LmiInt y, LmiUint width, LmiUint height, LmiTime frameInterval);

/**
{function visibility="private":
	{name: VidyoVirtualWindowShareConstructFromDevice}
	{parent: VidyoVirtualWindowShare}
	{description: }
	{prototype: VidyoVirtualWindowShare *VidyoVirtualWindowShareConstructFromDevice(VidyoVirtualWindowShare* vidyoVirtualWindowShare, const VidyoDevice *device, LmiAllocator* alloc)}
	{parameter:	{name: vidyoVirtualWindowShare}	{description: }}
	{parameter: {name: device} {description: }}
	{parameter: {name: alloc} {description: }}
	{return: }
}
*/
VidyoVirtualWindowShare *VidyoVirtualWindowShareConstructFromDevice(VidyoVirtualWindowShare* vidyoVirtualWindowShare, const VidyoDevice *device, LmiAllocator* alloc);

/**
{function:
	{name: VidyoVirtualWindowShareGetStats}
	{parent: VidyoVirtualWindowShare}
	{description: .}
	{prototype: LmiBool VidyoVirtualWindowShareGetStats(VidyoVirtualWindowShare *windowShare, VidyoLocalVideoSourceStats *stats)}
	{parameter: {name: windowShare} {description: The local window share object to extract stats.}}
	{parameter: {name: stats} {description: The stats object to fill.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoVirtualWindowShareGetStats(VidyoVirtualWindowShare *windowShare, VidyoLocalVideoSourceStats *stats);


LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoVirtualWindowShareInline.h"
#endif

#endif /*VIDYO_VIRTUALWINDOWSHARE_H_*/
