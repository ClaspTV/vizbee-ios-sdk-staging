//
// VZBHandoffCampaignInfo.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VZBSmartHandoffCampaignConfig;

NS_ASSUME_NONNULL_BEGIN

/// A public, read-only snapshot of the subset of handoff campaign configuration associated with a session.
@interface VZBHandoffCampaignInfo : NSObject

/// The campaign identifier.
@property (nonatomic, readonly, copy) NSString *campaignId;

/// Whether the campaign requires authentication.
/// Use this to gate auth flows so they are only started for campaigns that opt in.
@property (nonatomic, readonly, assign) BOOL isAuthEnabled;

- (instancetype)initWithCampaignConfig:(VZBSmartHandoffCampaignConfig *)config;

@end

NS_ASSUME_NONNULL_END
