//
//  TMDActivity.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 27/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// This class includes all information pertaining to the TMD activity collected from the Moprim Cloud.
@interface TMDActivity : NSObject

/// The unique id of the activity when stored in the local cache
@property (assign) long long activityId;

/// The UTC timestamp (in ms) of the last download of the TMD activity
@property long long timestampDownload;

/// The UTC timestamp (in ms) of the start of the TMD activity
@property (assign) long long timestampStart;

/// The UTC timestamp (in ms) of the end of the TMD activity
@property (assign) long long timestampEnd;

/// The UTC timestamp (in ms) of the last update of the TMD activity
@property (assign) long long timestampUpdate;

/// The corrected label of the activity
@property (nonatomic, strong) NSString *correctedActivity;

/// The original label of the activity
@property (nonatomic, strong) NSString *originalActivity;

/// The amount of CO2 (in grams) generated during the activity.
@property (assign) double co2;

/// The distance in meters covered in the activity
@property (assign) double distance;

/// The average speed (in kilometers per hours) during the activity
@property (assign) double speed;

/// The encoded polyline of the GPS locations during the activity
@property (nonatomic, strong) NSString *polyline;

/// The origin of the activity, or the location for the stationary activity
@property (nonatomic, strong) NSString *origin;

/// The destination of the activity, null for stationary
@property (nonatomic, strong) NSString *destination;

/// The metadata annotated to the TMD activity
@property (nonatomic, strong) NSString *metadata;

/// Indicates whether the activity was either validated or corrected by the user
@property BOOL verifiedByUser;

/// Indicates whether change made manually on the activity have been synced with the cloud
@property BOOL syncedWithCloud;

- (instancetype)initWithId:(long long)activityId timestampDownload:(long long)timestampDownload
        timestampStart:(long long)timestampStart timestampEnd:(long long)timestampEnd timestampUpdate:(long long)timestampUpdate
      originalActivity:(NSString *)originalActivity correctedActivity:(nullable NSString *)correctedActivity
                   co2:(double)co2 distance:(double)distance speed:(double)speed
              polyline:(NSString *)polyline origin:(nullable NSString *)origin destination:(nullable NSString *)destination
              metadata:(nullable NSString *)metadata verifiedByUser:(BOOL)verifiedByUser synced:(BOOL)syncedWithCloud;


/** Returns TRUE if the activity has same start and stop timestamp than 'other'
 *
 * Activities are usually compared with their timestamps.*/
- (BOOL)hasSameTimestampsThanActivity:(TMDActivity *)other;

/// Compares 2 TMDActivity objects, ignoring activityId, timestampDownload, timestampUpdate and syncedWithCloud
- (BOOL)hasSameDataThanActivity:(TMDActivity *)other;

/// Returns TRUE if the timestamps of both activities overlap
- (BOOL)overlapsWithActivity:(TMDActivity *)other isInclusive:(BOOL)isInclusive;

/// The duration (in seconds) of the activity
- (NSTimeInterval)duration;

/// The label of the activity
- (NSString *)activity;

/// Returns TRUE if the corrected label has been set by the user
- (BOOL)isCheckedByUser;

/** Returns TRUE if the corrected activity and original activity are the same
 *
 * This function is only used to validate the results of the TMD. */
- (BOOL)isCorrect;

@end

NS_ASSUME_NONNULL_END
