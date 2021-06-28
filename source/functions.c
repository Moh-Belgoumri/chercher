#include"include/functions.h"

void printHelp()
{
    printf("-h --help\t\tPrint this help text and exit.\n");
    printf("-v --version\t\tPrint program version and exit.\n");
    printf("-0\t\t\tLook only in directory.\n");
    printf("-1\t\t\tLook in directory and its immediate children\n");
    printf("-n\t\t\tLook in directory and all its children of depth =< n.\n");
    printf("-r\t\t\tLook recursively in directory and its children.\n");
}


void printVersion()
{
    printf("This is search version 1.0\n");
}


