//
// VZBCastAuthorizationCardConfiguration.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import "VZBCardConfiguration.h"

/**
 * Configuration class for customizing the Cast Authorization card UI.
 *
 * This class extends VZBCardConfiguration to provide specific customization
 * options for the card shown during cast authorization flows. It inherits all
 * basic customization properties (title, subtitle, ctaText) from its parent class.
 *
 * Use this configuration when you need to customize the appearance of the card
 * that appears during cast permission requests or authorization processes.
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
 * VZBCastAuthorizationCardConfiguration *config = [[VZBCastAuthorizationCardConfiguration alloc] init];
 * config.title = @"Allow Casting";
 * config.subtitle = @"Cast your favorite content to your TV";
 * config.ctaText = @"Continue";
 * ```
 */
@interface VZBCastAuthorizationCardConfiguration : VZBCardConfiguration

@end
