import PackageDescription

let package = Package(
    name: "GloVe",
    targets: [
        Target(name: "CGloVe"),
        Target(
            name: "GloVe",
            dependencies: [ "CGloVe" ]
        ),
    ]
)
