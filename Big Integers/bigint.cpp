//61ph3r
#include <iostream>
#include <ios>
#include <regex>
#include <array>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <sstream>
#include <streambuf>
#include <fstream>
#include <complex>
#include <numeric>
#include <random>

char to_char(int i)
{
	switch (i)
	{
		case 0: return '0'; case 1: return '1'; case 2: return '2';
		case 3: return '3'; case 4: return '4'; case 5: return '5';
		case 6: return '6'; case 7: return '7'; case 8: return '8'; case 9: return '9';
	}
}

int to_digit(char c)
{
	switch (c)
	{
		case '0': return 0; case '1': return 1; case '2': return 2;
		case '3': return 3; case '4': return 4; case '5': return 5;
		case '6': return 6; case '7': return 7; case '8': return 8; case '9': return 9;
	}
}


using namespace std;

typedef long long int lint;

class bigint
{
    private:
    string value = "0" ;    //default value is initialized to 0
    bool negative = false;  //default sign is positive (+)
	pair <string, string> standardify(string str1, string str2);	//padding the operands
	string add(string str1, string str2);	//internal addition logic
	string sub(string str1, string str2);	//internal subtraction logic
	
    public:
    //constructor																						
    bigint();   //create instance with default value (= 0);
    bigint(string str); //create instance with defined value
    bigint(string str, bool sign);  //create instance with defined value and sign
    bigint(lint num);   //create instance with given numerical value in STL integer
                        //(long long int used to allow casting from all integers in STL's scope)

    //data type manipulation
    string toString();
    void setSign(bool negativity);
    void setValue(string str);
    void setValue(bigint llint);
    bool getSign(); char getSignInChar();
    string getValue();
    string getFullValue();
	bool isNeg();
    void operator = (bigint otherObject);

    //arithmetic operations
    bigint operator + (bigint addend);  //addend + addend = summands + summands = sum (= augend + addend)
    bigint operator - (bigint subtrahend);  //minuend - subtrahend = difference
    bigint operator * (bigint multiplicand);//multiplier * multiplicand = factors * factors = product
    bigint operator / (bigint divisor);     //dividend / divisor = numerator / denominator = fraction = quotient = ratio
    bigint abs(bigint param);
    void increment();
    void decrement();



};


//data type manipulation
string bigint::toString()               {return (negative ? "-" + value : value);}
void bigint::setSign(bool negativity)   {negative = negativity;}
void bigint::setValue(string str)       {value = str;}
void bigint::setValue(bigint llint)     {setValue(llint.toString());}
bool bigint::getSign()                  {return negative;}
char bigint::getSignInChar()            {return (negative ? '-' : '+');}
string bigint::getValue()               {return value;}
string bigint::getFullValue()           {return this->toString();}
void bigint::operator = (bigint otherObject) {this->value = otherObject.value; this->negative = otherObject.negative;}

//constructors
bigint::bigint()                       	{value = "0";}

bigint::bigint(string str)
{
    if (str.empty()) value = "0";
    else
    {
        if (str.front() == '-')
        {
            str.erase(str.begin()); negative = true; 
			value = (str.empty()) ? "0" : str;
        }
        else value = str;
    };
}

bigint::bigint(string str, bool sign)       //warning: WIP (work in progress), may conflicts when string's sign and the boolean value is different
{
    //well, just override the string's sign with the given sign
    if (str.empty())
    {
        value = "0"; negative = sign;
    }
    else
    {
        if (str.front() == '-')
        {
        	str.erase(str.begin()); negative = sign; 
            value = (str.empty()) ? "0" : str;
        }
        else
        {
            value = str; negative = sign;
        }
    }
}

bigint::bigint(lint num)				{value = to_string(num);}



void standardify(string &str1, string &str2)	//pad strings with zeroes
{
	if (str1.size() == str2.size()) return;
    if (str1.size() < str2.size()) str1.insert(str1.begin(),str2.length() - str1.length(), '0');
    else str2.insert(str2.begin(), str1.length() - str2.length(), '0');
}

string add(string str1, string str2)
{
    standardify(str1, str2);
    string answer = ""; int carry = 0;
    for (lint i = str1.size() - 1 ; i >= 0 ; i--)
    {
        int currentSum = to_digit(str1[i]) + to_digit(str2[i]) + carry;
        carry = (currentSum >> 1) / 5;
        answer.push_back(to_char(currentSum % 10));
    };
    if (carry) answer.push_back('1');  reverse(answer.begin(), answer.end()); return answer;
}

string sub(string str1, string str2)
{
    standardify(str1, str2);
	bool neg = (str1 < str2) ? true : false; if (neg) swap(str1, str2);
	int carry = 0; string answer = "";
	for (lint i = str1.length() - 1; i >= 0 ; i--)
	{
		int current = to_digit(str1[i]) - to_digit(str2[i]) - carry; carry = 0;	//take the carry and clear the carry
		if (current < 0)
		{
			carry = 1;	//if borrowing needed, raise the carry
			current += 10;
		};
		answer.push_back(to_char(current % 10));
	}
	while (answer.back() == '0') answer.pop_back(); 
	reverse(begin(answer), end(answer)); return neg ? ("-" + answer) : answer;
}

