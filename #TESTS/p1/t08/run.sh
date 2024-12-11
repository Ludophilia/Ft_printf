#! /bin/bash

if [ $# -ne 0 ]; then exit 1; fi

# PRE-COMPILATION

OK="[OK]"
KO="[KO]"
DEBUG_STATUS=0

CC="cc"
CFLAGS="-Wall -Wextra -Werror"
# unset CFLAGS

LFTPF="$LFTPF_DIR/libftprintf.a"
INCL_DIR="$LFTPF_DIR/includes"

CFLAGS+=" -I$LFTPF_DIR"
CFLAGS+=" -I$INCL_DIR"
CFLAGS+=" -DDEBUG=$DEBUG_STATUS"

# PRE-TESTING

MAIN_TITLE="%%x specifier"
TEST_NB="08"

make -sC $LFTPF_DIR bonus

if [ $? -ne 0 ]; then
	printf "Something went wrong with the Makefile";
	exit 1;
fi

# FIRST TEST

PART_NB="00"
SUB_TITLE="$MAIN_TITLE - return values"
NB="$TEST_NB-$PART_NB"

NAME0="t${TEST_NB}p$PART_NB" ; SRCS0="t${TEST_NB}p$PART_NB.c"

$CC $CFLAGS -o $NAME0 $SRCS0 $LFTPF #2> /dev/null

./$NAME0 > /dev/null
if [ $? -ne 0 ]; then exit 1;
else printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\t\t\033[1;32m$OK\033[0m\n"; fi
rm -f $NAME0

# SECOND TEST

PART_NB="01"
SUB_TITLE="$MAIN_TITLE - output comparison"
NB="$TEST_NB-$PART_NB"

SRCS0="t${TEST_NB}p$PART_NB.c";

NAME0="t${TEST_NB}p$PART_NB-0"; NAME1="t${TEST_NB}p$PART_NB-1";

OUT0="orig"; OUT1="ft";

MACR_FLG0="-DPRINTF=printf -DPRINTF_STR=\"printf\""
MACR_FLG1="-DPRINTF=ft_printf -DPRINTF_STR=\"ft_printf\""

$CC $CFLAGS $MACR_FLG0 -o $NAME0 $SRCS0 $LFTPF \
	&& $CC $CFLAGS $MACR_FLG1 -o $NAME1 $SRCS0 $LFTPF

./$NAME0 > $OUT0 && ./$NAME1 > $OUT1

diff $OUT0 $OUT1 2>&1 1>/dev/null

if [ $? -ne 0 ]; then
	printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\t\033[1;41m$KO\033[0m\n"
	exit 1;
else printf "\033[1m$NB\033[0m\t$SUB_TITLE\t\t\033[1;32m$OK\033[0m\n"; fi

rm -f $NAME0 $NAME1 $OUT0 $OUT1

exit 0
