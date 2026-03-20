//
// VZBEvent.h
// VizbeeKit
//
// Copyright © Vizbee. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface VZBEvent : NSObject

- (instancetype)initWithName:(NSString *)name andData:(NSDictionary *)data;

@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, strong, readonly) NSDictionary *data;

@end

NS_ASSUME_NONNULL_END
