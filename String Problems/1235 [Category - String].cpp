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

#define INF (1 << 31) - 1
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

	int TC;
	cin >> TC;
	getchar();

	while(TC--)
	{
		string str,output;
		getline(cin,str);

		int sz = str.length();

		for(int i = sz/2-1; i>=0; i--)
			output.push_back(str[i]);

		for(int i = sz-1; i>=sz/2; i--)
			output.push_back(str[i]);

		cout << output << "\n";
	}

	return 0;
}
