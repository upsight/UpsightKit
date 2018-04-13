//
//  USSessions.h
//  USSessionManager
//
//  Copyright © 2016 Upsight. All rights reserved.
//

#ifndef USSessions_h
#define USSessions_h

@class USSessionManager;
@protocol UpsightSessionDelegate;
@class USSessionInfo;


/**
 * Optionally implemented delegate protocol to allow hooks into Upsight session creation.
 * <p/>
 * 
 * You can set your delegate by using [USSessionInfo setUpsightSessionDelegate:] method
 *
 */
@protocol UpsightSessionDelegate <NSObject>

@optional

/**
 * Called when a new session is about to start. It is guaranteed to run before any event is
 * recorded, so this gives an opportunity for the application to set initial event attributes.
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 * @param previousSessionInfo Information about the previous Upsight session. If there is no
 *                            previous session, a nil sessionNumber is sent.
 */
- (void)upsightSessionWillStart:(nonnull USSessionInfo *) previousSessionInfo;

/**
 * Called when a new session is created. And current session Info is now available
 * <p/>
 * This block is executed synchronously and should be fast-returning. 
 */
- (void)upsightSessionDidStart;

/**
 * Called when an existing session is about to be extended. It is guaranteed to run before any
 * event is recorded in this extended part of the session, so this gives an opportunity for the
 * application to set initial event attributes.
 * <p/>
 * This block is executed synchronously and should be fast-returning. 
 *
 * @param resumedSessionInfo Information about the extended Upsight session.
 */
- (void)upsightSessionWillResume:(nonnull USSessionInfo *) resumedSessionInfo;

/**
 * Called when an existing session is extended.
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 *
 */
- (void)upsightSessionDidResume;

/**
 * Called when a new user session is about to start. It is guaranteed to run before any event is
 * recorded, so this gives an opportunity for the application to set initial event attributes.
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 * @param previousSessionInfo Information about the previous Upsight session. If there is no
 *                            previous session, a nil sessionNumber is sent.
 */
- (void)upsightUserSessionWillStart:(nonnull USSessionInfo *) previousSessionInfo;

/**
 * Called when a new user session is created. And current session Info is now available
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 */
- (void)upsightUserSessionDidStart;

/**
 * Called when an existing user session is about to be extended. It is guaranteed to run before any
 * event is recorded in this extended part of the session, so this gives an opportunity for the
 * application to set initial event attributes.
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 *
 * @param resumedSessionInfo Information about the extended Upsight session.
 */
- (void)upsightUserSessionWillResume:(nonnull USSessionInfo *) resumedSessionInfo;

/**
 * Called when an existing user session is extended.
 * <p/>
 * This block is executed synchronously and should be fast-returning.
 *
 */
- (void)upsightUserSessionDidResume;

@end

/**
 * Information about an Upsight session.
 */
@interface USSessionInfo : NSObject

/**
 * The incrementing count assigned to the session. If no session has been recorded, defaults to nil.
 */
@property (nonatomic, nullable) NSNumber * sessionNumber;
/**
 * The start time of the session in seconds. If No session has been recorded defaults to 0.
 */
@property (nonatomic) NSTimeInterval sessionStartTime;


/**
 * Sets the delegate class inside the upsight SDK in order to receive information about the session lifecycle.
 * You may set the delegate to nil to clear out the delegate.
 *
 * @param delegate. An weakly retained delegate object to which the sdk will attempt to report session lifecycle events 
 *
 */

+ (void)setUpsightSessionDelegate:(nullable NSObject<UpsightSessionDelegate> *)delegate;

/**
 * Gets information about the current Upsight session. Or if no session is active, will return the 
 * most recent session information. If no session has been recorded, then a default object with 
 * sessionNumber of nil, and sessionStartTime of 0 will be returned.
 *
 */
+ (nonnull USSessionInfo *)getLatestSessionInfo;

/**
 * Gets information about the current Upsight user session. Or if no user session is active, will return the
 * most recent session information. If no session has been recorded, then a default object with
 * sessionNumber of nil, and sessionStartTime of 0 will be returned.
 *
 */
+ (nonnull USSessionInfo *)getLatestUserSessionInfo;

@end



#endif /* USSessions_h */
