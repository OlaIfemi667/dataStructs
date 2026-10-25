CC     = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

test: test_vec
	./test_vec

test_vec: test_vec.c vec.c vec.h
	$(CC) $(CFLAGS) test_vec.c vec.c -o test_vec

clean:
	rm -f test_vec
