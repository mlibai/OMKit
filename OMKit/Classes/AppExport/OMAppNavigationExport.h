//
//  AppNavigationExport.h
//  OCJSCore
//
//  Created by mlibai on 2017/6/16.
//  Copyright © 2017年 mlibai. All rights reserved.
//

#import <Foundation/Foundation.h>

@import JavaScriptCore;

@protocol OMAppExportDelegate, OMAppNavigationExportDelegate;

NS_ASSUME_NONNULL_BEGIN

/** 导航栏 */
NS_SWIFT_NAME(AppNavigationBarExportProtocol)
@protocol OMAppNavigationBarExport <NSObject, JSExport>
@property (nonatomic) BOOL isHidden;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *titleColor;
@property (nonatomic, copy, nullable) NSString *backgoundColor;
@end

/** 导航。处理导航行为以及管理导航条。 */
NS_SWIFT_NAME(AppNavigationExportProtocol)
@protocol OMAppNavigationExport <NSObject, JSExport>
@property (nonatomic, strong, readonly, nonnull) NSObject<OMAppNavigationBarExport> *bar;
@property (nonatomic, weak, nullable, readonly) id<OMAppNavigationExportDelegate> delegate;
JSExportAs(push, - (void)push:(nonnull NSString *)url animated:(BOOL)animated);
- (void)pop:(BOOL)animated;
JSExportAs(popTo, - (void)popTo:(NSInteger)index animated:(BOOL)animated);
@end





// 导航
NS_SWIFT_NAME(AppNavigationExport)
@interface OMAppNavigationExport : NSObject <OMAppNavigationExport>
@property (nonatomic, weak, nullable) id<OMAppNavigationExportDelegate> delegate;
@end


NS_SWIFT_NAME(AppNavigationExportDelegate)
@protocol OMAppNavigationExportDelegate <NSObject>

- (void)navigation:(OMAppNavigationExport *)navigation push:(NSString *)url animated:(BOOL)animated;
- (void)navigation:(OMAppNavigationExport *)navigation pop:(BOOL)animated;
- (void)navigation:(OMAppNavigationExport *)navigation popTo:(NSInteger)index animated:(BOOL)animated;

- (void)navigation:(OMAppNavigationExport *)navigation title:(nullable NSString *)title;
- (void)navigation:(OMAppNavigationExport *)navigation titleColor:(NSString *)titleColor;
- (void)navigation:(OMAppNavigationExport *)navigation isHidden:(BOOL)isHidden;
- (void)navigation:(OMAppNavigationExport *)navigation backgroundColor:(NSString *)backgroundColor;

@end
NS_ASSUME_NONNULL_END
