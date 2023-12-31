SRCS			=	./main.cpp ./utils.cpp

OBJS			= 	$(SRCS:.cpp=.o)

LIBS			= 	

CC				= 	g++
RM				= 	rm -f
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++11 $(LIBS)

NAME			= 	taskmaster

all:			$(NAME)

$(NAME):		$(OBJS)
				g++ $(CPPFLAGS) -g3 -o $(NAME) $(OBJS) $(LIBS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(OBJS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus