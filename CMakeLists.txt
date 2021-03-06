cmake_minimum_required(VERSION 3.15)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -L -lft")
include_directories(includes)
include_directories(libft/includes)

add_executable(ft_printf
        includes/unixtime.h
        includes/colors.h
        includes/funfortypes.h
        includes/libft.h
        includes/libftprintf.h
        libft/includes/libft.h
        libft/free_table.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_itoa.c
        libft/ft_itoabase.c
        libft/ft_itoahex.c
        libft/ft_lstadd.c
        libft/ft_lstadd_back.c
        libft/ft_lstdel.c
        libft/ft_lstdelone.c
        libft/ft_lstfind.c
        libft/ft_lsti.c
        libft/ft_lstiter.c
        libft/ft_lstlast.c
        libft/ft_lstmap.c
        libft/ft_lstmerge.c
        libft/ft_lstnew.c
        libft/ft_lstqsort.c
        libft/ft_lstremove_if.c
        libft/ft_lstreverse.c
        libft/ft_lstsize.c
        libft/ft_lstswap.c
        libft/ft_memalloc.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memcpy.c
        libft/ft_memdel.c
        libft/ft_memmove.c
        libft/ft_memset.c
        libft/ft_putchar.c
        libft/ft_putchar_fd.c
        libft/ft_putendl.c
        libft/ft_putendl_fd.c
        libft/ft_putnbr.c
        libft/ft_putnbr_fd.c
        libft/ft_putstr.c
        libft/ft_putstr_fd.c
        libft/ft_qsort.c
        libft/ft_strcat.c
        libft/ft_strchr.c
        libft/ft_strclr.c
        libft/ft_strcmp.c
        libft/ft_strcpy.c
        libft/ft_strdel.c
        libft/ft_strdup.c
        libft/ft_strequ.c
        libft/ft_striter.c
        libft/ft_striteri.c
        libft/ft_strjoin.c
        libft/ft_strlcat.c
        libft/ft_strlen.c
        libft/ft_strmap.c
        libft/ft_strmapi.c
        libft/ft_strncat.c
        libft/ft_strncmp.c
        libft/ft_strncpy.c
        libft/ft_strnequ.c
        libft/ft_strnew.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_swap_char.c
        libft/ft_swap_int.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_itoa_signed.c
        libft/ft_stradd_back.c
        libft/ft_stradd_front.c
        libft/get_next_line.c
        libft/ft_strreplace.c
        libft/ft_strcat_front.c
        libft/ft_strcut.c
        libft/ft_itoadouble.c
        srcs/fun_length.c
        srcs/funtypes_cdx_upx_o.c
        srcs/funtypes_sf_percent.c
        srcs/funtypes_ubp.c
        srcs/precision.c
        srcs/flag_hash.c
        srcs/bonus_star.c
        srcs/set_precision_width.c
        srcs/get_flag_sign.c
        srcs/length_bonus.c
        srcs/main.c
        srcs/type_color.c
        srcs/type_unixtime.c
        srcs/unixtime.c
        srcs/parse.c
        srcs/fun_flags.c
        srcs/placeholder.c
        srcs/printf.c)
