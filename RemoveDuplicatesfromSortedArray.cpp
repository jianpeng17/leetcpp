#include<iostream>
using namespace std;

/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j=0;
        if (A==NULL)
            return 0;
        for (int i=0;i<n-1;i++)
        {
            if(A[i]<A[i+1])
                A[++j] = A[i+1];
            //if(A[i]==A[i+1])
            //    A[j]=A[i];
        }
        return j+1;
    }
};

int main()
{
    int a[8] = {1,2,2,3,3,3,3,4};
    Solution s;
    int len = s.removeDuplicates(a,8);
    cout<<"new length is "<<len<<endl;
    for(int i = 0;i<len;i++)
        cout<<"a["<<i<<"] is " << a[i]<<endl;
}
