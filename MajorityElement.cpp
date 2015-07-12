#include <iostream>
#include <map>
#include <vector>


/*

Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Runtime: O(n) ¡ª Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number¡¯s ith bit must be the one bit that has the greater count.

Runtime: O(n log n) ¡ª Sorting: As we know more than half of the array are elements of the same value, we can sort the array and all majority elements will be grouped into one contiguous chunk. Therefore, the middle (n/2th) element must also be the majority element.


*/

/*
My Note
s1, todo
s2, sort, get the middle number
s3, map<key, count>

*/

using namespace std;
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int size = num.size();
        map<int, int> mmap;
        for(vector<int>::iterator itor = num.begin(); itor!=num.end(); itor++)
        {
            if (mmap.find(*itor) != mmap.end())
            {
                mmap[*itor] += 1;
            }
            else
            {
                mmap.insert(make_pair(*itor, 1));
            }
        }

        for(map<int, int>::iterator itor = mmap.begin(); itor!=mmap.end(); itor++)
        {
            int key = itor->first;  // itor->first is the key number
            if(mmap[key] > size/2)
                return key;
        }

    }
};


int main()
{
    int a[10] = {1,2,3,3,3,3,3,3,3,3};
    vector<int> vec(a,a+10);
    Solution s;
    int result = s.majorityElement(vec);
    cout<<"result is "<<result<<endl;

    return 1;
}

