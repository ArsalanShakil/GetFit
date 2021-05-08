//
//  TMDCommunityAPIStatusReponse.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 06/07/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMDCommunityAPIStatusResponse) {
    TMDCommunityAPIStatusResponseStandardAttributeMissing,
    TMDCommunityAPIStatusResponseCustomAttributeMissing,
    TMDCommunityAPIStatusResponseCommunityNotFound,
    TMDCommunityAPIStatusResponsePendingVerification,
    TMDCommunityAPIStatusResponseValidationCodeMissing,
    TMDCommunityAPIStatusResponseValidationCodeInvalid,
    TMDCommunityAPIStatusResponseSuccessfullyJoined,
    TMDCommunityAPIStatusResponseAlreadyJoined,
    TMDCommunityAPIStatusResponseCustomAttributeInvalid,
    TMDCommunityAPIStatusResponseUnknown
};

@interface TMDCommunityAPIReponse : NSObject

@property (atomic, assign)      TMDCommunityAPIStatusResponse status;
@property (nonatomic, strong)   NSString *message;

- (instancetype)initWithStatus:(TMDCommunityAPIStatusResponse)status message:(NSString*)message;
- (NSString*)statusString;
+ (TMDCommunityAPIReponse*)responseFromDictionary:(NSDictionary*)dictionary;

@end

NS_ASSUME_NONNULL_END
