CC     = gcc
CFLAGS = -Wall -Wextra -g -fsanitize=address,undefined

test: test_ht
	./test_ht

test_vec: test_ht.c ht.c ht.h
	$(CC) $(CFLAGS) test_ht.c ht.c -o test_ht

clean:
	rm -f test_ht
