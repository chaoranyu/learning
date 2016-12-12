#!/bin/bash

message="Hello"

if test "$message" = "Hello"; then
	echo "Hello World"
fi

if [ "$message" = "Hello" ]; then
	echo "Hello World"
fi

if [[ $message == "Hello" ]]; then
	echo "Hello World"
fi
