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
#define MAX 20000

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
    int t=0, container[MAX],query[MAX],i,n,q,repeat,j;
    bool present;

    while(cin >> n >> q)
    {
        if(n==0 && q==0)
        break;

        for(i=0; i<n; i++)
        cin >> container[i];


        for(i=0; i<q; i++)
        cin >> query[i];

        cout << "CASE# " << ++t << ":" << endl;

        for(j=0; j<q; j++)
        {
            present=false;
            repeat=0;

            for(i=0; i<n; i++)
            {
                if(container[i] < query[j])
                repeat++;

                else if(container[i]==query[j])
                present=true;

            }

            if(present)
            cout << query[j] << " found at " << repeat+1 << endl;

            else
            cout << query[j] << " not found" << endl;

        }

    }

    return 0;
}
