#include <stdio.h>
#include <syscall.h>
#include <string.h>

int puts(const char* s)
{
  static const char newline = '\n';
  int len = strlen(s);
  write(1, s, len);
  write(1, &newline, 1);
  return 1;
}

