//
//  AdformAdobeExtension.h
//  adobe-extension
//
//  Created by Vladas Drejeris on 2019-12-12.
//  Copyright © 2019 adform. All rights reserved.
//

#import "ACPExtension.h"

NS_ASSUME_NONNULL_BEGIN

extern long const kInvalidTrackingId;

@interface AdformAdobeExtension : ACPExtension

/// Registers extension in ACPCore.
+ (void) registerExtension;

/// Returns tracking point id retrieved from Adobe Experience Platform or kInvalidTrackingId, if id was not retrieved successfully.
+ (long) trackingPointId;

@end

NS_ASSUME_NONNULL_END
