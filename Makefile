SRCS			=	./main.cpp 

OBJS			= 	$(SRCS:.c=.o)

LIBS			= 	-L ./yaml-cpp -lyaml-cpp -I./yaml-cpp/include

CC				= 	g++
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror

NAME			= 	taskmaster

all:			$(NAME)

$(NAME):		$(OBJS)
				g++ $(CFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus