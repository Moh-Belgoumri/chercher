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
void printFileType(int type, struct stat filestat);
void printHeader(int date, int modification, int protection, int size, int type);
void printLastUsed(int date, struct stat filestat);
void printLastModified(int modification, struct stat filestat);
void printProtection(int protection, struct stat filestat);
void printSize(int size, struct stat filestat);
const char *unit(off_t bytes);
off_t reducedSize(off_t bytes);
#endif //__FUNCTIONS__H__