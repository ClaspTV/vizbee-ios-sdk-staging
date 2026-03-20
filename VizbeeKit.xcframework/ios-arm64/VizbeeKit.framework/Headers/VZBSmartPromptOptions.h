//
// VZBSmartPromptOptions.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VZBSmartHandoffContext;

/**
 * Bitmask constants representing individual subflows within the Smart Prompt flow.
 *
 * Combine using bitwise OR to enable multiple subflows simultaneously.
 *
 * @see VZBSmartPromptOptions.enabledSubflows
 */
typedef NS_OPTIONS(NSUInteger, VZBSmartPromptSubflow) {
    /** Subflow that handles cast authorization for the user. */
    VZBSmartPromptSubflowCastAuthorization = 1 << 1,

    /** Subflow that introduces the cast functionality to the user. */
    VZBSmartPromptSubflowCastIntroduction  = 1 << 2,

    /** Subflow that guides the user through installing the TV app. */
    VZBSmartPromptSubflowSmartInstall      = 1 << 3,

    /** Subflow that enables seamless content handoff from mobile to TV. */
    VZBSmartPromptSubflowSmartHandoff      = 1 << 4,
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Configuration options for the Smart Prompt flow.
 *
 * Use this class to customise which subflows are active, configure Smart Handoff
 * campaign targeting, before initiating the Smart Prompt flow.
 */
@interface VZBSmartPromptOptions : NSObject

/**
 * Bitmask of subflows to enable within the Smart Prompt flow.
 *
 * Defaults to all subflows enabled:
 * VZBSmartPromptSubflowCastAuthorization | VZBSmartPromptSubflowCastIntroduction |
 * VZBSmartPromptSubflowSmartInstall | VZBSmartPromptSubflowSmartHandoff.
 *
 * Example usage:
 * @code
 * options.enabledSubflows = VZBSmartPromptSubflowSmartInstall | VZBSmartPromptSubflowSmartHandoff;
 * @endcode
 *
 * @see VZBSmartPromptSubflow
 */
@property (nonatomic, assign) VZBSmartPromptSubflow enabledSubflows;

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
