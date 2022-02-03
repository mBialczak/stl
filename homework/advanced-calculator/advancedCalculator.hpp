#pragma once
#include <functional>
#include <map>
#include <string>
#include <utility>

enum class ErrorCode
{
    OK,
    BadCharacter,             // operator other then a number
    BadFormat,                // bad command format, e.g. "+ 5 4" instead of "4 + 5"
    DivideBy0,                // attempt of division by zero
    SqrtOfNegativeNumber,     // attempt of getting Sqrt of negative numbber
    ModuleOfNonIntegerValue   // attempt of getting modulo of non integer value
};

using FormatedInput = std::tuple<ErrorCode, double, std::string, double>;

using OperationsMap = std::map<char, std::function<std::pair<ErrorCode, double>(double, double)>>;

ErrorCode process(std::string input, double* out);

FormatedInput formatInput(const std::string& line);

bool quitRequested(std::string line);

void printInstructions();

std::vector<std::string> getTokens(const std::string& line);

bool hasUnallowedChars(const std::string& line);

//   * Dodawanie, mnożenie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
// * Modulo (`%`)
// * Obliczanie silni (`!`)
// * Podnoszenie liczby do potęgi (`^`)
// * Obliczanie pierwiastka (`$`)

// auto add = [](auto lhs, auto rhs) { return lhs + rhs; };

// auto multiply = []