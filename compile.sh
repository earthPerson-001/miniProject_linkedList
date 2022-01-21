#! /bin/sh

gcc -fdiagnostics-color=always \
    -g ./src/linkedList.c ./src/consoleColors.c \
    -o ./build/linkedlist \
    -I ./include \

build/linkedlist