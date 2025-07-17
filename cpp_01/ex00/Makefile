SRCS = newZombie.cpp Zombie.cpp randomChump.cpp  main.cpp

OBJS = ${SRCS:.cpp=.o}

NAME = zombie

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
RESET = \033[0m

all: ${NAME}

${NAME}: ${OBJS}
	@echo "${GREEN}Linking ${NAME}...${RESET}"
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}
	
%.o: %.cpp
	@echo "${YELLOW}Compiling $<...${RESET}"
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${RESET}"
	${RM} ${OBJS}

fclean: clean
	@echo "${RED}Cleaning executable...${RESET}"
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re