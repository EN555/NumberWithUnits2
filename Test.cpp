//
// Created by eviat on 4/18/2021.
//

# include "doctest.h"
# include "NumberWithUnits.hpp"
#include <fstream>
#include <sstream>
using namespace ariel;
using namespace std;





TEST_CASE("different dimensions"){
    ifstream units_file{"units2.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1,"km"};
    NumberWithUnits b{1,"cm"};
    NumberWithUnits c{1,"mm"};
    NumberWithUnits d{1,"min"};
    NumberWithUnits e{1,"USD"};
    // different dimensions need to throw exception
    CHECK_THROWS(a+d);
    CHECK_THROWS(a+e);
    CHECK_THROWS(b+d);
    CHECK_THROWS(b+e);
    CHECK_THROWS(c+e);
    // same dimensions need to return an answer
//    CHECK_NOTHROW(a+b);
//    CHECK_NOTTHROW(b+c);
//    CHECK_NOTTHROW(a+c);
}

TEST_CASE("math operators"){
    NumberWithUnits a{10,"ton"};
    NumberWithUnits b{1000,"kg"};
    NumberWithUnits c{1000,"g"};      //equal to 1 kilogram
    NumberWithUnits d{10000,"dg"};    //equal to 1 gram
    //check plus operator
//    CHECK((a+b) == "1.1ton");
//    CHECK((b+a) == "11000kg");
//    CHECK((b+c) == "1001kg");
//    CHECK((c+b)=="1001000g");
//    //check minus operator
//    CHECK((a-b)== "9ton");
//    CHECK((a-10*b)== "0ton");
//    CHECK((b-c)=="999kg");
//    CHECK((c-0.01*b)=="-9000g");  //the result is negative number
    //check < operator
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
    //check <= operator
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);


            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
    //check <= operator
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
    //check <= operator
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
    //check <= operator
            CHECK((a<b)== false);
            CHECK((a>b) == true);
            CHECK((b>c) == true);
            CHECK((b<c) == false);
    //check < operator

    //check >= operator

    //check == operator

    //check != operator

    //check ++ as prefix operator

    //check ++ as postfix operator

    //check -- as prefix operator

    //check -- as postfix operator

    //check += operator

    //check -= operator


}