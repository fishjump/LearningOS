#!/bin/bash

find include -name *.*pp | xargs clang-format -i
find src -name *.*pp | xargs clang-format -i