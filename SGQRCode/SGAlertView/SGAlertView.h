
#import <UIKit/UIKit.h>
@class SGAlertView;

typedef enum : NSUInteger {
    SGAlertViewBottomViewTypeOne,
    SGAlertViewBottomViewTypeTwo,
} SGAlertViewBottomViewType;

@protocol SGAlertViewDelegate <NSObject>

@optional
/** right 按钮的点击事件(SGAlertViewBottomViewTypeOne 类型的确定按钮；SGAlertViewBottomViewTypeTwo 类型是right) */
- (void)didSelectedRightButtonClick;
/** left 按钮的点击事件(点击事件针对 SGAlertViewBottomViewTypeTwo 类型起作用) */
- (void)didSelectedLeftButtonClick;

@end

@interface SGAlertView : UIView

@property (nonatomic, weak) id<SGAlertViewDelegate> delegate_SG;

/** 确定(Right)按钮标题(SGAlertViewBottomViewTypeTwo 默认为Right按钮) */
@property (nonatomic, copy) NSString *sure_btnTitle;
/** left 按钮标题 */
@property (nonatomic, copy) NSString *left_btnTitle;
/** 确定(Right)按钮标题颜色(SGAlertViewBottomViewTypeTwo 默认为Right按钮)*/
@property (nonatomic, strong) UIColor *sure_btnTitleColor;
/** left 按钮标题颜色(SGAlertViewBottomViewTypeTwo 样式的Left按钮)*/
@property (nonatomic, strong) UIColor *left_btnTitleColor;
/** 底部按钮样式 */
@property (nonatomic, assign) SGAlertViewBottomViewType alertViewBottomViewType;

/** 对象方法创建 SGAlertView */
- (instancetype)initWithTitle:(NSString *)title delegate:(id<SGAlertViewDelegate>)delegate contentTitle:(NSString *)contentTitle alertViewBottomViewType:(SGAlertViewBottomViewType)alertViewBottomViewType;

/** 类方法创建 SGAlertView */
+ (instancetype)alertViewWithTitle:(NSString *)title delegate:(id<SGAlertViewDelegate>)delegate contentTitle:(NSString *)contentTitle alertViewBottomViewType:(SGAlertViewBottomViewType)alertViewBottomViewType;

- (void)show;

@end
