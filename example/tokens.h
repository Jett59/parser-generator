#ifndef TOKENS_H
#define TOKENS_H

#include <fstream>

namespace Tokens {
enum class TokenType {nothing, something };

std::ostream& operator<<(std::ostream& stream, const TokenType tokenType) {
    switch (tokenType) {
        case TokenType::nothing: {
          stream << "nothing";
          break;
        }
        case TokenType::something: {
          stream << "something";
          break;
        }
        default:
          stream << "unknown";
    }
    return stream;
}
}

#define TOKEN_TYPE Tokens::TokenType

#endif