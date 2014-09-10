# Getting Started

When you run mobile campaigns, boost of new app installs are often one of the main goals. We are happy to announce that today we are launching app installs solution for iOS and Android devices. Easy to install SDK will enable campaign app installs tracking and reporting in Adform platform without need to deal with 3rd party SDKs and invest tons of time into that.

## 1. General Info

The use of Adform Tracking SDK requires the following:

* Xcode 5.0 or later.
* iOS SDK 7.0 or later.
* Requires deployment target 6.0 or later

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_01.png)

## 2. Drag Adform Tracking SDK folder to your project.

* Download latest build version of Adform Tracking SDK.
* Drag Adform Tracking SDK folder to your project, when asked select **Copy items into destination group's folder**.

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_02.png)

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_03.png)

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_04.png)

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_05.png)

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_06.png)

````
#import "AdformTrackingSDK.h"
````

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_07.png)

````
[[AdformTrackingSDK sharedInstance] startTrackingWithTrackingPointId:@"123456"];
````

Thats it! You are ready to go.

## 5. Custom Adform Tracking SDK implementations

* Sending tracking events manualy

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_08.png)

````
#import "AdformTrackingSDK.h"
````


![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_09.png)

````
TrackPoint *trackPoint = [[TrackPoint alloc] initWithTrackingPointId:@"123456"];

[trackPoint setSectionName:@"Custom Section Name"];

NSMutableDictionary *parameters = [[NSMutableDictionary alloc] init];

[trackPoint setCustomParameterWithKey:@"var1" withValue:@"Custom Variable 1"];
[trackPoint setCustomParameterWithKey:@"var2" withValue:@"Custom Variable 2"];
[trackPoint setCustomParameterWithKey:@"var3" withValue:@"Custom Variable 3"];

[[AdformTrackingSDK sharedInstance] setCustomParameters: parameters];

[[AdformTrackingSDK sharedInstance] sendTrackingInformation:trackPoint];
````

* Setting Custom App Name for Tracking Point

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_10.png)

````
[[AdformTrackingSDK sharedInstance] setDefaultApplicationName:@"Custom Application Name"];
    
[[AdformTrackingSDK sharedInstance] startTrackingWithTrackingPointId:@"123456"];
````
