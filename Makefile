# Reset
Color_Off='\033[0m'       # Text Reset

# Regular
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

# Bright
BBlack='\033[1;30m'       # Black
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BYellow='\033[1;33m'      # Yellow
BBlue='\033[1;34m'        # Blue
BPurple='\033[1;35m'      # Purple
BCyan='\033[1;36m'        # Cyan
BWhite='\033[1;37m'       # White


NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s	\
		ft_strcmp.s	\
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s	\

OBJS = $(SRCS:.s=.o)

NASM = nasm
NASMFLAGS = -f macho64

CC = gcc

ifeq ($(shell uname -m), arm64)
	CC += -ld_classic --target=x86_64-apple-darwin
endif

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "${GREEN}+ $(NAME)${Color_Off}"

%.o: %.s
	@$(NASM) $(NASMFLAGS) $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "${Red}- $(OBJS)${Color_Off}"

fclean: clean
	@rm -f $(NAME)
	@rm -f test.txt
	@rm -rf main
	@echo "${Red}- $(NAME)${Color_Off}"

re: fclean all

ut: all
	@$(CC) $(CFLAGS) $(NAME) main.c -L. -lasm -o main && ./main

.PHONY: all clean fclean re