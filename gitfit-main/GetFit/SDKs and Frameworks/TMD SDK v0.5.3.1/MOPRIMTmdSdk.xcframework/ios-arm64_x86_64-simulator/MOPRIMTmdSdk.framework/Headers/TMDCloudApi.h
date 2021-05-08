//
//  TMDCloudApi.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 27/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TMDTask.h"
#import "TMDActivity.h"
#import "TMDStats.h"
#import "TMDStatus.h"
#import "TMDCommunity.h"
#import "TMDCommunityCard.h"
#import "TMDCommunityAPIReponse.h"
#import "TMDCloudMetadata.h"
#import "TMDUploadMetadata.h"
#import "TMDUploadDelegate.h"
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "TMDSyntheticRequestType.h"

NS_ASSUME_NONNULL_BEGIN

/// This class offers static functions to interact with the Moprim Cloud. Most common use cases are fetching data and metadata and uploading data to the sync.
@interface TMDCloudApi : NSObject


/*! @brief Fetch TMD activity data from the Moprim Cloud for the defined date
 * @param date the date (only the day, month, year components are relevant)
 * @param offset Number of minutes after midnight that indicates the start of the day. (example: if you want data for the day and consider that days should be separated at 4AM instead of midnight, set this parameter to 240.0.
 * Set this parameter to 0.0 if you want days to be separated at midnight.
 * @return A list of TMD activities if successful, an error otherwise.
 */
+ (TMDTask<NSArray<TMDActivity *> *> *) fetchData:(NSDate *)date minutesOffset:(double)offset;

/*! @brief Fetch TMD activity data from the Moprim Cloud between two timestamps
 * @param start the start time (timestamp in ms)
 * @param end the end time (timestamp in ms)
 * @return A list of TMD activities if successful, an error otherwise.
 */
+ (TMDTask<NSArray<TMDActivity *> *> *) fetchDataWithStart:(long long)start withEnd:(long long)end;

/** Fetch TMD activity data from the cache for the defined date
 *
 * Use this method if you wish not to request data from the cloud
 * @param date the date (only the day, month, year components are relevant)
 * @param offset Number of minutes after midnight that indicates the start of the day. (example: if you want data for the day and consider that days should be separated at 4AM instead of midnight, set this parameter to 240.0.
 * Set this parameter to 0.0 if you want days to be separated at midnight.
 * @return A list of TMD activities if successful, an error otherwise.
 */
+ (TMDTask<NSArray<TMDActivity *> *> *) fetchDataFromCache:(NSDate *)date minutesOffset:(double)offset NS_SWIFT_NAME(fetchDataFromCache(_:minutesOffset:));

/** Fetch TMD activity data from the cache between two timestamps
 *
 * Use this method if you wish not to request data from the cloud
 * @param start the start time (timestamp in ms)
 * @param end the end time (timestamp in ms)
 * @return A list of TMD activities if successful, an error otherwise.
*/
+ (TMDTask<NSArray<TMDActivity *> *> *) fetchDataFromCacheWithStart:(long long)start withEnd:(long long)end;

+ (TMDTask <NSArray<TMDStatus *> *> *)fetchLongTmdStatusesFromCache:(NSDate *)date minutesOffset:(double)offset;

+ (TMDTask<NSArray<TMDStatus *> *> *) fetchLongTmdStatusesFromCacheWithStart:(long long)start withEnd:(long long)end;

/*!
 * @brief Fetching stats from the Moprim cloud.
 * @param nbDays the number of days to compute the statistics for (e.g. 30 for the last 30 days)
 * @return A TMDStats object containing the statistics.
 */
+ (TMDTask<TMDStats *> *) fetchStatsForLast: (NSInteger) nbDays;

/*!
* @brief Fetching stats from the cloud
* @param startDate the start date in ISO format "yyyy-MM-dd"
* @param endDate the end date in ISO format "yyyy-MM-dd"
* @return A TMDStats object containing the statistics between startDate and endDate (including those dates).
*/
+ (TMDTask <TMDStats *> *) fetchStatsWithStartDate :(NSString*)startDate withEnd: (NSString*)endDate;

/*!
 * @brief Fetching stats from the local cache
 * @param nbDays the number of days to compute the statistics for (e.g. 30 for the last 30 days)
 * @return A TMDStats object containing the statistics.
 */
+ (TMDTask <TMDStats *> *) fetchStatsFromCacheForLast: (NSInteger) nbDays;


/*!
* @brief Fetching stats from the local cache
* @param startDate the start date in ISO format "yyyy-MM-dd"
* @param endDate the end date in ISO format "yyyy-MM-dd"
* @return A TMDStats object containing the statistics between startDate and endDate (including those dates).
*/
+ (TMDTask <TMDStats*> *) fetchStatsFromCacheWithStartDate :(NSString*)startDate withEnd: (NSString*)endDate;

+ (TMDTask <NSArray <TMDCommunity *> *> *) fetchUserCommunitiesFromCacheForLanguage:(NSString*)language;
+ (TMDTask <NSArray <TMDCommunity *> *> *) fetchNotJoinedCommunitiesFromCacheForLanguage:(NSString*)language;
+ (TMDTask <NSArray <TMDCommunity *> *> *) fetchUserCommunitiesFromCloudForLanguage:(NSString*)language;
+ (TMDTask <NSArray <TMDCommunity *> *> *) fetchNotJoinedCommunitiesFromCloudForLanguage:(NSString*)language;

+ (TMDTask <TMDCommunity *> *) getCommunityFromCacheWithId:(NSString*)communityId forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunity *> *) getCommunityWithId:(NSString*)communityId forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunity *> *) findCommunityWithCode:(NSString*)code forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunityAPIReponse *> *) joinCommunityWithId:(NSString*)communityId forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunityAPIReponse *> *) joinCommunityWithId:(NSString*)communityId withParameters:(NSDictionary*)parameters forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunityAPIReponse *> *) joinCommunityWithId:(NSString*)communityId withConfirmationCode:(NSString*)code forLanguage:(NSString*)language;
+ (TMDTask *) leaveCommunityWithId:(NSString*)communityId forLanguage:(NSString*)language;
+ (TMDTask <TMDCommunity *> *) forgetCommunityWithId:(NSString*)communityId forLanguage:(NSString*)language;
+ (TMDTask <UIImage *> *) getCommunityIconWithId:(NSString*)communityId withShape:(TMDCommunityIconShape)shape forLanguage:(NSString*)language;
+ (TMDTask <NSArray <TMDCommunityCard *> *> *) getCommunityCardsForAppLocation:(NSString* _Nullable)appLocation forLanguage:(NSString*)language;
+ (TMDTask <NSArray <TMDCommunityCard *> *> *) getCommunityCardsFromCacheForAppLocation:(NSString* _Nullable)appLocation forLanguage:(NSString*)language;

/** Fetch the metadata from the Cloud.
 *
 * This function is usually called when one wants to know what data can be fetched from the Cloud
 * @return The cloud metadata.
 */
+ (TMDTask<TMDCloudMetadata *> *) fetchMetadata;

/** Fetch the metadata from the cache.
 *
 * This function is usually called when one wants to know what data can be fetched from the Cloud
 * @return The cloud metadata.
 */
+ (TMDTask<TMDCloudMetadata *> *) fetchMetadataFromCache;

/*!
 * @brief Upload the collected data to the cloud pro-actively
 * @return A TMDUploadMetadata object indicating how much data was sent.
 */
+ (TMDTask<TMDUploadMetadata *> *) uploadData;

/*!
* @brief Upload the collected data to the cloud pro-actively and notifies the delegate when the upload starts and ends
* @return A TMDUploadMetadata object indicating how much data was sent.
*/
+ (TMDTask <TMDUploadMetadata *> *) uploadDataWithDelegate:(id<TMDUploadDelegate> _Nullable)delegate;



/*!
 * @brief Generates synthetic data in the cloud, that can be fetched right after. The start timestamp of the generated trip will be the execution date of the method.
 * @param origin the origin location of the trip
 * @param destination the end location of the trip
 * @param type the type of synthetic data wanted
 * @param apiKey your API key to use the Here API
 * @return A string indicating what data has been added to the cloud
 */
+ (TMDTask<NSString *>*)generateSyntheticDataWithOriginLocation:(CLLocation*)origin
                                        destination:(CLLocation*)destination
                                        requestType:(TMDSyntheticRequestType)type
                                         hereApiKey:(NSString*)apiKey;

/*!
 * @brief Generates synthetic data in the cloud, that can be fetched right after.
 * @param origin the origin location of the trip
 * @param destination the end location of the trip
 * @param start the start timestamp of the trip (in ms)
 * @param type the type of synthetic data wanted
 * @param apiKey your API key to use the Here API
 * @return A string indicating what data has been added to the cloud
 */
+ (TMDTask<NSString *>*)generateSyntheticDataWithOriginLocation:(CLLocation*)origin
                                        destination:(CLLocation*)destination
                                     startTimestamp:(long long)start
                                        requestType:(TMDSyntheticRequestType)type
                                         hereApiKey:(NSString*)apiKey;

/*!
 * @brief Generates synthetic data in the cloud, that can be fetched right after.
 * @param origin the origin location of the trip
 * @param destination the end location of the trip
 * @param stop the timestamp of the end of the trip (in ms)
 * @param type the type of synthetic data wanted
 * @param apiKey your API key to use the Here API
 * @return A string indicating what data has been added to the cloud
 */
+ (TMDTask<NSString *>*)generateSyntheticDataWithOriginLocation:(CLLocation*)origin
                                        destination:(CLLocation*)destination
                                      stopTimestamp:(long long)stop
                                        requestType:(TMDSyntheticRequestType)type
                                         hereApiKey:(NSString*)apiKey;

/*!
 * @brief Correct the label of activity
 * @param activity the activity to correct
 * @param correctedLabel the new label
 * @return The corrected activity object.
 */
+ (TMDTask<TMDActivity*>*) correctActivity:(TMDActivity*)activity withLabel:(NSString*)correctedLabel NS_SWIFT_NAME(correctActivity(_:withLabel:));

/*!
 * @brief Annotate the activity with metadata
 * @param activity the activity to annotate
 * @param metadata the metadata
 * @return The annotated activity object.
 */
+ (TMDTask<TMDActivity *> *) annotateActivity:(TMDActivity *)activity withMetadata: (NSString *)metadata;

/*!
 * @brief Update the label and metadata of the activity
 * @param activity the activity to update
 * @param correctedLabel the new label
 * @param metadata the metadata
 * @return The updated activity object.
 */
+ (TMDTask<TMDActivity *> *) updateActivity:(TMDActivity *)activity
                                   withLabel:(NSString *)correctedLabel
                               withMetadata:(NSString *)metadata NS_SWIFT_NAME(updateActivity(_:withLabel:withMetadata:));

@end

NS_ASSUME_NONNULL_END
