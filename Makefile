#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -g -Wall -Wextra -Werror

NAME	= testhashmap
INCLUDE	= includes/



#libraries=====================================================================

LIBS	= libft
B_LIBS	= libft_bonus
ARCH	= ft
B_ARCH	= ft_bonus

LIBFT	= libft/libft.a
LIBFT_B	= libft_bonus/libft_bonus.a



#sources=======================================================================

SRCS	= test.c \
		  hashmap/addkey.c \
		  hashmap/djb2.c \
		  hashmap/extend_hashtable.c \
		  hashmap/ft_strcmp.c \
		  hashmap/get.c \
		  hashmap/init_hashtable.c \
		  hashmap/remove_hashtable.c \
		  hashmap/removekey.c

OBJS	= $(SRCS:.c=.o)




	TARGET_OBJS = $(OBJS)
	TARGET_LIB = $(LIBFT)
	TARGET_LIBS = $(LIBS)
	TARGET_ARCH = $(ARCH)

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(TARGET_LIB) $(TARGET_OBJS)
	$(CC) -o $@ $(TARGET_OBJS) $(foreach lib, $(TARGET_LIBS), -L$(lib)) $(foreach arch, $(TARGET_ARCH), -l$(arch))


$(LIBFT) :
	make -C libft




#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
