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

#define MAX 1000
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


struct cmp
{

    bool operator()(const string &a, const string &b)
    {
        return a.length()<b.length();
    }

}obj;



int main()
{
    //READ("input.txt");
    //WRITE("output.txt");

    int N,L,C;

    while(cin >> N >> L >> C)
    {
        string str;
        vector<string> Data;

        for(int i=0; i<N; i++)
        {
            cin >> str;
            Data.push_back(str);
        }

        //sort(Data.begin(),Data.end(),obj);

        /*for(int i=0; i<N; i++)
            cout << Data[i] << " ";*/

        int wordLength = 0,line = 0,page = 1;

        for(int i=0; i<N; i++)
        {
            if(wordLength + Data[i].length() > C)
            {
                //cout << "New Line starts ............ \n";
                wordLength = 0;
                line++;
            }

            if(line>=L) // page Refreshing
            {
                //cout << "New Page starts ............ \n";
                page++;
                wordLength = 0;
                line=0;
            }

            wordLength+=Data[i].length();
            wordLength++; // space count

        }

        cout << page << "\n";

    }

    return 0;
}
