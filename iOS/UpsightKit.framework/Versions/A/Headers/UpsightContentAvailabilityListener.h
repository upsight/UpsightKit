//
//  UpsightContentAvailabilityListener.h
//  USBillboards
//
//  Created by Norman van der Ploeg on 2017-12-13.
//  Copyright © 2017 Upsight. All rights reserved.
//

#ifndef UpsightContentAvailabilityListener_h
#define UpsightContentAvailabilityListener_h

@protocol UpsightContentAvailabilityListener <NSObject>

- (void)onContentAvailableForScope:(nonnull NSString *) scope withParameters:(nullable NSDictionary *) parameters;
- (void)onContentNotAvailableForScope:(nonnull NSString *) scope withParameters:(nullable NSDictionary *) parameters;

- (void)partnerInitialized:(nonnull NSString *) partnerName;

@end



#endif /* UpsightContentAvailabilityListener_h */
