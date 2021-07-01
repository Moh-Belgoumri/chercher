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

void printDirectory(char* path, char* pattern)
{
    DIR* directory = NULL;
    struct dirent* file = NULL;
    directory = opendir(path);
    if (directory == NULL)
    {
        fprintf(stderr, "Error while trying to open %s\n", path);
        exit(EXIT_FAILURE);
    }

    file = readdir(directory);
    if(!fnmatch(pattern, file -> d_name, 0))
        printf("%s\n", file -> d_name);

    if (closedir(directory) == -1)
    {
        fprintf(stderr, "Error while trying to close %s\n", path);
        exit(EXIT_FAILURE);
    }
}
