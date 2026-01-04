#include <bits/stdc++.h>
using namespace std;

/*
Bruteforce Approach-to go and mark -1 in that particular row and col except where there are 0's because that would hinder the behaviour as we have to check for that 0 too

T.C-O( (nxm)x(n+m)+nxm )  //the last n x m is for placing the zeros at -1 while traversal
near about O(N3)
S.C-O(1)


    void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
   }


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}





#include <bits/stdc++.h>
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {




    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }



      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
          }

          return matrix;
}

*/

/*
Better Approach-to store the 0 element occuring index in additional tqo arrays of rows and cols
T.C-O(nxm + nxm)
S.C-O(n)+O(m)

        //     int m=matrix.size();
        //     int n=matrix[0].size();

        //    int *rows=new int[m];
        //    int *cols=new int[n];

        //    fill_n(rows,m,0);
        //    fill_n(cols,n,0);

        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);
        //intitially set all the locations as zeroes


        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1; //update in this array as 1 to keep the track of zero occuring
                    cols[j] = 1;
                }
            }
        }

        //aim is to set th entire row and cols 0 if 0 occurs at any index in the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (rows[i] == 1 || cols[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
*/

int main()
{

    return 0;
}