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
#define MAX 50005
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
	int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a%b)); }
	int LCM(int a, int b) { return (a * (b / GCD(a, b))); }

};


int main()
{
    string str;
    while(getline(cin,str))
    {
        bool first = true;
        int arr[27];
        int sz = str.length();
        memset(arr,0,sizeof(arr));

        for(int i=0; i<sz; i++)
        {
            if(isalpha(str[i]))
                arr[str[i]-96]++;
        }

        for(int i=1; i<=26; i++)
        {
            if(arr[i])
            {
                i++;
                if(first){cout << (char)(i+95) << ":"; first=false;}
                else cout << ", " << (char)(i+95) << ":";

                while(i<=26 && arr[i])
                    i++;

                cout << (char)(i+95);
            }

        }

        cout << "\n";
    }

}
