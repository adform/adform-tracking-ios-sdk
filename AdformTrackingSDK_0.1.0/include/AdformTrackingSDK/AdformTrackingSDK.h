//
//  AdformTrackingSDK.h
//  AdformTrackingSDK
//
//  Created by Linar on 7/15/14.
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrackPoint.h"

@class UIWebView;
@class DatabaseRepository;


@interface AdformTrackingSDK : NSObject
{
    @private
    NSOperationQueue    *_operationQueue;
    DatabaseRepository  *_databaseRepository;
    UIWebView           *_hiddenWebview;
    TrackPoint          *_startingTrackPoint;
}

+ (AdformTrackingSDK *)sharedInstance;

- (void)startTrackingWithTrackingPointId:(NSString *)trackingPointId;
- (void)sendTrackingInformation:(TrackPoint *)trackPoint;
- (void)setCustomParameterWithKey:(NSString *)key withValue:(NSString *)parameter;
- (void)setCustomParameters:(NSDictionary *)parametersDictionary;

@end
