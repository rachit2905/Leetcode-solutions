//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool safe(string a ,string b)
  {
      int n = a.length() ;
      int i =0 ,c= 0 ; 
      while(i<n )
      {
          if(a[i]!=b[i])c++;
          i++ ;
      }
     return c==1? 1:0;  
  }

    int wordLadderLength(string start, string target, vector<string>& wordList) {
        // Code here
    map<string , int >vis ; 
    map<string , vector<string>> adj ;
    int n = wordList.size() ;
    
    for(int i = 0; i<n ;i++)
    {
        if(safe(start , wordList[i]))
        {
            adj[wordList[i]].push_back(start) ;
            adj[start].push_back(wordList[i]) ;
        }
    }
    
    for(int i = 0; i<n ;i++)
    {
        for(int j =0 ;j<n ;j++)
        {
            if(i!=j && safe(wordList[i] ,wordList[j]))
            {adj[wordList[i]].push_back(wordList[j]) ;
            adj[wordList[j]].push_back(wordList[i]) ;}
            
            
        }
    }
    queue<pair<string ,int >> q ; 
    q.push({start, 0 }) ; 
    vis[start]=1 ;
    
    while(!q.empty())
    {
        string node = q.front().first ;
        int step= q.front().second ;
        q.pop() ;
        if(node==target)
        return step+1 ;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1 ;
                q.push({it, step+1}) ;
            }
        }
    }
       return 0 ; 
    }
};


//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends