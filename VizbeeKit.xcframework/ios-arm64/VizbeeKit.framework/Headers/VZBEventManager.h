//
// VZBEventManager.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBEventHandler.h"

NS_ASSUME_NONNULL_BEGIN

/// Manages events and their handlers by maintaining the mapping among them
@interface VZBEventManager : NSObject

/// Registers a handler for an event name.
/// - Parameters:
///   - eventName: event name
///   - eventHandler: event handler
- (void)registerForEvent:(NSString *)eventName 
            eventHandler:(id<VZBEventHandler>)eventHandler;

/// Unregisters a handler for an event name.
/// - Parameters:
///   - eventName: event name
///   - eventHandler: event handler
- (void)unregisterForEvent:(NSString *)eventName 
              eventHandler:(id<VZBEventHandler>)eventHandler;


/// Sends a custom message to receiver device.
/// - Parameters:
///   - name: event name.
///   - data: payload sent to receiver device. Expected as JSON.
- (void)sendEventWithName:(nonnull NSString *)name
                  andData:(nonnull NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
