//
//  TMDCommunityCard.h
//  Demo
//
//  Created by Kyrill Cousson on 17/07/2020.
//  Copyright © 2020 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TMDCommunity.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TMDCommunityCardSize) {
    TMDCommunityCardSizeSmall,
    TMDCommunityCardSizeMedium,
    TMDCommunityCardSizeTall
};

@interface TMDCommunityCard : NSObject

@property (nonatomic, strong)   NSString *cardIdentifier;
@property (nonatomic, strong)   NSString *cardType;
@property (nonatomic, strong)   NSString *cardLocation;
@property (nonatomic, strong)   NSString *communityIdentifier;
@property (atomic, assign)      long long last_updated;
@property (atomic, assign)      TMDCommunityCardSize cardSize;
@property (nonatomic, strong)   NSString* cardSizeType;
@property (nonatomic, strong)   NSDictionary <NSString*, id> *cardParameters;

- (instancetype)initWithIdentifier:(NSString *)cardIdentifier
                          cardType:(NSString*)cardType
                      cardLocation:(NSString*)cardLocation
               communityIdentifier:(NSString*)communityIdentifier
                          cardSize:(NSString*)cardSizeType
                        parameters:(NSDictionary*)parameters
                      last_updated:(long long)last_updated;

+ (TMDCommunityCard*)communityCardFromDictionary:(NSDictionary *)dictionary;
+ (NSArray <TMDCommunityCard*> *)communityCardsFromArray:(NSArray*)array;

- (NSString*)jsonCardParameters;

+ (TMDCommunityCard*)testLeaderboardCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testModalityStatsCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testMultiModalityStatsCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testMonetaryCompensationCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testMonetaryCompensationCardNoTargetWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testTextCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testTextButtonCardWithCommunityIdentifier:(NSString *)communityIdentifier;
+ (TMDCommunityCard*)testTallTextCardWithCommunityIdentifier:(NSString *)communityIdentifier;

- (BOOL)hasSameDataThanOtherCommunityCard:(TMDCommunityCard*)communityCard;

@end

NS_ASSUME_NONNULL_END
