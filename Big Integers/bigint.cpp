#include <iostream>
#include <ios>
#include <array>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <complex>
#include <numeric>

char to_char(int i)		{return ((i % 10 ) + '0');}
int to_digit(char c)	{return (c - '0');}


using namespace std;

typedef long long int lint;

class bigint
{
    private:
    string value = "0" ;    //default value is initialized to 0
    bool negative = false;  //default sign is positive (+)
	void standardify(string &str1, string &str2);	//padding the operands
	string add(string str1, string str2);	//internal addition logic
	string sub(string str1, string str2);	//internal subtraction logic
	string mul(string str1, string str2);	//internal multiplication logic
	string div(string str1, string str2);	//internal division logic
	bool less_than(string str1, string str2);
	bool greater_than(string str1, string str2);
	bool equal_to(string str1, string str2);
	bool less_than_or_equal_to(string str1, string str2);
	bool greater_than_or_equal_to(string str1, string str2);
		
    public:
    //constructor																						
    bigint();   //create instance with default value (= 0);
    bigint(string str); //create instance with defined value
    bigint(string str, bool sign);  //create instance with defined value and sign

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
    
    //comparison operations
    bool operator < (bigint compObject1);
    bool operator > (bigint compObject1);
    bool operator == (bigint compObject1);
    bool operator != (bigint compObject1);
    bool operator >= (bigint compObject1);
    bool operator <= (bigint compObject1);
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
bool bigint::isNeg()					{return negative;}

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

bigint::bigint(string str, bool negative)
{
    if (str.empty())
    {
        value = "0"; this->negative = negative;
    }
    else
    {
        if (str.front() == '-')
        {
        	str.erase(str.begin());
			this->negative = negative; value = (str.empty()) ? "0" : str;
        }
        else
        {
            value = str; this->negative = negative;
        }
    }
}


void bigint::standardify(string &str1, string &str2)	//pad strings with zeroes
{
	if (str1.size() == str2.size()) return;
    if (str1.size() < str2.size()) str1.insert(str1.begin(),str2.length() - str1.length(), '0');
    else str2.insert(str2.begin(), str1.length() - str2.length(), '0');
}

string bigint::add(string str1, string str2)
{
    standardify(str1, str2);
    string answer = ""; int carry = 0;
    for (lint i = str1.size() - 1 ; i >= 0 ; i--)
    {
        int currentSum = to_digit(str1[i]) + to_digit(str2[i]) + carry;
        carry = (currentSum >> 1) / 5;
        answer.push_back(to_char(currentSum % 10));
    };
    if (carry) answer.push_back('1'); reverse(answer.begin(), answer.end()); return answer;
}

string bigint::sub(string str1, string str2)
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

bigint bigint::operator + (bigint addend2)
{
	bigint addend1 = *this;
	bool add1_neg = addend1.negative, add2_neg = addend2.negative;
	if (add1_neg && (!add2_neg)) return bigint(sub(addend2.value, addend1.value)); 
	if ((!add1_neg) && add2_neg) return bigint(sub(addend1.value, addend2.value)); 
	if ((!add1_neg) && (!add2_neg)) return (bigint(add(addend1.value, addend2.value)));
	if (add1_neg && add2_neg) return bigint(add(addend1.value, addend2.value), true);
}

bigint bigint::operator - (bigint subtrahend)
{
	bigint minuend = *this;
	bool minu_neg = minuend.negative, subtr_neg = subtrahend.negative;
	if (minu_neg && (!subtr_neg)) return bigint(add(minuend.value, subtrahend.value),true);
	if ((!minu_neg) && subtr_neg) return bigint(add(minuend.value, subtrahend.value));
	if (minu_neg && subtr_neg) return bigint(sub(subtrahend.value, minuend.value));
	if ((!minu_neg) && (!subtr_neg)) return bigint(sub(minuend.value, subtrahend.value));
}
