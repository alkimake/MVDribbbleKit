// MVShot.h
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

#import "MVUser.h"

@interface MVShot : NSObject

@property (nonatomic) NSNumber *attachmentsCount;
@property (nonatomic) NSURL *attachmentsURL;
@property (nonatomic) NSNumber *bucketsCount;
@property (nonatomic) NSNumber *commentsCount;

@property (nonatomic) NSURL *commentsURL;
@property (nonatomic) NSDate *createdDate;
@property (nonatomic, copy) NSString *shotDescription;
@property (nonatomic) NSURL *htmlURL;
@property (nonatomic) NSNumber *shotID;

@property (nonatomic) NSNumber *likesCount;
@property (nonatomic) NSURL *likesURL;
@property (nonatomic) NSNumber *reboundsCount;
@property (nonatomic) NSURL *reboundsURL;
@property (nonatomic) NSArray *tags;
@property (nonatomic) NSURL *projectsURL;

@property (nonatomic, copy) NSString *title;
@property (nonatomic) NSDate *updatedDate;
@property (nonatomic) NSNumber *viewsCount;

@property (nonatomic) NSURL *highDPIImageURL;
@property (nonatomic) NSURL *normalImageURL;
@property (nonatomic) NSURL *teaserImageURL;

@property (nonatomic) MVUser *team;
@property (nonatomic) MVUser *user;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end
