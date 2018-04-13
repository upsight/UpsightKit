//
//  USUserSession.h
//  UpsightAnalytics
//
//  Created by Norman van der Ploeg on 2017-06-26.
//  Copyright © 2018 Upsight. All rights reserved.
//

#import <Foundation/Foundation.h>

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



@end
