//
//	VidyoVirtualWindowShare_Objc.h
//	VidyoClient
//
//	This file is auto generated, do not edit this file
//	Copyright (c) 2016 Vidyo, Inc. All rights reserved.
//

#import "VidyoLocalRenderer_Objc.h"
#import "VidyoMediaFormats_Objc.h"
#import "VidyoRemoteRenderer_Objc.h"
#import "VidyoStatistics_Objc.h"
#import "VidyoVideoFrame_Objc.h"
typedef NS_ENUM(NSInteger, VCVirtualWindowShareState){
	VCVirtualWindowShareStateOk,
	VCVirtualWindowShareStateNotVisible,
	VCVirtualWindowShareStateMinimized,
	VCVirtualWindowShareStateClosed,
	VCVirtualWindowShareStateMiscError
};
@protocol VCVirtualWindowShareIConstruct

	-(void) startCallback:(long)frameInterval MediaFormat:(VCMediaFormat)mediaFormat UserData:(long)userData;
	-(void) reconfigureCallback:(long)frameInterval MediaFormat:(VCMediaFormat)mediaFormat UserData:(long)userData;
	-(void) stopCallback:(long)userData;
@end
@interface VCVirtualWindowShare : NSObject
{
	void* objPtr;
	@public
	id<VCVirtualWindowShareIConstruct> virtualWindowShareIConstruct;
}

	@property NSMutableString* applicationName;
	@property NSMutableString* id;
	@property NSMutableString* name;
	-(id) init:(NSMutableString*)id WindowName:(NSMutableString*)windowName ApplicationName:(NSMutableString*)applicationName VirtualWindowShareIConstruct:(id<VCVirtualWindowShareIConstruct>)virtualWindowShareIConstruct;
	-(void) dealloc;
	-(long) addToLocalRenderer:(VCLocalRenderer*)renderer;
	-(BOOL) addToRemoteRenderer:(VCRemoteRenderer*)remoteRenderer;
	-(void) clearConstraints;
	-(NSString*) getApplicationName;
	-(NSString*) getId;
	-(NSString*) getName;
	-(NSString*) getPreviewLabel;
	-(BOOL) getStats:(VCLocalVideoSourceStats*)stats;
	-(long) getUserData;
	-(void) onFrame:(VCVideoFrame*)videoFrame MediaFormat:(VCMediaFormat)mediaFormat;
	-(BOOL) removeFromLocalRenderer:(VCLocalRenderer*)renderer;
	-(BOOL) removeFromRemoteRenderer:(VCRemoteRenderer*)remoteRenderer;
	-(BOOL) setBoundsConstraints:(long)maxFrameInterval MinFrameInterval:(long)minFrameInterval MaxWidth:(unsigned int)maxWidth MinWidth:(unsigned int)minWidth MaxHeight:(unsigned int)maxHeight MinHeight:(unsigned int)minHeight;
	-(BOOL) setDiscrerteConstraints:(long)maxFrameInterval MinFrameInterval:(long)minFrameInterval Width:(unsigned int)width Height:(unsigned int)height ScaleFactor:(float)scaleFactor;
	-(BOOL) setFrameInterval:(long)frameInterval;
	-(BOOL) setLowLatencyProfile:(BOOL)profile;
	-(BOOL) setPositionInLocalRenderer:(VCLocalRenderer*)localRenderer X:(int)x Y:(int)y Width:(unsigned int)width Height:(unsigned int)height FrameInterval:(long)frameInterval;
	-(BOOL) setPreviewLabel:(NSString*)previewLabel;
	-(BOOL) setScaleFactor:(float)scaleFactor;
	-(id) initWithObject:(void*)rPtr;
	-(void*)getObjectPtr;
@end
