# -----------------------------------------------------------
# File: /Makefile
# Created Date: Tuesday, January 24th 2023, 8:18:37 am
# Author: mvtta
# Last Modified: 
# Modified By: 
# Depends on: ftconfig.mk
# "I... a universe of atoms, an atom in the universe." - RF
# Copyright (c) 2023 knowledge is free
# -----------------------------------------------------------

CONFIG = ftconfig.mk
include $(CONFIG)

${EXEC}: ${LIBS} $(OBJ)	
	mkdir -p ${BROOT}
	$(CC) $(CFLAGS) ${LINKFLAGS} -I${IROOT} ${SRC} -o ${OBJ} ${EXEC}
	mv $@ $(BROOT)

${LIBS}:
	make -C lib/minilibx
$(OBJ):
	mkdir -p ${OROOT}

all : ${EXEC}

.o:%.c
	$(CC) $(CFLAGS) $(OBJ) -c $<

clean :
	@rm -f $(O_EXEC)
	@printf "clean\n"

fclean : clean
	@rm -rf $(BROOT)
	@rm -rf $(OROOT)
	@printf "clean bin and obj root\n"
	@rm -f $(EXEC) $(LIBFT)
	@printf "clean exec and lib\n"
	@printf "clean done\n"


re : fclean all

.PHONY: all clean fclean re

$(V).SILENT:
