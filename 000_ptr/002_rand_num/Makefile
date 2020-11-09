CC=gcc 
OBJ=rand_num
OBJS=rand_num.c 
CFLAGS= -Wall -g -static 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o rand_num
