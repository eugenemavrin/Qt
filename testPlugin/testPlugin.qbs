import qbs

Project {
    property path sourcePath: path + "/src"

    minimumQbsVersion: "1.6.0"

    qbs.installPrefix: ""

    references: [
        "plugin/plugin.qbs",
        "src/src.qbs"
    ]

}
