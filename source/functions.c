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
    struct stat filestat;
    directory = opendir(path);
    if (directory == NULL)
    {
        fprintf(stderr, "Error while trying to open %s\n", path);
        exit(EXIT_FAILURE);
    }
    
    while ((file = readdir(directory)) != NULL)
        
        if (!fnmatch(pattern, file -> d_name, 0))
        {
            char buf[PATH_LEN]; // To contain the full path to file
            strcpy(buf, path);  // Add path
            strcat(buf, file -> d_name); // Add file name
            if (stat(buf, &filestat)) // Get status in filestat
            {
                fprintf(stderr, "Error: Failed to get status for %s\n", buf);
                exit(EXIT_FAILURE);
            }
            printf(
                "Name = %s\nSize = %ld\nProtection = %o\n",
                file -> d_name, 
                filestat.st_size, 
                (filestat.st_mode & 0777)
            );
            printFileType(filestat.st_mode);
        }
    if (closedir(directory) == -1)
    {
        fprintf(stderr, "Error while trying to close %s\n", path);
        exit(EXIT_FAILURE);
    }
}

void printFileType(mode_t m)
{
    if (S_ISDIR(m))
        printf("%-11s\n","directory");
    else if (S_ISREG(m))
        printf("%-11s\n","regular");
    else if (S_ISCHR(m))
        printf("%-11s\n","character");
    else if (S_ISBLK(m))
        printf("%-11s\n","block");
    else if (S_ISFIFO(m))
        printf("%-11s\n","fifo");
    else if (S_ISLNK(m))
        printf("%-11s\n","link");
    else if (S_ISSOCK(m))
        printf("%-11s\n","socket");
    else
    {
        fprintf(stderr, "Error: Unknown file type %d\n", m);
        exit(EXIT_FAILURE);
    }
}