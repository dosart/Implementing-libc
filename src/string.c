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

int str_cmp(const char *str1, const char *str2) {
  while (1) {
    if (*str1!=*str2)
      return (*str1 - *str2);
    if (*str1=='\0')
      return 0;
    ++str1;
    ++str2;
  }
}

char *str_cat(char *dest, const char *src) {
  char *origin = dest;

  while (*dest!='\0')
    ++dest;
  while (*src!='\0')
    *dest++ = *src++;
  *dest = '\0';

  return origin;
}

size_t str_len(char *str) {
  char *original = str;
  while (*str!='\0')
    ++str;

  return (str - original);
}
