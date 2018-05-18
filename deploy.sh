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
    cp efc.1 bin/
    cd bin
    tar czf efc_$TRAVIS_OS_NAME.tar.gz *
    mkdir ../release
    cp efc_$TRAVIS_OS_NAME.tar.gz ../release/
    cd ..
    ghr -u divanvisagie $tag release
else
    echo "Tag not found"
fi