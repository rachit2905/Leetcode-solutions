//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        // code here
        int n = wordList.size();
        vector<int> adj[n + 1];
        //Firstly, we make our graph 
        for(int i = 0; i < n; i++){
            string curr1 = wordList[i];
            for(int j = i + 1; j < n; j++){
                string curr2 = wordList[j];
                int cnt = 0;
                for(int k = 0; k < curr2.length(); k++){
                    if(curr1[k] != curr2[k]){
                        cnt++;
                    }
                }
                if(cnt == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int src = -1;
        int dest = -1;
        for(int i = 0; i < n; i++){
            if(startWord == wordList[i]){
                src = i;
            }
            else if(targetWord == wordList[i]){
                dest = i;
            }
        }
        vector<vector<string>> ans;
        if(dest == -1){
            return ans;
        }
        if(src == -1){
            if(startWord.length() != targetWord.length()){
                return ans;
            }
            for(int i = 0; i < n; i++){
                string curr = wordList[i];
                int cnt = 0;
                for(int k = 0; k < curr.length(); k++){
                    if(startWord[k] != curr[k]){
                        cnt++;
                    }
                }
                if(cnt == 1){
                    adj[n].push_back(i);
                    adj[i].push_back(n);
                }
            }
            src = n;
        }
        queue<pair<int, vector<string>>> q;
        vector<string> curr;
        curr.push_back(startWord);
        q.push({src, curr});
        vector<bool> visited (n, false);
        bool isFound = false;
        while(q.empty() == false){
            int sz = q.size();
            for(int cnt = 0; cnt < sz; cnt++){
                auto curr = q.front();
                q.pop();
                visited[curr.first] = true;
                if(curr.first == dest){
                    isFound = true;
                    ans.push_back(curr.second);
                }
                for(auto &e : adj[curr.first]){
                    if(visited[e] == false){
                        curr.second.push_back(wordList[e]);
                        q.push({e, curr.second});
                        curr.second.pop_back();
                    }
                }
            }
            if(isFound){
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends