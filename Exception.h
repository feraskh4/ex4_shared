#ifndef EX4_EXCEPTIONS_H
#define EX4_EXCEPTIONS_H

// file exceptions should be inhereted from std::exceptions
#include <exception>


const int MAX_LINE = 256;
const std::string ERROR_MSG = "Deck File Error: File format error in line ";

class DeckFileNotFound : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};


class DeckFileFormatError  : public std::exception
{
    std::string m_msg;
public:
    DeckFileFormatError(int line) : m_msg(ERROR_MSG+std::to_string(line)) {}
    virtual ~DeckFileFormatError()override = default;
    const char* what() const noexcept override
    {
        return (m_msg).c_str();
    }
};

class DeckFileInvalidSize  : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

// OPTIONAL write ur own handleres like for invalid player name etc...


#endif // EX4_EXCEPTIONS_H