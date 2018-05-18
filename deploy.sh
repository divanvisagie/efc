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
    cp bin/efc release/
    cd release
    tar czf efc-$TRAVIS_OS_NAME-$tag.tar.gz *
    mkdir ../pkg
    cp efc-$TRAVIS_OS_NAME-$tag.tar.gz ../pkg/
    cd ..
    ghr -u divanvisagie $tag pkg
else
    echo "Tag not found"
fi