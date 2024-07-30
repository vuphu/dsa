#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_folder>"
    exit 1
fi

SOURCE_FILE="$1/impl.py"

python3 $SOURCE_FILE