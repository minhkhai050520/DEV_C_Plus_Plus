#include <iostream>

using namespace std;
void peek_and_putback();
void input_failure();
void clear_function();
int main(){
/*
    char ch1, ch2;
    int num = 0;
    cin.get(ch1);
    cin.get(ch2);
    cin >> num;
    cout << "ch1: " << ch1 << " ch2: " << ch2 << " Num: "<< num << endl;
    int a, b;
    cin >> a;
    cin.ignore(100, '\n');
    cin >> b;
    cout << a << " " << b << endl;
    return 0;
*/
    // peek_and_putback();
    // input_failure();
    clear_function();
    return 0;
}

/*peek and putback*/
void peek_and_putback()
{
    char ch;
    cout << "Line 1: Enter a string: ";
    cin.get(ch);
    cout << endl;

    cout << "Line 4: After first cin.get(ch); "
        << "ch = " << ch << endl;
    
        cin.get(ch);
    cout << "Line 6: After second cin.get(); "
        << "ch = " << ch << endl;

    cin.putback(ch);
    cin.get(ch);

    cout << "Line 9: After putback and then "
        << "cin.get(ch); ch = " << ch << endl;
    
    ch = cin.peek();
    cout << "Line 11: After cin.peek(); ch = "
        << ch << endl;

    cin.get(ch);
    cout << "Line 13: After cin.get(ch); ch = "
        << ch << endl;
}

/*Input failure program*/

void input_failure()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    cout << "Enter 4 intergers: ";

    cin >> a >> b >> c >> d;
    cout << endl;

    cout << "The numbers you entered are:"
    << endl;
    cout << "a = " << a << ", b = " << b
    << ", c = " << c << ", d = " << d << endl;
}

/* Clear function */

void clear_function()
{
    int a = 23;
    int b = 34;

    cout << "Line 3: Enter a number followed"
        << " by a character: ";

    cin >> a >> b; //Line 4
    cout << endl << "Line 5: a = " << a
        << ", b = " << b << endl;
    
    cin.clear(); // Restore input stream
    cin.ignore(200,'\n');
    cout << "Line 8: Enter two numbers: "; //Line 8
    cin >> a >> b; //Line 9
    cout << endl << "Line 10: a = " << a
        << ", b = " << b << endl;
}