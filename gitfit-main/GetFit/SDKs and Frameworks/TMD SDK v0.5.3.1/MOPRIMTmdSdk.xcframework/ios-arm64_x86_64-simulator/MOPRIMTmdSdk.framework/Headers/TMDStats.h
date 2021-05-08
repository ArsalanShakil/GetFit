//
//  TMDStats.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 27/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMDStatsValue : NSObject

/// The activity name
@property (nonatomic, strong) NSString *activity;

/// The amount of CO2 (in grams) generated during the activity, for the user
@property (assign) double userCo2;

/// The distance in meters covered in the activity, for the user
@property (assign) double userDistance;

/// The duration in seconds of the activity, for the user
@property (assign) NSTimeInterval userDuration;

/// The number of times this activity was detected for that period, for the user
@property (assign) int userLegs;

/// The average amount of CO2 (in grams)  for the community for this activity
@property (assign) double communityCo2;

/// The average distance in meters for the community for this activity
@property (assign) double communityDistance;

/// The average duration in seconds for the community for this activity
@property (assign) NSTimeInterval communityDuration;

/// The number of times this activity was detected for that period, for the community
@property (assign) int communityLegs;

/// The number of users in the community
@property (assign) int communitySize;

/// The statistics date
@property (nonatomic, strong) NSString *dateString;

- (instancetype)initWithActivity:(NSString *)activity
                         userCo2:(double)userCo2
                    userDistance:(double)userDistance
                    userDuration:(NSTimeInterval)userDuration
                        userLegs:(int)userLegs
                    communityCo2:(double)communityCo2
               communityDistance:(double)communityDistance
               communityDuration:(NSTimeInterval)communityDuration
                   communityLegs:(int)communityLegs
                   communitySize:(int)communitySize
                      dateString:(NSString*)dateString;

- (instancetype)initWithActivity:(NSString *)activity
                      dictionary:(NSDictionary *)stats
                   communitySize:(int)communitySize
                      dateString:(NSString*)dateString;

- (BOOL)hasSameDataThanStatsValue:(TMDStatsValue *)other;

@end

/** TMDStats contains statistics on modalities (arrays of TMDStatsValue) sorted by dates.
  * Each TMDStatsValue comes with the modality name, the combined sum of CO2 emissions, distance and duration for the user and for the community. */
@interface TMDStats : NSObject

- (instancetype)init;
- (instancetype)initWithDictionary:(NSDictionary <NSString*, NSArray<TMDStatsValue*>*> *)dictionary;
- (instancetype)initWithStatsValues:(NSArray<TMDStatsValue *> *)statsValues betweenDate:(NSString*)startDateString andDate:(NSString*)endDateString;

- (BOOL)hasSameDataThanStats:(TMDStats *)other;

- (NSArray<TMDStatsValue *>*)statsForDate:(NSString*)dateString;
- (NSArray<NSString*>*)dates;
- (NSArray<TMDStatsValue *>*)allStats;

+ (TMDStats *)fromJsonData:(NSData *)jsonData error:(NSError * _Nullable *)error betweenDate:(NSString*)startDateString andDate:(NSString*)endDateString;

@end

NS_ASSUME_NONNULL_END
