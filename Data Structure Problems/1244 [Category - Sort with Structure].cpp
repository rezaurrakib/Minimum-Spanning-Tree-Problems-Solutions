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

struct COMP
{
    bool operator()(const pair<string,int> &a, const pair<string,int> &b)
    {
        if(a.first.length() == b.first.length())
            return a.second < b.second;

        else return a.first.length() > b.first.length();
    }

}cmp;

int main()
{
    int TC;
    cin >> TC;
    getchar();

    while(TC--)
    {
        string s,str;
        vector<pair<string,int> >Data;
        getline(cin,str);
        stringstream ss(str);
        int idx = 1 ;

        while(ss>>s)
        {
            Data.push_back(make_pair(s,idx));
            idx++;
        }

        sort(Data.begin(), Data.end(), cmp);
        cout << Data[0].first;

        for(int i=1; i<Data.size(); i++)
            cout << " " << Data[i].first;

        cout << "\n";

    }

    return 0;

}
