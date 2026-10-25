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

    /* 1. Pop sur vecteur vide */
    vec e;
    vec_init(&e);
    int y;
    assert(vec_pop(&e, &y) == -1);
    vec_free(&e);

    /* 2. Double vec_free */
    vec d;
    vec_init(&d);
    assert(vec_push(&d, 1) == 0);
    vec_free(&d);
    vec_free(&d);
    assert(d.data == NULL && d.len == 0 && d.cap == 0);

    /* 3. Push de 1000 éléments */
    vec g;
    vec_init(&g);
    for (int i = 0; i < 1000; i++)
        assert(vec_push(&g, i) == 0);
    assert(g.len == 1000);
    for (int i = 0; i < 1000; i++) {
        int z;
        assert(vec_get(&g, (size_t)i, &z) == 0 && z == i);
    }
    vec_free(&g);

    /* Bonus : push/pop dans l'ordre inverse */
    vec h;
    vec_init(&h);
    for (int i = 0; i < 10; i++)
        assert(vec_push(&h, i) == 0);
    for (int i = 9; i >= 0; i--) {
        int w;
        assert(vec_pop(&h, &w) == 0 && w == i);
    }
    assert(h.len == 0);
    vec_free(&h);

    puts("OK");
    return 0;
}
