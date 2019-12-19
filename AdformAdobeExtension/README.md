# Publishing events using Adobe Experience SDK

## 1. Set-up Adobe experience platform

- To use Adobe experience sdk you'll have to integrate the Adobe experience sdk first
- Then install `Adform mobile extenesion` in Adobe experience cloud platform

## 2. Integerate Adform extension

### 2.1 Using CocoaPods

We are using CocaPods for dependency management. Therefore, please add this pod to your podfile:

```
pod 'AdformAdobeExtension'
```

### 2.2. Manual integration

If you wish to integrate this extension manually, follow these steps: 

1. Copy `libAdformAdobeExtension.a` and `include` folder and add them to your project. 
2. Integrate required dependencies: `AdformTracking` and `ACPCore`. 

### 2.3. Register Adform extension

To register Adform extension you just need to add this line of code to your Adobe Experience SDK setup:

```obj-c
[AdformAdobeExtension register];
```

## 3. Sending events

There are a couple of ways to send events through Adobe Experience SDK. If you already have Adform integrated you can convenience method to convert current track points to event data or just create event data from scratch using provided key constants.

### 3.1. Using track point adapter

To minimize code changes needed to migrate to Adobe Experience SDK you can use `AFTEventAdapter` class to convert `AFTrackPoint` class instances to event data and send it through Adobe SDK. Following example shows you how to do it.

```obj-c
- (void)sendTrackPoint {
    AFTrackPoint *trackPoint = [[AFTrackPoint alloc] initTrackPoint:123456789];
    [trackPoint setAppName:@"DemoAdobe-iOS"];
    
    AFOrder *order = [AFOrder new];
    order.orderId = @"1";
    order.sale = 15;
    order.currency = @"Eur";
    order.orderStatus = @"Sold";
    order.country = @"Lithuania";
    order.gender = @"Male";
    [trackPoint setOrder:order];
    
    AFProduct *product1 = [AFProduct new];
    product1.categoryId = @"1";
    product1.categoryName = @"Category";
    product1.productId = @"2";
    product1.productName = @"Product";
    product1.weight = 5;
    product1.step = AFEcomerceStepView;
    product1.productCount = 3;
    [trackPoint addProduct:product];
    
    NSDictionary *data = [AFTEventAdapter makeContextDataFrom:trackPoint];
    [ACPCore trackAction: @"Demo-action" data: data];
}
```

### 3.2. Sending event data directly

If you have not created events for Adform before, there is a more generic way of sending those events:

```obj-c
- (void)sendTrackPoint {
    NSString *trackingPointId = [NSString stringWithFormat:@"%ld", [AdformAdobeExtension trackingPointId];
    NSDictionary *data = @{
        kTrackPointIdKey: trackingPointId,
        kTrackPointAppNameKey: @"DemoAdobe-iOS",
        
        kTrackPointOrderIdKey: @"1",
        kTrackPointOrderSaleKey: @"15",
        kTrackPointOrderCurrencyKey: @"Eur",
        kTrackPointOrderStatusKey: @"Sold",
        kTrackPointOrderCountryKey: @"Lithuania",
        kTrackPointOrderGenderKey: @"Male",
        
        // Product
        kTrackPointProductCategoryIdKey: @"1",
        kTrackPointProductCategoryNameKey: @"Category",
        kTrackPointProductIdKey: @"2",
        kTrackPointProductNameKey: @"Product",
        kTrackPointProductWeightKey: @"5",
        kTrackPointProductStepKey: @"1",
        kTrackPointProductCountKey: @"3"
    }
    
    [ACPCore trackAction: @"Demo-action" data: data];
}
```

# Release notes

## 1.3.3

### Initial release
