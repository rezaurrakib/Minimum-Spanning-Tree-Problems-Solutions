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
    //WRITE("output.txt");

    string str1,str2;
    int dp[MAX][MAX];

    while(getline(cin,str1))
    {
        getline(cin,str2);

        int sz1 = str1.length();
        int sz2 = str2.length();

        for(int i=0; i<=sz1; i++) dp[0][i] = 0;
        for(int i=0; i<=sz2; i++) dp[i][0] = 0;
        int mx = 0;

        for(int i=1; i<=sz1; i++)
        {
             for(int j=1; j<=sz2; j++)
             {
                 if(str1[i-1]==str2[j-1])
                 {
                        dp[i][j] = dp[i-1][j-1] + 1;
                        mx = max(mx,dp[i][j]);

                 }
                 else dp[i][j] = 0;//max(dp[i][j-1],dp[i-1][j]);

             }

        }

        cout << mx << "\n";

    }


    return 0;
}
