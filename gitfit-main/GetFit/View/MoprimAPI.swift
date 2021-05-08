//
//  File.swift
//  GetFit
//
//  Created by iosdev on 1.5.2021.
//

import Foundation
import MOPRIMTmdSdk
import CoreMotion
import CoreLocation

class MoprimAPI : NSObject, CLLocationManagerDelegate{
    override init() {
        super.init()
        self.askLocationPermissions()
        self.askMotionPermissions()
        TMD.start()
        self.createSyntheticData()
    }
    
    var delegate:MoprimAPIDelegate?
    
    let locationManager = CLLocationManager()
    
    let motionActivityManager = CMMotionActivityManager()
    
    
    
    func askMotionPermissions() {
        if CMMotionActivityManager.isActivityAvailable() {
            self.motionActivityManager.startActivityUpdates(to: OperationQueue.main) { (motion) in
                print("received motion activity")
                self.motionActivityManager.stopActivityUpdates()
            }
        }
    }
        
    func askLocationPermissions() {
            self.locationManager.delegate = self
            self.locationManager.requestAlwaysAuthorization()
        
        
        }
        
    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        if #available(iOS 14.0, *) {
                let preciseLocationAuthorized = (manager.accuracyAuthorization == .fullAccuracy)
                if preciseLocationAuthorized == false {
                    manager.requestTemporaryFullAccuracyAuthorization(withPurposeKey: "tmd.AccurateLocationPurpose")
                    // Note that this will only ask for TEMPORARY precise location.
                    // You should make sure to ask your user to keep the Precise Location turned on in the Settings.
                }
            } else {
                // No need to ask for precise location before iOS 14
            }
        }
    
    func fetchData(){
        let date = Date()
        TMDCloudApi.fetchData(date, minutesOffset: 0).continueWith { (task) -> Any? in
            DispatchQueue.main.async {
                // Execute your UI related code on the main thread
                
                if let error = task.error {
                    NSLog("fetchData Error: %@", error.localizedDescription)
                }
                else if let data = task.result {
                    self.delegate?.fetchMoprimData(data: data)
                    NSLog("fetchData result: %@", data)
                }
                return
            }
        }
    }
    
    func statsData(){
        TMDCloudApi.fetchStats(forLast: 365).continueOnSuccessWith { (task) -> Any? in
                    DispatchQueue.main.async {
                        // Execute your UI related code on the main thread
        
                        if let error = task.error {
                            NSLog("fetchStats Error: %@", error.localizedDescription)
                        }
                        else if let data = task.result {
                            NSLog("fetchStats result: %@", data.allStats())
        
                        }
                    }
                }
    }
    
    func createSyntheticData() {
        // Karaportti, Espoo
        let origin = CLLocation(latitude: 60.2238542, longitude: 24.7586268)
        // Leppävaara, Espoo
        let destination = CLLocation(latitude: 60.2166658, longitude: 24.8166634)
        // Helsinki
        // let destination = CLLocation(latitude: 60.16, longitude: 24.93)
        let endTime = Int64((Date().timeIntervalSince1970 * 1000.0).rounded()) + 3600000
        
        TMDCloudApi.generateSyntheticData(withOriginLocation: origin, destination: destination, stopTimestamp: endTime, requestType: TMDSyntheticRequestType.bicycle, hereApiKey: "gbQoL3WzflRncLCfxFdNb2Fy7mLp53dWvlnNAdMI9zc")
    }
    
    
    
    
}
//TODO: MAKE A STRUCT FOR CORE DATA
//struct moprimData {}

protocol MoprimAPIDelegate{
    func fetchMoprimData(data:NSArray)
    
}
