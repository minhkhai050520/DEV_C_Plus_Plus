#include <iostream>

using namespace std;

void caculator_v1()
{
    std :: cout << "Please enter expression (we can handle + and -):";
    int lval = 0;
    int rval = 0;
    char op = 0;
    int res = 0;

    std :: cin >> lval >> op >> rval;

    if(op == '+')
        res = lval + rval;
    else if(op == '-')
        res = lval - rval;
    
        std :: cout << "result: " << res << "\n";
}

void caculator_v2()
{
    int lval = 0;
    int rval = 0;

    cout << "Please enter expression (we can handle +,-,* and /)\n";
    cout << "Add and x to end expression (e.g.,1+2*3x):";

    cin >> lval;

    if(!cin)
    {
        cout << "No first operand";
        exit(1);
    }

    for(char op; cin >> op;)
    {
        if(op != 'x')
            cin >> rval;
        
        if(!cin)
        {
            cout << "No second operand";
            exit(1);
        }

        switch(op)
        {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
            default:
                cout << "Result: " << lval << "\n";
                return;
        }
    }
}

int main()
{
    caculator_v2();
    return 0;
}