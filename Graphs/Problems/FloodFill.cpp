#include <bits/stdc++.h>
using namespace std;

// LC-733 : Sheet
//TC : O(4*(mxn) + mxn ) 
//because every cell you are checking 4 direction so mxn for every cell movement and for each cell 4x(mxn) 
//4 constant for directions check at every call =>  O(mxn)
class Solution
{
public:
    vector<vector<int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void DFS(vector<vector<int>> &image, int sr, int sc, int color, int srcColor, int m, int n)
    {
        image[sr][sc] = color;

        for (auto &dir : dirs)
        {
            int x_ = sr + dir[0];
            int y_ = sc + dir[1];

            if (x_ >= 0 && x_ < m && y_ >= 0 && y_ < n && image[x_][y_] == srcColor)
                DFS(image, x_, y_, color, srcColor, m, n);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        // take the value of src and color it with the color given and wherever there is src color in
        //  4 directions color it with that
        int m = image.size();
        int n = image[0].size();

        int srcColor = image[sr][sc];

        if (srcColor == color) // then no need to change
            return image;

        DFS(image, sr, sc, color, srcColor, m, n);
        return image;
    }
};


int main()
{

    return 0;
}