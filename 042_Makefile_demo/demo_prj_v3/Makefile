# ---------------------------------------------------------------------------
#                   
#                           Make for demo
#                       
# ---------------------------------------------------------------------------
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
 
#export CC LD
 
# shell命令，这样可以做到全局可控
ECHO = @echo
MKDIR = mkdir -p
RM = @rm -rf
MAKE = make -j# -j支持并行编译
 
export ECHO MKDIR RM
 
# ---------------------------------------------------------------------------
# Compiler dir_env define
# ---------------------------------------------------------------------------
TOP_DIR := $(shell pwd)
BUILD_DIR := $(TOP_DIR)/build
BIN_DIR := $(BUILD_DIR)/bin
OBJS_DIR := $(BUILD_DIR)/objs
# Attempt to create a output target directory.
$(shell [ -d ${BUILD_DIR} ] || $(MKDIR) ${BUILD_DIR} && $(MKDIR) ${OBJS_DIR} && $(MKDIR) ${BIN_DIR})
 
export TOP_DIR OBJS_DIR
 
# ---------------------------------------------------------------------------
# OBJS include the necessary directories and the source files 
# ---------------------------------------------------------------------------
SUB_DIRS = public lib demo
ALL_OBJS = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SUB_DIRS))) #addprefix加前缀函数   addsuffix加后缀函数 
INCLUDE = -I$(TOP_DIR)/public/include \
          -I$(TOP_DIR)/lib/include \
          -I$(TOP_DIR)/demo/include
 
export INCLUDE #把该变量传递给下一级目录

CFLAGS = -g
 
.PHONY: all clean $(SUB_DIRS)
 
all: $(BIN_DIR)/demo_app
 
$(BIN_DIR)/demo_app: $(SUB_DIRS)
	$(ECHO) Build demo_prj start...
	$(CC) $(ALL_OBJS) -o $@
	$(ECHO) Done!!!
 
#$(ALL_OBJS): $(SUB_DIRS)

$(SUB_DIRS):
	$(MAKE) -C $@ #嵌套执行Makefie,执行下一级目录下的Makefile
 
clean:
	$(RM) $(shell find ./ -name "*.o")
	$(RM) $(BIN_DIR)/demo_app
	$(ECHO) clean demo_prj over... 
                                          

