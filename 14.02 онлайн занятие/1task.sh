#!/usr/bin/env bash

set -Eeuo pipefail

read n

read -a arr

pred="${arr[0]}"
echo -n "$pred"

for (( i = 1; i < n; i++ )); do
    curr="${arr[$i]}"
    if [ "$curr" != "$pred" ]; then
        echo -n " $curr"
    fi
    pred="$curr"
done

echo
