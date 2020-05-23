import qbs

CppApplication {
    consoleApplication: true
    Depends { name: "Qt"; submodules: ["core"] }
    Depends { name: "cpp"}
    cpp.staticLibraries: [
        path + "/modules/libqtcjson.a"
    ]

    files: [
        "main.cpp",
        "modules/json.h"
    ]

    Group {
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
