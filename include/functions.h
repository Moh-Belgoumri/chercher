#ifndef __FUNCTIONS__H__
#define __FUNCTIONS__H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include <dirent.h>

#define PATH_LEN 1024
void printHelp();
void printVersion();
void printDirectory(
    char* path, 
    char* pattern, 
    int date, 
    int modification, 
    int protection, 
    int size, 
    int type, 
    int depth
);
void printFileType(mode_t m, int type);
void printHeader(int date, int modification, int protection, int size, int type);
void printLastUsed(int date, struct stat filestat);
#endif //__FUNCTIONS__H__