
#ifndef PFINDER_H
#define PFINDER_H
#include<vector>
#include<string>
#include<iostream>
#include<math.h>

typedef struct{
    size_t x=0,y=0;
    bool visited=false,obs=false;
}point;
using namespace std;
class PFinder
{
    size_t nb=0;
    vector<pair<int,int>> best;
    vector<point> _map;
    point init,goal,current;
    double calcP(point);
    point getPointByXY(size_t x,size_t y);
    vector<point> getCurrentEntourage();
public:
    size_t getnb(){return nb;}
    PFinder(vector<point>,point,point);
    void NextStep();
    point getCurrent();
    void showMap();
    vector<point> findPath();
};

#endif // PFINDER_H
