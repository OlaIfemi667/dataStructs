#ifndef VEC_H
#define VEC_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t len;   /* éléments utilisés */
    size_t cap;   /* éléments alloués */
} vec;

void vec_init(vec *v);
void vec_free(vec *v);
int  vec_push(vec *v, int x);             /* 0 = ok, -1 = échec mémoire */
int  vec_get(const vec *v, size_t i, int *out);  /* 0 = ok, -1 = hors limites */
int  vec_pop(vec *v, int *out);           /* 0 = ok, -1 = vide */

#endif
