

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

  test_str_ch1();
  test_str_ch2();
  test_str_ch3();
  test_str_ch4();
  test_str_ch5();

  test_str_spn1();
  test_str_spn2();
  test_str_spn3();

  test_str_cspn1();
  test_str_cspn2();
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
void test_str_cpyn3() {
  printf("test_str_cpyn3()\n");

  char src[20] = "This is source";
  char dest[20] = "This is destination";

  char *result = str_cpyn(dest, src, 14);
  assert(str_cmp(result, "This is sourceation")==0);
}

void test_str_ch1() {
  printf("test_str_ch1()\n");

  char *result = str_ch("This is sourceation", 'T');
  assert(*result=='T');
}

void test_str_ch2() {
  printf("test_str_ch2()\n");

  char *result = str_ch("This is sourceation", 'n');
  assert(*result=='n');
}

void test_str_ch3() {
  printf("test_str_ch3()\n");

  char *result = str_ch("This is sourceation", ' ');
  assert(*result==' ');
}

void test_str_ch4() {
  printf("test_str_ch4()\n");

  char *result = str_ch("This is sourceation", '\0');
  assert(*result=='\0');
}

void test_str_ch5() {
  printf("test_str_ch4()\n");

  char *result = str_ch("This is sourceation", 'L');
  assert(result==NULL);
}

void test_str_spn1() {
  printf("test_str_spn1()\n");

  size_t result = str_spn("12345678", "123");
  assert(result==3);
}

void test_str_spn2() {
  printf("test_str_spn2()\n");

  size_t result = str_spn("12345678", "LKO");
  assert(result==0);
}

void test_str_spn3() {
  printf("test_str_spn3()\n");

  size_t result = str_spn("11345678", "123");
  assert(result==3);
}

void test_str_cspn1() {
  printf("test_str_cspn1()\n");

  size_t result = str_cspn("12345678", "LKO");
  assert(result==8);
}

void test_str_cspn2() {
  printf("test_str_cspn2()\n");

  size_t result = str_cspn("1234Lkt", "LKO");
  assert(result==4);
}
