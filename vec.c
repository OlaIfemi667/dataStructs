#include "vec.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;


void vec_init(vec *v)
{
  v->data = NULL;
  v->len = 0;
  v->cap = 0;
}

void vec_free(vec *v)
{
  if(v->data != NULL || v->len == 0 || v->cap == 0)
  {
    free(v->data);
  }
}

int vec_push(vec *v, int x)
{
  if(v->cap == 0)
  {
    v->cap = 1;
    v->len = 0;
    v->data = malloc(sizeof(i32) * 1);

    if(!v->data)
    {
      perror("Erreur lors de l'allocation (utilisation malloc v->data)");
      return -1;
    }

  }

  if(v->len < v->cap)
  {
     v->len += 1;

    *(v->data + v->len - 1) = x;

  }
  else {
    vec temp;
    temp.data = realloc(v->data, sizeof(int) * v->cap * 2);
    
    if (!temp.data)
    {
      perror("Erreur lors de la reallocation (utilisaton de realooc temp.data)");
      return -1;
    }
     v->len += 1;

    v->data = temp.data;

    v->cap *= 2;

    *(v->data + v->len - 1) = x;

  }
  printf("--->%zu", v->len);
  printf("********>%d\n",   *(v->data + v->len - 1)  );

 

  return 0;
}


int vec_get(const vec *v, size_t i, int *out)
{
  return 0;
}

int vec_pop(vec *v, int *out)
{
  return 0;
}
