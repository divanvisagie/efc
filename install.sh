#!/bin/bash

cp efc /usr/local/bin
mkdir -p /usr/local/man/man1/
install -g 0 -o 0 -m 0644 efc.1 /usr/local/man/man1/
gzip /usr/local/man/man1/efc.1