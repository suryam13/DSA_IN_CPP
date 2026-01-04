/*
Divide and Conquer
Best Case-
T.C.O(NLogN)
S.C.O(1)//it uses stack space but doesnt need an extra array space(auxillary space) unlike in merge sort
but talking about stack space that would be the maximum depth of the tree which would be logN


Worst Case-
T.C.O(N2)
S.C.no auxillary space but stack space would be O(N) as that would be the depth in recursion tree


in worst case suppose the array is sorted prior only then it would be O(N2)

STEP 1- Pick a pivot element element,it can be any element in the array and place it in its correct place in accordance with the sorted array

STEP 2-Smaller elements on the left side whereas larger on the right side

Apply the same operation recursively
*/

#include <bits/stdc++.h>
using namespace std;

// taking last element as pivot
void quickSort(vector<int> &arr, int low, int high)
{

    // if there is no element left then return
    if (low > high) // over here it wont be low==high because suppose 9 7 (4,5) so here the pivind returned would be 4 so next when left half would be called then the call will be made for 4,3 so here it is irrelevant;
        return;

    // get the partition index
    int pIndex = partition(arr, low, high);
    // calling for the right half
    quickSort(arr, pIndex + 1, high);
    // calling for the left half
    quickSort(arr, low, pIndex - 1);
}
int partition(vector<int> &arr, int low, int high)
{

    // now lets consider the last element as pivot
    int pivot = arr[high];
    int i = low;
    int pivind = low;
    // initially we are considering that pivot index would be on low that is at the start

    while (i < high) // no need to go till the end becuase the last one is itself pivot and needs to be swapped
    {
        // as we are sorting the array in asc order so we want that when the pivot is swapped at the right side all should be greater
        // so if the current is smaller then it is a problem eg 8 3 4 6 5 if the pivot 5 is swapped then 3 would go on right and would not follow the pattern
        // so we will swap it with 8 and do pivind++ so that it again points at 8

        if (arr[i] < pivot)
        {
            swap(arr[i], arr[pivind]);
            pivind++;
        }
        i++;
    }
    swap(arr[pivind], arr[high]);
    return pivind;

    // to take the first element as pivot
    /*
    int partition(vector<int>& arr, int low, int high) {

        //now lets consider the first element as pivot
        int pivot=arr[low];
        int i=high;
        int pivind=high;
        //initially we are considering that pivot index would be on high that is at the end

        while(i>low) //no need to go till the first becuase the first one is itself pivot and needs to be swapped
        {

            //so it means when the pivot goes on the right side everything at left should be smaller and right should be greater
            //so means agar pivind value chota hai toh hi sahi rahega
            //so means if arr[i] bada then issue

            if(arr[i]>pivot)
            {
                swap(arr[i],arr[pivind]);
                pivind--;
            }
            i--;
        }
        swap(arr[pivind],arr[low]);
        return pi
    */
}
int main()
{

    return 0;
}
