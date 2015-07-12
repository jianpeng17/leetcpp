#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


*/

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.empty())
            return result;
        sort(num.begin(), num.end());
        int len = num.size();
        for(int i=0; i<len-2; i++)
        {
            if (i>0 && num[i-1]==num[i]) continue;
            if(num[i]>0)
                break;
            int j = i+1, k=len-1;
            while(j<k)
            {
                vector<int> vec;
                if(num[i] + num[j] + num[k] == 0)
                {
                    vec.push_back(num[i]);
                    vec.push_back(num[j]);
                    vec.push_back(num[k]);
                    result.push_back(vec);
                    while(j<k && num[j]==num[j+1])
                        j++;
                    j++;
                    while(j<k && num[k]==num[k-1])
                        k--;
                    k--;
                }
                else if (num[i] + num[j] + num[k] < 0)
                {
                    while(j<k && num[j]==num[j+1])
                        j++;
                    j++;
                }
                else if (num[i] + num[j] + num[k] > 0)
                {
                    while(j<k && num[k]==num[k-1])
                        k--;
                    k--;
                }
            }
        }
        return result;

    }
};

int main()
{

    Solution s;
    int A[] = {-2,0,0,0,1,1};
    vector<int> vec(A, A+6);
    vector<vector<int>> result = s.threeSum(vec);
    cout<<"debug"<<endl;
    for(vector<vector<int>>::iterator itor = result.begin(); itor != result.end(); itor++)
    {
        for(vector<int>::iterator it = itor->begin(); it != itor->end(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }

    return 1;
}

