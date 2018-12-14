//
//  AFProduct.h
//  AdformTracking
//
//  Created by Vladas Drejeris on 18/01/16.
//  Copyright © 2016 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Ecomerce workflow step. values.
 
 - AFEcomerceStepUndefined: 
    Step is not defined. The default value for product.
 
 - AFEcomerceStepView: 
    Identifies that user has viewed a product.
 
 - AFEcomerceStepBasket: 
    Identifies that user has added a product to its shopping basket.
 
 - AFEcomerceStepPurchase:
    Identifies that user has purchased a product.
 */
typedef NS_ENUM(NSInteger, AFEcomerceStep) {
    
    /// Step is not defined. The default value for product.
    AFEcomerceStepUndefined = 0,
    
    /// Identifies that user has viewed a product.
    AFEcomerceStepView = 1,
    
    /// Identifies that user has added a product to its shopping basket.
    AFEcomerceStepBasket = 2,
    
    /// Identifies that user has purchased a product.
    AFEcomerceStepPurchase = 3
};

NS_ASSUME_NONNULL_BEGIN

/**
 Defines a product object.
 
 Products may be set to track points to send product variables.
 */
@interface AFProduct : NSObject

/**
 The name name of the product category.
 */
@property (nonatomic, strong, nullable) NSString *categoryName;

/**
 The id of the product category.
 */
@property (nonatomic, strong, nullable) NSString *categoryId;

/**
 The product name.
 */
@property (nonatomic, strong, nullable) NSString *productName;

/**
 The product id.
 */
@property (nonatomic, strong, nullable) NSString *productId;

/**
 The product weight.
 */
@property (nonatomic, assign) NSInteger weight;

/**
 Ecomerce workflow step.
 
 @see AFEcomerceStep.
 */
@property (nonatomic, assign) AFEcomerceStep step;

/**
 The sales of the product.
 */
@property (nonatomic, assign) float productSales;

/**
 The product count.
 */
@property (nonatomic, assign) NSInteger productCount;

/**
 Additional information that may be associated to the product.
 */
@property (nonatomic, strong, nullable) NSString *custom;


- (instancetype)initWithCategoryName:(nullable NSString *)categoryName
                          categoryId:(nullable NSString *)categoryId
                         productName:(nullable NSString *)productName
                           productId:(nullable NSString *)productId
                              weight:(NSInteger )weight
                                step:(NSInteger )step
                        productSales:(float )productSales
                        productCount:(NSInteger )productCount
                              custom:(nullable NSString *)custom;

@end
NS_ASSUME_NONNULL_END
