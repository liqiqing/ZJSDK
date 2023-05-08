//
//  KMSwitchButtons.h
//  ScrollerTab
//
//  Created by kkmm on 2018/8/9.
//  Copyright © 2018年 kkmm. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SWModel.h"
#import "SliderSwitchProtocol.h"
#import "SliderLabel.h"
@class SliderSwitch;
@protocol SliderSwitchDelegate <UIScrollViewDelegate>
@required

/**
 设置每个index对应的页面

 @param sliderSwitch 自身
 @param index 索引
 @return 需要返回的pageView
 */
- (UIView <SliderSwitchProtocol>*)sliderSwitch:(SliderSwitch *)sliderSwitch setSubViewInIndex:(NSInteger)index;

@optional
- (void)sliderSwitch:(SliderSwitch *)sliderSwitch didSelectedIndex:(NSInteger)selectedIndex bySlideWay:(SlideWay)slideWay isFirstSlide:(BOOL)isFirstSlide;
/*! 选中selectedIndex 回调*/
//- (void)sliderSwitch:(SliderSwitch *)sliderSwitch didSelectedIndex:(NSInteger)selectedIndex;
- (void)sliderSwitch:(SliderSwitch *)sliderSwitch didSelectedIndex:(NSInteger)selectedIndex bySlideWay:(SlideWay)slideWay;

- (void)sliderSwitch:(SliderSwitch *)sliderSwitch didRepeatSelectedIndex:(NSInteger)selectedIndex bySlideWay:(SlideWay)slideWay;

- (void)sliderSwitchDidDoubleClickBlank:(SliderSwitch *)sliderSwitch;

@end


@interface SliderSwitch <T>: UIScrollView
/*! 数据源*/
@property(nonatomic,strong) NSMutableArray <SWModel *>*dataArray;
/*! visiablePageViews可见控制器数组*/
@property(nonatomic,strong)NSMutableArray <SWModel *>*visiablePageViews;
/*! title的未选中字色*/
@property(nonatomic,strong) UIColor *normalTitleColor;
/*! title的选中字色*/
@property(nonatomic,strong) UIColor *selectedTitleColor;
/*! title字体*/
@property(nonatomic,strong) UIFont *titleFont;
/*! 选中title字体*/
@property(nonatomic,strong) UIFont *selectedTitleFont;
/*! 选中按钮颜色*/
@property(nonatomic,strong) UIColor *selectedButtonColor;
/*! 选中按钮渐变色*/
@property(nonatomic, strong) NSArray *selectedButtonColors;
/*! button宽高*/
@property(nonatomic,assign) CGSize buttonSize;
/*! 滑块*/
@property(nonatomic,strong)CAGradientLayer *sliderLayer;
/*! 滑块默认颜色*/
@property(nonatomic,strong)UIColor *defalutSliderColor;
/*! 选中按钮字体是否变粗，默认变粗*/
@property(nonatomic) BOOL selectedFontBlod;
/*! 当前选中index*/
@property(nonatomic,readonly) NSInteger selectedIndex;
/*! 当前选中pageView*/
@property(nonatomic,strong) UIView <SliderSwitchProtocol>*  selectedPageView;
/*! 容器ScrollView*/
@property(nonatomic,weak) UIScrollView *containerScroll;
/**
 *可见中心偏移量 ，滑动停止后SliderSwitch中心按钮 悬停位置的偏移量
 
 *通常用作SliderSwitch未处于屏幕中心，而选中项需要悬停在屏幕中心的情形
 
 *默认为0,中心位置
 
 */
@property(nonatomic,assign)CGFloat visibleCenterOffset;
/** 滑条Size */
@property(nonatomic,assign) CGSize sliderSize;
/** 滑条距离底部的边距   default = 2 */
@property(nonatomic,assign) CGFloat sliderBottomMargin;
/** 滑条偏移量 */
@property(nonatomic,assign) CGFloat sliderOffset DEPRECATED_MSG_ATTRIBUTE("考虑以后可能的情形预定义属性，功能未实现");
/** 是否首次加载 */
@property(nonatomic) BOOL isFirstSlide;
///选中时Y轴偏移量 默认为-1
@property (nonatomic, assign) CGFloat Ytranform;


/** 动画是否停止 */
@property(nonatomic) BOOL animationStop;

/** 滑条是否可伸缩
 *  点击滑动时scrollViewDidScroll回调不改变slider.frame
 */
@property(nonatomic) BOOL sliderFlexibleWidthEnable;

/** 是否显示Item分割线 */
@property(nonatomic) BOOL showLine;

@property(nonatomic,weak) id<SliderSwitchDelegate> delegate;

-(void)setDataArray:(NSMutableArray<SWModel *> *)dataArray autoSize:(BOOL)autoSize;
- (instancetype)initWithFrame:(CGRect)frame buttonSize:(CGSize)size;



/** 记录上一次滑动的点  */
-(void)anchorScrollViewPoint:(UIScrollView *)scrollView;

/*! 滑动到idx  默认加载动画  默认触发方式 byCode*/
-(void)slideToIndex:(NSInteger)idx;

/*! 滑动到idx 是否加载动画  默认触发方式 byCode*/
-(void)slideToIndex:(NSInteger)idx animated:(BOOL)animated;


/// 滑动到index 需要确保滑动已完成则使用此方法
/// @param idx		 index
/// @param animated   是否开启动画
/// @param SlideWay 	 触发方式
-(void)slideToIndex:(NSInteger)idx animated:(BOOL)animated bySlideWay:(SlideWay)slideWay;

/// 滑动到index 需要确保滑动已完成则使用此方法
/// @param idx         index
/// @param animated   是否开启动画
/// @param SlideWay      触发方式
/// @param completion 完成回调
-(void)slideToIndex:(NSInteger)idx animated:(BOOL)animated bySlideWay:(SlideWay)slideWay complete:(void(^)(void))completion;

/*! 请求刷新当前子页面,主要用于点击menubar时调用刷新 */
-(void)requestRefreshCurrentPage;
/**
 重载数据
 */
-(void)sw_reloadData;
/**
 销毁子控制器，pop前调用
 */
-(void)distory;
///更新子pageView约束
-(void)updateSubpageViewFrame;
/**
 页面空白处增加双击事件
 */
-(void)addDoubleGesture;

@end

