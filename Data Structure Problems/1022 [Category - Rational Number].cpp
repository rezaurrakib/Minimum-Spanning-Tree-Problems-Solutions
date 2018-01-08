// Reza, Sr. Software Engineer
// Digital Imaging Group, Samsung Research, Bangladesh

#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <set>
#include <bitset>
#include <list>
#include <sstream>
#include <functional>

using namespace std;

typedef long long ll;

#define INF 2147483648
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14
#define cInp(a) scanf("%d",&a)
#define cInp1(a,b) scanf("%c %c",&a,&b)
#define cInp2(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define DFS_BLACK 1
#define DFS_WHITE 0
#define NODES 5000

struct NumberTheory
{
    int GCD(int a, int b)
    {
        return (b == 0 ? a : GCD(b, a%b));
    }
    int LCM(int a, int b)
    {
        return (a * (b / GCD(a, b)));
    }

};

NumberTheory obj;

int main()
{
    int TC;
    cin >> TC;
    getchar();

    while(TC--)
    {
        string str,op1,op2,op;
        int n1,d1,n2,d2;
        getline(cin,str);
        stringstream ss(str);
        ss >> n1 >> op1 >> d1 >> op >> n2 >> op2 >> d2;
        //cout << n1 << " " << d1 << " " << n2 << " " << d2 << "\n";

        if(op == "+")
        {
            int x = (n1*d2 + n2*d1);
            int y = d1 * d2;

            int gcd = obj.GCD(x,y);
            cout << x << "/" << y << " = " << x/gcd << "/" << y/gcd << "\n";
        }

        else if(op == "-")
        {
            int xP;
            int x = (n1*d2 - n2*d1);
            int y = d1 * d2;

            if(x<0) xP = -1 * x;
            else xP = x;

            int gcd = obj.GCD(xP,y);
            cout << x << "/" << y << " = " << x/gcd << "/" << y/gcd << "\n";
        }

        else if(op == "*")
        {
            int x = n1 * n2;
            int y = d1 * d2;

            int gcd = obj.GCD(x,y);
            cout << x << "/" << y << " = " << x/gcd << "/" << y/gcd << "\n";
        }

        else if(op == "/")
        {
            int x = n1 * d2;
            int y = d1 * n2;

            int gcd = obj.GCD(x,y);
            cout << x << "/" << y << " = " << x/gcd << "/" << y/gcd << "\n";
        }

    }

    return 0;
}
