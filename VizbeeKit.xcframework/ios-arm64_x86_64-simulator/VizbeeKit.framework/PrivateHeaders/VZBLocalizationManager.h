//
// VZBLocalizationManager.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VZBLocalizationManager : NSObject

+ (instancetype)sharedInstance;

/// Override the SDK display language.
/// Must be called before SDK initialization, or via +[Vizbee setLocale:]
/// which is the safe public entry point for runtime locale changes.
- (void)setLocale:(NSLocale *)locale;

/// Returns the currently active locale override, or en-US if no override is set.
/// Never returns nil.
- (NSLocale *)currentLocale;

/// Maps the given locale to the server-side locale code
/// (e.g. @"es-MX", @"pt-BR", @"zh-CN").
/// Returns @"en-US" for any unsupported language.
- (NSString *)currentLocaleCode:(NSLocale *)locale;

/// Resolved bundle to pass to NSLocalizedStringFromTableInBundle.
/// Returns the lproj-scoped bundle if a locale override is active,
/// otherwise returns the en-US.lproj bundle.
- (NSBundle *)resolvedBundle;

@end

NS_ASSUME_NONNULL_END
