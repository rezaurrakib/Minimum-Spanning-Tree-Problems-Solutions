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

int main()
{
    int n,hold_last,i,first,last;
    queue <int> temp;

    while(cin >> n && n)
    {
        cout << "Discarded cards:";
        for(i=0; i<n; i++)
        temp.push(i+1);

        if(n==1)
        {
            cout << "\nRemaining card: 1\n";
            temp.pop();
        }

        else
        {
            while(1)
            {
                first = temp.front();
                temp.pop();
                cout << " " << first;
                last = temp.front();
                temp.pop();
                temp.push(last);

                if(temp.size()==1)
                break;

                cout << ",";

            }

            hold_last =  temp.front();
            temp.pop();
            cout << "\nRemaining card: " << hold_last << "\n";
        }


    }


    return 0;
}

