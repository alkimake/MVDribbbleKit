// MVDribbbleKit.h
//
// Copyright (c) 2014 Marcel Voss
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

#import "MVShot.h"
#import "MVLike.h"
#import "MVUser.h"
#import "MVComment.h"
#import "MVAttachment.h"

#import "MVAuthBrowser.h"

typedef NS_ENUM(NSInteger, List) {
    ListAnimated,
    ListDebuts,
    ListPlayoffs,
    ListRebounds,
    ListTeams
};

typedef NS_ENUM(NSInteger, UserType) {
    UserTypeFollowers,
    UserTypeFollowing,
    UserTypeDraftees
};

typedef void (^SuccessHandler) (NSArray *resultsArray, NSHTTPURLResponse *response);
typedef void (^FailureHandler) (NSError *error, NSHTTPURLResponse *response);

@interface MVDribbbleKit : NSObject

@property (nonatomic) NSNumber *itemsPerPage;
@property (nonatomic) BOOL allowsCellularAccess;

@property (nonatomic) NSArray *scopes;

@property (nonatomic, copy) NSString *clientID;
@property (nonatomic, copy) NSString *clientSecret;
@property (nonatomic, copy) NSString *callbackURL;

@property (nonatomic, copy) NSString *accessToken;

#pragma mark - Miscellaneous

+ (MVDribbbleKit *)sharedInstance;
- (instancetype)initWithClientID:(NSString *)clientID secretID:(NSString *)secretID callbackURL:(NSString *)callbackURL;

#pragma mark - Authorization

- (void)authorizeWithCompletion:(void (^) (NSError *error, NSString *accessToken))completion;
- (void)setClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret callbackURL:(NSString *)callbackURL;

#pragma mark - Users

// If playerID is nil, return the authenticated player
- (void)getDetailsForUser:(NSString *)userID
                    success:(void (^) (MVUser *user, NSHTTPURLResponse *response))success
                    failure:(FailureHandler)failure;

- (void)getFollowersForUser:(NSString *)userID page:(NSNumber *)page
                      success:(SuccessHandler)success
                      failure:(FailureHandler)failure;

- (void)getFollowingsForUser:(NSString *)userID page:(NSNumber *)page
                      success:(SuccessHandler)success
                      failure:(FailureHandler)failure;

- (void)followUserWithID:(NSString *)userID
                   success:(void (^) (NSHTTPURLResponse *response))success
                   failure:(FailureHandler)failure;

- (void)unfollowUserWithID:(NSString *)userID
                     success:(void (^) (NSHTTPURLResponse *response))success
                     failure:(FailureHandler)failure;

#pragma mark - Teams

// If playerID is nil, use the authenticated player
- (void)getTeamsForUserWithID:(NSString *)userID page:(NSNumber *)page
                        success:(SuccessHandler)success
                        failure:(FailureHandler)failure;

#pragma mark - Shots

- (void)getShotWithID:(NSNumber *)shotID
              success:(void (^) (MVShot *shot, NSHTTPURLResponse *response))success
              failure:(FailureHandler)failure;

- (void)updateShotWithID:(NSNumber *)shotID title:(NSString *)title description:(NSString *)description tags:(NSArray *)tags teamID:(NSNumber *)teamID
                 success:(void (^) (MVShot *shot, NSHTTPURLResponse *respose))success
                 failure:(FailureHandler)failure;

// TODO: Still missing
- (void)getShotsOnList:(List)list page:(NSNumber *)page
               success:(SuccessHandler)success
               failure:(FailureHandler)failure;

- (void)getShotsByUser:(NSString *)userID page:(NSNumber *)page
                 success:(SuccessHandler)success
                 failure:(FailureHandler)failure;

- (void)getLikedShotsByUser:(NSString *)userID page:(NSNumber *)page
                      success:(SuccessHandler)success
                      failure:(FailureHandler)failure;

// TODO: Needs a new name
- (void)getTimelineOfUser:(NSString *)userID page:(NSNumber *)page
                         success:(SuccessHandler)success
                         failure:(FailureHandler)failure;

- (void)getLikesForShot:(NSNumber *)shotID page:(NSNumber *)page
                success:(SuccessHandler)success
                failure:(FailureHandler)failure;

- (void)likeShotWithID:(NSNumber *)shotID
               success:(void (^) (MVLike *like, NSHTTPURLResponse *response))success
               failure:(FailureHandler)failure;

- (void)unlikeShotWithID:(NSNumber *)shotID
                 success:(void (^) (NSHTTPURLResponse *response))success
                 failure:(FailureHandler)failure;

- (void)deleteShotWithID:(NSNumber *)shotID
                 success:(void (^) (NSHTTPURLResponse *response))success
                 failure:(FailureHandler)failure;

#pragma mark - Attachments

- (void)getAttachmentsForShot:(NSNumber *)shotID page:(NSNumber *)page
                      success:(SuccessHandler)success
                      failure:(FailureHandler)failure;

- (void)getAttachmentWithID:(NSNumber *)attachmentID onShot:(NSNumber *)shotID
                    success:(void (^) (MVAttachment *attachment, NSHTTPURLResponse *response))success
                    failure:(FailureHandler)failure;

- (void)createAttachmentForShot:(NSNumber *)shotID fromData:(NSData *)attachmentData
                        success:(void (^) (MVAttachment *attachment, NSHTTPURLResponse *response))success
                        failure:(FailureHandler)failure;

- (void)deleteAttachmetWithID:(NSNumber *)attachmentID onShot:(NSNumber *)shotID
                      success:(void (^) (NSHTTPURLResponse *response))success
                      failure:(FailureHandler)failure;

#pragma mark - Comments

- (void)getCommentsForShot:(NSNumber *)shotID page:(NSNumber *)page
                   success:(SuccessHandler)success
                   failure:(FailureHandler)failure;

- (void)getLikesForCommentWithID:(NSNumber *)commentID onShot:(NSNumber *)shotID page:(NSNumber *)page
                         success:(SuccessHandler)success
                         failure:(FailureHandler)failure;

- (void)createCommentForShot:(NSNumber *)shotID body:(NSString *)body
                     success:(void (^) (MVComment *comment, NSHTTPURLResponse *response))success
                     failure:(FailureHandler)failure;

// FIXME: Doesn't work
- (void)updateCommentWithID:(NSNumber *)commentID onShot:(NSNumber *)shotID body:(NSString *)body
                    success:(void (^) (MVComment *comment, NSHTTPURLResponse *response))success
                    failure:(FailureHandler)failure;

- (void)likeCommentWithID:(NSNumber *)commentID onShot:(NSNumber *)shotID
                  success:(void (^) (MVLike *like, NSHTTPURLResponse *response))success
                  failure:(FailureHandler)failure;

- (void)unlikeCommentWithID:(NSNumber *)commentID onShot:(NSNumber *)shotID
                  success:(void (^) (NSHTTPURLResponse *response))success
                  failure:(FailureHandler)failure;

#pragma mark - Rebounds

- (void)getReboundsForShot:(NSNumber *)shotID page:(NSNumber *)page
                   success:(SuccessHandler)success
                   failure:(FailureHandler)failure;

@end
