//
//  GCFloatedLabelView.h
//
//

#ifndef GameChat_GCFloatedLabelView_h
#define GameChat_GCFloatedLabelView_h

#import <UIKit/UIKit.h>

@interface GCFloatedLabelView : UIView

@property(nonatomic, assign)NSInteger showTime;

- (void)show:(CGPoint)center withTime:(NSInteger)showTime withText:(NSString*)message;

@end

#endif
