#import <Foundation/Foundation.h>
#import "GCFloatedLabelView.h"

@interface GCFloatedLabelView()

@property(nonatomic, retain)UILabel* uiLable;
@property (nonatomic, retain) NSTimer* closeTimer;
@property (nonatomic, assign) NSInteger lastTime;

@end

@implementation GCFloatedLabelView

- (void)show:(CGPoint)center withTime:(NSInteger)showTime withText:(NSString*)message {
	
    [self.layer setCornerRadius:5];

    self.frame = CGRectMake(0, 0, 220, 50);

    [self setCenter:center];

    if (!_uiLable) {

        _uiLable = [[UILabel alloc] init];
        
        [_uiLable setFont:[UIFont systemFontOfSize:14]];
        
        _uiLable.textColor = [UIColor whiteColor];
        
        [self addSubview:_uiLable];
    }

    [_uiLable setText:message];

    CGSize size = [self boundingRectWithSize:CGSizeMake(240, 1000) label:_uiLable];

    _uiLable.frame = CGRectMake(0, 0, size.width, size.height);

    [_uiLable setCenter:CGPointMake(0.5 * self.frame.size.width, 0.5 * self.frame.size.height)];

    [self setBackgroundColor:[UIColor colorWithRed:0 green:0 blue:0 alpha:1]];

    _closeTimer = [NSTimer scheduledTimerWithTimeInterval:1.0f target:self selector:@selector(closeTick:) userInfo:nil repeats:YES];

    _lastTime = showTime;

    [_closeTimer fire];
}

- (CGSize)boundingRectWithSize:(CGSize)size label:(UILabel*)label
{
    NSDictionary *attribute = @{NSFontAttributeName: label.font};
    
    CGSize retSize = [label.text boundingRectWithSize:size
                                             options:\
                      NSStringDrawingTruncatesLastVisibleLine |
                      NSStringDrawingUsesLineFragmentOrigin |
                      NSStringDrawingUsesFontLeading
                                          attributes:attribute
                                             context:nil].size;
    
    return retSize;
}


- (void)closeTick:(NSTimer *)timer {
	
	if (_lastTime <= 0) {
		
		[_closeTimer invalidate];
		
		_closeTimer = nil;
		
		[self removeFromSuperview];
		
		return;
	}
	
	_lastTime--;
}

- (void)invalidTimer {
	
	[_closeTimer invalidate];
	
	_closeTimer = nil;
}


@end
