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

#define INF (1 << 31) - 1
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14
#define cInp(a) scanf("%d",&a)
#define cInp1(a,b) scanf("%d%d",&a,&b)
#define cInp2(a,b,c) scanf("%d%d%d",&a,&b,&c)

struct NumberTheory
{
	int GCD(int a, int b) { return (b == 0 ? a : GCD(b, a%b)); }
	int LCM(int a, int b) { return (a * (b / GCD(a, b))); }

};


// Implementing Strongly Connected Components //

vector<int> SCC[2002];
vector<int> GRAPH[2002];
int N,a,b,c,M,indexGlobal,sccCount;

// Holding the node information //

struct NodeInfo
{
	int index;
	int lowLink;
	bool onStack;

};

stack<NodeInfo> S;

NodeInfo objNode[2002];

void reset()
{
	for(int i=0; i<=2000; i++)
	{
		objNode[i].index = INF;
		objNode[i].lowLink = INF;
		objNode[i].onStack = false;

		SCC[i].clear();
		GRAPH[i].clear();
	}

}

void StronglyConnected(int v)
{
	objNode[v].index = indexGlobal;
	objNode[v].lowLink = indexGlobal;

	indexGlobal++;

	S.push(objNode[v]);
	objNode[v].onStack = true;

	for(int i=0; i<GRAPH[v].size(); i++)
	{
		if(objNode[GRAPH[v][i]].index == INF)
		{
			StronglyConnected(GRAPH[v][i]);
			objNode[v].lowLink = min(objNode[v].lowLink,objNode[GRAPH[v][i]].lowLink);
		}

		else if(objNode[GRAPH[v][i]].onStack)
		{
			objNode[v].lowLink = min(objNode[v].lowLink,objNode[GRAPH[v][i]].index);
		}
	}


	// If v is a root node , pop the stack and generate an SCC //

	if(objNode[v].lowLink == objNode[v].index)
	{
		sccCount++;

		while(true)
		{
			NodeInfo w = S.top();
			S.pop();
			//w.onStack = false;
			objNode[w.index].onStack = false;
			SCC[sccCount].push_back(w.index);

			if(objNode[v].index == w.index) break;
		}

	}

}

int main()
{

	while(cInp1(N,M))
	{
		if(!N && !M) break;

		reset();
		indexGlobal = 1;
		sccCount = -1;

		while(M--)
		{
			cInp2(a,b,c);
			GRAPH[a].push_back(b);
			if(c==2) GRAPH[b].push_back(a);

		}

		for(int i=1; i<=N; i++)
		{
			if(objNode[i].index==INF)
				StronglyConnected(i);

		}

		//printf("Edges : %d\n",sccCount);

		if(!sccCount) printf("1\n");
		else printf("0\n");

	}

    return 0;
}
