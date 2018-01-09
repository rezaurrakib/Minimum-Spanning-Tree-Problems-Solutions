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
    int TC;
    cin >> TC;
    getchar();

    while(TC--)
    {
        string str,temp;
        getline(cin,str);

        for(int i=0; i<str.length(); i++)
            if(isalpha(str[i]))
                temp.push_back(str[i]+3);
            else temp.push_back(str[i]);

        string output;

        for(int i=temp.size()-1; i>=0; i--)
            output.push_back(temp[i]);

        //cout << "output : " << output << "\n";

        int ln = (temp.size())/2;

        //cout << ln << "\n";

        for(int i=ln; i<temp.size(); i++)
            output[i] = output[i]-1;

        cout << output << "\n";
    }


    return 0;
}
