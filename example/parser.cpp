#include "../generator.h"
#include "tokens.h"
#include <iostream>

using namespace std;

#define PARSE_STACK_VALUES TOKEN_TYPE

PARSE_STACK;

int main() {
  cout << token(something) << endl;
  return 0;
}
