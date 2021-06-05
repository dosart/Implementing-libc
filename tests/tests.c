

#include "tests.h"
#include "string.h"

#include <assert.h>
#include <stdio.h>

void tests() {
  test_memcpy();
  test_memset();

  test_strcmp1();
  test_strcmp2();
  test_strcmp3();
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
  printf("test_memset()\n");

  const size_t count = 16;
  char buf[16] = "12345678";

  char *result = str_memset(buf, '1', sizeof(buf));

  assert(result==buf);
  for (size_t i = 0; i < count; i++) {
    assert(buf[i]=='1');
  }
}

void test_strcmp1() {
  printf("test_strcmp1()\n");

  char string1[] = "The quick brown dog jumps over the lazy fox";
  char string2[] = "The QUICK brown dog jumps over the lazy fox";

  int result = str_cmp(string1, string2);
  assert(result > 0);
}

void test_strcmp2() {
  printf("test_strcmp2()\n");

  char string1[] = "The Quick brown dog jumps over the lazy fox";
  char string2[] = "The qUICK brown dog jumps over the lazy fox";

  int result = str_cmp(string1, string2);
  assert(result < 0);
}

void test_strcmp3() {
  printf("test_strcmp3()\n");

  char string1[] = "The Quick brown dog jumps over the lazy fox";
  char string2[] = "The Quick brown dog jumps over the lazy fox";

  int result = str_cmp(string1, string2);
  assert(result==0);
}
