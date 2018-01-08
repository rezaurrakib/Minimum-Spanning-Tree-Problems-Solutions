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
#include <sstream>

using namespace std;

typedef long long ll;

#define MAX 10000000
#define PI acos(-1.0)// Reza, Sr. Software Engineer
// Digital Imaging Group, Samsung Research, Bangladesh
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)


ll M;

bool negModCheckEven(ll a)
{
	if(a<0) a*=-1;
	if(a%2==0) return true;
	else return false;

}

bool negModCheckOdd(ll a)
{
	if(a<0) a*=-1;
	if(a%2==1) return true;
	else return false;

}


struct MyStruct
{

	bool operator()(const ll &a, const ll &b)
	{
		if(a%M < b%M) return true;
		if(a%M == b%M)
		{
			if(negModCheckOdd(a) && negModCheckEven(b)) return true;
			else if(negModCheckOdd(a) && negModCheckOdd(b) && a>b) return true;
			else if(negModCheckEven(a) && negModCheckEven(b) && a<b) return true;
		}

		return false;

	}
}obj;


int main()
{
    //READ("input.txt");
	//WRITE("output.txt");

	ll N;

	while(cin >> N >> M)
	{
		if(N==0 && M==0){
			cout << "0 0\n";
			break;
		}

		vector<ll> V;
		ll a;

		for(ll i=0; i<N; i++)
		{
			cin >> a;
			V.push_back(a);
		}

		sort(V.begin(),V.end(),obj);

		cout << N << " " << M << "\n";

		for(ll i=0; i<V.size(); i++)
			cout << V[i] << "\n";

	}

    return 0;
}
