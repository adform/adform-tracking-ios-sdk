//
//  TrackPointEntity.h
//  AdformTracking
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFProduct;

@interface TrackPoint : NSObject

/**
 Initializes a new instance of TrackPoint with trackingPointId.
 
 @parameter trackingPointId A tracking point id provided to you by Adform.
 
 @result A new TrackPoint object instance.
 */
- (id)initTrackPoint:(long )trackingPointId;


// Getters

/**
 Returns a tracking point id which was used to initialize TrackPoint instance.
 
 @return A string containing tracking point id.
 */
- (long )getTrackPointId;

/**
 Returns a section name set to the tracking point.
 
 @return A string with section name or nil if none was set.
 */
- (NSString *)getSectionName;

/**
 Returns a custom application name set to the tracking point.
 
 @return A string with custom application name or nil if none was set.
 */
- (NSString *)getAppName;

/**
 Returns custom parameters set to the tracking point.
 
 @return A dictionary with parameters or nil if none were set.
 */
- (NSDictionary *)getParameters;

/**
 Returns an array of products assigned to this track point.
 
 @return An array with products or nil if none were set.
 */
- (NSArray *)products;


// Setters

/**
 Sets custom application name to the track point.
 
 @parameter applicationName A custom application name to be set to the track point.
 */
- (void)setAppName:(NSString *)applicationName;

/**
 Sets section name to the track point.
 
 @parmater sectionName A string with section name.
 */
- (void)setSectionName:(NSString *)sectionName;

/**
 Adds a custom parameter to the track point.
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)addParameter:(NSString *)key withValue:(NSString *)parameter;

/**
 Sets multiple custom parameters to the track point.
 
 @param parameters A dictionary containing parameters.
 */
- (void)setParameters:(NSDictionary *)parameters;

/**
 Sets an array of products to track point.
 
 This method overrides any products already set and they will be removed.
 
 @param products An array of products to set.
 */
- (void)setProducts:(NSArray *)products;

/**
 Assigns a single product to track point.
 
 This method doesn't remove previously added products.
 
 @param product A product that should be associated to the track point.
 */
- (void)addProduct:(AFProduct *)product;


//Deprecated

/**
 Initializes a new instance of TrackPoint with trackingPointId.
 
 @parameter trackingPointId A tracking point id provided to you by Adform.
 
 @result A new TrackPoint object instance.
 */
- (id)initWithTrackingPointId:(NSString *)trackingPointId __deprecated_msg("Please use initTrackPoint: instead!");

/**
 Returns a tracking point id which was used to initialize TrackPoint instance.
 
 @return A string containing tracking point id.
 */
- (NSString *)getTrackingPointId __deprecated_msg("Please use getTrackPointId: instead!");

/**
 Returns a custom application name set to the tracking point.
 
 @return A string with custom application name or nil if none was set.
 */
- (NSString *)getApplicationName __deprecated_msg("Please use getAppName: instead!");

/**
 Sets custom application name to the track point.
 
 @parameter applicationName A custom application name to be set to the track point.
 */
- (void)setDefaultApplicationName:(NSString *)applicationName __deprecated_msg("Please use setAppName: instead!");

/**
 Sets custom parameter for the track point.
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)setCustomParameterWithKey:(NSString *)key withValue:(NSString *)parameter __deprecated_msg("Please use setParameter:withValue: instead!");

/**
 Sets multiple custom parameters to the track point.
 
 @param parameters A dictionary containing parameters.
 */
- (void)setCustomParameters:(NSDictionary *)parametersDictionary  __deprecated_msg("Please use setParameters: instead!");

@end
