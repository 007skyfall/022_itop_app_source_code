CC=gcc 
STRIP=strip
OBJ=test_read
OBJS=test_read.c 
CFLAGS= -Wall -g -lm 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	$(STRIP) $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o test_read testwrite 
