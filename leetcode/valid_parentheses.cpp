#include <iostream>
#include <stack>


/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        for (const auto& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if (!stack.empty() && 
                    (stack.top() == '(' && ch == ')' || 
                    stack.top() == '{' && ch == '}' ||
                    stack.top() == '[' && ch == ']')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};


int main(int argc, char** argv) {
    Solution sol;
    std::cout << sol.isValid("]") << std::endl;
}