/*
*   Copyright 2021 Jett Thompson
*
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*/

/*Defines macros, templates and helpers for generating parsers*/

#ifndef ___PARSER_GENERATOR_PARSER_H_INCLUDED___
#define ___PARSER_GENERATOR_PARSER_H_INCLUDED___

#ifndef __cplusplus
#error Try a C++ compiler.
#endif

#if __cplusplus < 201703L
#error Try -std=c++17
#endif

#include <variant>
#include <vector>
#include <utility>

#define PARSE_STACK_VALUE_TYPE std::variant<PARSE_STACK_VALUES>
#define PARSE_STACK_VALUE(ELEMENT, TYPE)  std::get<TYPE>(ELEMENT)

namespace parserGenerator {
    template<typename StackValueType, typename StackElementType> // To allow the specific variants to be defined later
    class ParserStack {
        private:
         std::vector<std::pair<StackValueType, StackElementType>> internalStack;
         public:
         ParserStack() {}
         ~ParserStack() {}
         template<typename ValueType> ValueType pop() {
           ValueType result = PARSE_STACK_VALUE(internalStack.back().first, ValueType);
           internalStack.pop_back();
           return result;
         }
         template<typename ValueType> ValueType peek(int offsetFromTop) {
           return PARSE_STACK_VALUE(internalStack.at(internalStack.size() - 1 - offsetFromTop).first, ValueType);
         }
         StackElementType peekType(int offsetFromTop) {
           return internalStack.at(internalStack.size() - 1 - offsetFromTop).second;
         }
         template<typename ValueType> void push(ValueType value, StackElementType type) {
           internalStack.push_back(std::pair<StackValueType, StackElementType>(value, type));
         }
         int size() { return internalStack.size(); }
    };
}

#define PARSE_STACK parserGenerator::ParserStack<PARSE_STACK_VALUE_TYPE, PARSE_STACK_ELEMENT_TYPE>

#endif