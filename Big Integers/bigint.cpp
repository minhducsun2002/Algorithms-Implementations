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
#include "bigint.hpp"

char to_char(int i)	    {return ((i % 10 ) + '0');}
int to_digit(char c)	{return (c - '0');}


using namespace std;

typedef long long int llint;

class bigint
{
    private:
    string value = "0" ;    //default value is initialized to 0
    bool negative = false;  //default sign is positive (+)
		
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
    bigint operator + (bigint addend);  	//addend + addend = summands + summands = sum (= augend + addend)
    bigint operator - (bigint subtrahend);  //minuend - subtrahend = difference
    bigint operator * (bigint multiplicand);//multiplier * multiplicand = factors * factors = product
    bigint operator / (bigint divisor);     //dividend / divisor = numerator / denominator = fraction = quotient = ratio
    bigint abs(bigint param);

    bigint& operator += (bigint& addend);
    bigint& operator -= (bigint& subtrahend);  
    bigint& operator *= (bigint& multiplicand);   
    bigint& operator /= (bigint& divisor);
    
    bigint& operator ++ ();
    bigint operator ++ (int);
    bigint& operator -- ();
    bigint operator-- (int);
	
    //comparison operations
    bool operator < (bigint compObject1);
    bool operator > (bigint compObject1);
    bool operator == (bigint compObject1);
    bool operator != (bigint compObject1);
    bool operator >= (bigint compObject1);
    bool operator <= (bigint compObject1);

    private:    //internal logic
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
    string increment(string str);
    string decrement(string str);
};


//data type manipulation
string bigint::toString()               {return (this->negative ? "-" : "") + value;}
void bigint::setSign(bool negativity)   {negative = negativity;}
void bigint::setValue(string str)       {value = str;}
void bigint::setValue(bigint llint)     {setValue(llint.value); setSign(llint.getSign());}
bool bigint::getSign()                  {return negative;}
char bigint::getSignInChar()            {return (negative ? '-' : '+');}
string bigint::getValue()               {return value;}
string bigint::getFullValue()           {return this->toString();}
void bigint::operator = (bigint otherObject)    {this->value = otherObject.value; this->negative = otherObject.negative;}
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

//arithmetic operations
bigint bigint::operator + (bigint addend2)
{
	return (this->negative == addend2.negative) ? ((this->negative == true) ? bigint(add(this->value, addend2.value), true) : (bigint(add(this->value, addend2.value)))) : ((this->negative == true) ? bigint(sub(addend2.value, this->value)) : bigint(sub(this->value, addend2.value)));
}

bigint bigint::operator - (bigint subtrahend)
{
	return (this->negative == subtrahend.negative) ? (this->negative == true ? bigint(sub(subtrahend.value, this->value)) : bigint(sub(this->value, subtrahend.value))) : (this->negative == true ? bigint(add(this->value, subtrahend.value), true) : bigint(add(this->value, subtrahend.value)));
}

bigint bigint::operator * (bigint multiplicand)
{
    return (this->negative == multiplicand.negative) ? bigint(mul(this->value, multiplicand.value)) : bigint(mul(this->value, multiplicand.value), true);
}

//self-assignment operations
bigint& bigint::operator += (bigint& addend)		{this->setValue(*this + addend); return (*this);}
bigint& bigint::operator -= (bigint& subtrahend)	{this->setValue(*this - subtrahend); return (*this);}
bigint& bigint::operator *= (bigint& multiplicand)	{this->setValue(*this * multiplicand); return (*this);}

//unary operations
bigint& bigint::operator ++ ()	//prefix
{
	this->setValue(bigint(increment(this->toString()))); return *this;
};

bigint bigint::operator ++ (int)	//postfix
{
	bigint tmp = *this; ++*this; return tmp;
}

bigint& bigint::operator -- ()	//prefix
{
	this->setValue(bigint(decrement(this->toString()))); return *this;
}

bigint bigint::operator -- (int)	//postfix
{
	bigint tmp = *this; --*this; return tmp;
}


//===============================================================================
//internal logic
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
    for (llint i = str1.size() - 1 ; i >= 0 ; i--)
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
	for (llint i = str1.length() - 1; i >= 0 ; i--)
	{
		int current = to_digit(str1[i]) - to_digit(str2[i]) - carry; 
		carry = current < 0 ? 1 : 0;
		current += current < 0 ? 10 : 0;
		answer.push_back(to_char(current % 10));
	}
	while (answer.back() == '0') answer.pop_back(); 
	reverse(begin(answer), end(answer)); return neg ? ("-" + answer) : answer;
}

string bigint::mul(string str1, string str2)
{
	string answer = "0";
	for (llint i = str2.size() - 1 ; i >= 0 ; i--)
	{
		string digit_mul = "0";
		for (llint n = str1.size() - 1 ; n >= 0 ; n--) digit_mul = add(digit_mul, to_string(to_digit(str1[n]) * to_digit(str2[i])) + string(str1.size() - 1 - n, '0'));
		answer = add(answer, digit_mul + string(str2.size() - 1 - i, '0'));
	};
	return answer;
}

string bigint::decrement(string str)
{
	if (str == "0") return "-1";
	int carry = 1;
	for (llint i = str.size() - 1 ; i >= 0 ; i--)
	{
		int replace = to_digit(str[i]) - carry;
		carry = replace < 0 ? 1 : 0;
		replace += replace < 0 ? 10 : 0;
		str[i] = to_char(replace);
	};
	return (str.front() == '0' ? str.substr(1) : str);
}

string bigint::increment(string str)
{
	if (str == "-1") return "0";
	int carry = 1;
	for (llint i = str.size() - 1 ; i >= 0 ; i--)
	{
		int replace = to_digit(str[i]) + carry;
		carry = (replace >> 1) / 5;
		str[i] = to_char(replace % 10);
	};
	return ((carry) ? ("1" + str) : str);
}
