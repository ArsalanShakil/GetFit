//
//  TMDStatus.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 25/09/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMDStatus : NSObject

typedef enum {
    // At Tmd init, before the services start
    TMDEventNotRunning,
    
    // TMD is active and monitoring motion
    TMDEventIdle,
    
    // TMD is recording
    TMDEventRecording,
    
    // TMD has stopped because location permission changed
    TMDEventStoppedCauseInsufficientPermission,
    
    // TMD has been stopped manually via [TMD stop];
    TMDEventStoppedManually,
    
    // TMD could not start because of a problem with Motion & Fitness service availability/permissions
    TMDEventStartFailedCauseInsufficientMotionFitnessServices,
    
    // TMD could not start because of a problem with Location service availability/permissions
    TMDEventStartFailedCauseInsufficientLocationServices,
    
    // Application was killed
    TMDEventAppKilled,
    
    // Application was not running and the reason for that is unkown
    TMDEventAppNotRunningCauseUnknown,

    // Unkown event
    TMDEventUnknown
} TMDStatusName;

@property (assign) long long tmdStatusId;
@property (assign) long long timestampStart;
@property (assign) long long timestampEnd;
@property (nonatomic, strong) NSString *label;
@property BOOL syncedWithCloud;

- (instancetype)initWithId:(long long)tmdStatusId
        withTimestampStart:(long long)timestampStart
         withTimestampStop:(long long)timestampStop
                 withLabel:(NSString *)label
                withSynced:(BOOL)syncedWithCloud;

- (NSTimeInterval)duration;

+ (NSString*) tmdStatusNameToString:(TMDStatusName) tmdStatusName;
- (TMDStatusName) tmdStatusName;

@end

NS_ASSUME_NONNULL_END
