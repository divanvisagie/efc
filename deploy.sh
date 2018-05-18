#!/bin/bash

if git describe --exact-match --tags HEAD
then
    if [[ "$TRAVIS_OS_NAME" = "osx" ]]; then
      brew update;
      brew install sbt;
      brew tap tcnksm/ghr;
      brew install ghr;
    else
      sudo apt-get install -y fakeroot;
      curl -sL -o ~/bin/gimme https://raw.githubusercontent.com/travis-ci/gimme/master/gimme;
      chmod +x ~/bin/gimme;
      go get -u github.com/tcnksm/ghr; 
    fi
    echo "Found tag"
      tag=$(git describe --exact-match --tags HEAD)
    echo "Found tag $tag"
    cp install.sh bin/
    ghr -u divanvisagie $tag bin
else
    echo "Tag not found"
fi