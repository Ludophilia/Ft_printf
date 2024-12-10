#! /bin/bash

NAME="ft_printf"

CC="cc"
CFLAGS=""

INCL_DIR="includes"
SRCS_DIRM="srcs"
SRCS_DIRB="srcs_bonus"

SRCS_M="$SRCS_DIRM/main.c"

SRCS_B="$SRCS_DIRB/main_bonus.c"

if [ $# -eq 0 ] || [ $1 = "all" ]; then
	make -s all
	$CC $SRCS_M -o $NAME -L. -lftprintf -I$INCL_DIR
elif [ $1 = "bonus" ]; then
	make -s bonus
	$CC $SRCS_B -o $NAME -L. -lftprintf -I$INCL_DIR
elif [ $1 = "clean" ]; then
	make -s clean
elif [ $1 = "fclean" ]; then
	make -s fclean
	rm -f $NAME
else
	echo "Invalid option"
	exit 1
fi
