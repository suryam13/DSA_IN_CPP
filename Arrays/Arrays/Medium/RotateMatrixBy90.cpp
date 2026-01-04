#include <bits/stdc++.h>
using namespace std;

/*
brute- T.C. O(N2)  S.C. O(N2)

//create a new matrix and map the values through logical formulae

#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));

    //or either can use row=0 and col=n-1 to avoid the formula part for linking the matrix

    //int col=0;
    for (int i = 0; i < n; i++) {
    //int row=0
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
        //rotated[row][col] = matrix[i][j];
        //row++
    }
    col--;
    }
    return rotated;
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "n";
    }

}


*/

/*
Optimal Approach-
//T.C. mentioned inside the loops particulatly
//S.C. O(1)

   void rotate(vector<vector<int>>& matrix) {

    //T.C O(N*N/2)
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int i=0;
        int j=matrix[0].size()-1;


        //alternate method to reverse rows
        //O(n*n/2)
        // while(i<=j)
        // {
        //     for(int s=0;s<matrix[0].size();s++)
        //     {
        //         swap(matrix[s][i],matrix[s][j]);
        //     }
        //     i++;
        //     j--;

        // }



        //reverse all the rows

        for(int i=0;i<matrix.size();i++)
        reverse(matrix[i].begin(),matrix[i].end());
    }


*/
int main()
{

    return 0;
}