//
//  KMPagerView.h
//  KMSegmentedPager
//
//  Created by Jangsy7883 on 2015. 9. 4..
//  Copyright © 2015년 Dalkomm. All rights reserved.
//

#import <UIKit/UIKit.h>

@class KMPageView;

@protocol KMPageViewDelegate <NSObject>

@optional
- (void)pageView:(KMPageView*)pageView didScrollToCurrentPosition:(CGFloat)currentPosition;
- (void)pageView:(KMPageView*)pageView didScrollToCurrentIndex:(NSUInteger)currentIndex;

@end

@protocol KMPageViewDataSource <NSObject>

- (NSArray *)viewControllersForPageView:(KMPageView *)pageView;

@end

@interface KMPageView : UIView

@property (nonatomic, assign) NSUInteger currentIndex;

@property (nonatomic, assign, getter = isScrollPagingEnabled) BOOL scrollPagingEnabled;

@property (nonatomic, readonly) UIViewController* currentViewController;
@property (nonatomic, readonly) NSArray *viewControllers;
@property (nonatomic, readonly) NSInteger numberOfPage;

@property (nonatomic, weak) id<KMPageViewDelegate>delegate;
@property (nonatomic, weak) id<KMPageViewDataSource>dataSource;

- (void)reloadData;

- (void)setCurrentIndex:(NSUInteger)currentIndex animated:(BOOL)animated;

@end
