//
// Created by eviat on 4/15/2021.
//

#ifndef NUMBER_WITH_UNITS_A_MASTER_NUMBERWITHUNITS_HPP
#define NUMBER_WITH_UNITS_A_MASTER_NUMBERWITHUNITS_HPP

#include<string>
#include <math.h>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>

namespace ariel{

    class NumberWithUnits {
    public:
        NumberWithUnits();
        NumberWithUnits(double num, const std::string& type);
        static void read_units(std::ifstream& rfile);
        NumberWithUnits operator+(const NumberWithUnits& num) const;
        NumberWithUnits operator+=(const NumberWithUnits& num);
        NumberWithUnits operator+() const;
        NumberWithUnits operator-(const NumberWithUnits& num) const;
        NumberWithUnits operator-=(const NumberWithUnits& num);
        NumberWithUnits operator-() const;
        bool operator<(const NumberWithUnits& num) const;
        bool operator<=(const NumberWithUnits& num) const;
        bool operator>(const NumberWithUnits& num) const;
        bool operator>=(const NumberWithUnits& num) const;
        bool operator==(const NumberWithUnits& num) const;
        bool operator!=(const NumberWithUnits& num) const;
        NumberWithUnits& operator++();   // prefix operator
        NumberWithUnits operator++(int);    // postfix operator
        NumberWithUnits& operator--();
        NumberWithUnits operator--(int);
        NumberWithUnits operator*(double num);
        std::string& get_type();    //getters and setters  for type and number
        const std::string get_type() const;
        double& getnum();
        const double getnum() const;
    private:
        double number;
        std::string type;
        static std::map< std::string, std::map<std::string,double>> units;
        bool isFromSameType(const std::string& from_type,const std::string& to_type) const;
        static void convertNumType(std::string from_type, std::string to_type); // get number and type and convert to_type
        double convert_from_to(const std::string& from, const std::string& to) const;
    friend NumberWithUnits operator*(double num, const NumberWithUnits &oth_num);
    friend std::ostream &operator<<(std::ostream &num, const NumberWithUnits &obj);
    friend std::istream &operator>>(std::istream &num, NumberWithUnits &obj);
    };








}





#endif //NUMBER_WITH_UNITS_A_MASTER_NUMBERWITHUNITS_HPP
