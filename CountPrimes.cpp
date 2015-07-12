#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <assert.h>
/*
Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Hint:

    Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n2). Could we do better?

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

// Time Limit Exceeded
class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        for(int i=1; i<=n; i++)
        {
            if(isPrime(i))
                count++;
        }
        return count;
    }
    // is 1,2 prime?
    bool isPrime1(int n)
    {
        if (n == 1) return false;
        if (n == 2) return true;
        int divide = n/2;
        for(int i=2; i<=divide; i++)
        {
            //cout<<"i is "<<i<<endl;
            if ( i&1 == 0)
                continue;
            if(n%i == 0)
                return false;
        }
        return true;
    }

    bool isPrime(int n)
    {
        if (n == 1) return false;
        if (n == 2) return true;
        int divide = sqrt(n);
        for(int i=3; i<=divide; i+=2)
        {
            if(n%i == 0)
                return false;
        }
        return true;
    }
};

class Solution1 {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};


class Solution2 {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for(int i=0; i<sqrt(n); i++)
        {
            if(prime[i])
            {
                for(int j=i*i; j<n; j+=i)
                    prime[j] = false;
            }
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main()
{

    Solution1 s;
    int count = s.countPrimes(7);
    cout<<"total prime is "<<count<<endl;

    return 1;
}

