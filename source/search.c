#include "include/functions.h"

int main(int argc, char *argv[])
{
    int c; //To contain getopt() return
    static int fall, fdate, fhelp, fmodification, fprotection, fsize, ftype, fversion; //flag returns
    int depth = __INT_MAX__;
    char path[PATH_LEN];
    char pattern[PATH_LEN];
    char regargv[2][PATH_LEN];
    int regargc = 0;
    // Loop to parse args
    for (int i = 1; i < argc; i++)
    {
        //Handle flags
        if (argv[i][0] == '-')
        {
            // depth
            if (isdigit(argv[i][1]))
            {   
                depth = atoi(argv[i] + 1);
            }
            // Flags
            else 
            {
                switch (argv[i][1])
                {
                    case 'a':
                        fall = 1;
                        break;
                    case 'v':
                        fversion = 1;
                        break;
                    case 'h':
                        fhelp = 1;
                        break;
                    case 'd':
                        fdate = 1;
                        break;
                    case 'm':
                        fmodification = 1;
                        break;
                    case 'p':
                        fprotection = 1;
                        break;
                    case 's':
                        fsize = 1;
                        break;
                    case 't':
                        ftype = 1;
                        break;
                    default:
                        fprintf(stderr, "Error: Unknown option: %s\n", argv[i] + 1);
                        break;
                }
            } 
        }
        // Regular arguments
        else
        {
            strcpy(regargv[regargc], argv[i]);
            regargc++;     
        }
        
    }

    printHelp(fhelp);
    printVersion(fversion);
    // Test for missing arguments
    if (regargc == 0)
        fprintf(stderr, "Error: Missing mandatory argument: filename");
    
    // Test for missing path
    else if (regargc == 1)
    {
        strcpy(path, "."); //Default path is .
        strcpy(pattern, regargv[0]);
    }   
    else if (regargc == 2)
    {
        strcpy(path, regargv[0]);
        strcpy(pattern, regargv[1]);
    }
    else
        fprintf(stderr, "Error: Too many arguments\n");

    // Handle -a   
    if (fall)
        fdate = fsize = ftype = fprotection = 1;
    printHeader(fdate, fmodification, fprotection, fsize, ftype);
    printDirectory(path, pattern, fdate, fmodification, fprotection, fsize, ftype, depth);
    return EXIT_SUCCESS;
}
