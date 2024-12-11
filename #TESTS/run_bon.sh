#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PREPARATION

export LFTPF_DIR="../../..";

# BONUS PART

cd p1

for i in {05..05}; do
	cd t$i
	./run.sh
	cd ..
done

cd ..

exit 0
