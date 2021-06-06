

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

  test_str_cat1();
  test_str_cat2();
  test_str_cat3();

  test_str_len1();
  test_str_len2();
  test_str_len3();

  test_str_cpy1();
  test_str_cpy2();
  test_str_cpy3();

  test_str_cpyn1();
  test_str_cpyn2();
  test_str_cpyn3();
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

void test_str_cat1() {
  printf("test_str_cat1()\n");

  char src[50] = "This is source";
  char dest[50] = "This is destination";

  char *result = str_cat(dest, src);
  assert(str_cmp(result, "This is destinationThis is source")==0);
}

void test_str_cat2() {
  printf("test_str_cat2()\n");

  char src[20] = "This is source";
  char dest[1] = "";

  char *result = str_cat(dest, src);
  assert(str_cmp(result, "This is source")==0);
}

void test_str_cat3() {
  printf("test_str_cat3()\n");

  char src[1] = "";
  char dest[2] = "";

  char *result = str_cat(dest, src);
  assert(str_cmp(result, "")==0);
}

void test_str_len1() {
  printf("test_str_len1()\n");

  char src[1] = "";
  assert(str_len(src)==0);
}

void test_str_len2() {
  printf("test_str_len2()\n");

  char src[1] = " ";
  assert(str_len(src)==1);
}

void test_str_len3() {
  printf("test_str_len3()\n");

  char src[14] = "This is source";
  assert(str_len(src)==14);
}

void test_str_cpy1() {
  printf("test_str_len1()\n");

  char src[20] = "This is source";
  char dest[20] = "";

  char *result = str_cpy(dest, src);
  assert(str_cmp(result, "This is source")==0);
}

void test_str_cpy2() {
  printf("test_str_len2()\n");

  char src[20] = "This is source";
  char dest[20] = "This is destination";

  char *result = str_cpy(dest, src);
  assert(str_cmp(result, "This is source")==0);
}

void test_str_cpy3() {
  printf("test_str_len3()\n");

  char src[20] = "This is source";
  char dest[20] = " ";

  char *result = str_cpy(dest, src);
  assert(str_cmp(result, "This is source")==0);
}

void test_str_cpyn1() {
  printf("test_str_cpyn1()\n");

  char src[20] = "This is source";
  char dest[20] = "";

  char *result = str_cpyn(dest, src, 14);
  assert(str_cmp(result, "This is source")==0);
}
void test_str_cpyn2() {
  printf("test_str_cpyn2()\n");

  char src[20] = "This is source";
  char dest[20] = " ";

  char *result = str_cpyn(dest, src, 14);
  assert(str_cmp(result, "This is source")==0);

}
void test_str_cpyn3(){
  printf("test_str_cpyn3()\n");

  char src[20] = "This is source";
  char dest[20] = "This is destination";

  char *result = str_cpyn(dest, src, 14);
  assert(str_cmp(result, "This is sourceation")==0);
}
