//
//  USUserSession.h
//  UpsightAnalytics
//
//  Created by Norman van der Ploeg on 2017-06-26.
//  Copyright © 2018 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Upsight.h"

extern NSString * _Nonnull kUSUserSessionUserNameKey;
typedef NS_ENUM(NSUInteger, USUserSessionErrorCodes) {
    kUSUserSessionError_Success, //Operation completed without error
    kUSUserSessionError_NullUser, //nil user ID is not accepted
    kUSUserSessionError_IDLengthInvalid, //User ID length must be non Zero, and less than 256 Bytes
    kUSUserSessionError_ContentIsDisplaying //User ID may not be changed during content display
};

@interface Upsight (USUserSession)

/** Sets the specified User ID. This has several effects:
 - Ends the session for any current user
 - Creates a new user if needed (see retainAttributes flag)
 - Begins a new Session
 - Once a User ID is set, it is retained through application starts.
 
 @param aUserID A new value for the user attribute indicated by aUserID.  It is highly recommended to hash the userID to prevent sending private and indientifiable information. The string must be a maximum of 256 bytes in size.
 @param retainAttributes a flag to determine if the user attributes from an anonymous user session should be copied into a new user. If transitioning to or from an existing user, this flag is ignored.
 */
+ (nullable NSError *)setUserID:(nonnull NSString *) aUserID preserve:(BOOL) retainAttributes;

/** Resets the current user to nil (anonymous user)
 * Ends the current session if a User ID is currently set.
 */
+ (nullable NSError *)clearUserID;

/** Removes a user from the device, deleting all the attributes and session information associated with it. It will also set the current user to nil (anonymous user). This cannot be undone.  The anonymous user cannot be deleted.
 
 @param aUserID A new value for the user attribute indicated by aUserID.
 */

+ (nullable NSError *)deleteUser:(nonnull NSString *) aUserID;

/** Resets the User attributes of the current user to the default values found in the app Info.plist file
 */
+ (void)resetUserAttributes;

/** Fetches the current user ID.
 
 @return Value of the current user ID, nil if not no current user (anonymous user)
 */
+ (nullable NSString*)getCurrentUserID;

/** allows you to specify any 3-character country code to set as the user's home country. If you would like to clear this value, simply pass nil.
 @param aCountryName A 3 character code indicating the country. Country code will be validated by the API.
 
 @retval bool indicating whether the home country was successfully set
 */
+ (BOOL)setHomeCountry:(nullable NSString *) aCountryName;

/** returns the set home country string of the user or nil if none was set.

@retval 3 character string of the country that is set, or nil if no value is set.
*/
+ (nullable NSString *)getHomeCountry;

/** allows you to specify any 3-character country code to set as the user's current country. If you would like to clear this value, simply pass nil.
 
@param aCountryName A 3 character code indicating the country. Country code will be validated by the API .
 
@retval bool indicating whether the current country was successfully set
*/
+ (BOOL)setCurrentCountry:(nullable NSString *) aCountryName;

/**  returns the set current country string of the user or nil if none was set.
 
@retval 3 character string of the country that is set, or nil if no value is set.
*/
+ (nullable NSString *)getCurrentCountry;

 



@end
