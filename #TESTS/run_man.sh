#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

cd 0-9

for i in {0..5}; do
	cd t0$i
	./run.sh
	cd ..
done

exit 0
