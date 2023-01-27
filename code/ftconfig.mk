# -----------------------------------------------------------
# File: ftconfig.mk
# Created Date: Tuesday, January 24th 2023, 8:18:37 am
# Author: mvtta
# Last Modified: 
# Modified By: 
# Dependency of : Makefile
# “Au moment même où tout est perdu, tout est possible” - Levinas
# Copyright (c) 2023 knowledge is free
# -----------------------------------------------------------

#for gfx is test compiling : gcc src/init.c src/dft.c lib/libgfx/gfx.c inc/ft_visu.h lib/libgfx/gfx.h -I -lmlx -lm -lXext -lX11 -o ./dft
#
#now for minilix
# gcc -g src/init.c lib/minilibx/libmlx_Linux.a -I -lmlx -lXext -lX11 -o ./ft_test
#   179  ./ft_test 





EXEC 		= ./fouriertrans
IROOT		= inc/
L1			= lib/minilibx/
SROOT		= src/

SRC 		:= $(shell find $(SROOT) -name '*.c')
BROOT 		= bin/
OROOT		= obj/
OBJ 		= $(patsubst %.c,%.o,${SRC:%.c})
_DEPS 		= inc/ft_visu.h

CC			= gcc
# LINKLIBFT	= -L${L1}/bin -lft
# LINKBIM	= -L${L2}/bin -lbim
# LINKVEC	= -L${L3}/bin -lvec
LINKMLX		= -L${L1}/ -lmlx -lX11 -lXext
LINKFLAGS	= ${LINKMLX} #${LINKLIBFT} ${LINKBIM} ${LINKVEC}
CFLAGS		= -g -fsanitize=address -lm #-Werror -Wall -Wextra 
LIBS		= libmlx_Linux.a libmlx.a


-I /usr/X11/include -g -L /USR/X11/LIB -LX11 -LMLX -LXEXT
# *****************************************************************************
# * verbose
# ****************************************************************************

WELCOME = "Transforming..."                                  

SEP = ********************************************************************