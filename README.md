# efc
[![Build Status](https://travis-ci.org/divanvisagie/efc.svg?branch=master)](https://travis-ci.org/divanvisagie/efc)

Elder Futhark Converter

A text converter for the elder futhark,designed as a linux/unix command and a performant successor to runify.

```sh
Usage: efc [options] [arguments]

  Options:
    --phonetic  Replace phonetic sounds such as th with ᚦ
    --reverse   Convert Elder Futhark to Latin
    --version   Output version
    --help      Output help
```



## Building 

Cmake is used for building the program, run the following to get started quickly

```sh
cmake .
make
```

This will output the binary to `./bin/efc`

## License

GPLv2