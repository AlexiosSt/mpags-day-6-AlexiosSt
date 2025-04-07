#ifndef MPAGSCIPHER_CUSTOMEXCEPTIONS_HPP
#define MPAGSCIPHER_CUSTOMEXCEPTIONS_HPP

#include <stdexcept>

/**
* \class MissingArgument
* \brief Exception object to indicate missing argument in the command-line
*/
class MissingArgument : public std::invalid_argument{
    public:
        MissingArgument(const std::string& msg):
            std::invalid_argument{msg}{}
};

/**
* \class UnknownArgument
* \brief Exception object to indicate unrecognised argument in the command-line
*/
class UnkownArgument : public std::invalid_argument{
    public:
        UnkownArgument(const std::string& msg):
            std::invalid_argument{msg}{}
};

/**
* \class InvalidArgument
* \brief Exception object to indicate invalid argument in the command-line
*/
class InvalidArgument : public std::invalid_argument{
    public:
        InvalidArgument(const std::string& msg):
            std::invalid_argument{msg}{}
};

/**
* \class InconsistentArgument
* \brief Exception object to indicate an inconsistent set of arguments in the command-line
*/
class InconsistentArguments : public std::invalid_argument{
    public:
        InconsistentArguments(const std::string& msg):
            std::invalid_argument{msg}{}
};

/**
* \class InvalidKey
* \brief Exception object to indicate an invalid cipher key which has been provided in the command-line
*/
class InvalidKey : public std::invalid_argument{
    public:
        InvalidKey(const std::string& msg):
            std::invalid_argument{msg}{}
};

#endif // MPAGSCIPHER_CUSTOMEXCEPTIONS_HPP