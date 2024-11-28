#! /bin/bash

NAME="test01"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"

SRCS="t01.c"

LFTPF_DIR="../../.."
LFTPF="$LFTPF_DIR/libftprintf.a"

if [ $# -ne 0 ]; then
	return 1;
fi

make -s -C $LFTPF_DIR 
$CC $CFLAGS -I$LFTPF_DIR -o $NAME $SRCS $LFTPF
./$NAME


