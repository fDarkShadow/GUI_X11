from conans import ConanFile, CMake, tools

class GUI_X11(ConanFile):
    name = "GUI_X11"
    version = "0.0.1"
    license = "None"
    url = "None"
    description = "Library to integrate X11 in modern C++"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "txt"
    exports_sources = "src/*", "include/*", "CMakeLists.txt"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.hpp", dst="include", src="include")