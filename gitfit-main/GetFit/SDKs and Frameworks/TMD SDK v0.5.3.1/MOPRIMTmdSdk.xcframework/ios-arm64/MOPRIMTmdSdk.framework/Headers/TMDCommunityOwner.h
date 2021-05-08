//
//  TMDCommunityOwner.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 12/02/2021.
//  Copyright © 2021 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMDCommunityOwner : NSObject

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *contact;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *address;

- (instancetype)initWithName:(NSString*)name contact:(NSString*)contact email:(NSString*)email address:(NSString*)address;
+ (TMDCommunityOwner*)communityOwnerFromDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
