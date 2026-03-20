//
// VZBUIConfiguration.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "VZBCardConfiguration.h"

/**
 * VZBUIConfiguration
 *
 * This class manages the configuration for the UI components of the Vizbee Kit.
 * It allows setting and retrieving card configurations for different card types,
 */
@interface VZBUIConfiguration : NSObject

/**
 * Sets the card configuration for a specific card type.
 *
 * @param cardConfiguration The configuration to set.
 * @param cardType The type of card for which to set the configuration.
 */
-(void) setCardConfiguration:(VZBCardConfiguration* _Nonnull) cardConfiguration
                 forCardType:(VZBUICardType)cardType;

/**
 * Retrieves the card configuration for a specific card type.
 *
 * @param cardType The type of card for which to retrieve the configuration.
 * @return The card configuration for the specified card type.
 */
-(VZBCardConfiguration* _Nullable) getCardConfiguration:(VZBUICardType)cardType;

/**
 * Removes the card configuration for a specific card type.
 *
 * @param cardType The type of card for which to remove the configuration.
 */
-(void) removeCardConfiguration:(VZBUICardType)cardType;

@end
