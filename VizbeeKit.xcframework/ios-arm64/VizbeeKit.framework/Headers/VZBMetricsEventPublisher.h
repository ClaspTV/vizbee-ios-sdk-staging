//
// VZBMetricsEventPublisher.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VZBMetricsEventPublisher : NSObject

/// Method to send a custom event with a given name and attributes.
/// This method is to be used by outside modules to send events.
/// @param eventName The name of the event to send.
/// @param attributes The attributes associated with the event.
+ (void)sendEventWithName:(NSString *)eventName attributes:(NSDictionary *)attributes;

@end

NS_ASSUME_NONNULL_END
