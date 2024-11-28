#! /bin/bash

NAME="test00"

CC="cc"
CFLAGS="-Wall -Wextra -Werror"

SRCS="t00.c"

LFTPF_DIR="../../.."
LFTPF="$LFTPF_DIR/libftprintf.a"

if [ $# -neq 0 ]; then
	return 1;
fi

make -s -C $LFTPF_DIR 
$CC $CFLAGS -I$LFTPF_DIR -o $NAME $SRCS $LFTPF
./$NAME


