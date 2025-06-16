// swift-tools-version:5.6

/*
 * SwiftDecoder Swift Package for iOS CaptureSDK
 */

import PackageDescription

let package = Package(
    name: "SwiftDecoderSDK",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "SwiftDecoderSDK",
            targets: [
                "SwiftDecoder"
            ]
        )
    ],
    targets: [
        .binaryTarget(
            name: "SwiftDecoder",
            path: "Sources/SwiftDecoder.xcframework"
        )
    ]
)
