#ifndef EX4_EXCEPTIONS_H
#define EX4_EXCEPTIONS_H

// file exceptions should be inhereted from std::exceptions
#include <exception>

const int MAX_LINE = 256;

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
    int m_lineNum;
public:
    DeckFileFormatError(int line) : m_lineNum(line) {}
    const char* what() const noexcept override
    {
        char* msg = new char[MAX_LINE]();
        sprintf(msg, "Deck File Error: File format error in line %d", m_lineNum);
        return msg;
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