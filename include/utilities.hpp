#ifndef __UTILITIES__HPP__
#define __UTILITIES__HPP__

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <fnmatch.h>
#include <sys/stat.h>
#include <iomanip>
#include <tuple>
#define VERSION "1.0.0"

void printHelpMessage(bool shouldPrintHelpMessage);
void printVersion(bool shouldPrintVersion);
#endif // __UTILITIES__HPP__