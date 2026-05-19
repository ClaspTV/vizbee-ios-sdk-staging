//
// VZBHandoffSessionManager.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBHandoffSession.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, VZBHandoffSessionState) {
    /// No handoff device is selected or a previous session has ended.
    VZBHandoffSessionStateNotConnected,
    /// A handoff device has been selected and is being connected.
    VZBHandoffSessionStateConnecting,
    /// The handoff device is connected; the deeplink and any auth exchange are in progress.
    VZBHandoffSessionStateConnected
};

@protocol VZBHandoffSessionStateDelegate <NSObject>
- (void)onHandoffSessionStateChanged:(VZBHandoffSessionState)newState;
@end

/// Exposes handoff session lifecycle events, mirroring VZBSessionManager for casting.
@interface VZBHandoffSessionManager : NSObject

- (VZBHandoffSessionState)getSessionState;

- (void)addSessionStateDelegate:(id<VZBHandoffSessionStateDelegate>)delegate NS_SWIFT_NAME(addSessionStateDelegate(_:));
- (void)removeSessionStateDelegate:(id<VZBHandoffSessionStateDelegate>)delegate NS_SWIFT_NAME(removeSessionStateDelegate(_:));

- (BOOL)isConnecting;
- (BOOL)isConnected;

/// Returns the active handoff session, or nil if not currently connected.
- (nullable VZBHandoffSession *)getCurrentSession;

@end

NS_ASSUME_NONNULL_END
