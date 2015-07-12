#include <iostream>
#include <map>
#include <vector>


/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.



*/


/*
My Note
req1, skip white space, if the first character is not "-" "+", " ", return 0;
req2, may exceed INT_MIN, INT_MAX
req3, if met none numeric number, after "-", "+", return the current result


*/




using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if(str==NULL)
            return 0;
        int result; // need to initialize to 0
        bool neg=false;
        while(*str==' ') str++; // skip as many space as possible
        if(*str == '-' || *str == '+')
        {
            neg = (*str == '-') ? true:false; // remember the sign
            str++;
        }
        while(*str!='\0')
        {
            if(*str < '0' || *str > '9')
                return neg ? -result : result ; // if none numeric, return the current result with sign

            if(result>INT_MAX/10 ||
               (result==INT_MAX/10 && ( *str-'0' > INT_MAX%10 ) )) // exceed INT_MAX
                return neg?INT_MIN:INT_MAX;
            result = result*10 + (*str-'0');


            str++;
        }
        return neg ? -result : result ;
    }
};

int main()
{

    Solution s;
    char* c= "+-2";
    int i = s.atoi(c);
    cout<<"i is "<<i<<endl;

    return 1;
}

