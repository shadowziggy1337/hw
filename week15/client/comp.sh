#!/bin/bash

cd /clusterfs/larionov/week15/client
mkdir -p build
cd build
cmake ..
make