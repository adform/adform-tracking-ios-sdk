//
//  AdformTrackingSDK.h
//  AdformTracking
//
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFTrackPoint, AFOrder;

NS_ASSUME_NONNULL_BEGIN
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
 Creates and returns a singleton value.
 
 You should allways use this method to get AdformTrackingSDK instance, dont try to instantiate a new instance with init method.
 
 @return A shared AdformTrackingSDK instance.
 */
+ (AdformTrackingSDK *)sharedInstance;

/**
 Method to request permission to track user.
 When callin this method you must provide a NSUserTrackingUsageDescription in apps Info.plist file.
 */
- (void)requestTrackingPermissions API_AVAILABLE(ios(14.0));

/**
 Begins tracking.

 You should call it right after the application launched in [UIApplicationDelegate application:didFinishLaunchingWithOptions:] method.
 After calling this method SDK automatically tracks application start and/or download.
 If you want to send some custom data, you must set it before calling this method.
 
 @param trackingPointId Tracking point id provided to you by Adform.
 @param waitForPermissions flag to wait for advertisement id usage permission retrieval
 */
- (void)startTracking:(long )trackingPointId
   waitForPermissions:(BOOL)waitForPermissions;

/**
 An optional method used to begin tracking with multiple tracking point ids.
 
 You should call it right after the application launched in [UIApplicationDelegate application:didFinishLaunchingWithOptions:] method.
 After calling this method SDK automatically tracks application start and/or download.
 If you want to send some custom data, you must set it before calling this method.
 
 @param trackingPointIds An array of tracking point ids provided to you by Adform.
 @param waitForPermissions flag to wait for advertisement id usage permission retrieval

 */
- (void)startTrackingWithIds:(NSArray <NSNumber *> *)trackingPointIds waitForPermissions:(BOOL)waitForPermissions;

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
- (void)setAppName:(nullable NSString *)applicationName;

/**
 Adds custom parameters for initial tracking points ("Start" and "Download").
 You can set nil to remove a previously set order.
 */
- (void)setOrder:(nullable AFOrder *)order;

/**
 You can use this method to manually specifying if GDPR is applied.
 Must be a BOOL value wraped in a NSNumber.
 This value is not presisted between app launches, therefore you should set it in application did finish launching method.
 You can pass in null to clear a previouslt set value.
 */
- (void)setGDPR:(nullable NSNumber *)isSubject;

/**
 Returns a currently set is GDPR subject value.

 First SDK tries to retrieve this value from CMP, e.g. checks if `IABConsent_CMPPresent` flag is set to true in `NSUserDefaults`
 and then retrieves and returns a value from `NSUserDefaults` for key `IABConsent_SubjectToGDPR`. If there are no such value in `NSUserDefaults`
 a manually set `isSubjectToGDPR` value is returned (use `setSubjectToGDPR:` method to set this value manually).

 Returns nil if no value was found or set manually.
 */
- (nullable NSNumber *)isSubjectToGDPR;

/**
 You can use this method to manually set the GDPR consent value.
 It should be a base64 encoded string containing vendor and purpose consent.
 This value is not presisted between app launches, therefore you should set it in application did finish launching method.
 You can pass in null to clear a previouslt set value.
 */
- (void)setGDPRConsent:(nullable NSString *)consent;

/**
 Returns a currently set GDPR consent value.

 First SDK tries to retrieve this value from CMP, e.g. checks if `IABConsent_CMPPresent` flag is set to true in `NSUserDefaults`
 and then retrieves and returns a value from `NSUserDefaults` for key `IABConsent_ConsentString`. If there are no such value in `NSUserDefaults`
 a manually set `GDPRConsent` value is returned (use `setGDPRConsent:` method to set this value manually).

 Returns nil if no value was found or set manually.
 */
- (nullable NSString *)GDPRConsent;

/**
 You can use this method to manually set the US Privacy value.
 This value is not presisted between app launches, therefore you should set it in application did finish launching method.
 You can pass in null to clear a previouslt set value.
 */
- (void)setUSPrivacy:(nullable NSString *)value;

/**
 Returns a currently set US Privacy value.

 First SDK tries to retrieve this value from CMP, e.g. checks if `IABUSPrivacy_String` value is set and returns it from `NSUserDefaults`.
 If there are no such value in `NSUserDefaults` a manually set `USPrivacy` value is returned
 (use `setUSPrivacy:` method to set this value manually).

 Returns nil if no value was found or set manually.
 */
- (nullable NSString *)USPrivacy;

/**
 A user agent that is set to all tracking requests. If nil is set, then default user agent is used.

 @param customUserAgent A new custom user agent to set. You may pass nil to cleat old value and use a default user agent.
 */
- (void)setCustomUserAgent:(nullable NSString *)customUserAgent;

/**
 A user agent that is set to all tracking requests. If nil is set, then default user agent is used.

 @return Custom user agent that was set previously.
 */
- (nullable NSString *)customUserAgent;

/// Used to proccess the url that opend the application to handle deep linking and interactions with SDK.
///
/// Must be called in [UIApplicationDelegate application:openURL:options:].
///
/// @param url URL that was passed to [UIApplicationDelegate application:openURL:options:] method.
/// @param options Options dictionary that was passed to [UIApplicationDelegate application:openURL:options:] method.
- (BOOL)applicationOpenURL:(NSURL *)url options:(NSDictionary *)options;

@end

//Deprecated
@interface AdformTrackingSDK ()

/**
 Used to proccess the url that opend the application to handle deep linking and interactions with SDK.

 Must be called in [UIApplicationDelegate application:openURL:sourceApplication:annotation:].

 @param url URL that was passed to [UIApplicationDelegate application:openURL:sourceApplication:annotation:] method.
 @param sourceApplication sourceApplication that was passed in [UIApplicationDelegate application:openURL:sourceApplication:annotation:] method.

 @return YES if the call was intended for AdformTrackingSDK, else NO.
 */
- (BOOL )applicationOpenUrl:(NSURL *)url sourceApplication:(nullable NSString *)sourceApplication __deprecated_msg("Use 'applicationOpenURL:options:' instead!");

@end
NS_ASSUME_NONNULL_END
