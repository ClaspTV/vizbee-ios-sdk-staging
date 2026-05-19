//
// VZBHandoffSession.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBScreen.h"
#import "VZBEventManager.h"
#import "VZBHandoffCampaignInfo.h"

@class VZBSmartHandoffDeviceInstance;

NS_ASSUME_NONNULL_BEGIN

/// Represents an active handoff session with a TV device.
@interface VZBHandoffSession : NSObject

@property (nonatomic, readonly, strong, nonnull) VZBScreen *vizbeeScreen;
@property (nonatomic, readonly, strong, nonnull) VZBEventManager *eventManager;
@property (nonatomic, readonly, strong, nonnull) VZBHandoffCampaignInfo *campaignInfo;

- (instancetype)initWithDevice:(VZBSmartHandoffDeviceInstance *)device;
- (void)tearDown;

@end

NS_ASSUME_NONNULL_END
