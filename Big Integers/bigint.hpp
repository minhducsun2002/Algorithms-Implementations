//include guard

#ifndef BIGINT_CXX_INCLUDE
#define BIGINT_CXX_INCLUDE

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
    bigint(string str, bool negativeness);  //create instance with defined value and sign
    bigint(lint num);   //create instance with given numerical value in STL integer
                        //(long long int used to allow casting from all integers in STL's scope)

    //data type manipulation
    string toString();
    void setSign(bool negativity);
    void setValue(string str);
    void setValue(bigint llint);
    bool getSign(); char getSignInChar();   
    string getFullValue();
    void operator = (bigint otherObject);
    

    //arithmetic operations
    bigint operator + (bigint addend);      //addend + addend = summands + summands = sum (= augend + addend)
    bigint operator - (bigint subtrahend);  //minuend - subtrahend = difference
    bigint operator * (bigint multiplicand);//multiplier * multiplicand = factors * factors = product
    bigint operator / (bigint divisor);     //dividend / divisor = numerator / denominator = fraction = quotient = ratio
    bigint abs(bigint param);
    void increment();
    void decrement();



};


#endif
