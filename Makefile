#!/bin/bash

all:
	g++ src/*.cpp -o sortbooks -Wall -Wextra -pedantic -std=c++11

clean:
	rm sortbooks
