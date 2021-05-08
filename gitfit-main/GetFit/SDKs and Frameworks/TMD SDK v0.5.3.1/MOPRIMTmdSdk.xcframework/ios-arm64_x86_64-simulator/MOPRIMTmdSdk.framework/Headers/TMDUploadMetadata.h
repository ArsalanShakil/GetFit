//
//  TMDUploadMetadata.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 26/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A class that summarizes the results of an upload
@interface TMDUploadMetadata : NSObject

/// The upload timestamp of the last upload
@property (assign) long long uploadTimestamp;

/// The end timestamp of last activity that was just uploaded
@property (assign) long long lastTmdActivityTimestamp;

/// The number of TMD sequences that were just uploaded
@property (assign) NSInteger nbTmdSequences;

/// The timestamp of the last location point that was just uploaded
@property (assign) long long lastLocationTimestamp;

/// The number of location data points that were uploaded
@property (assign) NSInteger nbLocations;

/// The number of activity corrections that were uploaded
@property (assign) NSInteger nbCorrections;

/*! @brief Default constructor
 * @param uploadTimestamp               The upload timestamp of the last upload
 * @param lastTmdActivityTimestamp      The end timestamp of last activity that was just uploaded
 * @param nbTmdSequences                The number of TMD sequences that were just uploaded
 * @param lastLocationTimestamp         The timestamp of the last location point that was just uploaded
 * @param nbLocations                   The number of location data points that were uploaded
 * @param nbCorrections                 The number of activity corrections that were uploaded
 */
- (instancetype)initWithUploadTimestamp:(long long)uploadTimestamp
               lastTmdActivityTimestamp:(long long)lastTmdActivityTimestamp
                         nbTmdSequences:(NSInteger)nbTmdSequences
                  lastLocationTimestamp:(long long)lastLocationTimestamp
                            nbLocations:(NSInteger)nbLocations
                          nbCorrections:(NSInteger)nbCorrections;

/*! 
* @param uploadTimestamp               The upload timestamp of the last upload
*/
- (instancetype)initWithUploadTimestamp:(long long)uploadTimestamp;

/// Default constructor when nothing was set
- (instancetype)init;

- (void)addLastTmdActivityTimestamp:(long long)lastTmdActivityTimestamp;
- (void)addLastLocationTimestamp:(long long)lastLocationTimestamp;
- (void)addNbTmdSequences:(NSInteger)nbTmdSequences;
- (void)addNbLocations:(NSInteger)nbLocations;
- (void)addNbCorrections:(NSInteger)nbCorrections;

/// JSON description of the metadata
- (NSString*) description;

@end

NS_ASSUME_NONNULL_END
