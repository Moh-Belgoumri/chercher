#include "include/utilities.hpp"


int main(int argc, char const *argv[])
{
    bool shouldPrintHelpMessage = true, shouldPrintVersion = true;
    if (shouldPrintHelpMessage)
        printHelpMessage();
    if(shouldPrintVersion)
        printVersion();
    return EXIT_SUCCESS;
}