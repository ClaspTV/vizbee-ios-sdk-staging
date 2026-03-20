#import <Foundation/Foundation.h>
#import "VZBVideoTrackStatus.h"

typedef NS_ENUM(NSUInteger, VZBVideoPlayerState) {
    VZBVideoPlayerStateIdle,
    VZBVideoPlayerStateLoading,
    VZBVideoPlayerStateStarted,
    VZBVideoPlayerStatePlaying,
    VZBVideoPlayerStatePaused,
    VZBVideoPlayerStateBuffering,
    VZBVideoPlayerStateError,
    VZBVideoPlayerStateStopped,
    VZBVideoPlayerStateStoppedOnDisconnect,
    VZBVideoPlayerStateEnded,
};

@interface VZBVideoStatus : NSObject

@property (nonatomic, strong, readonly) NSString*_Nullable guid;
@property (nonatomic, strong, readonly) NSString*_Nullable title;
@property (nonatomic, strong, readonly) NSString*_Nullable subTitle;
@property (nonatomic, strong, readonly) NSString*_Nullable imageURL;
@property (nonatomic, assign, readonly) NSTimeInterval streamPosition;
@property (nonatomic, assign, readonly) NSTimeInterval streamDuration;
@property (nonatomic, assign, readonly) NSTimeInterval adPosition;
@property (nonatomic, assign, readonly) NSTimeInterval adDuration;
@property (nonatomic, assign, readonly) BOOL isStreamLive;
@property (nonatomic, assign, readonly) BOOL isAdPlaying;
@property (nonatomic, assign, readonly) VZBVideoPlayerState playerState;

// Deprecated old property (returns first track status if available)
@property (nonatomic, strong, readonly) VZBVideoTrackStatus*_Nullable trackStatus DEPRECATED_MSG_ATTRIBUTE("Use trackStatuses instead");

// New property
@property (nonatomic, strong, readonly) NSArray<VZBVideoTrackStatus *>*_Nullable tracksStatus;

- (instancetype _Nonnull)init NS_DESIGNATED_INITIALIZER;

// Original init method with trackStatus
- (instancetype _Nonnull)initWithGuid:(NSString*_Nullable)guid
                               title:(NSString*_Nullable)title
                            subtitle:(NSString*_Nullable)subtitle
                            imageURL:(NSString*_Nullable)imageURL
                      streamPosition:(NSTimeInterval)streamPosition
                      streamDuration:(NSTimeInterval)streamDuration
                         adPosition:(NSTimeInterval)adPosition
                         adDuration:(NSTimeInterval)adDuration
                       isStreamLive:(BOOL)isStreamLive
                       isAdPlaying:(BOOL)isAdPlaying
                       playerState:(VZBVideoPlayerState)playerState
                       trackStatus:(VZBVideoTrackStatus*_Nullable)trackStatus DEPRECATED_MSG_ATTRIBUTE("Use initWithGuid:title:subtitle:imageURL:streamPosition:streamDuration:adPosition:adDuration:isStreamLive:isAdPlaying:playerState:tracksStatus: instead");

// New init method with trackStatuses array
- (instancetype _Nonnull)initWithGuid:(NSString*_Nullable)guid
                               title:(NSString*_Nullable)title
                            subtitle:(NSString*_Nullable)subtitle
                            imageURL:(NSString*_Nullable)imageURL
                      streamPosition:(NSTimeInterval)streamPosition
                      streamDuration:(NSTimeInterval)streamDuration
                         adPosition:(NSTimeInterval)adPosition
                         adDuration:(NSTimeInterval)adDuration
                       isStreamLive:(BOOL)isStreamLive
                       isAdPlaying:(BOOL)isAdPlaying
                       playerState:(VZBVideoPlayerState)playerState
                      tracksStatus:(NSArray<VZBVideoTrackStatus*>*_Nullable)tracksStatus NS_DESIGNATED_INITIALIZER;

@end
