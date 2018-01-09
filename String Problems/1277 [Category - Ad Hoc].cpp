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

#define MAX 10000000
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


    int TC,N;
    cInp(TC);

    while(TC--)
    {
        cInp(N);
        vector<string> Data;
        vector<string> Attd;

        for(int i=0; i<N; i++)
        {
			getchar();
            string str;
            cin >> str;
            Data.push_back(str);
        }

		int cnt = 0;

        for(int i=0; i<N; i++)
        {
            string str;
            cin >> str;
            int pr=0,m=0;

            for(int j=0; j<str.length(); j++)
            {
                if(str[j] == 'P') pr++;
                else if (str[j] == 'M') m++;
            }

            int total = str.length() - m;
			double val = (double) ((pr*100)/total);
            if(val < 75.0000)
			{
				if(cnt==0) cout << Data[i];
				else cout << " " << Data[i];
				cnt++;
			}

        }

        cout << "\n";

    }


    return 0;
}
