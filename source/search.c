#include "include/functions.h"

int main(int argc, char *argv[])
{
    int c;
    
    while(1)
    {
        int opt_index = 0;    
        static struct option long_options[] = {
            {"all",          no_argument, NULL, 'a'},
            {"date",         no_argument, NULL, 'd'},
            {"help",         no_argument, NULL, 'h'},
            {"modification", no_argument, NULL, 'm'},
            {"protection",   no_argument, NULL, 'p'},
            {"size",         no_argument, NULL, 's'},
            {"type",         no_argument, NULL, 't'},
            {"version",      no_argument, NULL, 'v'},
            {NULL,           0,           NULL,  0}
        };
        c = getopt_long(argc, argv, ":adhmprstv", long_options, &opt_index);
        
        if (c == -1)
            break;
        
        switch(c)
        {
            case 'a': 
                break;
            case 'd': 
                break;
            case 'h':
                printHelp();
                break;
            case 'p': 
                break;
            case 'r': 
                break;
            case 's': 
                break;
            case 't': 
                break;
            case 'v':
                printVersion();
                break;
            case '?':
                printf("Unknown option %c\n", optopt);
                break;
            default:
                printf("?? getopt returned character code 0%d ??\n", c);
                break;
        }
    }
    return EXIT_SUCCESS;
}
