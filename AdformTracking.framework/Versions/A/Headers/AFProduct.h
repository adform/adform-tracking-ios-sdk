//
//  AFProduct.h
//  AdformTracking
//
//  Created by Vladas Drejeris on 18/01/16.
//  Copyright © 2016 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Defines a product object.
 
 Products may be set to track points to send product variables.
 */
@interface AFProduct : NSObject <NSCoding>

/**
 The name name of the product category.
 */
@property (nonatomic, strong) NSString *categoryName;

/**
 The id of the product category.
 */
@property (nonatomic, strong) NSString *categoryId;

/**
 The product name.
 */
@property (nonatomic, strong) NSString *productName;

/**
 The product id.
 */
@property (nonatomic, strong) NSString *productId;

/**
 The product weight.
 */
@property (nonatomic, strong) NSString *weight;

/**
 The product step.
 */
@property (nonatomic, strong) NSString *step;

/**
 The sales of the product.
 */
@property (nonatomic, strong) NSString *productSales;

/**
 The product count.
 */
@property (nonatomic, strong) NSString *productCount;

/**
 Additional information that may be associated to the product.
 */
@property (nonatomic, strong) NSString *custom;

- (instancetype)initWithCategoryName:(NSString *)categoryName
                          categoryId:(NSString *)categoryId
                         productName:(NSString *)productName
                           productId:(NSString *)productId
                              weight:(NSString *)weight
                                step:(NSString *)step
                        productSales:(NSString *)productSales
                        productCount:(NSString *)productCount
                              custom:(NSString *)custom;

@end
