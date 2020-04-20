#!/bin/bash

g++ -std=c++14 main.cpp zdarzenie.cpp zdarzenie.h jednostka.cpp jednostka.h centrala.cpp centrala.h
rm *.gch
./a.out

