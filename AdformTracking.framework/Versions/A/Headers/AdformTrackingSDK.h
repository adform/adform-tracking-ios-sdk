//
//  AdformTrackingSDK.h
//  AdformTracking
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFTrackPoint, AFOrder;

@interface AdformTrackingSDK : NSObject

/**
 Identifies if Adform Tracking sdk is enabled.
 If it is disabled, no tracking information will collected and sent
 to server.
 */
@property (nonatomic, assign, readonly, getter=isEnabled) BOOL enabled;

/**
 Enables or disables AdformTrackingSDK.
 
 @param enabled You can disable the sdk by passing FALSE or enable with TRUE.
 */
- (void)setEnabled:(BOOL)enabled;

/**
 Identifies is sim card state tracking is enabled.
 
 @important On iPhones running iOS 6 SIM card state may be inacurate. Because
    the device retains SIM card information until it is restarted
    even if the card was removed.
 */
@property (nonatomic, assign, readonly, getter=isSendSimCardStateEnabled) BOOL sendSimCardStateEnabled;

/**
 Enables or disables SIM card state information sending.
 
 If set to true SDK will track if SIM card is inserted to device or not.
 Default value - false.
 
 @important On iPhones running iOS 6 SIM card state may be inacurate. Because
 the device retains SIM card information until it is restarted
 even if the card was removed.
 
 @param enabled If true - enables SIM card state tracking if false - disables it.
 
 */
- (void)setSendSimCardStateEnabled:(BOOL)enabled;

/**
 Identifies if sdk is using HTTPS protocol for network communications.
 */
@property (nonatomic, assign, readonly, getter=isHTTPSEnabled) BOOL HTTPSEnabled;

/**
 Enables or disables HTTPS support.
 
 By default sdk uses HTTPS because that is required by Apple on iOS 9+ platforms.
 It is not recomended, but you can use this method to disable HTTPS.
 */
- (void)setHTTPSEnabled:(BOOL)HTTPSEnabled;

/**
 Identifies if the use of safari view controller to send tracking data to server is enabled.
 
 Default value - false.
 */
@property (nonatomic, assign, readonly, getter=isSafariControllerEnabled) BOOL safariControllerEnabled;

/**
 Enables or disables the use of safari view controller to send tracking data to server.
 
 @param enabled You can enable the use of safari view controller by passing true.
 */
- (void)setSafariControllerEnabled:(BOOL)enabled;



/**
 Creates and returns a singleton value.
 
 You should allways use this method to get AdformTrackingSDK instance, dont try to instantiate a new instance with init method.
 
 @return A shared AdformTrackingSDK instance.
 */
+ (AdformTrackingSDK *)sharedInstance;

/**
 Begins tracking.

 You should call it right after the application launched in [UIApplicationDelegate application:didFinishLaunchingWithOptions:] method.
 After calling this method SDK automatically tracks application start and/or download.
 If you want to send some custom data, you must set it before calling this method.
 
 @param trackingPointId Tracking point id provided to you by Adform.
 */
- (void)startTracking:(long )trackingPointId;

/**
 An optional method used to begin tracking with multiple tracking point ids.
 
 You should call it right after the application launched in [UIApplicationDelegate application:didFinishLaunchingWithOptions:] method.
 After calling this method SDK automatically tracks application start and/or download.
 If you want to send some custom data, you must set it before calling this method.
 
 @param trackingPointIds An array of tracking point ids provided to you by Adform.
 */
- (void)startTrackingWithIds:(NSArray <NSNumber *> *)trackingPointIds;

/**
 Sends custom tracking point to server.
 
 @param trackPoint AFTrackPoint object to send.
 */
- (void)sendTrackPoint:(AFTrackPoint *)trackPoint;

/**
 Sends an array of tracking points to server.
 
 @param trackPoints An array of AFTrackPoint objects to send.
 */
- (void)sendTrackPoints:(NSArray <AFTrackPoint *> *)trackPoints;

/**
 Sets custom application name for initial tracking points ("Start" and "Download").
 
 @param applicationName A string with custom applicationName.
 */
- (void)setAppName:(NSString *)applicationName;

/**
 Adds custom parameters for initial tracking points ("Start" and "Download").
 */
- (void)setOrder:(AFOrder *)order;

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
 Adds custom parameter for initial tracking points ("Start" and "Download").
 
 @param key A key for a parameter.
 @param parameter A parameter for a key.
 */
- (void)addParameter:(NSString *)key withValue:(NSString *)parameter __deprecated_msg("To add custom parameters to trackpoint use 'setOrder:' instead!");

/**
 Sets multiple custom parameters for initial tracking points ("Start" and "Download").
 
 @param parameters A dictionary containing parameters.
 */
- (void)setParameters:(NSDictionary *)parameters __deprecated_msg("To add custom parameters to trackpoint use 'setOrder:' instead!");

@end
