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
    

    //arithmetic operations
    bigint operator + (bigint addend);  //addend + addend = summands + summands = sum (= augend + addend)
    bigint operator - (bigint subtrahend);  //minuend - subtrahend = difference
    bigint operator * (bigint multiplicand);//multiplier * multiplicand = factors * factors = product
    bigint operator / (bigint divisor);     //dividend / divisor = numerator / denominator = fraction = quotient = ratio
    bigint abs(bigint param);
    void increment();
    void decrement();



}


//data type manipulation
string bigint::toString()               {return ((negative ? "" : "-") + value);}
void bigint::setSign(bool negativity)   {negative = true;}
void bigint::setValue(string str)       {value = str;}
void bigint::setValue(bigint llint)     {setValue(llint.toString());}
bool bigint::getSign()                  {return negative;}
char bigint::getSignInChar()            {return (negative ? '-' : '+');}
string bigint::getValue()               {return value;}
string bigint::getFullValue()           {return this->toString();}


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
