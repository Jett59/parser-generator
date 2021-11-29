#include "../generator.h"
#include "tokens.h"
#include <iostream>

using namespace std;

enum class ParseStackElementType { INT, DOUBLE };

#define PARSE_STACK_ELEMENT_TYPE ParseStackElementType

#define PARSE_STACK_VALUES int, double

ostream& operator<<(ostream& stream, PARSE_STACK stack) {
  for (int i = 0; i < stack.size(); i ++) {
    switch (stack.peekType(i)) {
      case ParseStackElementType::INT: {
        stream << stack.peek<int>(i);
        break;
      }
      case ParseStackElementType::DOUBLE: {
        stream << stack.peek<double>(i);
        break;
      }
    }
    stream << endl;
  }
  return stream;
  }

int main() {
    PARSE_STACK parseStack;
  parseStack.push<int>(42, ParseStackElementType::INT);
  parseStack.push<double>(3.14, ParseStackElementType::DOUBLE);
  cout << parseStack << endl;
  return 0;
}
