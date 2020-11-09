CC=gcc 
STRIP=strip
OBJ=test_uart_open
OBJS=test_uart_open.c 
CFLAGS= -Wall -g -lm 
$(OBJ):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	$(STRIP) $@
$*.o:$%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
.PHONY:clean
clean:
	$(RM) *.o test_uart_open
