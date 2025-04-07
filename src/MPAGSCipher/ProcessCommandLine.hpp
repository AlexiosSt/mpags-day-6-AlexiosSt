#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include "CipherMode.hpp"
#include "CipherType.hpp"
#include "CustomExceptions.hpp"

#include <string>
#include <vector>

/**
 * \file ProcessCommandLine.hpp
 * \brief Contains the declarations of the data structures and functions associated with the processing of command-line arguments
 */

/**
 * \struct ProgramSettings
 * \brief Holds the settings of the program that can be modified by command-line arguments
 */
struct ProgramSettings {
    /// Indicates the presence of the help flag in the arguments
    bool helpRequested;
    /// Indicates the presence of the version flag in the arguments
    bool versionRequested;
    /// Name of the input file
    std::string inputFile;
    /// Name of the output file
    std::string outputFile;
    /// Key to be used in encrypting/decrypting routine
    std::vector<std::string> cipherKey;
    /// Which cipher(s) to use (e.g. Caesar, Playfair, etc.)
    std::vector<CipherType> cipherType;
    /// Flag indicating the mode in which the cipher should run (i.e. encrypt or decrypt)
    CipherMode cipherMode;
};

/**
 * \brief Processes the command-line arguments and modifies accordingly the program settings
 *
 * \param cmdLineArgs the command-line arguments to be processed
 * \return true if the arguments could be successfully parsed, false otherwise
 * \exception MissingArgument will be thrown if an expected argument is not found durng parsing
 * \exception UnknownArgument will be emitted if an argument encountered during parsing is not recognised
 */
ProgramSettings processCommandLine(const std::vector<std::string>& cmdLineArgs);

#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP