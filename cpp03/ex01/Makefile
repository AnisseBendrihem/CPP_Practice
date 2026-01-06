# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/06 13:50:38 by abendrih          #+#    #+#              #
#    Updated: 2026/01/06 14:54:03 by abendrih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ScavTrap

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp

OBJS		=	$(SRCS:.cpp=.o)

HEADERS		=	ClapTrap.hpp \
				ScavTrap.hpp

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp $(HEADERS)
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
