#parameters====================================================================

CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -g -Wall -Wextra -Werror

NAME	= testhashmap



#sources=======================================================================

SRCS	=	test.c \
			hashmap/addkey.c \
			hashmap/djb2.c \
			hashmap/extend_hashtable.c \
			hashmap/get.c \
			hashmap/hash_memset.c \
			hashmap/hash_strcmp.c \
			hashmap/hash_strdup.c \
			hashmap/init_hashtable.c \
			hashmap/remove_hashtable.c \
			hashmap/removekey.c

OBJS	= $(SRCS:.c=.o)

TARGET_OBJS = $(OBJS)

#rules=========================================================================

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CC) -o $@ $(TARGET_OBJS)

#const options=================================================================

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean :
	rm -f $(OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all
