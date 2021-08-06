#include "include/utilities.hpp"


/**
 * @brief Prints help message and exits
 * @author Mohammed D. Belgoumri
 * TODO : Merge std::cout calls 
*/
void printHelpMessage()
{
    // Short description string
    std::string shortDescription = "search - search for files and directories.";

    // Synopsis
    std::string synopsis = "search [directory] [-h | -v | [-a] [-l | [-p] [-s] [-t] [-H]] [-d <max> | -r]] <pattern>";

    // Detailed description
    std::string description = "Prints out the paths of all files and directories matching pattern within directory.";

    // Author
    std::string author = "Written by Mohammed D. Belgoumri";

    // arguments/descriptions

    std::vector<std::pair<std::string, std::string>> arguments
    {
        {"directory (optional)", "The root directory for the search, defaults to the working directory."},
        {"pattern (mandatory)", "A wildcard pattern to match the contents of directory against."}
    };

    // options/desciptions
    std::vector<std::pair<std::string, std::string>> options
    {
        {"-a, --all", "Do not ignore hidden files and directories."},
        {"-d, --depth", "Search in directory and its subdirectories up to a depth of max. If -d is not used, max = 0."},
        {"-h, --help", "Print help message and exit."},
        {"-l, --long", "Use long output format. (Synonym of -psH)."},
        {"-p, --permissions", "Show access permissions."},
        {"-r, --Recursive", "Search recursively in directory and its subdirectories."},
        {"-s, --size", "Show the item size (in bytes)."},
        {"-t, --type", "Show the item type."},
        {"-v, --version", "Show program version and exit."},
        {"-H, --history", "Show the dates of creation, last modification and last access."}
    };


    // Print name
    std::cout << "\e[1m" << "NAME" << std::endl;
    std::cout << "\e[0m" << "\t" << shortDescription << std::endl;
       
    // Print synopsys
    std::cout << "\e[1m" << "SYNOPSIS" << std::endl;
    std::cout << "\e[0m" << "\t" << synopsis << std::endl;

    // Print description
    std::cout << "\e[1m" << "DESCRIPTION" << std::endl;
    std::cout << "\e[0m" << "\t" << description << std::endl;

    // Print arguments
    std::cout << "\e[1m" << "\tARGUMENTS" << std::endl;

    // Reset font weight
    std::cout << "\e[0m";

    // Print args/descriptions
    for (const auto& [argument, description] : arguments)
    {
        // Indent once and a half
        std::cout << "\t  ";

        // Print argument
        std::cout << std::left << std::setw(30) << argument;
        std::cout << std::left << description << std::endl;
    }

    // Print options
    std::cout << "\e[1m" << "\tOPTIONS" << std::endl;
    
    // Reset font weight
    std::cout << "\e[0m";

    // Print options/descriptions
    for (const auto& [option, description] : options)
    {
        // Indent once and a half
        std::cout << "\t  ";
        
        // Print options left justified
        std::cout << std::left << std::setw(30) << option;

        // Print descriptions right justified
        std::cout << std::right << description << std::endl;
    }

    // Print author
    std::cout << "\e[1m" << "AUTHOR" << std::endl;
    std::cout << "\e[0m" << "\t" << author <<std::endl;
}

/**
 * @brief Prints the program version and exits.
 * @author Mohammed D. Belgoumri
*/
void printVersion()
{
    std::cout << "This is search version " << VERSION_STRING << std::endl;
}

