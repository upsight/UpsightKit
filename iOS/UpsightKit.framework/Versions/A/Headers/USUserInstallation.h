//
//  USUserInstallation.h
//  UpsightAnalytics
//
//  Created by Norman van der Ploeg on 2017-07-31.
//  Copyright © 2017 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface USUserInstallation : NSObject


//Returns the installation date (epoch since 01/01/1970) Sets the date to the current time if no installation is found for the given user
- (NSDate *)installDateForUser:(NSString *) userID;
- (void)setinstallDate:(NSDate *) date ForUser:(NSString *) userID;
- (void)removeInstallForUser:(NSString *) userID;
@end
