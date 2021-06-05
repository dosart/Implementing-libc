

#include "tests.h"
#include "string.h"

#include <assert.h>
#include <stdio.h>

void tests() {
  test_memcpy1();
}

void test_memcpy1() {
  printf("test_memcpy1()\n");

  const size_t count = 6;
  char src[10] = "123456";
  char dst[10] = "";

  char *result = str_memcpy(dst, src, count);

  assert(result==dst);
  for (size_t i = 0; i < count; i++) {
    assert(dst[i]==src[i]);
  }
}
