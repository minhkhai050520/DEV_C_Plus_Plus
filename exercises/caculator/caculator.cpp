#include <iostream>

using namespace std;

class Token{
public:
    char kind;
    double value;
    Token(char k) :kind{k}, value{0.0} {};
    Token(char k, double v) :kind{k}, value{v} {};
};

class Token_stream{
public:
    Token get();
    void putback(Token t);
private:
    bool full = false;
    Token buffer;
};

void Token_stream::putback(Token t)
{
    if(full)
    {
        cout << "error: putback() into a full buffer\n";
        exit(1);
    }
    buffer = t;
    full = true;
}

Token Token_stream::get()
{
    if(full)
    {
        full = false;
        return buffer;
    }
    char ch = 0;
    if (!(cin >> ch))
    {
        cout << "No input\n";
        exit(1);
    }

    switch(ch)
    {
        case ';':
        case 'q':
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val = 0;
            cin >> val;
            return Token{'8',val};
        }
        default:
        {
            cout << "Bad token\n";
            exit(1);
        }
    }
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch(t.kind){
        case '(':
        {
            double d = expression();
            t = ts.get();
            if(t.kind != ')')
            {
                cout << ") expected\n";
                exit(1);
            }
            return d;
        }
        case '8':
            return t.value;
        default:
        {
            cout << "primary expected\n";
            exit(1);
        }
    }
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if(d == 0)
                {
                    cout << "divide by zero\n";
                    exit(1);
                }
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();
    Token t = ts.get();

    while(true)
    {
        switch(t.kind)
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
/*
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
*/
int main()
{
    double val;
    while(cin)
    {
        cout << "> ";
        Token t =ts.get();
        if(t.kind == 'q') break;
        if(t.kind == ';')
            cout <<"="<< val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
    return 0;
}