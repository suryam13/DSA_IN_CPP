#include<bits/stdc++.h>
using namespace std;
 int trap(vector<int>& height) {

        //storing the max in the previous entire as well as the next max entire (not just next max,its entire range max)
        vector<int> preMax(height.size());
        vector<int> suffMax(height.size());

        int maxi = height[0];
        for (int i = 0; i < height.size(); i++) {
            preMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }

        maxi = height[height.size() - 1];
        for (int j = height.size() - 1; j >= 0; j--) {
            suffMax[j] = maxi;
            maxi = max(maxi, height[j]);
        }

        int cnt = 0;
        for (int i = 0; i < height.size(); i++) {
            //if its less then only that position can hold water
            if (preMax[i] > height[i] && suffMax[i] > height[i]) {
                cnt += min(preMax[i], suffMax[i]) - height[i];
            }
        }
        return cnt;
    }
 int main()
{
    
    return 0;
}