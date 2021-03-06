#include <QCoreApplication>
#include <string>
#include <vector>
#include <iostream>
#include "pfinder.h"
#include<QObject>
#include<math.h>

using namespace std;

enum stat{
    INIT=2,FINAL=3
};

int main()
{

    vector<point> v(0);
    for(size_t i=0;i<100;i++)
        for(size_t j=0;j<100;j++)
        {
            point p;
            p.x=i;
            p.y=j;
            if((i==12 && (j==12||j==13))||(i==50 && j==50))p.obs=true;
            v.push_back(p);
        }
    point start,end;start.x=10;start.y=10;end.x=99;end.y=99;
    PFinder pf(v,start,end);
    auto p=pf.findPath();
    cout<<"NB="<<pf.getnb()<<endl;
    return 0;
}
