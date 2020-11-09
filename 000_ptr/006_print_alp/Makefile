CC=gcc 
OBJ=print_alp
OBJS=print_alp.c 
CFLAGS= -Wall -g -static 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o print_alp
