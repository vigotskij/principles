#!/bin/bash

## Borro el directorio bin si ya existiera
if [ -d "./bin" ];
    then rm -r ./bin;
fi

## Creo el directorio para los binarios
mkdir ./bin/

## Compilo todo
g++ -Wall -std=c++11 -ldl main.cpp -o ./bin/main.bin
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Application/Application.cpp -o ./bin/Application.so
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/ConsoleGreeter/ConsoleGreeter.cpp -o ./bin/Greeter.so

## Otorgo permisos de escritura al ejecutable
chmod +x ./bin/main.bin


