#include <iostream>

struct Sales_data{
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
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

/* read */
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}
/* My own read */
std::istream &myOwnRead(Sales_data &item)
{
    double price;
    std::cin >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return std::cin;
}

/* print */
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return os;
}
/*My own print*/
std::ostream &myOwnPrint(Sales_data &item)
{
    std::cout << item.isbn() << " " << item.units_sold << " "
    << item.revenue << " " << item.avg_price();
    return std::cout;
}

/* Add */
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
/* My own add*/
Sales_data myOwnAdd(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    return sum.combine(rhs);
}

int main()
{
    Sales_data total;

    /*if(read(std::cin, total))*/
    if(myOwnRead(total))
    {
        Sales_data trans;
        /*while(read(std::cin, trans))*/
        while(myOwnRead(trans))
        {
            if(total.isbn() == trans.isbn())
                /*total.combine(trans);*/
                /*total = add(total, trans);*/
                total = myOwnAdd(total, trans);
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        /*print(std::cout, total) << std::endl;*/
        myOwnPrint(total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}