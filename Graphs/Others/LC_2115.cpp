#include<bits/stdc++.h>
using namespace std;


vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
    //Kahn Algo - topo sort

    // creating an adjacency list
    unordered_map<string, vector<string>> adj;  
    unordered_map<string, int> inDegree;
    vector<string> ans; //final answer storage
    unordered_set<string> st(recipes.begin(), recipes.end()); //to check for inserting into ans whether it 
    //belongs to the recipe or not when inDegree is 0

    for (int i = 0; i < recipes.size(); i++) {
        for (int j = 0; j < ingredients[i].size(); j++) {
            adj[ingredients[i][j]].push_back(recipes[i]);
        }
    }
    // here we are storing which ingredient is required to make that recipe in the adj list so doing reverse 
    //mapping

    // for(auto &[key,value]:adj)
    // {   cout<<key<<"->";
    //     for(auto &val:value)
    //     {
    //         cout<<val<<" ";
    //     }
    //     cout<<endl;
    // }


    for(auto &str:supplies)  //the ones in the supply would be having indegree 0 as they are not dependent on 
    //others 
    {
        inDegree[str]=0;
    }

    // calculating inDegree of each item 
    for (auto& value : adj) { 
        for (auto& val : value.second) {
            inDegree[val]++;
        }
    }

    queue<string> q;
    for (auto& value: inDegree) {
        if (value.second == 0)
            q.push(value.first);
    }

    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (st.find(u) != st.end()) //if it exists in the recipe then push
            ans.push_back(u);

        for (auto& v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return ans;
}
 int main()
{
    
    return 0;
}