class Solution {
public:
     map<pair<int,vector<int>> ,int> m;
    int maxCount(vector<string> &words, int i, vector<int> &freq, vector<int>&score) {
        if(i >= words.size()) return 0;
        if(m.find({i, freq}) != m.end()) return m[{i, freq}];
        //if word can be formed or not from the available letters
        bool isPossible = true;
        vector<int> temp = freq;
        int scoreTemp = 0;
        for(int j = 0; j < words[i].length(); j++) {
            if(temp[words[i][j] - 'a'] - 1 < 0) {
                isPossible = false;
                break;
            }
            temp[words[i][j] - 'a']--;
            scoreTemp += score[words[i][j] - 'a'];
        }
        //take it
        int op1 = 0;
        
        if(isPossible) {
            op1 = scoreTemp + maxCount(words, i + 1, temp, score);
        }
        //not taking it
        int op2 = maxCount(words, i + 1, freq, score);
        return m[{i, freq}] = max(op1, op2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(int i = 0; i < letters.size(); i++) {
            freq[letters[i] - 'a']++;
        }
        return maxCount(words, 0, freq, score);
    }
};