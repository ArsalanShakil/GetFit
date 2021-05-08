//
//  TMDUserPersonalInfo.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 26/06/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMDUserPersonalInfo : NSObject

@property (nonatomic, strong) NSString *phone_number;
@property (nonatomic, strong) NSString *nickname;
@property (nonatomic, strong) NSString *given_name;
@property (nonatomic, strong) NSString *family_name;
@property (nonatomic, strong) NSString *gender;
@property (nonatomic, strong) NSString *address;
@property (nonatomic, strong) NSString *birthdate;
@property (nonatomic, strong) NSString *locale; // the user's preferred language
@property (nonatomic, strong) NSString *zoneinfo; // the user's timezone

@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *email_verified;

- (instancetype)initWithUserAttributes:(NSDictionary<NSString *,NSString *> * )attributes;
- (NSDictionary*)toDictionary;
- (NSString*)description;

+ (NSString*)fieldNamePhone;
+ (NSString*)fieldNameNickname;
+ (NSString*)fieldNameGivenName;
+ (NSString*)fieldNameFamilyName;
+ (NSString*)fieldNameGender;
+ (NSString*)fieldNameAddress;
+ (NSString*)fieldNameBirthdate;
+ (NSString*)fieldNameLocale;
+ (NSString*)fieldNameZoneInfo;

@end

NS_ASSUME_NONNULL_END
