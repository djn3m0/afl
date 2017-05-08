/*
   american fuzzy lop - a trivial program to test the build
   --------------------------------------------------------

   Written and maintained by Michal Zalewski <lcamtuf@google.com>

   Copyright 2014 Google Inc. All rights reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at:

     http://www.apache.org/licenses/LICENSE-2.0

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

__attribute__((noinline))
int foo(char x) {
  if (x == '0') return 1;
  return 0;
}

__attribute__((noinline))
int bar(char x) {
  if (x == '1') return 1;
  return 0;
}

int main(int argc, char** argv) {

  char buf[8];

  if (read(0, buf, 8) < 1) {
    printf("Hum?\n");
    exit(1);
  }

  if (foo(buf[0]))
    printf("Looks like a zero to me!\n");
  else if (bar(buf[0]))
    printf("Looks like a one to me!\n");
  else
    printf("Something else? How quaint!\n");

  exit(0);

}
