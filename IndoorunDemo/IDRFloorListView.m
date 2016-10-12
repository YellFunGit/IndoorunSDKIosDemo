//
//  FloorListView.m
//  YellFunCars
//
//  Created by Sincere on 15/7/14.
//  Copyright (c) 2015年 Sincere. All rights reserved.
//

#import "IDRFloorListView.h"
#import "UIColor+YFHexColor.h"

@interface IDRFloorListView(){
    
    UIView  * _redDotView;
    BOOL      isOk;
    IDRFloor * _lastFloor;
}

@property (nonatomic, retain) IDRFloor    * currentFloor;
@property (nonatomic, retain) IDRFloor    * locatedFloor;

@end
@implementation IDRFloorListView

- (instancetype)initWithFloors:(NSArray*)floor origionX:(CGFloat)x origionY:(CGFloat)y
{
    if (self=[super init]) {
        
        _floors=floor;
        _isShown = NO;
        _isShownEnable = YES;
        [self setUserInteractionEnabled:YES];
        self.frame=CGRectMake(x, y, 34, 36 + floor.count*36);
        self.backgroundColor = [UIColor clearColor];
        IDRFloor * defaultFloor = _floors[0];
        
        _button = [UIButton buttonWithType:UIButtonTypeCustom];
        [_button setBackgroundImage:[UIImage imageNamed:@"YF_FloorNormal.png"] forState:UIControlStateNormal];
        [_button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
        [_button setBackgroundImage:[UIImage imageNamed:@"YF_FloorSelected.png"] forState:UIControlStateSelected];
        [_button setTitleColor:[UIColor whiteColor] forState:UIControlStateSelected];
        [_button setBackgroundColor:[UIColor clearColor]];
        [_button setFrame:CGRectMake(0, 0, 34, 34)];
        [_button addTarget:self action:@selector(buttonClick:) forControlEvents:UIControlEventTouchUpInside];
        [_button.titleLabel setText:defaultFloor.title];
        [_button setTitle:defaultFloor.title forState:UIControlStateNormal];
        [_button setTitle:defaultFloor.title forState:UIControlStateSelected];
        [_button.titleLabel setFont:[UIFont systemFontOfSize:13.0f]];
        [self addSubview:_button];
        
        _table=[[UITableView alloc] initWithFrame:CGRectMake(0, 36, 34, 0) style:UITableViewStylePlain];
        [_table setDelegate:self];
        [_table setDataSource:self];
        [_table setScrollEnabled:NO];
        [_table setBackgroundColor:[UIColor clearColor]];
        [[_table layer] setCornerRadius:2.0f];
        [self addSubview:_table];
        
        _redDotView = [[UIView alloc] initWithFrame:CGRectMake(26, 14, 4, 4)];
        [_redDotView setBackgroundColor:[UIColor redColor]];
        _redDotView.layer.cornerRadius = 2.0f;
        [_redDotView setUserInteractionEnabled:YES];
        [_redDotView setAlpha:0.0f];
        [self addSubview:_redDotView];
    }
    return self;
}

- (void)buttonClick:(UIButton*)senser
{
    if (!_isShownEnable)
    {
        return;
    }
    
    if (!_floors || _floors.count<=1) {
        UIAlertView * alert = [[UIAlertView alloc] initWithTitle:nil message:@"该建筑物只有一层楼" delegate:nil cancelButtonTitle:@"ok" otherButtonTitles:nil,nil];
        [alert show];
        return;
    }

    if (senser.selected == NO) {
        
        [self showFloor];
    }
    else{
        
        [self disMissFloor];
    }
        
}

-(void)setCurrentFloor:(IDRFloor *)currentFloor {
    
    _currentFloor  = currentFloor;
    
    _lastFloor = _currentFloor;
    
    [_button setTitle:currentFloor.title forState:UIControlStateNormal];
    
    [_button setTitle:currentFloor.title forState:UIControlStateSelected];
    
    [_table reloadData];
    
    if ([_currentFloor equalFloor:_locatedFloor]) {
        
        [self showRedDotView];
    }
    else {
        
        [self disMissRedDotView];
    }
}

- (void)setLocatedFloor:(IDRFloor *)locatedFloor
{
    _locatedFloor = locatedFloor;
    
    if ([_currentFloor equalFloor:_locatedFloor]) {
        
        [self showRedDotView];
    }
    else {
        
        [self disMissRedDotView];
    }
    
    [_table reloadData];
}

- (void)showFloor
{
    [self setIsShown:YES];
    
    _button.selected = !_button.selected;
    
    CGRect rect = CGRectMake(self.frame.origin.x, self.frame.origin.y, self.frame.size.width, self.frame.size.height+35*_floors.count);
 
    [UIView animateWithDuration:0.5f animations:^{
        
        [self setFrame:rect];
        
        [_table setFrame:CGRectMake(0, 34, 34, 35*_floors.count)];
        
    } completion:nil];
}

- (void)disMissFloor
{
    [self setIsShown:NO];
    
     _button.selected = !_button.selected;
    
    CGRect rect = CGRectMake(self.frame.origin.x, self.frame.origin.y, self.frame.size.width, self.frame.size.height - 35 * _floors.count);
    
    [UIView animateWithDuration:0.5f animations:^{
        
        [self setFrame:rect];
        
        [_table setFrame:CGRectMake(0, 34, 34, 0)];
    }];
}

- (void)showRedDotView
{
    if (_redDotView.alpha == 1) {
        return;
    }
    [UIView animateWithDuration:0.5 animations:^{
        [_redDotView setAlpha:1.0f];
    }];
}

- (void)disMissRedDotView
{
    if (_redDotView.alpha == 0) {
        return;
    }
    
    [UIView animateWithDuration:0.5 animations:^{
        [_redDotView setAlpha:0];
    }];
}

- (void)exchangeFloors:(NSArray*)floors
{
    [self setFloors:floors];
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;
}

- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView
{
    if (!_floors || _floors.count == 0) {
        
        return 0;
    }
    
    return _floors.count;
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell* cell=[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cell"];
    [cell setBackgroundColor:[UIColor clearColor]];
    
    IDRFloor * floor=_floors[indexPath.section];
    
    UILabel * label=[[UILabel alloc] initWithFrame:CGRectMake(0, 0, 34, 34)];
    [label setText:floor.title];
    [label setTextAlignment:NSTextAlignmentCenter];
    [label setTextColor:[UIColor ColorWithHex:@"ffffff"]];
    [label setBackgroundColor:[UIColor clearColor]];
    [label setFont:[UIFont systemFontOfSize:12.f]];
    [cell addSubview:label];
    [label setClipsToBounds:YES];
    cell.contentView.alpha = 0.9;
    
    for (UIView * redDow in [cell.contentView subviews])
    {
        if (redDow.tag == 8080)
        {
            [redDow removeFromSuperview];
        }
    }
    if ([[_currentFloor title] isEqualToString:[floor title]])
    {
        cell.contentView.backgroundColor = [UIColor ColorWithHex:@"148CFF"];
    }else{
        cell.contentView.backgroundColor = [UIColor blackColor];
    }
    
    if ([[_locatedFloor title] isEqualToString:[floor title]]) {
        UIView * redDotView = [[UIView alloc] initWithFrame:CGRectMake(26, 14, 4, 4)];
        [redDotView setBackgroundColor:[UIColor redColor]];
        redDotView.layer.cornerRadius = 2.0f;
        [redDotView setUserInteractionEnabled:YES];
        cell.tag = 8080;
        [cell.contentView addSubview:redDotView];
    }
 
    return cell;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 34;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 2;
}

- (UIView*)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    UIView * view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 34, 2)];
    [view setBackgroundColor:[UIColor clearColor]];
    return view;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.section >= _floors.count) {
        
        return;
    }
    
    NSInteger index = indexPath.section;
    
    IDRFloor * selectedFloor = [_floors objectAtIndex:index];
    
    [_mapView setAutoChangeToUserFloor:NO];
    
    BOOL changeSuccess = [_mapView changeFloor:selectedFloor];
    
    if (isOk && changeSuccess)
    {
        [_button setTitle:selectedFloor.title forState:UIControlStateNormal];
        
        [_button setTitle:selectedFloor.title forState:UIControlStateSelected];
    }
    
    UITableViewCell* cell = [tableView cellForRowAtIndexPath:indexPath];
    
    cell.contentView.backgroundColor  = [UIColor ColorWithHex:@"148CFF"];
    
    [tableView reloadData];
    
    [self disMissFloor];
}

@end
