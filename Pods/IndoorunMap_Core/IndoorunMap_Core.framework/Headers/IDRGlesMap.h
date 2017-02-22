//
//  IDRMapProtocal.h
//  IndoorunMap_Core
//
//  Created by ky on 12/01/2017.
//  Copyright © 2017 yellfun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDRMapView.h"
#import "IDRMapMarker.h"

@class IDRNaviSuggestion;
@class IDRUnit;

@interface IDRGlesMap : UIView

- (instancetype)initWithFrame:(CGRect)frame;

- (void)setMap:(NSString*)mapFile name:(NSString*)name size:(CGSize)size;

- (void)rotate:(CGFloat)angle;

- (void)scale:(CGFloat)scale anim:(CGFloat)animTime;

- (void)translate:(CGFloat)x y:(CGFloat)y anim:(BOOL)anim;

- (void)zoomFit;

- (void)addUnits:(NSArray*)units floor:(NSInteger)floorIndex;

- (void)setUserLocation:(IDRPosition*)pos show:(BOOL)show;

- (void)updateMarker:(id<IDRMapMarkerProtocal>)overlay;

- (void)addMarker:(id<IDRMapMarkerProtocal>)overlay;

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

- (void)resetMapRotate;

- (void)launching;

- (CGFloat)mapScale;

- (void)forceRoute:(BOOL)force;

- (void)showCompress:(bool)show;

- (NSInteger)addCollectLine:(IDRLine*)line color:(int)color;

- (void)removeLine:(NSInteger)Id;

- (NSInteger)addLabel:(NSString*)text color:(int)color pos:(CGPoint)p;

- (void)removeLabel:(NSInteger)Id;

- (NSInteger)findLine:(CGPoint)screenPoint;

- (void)selectLine:(NSInteger)lineId color:(int)color;

- (void)moveToPos:(CGPoint)point;

- (void)clear;

- (IDRNaviSuggestion*)getNavStatus;

- (void)onTouch:(NSInteger)type point1:(CGPoint)p1 piont2:(CGPoint)p2;

- (CGFloat)mapRoatation;

- (void)pause;

- (void)resume;

- (CGFloat)mapWidth;

- (CGFloat)mapHeight;

- (void)updateUnitsColor:(NSArray<IDRUnit*>*)units;

- (void)clearPolys;

- (void)setBackColor:(UIColor*)color;

- (void)showRouteDirectLine:(BOOL)show;

@property (nonatomic, assign) BOOL visible;

@property (nonatomic, assign) BOOL enable;

@property (nonatomic, assign) CGPoint anchor;

@property (nonatomic, assign) CGFloat azimuth;

@property (nonatomic, assign) BOOL pauseRender;

@property (nonatomic, weak) IDRMapView *mapView;

@end
