class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         unordered_set<string>us(deadends.begin(),deadends.end());
        unordered_set<string>visited;
        queue<string>q;
        if(us.find("0000")!=us.end()){
            return -1;
        }
        if(target=="0000"){
            return 0;
        }
        q.push("0000");
        visited.insert("0000");
        int level=0;
        while(!q.empty()){
            int count=q.size();
            for(int j{0};j<count;j++){
                string curr=q.front();
                for(int i{0};i<4;++i){
                    string x=curr;
                    
                    if(x[i]=='9')
                        x[i]='0';
                    else 
                        x[i]=x[i]+1;
                    
                    if(visited.find(x)==visited.end() && us.find(x)==us.end()){
                        if(x==target){
                            return level+1;
                        }
                        visited.insert(x);
                        q.push(x);
                    }
                    x=curr;
                    if(x[i]=='0')
                        x[i]='9';
                    else 
                        x[i]=x[i]-1;
                    if(visited.find(x)==visited.end() && us.find(x)==us.end()){
                        if(x==target){
                            return level+1;
                        }
                        visited.insert(x);
                        q.push(x);
                    }
                }
                q.pop();
            }
            level++;
        }
        return -1;
    }
};