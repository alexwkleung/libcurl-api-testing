CXX = gcc
LDFLAGS = -L/usr/local/Cellar/curl/7.85.0/lib -lcurl
CXXFLAGS = -std=c99 -Wall -Wextra -g -I/usr/local/Cellar/curl/7.85.0/include

VAR = main.c
OUT = a.o

.PHONY: build
build: 
	${CXX} ${LDFLAGS} ${CFLAGS} ${VAR} -o ${OUT} && ./${OUT} && rm ${OUT}