//
// VZBEventManager.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VZBEventHandler.h"

@class VZBBaseDeviceClient;

NS_ASSUME_NONNULL_BEGIN

/// Manages events and their handlers by maintaining the mapping among them.
///
/// Conforms to VZBEventHandler and registers itself on the device client's sync layer once
/// per event name. When an event arrives, onEvent: is called on the event manager, which
/// multiplexes to all app-registered handlers for that name. This keeps the sync layer's
/// handler map minimal (one entry per event name) while allowing N app-level subscribers.
@interface VZBEventManager : NSObject <VZBEventHandler>

/// Creates an event manager bound to a specific device client.
/// Preferred over plain -init when a connected device client is available.
- (instancetype)initWithDeviceClient:(nullable VZBBaseDeviceClient *)deviceClient;

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

/// Unregisters self from the device client and clears all registered handlers.
/// Must be called when the owning session ends.
- (void)tearDown;

@end

NS_ASSUME_NONNULL_END
