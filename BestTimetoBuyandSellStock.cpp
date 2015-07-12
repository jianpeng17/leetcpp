#include <iostream>
#include <map>
#include <vector>


/*

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

*/



/*
My Note
just need to get the lowest point, update the profit if current value minus lowest is larger

*/




using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())  // check null
            return 0;
        int profit = 0;
        int lowest = prices.front();   // 
        for(vector<int>::iterator itor = prices.begin(); itor!=prices.end();itor++)
        {
            if (*itor<lowest)
                lowest = *itor;
            if ( (*itor -lowest) > profit )
                profit = *itor -lowest;
        }
        return profit;
    }
};

int main()
{

    Solution s;

    return 1;
}

