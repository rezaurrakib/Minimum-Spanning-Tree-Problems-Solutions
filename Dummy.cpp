// Rezaur Rahman Rakib //
// Digital Imaging Group, Samsung Research, Bangladesh //

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

#define MAX 10000000
#define INF 100000000
#define PI acos(-1.0)
#define READ(filename) freopen(filename,"r",stdin)
#define WRITE(filename) freopen(filename,"w",stdout)
#define EPS 1e-14




// Returns the possible solution for the exact subset sum //
// Elements are infinite numbers // 
// If no solution occurs, then returns impossible //



ll N,S,weight[500];
ll dp[405][60],ret;
bool visitedPoints[405][60],pathPoints[405][60];

ll AnotherApproach(ll sum, ll index)
{
	if(index==N || sum<0) return INF;
	if(sum==0) return 0; 

	if(visitedPoints[sum][index]) return dp[sum][index];

	dp[sum][index]=INF;
	visitedPoints[sum][index] = true;

	ll temp = AnotherApproach(sum-weight[index],index) + 1;

	if(dp[sum][index]>temp)
	{
		dp[sum][index]=temp;
		pathPoints[sum][index]=true;
	}

	temp = AnotherApproach(sum,index+1);

	if(dp[sum][index]>temp) // more better solution //
	{
		dp[sum][index]=temp;
		pathPoints[sum][index]=false;
	}

	return dp[sum][index];
}


ll pathPrint(ll sum, ll index)
{
	if(sum==0) 
	{
		printf("\n");
		return 0;
	}

	
	/*if(sum<0 || index==N){
		cout << "No sol ... \n";
		return 0;
	}*/

	if(pathPoints[sum][index])
	{
		cout << " " << weight[index];
		pathPrint(sum-weight[index],index);
	}

	else pathPrint(sum,index+1);
}

int main()
{
    //READ("ipt.txt");
    //WRITE("output.txt");
	ll TC;
	int tc=1;
	cin >> TC;

	while(TC--)
	{
		cin >> N >> S;
		memset(dp,0,sizeof(dp));
		memset(visitedPoints,false,sizeof(visitedPoints));
		memset(pathPoints,false,sizeof(pathPoints));

		for(ll i=0; i<N; i++)
			cin >> weight[i];

		reverse(weight,weight+N);
		printf("Case %d:",tc++);

		ll length = AnotherApproach(S,0);

		if(length!=INF)
		{
			printf(" [%lld]",length);
			pathPrint(S,0); // a loop can trace all sequences ...... ;)
		}
		else printf(" impossible\n");
	}

    return 0;
}