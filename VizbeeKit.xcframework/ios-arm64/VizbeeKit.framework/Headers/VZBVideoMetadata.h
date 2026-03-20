//
//  VZBVideoMetadata.h
//  VizbeeKit
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Encapsulates all the metadata about one video asset.
 */
@interface VZBVideoMetadata : NSObject

/** Globally Unique ID of the content */
@property (nonatomic, copy) NSString* guid;

//----------------------------------
#pragma mark - Description
//----------------------------------

/** Title of the video */
@property (nonatomic, copy) NSString* title;

/** subTitle of the video */
@property (nonatomic, copy) NSString* subTitle;

/** Image for the video */
@property (nonatomic, strong) UIImage* image;

/** If the image needs to be downloaded, specify the URL here instead. */
@property (nonatomic, strong) NSURL* imageURL;

//----------------------------------
#pragma mark - Deeplink
//----------------------------------

/**
 * Deeplink URI for directly launching the video on the target device.
 *
 * @b This is the preferred way to identify video content. When provided, the target device can use it to navigate directly to and play the content without needing to resolve it from other metadata fields.
 *
 * If a deeplink is not available, provide sufficient metadata (@c guid, @c title,
 * @c subTitle, @c imageURL, etc.) so the receiver can resolve the content instead.
 *
 * Example: @c @"myapp://video/12345"
 */
@property (nonatomic, copy) NSString* deeplink;

//----------------------------------
#pragma mark - LIVE or VOD
//----------------------------------

/** True if the video is a live stream; false by default */
@property (nonatomic, assign) BOOL isLive;

//----------------------------------
#pragma mark - Authentication
//----------------------------------

/** True if the video requires authorization; false by default */
@property (nonatomic, assign) BOOL isAuthenticationRequired;

//----------------------------------
#pragma mark - Ads
//----------------------------------

/** array of NSNumber */
@property (nonatomic, readonly) NSArray *cuePoints;

-(void) setCuePointsInMilliseconds:(NSArray*)cp;

-(void) setCuePointsInSeconds:(NSArray*) cp;

//----------------------------------
#pragma mark - custom metadata
//----------------------------------

@property (nonatomic, copy) NSDictionary* customMetadata;

//----------------------------------
#pragma mark - Util
//----------------------------------

-(void) copy:(VZBVideoMetadata*) src;

@end
