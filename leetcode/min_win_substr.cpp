#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> t_count(128, 0);
        vector<int> window_count(128, 0);

        for (char c : t) {
            t_count[c]++;
        }

        int left = 0;
        int required_chars = 0; 
        int unique_t_chars = 0;

        for (int count : t_count) {
            if (count > 0) unique_t_chars++;
        }

        int min_len = INT_MAX;
        int start_idx = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];
            window_count[c]++;

            if (t_count[c] > 0 && window_count[c] == t_count[c]) {
                required_chars++;
            }

            while (required_chars == unique_t_chars) {
                int current_window_len = right - left + 1;
                
                if (current_window_len < min_len) {
                    min_len = current_window_len;
                    start_idx = left;
                }

                char left_char = s[left];
                window_count[left_char]--;

                if (t_count[left_char] > 0 && window_count[left_char] < t_count[left_char]) {
                    required_chars--;
                }
                
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};