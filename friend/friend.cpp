#include<iostream>

class Sales_data{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, Sales_data&);
public:
    Sales_data() = default;
    Sales_data(std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p){}
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
private:
    std::string bookNo = 0;
    unsigned units_sold = 0;
    double revenue = 0;
};