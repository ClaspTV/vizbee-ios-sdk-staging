//
// VZBMultiDeviceSmartInstallCardConfiguration.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import "VZBCardConfiguration.h"

/**
* Configuration class for customizing the Multi-Device Smart Install card UI.
*
* This class extends VZBCardConfiguration to provide specific customization
* options for the card that promotes app installation across multiple devices.
* It inherits all basic customization properties (title, subtitle, ctaText)
* from its parent class.
*
* Use this configuration when you want to customize the appearance of the card
* that encourages users to install the app on various platforms (like TV, mobile,
* tablet) for a more comprehensive and enhanced viewing experience across their
* devices.
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
* VZBMultiDeviceSmartInstallCardConfiguration *config = [[VZBMultiDeviceSmartInstallCardConfiguration alloc] init];
* config.title = @"Install on TV";
* config.subtitle = @"Select the device to install the app on your TV for seamless viewing";
* ```
*/
@interface VZBMultiDeviceSmartInstallCardConfiguration : VZBCardConfiguration

@end
