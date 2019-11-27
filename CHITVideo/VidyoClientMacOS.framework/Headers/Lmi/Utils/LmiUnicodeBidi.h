/** {file:
      {name: LmiUnicodeBidi.h}
      {description: Functions to perform Unicode bidirectionality processing.}
      {copyright:
      	(c) 2017 Vidyo, Inc.,
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

#ifndef LMI_UNICODEBIDI_H_
#define LMI_UNICODEBIDI_H_

#include <Lmi/Utils/LmiUnicode.h>
#include <Lmi/Utils/LmiBasicTypesContainer.h>

LMI_BEGIN_EXTERN_C

/**
	{package visibility="private":
		{name: UnicodeBidi}
		{parent: Unicode}
		{include: Lmi/Utils/LmiUnicodeBidi.h}
		{description: Utilities for handling bidirectional Unicode text.}
	}
*/


/**
	{type visibility="private":
		{name: LmiUnicodeBidiParagraphDirection}
		{parent: UnicodeBidi}
		{description: The high-level text direction of a paragraph.}
		{value: {name: LMI_UNICODEBIDI_PARAGRAPHDIRECTION_LTR}
			{description: A left-to-right paragraph direction.}}
		{value: {name: LMI_UNICODEBIDI_PARAGRAPHDIRECTION_RTL}
			{description: A right-to-left paragraph direction.}}
		{value: {name: LMI_UNICODEBIDI_PARAGRAPHDIRECTION_Auto}
			{description: Automatic paragraph direction.}}
	}
*/
typedef enum {
	LMI_UNICODEBIDI_PARAGRAPHDIRECTION_LTR,
	LMI_UNICODEBIDI_PARAGRAPHDIRECTION_RTL,
	LMI_UNICODEBIDI_PARAGRAPHDIRECTION_Auto
} LmiUnicodeBidiParagraphDirection;


/**
	{type visibility="private":
		{name: LmiUnicodeBidiParameters}
		{parent: UnicodeBidi}
		{description: Parameters to the Unicode bidi algorithm.}
	}
*/
typedef struct {
	LmiUnicodeBidiParagraphDirection defaultParagraphDir;
	LmiBool doGlyphMirroring;
	LmiBool saveBN;
} LmiUnicodeBidiParameters;

/**
	{function visibility="private":
		{name: LmiUnicodeBidiParametersConstructDefault}
		{parent: LmiUnicodeBidiParameters}
		{description: Construct a Unicode Bidi parameters object with default settings.}
		{prototype: LmiUnicodeBidiParameters* LmiUnicodeBidiParametersConstructDefault(LmiUnicodeBidiParameters* bp)}
		{parameter:
			{name: bp}
			{description: The Unicode bidi parameters object to construct.}}
		{return: The object on success, or NULL on failure.}
	}
*/
LmiUnicodeBidiParameters* LmiUnicodeBidiParametersConstructDefault(LmiUnicodeBidiParameters* bp);

/**
	{function visibility="private":
		{name: LmiUnicodeBidiParametersDestruct}
		{parent: LmiUnicodeBidiParameters}
		{description: Destruct a Unicode Bidi parameters object.}
		{prototype: void LmiUnicodeBidiParametersDestruct(LmiUnicodeBidiParameters* bp)}
		{parameter:
			{name: bp}
			{description: The Unicode bidi parameters object to destruct.}}
	}
*/
void LmiUnicodeBidiParametersDestruct(LmiUnicodeBidiParameters* bp);

/**
	{function visibility="private":
		{name: LmiUnicodeBidiParametersSetParagraphDir}
		{parent: LmiUnicodeBidiParameters}
		{description: Set the default paragraph direction the Unicode bidi algorithm will use.  The default is LMI_UNICODEBIDI_PARAGRAPHDIRECTION_Auto, meaning that the paragraph direction will be auto-detected based on the paragraph contents.}
		{prototype: LmiBool LmiUnicodeBidiParametersSetParagraphDir(LmiUnicodeBidiParameters* bp, LmiUnicodeBidiParagraphDirection defaultParagraphDir)}
		{parameter:
			{name: bp}
			{description: The Unicode bidi parameters object.}}
		{parameter:
			{name: defaultParagraphDir}
			{description: The default paragraph direction to set.}}
		{return: LMI_TRUE on success, else LMI_FALSE.}
	}
*/
LmiBool LmiUnicodeBidiParametersSetParagraphDir(LmiUnicodeBidiParameters* bp, LmiUnicodeBidiParagraphDirection defaultParagraphDir);


/**
	{function visibility="private":
		{name: LmiUnicodeBidiParametersDoGlyphMirroring}
		{parent: LmiUnicodeBidiParameters}
		{description: Set whether the Unicode bidi algorithm will do glyph mirroring for appropriate glyphs in right-to-left contexts (e.g., replacing "<" with ">").  The default is true.}
		{prototype: LmiBool LmiUnicodeBidiParametersDoGlyphMirroring(LmiUnicodeBidiParameters* bp, LmiBool doMirroring)}
		{parameter:
			{name: bp}
			{description: The Unicode bidi parameters object.}}
		{parameter:
			{name: doMirroring}
			{description: Whether to do glyph mirroring.}}
		{return: LMI_TRUE on success, else LMI_FALSE.}
	}
*/
LmiBool LmiUnicodeBidiParametersDoGlyphMirroring(LmiUnicodeBidiParameters* bp, LmiBool doMirroring);


/**
	{function visibility="private":
		{name: LmiUnicodeBidiParametersSaveBoundaryNeutral}
		{parent: LmiUnicodeBidiParameters}
		{description: Set whether "boundary neutral" characters -- ignorables, non-characters, and control characters -- in the Unicode bidi algorithm's input should be included in the output.  The default is false.}
		{prototype: LmiBool LmiUnicodeBidiParametersSaveBoundaryNeutral(LmiUnicodeBidiParameters* bp, LmiBool saveBN)}
		{parameter:
			{name: bp}
			{description: The Unicode bidi parameters object.}}
		{parameter:
			{name: saveBN}
			{description: Whether to save boundary neutral characters.}}
		{return: LMI_TRUE on success, else LMI_FALSE.}
	}
*/
LmiBool LmiUnicodeBidiParametersSaveBoundaryNeutral(LmiUnicodeBidiParameters* bp, LmiBool saveBN);

/**
	{function visibility="private":
		{name: LmiUnicodeBidiTransformToPhysical}
		{parent: UnicodeBidi}
		{description: Transform a Unicode string from logical to physical order.}
		{prototype: LmiBool LmiUnicodeBidiTransformToPhysical(const LmiWideString* logical, LmiWideString* physical, LmiUnicodeBidiParagraphDirection* paragraphDir, const LmiUnicodeBidiParameters* params)}
		{parameter:
			{name: logical}
			{description: The original Unicode wide string.  This should consist of only one "paragraph" in Unicode terms (i.e., it should not contain newlines or the like, except optionally at the end).}}
		{parameter:
			{name: physical}
			{description: A constructed wide string.  On successful return, the physical order of the string will be written into this object, in left-to-right order.}}
		{parameter:
			{name: paragraphDir}
			{description: On successful return, the paragraph direction will be written to this variable.  This can be used for alignment.}}
		{parameter:
			{name: params}
			{description: A structure defining various parameters to the bidi algorithm's behavior; or NULL, for the default behavior (the same as LmiUnicodeBidiParametersConstructDefault.)}}
		{return: LMI_TRUE if successful, otherwise LMI_FALSE.}
	}
*/
LmiBool LmiUnicodeBidiTransformToPhysical(const LmiWideString* logical, LmiWideString* physical, LmiUnicodeBidiParagraphDirection* paragraphDir, const LmiUnicodeBidiParameters* params);

/* Internal API for testing.  Exposes levels vector. */
LmiBool LmiUnicodeBidiTransformToPhysical_(const LmiWideString* logical, LmiWideString* physical, LmiUnicodeBidiParagraphDirection* paragraphDir, const LmiUnicodeBidiParameters* params, LmiVector(LmiInt)* levels);


LMI_END_EXTERN_C

#endif /* LMI_UNICODE_H_ */
