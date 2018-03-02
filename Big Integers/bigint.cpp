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

using namespace std;

typedef long long int lint;

class bigint
{
    private:
    string value = "0" ;    //default value is initialized to 0
    bool negative = false;  //default sign is positive (+)

    public:
    //constructor																							//==done==
    bigint();   //create instance with default value (= 0);													//done
    bigint(string str); //create instance with defined value												//done
    bigint(string str, bool sign);  //create instance with defined value and sign							//done
    bigint(lint num);   //create instance with given numerical value in STL integer							//done
                        //(long long int used to allow casting from all integers in STL's scope)

    //data type manipulation
    string toString();																						//==done==
    void setSign(bool negativity);																			//done									
    void setValue(string str);																				//done							
    void setValue(bigint llint);																			//done							
    bool getSign(); char getSignInChar();																	//done														
    string getValue();    																					//done
    string getFullValue();																					//done
	bool isNeg();																							//done
    void operator = (bigint otherObject);																	//done

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
string bigint::toString()               {return ((negative ? "" : "-") + value);}
void bigint::setSign(bool negativity)   {negative = negativity;}
void bigint::setValue(string str)       {value = str;}
void bigint::setValue(bigint llint)     {setValue(llint.toString());}
bool bigint::getSign()                  {return negative;}
char bigint::getSignInChar()            {return (negative ? '-' : '+');}
string bigint::getValue()               {return value;}
string bigint::getFullValue()           {return this->toString();}
void bigint::operator = (bigint otherObject) {this->value = otherObject.value; this.negative = otherObject.negative;}

//constructors
bigint::bigint()                        
{
    value = "0";
}

bigint::bigint(string str)
{
    if (str.empty())
    {
        value = "0";
        return;
    }
    else
    {
        if (str[0] == '-')
        {
            str.erase(0,1);
            negative = true;
            if (str.empty()) value = "0"; else value = str;
            return;
        }
        else
        {
            value = str; return;
        }
    }
}

bigint::bigint(string str, bool sign)       //warning: WIP (work in progress), may make conflicts when string's sign and the boolean value is different
{
    //well, just override the string's sign with the given sign
    if (str.empty())
    {
        value = "0";
        negative = sign;
        return;
    }
    else
    {
        if (str[0] == '-')
        {
            str.erase(0,1);
            negative = true;
            if (str.empty()) value = "0"; else value = str;
            negative = sign;
            return;
        }
        else
        {
            value = str;
            negative = sign;
            return;
        }
    }
}

bigint::bigint(lint num)
{
    value = to_string(num);
}

bigint bigint::operator + (bigint addend)
{
	bool add1_neg = this->negative, add2_neg = this->negative;
	if (add1_neg && add2_neg)	//all negative
	{
		bigint tmp1 = *this; tmp1.setSign(false);
		bigint tmp2 = addend; tmp2.setSign(false);
		bigint result = tmp1 + tmp2; result.setSign(true);
		return result;
	};
	if (add1_neg && (!add2_neg)) //add1 is negative
	{
		bigint tmp = *this; tmp.setSign(false);
		return (addend - tmp);
	};
	if (add2_neg && (!add1_neg)) //add2 is negative
	{
		bigint tmp = addend; tmp.setSign(false);
		return (*this - tmp);
	}
	string add1 = this->getValue(), add2 = addend.getValue();
	
	//padding
	while (add1.length() < add2.length()) add1 = "0" + add1;
	while (add2.length() < add1.length()) add2 = "0" + add2;
	


	string answer = "";
	
	reverse(add1.begin(), add1.end());
	reverse(add2.begin(), add2.end());
	
	int carry = 0;
	for (lint i = 0 ; i <= add1.length() - 1; i++)
	{
		int sum = integerify(add1[i]) + integerify(add2[i]) + carry;
		carry = 0;
		int push = sum % 10; char push_ = push + 48;
		carry = push / 10;
		answer.push_back(push_);
	};
	if (carry != 0) answer.push_back('1');
	
	reverse(answer.begin(), answer.end());
	bigint returnValue (answer, false);
	return returnValue;
}


bigint bigint::operator - (bigint subtrahend)
{
	bool add1_neg = this->getSign(), add2_neg = subtrahend.getSign();
	if (add1_neg && add2_neg)	//all negative
	{
		bigint tmp1 (this->getValue(), !add1_neg);
		bigint tmp2 (subtrahend.getValue(), !add2_neg);;
		return (tmp2 - tmp1);
	};
	if (add1_neg && !add2_neg) 	//add1 is negative
	{
		bigint tmp1 (this->getValue(), false);
		return (subtrahend - tmp1);
	};
	if (!add1_neg && add2_neg)
	{
		bigint tmp1 (subtrahend->getValue(), false);
		return (*this - tmp1);
	}
	
	string add1 = this->getValue(), add2 = subtrahend.getValue();
	

    //padding
	while (add1.length() < add2.length()) add1 = "0" + add1;
	while (add2.length() < add1.length()) add2 = "0" + add2;


    bool neg = false;
    if (add1 < add2)
    {
         add1.swap(add2); neg = true;
    }

    
    int remsub = 0;     //carry
    string answer = "";
    for (lint i = add1.length() - 1 ; i >= 0 ; i--)
    {
        int current = (add1[i] - '0') - (add2[i] - '0') - remsub;   //calculating
        remsub = 0; //clear value
        if (curr < 0)
        {
            remsub = 1; //raise if have to borrow
            curr += 10;
        };
        answer.append(1, ((curr % 10) + '0'))
    }
    std::reverse(answer.begin(), answer.end());
    bigint tmp (answer, neg);
    return tmp;
}



/*
int main()
{
    cout << "Please enter a number: ";
    string str; cin >> str;
    typedef bigint llint;
    llint _instance1 (str);
    llint _emptyInstance;
    cout << "Results: " << endl;
    //for each function, <cout> a line
    //toString and all constructors are tested
    cout << _instance1.bigint::toString() << endl;
    cout << "[Default value:] " << _emptyInstance.toString() << endl;
    llint _instance2 (str, true); cout << "[Force negative:] " << _instance2.toString() << endl;
    cout << "[Instance2.sign:] " << _instance2.getSign() << endl;
    llint _instance3 (_instance2.toString(), false); cout << "[Force positive (after negating above): ] " << _instance3.toString() << endl;
    cout << "[Instance3.setSign(neg):] "; _instance3.setSign(true); cout << _instance3.getSign() << endl;
    cout << "Please enter a number (<long long int> range): "; lint _tmpLLInt; cin >> _tmpLLInt;
    llint _instance4 (_tmpLLInt); cout << "[Converted value:] " << _instance4.toString() << endl;
    cout << "[getFullValue:] "; _instance3.setSign(false); cout << _instance3.getFullValue() << endl;
}
*/
