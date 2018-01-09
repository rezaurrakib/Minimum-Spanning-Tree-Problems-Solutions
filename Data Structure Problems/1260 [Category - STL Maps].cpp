// Reza, Sr. Software Engineer
// Digital Imaging Group, Samsung Research, Bangladesh

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstring>
#define MAX 10100
using namespace std;

typedef map<string,int> m;
typedef map<string,int>:: iterator iit;
m hardwood;
iit counter;


int main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,k,t,count;
    bool space=false;
    //string str;
    char a[MAX];
    cin >> t;
    getchar();
    getchar();

    while(t--)
    {
        count=0;
        while(1)
        {
            if(gets(a)==NULL)
                break;

            if(!strlen(a))
                break;

            hardwood[a]++;
            count++;
        }

        if(space)
            cout << "\n";
        else
            space=true;

        for(counter=hardwood.begin(); counter!=hardwood.end(); counter++)
        {
            long data = ((*counter).second)*100;
            double output =(double)data/count;
            cout << (*counter).first << " " << fixed << setprecision(4) << output <<"\n";
        }
        hardwood.clear();

    }

    return 0;
}
