/** 
{file:
	{name: VidyoAudioFrame.h}
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
#ifndef VIDYO_AUDIOFRAME_H_ 
#define VIDYO_AUDIOFRAME_H_ 

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Os/LmiSharedPtr.h>

LMI_BEGIN_EXTERN_C

struct VidyoAudioFrameImpl_;
typedef struct VidyoAudioFrameImpl_ VidyoAudioFrameImpl;
Declare_LmiSharedPtr(VidyoAudioFrameImpl)
Declare_LmiSharedPtrWrapper(VidyoAudioFrame, VidyoAudioFrameImpl)
Declare_LmiVector(VidyoAudioFrame)
Declare_LmiList(VidyoAudioFrame)

/**
{type apigroup="connector,simple" reference-counted="yes":
	{name: VidyoAudioFrame}
	{parent: Device}
	{include: Lmi/VidyoClient/VidyoAudioFrame.h}
	{description: This object represents an audio frame.}
	{member:
		{name: data}
		{type: LmiVoidPtr}
		{description: Pointer to the frame\'s payload.}
	}
	{member:
		{name: size}
		{type: LmiSizeT}
		{description: Size in bytes of the audio frame object\'s payload.}
	}
	{member:
		{name: sampleRate}
		{type: LmiSizeT}
		{description: Number of samples per second.}
	}
	{member:
		{name: numberOfChannels}
		{type: LmiSizeT}
		{description: Number of channels.}
	}
	{member:
		{name: numberOfSamples}
		{type: LmiSizeT}
		{description: Number of samples.}
	}
	{member:
		{name: bitsPerSample}
		{type: LmiUint}
		{description: Bits per sample of the audio data which is based on the data format (16 bits for in16, 32 bits for fl32).}
	}
	{member:
		{name: format}
		{type: LmiString}
		{description: Format of the audio frame.}
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
	{member:
		{name: energyBitPresent}
		{type: LmiBool}
		{description: Energy bit has been set.}
	}
	{member:
		{name: energy}
		{type: LmiInt}
		{description: Energy of the audio frame in dBFS (full scale).}
	}
	{member:
		{name: speechBitPresent}
		{type: LmiBool}
		{description: Speech bit has been set.}
	}
	{member:
		{name: speech}
		{type: LmiBool}
		{description: Speech is detected in the frame.}
	}
	{member:
		{name: discontinuityBitPresent}
		{type: LmiBool}
		{description: Discontinuity bit has been set.}
	}
	{member:
		{name: discontinuity}
		{type: LmiBool}
		{description: Discontinuity has been detected.}
	}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoAudioFrameConstructCopy}
	{parent: VidyoAudioFrame}
	{description: Constructs an VidyoAudioFrame object as a copy of another.}
	{prototype: VidyoAudioFrame *VidyoAudioFrameConstructCopy(VidyoAudioFrame *obj, const VidyoAudioFrame *other)}
	{parameter: {name: obj} {description: The VidyoAudioFrame object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoAudioFrameDestruct}
	{parent: VidyoAudioFrame}
	{description: Destructs an VidyoAudioFrame object.}
	{prototype: void VidyoAudioFrameDestruct(VidyoAudioFrame *obj)}
	{parameter: {name: obj} {description: The VidyoAudioFrame object to destruct.}}
}
*/

/**
{function apigroup="connector,simple" visibility="private":
	{name: VidyoAudioFrameAssign}
	{parent: VidyoAudioFrame}
	{description: Assigns one VidyoAudioFrame object the value of another. }
	{prototype: VidyoAudioFrame *VidyoAudioFrameAssign(VidyoAudioFrame *obj, const VidyoAudioFrame *other)}
	{parameter: {name: obj} {description: The VidyoAudioFrame object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function visibility="private":
	{name: VidyoAudioFrameSetUserData}
	{parent: VidyoAudioFrame}
	{description: }
	{prototype: void VidyoAudioFrameSetUserData(VidyoAudioFrame* f, LmiVoidPtr userData)}
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
void VidyoAudioFrameSetUserData(VidyoAudioFrame* f, LmiVoidPtr userData);

/**
{function visibility="private":
	{name: VidyoAudioFrameGetUserData}
	{parent: VidyoAudioFrame}
	{description: }
	{prototype: LmiVoidPtr VidyoAudioFrameGetUserData(const VidyoAudioFrame* f)}
	{parameter:
		{name: f}
		{description: }
	}
	{return: }
}
*/
LmiVoidPtr VidyoAudioFrameGetUserData(const VidyoAudioFrame* f);


/**
 {function apigroup="connector,simple":
    {name: VidyoAudioFrameGetData}
    {parent: VidyoAudioFrame}
    {description:. }
    {prototype: LmiVoidPtr VidyoAudioFrameGetData(const VidyoAudioFrame *f)}
    {parameter:
        {name: f}
        {description: The VidyoAudioFrame object. }
    }
    {return:.}
 }
 */
LmiVoidPtr VidyoAudioFrameGetData(const VidyoAudioFrame *f);


/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetSize}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiSizeT VidyoAudioFrameGetSize(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiSizeT VidyoAudioFrameGetSize(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetSampleRate}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiSizeT VidyoAudioFrameGetSampleRate(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiSizeT VidyoAudioFrameGetSampleRate(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetNumberOfChannels}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiSizeT VidyoAudioFrameGetNumberOfChannels(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiSizeT VidyoAudioFrameGetNumberOfChannels(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetNumberOfSamples}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiSizeT VidyoAudioFrameGetNumberOfSamples(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiSizeT VidyoAudioFrameGetNumberOfSamples(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetBitsPerSample}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiSizeT VidyoAudioFrameGetBitsPerSample(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiSizeT VidyoAudioFrameGetBitsPerSample(const VidyoAudioFrame *f);

/**
{function apigroup="connector,simple":
	{name: VidyoAudioFrameGetFormat}
	{parent: VidyoAudioFrame}
	{description: Gets the frame format. }
	{prototype: const LmiString *VidyoAudioFrameGetFormat(const VidyoAudioFrame *f)}
	{parameter:
		{name: f}
		{description: The VidyoAudioFrame object. }
	}
	{return: Frame format.}
}
*/
const LmiString *VidyoAudioFrameGetFormat(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetElapsedTime}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiTime VidyoAudioFrameGetElapsedTime(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiTime VidyoAudioFrameGetElapsedTime(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetTimestamp}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiTime VidyoAudioFrameGetTimestamp(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiTime VidyoAudioFrameGetTimestamp(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetEnergyBitPresent}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiBool VidyoAudioFrameGetEnergyBitPresent(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiBool VidyoAudioFrameGetEnergyBitPresent(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetEnergy}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiInt VidyoAudioFrameGetEnergy(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiInt VidyoAudioFrameGetEnergy(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetSpeechBitPresent}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiBool VidyoAudioFrameGetSpeechBitPresent(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiBool VidyoAudioFrameGetSpeechBitPresent(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetSpeech}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiBool VidyoAudioFrameGetSpeech(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiBool VidyoAudioFrameGetSpeech(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetDiscontinuityBitPresent}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiBool VidyoAudioFrameGetDiscontinuityBitPresent(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiBool VidyoAudioFrameGetDiscontinuityBitPresent(const VidyoAudioFrame *f);

/**
 {function apigroup="connector,simple":
 {name: VidyoAudioFrameGetDiscontinuity}
 {parent: VidyoAudioFrame}
 {description:. }
 {prototype: LmiBool VidyoAudioFrameGetDiscontinuity(const VidyoAudioFrame *f)}
 {parameter:
 {name: f}
 {description: The VidyoAudioFrame object. }
 }
 {return:.}
 }
 */
LmiBool VidyoAudioFrameGetDiscontinuity(const VidyoAudioFrame *f);

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoAudioFrameInline.h"
#endif

LMI_END_EXTERN_C

#endif /* VIDYO_AUDIOFRAME_H_ */
