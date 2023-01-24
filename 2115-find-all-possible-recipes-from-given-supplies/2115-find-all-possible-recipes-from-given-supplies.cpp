class Solution
{
    public:
        vector<string> findAllRecipes(vector<string> &recipes, vector<vector< string >> &ingredients, vector< string > &supplies)
        {
            unordered_map<string, vector < string>> post_ingred;
            unordered_map<string, int> indegree;
            for (int i = 0; i < recipes.size(); i++)
            {
                for (auto &item: ingredients[i]) post_ingred[item].push_back(recipes[i]);
                indegree[recipes[i]] = ingredients[i].size();
            }
            queue<string> q;
            vector<string> ans;
            for (auto &supply: supplies) q.push(supply);
            while (q.size())
            {
                string curr = q.front();
                q.pop();
                for (auto &post: post_ingred[curr])
                {
                    indegree[post]--;
                    if (indegree[post] == 0)
                    {
                        ans.push_back(post);
                        q.push(post);
                    }
                }
            }
            return ans;
        }
};