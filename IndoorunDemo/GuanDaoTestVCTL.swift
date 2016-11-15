//
//  GuanDaoTestVCTL.swift
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

import UIKit

class GuanDaoTestVCTL: UIViewController, IDRMapViewDelegate, IDRLocationServerDelegate {

    var _region:IDRRegion?
    
    private var _mapView:IDRMapView?
    
    var _newPoints:IDRPosition?
    
    var _locator = IDRLocationServer()
    
    var _start = false
    
    @IBOutlet weak var _label:UILabel?

    override func viewDidLoad() {
        
        super.viewDidLoad()

        setupMapView()
        
        _locator.delegate = self
    }
    
    func setupMapView() -> Void {
        
        _mapView = IDRMapView()
        
        _mapView?.delegate = self
        
        _mapView?.loadMap(_region, floor: _region?.defaultFloor())
        
        self.view.addSubview(_mapView!)
        
        self.view.sendSubview(toBack: _mapView!)
        
        _mapView?.addDefaultFloorListView()
        
        _mapView?.addDefaultMapModeBtn()
    }
    
    //MARK:IDRMapView delegate
    func mapview(_ mapView: IDRMapView!, onClickMap pos: IDRPosition!) {
        
        if _start {
            
            return
        }
        
        _start = true
        
        let marker = IDRStartMarker()
        
        marker.pos = pos
        
        _newPoints = IDRPosition(x: pos.x, y: pos.y, floor: pos.floorId)
        
        _locator.start(_region)
        
        _mapView?.addMarker(marker)
        
        _locator.useWalkFilter = true
        
        _locator.delegate = self
        
        _locator.startPos = pos
        
        _locator.timeInterval = 300
    }
    
    //MARK:IDRLocationServer delegate
    func location(_ locationServer: IDRLocationServer!, didLocationSuccess userLocation: IDRUserLocation!) {
        
        let line = IDRLine(start: _newPoints!, end: userLocation.pos)
        
        _mapView?.glesMap.addCollect(line, color: 0x44444444)
        
        _newPoints = IDRPosition(x: userLocation.pos.x, y: userLocation.pos.y, floor: userLocation.pos.floorId)
        
        let stepCount = IDRWalkInsManager.sharedInstance().getStepCount()
        
        let walkDistance = IDRWalkInsManager.sharedInstance().getWalkDistance()
        
        _label?.text = "步数:\(stepCount) 行走距离:\(walkDistance)"
    }
}
