CROSS_COMPILE ?= 
CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++

TOP_DIR := $(shell pwd)
BUILD_DIR := $(TOP_DIR)/build
BIN_DIR := $(BUILD_DIR)/bin
OBJS_DIR := $(BUILD_DIR)/objs

$(shell [ -d ${BUILD_DIR} ] || mkdir -p ${BUILD_DIR} && mkdir -p ${BIN_DIR} && mkdir -p ${OBJS_DIR})

SUB_DIRS = public lib demo
ALL_SRCS = $(foreach dir,$(SUB_DIRS),$(wildcard $(dir)/*.c))
TMP_OBJS = $(notdir $(patsubst %.c,%.o,$(ALL_SRCS))) #patsubst把.c文件替换成.o文件,notdir只保留文件名，去掉路径
ALL_OBJS = $(addprefix $(OBJS_DIR)/,$(TMP_OBJS)) #addprefix加前缀函数

INCLUDE = -I./public -I./lib -I./demo

CFLAGS = -g

.PHONY: all clean $(SUB_DIRS)

all: $(BIN_DIR)/demo_app

$(BIN_DIR)/demo_app:$(ALL_OBJS)
	@echo Build demo_prj start...
	$(CC) $(ALL_OBJS) -o $@
	@echo Done!!!

$(ALL_OBJS):$(ALL_SRCS)
	@echo "Compiling $(filter %$(*F).c,$(ALL_SRCS))..." #filter过滤函数
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $(filter %$(*F).c,$(ALL_SRCS))

clean:
	@rm -rf $(shell find ./ -name "*.o")
	@rm -rf $(BIN_DIR)/demo_app
	@echo Clean demo_prj over!!!
