#!/bin/bash

if git describe --exact-match --tags HEAD
then
    echo "Found tag"
      tag=$(git describe --exact-match --tags HEAD)
    echo "Found tag $tag"
    cp install.sh bin/
    ghr -u divanvisagie $tag bin
else
    echo "Tag not found"
fi