SUB_DIRS = public lib demo  #替换目录
ALL_SRCS = $(foreach dir,$(SUB_DIRS),$(wildcard $(dir)/*.c)) #foreach用来循环  wildcard把所有.c文件都展开
ALL_OBJS = $(ALL_SRCS:.c=.o) #所有的.c替换成.o
INCLUDE = -I./public -I./lib -I./demo

CFLAGS = -g

.PHONY: all clean $(SUB_DIRS)

all:demo_app

demo_app:$(ALL_OBJS)
	@echo Build demo_prj start...
	gcc $(ALL_OBJS) -o $@
	@echo Done!!!

%.o:%.c
	@echo "Compiling $<..."
	gcc $(INCLUDE) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(shell find ./ -name "*.o")
	@rm -rf demo_app
	@echo Clean demo_prj over!!!
