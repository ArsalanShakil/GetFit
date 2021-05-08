//
//  TMDUploadDelegate.h
//  Demo
//
//  Created by Kyrill Cousson on 05/02/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TMDUploadDelegate <NSObject>

@optional

/// Notifies that an upload has started
- (void)uploadDidStart;

/// Notifies that an upload has completed
- (void)uploadDidEnd;

@end
