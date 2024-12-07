#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PREPARATION

export LFTPF_DIR="../../..";

# TESTING

cd p0

for i in {00..10}; do
	cd t$i
	./run.sh
	cd ..
done

exit 0
