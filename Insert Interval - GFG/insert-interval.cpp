//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution

{

public:

    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent)

    {

        vector<vector<int>> answer;

        int newstart = newEvent[0];

        int newend = newEvent[1];

        bool flag = false;

        for (int i = 0; i < N; i++)

        {

            int tempone = intervals[i][0];

            int temptwo = intervals[i][1];

            if (newstart > temptwo)

            {

                answer.push_back({tempone, temptwo});

            }

            else if (newend < tempone)

            {

                if (flag == false)

                {

                    answer.push_back({newstart, newend});

                    flag = true;

                }

                answer.push_back({tempone, temptwo});

            }

            else

            {

                newstart = min(tempone, newstart);

                newend = max(temptwo, newend);

            }

        }

                    if(flag==false)

            {

                answer.push_back({newstart,newend});

            }

        return answer;

    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends