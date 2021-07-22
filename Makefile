SRCS		= ft_itoa.c ft_printf.c ft_ultoa.c ft_writout.c 		
INCS		= ft_printf.h
OBJS        = $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
CC		= cc -c
RM		= rm -f
AR		= ar rcs 

$(NAME):	$(OBJS) $(INCS)
			$(AR) $(NAME) $(OBJS)
		
all:	$(NAME)

%.o: %.c
		$(CC) -o $@ $< $(CFLAGS)
so:
		$(CC) -fPIC $(CFLAGS) $(SRCS)
		gcc -shared -o libftprintf.so $(OBJS)
cleanso:
		$(RM) *.o
		$(RM) libftprintf.so
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all


.PHONY: 	all clean fclean re .c.o cleanso so 
