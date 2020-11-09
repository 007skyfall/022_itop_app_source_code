#./demo_prj_v3/demo/Makefile
 
MODULE = demo
SUB_SRCS_DIR = $(TOP_DIR)/$(MODULE)/source
SUB_OBJS_DIR = $(OBJS_DIR)/$(MODULE)
 
INCLUDE += 
 
SUB_ALL_SRCS := $(notdir $(wildcard $(SUB_SRCS_DIR)/*.c))   #wildcard展开所有的.c文件 notdir只保留文件名，路径名去掉
SUB_TMP_OBJS := $(SUB_ALL_SRCS:.c=.o)  #所有的.c替换成.o
SUB_ALL_OBJS := $(addprefix $(SUB_OBJS_DIR)/, $(SUB_TMP_OBJS)) #addprefix加前缀
 
all: $(OBJS_DIR)/$(MODULE).o
 
$(OBJS_DIR)/$(MODULE).o: $(SUB_ALL_OBJS)
	$(ECHO) Linking $(MODULE).o...
	$(LD) -r -o $@ $(SUB_ALL_OBJS)
 
$(SUB_OBJS_DIR)/%.o: $(SUB_SRCS_DIR)/%.c
	$(ECHO) Compiling $(notdir $<)...
	$(shell [ -d $(SUB_OBJS_DIR) ] || mkdir -p $(SUB_OBJS_DIR))   
	$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<

