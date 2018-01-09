// Reza, Sr. Software Engineer
// Digital Imaging Group, Samsung Research, Bangladesh

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

typedef long long ll;
typedef long l;
typedef vector<string> vs;

#define edge pair< ll, ll >
#define MAX 200010

// ( w (u, v) ) format
vector< pair< ll , edge > > GRAPH, MST;
ll parent[MAX], total, N, E, Tcost;

ll findset(ll x, ll *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

int kruskal()
{
    ll i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
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
    MST.clear();

    return 0;
}

void print()
{
    ll i;
    /*for(i=0; i<MST.size(); i++)
    {
        printf("( %d", MST[i].second.first);
        printf(", %d )", MST[i].second.second);
        printf(": %d\n", MST[i].first);
    }
    printf("Minimum cost: %d\n", total);*/

    cout << Tcost-total << "\n";
}

int main()
{
    //freopen("inp.txt","r",stdin);
    // freopen("out.txt","w",stdout)
    ll i, u, v, w;

    while(cin >> N >> E)
    {
        if(N==0 && E==0)
            break;

        Tcost=0;
        reset();
        for(i=0; i<E; i++)
        {
            cin >> u >> v >> w;
            GRAPH.push_back(pair< ll , edge >(w, edge(u, v)));
            Tcost += w;
        }
        kruskal(); // runs kruskal and construct MST vector
        print(); // prints MST edges and weights

        GRAPH.clear();

    }

    return 0;
}
