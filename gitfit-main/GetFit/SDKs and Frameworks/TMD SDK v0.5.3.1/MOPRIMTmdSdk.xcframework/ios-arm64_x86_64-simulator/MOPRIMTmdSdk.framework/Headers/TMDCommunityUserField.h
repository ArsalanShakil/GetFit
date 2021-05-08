//
//  TMDCommunityUserField.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 01/07/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMDCommunityUserFieldType) {
    TMDCommunityUserFieldTypeEmail,
    TMDCommunityUserFieldTypePhone,
    TMDCommunityUserFieldTypeText,
    TMDCommunityUserFieldTypeNumber,
    TMDCommunityUserFieldTypeUnknown
};

@interface TMDCommunityUserField : NSObject

@property (nonatomic, strong) NSString *filter;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *fieldDescription;
@property (nonatomic, strong) NSString *type;
@property (atomic, assign)    bool verified;
@property (atomic, assign)    bool mandatory;
@property (atomic, assign)    bool isStandard;

- (instancetype)initWithCustomName:(NSString*)name description:(NSString*)description mandatory:(bool)mandatory filter:(NSString*)filter placeholder:(NSString*)placeholder type:(NSString*)type verified:(bool)verified;

- (TMDCommunityUserFieldType)fieldType;
+ (NSArray <TMDCommunityUserField*>*)customFieldsFromDictionaryArray:(NSArray*)dictionaries;
+ (NSArray <TMDCommunityUserField*>*)standardFieldsFromDictionaryArray:(NSArray*)dictionaries;

@end

NS_ASSUME_NONNULL_END
