#include "string.h"

void *str_memcpy(void *dest, const void *src, size_t n) {
  char *tmp_dest = (char *) dest;
  char *tmp_src = (char *) src;

  for (size_t i = 0; i < n; ++i) {
    tmp_dest[i] = tmp_src[i];
  }
  return dest;
}

void *str_memset(void *buf, char z, size_t bytes) {
  char *tmp_buf = buf;
  while (bytes) {
    *tmp_buf++ = z;
    --bytes;
  }
  return buf;
}
