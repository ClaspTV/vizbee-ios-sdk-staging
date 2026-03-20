//
// VZBSmartHandoffCardConfiguration.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import "VZBCardConfiguration.h"

/**
 * Configuration class for customizing the Smart Handoff card UI.
 *
 * This class extends VZBCardConfiguration to provide specific customization
 * options for the card that guides users through the app installation and launching process.
 * It inherits all basic customization properties (title, subtitle, ctaText)
 * from its parent class.
 *
 * Use this configuration when you want to customize the appearance of the card
 * that promotes app installation on the target device for an enhanced viewing
 * experience.
 *
 * @note It is recommended to use cloud configuration instead of API customization
 * for card content. API customization should only be used for specific use cases
 * that require dynamic content. Cloud configuration provides more flexibility and
 * doesn't require app updates for content changes.
 *
 * @note Important: When providing configuration through the API, all properties must be filled.
 * Mixing values between API and cloud configuration is not supported, especially for primitive types.
 * This ensures consistency and prevents unexpected behavior when retrieving values.
 *
 * Example usage:
 * ```
 * VZBSmartHandoffCardConfiguration *config = [[VZBSmartHandoffCardConfiguration alloc] init];
 * config.title = @"Install on TV";
 * config.subtitle = @"Install <app_name> app on your <screen_device_type> for the best viewing experience";
 * config.ctaText = @"Install Now";
 * ```
 */
@interface VZBSmartHandoffCardConfiguration : VZBCardConfiguration

@end
