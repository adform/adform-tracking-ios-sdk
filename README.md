# Getting Started

When you run mobile campaigns, boost of new app installs are often one of the main goals. Our easy to install Tracking SDK will enable campaign app installs tracking and reporting in Adform platform without need to deal with 3rd party SDKs and invest tons of time into that.

***If you have any issues or suggestions please contact mobile-sdk@adform.com***

## ***iOS 15 support***

You can check out the new Adform Tracking SDK version that supports iOS 15 in `ios_15` branch.

## ***Important iOS 14 support***

Apple introduced a new AppTrackingTransparency framework and tracking permission in iOS 14. To support these changes you will need to make couple of small changes in Adform Tracking SDK integration. For more information check [Migration Guide](https://github.com/adform/adform-tracking-ios-sdk#upgrading-to-170) down bellow.

## 1. General Info

The use of Adform Tracking SDK requires the following:

* Xcode 9.0 or later.
* Requires deployment target 9.0 or later.
* Requires ARC to be enabled. 

[**Please folow Migration guide below if you are updating SDK to version 1.0.**](https://github.com/adform/adform-tracking-ios-sdk#upgrading-to-10)

### 1.1. Plugins

Tracking SDK is also available on these platforms:

* ***[Unity](https://github.com/adform/adform-tracking-sdk-unity-plugin)***
* ***[Xamarin](https://github.com/adform/adform-tracking-sdk-xamarin/wiki/xamarin-ios-integration-guide)*** 

## 2. Integration

### 2.1. Using Swift Package Manager

The [Swift Package Manager](https://swift.org/package-manager/) is a tool for managing the distribution of Swift code. It’s integrated with the Swift build system to automate the process of downloading, compiling, and linking dependencies.

You can add Adform Tracking SDK as a dependency to your project through Xcode UI or add it to your project's `Package.swift` file like this:

```swift
dependencies: [
    .package(url: "https://github.com/adform/adform-tracking-ios-sdk", .upToNextMajor(from: "1.7.4"))
]
```


**Important!** Xcode 12 has a bug where static frameworks distributed through SPM sometimes get embedded incorrectly into the app. This issue is mentioned in [Xcode 12.4 release notes](https://developer.apple.com/documentation/xcode-release-notes/xcode-12_4-release-notes). If the validation of your archived app fails you may need to use a workaround that strips the embedded frameworks after the build. You can use this build phase script to remove embedded frameworks from the app:

```
APP_PATH="${TARGET_BUILD_DIR}/${WRAPPER_NAME}"

rm -rf "${APP_PATH}/Frameworks/AdformTracking.framework"
rm -rf "${APP_PATH}/Frameworks/ProtocolBuffers.framework"
rm -rf "${APP_PATH}/Plugins/AdformTracking.framework"
rm -rf "${APP_PATH}/Plugins/ProtocolBuffers.framework"
```

### 2.2. Using CocoaPods

Adform Tracking SDK is available via [CocoaPods](https://cocoapods.org/). To integrate SDK using CocoaPods, you need to edit `Podfile` and specify the `AdformTracking` pod.

```
pod 'AdformTracking', '~> 1.7.4'
```

For more information about CocoaPods visit [CocoaPods site](http://cocoapods.org/about).

### 2.3. Using Carthage

Adform Tracking SDK is available via Carthage. 

* To integrate SDK using Carthage, you need to specify it in `Cartfile`.

```
github "adform/adform-tracking-ios-sdk"
```

* Adform Tracking SDK uses Protocol Buffers - Google's data interchange format.
Therefore you need to import Protobuf library to your project too.

```
github "adform/protobuf-ios"
```

* Our SDK and Protocol Buffers library are distributed as static frameworks. Therefore, you should not add them to input/output files in Carthage copy-frameworks Build Phase.

For more information about Carthage visit [Carthage site](https://github.com/Carthage/Carthage).

### 2.4. Manual

* Download latest build version of Adform Tracking SDK.
* Drag **AdformTracking.framework** to your project.

![alt tag](Screenshots/drag_and_drop.png)

* When asked select **Copy items into destination group's folder**.

![alt tag](Screenshots/copy.png)

* Then select **AdformTracking.xcframework** in project navigator, go to file inspector and add it to your applications target (Target Membership).

* Adform Tracking SDK uses Protocol Buffers - Google's data interchange format. 
Therefore you need to import Protobuf library to your project. You can use it either directly from [Google source code](https://github.com/google/protobuf/tree/master/objectivec) or integrate our [framework build](https://github.com/adform/protobuf-ios). 

### 2.4. Troubleshooting

* If you get a `missing symbols error`, it may mean that automatic framework linking has failed, in this case try to add `AdSupprt.framework` dependency explicitly in you project.

* If you get a `bundle format unrecognized, invalid, or unsuitable` error while integrating the SDK, it probably means one of two problems:

  - That you are integrating SDK with Carthge and have added AdformTracking.framework and ProtocolBuffers.framework to input/output files in Carthage copy-frameworks Build Phase. You should not add these frameworks to copy-frameworks Build Phase.
  - You have selected `Embed` in Framework and Libraries project configuration. This configuration should be selected to `Do Not Embed`.

## 3. Basic Adform Tracking SDK implementation

* Import `AdformTracking` in `AppDelegate.h`

* In `application:didFinishLaunchingWithOptions:` method call `startTracking:waitForPermissions:` method with your Client Tracking ID and `waitForPermissions` `true`. This method should be called only one time, when app starts.

#### Swift

```swift
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
    AdformTrackingSDK.sharedInstance().startTracking(yourTrackingId, waitForPermissions: true)
        
    return true
}
```

<details>
  <summary>Objective-C</summary>
	
```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [[AdformTrackingSDK sharedInstance] startTracking:yourTrackingId waitForPermissions:true];
	
    return YES;
}
```
	
</details>

* Then call `requestTrackingPermissions` to get user permission to use Advertising Identifier for tracking. Calling this method will present systemic permission alert. Therefore, it is up to you to decide when it is best to show this alert. 

#### Swift

```swift
if #available(iOS 14.0, *) {
     AdformTrackingSDK.sharedInstance().requestTrackingPermissions()
}
```

<details>
  <summary>Objective-C</summary>

```objc
if (@available(iOS 14.0, *)) {
     [[AdformTrackingSDK sharedInstance] requestTrackingPermissions];
}
```

</details>

* Add `NSUserTrackingUsageDescription` entry to your apps `Info.plist` file. 


Thats it! You are ready to go. Now in Adform system will see default tracking points (Download, Start, Update), when they are triggered.

* Optionally, if you don't want to use Advertising Identifier for tracking, you may not ask user for permissions. In this case you must pass `false` to  `waitForPermissions` when calling `startTracking:waitForPermissions:`.  

#### Swift

```swift
func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
    AdformTrackingSDK.sharedInstance().startTracking(yourTrackingId, waitForPermissions: true)
        
    return true
}
```

<details>
  <summary>Objective-C</summary>

```objc
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
   
    [[AdformTrackingSDK sharedInstance] startTracking:yourTrackingId waitForPermissions:false];
	
    return YES;
}
```

</details>

* Optionally you can set custom application name and custom variables before calling `startTracking:`.

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setAppName("CustomApplicationName")

let order = AFOrder()
order.firstName = "Fist name"
order.lastName = "Last name"
        
// You also can set other custom variables.
order.setCustomVariable("var1", forKey: 1)
order.setSystemVariable("sysVar1", forKey: 1)
order.setNumericSystemVariable(123.45, forKey: 1)
        
AdformTrackingSDK.sharedInstance().setOrder(order)
AdformTrackingSDK.sharedInstance().startTracking(yourTrackingId, waitForPermissions: true)
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] setAppName:@"CustomApplicationName"];

AFOrder *order = [AFOrder new];
order.firstName = @"First Name";
order.lastName = @"Last Name";

// You also can set other custom variables.
[order setCustomVariable:@"var1" forKey:1];
[order setSystemVariable:@"sysVar1" forKey:1];
[order setNumericSystemVariable:@(123.45) forKey:1];

[[AdformTrackingSDK sharedInstance] setOrder:order];
[[AdformTrackingSDK sharedInstance] startTracking:yourTrackingId waitForPermissions:false];
```

</details>

## 4. Custom Adform Tracking SDK implementations

* For sending custom tracking events manually you need to import `AdformTracking` in any class you want to send events from, in provided example we use `ViewController.h`.

* Create an `AFTrackPoint` instance with your client `Tracking_ID`. After that you can set tracking point name, custom variables and finally send the tracking point. 

* When defining variables' it's required to keep in mind, that there are different type of variables:
	* Custom variables with predefined names (orderid, currency, firstname, etc.)
	* Custom variables (var1-var10)
	* System variables (sv1-sv89)
	* Numeric system variables (svn1, svn2)

* Create a `AFTrackPoint` instance with your track point id, set custom application name, custom parameters, a.k.a. order, and send the track point.

#### Swift

```swift
let trackPoint = AFTrackPoint(trackPoint: yourTrackingId)
trackPoint.setSectionName("Custom Tracking Point Name")
        
let order = AFOrder()
order.orderId = "Order ID"
order.sale = 1234
order.currency = "Eur"
order.orderStatus = "Sold"
order.firstName = "First Name"
order.lastName = "Last Name"
order.country = "Country"
order.address1 = "Address 1"
order.address2 = "Address 2"
order.zip = "ZIP code"
order.email = "E-mail"
order.phone = "Phone"
order.gender = "Gender"
order.ageGroup = "Age group"
order.basketSize = 12
        
// You also can set other custom variables.
order.setCustomVariable("var1", forKey: 1) // key defines variable index, e.g. forKey:3 means Var3
order.setSystemVariable("sysVar1", forKey: 1) // key defines variable index, e.g. forKey:3 means Sv3
order.setNumericSystemVariable(123.45, forKey: 1) // key defines variable index, e.g. forKey:2 means Svn2; Only numeric values allowed

trackPoint.setOrder(order)
        
AdformTrackingSDK.sharedInstance().send(trackPoint)
```

<details>
  <summary>Objective-C</summary>

```objc
AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:yourTrackingId];
[trackPoint setSectionName:@"CCustom Tracking Point Name"];

AFOrder *order = [AFOrder new];
order.orderId = @"Order ID";
order.sale = 1234; //numeric format
order.currency = @"Eur";
order.orderStatus = @"Sold";
order.firstName = @"First Name";
order.lastName = @"Last Name";
order.country = @"Country";
order.address1 = @"Address 1";
order.address2 = @"Address 2";
order.zip = @"ZIP code";
order.email = @"E-mail";
order.phone = @"Phone";
order.gender = @"Gender";
order.ageGroup = @"Age group";
order.basketSize = 12; //numeric format

// You can also set other custom variables.
[order setCustomVariable:@"Var1 value" forKey:1]; // forKey defines variable index, e.g. forKey:3 means Var3
[order setSystemVariable:@"Sv1 value" forKey:1]; // forKey defines variable index, e.g. forKey:3 means Sv3
[order setNumericSystemVariable:@(123.45) forKey:1]; // forKey defines variable index, e.g. forKey:2 means Svn2; Only numeric values allowed

[trackPoint setOrder:order];

[[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
```

</details>


To logicaly group tracking points you can set separate app names for each custom tracking point. This would allow to use app name together with custom section name.

#### Swift

```swift
let trackPoint = AFTrackPoint(trackPoint: yourTrackingId)
        
trackPoint.setSectionName("Custom Tracking Point Name")
trackPoint.setAppName("Custom_app_name-Section_name")
        
AdformTrackingSDK.sharedInstance().send(trackPoint)
```

<details>
  <summary>Objective-C</summary>

```objc
AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:yourTrackingId];
    
[trackPoint setSectionName:@"Custom Tracking Point Name"];
[trackPoint setAppName:@"Custom_app_name-Section_name"];
    
[[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
```

</details>

## 5. Product variables

Also it is posible to send additional product variables information with tracking points. To do so you have two options, first use `addProduct:` method and add products to the trackpoint one at a time, second use `setProducts:` method and set an array of products. Either way you must set `AFProduct` objects.

#### Swift

```swift
let trackPoint = AFTrackPoint(trackPoint: yourTrackingId)
trackPoint.setSectionName("Custom Application Name")
        
let product = AFProduct(
    categoryName: "Product category name",
    categoryId: "Product category id",
    productName: "Product name",
    productId: "Product id",
    weight: 10,
    step: 1,
    productSales: 12.58,
    productCount: 2,
    custom: "Custom product information"
)
trackPoint.addProduct(product)
        
AdformTrackingSDK.sharedInstance().send(trackPoint)
```

<details>
  <summary>Objective-C</summary>

```objc
AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:yourTrackingId];
[trackPoint setSectionName:@"Custom Tracking Point Name"];
    
AFProduct *product = [[AFProduct alloc] initWithCategoryName:@"Product category name"
                                                  categoryId:@"Product category id"
                                                 productName:@"Product name"
                                                   productId:@"Product id"
                                                      weight:10
                                                        step:1
                                                productSales:12.58
                                                productCount:2
                                                      custom:@"Custom product information"];
 [trackPoint addProduct:product];
    
 [[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
``` 

</details>

Also for same tracking point you can list more than one product variables list:

#### Swift

```swift
let trackPoint = AFTrackPoint(trackPoint: yourTrackingId)
trackPoint.setSectionName("Custom Application Name")
        
let product1 = AFProduct(
    categoryName: "Product category name",
    categoryId: "Product category id",
    productName: "Product name",
    productId: "Product id",
    weight: 10,
    step: 1,
    productSales: 12.58,
    productCount: 2,
    custom: "Custom product information"
)

let product2 = AFProduct(
    categoryName: "Product category name",
    categoryId: "Product category id",
    productName: "Product name",
    productId: "Product id",
    weight: 10,
    step: 1,
    productSales: 12.58,
    productCount: 2,
    custom: "Custom product information"
)
trackPoint.setProducts([product1, product2])
        
AdformTrackingSDK.sharedInstance().send(trackPoint)
```

<details>
  <summary>Objective-C</summary>

```objc
AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:yourTrackingId];
[trackPoint setSectionName:@"Custom Tracking Point Name"];
    
AFProduct *product1 = [[AFProduct alloc] initWithCategoryName:@"Product category name"
                                                   categoryId:@"Product category id"
                                                  productName:@"Product name"
                                                    productId:@"Product id"
                                                       weight:10
                                                         step:1
                                                 productSales:12.58
                                                 productCount:2
                                                       custom:@"Custom product information"];
                                                          
AFProduct *product2 = [[AFProduct alloc] initWithCategoryName:@"Product category name"
                                                   categoryId:@"Product category id"
                                                  productName:@"Product name"
                                                    productId:@"Product id"
                                                       weight:10
                                                         step:1
                                                 productSales:12.58
                                                 productCount:2
                                                       custom:@"Custom product information"];
[trackPoint setProducts:@[product1, product2]];

[[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
``` 

</details>

If you want to send only part of available product data, you can avoid using big init method by setting those properties manually after creating an object with default initializer.

#### Swift

```swift
let trackPoint = AFTrackPoint(trackPoint: yourTrackingId)
        
let product = AFProduct()
product.productName = "My Product Name"
trackPoint.addProduct(product)
        
AdformTrackingSDK.sharedInstance().send(trackPoint)
```

<details>
  <summary>Objective-C</summary>


```objc
AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:Tracking_ID];

AFProduct *product = [AFProduct new];
product.productName = @"My Product Name";
[trackPoint addProduct:product];
    
[[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
```

</details>

## 6. Sending information to multiple clients

It is possible to send tracking information to multiple clients by defining each client's Tracking id.

In order to start tracking, please use an example below:

#### Swift

```swift
AdformTrackingSDK.sharedInstance()
    .startTracking(
        withIds: [yourTrackingId1, yourTrackingId2, yourTrackingId3],
        waitForPermissions: true
    )
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] startTrackingWithIds:@[yourTrackingId1, yourTrackingId2, yourTrackingId3] waitForPermissions:true];
```

</details>

To send custom tracking points for multiple clients, you should use `AFTrackPointsBuilder` class. It helps you create multiple trackpoints with same information, but differrent tracking id.Example bellow ilustrates how to do so:

#### Swift

```swift
let trackPointBuilder = AFTrackPointsBuilder()
        
// You must set at least these properties:
trackPointBuilder.trackPointIds = [yourTrackingId1, yourTrackingId2, yourTrackingId3]
trackPointBuilder.sectionName = "Custom trackpoint"
        
// Additionally you can set more information to track.
trackPointBuilder.applicationName = "Custom application name"
trackPointBuilder.order = yourOrder;
            
// Create trackpoints
let trackingPoints = trackPointBuilder.build()
            
// Send trackpoints.
AdformTrackingSDK.sharedInstance().send(trackingPoints)
```

<details>
  <summary>Objective-C</summary>

```objc
AFTrackPointsBuilder *trackPointBuilder = [[AFTrackPointsBuilder alloc] init];
    
// You must set at least these properties:
trackPointBuilder.trackPointIds = @[yourTrackingId1, yourTrackingId2, yourTrackingId3];
trackPointBuilder.sectionName = @"Custom trackpoint";
    
// Additionally you can set more information to track.
trackPointBuilder.applicationName = @"Custom application name";
trackPointBuilder.order = yourOrder;
    
// Create trackpoints
NSArray *trackPoints = [trackPointBuilder build];
    
// Send trackpoints.
[[AdformTrackingSDK sharedInstance] sendTrackPoints:trackPoints];
```

</details>

## 7. Limit tracking

You can disable the Adform Tracking SDK from tracking any events by calling `setEnabled:` with parameter `NO`. This setting is remembered between application launches. By default tracking is enabled.

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setEnabled(false)
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] setEnabled:NO];
``` 

</details>

You can check if tracking is enabled by calling `isEnabled` method.

## 8. Deeplink tracking

Adform Tracking SDK uses deep-link tracking to attribute part of Facebook events. You should implement it if you are going to use our SDK for Facebook tracking.

The implementation is very simple, you just have to call `AdformTrackingSDK` method `applicationOpenUrl:sourceApplication:` in your `AppDelegate` class's method `application:openURL:sourceApplication:annotation:` and pass url and sourceApplication parameters.

#### Swift

```swift
func application(_ app: UIApplication, open url: URL, options: [UIApplication.OpenURLOptionsKey : Any] = [:]) -> Bool {
    return AdformTrackingSDK.sharedInstance().applicationOpen(url, options: options)
}
```

<details>
  <summary>Objective-C</summary>

```objc
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    return [[AdformTrackingSDK sharedInstance] applicationOpenURL:url options:options];
}
```

</details>

## 9. SIM card state tracking

Adform Tracking SDK allows you to track user device SIM card state. This feature allows you to see if a user device has a SIM card inserted into it. 

This feature is turned off by default, therefore if you want to use it, you need to enable it. To do so you just need to use the `setSendSimCardStateEnabled:` method.

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setSendSimCardStateEnabled(true)
AdformTrackingSDK.sharedInstance().startTracking(yourTrackingId, waitForPermissions: true)
```

<details>
  <summary>Objective-C</summary>

````objc
[[AdformTrackingSDK sharedInstance] setSendSimCardStateEnabled:true];
[[AdformTrackingSDK sharedInstance] startTracking:yourTrackingId waitForPermissions:true];
````

</details>

## 10. Security

By default AdformTracking sdk uses HTTPS protocol for network comunnications, but there is a possibility to disable it and use an insecure HTTP protocol. Example below shows you how to do it.

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setHTTPSEnabled(false)
```

<details>
  <summary>Objective-C</summary>

```objc
AdformTrackingSDK sharedInstance] setHTTPSEnabled:false];
```

</details>

## 11. GDPR

By default Adform Tracking SDK will check CMP settings and use that information. More information about this [here](https://github.com/InteractiveAdvertisingBureau/GDPR-Transparency-and-Consent-Framework/blob/master/Mobile%20In-App%20Consent%20APIs%20v1.0%20Final.md)

It is possible to set GDPR and GDPR consent manually. You need to use `setGdpr:` and `setGDPRConsent:` methods. For GDPR consent you need to set base64-encoded string.

Example:

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setGDPR(true)
	
let encodedGDPRConsent = "GgdprConsent".data(using: .utf8)?.base64EncodedString()
AdformTrackingSDK.sharedInstance().setGDPRConsent(encodedGDPRConsent)
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] setGDPR:@(true)];

NSString *encodedGDPRConsent = [[@"GgdprConsent" dataUsingEncoding:NSUTF8StringEncoding] base64EncodedStringWithOptions:0];
[[AdformTrackingSDK sharedInstance] setGDPRConsent:encodedGDPRConsent];
```

</details>

## 12. US Privacy

By default Adform Tracking SDK will check CMP settings to get US Privacy value. More information about this can be found here:

* [IAB Tech Lab U.S. Privacy String](https://github.com/InteractiveAdvertisingBureau/USPrivacy/blob/master/CCPA/US%20Privacy%20String.md)

* [IAB Tech Lab U.S. Privacy User Signal API](https://github.com/InteractiveAdvertisingBureau/USPrivacy/blob/master/CCPA/USP%20API.md)

It is also possible to set US Privacy value manually. You can do this using  `setUSPrivacy:` method.

Example:

#### Swift

```swift
let usPrivacy = "US_PRIVACY"
AdformTrackingSDK.sharedInstance().setUSPrivacy(usPrivacy)
```

<details>
  <summary>Objective-C</summary>

```objc
NSString *usPrivacy = @"US_PRIVACY";
[[AdformTrackingSDK sharedInstance] setUSPrivacy:usPrivacy];
```

</details>

## 13. Custom user-agent

Adform Tracking SDK uses web view user-agent as one of the parameters to identify users and perform attribution. In some cases an issue may arise if you are firing some tracking points in your own web view, e.g. you are developing a hibrid application. In these cases attribution may not work because user-agent of your own web view and default web view user-agent used by our SDK may not match. To solve this issue Adform Tracking SDK provides a method to set a custom user agent.

Example:

#### Swift

```swift
AdformTrackingSDK.sharedInstance().setCustomUserAgent("YOUR CUSTOM USER AGENT")
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] setCustomUserAgent:@"YOUR CUSTOM USER AGENT"];
```

</details>

## 14. Debug mode

You can enable debug mode by providing `AFTDebugModeEnabled` launch argument. When debug mode is enabled SDK will print additional logs to the console. This may be usefull during development while integrating Adform Tracking SDK into your application. 

# Migration guide

## Upgrading to 1.0

In SDK version 1.0 was added functionality, which requires additional changes during update from older versions:
* If you are integrating SDK manually you need to add additional `SafariServices` framework dependency to your project.
* Also if you are integrating SDK manually you need to import Google Protobuf library to your project. 
Instructions on how to do it can be found [here](https://github.com/google/protobuf/tree/master/objectivec#building).
* `TrackPoint` class have been renamed to `AFTrackPoint`.
* `getParameters`, `addParameter:withValue:` and `setParameters:` methods of `AFTrackPoint` and `AdformAdvertisingSDK` classes have been deprecated. Instead of them to set custom variables to tracking points you should use `setOrder:` method and `AFOrder` class.

## Upgrading to 1.2.0

`SafariServices` framework dependency is no longer needed by the SDK.

## Upgrading to 1.7.0

In iOS 14 we need to ask user for permission to use Advertising Identifier for tracking purposes. To do so, you will need to make these changes to SDK integration:

1. Pass in `true` as `waitForPermissions` parameter to `startTracking` method.

#### Swift

```swift
AdformTrackingSDK.sharedInstance().startTracking(withIds: yourTrackingId, waitForPermissions: true)
```

<details>
  <summary>Objective-C</summary>

```objc
[[AdformTrackingSDK sharedInstance] startTracking:yourTrackingId waitForPermissions:true];
```

</details>

2. Ask user for permission to access Advertising Identifier using `requestTrackingPermissions` method. Calling this method will present a systemic permissions alert, therefore it's up to you to decide when it is most apropriate to show it. 

#### Swift

```swift
if #available(iOS 14.0, *) {
    AdformTrackingSDK.sharedInstance().requestTrackingPermissions()
}
```

<details>
  <summary>Objective-C</summary>

```objc
if (@available(iOS 14.0, *)) {
    [[AdformTrackingSDK sharedInstance] requestTrackingPermissions];
}
```

</details>

3. Add `NSUserTrackingUsageDescription` entry to your apps `Info.plist` file. 


# Release notes

## 1.7.4

### New Features

* Adds debug mode, that can be enabled with `AFTDebugModeEnabled` launch argument. When debug mode is enabled SDK will print additional debug logs into the console.

## 1.7.3

### Bug fixes

* Fix Swift Package Manager dependencies

## 1.7.2

### New Features

* Add Swift Package Manager support.

## 1.7.1

### New Features

* Change framework format to .xcframework.

### Notice

* No carthage support for this version. Carthage doesn't support .xcframework type yet. Use 1.7.0 version if you need carthage support.

## 1.7.0

### New Features

* Add iOS 14, AppTrackingTransparency support.

### Notice

* No cocoapods support for this version. Cocoapods require .xcframework type to work with iOS 14, therefore use 1.7.1 version.

## 1.6.0

### New Features

* IAB CCPA Compliance Framework support.
* Update Framework structure.

## 1.5.1

### Bug fixes

* Fix web view multithreading issue.

## 1.5.0

### New Features

* Migrate UIWebView usage to WKWebView.

## 1.4.0

### New Features

* IAB Transparent Consent Framework 2.0 support.

## 1.3.3

### New Features

* Ad support for Carthage.

## 1.3.2

### New Features

* Added ability to set custom user-agent.

## 1.3.1

### Bug fixes

* Fixed database initialization error issues that affected some users;

## 1.3.0

### New Features

* Added GDPR support. More info in GDPR section.

## 1.2.0

### New Features

* Removed usage of SFSafariViewController.

## 1.1.5

### New Features

* Now SDK uses newest version of Protobuf library.

## 1.1.4

### Bug fixes

* Fixed issue when UIWebView was called from background thread;

## 1.1.3

### Bug fixes

* Fixed a typo;

## 1.1.2

### New Features

* iOS 10 support;

## 1.1.1

### New Features

* Now SDK uses Protocol Buffers v3.0.0-beta-3.1 library;

## 1.1

### New Features

* Add basket size parameter to order;

## 1.0

### New Features

* Improved app installs attribution;
* Multiple trackpoint support;

### Bug Fixes

* Minor bug fixes;


