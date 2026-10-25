#include "vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t i32;


void vec_init(vec *v)
{
  v->data = NULL;
  v->len = 0;
  v->cap = 0;
}

void vec_free(vec *v)
{
  free(v->data);
  v->data = NULL;
  v->len = 0;
  v->cap = 0;

}

i32 vec_push(vec *v, int x)
{
  if (v->len == v->cap)
  {
    size_t newcap;
    if (v->cap >= SIZE_MAX / 2 + 1)
      return -1;

    if (v->cap == 0)
      newcap = 4;
    else
     newcap = v->cap * 2;

    if (newcap > SIZE_MAX / sizeof(*v->data))
      return -1;

    i32 *temp = realloc(v->data, sizeof(*temp) * newcap);

    if (!temp)
    {
      return -1;
    }

    v->data = temp;
    v->cap = newcap;
  }

  v->data[v->len] = x;
  v->len += 1;

  return 0;
}


i32 vec_get(const vec *v, size_t i, int *out)
{
  if (i >= v->len) 
    return -1;
  *out = v->data[i];
  return 0;
}

i32 vec_pop(vec *v, int *out)
{
  if (v->len > 0)
  {
    *out = v->data[v->len-1];
    v->len -= 1;
    return 0;
  }
  else {
    return -1;
  }
}
