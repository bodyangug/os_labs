#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

typedef int (*system_function)(char*);


int mgetpid(char* buf);
int mgetppid(char* buf);
int mgetpgrp(char* buf);
int mgetuid(char* buf);
int mgeteuid(char* buf);
int mgetgid(char* buf);
int mgetegid(char* buf);
void print_help();
