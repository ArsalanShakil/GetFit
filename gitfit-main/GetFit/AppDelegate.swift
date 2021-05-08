//
//  AppDelegate.swift
//  GetFit
//
//  Created by iosdev on 13.4.2021.
//

import UIKit
import CoreData
import MOPRIMTmdSdk
import Firebase
import FirebaseFirestore

@main
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    
    
    //configure moprim api
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        FirebaseApp.configure()
        _ = Firestore.firestore()
        
        
        // Configure the app to trigger Background Fetch events as regularly as possible.
        UIApplication.shared.setMinimumBackgroundFetchInterval(UIApplication.backgroundFetchIntervalMinimum)
        
        // Declare your API Key and Endpoint:
        let myKey = "eu-central-1:cb996483-fd29-4a79-912e-9d9eff9af4f2"
        let myEndpoint = "https://1t0mp83yg7.execute-api.eu-central-1.amazonaws.com/metro2021/v1"
        
        // Initialize the TMD:
        TMD.initWithKey(myKey, withEndpoint: myEndpoint, withLaunchOptions: launchOptions).continueWith { (task) -> Any? in
            if let error = task.error {
                NSLog("Error while initializing the TMD SDK: %@", error.localizedDescription)
                
            }
            else {
                // Get the app's installation id:
                
                
                
                print("Successfully initialized the TMD with id %@", task.result ?? "<nil>")
                
                
                
                
            }
            return task;
        }
        return true
        
        
    }
    
    
    // MARK: UISceneSession Lifecycle
    
    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }
    
    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }
    
    // MARK: - Core Data stack
    
    lazy var persistentContainer: NSPersistentContainer = {
        /*
         The persistent container for the application. This implementation
         creates and returns a container, having loaded the store for the
         application to it. This property is optional since there are legitimate
         error conditions that could cause the creation of the store to fail.
         */
        let container = NSPersistentContainer(name: "GetFit")
        container.loadPersistentStores(completionHandler: { (storeDescription, error) in
            if let error = error as NSError? {
                // Replace this implementation with code to handle the error appropriately.
                // fatalError() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
                
                /*
                 Typical reasons for an error here include:
                 * The parent directory does not exist, cannot be created, or disallows writing.
                 * The persistent store is not accessible, due to permissions or data protection when the device is locked.
                 * The device is out of space.
                 * The store could not be migrated to the current model version.
                 Check the error message to determine what the actual problem was.
                 */
                fatalError("Unresolved error \(error), \(error.userInfo)")
            }
        })
        return container
    }()
    
    func application(_ application: UIApplication, handleEventsForBackgroundURLSession identifier: String, completionHandler: @escaping () -> Void) {
        TMD.application(application, handleEventsForBackgroundURLSession: identifier, completionHandler: completionHandler)
    }
    
    func application(_ application: UIApplication, performFetchWithCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
        // Run our background operations
        TMD.backgroundFetch().continueWith (block: { (task) -> Void in
            let tmdFetchResult:UIBackgroundFetchResult = UIBackgroundFetchResult(rawValue: (task.result!.uintValue))!
            // Call the completion handler with the UIBackgroundFetchResult returned by TMD.backgroundFetch(), or with your own background fetch result
            completionHandler(tmdFetchResult)
        })
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        TMD.applicationWillTerminate()
    }
    
    // MARK: - Core Data Saving support
    
    func saveContext () {
        let context = persistentContainer.viewContext
        if context.hasChanges {
            do {
                try context.save()
            } catch {
                // Replace this implementation with code to handle the error appropriately.
                // fatalError() causes the application to generate a crash log and terminate. You should not use this function in a shipping application, although it may be useful during development.
                let nserror = error as NSError
                fatalError("Unresolved error \(nserror), \(nserror.userInfo)")
            }
        }
    }
    
}

