//
//  AFTEventAdapter.h
//  adobe-extension
//
//  Created by Vladas Drejeris on 2019-12-13.
//  Copyright © 2019 adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AFTrackPoint;

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kTrackPointIdKey;
extern NSString * const kTrackPointAppNameKey;

extern NSString * const kTrackPointOrderIdKey;
extern NSString * const kTrackPointOrderSaleKey;
extern NSString * const kTrackPointOrderEmailKey;
extern NSString * const kTrackPointOrderFirstNameKey;
extern NSString * const kTrackPointOrderLastNameKey;
extern NSString * const kTrackPointOrderAddress1Key;
extern NSString * const kTrackPointOrderAddress2Key;
extern NSString * const kTrackPointOrderPhoneKey;
extern NSString * const kTrackPointOrderAgeGroupKey;
extern NSString * const kTrackPointOrderZipKey;
extern NSString * const kTrackPointOrderCountryKey;
extern NSString * const kTrackPointOrderGenderKey;
extern NSString * const kTrackPointOrderCurrencyKey;
extern NSString * const kTrackPointOrderStatusKey;
extern NSString * const kTrackPointOrderBasketSizeKey;

extern NSString * const kTrackPointProductCategoryNameKey;
extern NSString * const kTrackPointProductCategoryIdKey;
extern NSString * const kTrackPointProductNameKey;
extern NSString * const kTrackPointProductIdKey;
extern NSString * const kTrackPointProductWeightKey;
extern NSString * const kTrackPointProductStepKey;
extern NSString * const kTrackPointProductSalesKey;
extern NSString * const kTrackPointProductCountKey;
extern NSString * const kTrackPointProductCustomKey;

@interface AFTEventAdapter : NSObject

+ (NSDictionary<NSString *, NSString *> *)makeContextDataFrom:(AFTrackPoint *)trackPoint;

@end

NS_ASSUME_NONNULL_END
