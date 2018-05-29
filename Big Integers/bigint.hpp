//include guard

#ifndef BIGINT_CXX_INCLUDE
#define BIGINT_CXX_INCLUDE

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

class bigint
{
    private:
    std::string value = "0" ;    //default value is initialized to 0
    bool negative = false;  //default sign is positive (+)
	void standardify(std::string &str1, std::string &str2);	//padding the operands
	std::string add(std::string str1, std::string str2);	//internal addition logic
	std::string sub(std::string str1, std::string str2);	//internal subtraction logic
	std::string mul(std::string str1, std::string str2);	//internal multiplication logic
	std::string div(std::string str1, std::string str2);	//internal division logic
	bool less_than(std::string str1, std::string str2);
	bool greater_than(std::string str1, std::string str2);
	bool equal_to(std::string str1, std::string str2);
	bool less_than_or_equal_to(std::string str1, std::string str2);
	bool greater_than_or_equal_to(std::string str1, std::string str2);
		
    public:
    //constructor																						
    bigint();   //create instance with default value (= 0);
    bigint(std::string str); //create instance with defined value
    bigint(std::string str, bool sign);  //create instance with defined value and sign

    //data type manipulation
    std::string toString();
    void setSign(bool negativity);
    void setValue(std::string str);
    void setValue(bigint llint);
    bool getSign(); char getSignInChar();
    std::string getValue();
    std::string getFullValue();
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

#endif
