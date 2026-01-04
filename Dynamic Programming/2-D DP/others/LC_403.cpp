// class Solution
// {
// public:
//     // 0 means nil,1 means true,-1 means false
//     bool helper(vector<int> &stones, unordered_set<int> &st, int currValue, int prevJump, int target, map<pair<int, int>, int> &mapy)
//     {
//         if (currValue == target)
//             return true;

//         for (int i = -1; i <= 1; i++)
//         {
//             int nextJump = prevJump + i;

//             if (nextJump == 0)
//                 continue;
//             // since going on that again again would cause TLE

//             int nextValue = currValue + nextJump;

//             if (mapy[{nextValue, nextJump}] != 0)
//             {
//                 if (mapy[{nextValue, nextJump}] == -1) // means i have explored this path earlier which resulted in false so don't go
//                     continue;
//             }

//             if (st.count(nextValue)) // is theres s valid stones in the set or not
//             {
//                 if (helper(stones, st, nextValue, nextJump, target, mapy))
//                     return true;

//                 // store the result of the path as -1 that is negative
//                 mapy[{nextValue, nextJump}] = -1;
//             }
//         }

//         return false;
//     }

//     bool canCross(vector<int> &stones)
//     {

//         // Memoization (top-bottom)
//         int n = stones.size();
//         map<pair<int, int>, int> mapy;
//         // for memoization

//         unordered_set<int> st; // for storing the valid stones possible
//         for (auto &el : stones)
//             st.insert(el);

//         if (stones[1] != stones[0] + 1)
//             return false;
//         // the initial jump is exactly 1 and the array is sorted so should follow the condition
//         return helper(stones, st, 1, 1, stones[n - 1], mapy);
//     }
// };