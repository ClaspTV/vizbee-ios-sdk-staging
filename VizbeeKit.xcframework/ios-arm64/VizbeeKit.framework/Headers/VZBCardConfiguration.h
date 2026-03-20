//
//  VZBCardConfiguration.h
//  VizbeeKit
//
//  Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An enumeration of different card types used in the Vizbee UI.
 * Each type represents a specific card variant serving different purposes.
 *
 * @note It is recommended to use cloud configuration instead of API customization
 * for card content. API customization should only be used for specific use cases
 * that require dynamic content. Cloud configuration provides more flexibility and
 * doesn't require app updates for content changes.
 */
typedef NS_ENUM(NSInteger, VZBUICardType) {
    
    /**
     * Card for requesting cast authorization from users.
     */
    VZBUICardTypeCastAuthorization,
    
    /**
     * Card for introducing cast functionality to users.
     */
    VZBUICardTypeCastIntroduction,
    
    /**
     * Card for smart app installation process.
     */
    VZBUICardTypeSmartInstall,
    
    /**
     * Card providing step-by-step guidance for app installation.
     */
    VZBUICardTypeGuidedSmartInstall,
    
    /**
     * Card for promoting app installation across multiple devices.
     */
    VZBUICardTypeMultiDeviceSmartInstall,
    
    /**
     * Card for cross-app promotion and TV deeplinking.
     */
    VZBUICardTypeSmartHandoff
};

/**
 * Base configuration class for customizing Vizbee UI cards.
 * It contains properties for customizing the appearance and content of cards.
 *
 * @note Important: When providing configuration through the API, all properties must be filled.
 * Mixing values between API and cloud configuration is not supported, especially for primitive types.
 * This ensures consistency and prevents unexpected behavior when retrieving values.
 */
@interface VZBCardConfiguration : NSObject

/**
 * The title text for the card.
 *
 * This is the primary text displayed on the card that catches user attention.
 * @note If not set, a cloud configured title or default title will be used.
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 * The subtitle or description text for the card.
 *
 * Provides additional context or details below the title.
 * @note If not set, a cloud configured subtitle or default subtitle will be used.
 */
@property (nonatomic, copy, nullable) NSString *subtitle;

/**
 * The text displayed on the call-to-action (CTA) button.
 *
 * Use this to customize the text of buttons that prompt user actions,
 * such as "Confirm", "Get Started", etc.
 * @note If not set, a cloud configured CTA text or default text will be used.
 */
@property (nonatomic, copy, nullable) NSString *ctaText;

@end
