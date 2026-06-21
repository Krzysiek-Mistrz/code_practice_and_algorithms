#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        int s_len = s.length();

        unordered_map<string, int> word_counts;
        for (const string& w : words) {
            word_counts[w]++;
        }

        for (int i = 0; i < word_len; ++i) {
            int left = i;
            int right = i;
            unordered_map<string, int> current_counts;
            int words_used = 0;

            while (right + word_len <= s_len) {
                string word = s.substr(right, word_len);
                right += word_len;

                if (word_counts.count(word)) {
                    current_counts[word]++;
                    words_used++;

                    while (current_counts[word] > word_counts[word]) {
                        string left_word = s.substr(left, word_len);
                        current_counts[left_word]--;
                        words_used--;
                        left += word_len;
                    }

                    if (words_used == num_words) {
                        result.push_back(left);
                    }
                }
                else {
                    current_counts.clear();
                    words_used = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};