//
//  AFOrder.h
//  AdformTracking
//
//  Created by Vladas Drejeris on 22/03/16.
//  Copyright © 2016 Adform. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
/**
 Defines an order object.
 
 This object may be used to send additional tracking information.
 */
@interface AFOrder : NSObject

/// Order ID
@property (nonatomic, strong, nullable) NSString *orderId;

/// Sale price
@property (nonatomic, assign) float sale;

/// Sale bucket size.
@property (nonatomic, assign) NSInteger basketSize;

/// Order currency code
@property (nonatomic, strong, nullable) NSString *currency;

/// Order status
@property (nonatomic, strong, nullable) NSString *orderStatus;

/// User contact information
@property (nonatomic, strong, nullable) NSString *firstName;
@property (nonatomic, strong, nullable) NSString *lastName;
@property (nonatomic, strong, nullable) NSString *country;
@property (nonatomic, strong, nullable) NSString *address1;
@property (nonatomic, strong, nullable) NSString *address2;
@property (nonatomic, strong, nullable) NSString *zip;
@property (nonatomic, strong, nullable) NSString *email;
@property (nonatomic, strong, nullable) NSString *phone;

/// User demographic information
@property (nonatomic, strong, nullable) NSString *gender;
@property (nonatomic, strong, nullable) NSString *ageGroup;


/** 
 Custom variables that are visible in reports.
 Keys must be integers, values with other type of keys will be ignored.
 Up to 10 variables are supported, therefore you may only use keys from range [1, 10].
 For convenience you may use 'setCustomVariable:forKey:' methods.
*/
@property (nonatomic, strong, nullable) NSMutableDictionary<NSNumber *, NSString *> *customVariables;

/**
 Sets custom variable to an order.
 
 If you want to remove a variable using thie method, just pass nil as a variable parameter.
 
 @param variable A value of the variable. May be nil.
 @param key A key used to associate the variable with. Must be in range [1, 10].
 */
- (void)setCustomVariable:(nullable NSString *)variable forKey:(NSInteger )key;

/** 
 System variables that are visible in reports.
 Keys must be integers, values with other type of keys will be ignored.
 Up to 255 variables are supported, therefore you may only use keys from range [1, 255].
 For convenience you may use 'setSystemVariable:forKey:' methods.
 */
@property (nonatomic, strong, nullable) NSMutableDictionary<NSNumber *, NSString *> *systemVariables;

/**
 Sets system variable to an order.
 
 If you want to remove a variable using thie method, just pass nil as a variable parameter.
 
 @param variable A value of the variable. May be nil.
 @param key A key used to associate the variable with. Must be in range [1, 255].
 */
- (void)setSystemVariable:(nullable NSString *)variable forKey:(NSInteger )key;

/**
 Numeric system variables that are visible in reports.
 Keys must be integers, values with other type of keys will be ignored.
 Up to 255 variables are supported, therefore you may only use keys from range [1, 255].
 For convenience you may use 'setNumericSystemVariable:forKey:' methods.
 */
@property (nonatomic, strong, nullable) NSMutableDictionary<NSNumber *, NSNumber *> *numericSystemVariables;

/**
 Sets numeric system variable to an order.
 
 If you want to remove a variable using thie method, just pass nil as a variable parameter.
 
 @param variable A value of the variable. May be nil.
 @param key A key used to associate the variable with. Must be in range [1, 255].
 */
- (void)setNumericSystemVariable:(nullable NSNumber *)variable forKey:(NSInteger )key;

@end
NS_ASSUME_NONNULL_END
