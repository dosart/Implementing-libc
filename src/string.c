#include "string.h"

void *str_memcpy(void *dest, const void *src, size_t n) {
  register char *tmp_dest = (char *) dest;
  register const char *tmp_src = (const char *) src;

  for (size_t i = 0; i < n; ++i) {
    tmp_dest[i] = tmp_src[i];
  }
  return dest;
}

void *str_memset(void *buf, char z, size_t bytes) {
  register char *tmp_buf = buf;
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
  register char *origin = dest;

  while (*dest!='\0')
    ++dest;
  while (*src!='\0')
    *dest++ = *src++;
  *dest = '\0';

  return origin;
}

size_t str_len(const char *str) {
  size_t i = 0;
  while (*str!='\0') {
    ++str;
    ++i;
  }
  return i;
}

char *str_cpy(char *dest, const char *src) {
  register char *original = dest;
  while ((*dest++ = *src++));
  return original;
}

char *str_cpyn(char *dest, const char *src, size_t n) {
  register char *original = dest;
  size_t i = 0;
  while (*src!='\0' && i < n) {
    *dest++ = *src++;
    ++i;
  }
  return original;
}

size_t str_spn(const char *str, char *accept) {
  size_t count = 0;
  while (*str && str_ch(accept, *str++))
    count++;

  return count;
}

size_t str_cspn(const char *str, char *accept) {
  size_t count = 0;
  while (*str) {
    if (str_ch(accept, *str++))
      return count;
    ++count;
  }
  return count;
}

char *str_ch(char *str, char c) {
  size_t i = 0;
  while (str[i] && str[i]!=c)
    ++i;
  return c==str[i] ? (char *) str + i : NULL;
}
