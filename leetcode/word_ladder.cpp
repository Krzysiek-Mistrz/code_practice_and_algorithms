#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int ladder = 1;

        while (!q.empty()) {
            int count = q.size();
            
            for (int i = 0; i < count; ++i) {
                string word = q.front();
                q.pop();

                if (word == endWord) return ladder;

                for (int j = 0; j < word.length(); ++j) {
                    char original_char = word[j];
                    
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        
                        if (words.count(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[j] = original_char;
                }
            }
            ladder++;
        }

        return 0;
    }
};