#include"include/functions.h"

void printHelp(int help)
{
    if (help) 
    {
        printf("This is search version 1.0.0\n");
        // Synopsis
        printf("Synopsis:\n");
        printf("\tsearch [directory][-a][-d][-h][-m][-n][-p][-s][-t][-v] pattern\n");
        
        // Description
        printf("Description:\n");
        printf("\tPrints out a list of all files matching `pattern` within `directory`. If `directory` \n\tis unspecified, the working directory is the default.\n");

        // Options
        printf("Options:\n");
        printf("\t-a\t\t\tSame as  -d -s -t -p\n");
        printf("\t-d\t\t\tPrint last access date.\n");
        printf("\t-h\t\t\tPrint this help text and exit.\n");
        printf("\t-m\t\t\tPrint last modification date.\n");
        printf("\t-n (n integer)\t\tSearch in directory and all its children of depth =< n (infinite by default).\n");
        printf("\t-p\t\t\tPrint protection.\n");
        printf("\t-s\t\t\tPrint size.\n");
        printf("\t-t\t\t\tPrint type.\n");
        printf("\t-v\t\t\tPrint program version and exit.\n");
        exit(EXIT_SUCCESS);
    }
}

void printVersion()
{
    printf("This is search version 1.0\n");
    exit(EXIT_SUCCESS);
}

void printDirectory(
    char* path, 
    char* pattern, 
    int date, 
    int modification, 
    int protection, 
    int size, 
    int type, 
    int depth
)
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
        if (strcmp(buf, "/")) // If path is /, no need to add a '/'
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

        // Test for pattern match and print if successful
        if (!fnmatch(pattern, file -> d_name, 0))
        {
            printFileType(type, filestat);
            printProtection(protection, filestat);
            printSize(size, filestat);
            printLastUsed(date, filestat);
            printLastModified(modification, filestat);
            printf("%s\n", buf);
        }
    }
    // Close directory and exit if failed
    if (closedir(directory) == -1)
    {
        fprintf(stderr, "Error while trying to close %s\n", path);
        exit(EXIT_FAILURE);
    }
}

void printFileType(int type, struct stat filestat)
{
    if (type)
    {
        if (S_ISDIR(filestat.st_mode))
            printf("%-12s","directory");
        else if (S_ISREG(filestat.st_mode))
            printf("%-12s","regular");
        else if (S_ISCHR(filestat.st_mode))
            printf("%-12s","character");
        else if (S_ISBLK(filestat.st_mode))
            printf("%-12s","block");
        else if (S_ISFIFO(filestat.st_mode))
            printf("%-12s","fifo");
        else if (S_ISLNK(filestat.st_mode))
            printf("%-12s","link");
        else if (S_ISSOCK(filestat.st_mode))
            printf("%-12s","socket");
        else
        {
            fprintf(stderr, "Error: Unknown file type %d\n", filestat.st_mode);
            exit(EXIT_FAILURE);
        }
    }
}

void printHeader(int date, int modification, int protection, int size, int type)
{
    if (type)
        printf("%-12s", "Type");
    if (protection)
        printf("%-12s", "Protection");
    if (size)
        printf("%-10s", "Size"); 
    if(date)
        printf("%-14s", "Last used");
    if (modification)
        printf("%-15s", "Last modified");
   
    printf("%s\n", "Name");
}

void printLastUsed(int date, struct stat filestat)
{
    if (date)
        printf(
            "%02d/%02d/%04d%-4s",
            localtime(&filestat.st_atim.tv_sec)->tm_mday,
            (localtime(&filestat.st_atim.tv_sec)->tm_mon + 1),
            (localtime(&filestat.st_atim.tv_sec)->tm_year + 1900),
            " "
        );
}

void printLastModified(int modification, struct stat filestat)
{
    if (modification)
        printf(
            "%02d/%02d/%04d%-5s",
            localtime(&filestat.st_atim.tv_sec)->tm_mday,
            (localtime(&filestat.st_atim.tv_sec)->tm_mon + 1),
            (localtime(&filestat.st_atim.tv_sec)->tm_year + 1900),
            " "
        );
}

void printProtection(int protection, struct stat filestat)
{
    if (protection)
        printf(
            "%o%-9s", 
            (filestat.st_mode & 0777), // Mode & mask
            " "
        );
}

void printSize(int size, struct stat filestat)
{
    if (size)
        printf(
            "%4ld %-3s%-2s", 
            reducedSize(filestat.st_size),
            unit(filestat.st_size),
            " "
        );
}

const char *unit(off_t bytes)
{
    if (bytes < 10000)
        return "";
    else if (bytes < 10000000)
        return "Kbs";
    else if (bytes < 10000000000)
        return "Mbs";
    else 
        return "Tbs";
}

off_t reducedSize(off_t bytes)
{
    if (bytes < 10000)
        return bytes;
    else if (bytes < 10000000)
        return bytes / 1000;
    else if (bytes < 10000000000)
        return bytes / 1000000;
    else 
        return bytes / 1000000000;
}