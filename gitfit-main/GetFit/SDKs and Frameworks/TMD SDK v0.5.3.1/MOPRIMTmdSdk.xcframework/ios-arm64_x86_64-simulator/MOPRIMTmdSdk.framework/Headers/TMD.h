//
//  TMD.h
//  MOPRIMTmdSdk
//
//  Created by Julien Mineraud on 09/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TMDTask.h"
#import "TMDDelegate.h"
#import "TMDUploadDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/** Use this class to initialize the TMD with initWithKey:withEndpoint: as soon as possible in your AppDelegate's didFinishLaunchingWithOptions method.*/
@interface TMD : NSObject

/** Initialize the Moprim TMD.
 * 
 * The call to this method should be placed as soon as possible in your AppDelegate's didFinishLaunchingWithOptions method.
 * @param key your API key
 * @param endpoint your API endpoint
 * @param launchOptions the launchOptions you get from your AppDelegate's didFinishLaunchingWithOptions method. Pass nil if launchOptions is not available.
 * The launchOptions parameter can be used to wake up the TMD when your app is being launched in the background (for example after a significant location change event).*/
+ (TMDTask *)initWithKey:(NSString *)key withEndpoint:(NSString *)endpoint withLaunchOptions:(NSDictionary* _Nullable)launchOptions;

+ (TMDTask *)initWithKey:(NSString *)key withTmdEndpoint:(NSString *)endpoint withCommunityEndpoint:(NSString * _Nullable)communityEndpoint withLaunchOptions:(NSDictionary* _Nullable)launchOptions;

/// Prevents further calls to the Cloud API. To be called after signing out a user.
+ (void) clearConfig;

/// \returns TRUE if the TMD has been properly initialized
+ (BOOL) isInitialized;

/// \returns TRUE if the TMD service is active and analysing mobility
+ (BOOL) isRunning;

/// \returns TRUE if the TMD service is active, and no mobility has been detected
+ (BOOL) isIdle;

/// \returns TRUE if the TMD service is active (can be in idle or running state)
+ (BOOL) isOn;

/// \returns TRUE if the TMD service is disabled
+ (BOOL) isOff;

/// \returns the time in seconds that the TMD has been recording data
+ (NSTimeInterval) getRunningTime;

/// Get the unique user id associated with this installation
+ (NSString *) getUUID;

/// Set a unique user id to gather data from multiple installations
/// @param uuid the unique user id
+ (void) setUUID:(nullable NSString *)uuid;

/** Resets the credentials used for communications with the cloud, and returns a TMDTask object with a new installation Id.
*
* It is recommended to stop the TMD before calling this method.
* @param key your API key
* @param endpoint your API endpoint */
+ (TMDTask*) resetCredentialsWithKey:(NSString *)key withEndpoint:(NSString *)endpoint;

+ (TMDTask*) resetCredentialsWithKey:(NSString *)key withEndpoint:(NSString *)endpoint withCommunityEndpoint:(NSString * _Nullable)communityEndpoint;

/** Retrieve the unique application installation id of application using the SDK
 * \returns a TMDTask object containing the unique installation id*/
+ (TMDTask<NSString *> *) getInstallationId;

/** Returns a string containing basic information about the last recorded data. Used for user feedback. */
+ (NSString *)getDataInfo;

/** Returns an array of string indicating which sensors are missing. */
+ (NSArray<NSString*>*)checkForMissingSensors;

/** Starts the TMD service
 * The state of the TMD after this call will be On, and either idle or running. */
+ (void) start;

/** Stops the TMD service
 * The state of the TMD after this call will be Off. */
+ (void) stop;


/** Use this methods from your AppDelegate's applicationWillTerminate method in order for the TMD SDK to prepare for the app termination.
*/
+ (void)applicationWillTerminate;

/** Use this methods from your AppDelegate's performFetchWithCompletionHandler method in order for the TMD SDK to update its data regularly in the background.
 *
 * Use the returned value to make a UIBackgroundFetchResult value to pass to the completionHandler.
 * If you have to make your own background fetch as well, it is your responsibility to pass a suitable UIBackgroundFetchResult to the completion handler that would combine your background fetch result with the TMD SDK's background fetch result.
 * \returns a NSNumber containing an integer representing the UIBackgroundFetchResult rawValue */
+ (TMDTask<NSNumber*> *) backgroundFetch;

/** Use this methods from your AppDelegate's handleEventsForBackgroundURLSession method in order for the TMD SDK to update its data regularly in the background.
 *
 * The identifier provided to this method will be used to check if the Background URL Session belongs to the TMD SDK or not. A call to this method will immediately return if the identifier does not belong to the TMD SDK.
 * If your app is already using the AppDelegate's handleEventsForBackgroundURLSession method, you must use the identifier to check if the Background URL Session comes from your code. */
+ (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler;

/// Set an object which adopts the TMDDelegate protocol as a delegate in order to receive events from the TMD.
+ (void) setDelegate:(id<TMDDelegate> _Nullable)delegate;

/// Register a TMDUploadDelegate to be notified when an upload starts or ends.
+ (void)setUploadDelegate:(id<TMDUploadDelegate> _Nullable)delegate;

/// Set to true in order to allow uploads on Mobile Data. By default, uploads on Mobile Data are disabled.
+ (void)setAllowUploadOnCellularNetwork:(bool)allow;

/// Returns true if the TMD framework is allowed to perform uploads on Mobile Data. Returns false if uploads are only allowed on Wifi.
+ (BOOL)isUploadOnCellularNetworkAllowed;

+ (void)logString:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
