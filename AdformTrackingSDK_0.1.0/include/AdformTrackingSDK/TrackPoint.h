//
//  TrackPointEntity.h
//  AdformTrackingSDK
//
//  Created by Linar on 8/21/14.
//  Copyright (c) 2014 Adform. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TrackPoint : NSObject
{
    @private
    NSString *_trackingPointId;
    NSString *_applicationName;
    NSString *_sectionName;
    NSMutableDictionary  *_parametersDictionary;
}

- (id)initWithTrackingPointId:(NSString *)trackingPointId;

// getters
- (NSString *)getTrackingPointId;
- (NSString *)getSectionName;
- (NSString *)getApplicationName;
- (NSDictionary *)getParameters;

// setters
- (void)setDefaultApplicationName:(NSString *)applicationName;
- (void)setSectionName:(NSString *)sectionName;
- (void)setCustomParameterWithKey:(NSString *)key withValue:(NSString *)parameter;
- (void)setCustomParameters:(NSDictionary *)parametersDictionary;

@end
