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

using namespace std;

typedef long long ll;

#define MAX 1000
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14
#define cInp(a) scanf("%d",&a)
#define cInp1(a,b) scanf("%d%d",&a,&b)
#define cInp2(a,b,c) scanf("%d%d%d",&a,&b,&c)

struct NumberTheory
{
	int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a%b)); }
	int LCM(int a, int b) { return (a * (b / GCD(a, b))); }

};

int main()
{
    //READ("input.txt");

    int N;
    bool sp = false;

    while(cInp(N) && N)
    {
        if(sp) cout << "\n";
        else sp = true;

        vector<string> Data;
        string str;
        int mx = 0;

        for(int i=0; i<N; i++)
        {
            cin >> str;
            Data.push_back(str);
            int len = str.length();
            mx = max(mx,len);
        }

        for(int i=0; i<N; i++)
            cout << setw(mx) << Data[i] << "\n";


    }

    return 0;
}
