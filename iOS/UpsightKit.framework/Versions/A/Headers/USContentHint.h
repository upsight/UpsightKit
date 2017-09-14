//
//  USContentHint.h
//  USBillboards
//
//  Created by Kash Shamim on 2/03/17.
//  Copyright (c) 2017 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Abstracts Upsight content hint, an object that gets propagated from the server to the
application. */
@protocol USContentHint <NSObject>

/** A dictionary of properties related to the content hint */
@property (nonatomic, readonly) NSDictionary *properties;

/** The type of content unit associated with this billboard represented as a string
 Content types can be added dynamically, but here is a list of types as of the release v4.4.0 of the SDK:
    "unknown",
    "announcement",
    "internal_cross_promotion",
    "rewards",
    "virtual_goods_promotion",
    "opt_in",
    "ads",
    "more_games",
    "video_campaign",
    "custom_view",
    "mediation"
 */
@property (nonatomic, readonly) NSString *contentType;

@end
