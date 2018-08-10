#!/bin/bash

# Usage:
#   ./build_ios.sh /path/to/model/directory

dir_resolve()
{
if [[ -d $1 ]]; then
    cd "$1" 2>/dev/null || return $?
    echo "`pwd -P`"
else
    cd "`dirname "$1"`"
    echo "`pwd -P`/`basename "$1"`"
fi
}

if [ ! -n "$1" ]; then
    echo "No graph directory specified - using ../models/"
    FOLDER=`dir_resolve "../models"`
else
    FOLDER=`dir_resolve $1`
fi

if [[ -d $FOLDER ]]; then
    LIST=`find "$FOLDER" -name "*.pb" | paste -sd "," -`
elif [[ -f $FOLDER ]]; then
    LIST="$FOLDER"
else
    echo "No file found: $FOLDER"
    exit 1
fi

tensorflow/contrib/makefile/build_all_ios.sh -T -g "$LIST"
