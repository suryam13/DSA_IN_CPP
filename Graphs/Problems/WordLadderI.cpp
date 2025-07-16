#include <bits/stdc++.h>
using namespace std;

// LC-127 Sheet
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    /*
    Approach:In this i'll be using a bfs approach as the shortest path is been asked and would be changing
    the  character one by one and when i get the final word depending upon the level that would be the
    shortest transformation time
    */

    unordered_set<string> words(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    int level = 1;
    int length = beginWord.size();

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            string topy = q.front();
            q.pop();

            if (topy == endWord)
                return level; // we got the shortest transformation length word

            // we have 'length' letter words so for each position we will be figuring out which word formed is
            // present in set or not
            for (int i = 0; i < length; i++)
            {
                string dummy = topy;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    dummy[i] = ch;
                    if (words.count(dummy)) // means valid word
                    {
                        q.push(dummy);
                        words.erase(dummy); // earse as we dont want to take the same word again in future
                        // eg : dog -> mog ..then we can again get mog-->dog
                    }
                }
            }
        }
        level++;
    }

    return 0;
}
int main()
{

    return 0;
}