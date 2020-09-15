//
//  ViewController.swift
//  DemoApp
//
//  Created by Marius iTo on 2020-09-09.
//  Copyright © 2020 Adform. All rights reserved.
//

import UIKit
import AdformTracking

class ViewController: UIViewController {

    let trackingPointId = 123123

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func sendOrder() {

        let order = AFOrder()

        order.currency = "currency"
        order.orderStatus = "order status"
        order.email = "email"
        order.firstName = "First Name"
        order.lastName = "Last Name"
        order.orderId = "order id"
        order.address1 = "address 1"
        order.address2 = "address 2"
        order.phone = "phone"
        order.basketSize = 7
        order.zip = "zip"
        order.country = "country"
        order.ageGroup = "age group"
        order.gender = "gender"
        order.sale = 44.54

        // You can also set other custom variables.

        order.setCustomVariable("var1", forKey: 1)
        order.setSystemVariable("sysVar1", forKey: 1)
        order.setNumericSystemVariable(123, forKey: 1)

        // Creating tracking point with order and sending, can customize names

        let trackingPoint = AFTrackPoint(trackPoint: trackingPointId)
        trackingPoint.setAppName("CustomAppName")
        trackingPoint.setSectionName("SectionName")
        trackingPoint.setOrder(order)

        AdformTrackingSDK.sharedInstance().send(trackingPoint)
    }

    @IBAction func sendProduct() {

        let product = AFProduct(categoryName: "Category name",
                                categoryId: "Category ID",
                                productName: "Product name",
                                productId: "Product ID",
                                weight: 1,
                                step: 1,
                                productSales: 1,
                                productCount: 1,
                                custom: "Custom information")

        let trackingPoint = AFTrackPoint(trackPoint: trackingPointId)
        trackingPoint.setSectionName("SectionName")
        trackingPoint.addProduct(product)

        AdformTrackingSDK.sharedInstance().send(trackingPoint)
    }

    @IBAction func sendMultipleProducts() {

        let product1 = AFProduct(categoryName: "Category name",
                                 categoryId: "Category ID",
                                 productName: "Product name",
                                 productId: "Product ID",
                                 weight: 1,
                                 step: 1,
                                 productSales: 1,
                                 productCount: 1,
                                 custom: "Custom information")

        let product2 = AFProduct(categoryName: "Category name",
                                 categoryId: "Category ID",
                                 productName: "Product name",
                                 productId: "Product ID",
                                 weight: 1,
                                 step: 1,
                                 productSales: 1,
                                 productCount: 1,
                                 custom: "Custom information")

        let trackingPoint = AFTrackPoint(trackPoint: trackingPointId)
        trackingPoint.setSectionName("SectionName")
        trackingPoint.setProducts([product1, product2])

        AdformTrackingSDK.sharedInstance().send(trackingPoint)

    }

    @IBAction func sendMultipleTrackingPoints() {

        let trackPointBuilder = AFTrackPointsBuilder()

        // Set custom ids
        trackPointBuilder.trackPointIds = [123456, 123123, 234234]

        // Customize information for points
        trackPointBuilder.sectionName = "Custom trackpoint"
        trackPointBuilder.applicationName = "Custom application name"

        // Create order and set it
        let order = AFOrder()
        order.currency = "currency"
        order.orderStatus = "order status"
        order.email = "email"
        order.orderId = "order id"

        trackPointBuilder.order = order

        // Create trackpoints
        let trackingPoints = trackPointBuilder.build()

        // Send trackpoints.
        AdformTrackingSDK.sharedInstance().send(trackingPoints)
    }
}

