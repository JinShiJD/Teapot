#!/bin/bash

set -e
set -x  # Enable detailed logging

# Clean previous build
rm -rf build/
mkdir -p build/

# Specify the path to your .pro file
PRO_FILE="teapot/teapot.pro"

# Build your Qt project
qmake $PRO_FILE -o build/
make -C build/

# Create debian package structure
mkdir -p build/DEBIAN

# Create control file (adjust with your package metadata)
cat << EOF > build/DEBIAN/control
Package: teapot
Version: 1.1.1
Architecture: amd64  # Adjust architecture as per your project
Maintainer: JinShiJD <2282575601@qq.com>
Depends: qt5-default, freeglut3, other-dependencies
Description: Teapot Qt application
 Long description of your Qt package
EOF

# Install your Qt project into the correct directories within build/
# Example: cp -r bin/ build/usr/bin

mkdir -p build/usr/local/bin
cp build/teapot build/usr/local/bin/

# Build the package
dpkg-deb --build build/ teapot-qt-1.0.deb

# List the contents of the current directory to verify the .deb file
ls -la
