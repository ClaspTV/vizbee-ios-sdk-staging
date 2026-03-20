//
// VZBGuidedSmartInstallCardConfiguration.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import "VZBCardConfiguration.h"

/**
* Configuration class for customizing the Guided Smart Install card UI.
*
* This class extends VZBCardConfiguration to provide specific customization
* options for the card that offers step-by-step guidance during app installation.
* It inherits all basic customization properties (title, subtitle, ctaText)
* from its parent class.
*
* Use this configuration when you want to customize the appearance of the card
* that provides a more detailed, guided approach to installing the app on
* target devices. This card type is particularly useful when users might need
* additional assistance or clearer instructions during the installation process.
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
* VZBGuidedSmartInstallCardConfiguration *config = [[VZBGuidedSmartInstallCardConfiguration alloc] init];
* config.title = @"Detected <screen_device_type>";
* config.subtitle = @"Let's get the <app_name> app installed on your <screen_friendly_name> with these simple steps";
* config.ctaText = @"Start Installation";
* ```
*/
@interface VZBGuidedSmartInstallCardConfiguration : VZBCardConfiguration

@end
