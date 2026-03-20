//
//  VZBAppAdapterDelegate.h
//  VizbeeKit
//
//  Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBVideoMetadata.h"
#import "VZBVideoStreamInfo.h"
#import "VZBScreenType.h"
#import "VZBVideoStatus.h"

/**
 * Should be implemented by the host application
 * to interface with the Vizbee SDK
 */
@protocol VZBAppAdapterDelegate <NSObject>

@required

/**
 * Fetch app's video object for a given video GUID.
 * @param guid Globally Unique ID for the video.
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVideoInfoByGUID:(nonnull NSString *)guid
                 onSuccess:(void(^_Nonnull)(id _Nonnull appVideoObject))successCallback
                 onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

/**
 * Map host app's video object to Vizbee video metadata for a given video GUID.
 * @param appVideoObject any datatype that naturally encapsulates the host app's video metadata
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVZBMetadataFromVideo:(id _Nonnull)appVideoObject
                      onSuccess:(void(^_Nonnull)(VZBVideoMetadata* _Nonnull videoMetadata))successCallback
                      onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

/**
 * Map host app's video object to Vizbee stream info for a given video GUID.
 * @param appVideoObject any datatype that naturally encapsulates the host app's video metadata
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) getVZBStreamInfoFromVideo:(id _Nonnull)appVideoObject
                        forScreen:(nonnull VZBScreenType*)screenType
                        onSuccess:(void(^_Nonnull)(VZBVideoStreamInfo* _Nonnull videoStreamInfo))successCallback
                        onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;


/**
 * @brief Go to a presenting view controller in the app to play a new deeplinked video.
 *
 * This method is called when a deep link or universal link is received by the Vizbee SDK.
 * Vizbee request the app to go to a presenting controller for the deeplinked video so the
 * video can be played on the phone or TV.
 *
 * @param guid a Globally Unique ID for video
 * @param successCallback asynchronous success callback.
 * @param failureCallback asynchronous failure callback.
 */
-(void) goToViewControllerForGUID:(NSString* _Nonnull)guid
                        onSuccess:(void(^_Nonnull)(UIViewController* _Nonnull presentingViewController))successCallback
                        onFailure:(void(^_Nonnull)(NSError* _Nonnull error))failureCallback;

@optional
/**
 * Launches the host app's ViewController to play video on the phone.
 * The implementing class must implement either this method OR the version with videoStatus.
 *
 * @param appVideoObject The app-specific video object containing video details
 * @param playHeadTime The position (in seconds) where playback should start
 * @param shouldAutoPlay Whether the video should start playing automatically
 * @param viewController The view controller from which to present the video player
 */
- (void)playVideoOnPhone:(nonnull id)appVideoObject
              atPosition:(NSTimeInterval)playHeadTime
          shouldAutoPlay:(BOOL)shouldAutoPlay
presentingViewController:(nonnull UIViewController *)viewController;

/**
 * Enhanced version of playVideoOnPhone that includes video status.
 * The implementing class must implement either this method OR the basic version above.
 *
 * @param appVideoObject The app-specific video object containing video details
 * @param playHeadTime The position (in seconds) where playback should start
 * @param shouldAutoPlay Whether the video should start playing automatically
 * @param viewController The view controller from which to present the video player
 * @param lastVideoStatus The last known video playback status (may be nil)
 */
- (void)playVideoOnPhone:(nonnull id)appVideoObject
              atPosition:(NSTimeInterval)playHeadTime
          shouldAutoPlay:(BOOL)shouldAutoPlay
presentingViewController:(nonnull UIViewController *)viewController
             videoStatus:(nullable VZBVideoStatus *)lastVideoStatus;

@end
