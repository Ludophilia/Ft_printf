#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PRE-COMPILATION

OK="[OK]"
KO="[KO]"
DEBUG_STATUS=0

CC="cc"
CFLAGS="-Wall -Wextra -Werror"
unset CFLAGS

LFTPF_DIR="../../.."
LFTPF="$LFTPF_DIR/libftprintf.a"

CFLAGS+=" -I$LFTPF_DIR"
CFLAGS+=" -DDEBUG=$DEBUG_STATUS"

# PRE-TESTING

MAIN_TITLE="Format string with no %%"
TEST_NB="02"

make -sC $LFTPF_DIR

if [ $? -ne 0 ]; then exit 1 ; printf "Something went wrong the Makefile" ; fi

# FIRST TEST

PART_NB="00"
SUB_TITLE="$MAIN_TITLE - return values"
NB="$TEST_NB-$PART_NB"

NAME0="t${TEST_NB}p$PART_NB" ; SRCS0="t${TEST_NB}p$PART_NB.c"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF 2> /dev/null

./$NAME0 > /dev/null
if [ $? -ne 0 ]; then exit 1;
else printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\t\033[1;32m$OK\033[0m\n"; fi
rm -f $NAME0

# SECOND TEST

PART_NB="01"
SUB_TITLE="$MAIN_TITLE - output comparison"
NB="$TEST_NB-01"

NAME0="t${TEST_NB}p$PART_NB-0" ; SRCS0="t${TEST_NB}p$PART_NB-0.c" 
	SRCS0+=" t${TEST_NB}p$PART_NB-main.c" ; OUT0="file0"
NAME1="t${TEST_NB}p$PART_NB-1" ; SRCS1="t${TEST_NB}p$PART_NB-1.c"
	SRCS1+=" t${TEST_NB}p$PART_NB-main.c" ; OUT1="file1"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF 2> /dev/null \
	&& $CC $CFLAGS -o $NAME1 $SRCS1 $LFTPF 2> /dev/null

./$NAME0 > $OUT0 && ./$NAME1 > $OUT1

diff $OUT0 $OUT1

if [ $? -ne 0 ]; then
	printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\033[1;41m$KO\033[0m\n"
	exit 1;
else printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\033[1;32m$OK\033[0m\n"; fi
rm -f $NAME0 $NAME1 $OUT0 $OUT1

exit 0
