//
//  AdformTrackingSDK.h
//  AdformTracking
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TrackPoint;

@interface AdformTrackingSDK : NSObject

@property (nonatomic, assign, readonly, getter=isEnabled) BOOL enabled;

/**
 Creates and returns a singleton value.
 
 You should allways use this method to get AdformTrackingSDK instance, dont try to instantiate a new instance with init method.
 
 @return A shared AdformTrackingSDK instance.
 */
+ (AdformTrackingSDK *)sharedInstance;

/**
 Enables or disables AdformTrackingSDK.
 
 @param enabled You can disable the sdk by passing FALSE or enable with TRUE.
 */
- (void)setEnabled:(BOOL)enabled;

/**
 Use this method to begin tracking.

 You should call it right after the application launched in [UIApplicationDelegate application:didFinishLaunchingWithOptions:] method.
 
 After calling this method SDK automatically tracks application start and/or download.
 
 If you want to send some custom data, you must set it before calling this method. You can do it by using setCustomParameter:withValue:, setCustomParameters: and setAppName: methods.
 
 @param trackingPointId Tracking point id provided to you by Adform.
 */
- (void)startTracking:(NSInteger )trackingPointId;

/**
 Sends custom tracking information to server.
 
 @param trackPoint TrackPoint instance containing custom tracking data.
 */
- (void)sendTrackPoint:(TrackPoint *)trackPoint;

/**
 Adds custom parameter for initial tracking points ("Start" and "Download").
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)addParameter:(NSString *)key withValue:(NSString *)parameter;

/**
 Sets multiple custom parameters for initial tracking points ("Start" and "Download").
 
 @param parameters A dictionary containing parameters.
 */
- (void)setParameters:(NSDictionary *)parameters;

/**
 Sets custom application name for initial tracking points ("Start" and "Download").
 
 @param applicationName A string with custom applicationName.
 */
- (void)setAppName:(NSString *)applicationName;

/**
 Used to proccess the url that opend the application to handle deep linking and interactions with SDK.
 
 Must be called in [UIApplicationDelegate application:openURL:sourceApplication:annotation:].
 
 @param url URL that was passed in [UIApplicationDelegate application:openURL:sourceApplication:annotation:] method.
 @param sourceApplication sourceApplication that was passed in [UIApplicationDelegate application:openURL:sourceApplication:annotation:] method.
 
 @return YES if the call was intended for AdformTrackingSDK, else NO.
 */
- (BOOL )applicationOpenUrl:(NSURL *)url sourceApplication:(NSString *)sourceApplication;



//Deprecated

/**
 Use this method to begin tracking.
 
 You should call it right after the application launched in application:didFinishLaunchingWithOptions: method.
 
 After calling this method SDK automatically tracks application start and/or download.
 
 If you want to send some custom data, you must set it before calling this method. You can do it by using setCustomParameter:withValue:, setCustomParameters: and setAppName: methods.
 
 @param trackingPointId Tracking point id provided to you by Adform.
 */
- (void)startTrackingWithTrackingPointId:(NSString *)trackingPointId __deprecated_msg("Please use startTracking: instead!");

/**
 Sends custom tracking information to server.
 
 @param trackPoint TrackPoint instance containing custom tracking data.
 */
- (void)sendTrackingInformation:(TrackPoint *)trackPoint __deprecated_msg("Please use sendTrackPoint: instead!");

/**
 Sets custom parameter for initial tracking points ("Start" and "Download").
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)setCustomParameterWithKey:(NSString *)key withValue:(NSString *)parameter __deprecated_msg("Please use setCustomParameter:withValue: instead!");

/**
 Sets default application name for initial tracking points ("Start" and "Download").
 
 @param applicationName A string with custom applicationName.
 */
- (void)setDefaultApplicationName:(NSString *)applicationName __deprecated_msg("Please use setAppName: instead!");

@end
