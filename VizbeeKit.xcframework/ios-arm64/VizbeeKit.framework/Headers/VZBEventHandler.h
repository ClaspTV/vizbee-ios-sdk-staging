//
// VZBEventHandler.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//
#import "VZBEvent.h"

@protocol VZBEventHandler <NSObject>

- (void)onEvent:(VZBEvent *)event;

@end
