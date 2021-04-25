//
// Created by eviat on 4/15/2021.
//

#include "NumberWithUnits.hpp"
#include<string>
#include<iostream>
#include<fstream>
#include <stdexcept>
using namespace ariel;
using namespace std;
const double EPSILON =  0.01;

map< string, map<string,double>> NumberWithUnits::units;    //initial static variable in the cpp file
NumberWithUnits::NumberWithUnits() {
    number =0;
}
NumberWithUnits::NumberWithUnits(double num, const std::string &type){
    if(units.find(type) == units.end()){    // check if the type exist or not
        throw("The Type does not exist in the map!");
    }
    this ->type = type;
    this -> number = num;
}
void NumberWithUnits::convertNumType(std::string from_type, std::string to_type){
    for(auto pairwaise: units[to_type]){
        if(pairwaise.first != from_type){
            double number = units[from_type][to_type]*pairwaise.second;
            units[from_type][pairwaise.first] = number;
            units[pairwaise.first][from_type] = 1.0/number;
        }
    }
}
// read from file and insert the values to the units map of map
void NumberWithUnits::read_units(std::ifstream& rfile) {
    if(!rfile.is_open()) return;
    std::string not_needed, startUnit, goalUnit;
    double temp =0 ;
    while(!rfile.eof())
    {
        rfile>>not_needed>>startUnit>>not_needed>>temp>>goalUnit;  //insert the units to the variables
        units[startUnit][goalUnit] = temp;
        units[goalUnit][startUnit] = 1.0/temp;
        convertNumType(startUnit,goalUnit);     //update all the rest
        convertNumType(goalUnit,startUnit);
    }
}

bool NumberWithUnits::isFromSameType(const std::string& from_type, const std::string& to_type) const{
    //check if exist in the map tuple like that
    if(units[from_type].find(to_type) != units[from_type].end() || from_type == to_type){ //the second check is like km ->km but it dosen't exist
        return true;
  }
    return false;
}
double NumberWithUnits::convert_from_to(const std::string& from, const std::string& to) const{
    //distinct between two cases
    if(from != to) {
        return units[from][to];
    }
    return 1;   // The dimensions are equal
}
NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw std::exception();      //("Try to add two different types!");
    }
    return NumberWithUnits{number +convert_from_to(num.type,type)*num.number,type};
}

NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits& num){
    if(!isFromSameType(type,num.type)){
        throw("Try to add two different types!");
    }
    number = number +convert_from_to(num.type,type)*num.number;
    return *this;
}
NumberWithUnits NumberWithUnits::operator+() const{ //dons't change anything
    return *this;
}
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw("Try to add two different types!");
    }
    return NumberWithUnits{number -convert_from_to(num.type,type)*num.number,type};
}
NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits& num){
    if(!isFromSameType(type,num.type)){
        throw("Try to add two different types!");
    }
    number = number - convert_from_to(num.type,type)*num.number;
    return *this;
}NumberWithUnits NumberWithUnits::operator-() const{
    return NumberWithUnits{-number, type};
}

bool NumberWithUnits::operator<(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return number < convert_from_to(num.type,type)*num.number;
}
bool NumberWithUnits::operator<=(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return number <= convert_from_to(num.type,type)*num.number;
}
bool NumberWithUnits::operator>(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return number > convert_from_to(num.type,type)*num.number;
}
bool NumberWithUnits::operator>=(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return number >= convert_from_to(num.type,type)*num.number;
}
bool NumberWithUnits::operator==(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return fabs(convert_from_to(num.type,type)*num.number - number) < EPSILON;
}
bool NumberWithUnits::operator!=(const NumberWithUnits& num) const{
    if(!isFromSameType(type,num.type)){
        throw invalid_argument("Try to add two different types!");
    }
    return number != convert_from_to(num.type,type)*num.number;
}
NumberWithUnits& NumberWithUnits::operator++(){     // prefix operator
    number+=1;
    return *this;
}
NumberWithUnits NumberWithUnits::operator++(int){   // postfix operator
    number+=1;
    return NumberWithUnits{number-1,type};
}
NumberWithUnits& NumberWithUnits::operator--(){   // prefix operator
    number-=1;
    return *this;
}
NumberWithUnits NumberWithUnits::operator--(int){
    number-=1;
    return NumberWithUnits{number,type};
}
NumberWithUnits ariel::operator*(double num, const NumberWithUnits &oth_num){
    return NumberWithUnits{oth_num.number*num,oth_num.type};
}
NumberWithUnits NumberWithUnits::operator*(double num){
    return NumberWithUnits{number*num,type};
}
std::ostream& ariel::operator<<(std::ostream &num, const NumberWithUnits &obj){
    return num<<obj.number<<"["<<obj.type<<"]";
}
std::istream& ariel::operator>>(std::istream &num, NumberWithUnits &obj){
    string unit, check;
    double number;
    num >>number>>check>>unit>>check;
    obj.number = number;
    obj.type = unit;
    return num;
}

//getters ans setters
std::string& NumberWithUnits::get_type(){
    return type;
}
const std::string NumberWithUnits::get_type() const{
    return type;
}
double& NumberWithUnits::getnum(){
    return number;
}
const double NumberWithUnits::getnum() const{
    return number;
}
