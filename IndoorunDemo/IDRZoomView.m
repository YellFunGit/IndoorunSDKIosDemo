//
//  IDRZoomView.m
//  IndoorunMap_Core
//
//  Created by ky on 09/03/2017.
//  Copyright © 2017 yellfun. All rights reserved.
//

#import "IDRZoomView.h"

@interface IDRZoomView()

@property (nonatomic) UIImageView *zoomBG;
@property (nonatomic) UIButton *zoomInBtn;
@property (nonatomic) UIButton *zoomOutBtn;

@end

@implementation IDRZoomView

- (id)initWithFrame:(CGRect)frame{
    
    self = [super initWithFrame:frame];
    
    CGFloat aHeight = 0;
    
    CGRect rect = self.bounds;
    
    _zoomBG = [[UIImageView alloc] initWithFrame:rect];
    [_zoomBG setImage:[UIImage imageNamed:@"放大缩小.png"]];
    [_zoomBG setUserInteractionEnabled:YES];
    [self addSubview:_zoomBG];
    
    _zoomInBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    
    [_zoomInBtn setFrame:CGRectMake(0, 0, rect.size.width, rect.size.height * 0.5)];
    [_zoomInBtn setImage:[UIImage imageNamed:@"YFMapAddClick.png"] forState:UIControlStateNormal];
    [_zoomInBtn setImage:[UIImage imageNamed:@"YFMapAddNormal.png"] forState:UIControlStateHighlighted];
    [_zoomInBtn setImageEdgeInsets:UIEdgeInsetsMake(10, 10, 10, 10)];
    [_zoomInBtn addTarget:self action:@selector(zoomInAction) forControlEvents:UIControlEventTouchUpInside];
    [self bringSubviewToFront:_zoomInBtn];
    [self addSubview:_zoomInBtn];
    
    _zoomOutBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [_zoomOutBtn setFrame:CGRectMake(0, rect.size.height * 0.5, rect.size.width, rect.size.height * 0.5)];
    [_zoomOutBtn setImage:[UIImage imageNamed:@"YFMapSubClick.png"] forState:UIControlStateHighlighted];
    [_zoomOutBtn setImage:[UIImage imageNamed:@"YFMapSub.png"] forState:UIControlStateNormal];
    [_zoomOutBtn setImageEdgeInsets:UIEdgeInsetsMake(16, 10, 17, 10)];
    [_zoomOutBtn addTarget:self action:@selector(zoomOutAction) forControlEvents:UIControlEventTouchUpInside];
    [self bringSubviewToFront:_zoomOutBtn];
    
    [self addSubview:_zoomOutBtn];
    
    return self;
}

- (void)zoomInAction {
    
    if ([_delegator respondsToSelector:@selector(zoomIn)]) {
        
        [_delegator performSelector:@selector(zoomIn)];
    }
}

- (void)zoomOutAction {
    
    if ([_delegator respondsToSelector:@selector(zoomOut)]) {
        
        [_delegator performSelector:@selector(zoomOut)];
    }
}

@end
