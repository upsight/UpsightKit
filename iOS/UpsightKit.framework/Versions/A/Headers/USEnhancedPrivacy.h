//
//  USEnhancedPrivacy.h
//  UpsightAnalytics
//
//  Created by Norman van der Ploeg on 2018-05-24.
//  Copyright © 2018 Upsight. All rights reserved.
//

#ifndef USEnhancedPrivacy_h
#define USEnhancedPrivacy_h

typedef NS_ENUM(NSInteger, EnhancedPrivacyApplicibiltyLevel) {
    kEnhancedPrivacyApplicibility_Auto, ///(Default) Upsight's servers will determine whether or not a user applies for enhanced privacy (eg they are in a country that must comply to GDPR). With this on, certain Upsight features, such as mediation, may not be available for users in areas where enhanced privacy applies.
    kEnhancedPrivacyApplicibility_YES, ///Enhanced privacy applies to this user.
    kEnhancedPrivacyApplicibility_NO /// Enhanced privacy does not apply to this user.
};

@interface Upsight (EnhancedPrivacy)

/** Sets the enhanced privacy applicibility Level to the corresponding value which helps determine how to handle user data. see @EnhancedPrivacyApplicibiltyLevel above
 @param privacyLevel Integter value corresponding to the above enums, values outside of the defined values will no-op
 
 */
+ (void)setEnhancedPrivacyApplicability:(NSInteger) privacyLevel;

/** Get shte current enhanced privacy applicibility level.
 @retval the Current level that the SDK has and is sending to the API. See @EnhancedPrivacyApplicibiltyLevel
 */
+ (NSInteger)getEnhancedPrivacyApplicability;

/**  allows you to indicate to Upsight whether or not a user has consented for additional data collection. This should be changed at any time a user either consents or revokes consent. Your application is responsible for requesting and properly passing in the current consent status to the Upsight SDK. By default this is set to false.
 
 @param consentGranted A flag to indicate whether the user has consent to data collection. True for Consent granted, false for consent revoked or denied.
 */
+ (void)setEnhancedPrivacyConsentGranted:(BOOL) consentGranted;

/** returns the current status of whether or not a user has given consent.
 
 @retval (bool) current status of Consent Granted
 */
+ (BOOL)isEnhancedPrivacyConsentGranted;

@end

#endif /* USEnhancedPrivacy_h */
