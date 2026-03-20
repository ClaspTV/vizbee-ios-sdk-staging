#import <Foundation/Foundation.h>
#import "VZBVideoStatus.h"

@class VZBCurrentVideoModel;

@protocol VZBVideoStatusUpdateDelegate <NSObject>

- (void)onVideoStatusUpdate:(VZBVideoStatus *)videoStatus;

@end

@interface VZBVideoClient : NSObject

- (instancetype)initWithVideoModel:(VZBCurrentVideoModel *)videoModel;

- (void)play;

- (void)pause;

- (void)seek:(long)position;

- (void)stop;

/**
* Sets active tracks (legacy method)
* @param tracks Array of tracks to set as active
* @deprecated Use setActiveTracks:withType: instead which allows specifying track type
*/
- (void)setActiveTracks:(NSArray<VZBVideoTrackInfo*>*)tracks DEPRECATED_MSG_ATTRIBUTE("Use setActiveTracks:withType: instead");

/**
* Sets active tracks of specified type
* @param tracks Array of tracks to set as active
* @param type Type of tracks being set (audio/text)
*/
- (void)setActiveTracks:(NSArray<VZBVideoTrackInfo*>*)tracks withType:(VZBVideoTrackType)type;


- (VZBVideoStatus *)getVideoStatus;

- (void)addVideoStatusDelegate:(id<VZBVideoStatusUpdateDelegate>)delegate;

- (void)removeVideoStatusDelegate:(id<VZBVideoStatusUpdateDelegate>)delegate;

- (void)tearDown;

@end
