//include guard

#ifndef BIGINT_CXX_INCLUDE
#define BIGINT_CXX_INCLUDE


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

#endif
