/**
 * @file merge_sort.cpp
 * @author Ahmed Shehatah  (ahmed2002.eg@gmail.com)
 * @brief Merge Sort is a Divide and Conquer algorithm. 
 * It divides the input array into two halves, calls itself for the two halves,
 *  and then merges the two sorted halves.
 *  The merge() function is used for merging two halves. 
 * 
 * time complexity O(nLog(n))
 * 
 * @version 0.1
 * @date 2021-12-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;
void merge(int *A, int szA, int *B, int szB)
{
    int *C = new int[szA + szB];
    int idxA = 0, idxB = 0, idxC = 0;
    // this loop compares the two array elements and puts the smaller first
    while (idxA < szA && idxB < szB)
        C[idxC++] = (A[idxA] < B[idxB] ? A[idxA++] : B[idxB++]);
    // in the next two loops either will work the bigger half
    while (idxA < szA)
        C[idxC++] = A[idxA++];
    while (idxB < szB)
        C[idxC++] = B[idxB++];
    // this loop assgins the sorted array to main array
    for (int i = 0; i < szA + szB; i++)
        A[i] = C[i];
    // this code deletes the helper array for memory leaking
    delete[] C;
}
void mergeSort(int *A, int sz)
{
    // base case if the array is less than 2 then it must be sorted so don't do anything
    if (sz < 2)
        return;
    int half = sz / 2;
    // this sorts the first half of the array
    mergeSort(A, half);
    // this sorts the second half of the array
    mergeSort(A + half, sz - half);
    // this part merges the two halves of the array
    merge(A, half, A + half, sz - half);
}
int main()
{
    // init the array
    int B[] = {4, 9, 8, 7, 1, 3, 56, 34};
    mergeSort(B, 8);
    for (int i = 0; i < 8; i++)
        cout << B[i] << " "[i == 7];
    return 0;
}