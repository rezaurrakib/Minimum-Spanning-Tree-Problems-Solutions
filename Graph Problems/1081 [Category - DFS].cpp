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

#define MAX 10000
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14
#define cInp(a) scanf("%d",&a)
#define cInp1(a,b) scanf("%d%d",&a,&b)
#define cInp2(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define DFS_WHITE false
#define DFS_BLACK true

struct NumberTheory
{
	int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a%b)); }
	int LCM(int a, int b) { return (a * (b / GCD(a, b))); }

};

set<int>Graph[MAX];
bool visited[MAX];
int TC,N,E,tc=1;

void dfs(int u, int sp)
{
    visited[u] = DFS_BLACK;
    // 0-1 pathR(G,1)
    for(set<int>::iterator it = Graph[u].begin(); it!=Graph[u].end(); it++)
    {
        for(int i=0; i<2*sp; i++) cout << " ";

        if(!visited[*it])
        {
            cout << u << "-" << *it << " pathR(G," << *it << ")\n";
            dfs(*it,sp+1);
        }
        else cout << u << "-" << *it << "\n";

    }
}

void reset()
{
    for(int i=0; i<=N; i++)
        Graph[i].clear();

}

int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    cin >> TC;

    while(TC--)
    {
        cout << "Caso " << tc++ << ":\n";
        cin >> N >> E;

        reset();

        for(int i=0; i<E; i++)
        {
            int a,b;
            cin >> a >> b;
            if(a<N && b<N)
            Graph[a].insert(b);
        }

        memset(visited,DFS_WHITE,sizeof(visited));

        for(int i=0; i<N; i++)
        {
            if(!visited[i])
            {
                dfs(i,1);
                if(Graph[i].size())cout << "\n";
            }

        }


        //cout << "\n";
    }

    return 0;
}
