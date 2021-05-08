//
//  TMDUploadCallback.h
//  Demo
//
//  Created by Julien Mineraud on 22/11/2018.
//  Copyright © 2018 Julien Mineraud. All rights reserved.
//
#import <Foundation/Foundation.h>

/// Use the TMDDelegate to be notified of success or failure after starting or stopping the TMD.
@protocol TMDDelegate <NSObject>

@optional

/// Indicates that the TMD service started without errors (it started actively monitoring user motion)
- (void)didStart;

/// Indicates that the TMD service could not start because of an error
- (void)didNotStartWithError:(NSError *)error;

/// Indicates that the TMD service stopped without errors (it stopped monitoring user motion)
- (void)didStop;

/// Indicates that the TMD service stopped with an error (it stopped monitoring user motion)
- (void)didStopWithError:(NSError *)error;

/// Indicates that the TMD service started analysing data (because the user started moving)
- (void)didStartAnalysing;

/// Indicates that the TMD stopped analysing data (because the user stopped moving)
- (void)didStopAnalysing;

@end
