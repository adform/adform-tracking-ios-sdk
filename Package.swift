// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "AdformTracking",
    platforms: [
        .iOS(.v9)
    ],
    products: [
        .library(
            name: "AdformTracking",
            targets: ["AdformTracking", "AdformTrackingDependencies"]
        )
    ],
    dependencies: [
        .package(name: "ProtocolBuffers", url: "https://github.com/adform/protobuf-ios", .upToNextMajor(from: "3.11.5")),
    ],
    targets: [
        .binaryTarget(
            name: "AdformTracking",
            path: "AdformTracking.xcframework"
        ),
        .target(
            name: "AdformTrackingDependencies",
            dependencies: ["ProtocolBuffers"],
            path: "ProtocolBuffersWrapper"
        )
    ]
)
