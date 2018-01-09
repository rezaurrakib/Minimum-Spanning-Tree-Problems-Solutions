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
#define cInp1(a,b) scanf("%d %d",&a,&b)
#define cInp2(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define DFS_BLACK 1
#define DFS_WHITE 0

typedef long long ll;
typedef long l;
typedef vector<string> vs;

#define edge pair< ll, ll >
#define MAX 40010

// ( w (u, v) ) format
vector< pair< ll , edge > > GRAPH, MST;
ll parent[MAX],total,Tcost;
int N,M;

ll findset(ll x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

int kruskal()
{
    ll i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<M; i++)
    {
        pu = findset(GRAPH[i].second.first);
        pv = findset(GRAPH[i].second.second);
        if(pu != pv)
        {
            //MST.push_back(GRAPH[i]); // add to tree
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }

    return 0;
}

ll reset()
{
    // reset appropriate variables here
    // like MST.clear(), GRAPH.clear(); etc etc.
    for(ll i=0; i<=N; i++) parent[i] = i;
    //MST.clear();

    return 0;
}

void print()
{
    //ll i;
    /*for(i=0; i<MST.size(); i++)
    {
        printf("( %d", MST[i].second.first);
        printf(", %d )", MST[i].second.second);
        printf(": %d\n", MST[i].first);
    }
    printf("Minimum cost: %d\n", total);*/

    cout << total << "\n";
}

int main()
{
    //READ("input.txt");
	//WRITE("output.txt");

    ll i, u, v, w;

	while(cInp1(N,M))
    {
        if(N==0 && M==0)
            break;

        //Tcost=0;
        reset();
        for(i=0; i<M; i++)
        {
            cin >> u >> v >> w;
            GRAPH.push_back(pair< ll , edge >(w, edge(u, v)));
            //Tcost += w;
        }
        kruskal(); // runs kruskal and construct MST vector
        print(); // prints MST edges and weights

        GRAPH.clear();

    }

    return 0;
}
