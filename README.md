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

* Go to your application target’s configuration > General > Linked Frameworks and Libraries section and add these frameworks to your project:

   * **AdSupport.framework**
   * **CoreData.framework**
   * **SystemConfiguration.framework**

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_04.png)

* Go to your application target’s configuration > Build settings > Linking > Other Linker Flags, and set **-ObjC** flag.

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_05.png)

## 3. Basic Adform Tracking SDK implementation

* Import **AdformTrackingSDK.h** in **AppDelegate.h**

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_06.png)

````
#import "AdformTrackingSDK.h"
````

* In **application:didFinishLaunchingWithOptions:** method set custom parameters (optional) and call **startTracking:** method with your tracking point id

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_07.png)

````
[[AdformTrackingSDK sharedInstance] startTracking:123456];
````

Thats it! You are ready to go.

## 4. Custom Adform Tracking SDK implementations

* For Sending tracking events manualy you need import **AdformTrackingSDK.h** in **ViewController.h** 

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_08.png)

````
#import "AdformTrackingSDK.h"
````

* And set custom parameters as, follows

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_09.png)

````
TrackPoint *trackPoint = [[TrackPoint alloc] initTrackPoint:123456];

[trackPoint setSectionName:@"Custom Section Name"];

[trackPoint addParameter:@"var1" withValue:@"Custom Variable 1"];
[trackPoint addParameter:@"var2" withValue:@"Custom Variable 2"];
[trackPoint addParameter:@"var3" withValue:@"Custom Variable 3"];

[[AdformTrackingSDK sharedInstance] sendTrackPoint:trackPoint];
````

* Setting Custom App Name for Tracking Point

![alt tag](http://37.157.0.44/mobilesdk/help/tracking/ios/image_10.png)

````
[[AdformTrackingSDK sharedInstance] setAppName:@"Custom Application Name"];
    
[[AdformTrackingSDK sharedInstance] startTracking:123456];
````
