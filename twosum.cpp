#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
//#include<boost/unordered_map.hpp>
using namespace std;

/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
My Note
because the array is not ordered, can not use two pointers
the slow way is iterate the array, get the sub, then find if it is in the array  (what if the sub is equal to the key, 4, 4 -> 8)
construct a map, the key is the array number, the value is the index

*/


// slow
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> output;
    int i,j;
      for(vector<int>::iterator itor = numbers.begin();itor!=numbers.end();itor++)
         {
            int sub = target - *itor;
            cout<<"sub is "<<sub<<endl;
            vector<int>::iterator it = find(numbers.begin(),numbers.end(),sub);
            if ( it != numbers.end() )
            {
                i = itor - numbers.begin()+1;
                j = it - numbers.begin()+1;

                output.push_back(i);
                output.push_back(j);

                return output;
            }

         }
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> output;

    std::unordered_map<int, int> tmpMap;
    //std::multimap<int, int> tmpMap;

    for(vector<int>::iterator itor = numbers.begin();itor!=numbers.end();itor++)
    {
        tmpMap.insert( make_pair(*itor, itor-numbers.begin()) ); //according to effective stl, this is more effective
    }

    for(vector<int>::iterator itor = numbers.begin();itor!=numbers.end();itor++)
    {
        int sub = target - *itor;
        //if (sub == *itor)  // for 3+3 = 6
         //   continue;
        std::unordered_map<int, int>::iterator it = tmpMap.find(sub);
        if (it!=tmpMap.end() && (tmpMap[sub] > tmpMap[*itor]) )
        {
            output.push_back(tmpMap[*itor]+1);
            output.push_back(tmpMap[sub]+1);
            return output;
        }
    }

    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> mapping;
    vector<int> result;
    for (int i = 0; i < numbers.size(); i++) {
        mapping[numbers[i]] = i;
    }

    for ( auto it = mapping.begin(); it != mapping.end(); ++it )
    std::cout << " " << it->first << ":" << it->second;
  std::cout << std::endl;

    for (int i = 0; i < numbers.size(); i++) {
        const int gap = target - numbers[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
        }
    }
    return result;

    }
};

// compile with c++11 option

// jima1, for key "0", it is stored once in unordered_map, 0:3
//int arr[] = {0,4,3,0};

int main()
{
    //int arr[] = {3,2,7,9,0,4};
    // int arr[] = {3,2,4};
    int arr[] = {0,4,3,0};
    vector<int> a (arr, arr+sizeof(arr)/sizeof(int));
    int target = 0;
    Solution2 s;
    vector<int> result = s.twoSum(a,target);
    for(vector<int>::iterator itor = result.begin();itor!=result.end();itor++)
        cout<<"index is " << *itor<<endl;
}
