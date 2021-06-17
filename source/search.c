#include "include/functions.h"

int main(int argc, char *argv[])
{
    char c;
    while((c = getopt(argc, argv, "1:")) != -1)
    {
        printf("%c\n", c);
    }    
    return 0;
}
