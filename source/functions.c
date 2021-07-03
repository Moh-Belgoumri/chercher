#include"include/functions.h"

void printHelp()
{
    printf("-h --help\t\tPrint this help text and exit.\n");
    printf("-v --version\t\tPrint program version and exit.\n");
    printf("-0\t\t\tLook only in directory.\n");
    printf("-1\t\t\tLook in directory and its immediate children\n");
    printf("-n\t\t\tLook in directory and all its children of depth =< n.\n");
    printf("-r\t\t\tLook recursively in directory and its children.\n");
    exit(EXIT_SUCCESS);
}

void printVersion()
{
    printf("This is search version 1.0\n");
    exit(EXIT_SUCCESS);
}

void printDirectory(char* path, char* pattern, int date, int modification, int protection, int size, int type, int depth)
{
    // Exit if depth reached
    if (depth == -1)
        return;

    DIR* directory = NULL; // To contain the opened directory
    struct dirent* file = NULL; // To contain the files in directory
    struct stat filestat; // To contain file status
     
    directory = opendir(path);
    
    // Open path in directory and exit if failed
    if (directory == NULL)
    {
        fprintf(stderr, "Error while trying to open %s\n", path);
        exit(EXIT_FAILURE);
    }
    
    //Readdir until NULL
    while ((file = readdir(directory)) != NULL)
    {
        // Ignore ., .. and all hidden files
        if (file->d_name[0] == '.')
             continue;     
        
        char buf[PATH_LEN]; // To contain the full path to file
        strcpy(buf, path);  // Add path
        strcat(buf, "/");
        strcat(buf, file -> d_name); // Add file name
        if (stat(buf, &filestat)) // Get status in filestat and exit if stat failed
        {
            fprintf(stderr, "Error: Failed to get status for %s\n", buf);
            exit(EXIT_FAILURE);
        }

        // If file is a directory, apply the search to it recursively
        if (S_ISDIR(filestat.st_mode))
            printDirectory(
                buf,
                pattern,
                date,
                modification,
                protection,
                size,
                type,
                depth - 1
            );

        // Test for pattern match
        if (!fnmatch(pattern, file -> d_name, 0))
        {
            printf(
                "Name = %s\nSize = %ld\nProtection = %o\n",
                file -> d_name, 
                filestat.st_size, 
                (filestat.st_mode & 0777)
            );
            printFileType(filestat.st_mode);
        }
    }
    // Close directory and exit if failed
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