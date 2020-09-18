//
//  AFTrackPointBuilder.h
//  AdformTracking
//
//  Created by Vladas Drejeris on 12/04/16.
//  Copyright © 2016 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFProduct, AFOrder, AFTrackPoint;

NS_ASSUME_NONNULL_BEGIN
/**
 Track points builder used to simplify trackpoint creation for multiple tracking point ids.
 
 This builder constructs an array of track points with identical data for each track point id passed to it.
 */
@interface AFTrackPointsBuilder : NSObject

/**
 An array of tracking point ids wrapped in NSNumber objects.
 */
@property (nonatomic, strong) NSArray <NSNumber *> *trackPointIds;
/**
 Custom application name used to construct track points.
 */
@property (nonatomic, strong, nullable) NSString *applicationName;
/**
 Section name used to construct track points.
 */
@property (nonatomic, strong, nullable) NSString *sectionName;
/**
 An array of products used to construct track points.
 */
@property (nonatomic, strong, nullable) NSArray <AFProduct *> *products;
/**
 AFOrder object containing additional traking information and custom parameters used to construct track points.
 */
@property (nonatomic, strong, nullable) AFOrder *order;

/**
 Initializes a new AFTrackPointsBuilder instance with provided parameters.
 
 @param appName Custom application name.
 @param sectionName Section name.
 @param products An array of products.
 @param order AFOrder object containing additional traking information and custom parameters.
 @param trackpointIds An array of tracking point ids.
 */
- (instancetype)initWithAppName:(nullable NSString *)appName
                    sectionName:(nullable NSString *)sectionName
                       products:(nullable NSArray <AFProduct *> *)products
                          order:(nullable AFOrder *)order
                  trackPointIds:(NSArray <NSNumber *> *)trackpointIds;

/**
 Builds an array of trackpoints for provided parameters.
 
 @return An array of constructed track points.
 */
- (NSArray <AFTrackPoint *> *)build;

@end
NS_ASSUME_NONNULL_END
