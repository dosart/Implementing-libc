# Implementing-libc

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/44676cb472e348a3abe7ea966893f395)](https://www.codacy.com/gh/dosart/Implementing-libc/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=dosart/Implementing-libc&amp;utm_campaign=Badge_Grade)
[![Build Status](https://www.travis-ci.com/dosart/Implementing-libc.svg?branch=main)](https://www.travis-ci.com/dosart/Implementing-libc)

This is a simple libc implementation for educational purposes.

## memory menager

- [x] void *malloc (unsigned long) - allocates size bytes of uninitialized storage
- [x] void *calloc(unsigned long) - allocates memory for an array of num objects of size size and initializes it to all bits zero
- [x] void *realoc(unsigned long) - reallocates the given area of memory
- [x] void free(void* ptr) - deallocates the space previously allocated by malloc(), calloc(), realoc()

## tiny garbage collector

Implementation of Mark&Sweep algorithm for memory manager

## string.h

- [x] void *memcpy(void *dest, const void *src, size_t n) - copies bytes between buffers. From src to dest
- [x] void *memset(void *buf, char ch, size_t count) - sets buffers to a specified character
- [x] char *cat(char *dest, const char *src) - appends a string
- [x] size_t len(const char *str) - gets the length of a string
- [x] char *cpy(char *dest, const char *src) - copies a string
- [x] char *cpyn(char *dest, const char *src, size_t num) - copies the first num characters of source to destination
- [x] size_t spn(const char *str, char *accept) - teturns the length of the initial portion of str1 which consists only of characters that are part of accept
- [x] size_t cspn(const char *str, char *not_accept) - Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence
- [x] char *ch(char *str, char ch) - returns a pointer to the first occurrence of character in the C string str
