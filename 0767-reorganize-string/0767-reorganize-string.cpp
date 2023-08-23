class Solution {
public:
    string reorganizeString(string s) {
         sort(s.begin(), s.end());
        string answer = "";
        answer += s[0];
        int fill_index = s.size() - 1;
        int i;
        for(i = 1; i < s.size(); i++){
            if(i > fill_index) break;
            if(s[i] == s[i-1]){
                if(s[i] == s[fill_index]) break;
                answer += s[fill_index];
                fill_index--;
            }
            answer+=s[i];
        }
        cout<<answer;
        int starting_index = -1;
        for(int j = i; j <= fill_index; j++){
            starting_index += 1;
            bool condition = false;
            if(starting_index == answer.size()) return "";
            for(int k = starting_index; k <= answer.size(); k++){
                if(k == 0){
                    if(answer[k] != s[fill_index]){
                        answer.insert(k, 1, s[fill_index]);
                        condition = true;
                        break;
                    }
                }else if (k == answer.size()){
                    if(answer[k - 1] != s[fill_index]){
                        answer += s[fill_index];
                        condition = true;
                        break;
                    }
                }
                if(answer[k] != s[fill_index] && answer[k - 1] != s[fill_index]){
                    answer.insert(k, 1, s[fill_index]);
                    condition = true;
                    break;
                }
            }
            if(!condition) return "";
        }
        return answer;
    }
};