/*
 *  Copyright (c) 2014, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TMDTask;

/*!
 The consumer view of a Task. A TMDTask has methods to
 inspect the state of the task, and to add continuations to
 be run once the task is complete.
 
 TMDTask is based on Bolts Tasks, see https://github.com/BoltsFramework/Bolts-Swift for documentation.
 */
@interface TMDTask<__covariant ResultType> : NSObject

/*!
 A block that can act as a continuation for a task.
 */
typedef __nullable id(^TMDContinuationBlock)(TMDTask<ResultType> *t);

/*!
 Creates a task that is already completed with the given result.
 @param result The result for the task.
 */
+ (instancetype)taskWithResult:(nullable ResultType)result;

/*!
 Creates a task that is already completed with the given error.
 @param error The error for the task.
 */
+ (instancetype)taskWithError:(NSError *)error;

// Properties that will be set on the task once it is completed.

/*!
 The result of a successful task.
 */
@property (nullable, nonatomic, strong, readonly) ResultType result;

/*!
 The error of a failed task.
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/*!
 Whether this task has completed due to an error.
 */
@property (nonatomic, assign, readonly, getter=isFaulted) BOOL faulted;

/*!
 Whether this task has completed.
 */
@property (nonatomic, assign, readonly, getter=isCompleted) BOOL completed;

/*!
 Enqueues the given block to be run once this task is complete.
 This method uses a default execution strategy. The block will be
 run on the thread where the previous task completes, unless the
 the stack depth is too deep, in which case it will be run on a
 dispatch queue with default priority.
 @param block The block to be run once this task is complete.
 @returns A task that will be completed after block has run.
 If block returns a AWSTask, then the task returned from
 this method will not be completed until that task is completed.
 */
- (TMDTask *)continueWithBlock:(TMDContinuationBlock)block NS_SWIFT_NAME(continueWith(block:));

/*!
 Identical to continueWithBlock:, except that the block is only run
 if this task did not produce a cancellation or an error.
 If it did, then the failure will be propagated to the returned
 task.
 @param block The block to be run once this task is complete.
 @returns A task that will be completed after block has run.
 If block returns a AWSTask, then the task returned from
 this method will not be completed until that task is completed.
 */
- (TMDTask *)continueWithSuccessBlock:(TMDContinuationBlock)block NS_SWIFT_NAME(continueOnSuccessWith(block:));

@end

NS_ASSUME_NONNULL_END
