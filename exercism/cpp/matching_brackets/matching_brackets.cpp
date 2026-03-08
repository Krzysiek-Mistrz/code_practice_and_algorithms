#include "matching_brackets.h"


namespace matching_brackets
{
    
    bool check(std::string input) {
    std::stack<char> stack;

    for (auto ch : input) {
        if (ch == '{' or ch == '[' or ch == '(') {
            stack.push(ch);
        } else if (ch == '}' or ch == ']' or ch == ')') {
            if (stack.empty()) {
                return false;
            } else {
                if (ch == '}' and stack.top() != '{') {
                    return false;
                } else if (ch == ']' and stack.top() != '[') {
                    return false;
                } else if (ch == ')' and stack.top() != '(') {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
    }

    return stack.empty();
}

} // namespace matching_brackets
