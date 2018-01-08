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
#define MAX 510
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
#define max(a,b) (a>b) ? a : b

typedef long long ll;

struct NumberTheoryLib
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


    string INT_TO_STRING(ll INTEGER)
    {
        string number;

        stringstream out ;
        out << INTEGER;
        number = out.str();

        return(number);
    }

    // CONVERT THE NUMBER (Here, string number) INTO REQUIRED BASE(Here,req_base) //
    // FROM THE CURRENT BASE (Here, base) //
    // YOU MAY CONSIDER base=X AND req_base=Y ......... :D //

    string Base_Conversion(string number, int base,int req_base)
    {
        // Convert into Decimal //

        ll sum=0;
        int j = number.length()-1;
        for(int i=0; i<number.length(); i++,j--)
        {
            if(isdigit(number[i])) number[i]-=48;
            else number[i]-=87;
            sum = sum + (number[i]*pow(base,j));
        }

        if(req_base==10) return INT_TO_STRING(sum);

        // Convert to required Base from Decimal//

        string temp;

        while(sum/req_base)
        {
            if(sum%req_base>9) temp.push_back((sum%req_base)+87);
            else temp.push_back((sum%req_base)+48);
            sum/=req_base;
        }

        if(sum%req_base>9) temp.push_back((sum%req_base)+87);
        else temp.push_back((sum%req_base)+48);

        reverse(temp.begin(),temp.end());
        return (temp);
    }


};

int main()
{
    int N,tc=1;
    bool sp = false;

    while(cin >> N && N)
    {
        if(sp) cout << "\n";
        else sp = true;

        int cons[201],y,x;
        double sumx=0,sumy=0;
        bool first = true;
        memset(cons,0,sizeof(cons));

        for(int i=0; i<N; i++)
        {
            cin >> x >> y;
            cons[y/x] +=x;
            sumx+=x;
            sumy+=y;
        }

        cout << "Cidade# " << tc++ << ":\n";

        for(int i=0; i<=200; i++)
        {
            if(cons[i] && first) {cout << cons[i] << "-" << i; first = false;}
            else if(cons[i] && !first) cout << " " << cons[i] << "-" << i;
        }
        cout << "\nConsumo medio: " << fixed << setprecision(2) << floor((sumy/sumx)*100)/100 << " m3.\n";
    }

    return 0;
}
