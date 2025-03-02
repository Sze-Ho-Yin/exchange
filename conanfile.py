# This file is managed by Conan, contents will be overwritten.

from conan import ConanFile

class ConanApplication(ConanFile):
    package_type = "application"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        requirements = self.conan_data.get('requirements', [])
        for requirement in requirements:
            self.requires(requirement)

    def build_requirements(self):
        self.tool_requires("cmake/3.28.1")
