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

    int t,l,f,train[51],i,temp,j,k;

    scanf("%d",&t);

    while(t--)
    {
        f=0,i=0;

        scanf("%d",&l);

        while(l--)
        {
            scanf("%d",&train[i]);
            i++;
        }


        for(j=0; j<i; j++)                // Algorithm of bubble sort
        {

            for(k=1; k<i-j; k++)          // in order to avoid swapping
                // with garbase value
            {

                if(train[k-1] > train[k])
                {
                    temp=train[k-1];
                    train[k-1]=train[k];
                    train[k]=temp;
                    f++;
                }
            }
        }


        printf("Optimal train swapping takes %d swaps.\n",f);
    }


    return 0;
}
