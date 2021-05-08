//
//  MapViewController.swift
//  GetFit
//
//  Created by iosdev on 17.4.2021.
//

import UIKit
import heresdk
import CoreLocation
import Foundation



class MapViewController: UIViewController, PlatformPositioningProviderDelegate {
    
    func onLocationUpdated(location: CLLocation) {
        mapView.camera.setTarget(GeoCoordinates(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude))
        mapView.camera.setZoomLevel(15)
        
        func createMapCircle() -> MapCircleLite {
            let geoCircle = GeoCircle(center: GeoCoordinates(latitude: location.coordinate.latitude, longitude: location.coordinate.longitude),
                                      radiusInMeters: 10)
            let mapCircleStyle = MapCircleStyleLite()
            mapCircleStyle.setFillColor(0xFF908AC0, encoding: .rgba8888)
            let mapCircle = MapCircleLite(geometry: geoCircle, style: mapCircleStyle)
            
            return mapCircle
        }
        let mapCircle = createMapCircle()
        let mapScene = mapView.mapScene
        mapScene.addMapCircle(mapCircle)
        
    }
    
    
    var platforPositioningProvider = PlatformPositioningProvider()
    
    
    var mapView: MapViewLite!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        platforPositioningProvider.delegate = self
        platforPositioningProvider.startLocating()
        
        
        
        // Initialize MapViewLite without a storyboard.
        mapView = MapViewLite(frame: view.bounds)
        view.addSubview(mapView)
        
        
        mapView.mapScene.loadScene(mapStyle: .normalDay, callback: onLoadScene)
        
    }
    
    func convertLocation(nativeLocation: CLLocation) -> Location {
        let geoCoordinates = GeoCoordinates(latitude: nativeLocation.coordinate.latitude,
                                            longitude: nativeLocation.coordinate.longitude,
                                            altitude: nativeLocation.altitude)
        var location = Location(coordinates: geoCoordinates,
                                timestamp: nativeLocation.timestamp)
        location.bearingInDegrees = nativeLocation.course < 0 ? nil : nativeLocation.course
        location.speedInMetersPerSecond = nativeLocation.speed < 0 ? nil : nativeLocation.speed
        location.horizontalAccuracyInMeters = nativeLocation.horizontalAccuracy < 0 ? nil : nativeLocation.horizontalAccuracy
        location.verticalAccuracyInMeters = nativeLocation.verticalAccuracy < 0 ? nil : nativeLocation.verticalAccuracy
        
        
        return location
    }
    
    
    
    func onLoadScene(errorCode: MapSceneLite.ErrorCode?) {
        if let error = errorCode {
            print("Error: Map scene not loaded, \(error)")
        } else {
            // Configure the map.
            mapView.camera.setTarget(GeoCoordinates(latitude: 60.1699, longitude: 24.9384))
            mapView.camera.setZoomLevel(10)
        }
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        mapView.handleLowMemory()
    }
    
    
    
}

public protocol PlatformPositioningProviderDelegate {
    func onLocationUpdated(location: CLLocation)
}


// A simple iOS based positioning implementation.
class PlatformPositioningProvider : NSObject,
                                    CLLocationManagerDelegate {
    
    var delegate: PlatformPositioningProviderDelegate?
    private let locationManager = CLLocationManager()
    
    func startLocating() {
        if locationManager.delegate == nil {
            locationManager.delegate = self
            locationManager.desiredAccuracy = kCLLocationAccuracyBest
            locationManager.requestAlwaysAuthorization()
        }
    }
    
    func stopLocating() {
        locationManager.stopUpdatingLocation()
    }
    
    // Conforms to the CLLocationManagerDelegate protocol.
    func locationManager(_ manager: CLLocationManager,
                         didChangeAuthorization status: CLAuthorizationStatus) {
        switch status {
        case .restricted, .denied, .notDetermined:
            print("Positioning denied by user.")
            break
        case .authorizedWhenInUse, .authorizedAlways:
            print("Positioning authorized by user.")
            locationManager.startUpdatingLocation()
            break
        default:
            break
        }
    }
    
    // Conforms to the CLLocationManagerDelegate protocol.
    func locationManager(_ manager: CLLocationManager,
                         didFailWithError error: Error) {
        if let error = error as? CLError, error.code == .denied {
            print("Positioning denied by user.")
            manager.stopUpdatingLocation()
        }
    }
    
    // Conforms to the CLLocationManagerDelegate protocol.
    func locationManager(_ manager: CLLocationManager,
                         didUpdateLocations locations: [CLLocation]) {
        guard let lastLocation = locations.last else {
            print("Warning: No last location found")
            return
        }
        
        delegate?.onLocationUpdated(location: lastLocation)
    }
    
    
    
}

