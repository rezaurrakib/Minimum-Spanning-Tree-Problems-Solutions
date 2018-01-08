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
    string str;
    int TC;
    cin >> TC;
    getchar();

    while(TC--)
    {
        getline(cin,str);
        int cnt = 0;
        int sz = str.length();
        stack<char> S;
        for(int i=0; i<sz; i++)
        {
            if(str[i]=='<')
               S.push('<');

            else if(str[i] == '>')
            {
                if(!S.empty()){
                    S.pop();
                    cnt++;
                }
            }

        }

        cout << cnt << "\n";


    }

    return 0;

}
