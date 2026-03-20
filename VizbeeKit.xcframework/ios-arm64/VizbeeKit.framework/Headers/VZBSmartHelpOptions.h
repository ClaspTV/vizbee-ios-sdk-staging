//
// VZBSmartHelpOptions.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBSmartHandoffOptions.h"

@class VZBSmartHandoffContext;

/**
 * Bitmask constants representing individual subflows within the Smart Help flow.
 *
 * Combine using bitwise OR to enable multiple subflows simultaneously.
 * NOTE: VZBSmartHelpSubflowCastAuthorization is defined at bit 1 and
 * VZBSmartHelpSubflowCastIntroduction at bit 2 for cross-platform parity with Android.
 *
 * @see VZBSmartHelpOptions.enabledSubflows
 */
typedef NS_OPTIONS(NSUInteger, VZBSmartHelpSubflow) {
    /** Subflow that handles cast authorization for the user. */
    VZBSmartHelpSubflowCastAuthorization = 1 << 1,

    /** Subflow that introduces the cast functionality to the user. */
    VZBSmartHelpSubflowCastIntroduction  = 1 << 2,

    /** Subflow that guides the user through installing the TV app. */
    VZBSmartHelpSubflowSmartInstall      = 1 << 3,

    /** Subflow that enables seamless content handoff from mobile to TV. */
    VZBSmartHelpSubflowSmartHandoff      = 1 << 4,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Configuration options for the Smart Help flow.
 *
 * Use this class to customize which subflows are active, configure Smart Handoff
 * campaign targeting, and control card visibility behavior before initiating
 * the Smart Help flow.
 */
@interface VZBSmartHelpOptions : NSObject

/**
 * Bitmask of subflows to enable within the Smart Help flow.
 *
 * Defaults to all subflows enabled:
 * VZBSmartHelpSubflowCastAuthorization | VZBSmartHelpSubflowCastIntroduction |
 * VZBSmartHelpSubflowSmartInstall | VZBSmartHelpSubflowSmartHandoff.
 *
 * Example usage:
 * @code
 * options.enabledSubflows = VZBSmartHelpSubflowSmartInstall | VZBSmartHelpSubflowSmartHandoff;
 * @endcode
 *
 * @see VZBSmartHelpSubflow
 */
@property (nonatomic, assign) VZBSmartHelpSubflow enabledSubflows;

/**
 * Optional context for targeting a specific Smart Handoff campaign.
 *
 * When set, the Smart Handoff flow will attempt to use the campaign matching
 * the provided context (e.g., campaignId). Falls back to the default
 * rank-based campaign selection if no matching campaign is found.
 * When nil (default), standard campaign selection logic is applied.
 *
 * @see VZBSmartHandoffContext
 */
@property (nonatomic, strong, nullable) VZBSmartHandoffContext *smartHandoffContext;

@end

NS_ASSUME_NONNULL_END
