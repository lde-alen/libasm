/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:20:43 by lde-alen          #+#    #+#             */
/*   Updated: 2025/01/04 15:09:33 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
#define LIBASM_H

/**
    rax is used to store the return value of a function.
    rcx is used as a counter in loops.
    rsp is used to store the stack pointer.
    rbp is used to store the base pointer.
    rdi, rsi, rdx, rcx, r8, r9 are used respectively to pass arguments, vulgarly like function(rdi, rsi, rdx, rcx, r8, r9)
 
    je -> jump if equal
    jne -> jump if not equal

    jz-> jump if null flag found

    mov -> move from a to b
    movzx BYTE[] -> move specific size from a to b and fill remaining with 0

 */

// Reset
# define COLOR_OFF "\033[0m"       //Text Reset

//Regular
# define BLACK "\033[0;30m"        // Black
# define RED "\033[0;31m"          // Red
# define GREEN "\033[0;32m"        // Green
# define YELLOW "\033[0;33m"       // Yellow
# define BLUE "\033[0;34m"         // Blue
# define PURPLE "\033[0;35m"       // Purple
# define CYAN "\033[0;36m"         // Cyan
# define WHITE "\033[0;37m"        // White

// Bright
# define BBLACK "\033[1;30m"       //Black
# define BRED "\033[1;31m"         //Red
# define BGREEN "\033[1;32m"       //Green
# define BYELLOW "\033[1;33m"      //Yellow
# define BBLUE "\033[1;34m"        //Blue
# define BPURPLE "\033[1;35m"      //Purple
# define BCYAN "\033[1;36m"        //Cyan
# define BWHITE "\033[1;37m"       //White


# ifdef __linux__
    # define READ 0
    # define WRITE 1
    # define OPEN 2
# else
    # define READ 0x2000003
    # define WRITE 0x2000004
# endif

// # define BUFFER_SIZE 10000

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <time.h>

int			ft_strlen(char *str);
char		*ft_strcpy(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
ssize_t		ft_write(unsigned int fd, const char *str, size_t len);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(const char *s);

#endif