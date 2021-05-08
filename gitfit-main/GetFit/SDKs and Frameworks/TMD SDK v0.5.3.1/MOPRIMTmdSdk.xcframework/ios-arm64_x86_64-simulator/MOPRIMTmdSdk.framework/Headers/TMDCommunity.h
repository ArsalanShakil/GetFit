//
//  TMDCommunity.h
//  MOPRIMTmdSdk
//
//  Created by Kyrill Cousson on 22/05/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TMDCommunityUserField.h"
#import "TMDCommunityOwner.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMDCommunityIconShape) {
    TMDCommunityIconShapeSquare,
    TMDCommunityIconShapeWide,
};

typedef NS_ENUM(NSInteger, TMDCommunityUserStatus) {
    TMDCommunityUserStatusUnknown,
    TMDCommunityUserStatusNotJoined,
    TMDCommunityUserStatusJoined,
    TMDCommunityUserStatusPendingVerification,
    TMDCommunityUserStatusLeft
};

typedef NS_ENUM(NSInteger, TMDCommunityMobilityData) {
    TMDCommunityMobilityDataTimestamp,
    TMDCommunityMobilityDataCO2,
    TMDCommunityMobilityDataDistance,
    TMDCommunityMobilityDataDuration,
    TMDCommunityMobilityDataPath,
    TMDCommunityMobilityDataPOIStart,
    TMDCommunityMobilityDataPOIStop
};

typedef NS_ENUM(NSInteger, TMDCommunityReportedMode) {
    TMDCommunityReportedModeUser,
    TMDCommunityReportedModeGlobal,
    TMDCommunityReportedModeUnknown
};

typedef NS_ENUM(NSInteger, TMDCommunityReportingPeriod) {
    TMDCommunityReportingPeriodLeg,
    TMDCommunityReportingPeriodHourly,
    TMDCommunityReportingPeriodDaily,
    TMDCommunityReportingPeriodWeekly,
    TMDCommunityReportingPeriodMonthly,
    TMDCommunityReportingPeriodOther
};

/// This class includes all information pertaining to the TMD activity collected from the Moprim Cloud.
@interface TMDCommunity : NSObject

/// The unique id of the community
@property (nonatomic, strong) NSString *communityId;

/// The metadata annotated to the TMD activity
@property (nonatomic, strong) NSString *name;

@property (nonatomic, strong) NSDictionary <NSString*, id> *communityOwnerDictionary;
@property (nonatomic, strong) NSString *shortDescription;
@property (nonatomic, strong) NSString *longDescription;
@property (nonatomic, strong) NSString * _Nullable url;
@property (nonatomic, strong) NSString *visibility;
@property (nonatomic, strong) NSString *sharedMobilityData;
@property (nonatomic, strong) NSString *sharedMobilityModes;
@property (nonatomic, strong) NSString *reportedMode;
@property (nonatomic, strong) NSString *reportingPeriod;
@property (nonatomic, strong) NSString *customFields;
@property (nonatomic, strong) NSString *standardFields;
@property (nonatomic, strong) NSArray <TMDCommunityUserField*> *customFieldsArray;
@property (nonatomic, strong) NSArray <TMDCommunityUserField*> *standardFieldsArray;
@property (atomic, assign) BOOL sharedHistoricalData;

@property (nonatomic, strong)  UIImage * _Nullable communityIcon;

/// Indicates whether change made manually on the activity have been synced with the cloud
@property NSString *userStatus;

- (instancetype)initWithId:(NSString *)communityId
                      name:(NSString *)name
                     owner:(NSDictionary <NSString*, id> *)owner
          shortDescription:(NSString *)shortDescription
           longDescription:(NSString *)longDescription
                       url:(NSString *)url
                visibility:(NSString *)visibility
        sharedMobilityData:(NSString *)sharedMobilityData
       sharedMobilityModes:(NSString *)sharedMobilityModes
            standardFields:(NSString *)standardFields
              customFields:(NSString *)customFields
      sharedHistoricalData:(BOOL)sharedHistoricalData
              reportedMode:(NSString *)reportedMode
           reportingPeriod:(NSString *)reportingPeriod
                userStatus:(NSString *)userStatus;

- (NSString*)jsonCommunityOwner;
- (TMDCommunityOwner*)communityOwner;
- (TMDCommunityUserStatus)communityUserStatus;
- (TMDCommunityReportedMode)communityReportedMode;
- (TMDCommunityReportingPeriod)communityReportingPeriod;

- (NSArray <NSNumber*> *)sharedMobilityDataArray;
- (NSArray <NSString*> *)sharedMobilityModesArray;

+ (NSString *)iconShapeStringFromValue:(TMDCommunityIconShape)shape;

+ (TMDCommunityMobilityData)mobilityDataFromIntegerValue:(NSInteger)value;

+ (NSArray<TMDCommunity *>*)communitiesfromJsonData:(NSData *)jsonData error:(NSError * _Nullable *)error;
+ (TMDCommunity*)communityFromJsonData:(NSData *)jsonData error:(NSError * _Nullable *)error;
+ (TMDCommunity*)communityFromDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
