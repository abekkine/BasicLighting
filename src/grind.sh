#!/bin/bash

valgrind \
    --log-file=vg.log \
    --leak-check=full \
    ./lights.bin