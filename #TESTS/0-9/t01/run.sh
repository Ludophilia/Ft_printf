#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PREPARATION

CC="cc"
CFLAGS="-Wall -Wextra -Werror"
unset CFLAGS

LFTPF_DIR="../../.."
LFTPF="$LFTPF_DIR/libftprintf.a"

DEBUG_STATUS=0

CFLAGS+=" -I$LFTPF_DIR"
CFLAGS+=" -DDEBUG=$DEBUG_STATUS"

make -sC $LFTPF_DIR

# FIRST TEST

NB="01-00"
TITLE="Empty string - return values"
OK_STATUS="[OK]"
NAME0="t01p00"
SRCS0="t01p00.c"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF 2> /dev/null

./$NAME0 > /dev/null
if [ $? -ne 0 ]; then exit 1;
else printf "\033[1m$NB\033[0m\t$TITLE\t\t\t\033[1;32m$OK_STATUS\033[0m\n"; fi
rm $NAME0

# SECOND TEST

NB="01-01"
TITLE="Empty string - output comparison"
OK_STATUS="[OK]"
NAME0="t01p01-0" ; SRCS0="t01p01-0.c" ; OUT0="file0"
NAME1="t01p01-1" ; SRCS1="t01p01-1.c" ; OUT1="file1"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF 2> /dev/null
$CC $CFLAGS -o $NAME1 $SRCS1 $LFTPF 2> /dev/null

./$NAME0 > $OUT0 && ./$NAME0 > $OUT1
diff $OUT0 $OUT1
if [ $? -ne 0 ]; then exit 1;
else printf "\033[1m$NB\033[0m\t$TITLE\t\t\033[1;32m$OK_STATUS\033[0m\n"; fi
rm -f $NAME0 $NAME1 $OUT0 $OUT1

exit 0
