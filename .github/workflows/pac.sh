#!/bin/bash

# 安装构建依赖
sudo apt-get update
sudo apt-get install -y build-essential

# 构建项目
./configure
make

# 创建deb包
sudo checkinstall -D --install=no --pkgname=my-package --pkgversion=1.0 --maintainer="2282575601@qq.com" --default
