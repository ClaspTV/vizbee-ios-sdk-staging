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

/// Override the SDK display language. Pass nil to revert to en-US.
- (void)setLocale:(nullable NSLocale *)locale;

/// Returns the currently active locale override, or en-US if using system language.
- (nullable NSLocale *)currentLocale;

/// Returns the current locale mapped to the server-side locale code
/// (matches Android pref_entries_app_language_values).
/// Returns en-US if the current language has no server mapping.
- (nullable NSString *)currentLocaleCode;

/// Resolved bundle to pass to NSLocalizedStringFromTableInBundle.
/// Returns the lproj-scoped bundle if a locale override is active,
/// otherwise returns the full framework bundle (system language).
- (NSBundle *)resolvedBundle;

@end

NS_ASSUME_NONNULL_END
