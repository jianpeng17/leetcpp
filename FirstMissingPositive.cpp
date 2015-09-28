#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
 Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

using namespace std;



int firstMissingPositive(int A[], int n) {
    int arr[n];
    memset(arr, 0, n*sizeof(int));
    cout<<"size of arr is " << sizeof(arr)<<endl;
    // if not initialized, is it all zero?  NO!!!!
    // memset is set by each byte, so
    /*
    for(int i=0; i<n; i++)
        arr[i]=0;
    */
    for(int i=0; i<n; i++)
    {
        int k=A[i];
        if (k>0 && k<=n)
            arr[k-1]=k;
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
            return i+1;
    }
    return n+1;
}

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        bitset<n> bs; //  not initialized with a constant expression|
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0 && nums[i]<=n)
            bs.set(nums[i]-1);
        }
        for(int i=0; i<n; i++)
        {
            if(bs[i] == false)
                return i+1;
        }
        return n+1;
    }
};

//#define test(a[])


int main()
{
    int test[10];
    for(int i=0; i<10; i++)
        cout<<" i is "<<test[i]<<endl;
    int a1[] = {-1,3,4};
    int a2[] = {1,2,3};
    //Solution s;
    int r1 = firstMissingPositive(a1,3);
    int r2 = firstMissingPositive(a2,3);
    assert(r1==1);
    assert(r2==4);
    return 1;
}

