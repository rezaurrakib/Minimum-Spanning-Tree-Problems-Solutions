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

char arr[] = {'0','1','2','3','4','5','6','7','8','9'};
int val[] = {6,2,5,5,4,5,6,3,7,6};

int main()
{
    int TC;
    cInp(TC);

    while(TC--)
    {
        char str[50000];
        scanf("%s",&str);
        int sz = strlen(str);
        //printf("%d .. \n",sz);
        int sum=0;

        for(int i=0; i<sz; i++)
        {
            for(int j=0; j<10; j++)
            {
                if(arr[j] == str[i])
                {
                    sum+=val[j];
                    break;
                }
            }
        }

        printf("%d leds\n",sum);

    }
    return 0;
}
