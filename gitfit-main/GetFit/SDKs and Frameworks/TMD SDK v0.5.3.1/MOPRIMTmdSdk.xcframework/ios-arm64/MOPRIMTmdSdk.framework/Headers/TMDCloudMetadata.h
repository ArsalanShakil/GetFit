//
//  TMDCloudMetadata.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 27/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// TMD metadata contains information about the information that our cloud knows about a user:
@interface TMDCloudMetadata : NSObject

/// The timestamp (in milliseconds) of the first time the cloud received data (i.e., start of the first recognized activity)
@property (assign) long long firstUploadTimestamp;

/// The last TMD activity timestamp
@property (assign) long long lastTmdTimestamp;

/// The timestamp of the last non-stationary TMD activity
@property (assign) long long lastTmdMovingActivityTimestamp;

/// The timestamp of the last location
@property (assign) long long lastLocationTimestamp;

/// The timestamp of the last upload of TMD
@property (assign) long long lastTmdUploadTimestamp;

/// The timestamp of the last upload of location
@property (assign) long long lastLocationUploadTimestamp;

/// The average daily co2 value for the community
@property (assign) double communityDailyCo2;

/// The average daily distance value for the community
@property (assign) double communityDailyDistance;

/// The average daily duration value for the community
@property (assign) double communityDailyDuration;

- (instancetype)initWithFirstUploadTimestamp:(long long) firstUploadTimestamp
                            lastTmdTimestamp:(long long) lastTmdTimestamp
              lastTmdMovingActivityTimestamp:(long long) lastTmdMovingActivityTimestamp
                       lastLocationTimestamp:(long long) lastLocationTimestamp
                      lastTmdUploadTimestamp:(long long) lastTmdUploadTimestamp
                 lastLocationUploadTimestamp:(long long) lastLocationUploadTimestamp
                           communityDailyCo2:(double) communityDailyCo2
                      communityDailyDistance:(double) communityDailyDistance
                      communityDailyDuration:(double) communityDailyDuration;


/// JSON description of the object.
- (NSString*) description;

@end

NS_ASSUME_NONNULL_END
