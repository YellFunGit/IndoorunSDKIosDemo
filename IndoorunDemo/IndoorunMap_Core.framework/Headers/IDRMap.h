//
//  MapRender.h
//  TestOpengles
//
//  Created by ky on 8/8/16.
//  Copyright © 2016 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRMapMarker.h"
#import "IDRLine.h"

@class IDRNaviSuggestion;
@class IDRMapView;

@interface IDRMap : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void)setMap:(NSString*)mapFile size:(CGSize)size;

- (void)rotate:(CGFloat)angle;

- (void)scale:(CGFloat)scale anim:(CGFloat)animTime;

- (void)translate:(CGFloat)x y:(CGFloat)y;

- (void)zoomFit:(NSInteger)type;

- (void)addUnits:(NSArray*)units;

- (void)setUserLocation:(CGPoint)pos show:(BOOL)show;

- (void)updateMarker:(id<IDRMapMarkerProtocal>)overlay;

- (NSInteger)addMarker:(id<IDRMapMarkerProtocal>)overlay;

- (void)removeMarker:(id<IDRMapMarkerProtocal>)overlay;

- (NSInteger)findMarker:(CGPoint)screenPos;

- (CGPoint)getScreenPos:(CGPoint)mapPos;

- (CGPoint)getMapPos:(CGPoint)screenPos;

- (void)showNaviPath:(NSArray*)points show:(BOOL)show;

- (void)birdView;

- (void)centerPos:(IDRPosition*)pos;

- (CGPoint)mapCenter;

- (void)setMapMode:(int)mapMode navi:(BOOL)navi;

- (void)zoomIn;

- (void)zoomOut;

- (void)resetAnchor;

- (void)launching;

- (void)forceRoute:(BOOL)force;

- (void)showCompress:(bool)show;

- (NSInteger)addCollectLine:(IDRLine*)line color:(int)color;

- (NSInteger)addLabel:(NSString*)text color:(int)color pos:(CGPoint)p;

- (void)removeLabel:(NSInteger)Id;

- (NSInteger)findLine:(CGPoint)screenPoint;

- (void)selectLine:(NSInteger)lineId color:(int)color;

- (void)moveToPos:(CGPoint)point;

- (void)clear;

- (IDRNaviSuggestion*)getNavStatus;

- (void)onTouch:(NSInteger)type point1:(CGPoint)p1 piont2:(CGPoint)p2;

- (CGFloat)mapRoatation;

@property (nonatomic, assign) CGPoint anchor;

@property (nonatomic, assign) CGFloat azimuth;

@property (nonatomic, weak) IDRMapView *mapView;

@end
