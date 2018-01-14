SRC_DIR = ./src
INC_DIR = ./includes
OBJ_DIR = ./obj
BIN_DIR = ./bin

CC = gcc
_OBJS = life.o calculate.o lifedisplay.o nextgen.o
OBJS = $(patsubst %, $(OBJ_DIR)/%, $(_OBJS))
_SRCS = $(patsubst %.o, %.c, $(_OBJS))
SRCS = $(patsubst %, $(SRC_DIR)/%, $(_SRCS))
CFLAGS = -g -I$(INC_DIR)
LDFLAGS = -lm

all: $(BIN_DIR)/gameoflife

$(BIN_DIR)/gameoflife: $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

dependencies: $(SRCS)
	$(CC) -I$(INC_DIR) -MM $^ | sed '/^.*.o:/ s#^#$(OBJ_DIR)/#' > $@

include dependencies
