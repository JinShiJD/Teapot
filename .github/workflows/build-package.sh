#!/bin/bash

set -e
set -x  # Enable detailed logging

# Clean previous build
rm -rf build/
mkdir -p build/

# Build your Qt project
qmake teapot.pro -o build/
make -C build/

# Create debian package structure
mkdir -p build/DEBIAN

# Create control file (adjust with your package metadata)
cat << EOF > build/DEBIAN/control
Package: Teapot
Version: 1.1.1
Architecture: amd64  # Adjust architecture as per your project
Maintainer: JinShiJD <2282575601@qq.com>
Depends: qt5-default, other-dependencies
Description: Short description of your Qt package
 Long description of your Qt package
EOF

# Install your Qt project into the correct directories within build/
# Example: cp -r bin/ build/usr/bin

# Build the package
dpkg-deb --build build/
