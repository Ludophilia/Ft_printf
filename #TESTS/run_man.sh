#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PREPARATION

export LFTPF_DIR="../../..";

# TESTING

cd 0-9

for i in {0..6}; do
	cd t0$i
	./run.sh
	cd ..
done

exit 0
