import os

from conans import ConanFile, tools
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps


class CustomerTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy('*.so*', dst='bin', src='lib')

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        if not tools.cross_building(self.settings):
            self.run(f".{os.sep}example")

