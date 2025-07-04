#include<iostream>

struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : 
                bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(std::istream &is){
        read(is, *this);
    }
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::istream &read(std::istream &, Sales_data &);
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& Sales_data::read(std::istream& is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
/*
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}
*/
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price() << "\n";
    return os;
}

int main()
{
    Sales_data data1;
    print(std::cout, data1);

    Sales_data data2("actions");
    print(std::cout, data2);

    Sales_data data3("adventure", 10, 15.5);
    print(std::cout, data3);

    Sales_data data4(std::cin);
    print(std::cout, data4);
    return 0;
}