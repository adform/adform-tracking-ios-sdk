//
//  AppDelegate.swift
//  DemoApp
//
//  Created by Marius iTo on 2020-09-09.
//  Copyright © 2020 Adform. All rights reserved.
//

import UIKit
import AdformTracking

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.

        let trackingPointId = 123123 // Tracking point id provided to you by Adform.
        AdformTrackingSDK.sharedInstance().setAppName("DemoApp")
        AdformTrackingSDK.sharedInstance().startTracking(trackingPointId, waitForPermissions: true)
        if #available(iOS 14.0, *) {
            AdformTrackingSDK.sharedInstance().requestTrackingPermissions()
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


}

