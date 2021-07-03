#include "include/functions.h"

int main(int argc, char *argv[])
{
    int c;
    static int fall, fdate, fhelp, fmodification, fprotection, fsize, ftype, fversion;
    int depth = __INT_MAX__;
    
    while(1)
    {
        int opt_index = 0;    
        static struct option long_options[] = {
            {"all",          no_argument, &fall, 'a'},
            {"date",         no_argument, &fdate, 'd'},
            {"help",         no_argument, &fhelp, 'h'},
            {"modification", no_argument, &fmodification, 'm'},
            {"protection",   no_argument, &fprotection, 'p'},
            {"size",         no_argument, &fsize, 's'},
            {"type",         no_argument, &ftype, 't'},
            {"version",      no_argument, &fversion, 'v'},
            {NULL,           0,           NULL,  0}
        };
        c = getopt_long(argc, argv, ":adhmprstv", long_options, &opt_index);
        
        if (c == -1)
            break;
        
        switch(c)
        {
            case '?':
                fprintf(stderr, "Error: Unknown option %c\n", optopt);
                break;
            default:
                fprintf(stderr, "Error: getopt returned character code 0%d ??\n", c);
                break;
        }
    }
    if (fhelp)
        printHelp();
    if (fversion)
        printVersion();
    if (fall)
        fdate = fsize = ftype = fprotection = 1;
    printHeader(1, fmodification, fprotection, fsize, 1);
    // printf("%-12s%-12s%-6s%-12s%-15s%s\n", "directory", "777", "4096", "03-07-2021", "03-07-2021", "functions");
    printDirectory(argv[1], argv[2], 1, fmodification, fprotection, fsize, 1, depth);
    return EXIT_SUCCESS;
}
