#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int j = i + 1;
            int line_length = words[i].length();
            
            while (j < n && line_length + 1 + words[j].length() <= maxWidth) {
                line_length += 1 + words[j].length();
                j++;
            }
            
            int num_words = j - i;
            string line = "";
            
            if (j == n || num_words == 1) {
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            }
            else {
                int total_spaces = maxWidth - (line_length - (num_words - 1));
                int base_spaces = total_spaces / (num_words - 1);
                int extra_spaces = total_spaces % (num_words - 1);
                
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces_to_add = base_spaces + (k - i < extra_spaces ? 1 : 0);
                        line += string(spaces_to_add, ' ');
                    }
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};