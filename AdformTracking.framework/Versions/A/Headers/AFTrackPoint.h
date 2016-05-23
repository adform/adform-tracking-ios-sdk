//
//  TrackPointEntity.h
//  AdformTracking
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFProduct, AFOrder;

@interface AFTrackPoint : NSObject

/**
 Initializes a new instance of TrackPoint with trackingPointId.
 
 @param trackingPointId A tracking point id provided to you by Adform.
 
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
 Returns an array of products assigned to this track point.
 
 @return An array with products or nil if none were set.
 */
- (NSArray *)products;

/**
 Returns an AFOrder object containing additional traking information and custom parameters.
 May be nil if order was not set yet.
 */
- (AFOrder *)order;


// Setters

/**
 Sets custom application name to the track point.
 
 @param applicationName A custom application name to be set to the track point.
 */
- (void)setAppName:(NSString *)applicationName;

/**
 Sets section name to the track point.
 
 @parmater sectionName A string with section name.
 */
- (void)setSectionName:(NSString *)sectionName;

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

/**
 Sets an AFOrder object containing additional traking information and custom parameters.
 You can set nil to remove a previously set order.
 */
- (void)setOrder:(AFOrder *)order;


//Deprecated

/**
 Returns custom parameters set to the tracking point.
 
 @return A dictionary with parameters or nil if none were set.
 */
- (NSDictionary *)getParameters __deprecated_msg("To get custom parameters set to trackpoint use 'order:' instead!");

/**
 Adds a custom parameter to the track point.
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)addParameter:(NSString *)key withValue:(NSString *)parameter __deprecated_msg("To add custom parameters to trackpoint use 'setOrder:' instead!");

/**
 Sets multiple custom parameters to the track point.
 
 @param parameters A dictionary containing parameters.
 */
- (void)setParameters:(NSDictionary *)parameters __deprecated_msg("To add custom parameters to trackpoint use 'setOrder:' instead!");

@end
