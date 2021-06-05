

#include "tests.h"
#include "string.h"

#include <assert.h>
#include <stdio.h>

void tests() {
  test_memcpy();
  test_memset();
}

void test_memcpy() {
  printf("test_memcpy()\n");

  const size_t count = 6;
  char src[10] = "123456";
  char dst[10] = "";

  char *result = str_memcpy(dst, src, count);

  assert(result==dst);
  for (size_t i = 0; i < count; i++) {
    assert(dst[i]==src[i]);
  }
}

void test_memset() {
  const size_t count = 16;
  char buf[16] = "12345678";

  char *result = str_memset(buf, '1', sizeof(buf));

  assert(result==buf);
  for (size_t i = 0; i < count; i++) {
    assert(buf[i]=='1');
  }
}
