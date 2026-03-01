/*
Given a string containing brackets [], braces {}, parentheses 
(), or any combination thereof, verify that any and all pairs 
are matched and nested correctly. Any other characters should 
be ignored. For example, "{what is (42)}?" is balanced and 
"[text}" is not.
*/

#pragma once

#include <string>
#include <stack>


namespace matching_brackets {

bool check(std::string input);

}  // namespace matching_brackets
