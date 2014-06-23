#!/bin/bash

lcov -o report.info -c -d .

genhtml -o report --no-branch-coverage report.info

pushd .

cd report

chromium-browser ./index.html