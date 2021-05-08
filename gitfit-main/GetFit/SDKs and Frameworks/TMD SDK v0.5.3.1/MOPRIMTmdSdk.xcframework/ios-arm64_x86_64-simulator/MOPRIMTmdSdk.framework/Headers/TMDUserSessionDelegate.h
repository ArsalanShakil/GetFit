//
//  TMDUserSessionDelegate.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 28/05/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDUserApi.h"

typedef NS_ENUM(NSUInteger, TMDUserState) {
    signedIn, signedOut, signedOutFederatedTokensInvalid, signedOutUserPoolsTokenInvalid, guest, unknown
};

@protocol TMDUserSessionDelegate <NSObject>
- (void)sessionStateDidChange:(TMDUserState)state;
@end
