CC=gcc 
OBJ=alp_num
OBJS=alp_num.c 
CFLAGS= -Wall -g -static 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o alp_num
