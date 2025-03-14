#include<bits/stdc++.h>
using namespace std;
//LC - 207
//If there is a cycle then impossible to complete the number of courses

/*
TC- O(V+E)
SC- O(V+E) for graph making and O(V) for vertices storage in queue
*/


//BFS Approach for cycle detection in directed graph using Kahns algorithm
/*

 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        /*
        over here there is dependency means 1 has to be completed before 0 
        means when its possible to write toplogical sort means we can complete the courses and thereby 
        return true

        It is a directed Graph since the second should be completed before 1st 

        if we fall in loop/cycle then its not possible to complete the courses,so using kahns algorithm
        (bfs) to check whether a cycle exists

        numCourses - 3
        prerequisites - [[1,0],[2,1],[0,2]]

        consider this test case it forms loop hence false,not possible to complete all the 3 courses
        */

        //making adj list
    //     unordered_map<int,vector<int>> mapy;
    //     for(auto &edge:prerequisites)
    //     {
    //         int first= edge[0];
    //         int second= edge[1];

    //         //second-->first
    //         mapy[second].push_back(first);
    //     }

    //     vector<int> inDegree(numCourses);
    //     //now marking the inDegrees
    //     for(auto &vertex:mapy)  //return an iterator 
    //     {
    //         for(auto &edges:vertex.second) //2nd parameter of iterator returns vector so on that for elem
    //         inDegree[edges]++;
    //     }

    //     //pushing the inDegree 0 vertcies to the queue
    //     queue<int> q;
    //     for(int i=0;i<inDegree.size();i++)
    //     {
    //         if(inDegree[i]==0) //so push into the queue
    //         q.push(i);
    //     }  


    //     int cnt=0;
    //     while(!q.empty())
    //     {
    //         int u=q.front();
    //         cnt++;//means these many has been visited into the queue
    //         q.pop();

    //         for(int &v:mapy[u]) //go onto each edges
    //         { 
    //             inDegree[v]--; //as one load is been popped out as parent is out
    //             if(inDegree[v]==0) //so push into the queue
    //             q.push(v);
    //         }
    //     }

    //     if(cnt==numCourses) //means it was possible to complete all the courses 
    //     return true; 

    //     return false;
   
    // }
    
 int main()
{
    
    return 0;
}