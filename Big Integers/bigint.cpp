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
	pair <string, string> standardify(string str1, string str2);	//padding the operands
	string add(string str1, string str2);	//internal addition logic
	string sub(string str1, string str2);	//internal subtraction logic
	
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

