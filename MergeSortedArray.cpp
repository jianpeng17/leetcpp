#include <iostream>
#include <set>
#include <vector>
#include "string.h"


/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

*/


/*
My Note
arrange the array from back to front

*/


using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        std::multiset<int> mySet;  // using set will delete duplicate
        for(int i=0;i<m;i++)
            mySet.insert(A[i]);
        for(int j=0;j<n;j++)
            mySet.insert(B[j]);
        int totoal = m+n;
        memset(A, 0, sizeof(int)*(m+n));
        int index = 0;
        for(std::multiset<int>::iterator itor = mySet.begin(); itor != mySet.end(); itor++)
            A[index++] = *itor;
    }
};

class Solution2 {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1, k= m+n-1;
        while(i>=0 && j>=0)
        {
             //A[k--] = A[i--] ? B[j--] : A[i]>B[j];// wrong
             A[k--] = A[i] > B[j] ? A[i--]:B[j--];
             cout<<"i is " << i<<", j is "<< j<<endl;
        }


        while (j>=0)  // this is to prevent A is empty
            A[k--] = B[j--];

    }
};

int main()
{
    int A[10] = {1,3,5,7,9};
    int B[5] = {2,4,6,8,10};
    Solution2 s;
    s.merge(A,5,B,5);
    for(int i = 0; i<10; i++)
        cout<<A[i]<<endl;


    return 1;
}

