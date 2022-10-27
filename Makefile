CPP=g++

INC=include
CFLAGS= -g -Wall -Wextra -Werror  -ofast
NAME=main
SRC_FILES = main.cpp Sommet.cpp  Arete.cpp Graphe.cpp GC.cpp
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(patsubst %.cpp, %.o, $(SRCS))


all: clean $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ -I./$(INC)

clean:
	rm -f $(OBJS) $(NAME)
