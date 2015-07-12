#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.
Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

*/

using namespace std;

class Solution {
public:

    int reverse(int x) {
        //bool neg=x<0? true:false;
        //x= abs(x); // jima1, if this is -2147483648, the abs is not right
        //cout<<"x is "<<x<<endl;
        int result = 0;
        while(x!=0)
        {
            int tmp = x%10;
            cout<<"result is "<<result<<endl;
            if(result > INT_MAX/10 || result < INT_MIN/10)
            // max is 2147483647, if the last number is bigger than 2, then the original number is larger than int
                return 0;
            result = 10*result + tmp;
            x = x/10;

        }
        //return neg?-result:result ;
        return result;

    }
};


int main()
{

    Solution s;
    int input;
    //cout<<"-321%10 is "<<-321%10<<endl;
    cout<<"max is "<<INT_MAX<<", min is "<<INT_MIN<<endl;
    do
    {
        cout<<"please input a number.."<<endl;
        cin>>input;
        cout<<"the number you input is "<<input<<", after reverse, the number is "<<s.reverse(input)<<endl;

    }while(input!=0);

    //int i = -100;
    //int j = s.reverse(i);
    //cout<<"after reverse, j is " <<j<<endl;

    return 1;
}

