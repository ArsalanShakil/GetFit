//
//  TMDUserApi.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 25/05/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTask.h"
#import "TMDUserPersonalInfo.h"
#import "TMDUserSessionDelegate.h"
#import "TMDCommunity.h"

NS_ASSUME_NONNULL_BEGIN

@interface TMDUserApi : NSObject

+ (TMDUserApi *)sharedInstance;
- (bool)isInitialized;

- (void)initializeUserApiWithInitialStateCompletion:(void (^)(enum TMDUserState, NSError * _Nullable))initialStateCompletion;
- (void)setSessionStateDelegate:(id<TMDUserSessionDelegate>)delegate;
+ (TMDUserState)userSessionState;
+ (NSString*)userSessionStateString:(TMDUserState)state;

+ (TMDTask <NSNumber*> *)signInWithEmail:(NSString*)email password:(NSString*)password;
+ (TMDTask <NSNumber*> *)signUpWithEmail:(NSString*)email password:(NSString*)password;
+ (TMDTask <NSNumber*> *)confirmSignUpWithEmail:(NSString*)email confirmationCode:(NSString*)confirmationCode;
+ (TMDTask <NSNumber*> *)resendConfirmationCodeForEmail:(NSString*)email;
+ (TMDTask <NSNumber*> *)forgotPasswordForEmail:(NSString*)email;
+ (TMDTask <NSNumber*> *)setNewPassword:(NSString*)password forEmail:(NSString*)email withConfirmationCode:(NSString*)confirmationCode;
+ (void)signOut;

+ (TMDTask <NSString*> *)getUsername;
+ (TMDTask <TMDUserPersonalInfo *> *)getUserPersonalInfo;
+ (TMDTask <TMDUserPersonalInfo *> *)updateUserPersonalInfo:(TMDUserPersonalInfo *)userPersonalInfo;
+ (TMDTask <NSArray <TMDCommunityUserField*> *> *)missingPersonalInfoFieldsForCommunity:(TMDCommunity *)community;

@end

NS_ASSUME_NONNULL_END
