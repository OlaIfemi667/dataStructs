#include <assert.h>
#include <stdio.h>
#include "vec.h"

int main(void) {
    vec v;
    vec_init(&v);

    for (int i = 0; i < 100; i++)
        assert(vec_push(&v, i) == 0);
    assert(v.len == 100);


    int x;
    assert(vec_get(&v, 42, &x) == 0 && x == 42);
    assert(vec_get(&v, 100, &x) == -1);

    assert(vec_pop(&v, &x) == 0 && x == 99);

    vec_free(&v);
    puts("OK");
    return 0;
}
