CC=gcc 
STRIP=strip
OBJ=test_mkdir
OBJS=test_mkdir.c 
CFLAGS= -Wall -g -lm 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	$(STRIP) $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o test_mkdir
