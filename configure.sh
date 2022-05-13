#! /bin/sh

cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build # docs disabled to make the build time faster
