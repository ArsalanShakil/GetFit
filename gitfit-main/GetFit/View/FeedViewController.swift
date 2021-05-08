//
//  FeedViewController.swift
//  GetFit
//
//  Created by iosdev on 14.4.2021.
//

import UIKit
import MOPRIMTmdSdk
import CoreMotion
import CoreLocation



class FeedViewController: UIViewController, CLLocationManagerDelegate {
    let locationManager = CLLocationManager()
    let motionActivityManager = CMMotionActivityManager()
    private var activities: [TMDActivity] = []
    private var currentDate: Date = Date()
    
    
    @IBOutlet weak var yourActivityLabel: UILabel!
    @IBOutlet weak var weeklyEmissions: UILabel!
    @IBOutlet weak var stepsLabel: UILabel!
    
    @IBOutlet weak var weeklyActivityLabel: UILabel!
    @IBOutlet weak var weeklyActivityStepsLabel: UILabel!
    @IBOutlet weak var weeklyActivityDistanceLabel: UILabel!
    @IBOutlet weak var weeklyActivityEmissionLabel: UILabel!
    @IBOutlet weak var progressBarSteps: UIProgressView!
    @IBOutlet weak var progressBarRun: UIProgressView!
    @IBOutlet weak var runLabel: UILabel!
    @IBOutlet weak var weeklySteps: UILabel!
    @IBOutlet weak var weeklyDistance: UILabel!
    
    @IBOutlet weak var workoutButtonLabel: UIButton!
    
    @IBOutlet weak var startTrackingButtonLabel: UIButton!
    @IBOutlet weak var startTrackingButtonLabel2: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
        yourActivityLabel.text = "Your Activity".localized()
        weeklyActivityLabel.text = "Weekly Activity".localized()
        weeklyActivityStepsLabel.text = "Steps:".localized()
        weeklyActivityDistanceLabel.text = "Distance:".localized()
        weeklyActivityEmissionLabel.text = "CO2 emissions:".localized()
        workoutButtonLabel.setTitle("workout".localized(), for: .normal)
        startTrackingButtonLabel.setTitle("start tracking".localized(), for: .normal)
        startTrackingButtonLabel2.setTitle("start tracking".localized(), for: .normal)
        
        TMD.start()
        
        askMotionPermissions()
        askLocationPermissions()
        
        progressBarRun.setProgress(0.0, animated: true)
        progressBarSteps.setProgress(0.0, animated: true)
        
        
        
        // Karaportti, Espoo
        let origin = CLLocation(latitude: 60.2238542, longitude: 24.7586268)
        // Leppävaara, Espoo
        let destination = CLLocation(latitude: 60.2166658, longitude: 24.8166634)
        // Helsinki
        // let destination = CLLocation(latitude: 60.16, longitude: 24.93)
        let endTimeFetch = Int64((Date().timeIntervalSince1970 * 1000.0).rounded()) + 3600000
        
        TMDCloudApi.generateSyntheticData(withOriginLocation: origin, destination: destination, stopTimestamp: endTimeFetch, requestType: TMDSyntheticRequestType.bicycle, hereApiKey: "gbQoL3WzflRncLCfxFdNb2Fy7mLp53dWvlnNAdMI9zc")
        
        
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy/MM/dd HH:mm"
        let DateTime = Date(timeIntervalSinceNow: -670740)
        print("time", DateTime)
        
        TMDCloudApi.fetchData(withStart: 0000000000000, withEnd: 9999999999999).continueWith { (task) -> Any? in
            DispatchQueue.main.async {
                // Execute your UI related code on the main thread
                if let error = task.error {
                    NSLog("fetchData Error: %@", error.localizedDescription)
                }
                else if let data = task.result {
                    var stepsCounter = 0.0
                    NSLog("fetchData result: %@", data)
                    
                    for trip in data {
                        let trip = trip as! TMDActivity
                        print("DATA: activityId: \(trip.activityId), timestampDownload: \(trip.timestampDownload), timestampStart: \(trip.timestampStart), timestampEnd: \(trip.timestampEnd), timestampUpdate: \(trip.timestampUpdate), correctedActivity: \(trip.correctedActivity), originalActivity: \(trip.originalActivity), co2: \(trip.co2), distance: \(trip.distance), speed: \(trip.speed), polyline: \(trip.polyline), origin: \(trip.origin), destination: \(trip.destination), metadata: \(trip.metadata), verifiedByUser: \(trip.verifiedByUser), syncedWithCloud: \(trip.syncedWithCloud)")
                        
                        stepsCounter = stepsCounter + trip.distance
                        self.stepsLabel.text = String(Int(stepsCounter/1.2))
                        self.runLabel.text = String(Int(stepsCounter/1.3))
                        
                        self.progressBarRun.setProgress(1, animated: true)
                        self.progressBarSteps.setProgress(1, animated: true)
                        self.progressBarSteps.tintColor = UIColor(red: 0.93, green: 0.78, blue: 0.29, alpha: 1.00)
                        self.progressBarRun.tintColor = UIColor(red: 0.93, green: 0.78, blue: 0.29, alpha: 1.00)
                    }
                }
                
            }
        }
        
        TMDCloudApi.fetchStats(forLast: 7).continueOnSuccessWith { (task) -> Any? in
            DispatchQueue.main.async {
                // Execute your UI related code on the main thread
                if let error = task.error {
                    NSLog("fetchStats Error: %@", error.localizedDescription)
                }
                else if let data = task.result {
                    NSLog("fetchStats result: %@", data)
                    var weeklySteps = 0.0
                    var weeklyDistance = 0.0
                    var weeklyCO2 = 0.0
                    
                    
                    for statistic in data.allStats() {
                        print("STATS: activity: \(statistic.activity), userCo2: \(statistic.userCo2), userDistance: \(statistic.userDistance), userDuration: \(statistic.userDuration), userLegs: \(statistic.userLegs), communityCo2: \(statistic.communityCo2), communityDistance: \(statistic.communityDistance), communityDuration: \(statistic.communityDuration), communityLegs: \(statistic.communityLegs), communitySize: \(statistic.communitySize), dateString: \(statistic.dateString)")
                        
                        weeklySteps = weeklySteps + statistic.userDistance
                        self.weeklySteps.text = String(Int(weeklySteps/1.2))
                        
                        weeklyDistance = weeklyDistance + statistic.userDistance
                        self.weeklyDistance.text = "\(String(Int(weeklyDistance/1000)))km"
                        
                        weeklyCO2 = weeklyCO2 + statistic.userCo2
                        self.weeklyEmissions.text = String(Int(weeklyCO2))
                    }
                }
            }
        }
        
        
        
        
    }
    
    
    @IBAction func startTracking(_ sender: UIButton) {
        performSegue(withIdentifier: "openMap", sender: self)
        
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
    
    
    
    func askMotionPermissions() {
        if CMMotionActivityManager.isActivityAvailable() {
            self.motionActivityManager.startActivityUpdates(to: OperationQueue.main) { (motion) in
                print("received motion activity")
                self.motionActivityManager.stopActivityUpdates()
            }
        }
    }
    
    
}

extension String {
    func localized() -> String {
        return NSLocalizedString(self, tableName: "Localizable", bundle: .main, value: self, comment: self)
    }
}
