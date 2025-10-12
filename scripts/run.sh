#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_folder>"
    exit 1
fi

if ls "$1"/impl.py >/dev/null 2>&1; then
    SOURCE_FILE="$1/impl.py"
    python3 $SOURCE_FILE
fi

if ls "$1"/impl.cpp >/dev/null 2>&1; then
    EXECUTABLE="exec"
    SOURCE_FILE="$1/impl.cpp"
    g++ -std=c++20 -o $EXECUTABLE $SOURCE_FILE

    if [ $? -eq 0 ]; then
        ./$EXECUTABLE
        rm $EXECUTABLE
    else
        echo "Compilation failed."
    fi
fi

if ls "$1"/impl.rs >/dev/null 2>&1; then
    EXECUTABLE="exec"
    SOURCE_FILE="$1/impl.rs"
    rustfmt $SOURCE_FILE
    rustc -o $EXECUTABLE $SOURCE_FILE

    if [ $? -eq 0 ]; then
        ./$EXECUTABLE
        rm $EXECUTABLE
    else
        echo "Compilation failed."
    fi
fi