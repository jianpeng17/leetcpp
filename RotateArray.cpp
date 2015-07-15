#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]
Hint:
Could you do it in-place with O(1) extra space?

Related problem: Reverse Words in a String II

*/

using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n==0)
            return;
        k=k%n;
        int arr[n];
        for(int i=n-k, j=0; i<n; i++, j++)
            arr[j]=nums[i];
        for(int i=0, j=k; i<n-k; i++, j++)
            arr[j]=nums[i];
        for(int i=0;i<n;i++)
            nums[i]=arr[i];
        return;
    }
};

/*
class Solution {
    public: void rotate(int nums[], int n, int k)
    {
        int * temp = new int [n];
        if(k>n) k = k%n;
        memcpy(temp,nums+n-k,ksizeof(int));
        memcpy(temp+k,nums,(n-k)sizeof(int));
        memcpy(nums,temp,n*sizeof(int));
    }
};
*/

/*
void reverse(int *nums , int begin , int end){
int tmp;
while(begin<end){
    tmp=nums[begin];
    nums[begin]=nums[end];
    nums[end]=tmp;
    begin++;
    end--;
}
}

void rotate(int* nums, int numsSize, int k) 
{
if(k==0 || k==numsSize)
    return;
if(numsSize==0 )
  return;

reverse(nums,0,numsSize-1);
7,6,5,4,3,2,1
if(k>numsSize)
    k=k%numsSize;
if(numsSize-k!=0){


reverse(nums,0,k-1);
5,6,7,4,3,2,1
reverse(nums,k,numsSize-1);   
5,6,7,1,2,3,4
}

}

*/

int main()
{
    int a[]={1,2,3,4,5};
    Solution s;
    s.rotate(a,5,2);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";

    return 1;
}

