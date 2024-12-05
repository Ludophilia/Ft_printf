#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PREPARATION

CC="cc"
CFLAGS="-Wall -Wextra -Werror"

LFTPF_DIR="../../.."
LFTPF="$LFTPF_DIR/libftprintf.a"

DEBUG_STATUS=0

CFLAGS+=" -I$LFTPF_DIR"
CFLAGS+=" -DDEBUG=$DEBUG_STATUS"

make -sC $LFTPF_DIR

# FIRST TEST

NB="00-00"
TITLE="Null check, return values"
OK_STATUS="[OK]"
NAME0="t00p00" ; SRCS0="t00p00.c"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF

./$NAME0 > /dev/null
if [ $? -ne 0 ]; then exit 1;
else printf "\033[1m$NB\033[0m\t$TITLE\t\t\t\033[1;32m$OK_STATUS\033[0m\n"; fi
rm -f $NAME0

exit 0
