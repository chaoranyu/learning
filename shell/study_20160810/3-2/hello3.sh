#!/bin/bash

if grep "Hello" /tmp/tmp0 >/dev/null 2>&1; then
	echo "Hello World"
fi

grep "Hello" /tmp/tmp0 >/dev/null 2>&1
rc=$?
if [[ $rc -eq 0 ]]; then
	echo "Hello World"
fi
