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

#define SIZE 210
#define MAX 1000000
#define NODES 100005
#define DFS_GREEN 1000 // Yet Not Visited
#define DFS_RED 1100   // Already Visited

#define INF 10000000
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14
#define cInp(a) scanf("%d",&a)
#define cInp1(a,b) scanf("%d%d",&a,&b)
#define cInp2(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define edge pair<int,int>

//#define gc getchar_unlocked
#define gc getchar
//#define pc putchar_unlocked
#define pc putchar

typedef long long ll;

struct NumberTheory
{
    bitset<1000000> bs;
    vector<ll> prime;


    int GCD(int a, int b){ return (b == 0 ? a : GCD(b, a%b));}
    int LCM(int a, int b){ return (a * (b / GCD(a, b)));}

    ll sieve()
    {
        bs.set();

        bs[0]=bs[1]=0;
        for(ll i=2; i<MAX; i++)
        {
            if(bs[i])
            {
                for(ll j=i*i; j<MAX; j+=i)
                    bs[j]=0;

                prime.push_back(i);
            }
        }

        return 0;
    }


    bool check_prime(ll n)
    {
        if(n<MAX){
            if(bs[n]) return true;
            else return false;
        }

        // number greater than n //
        for(ll i=0; i<prime.size(); i++)
            if(n%prime[i]==0)
                return false;
        return true;
    }


};

int main()
{
    int TC,N,M;
    cin >> TC;

    while(TC--)
    {
        map<string,double> Price;
        string str;
        double val;

        cin >> N;
        getchar();

        for(int i=0; i<N; i++)
        {
            cin >> str >> val;
            Price[str] = val;
        }

        double sum=0.0;
        cin >> M;
        getchar();
        for(int j=0; j<M; j++)
        {
            cin >> str >> val;
            sum+=Price[str]*val;
        }

        cout << fixed << setprecision(2) << "R$ " << sum << "\n";

    }

    return 0;

}
