import qbs

DynamicLibrary {
    files: [
        "plugin.cpp",
        "plugin.h"
    ]
    name: "plugin"

    Depends { name: "cpp" }
    Depends { name: "Qt"; submodules: ["core"] }

    cpp.cxxLanguageVersion: "c++14"

    cpp.includePaths: [
        project.sourcePath
    ]

    install: true
    installDir: "bin/Plugins"
}
