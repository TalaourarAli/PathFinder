#include "pfinder.h"
#define DEBUG2
PFinder::PFinder(vector<point> m, point p,point p2)
    :_map(m),init(p),goal(p2),current(p){
}
double PFinder::calcP(point c){
    return //pow((init.x-c.x),2)+pow((init.y-c.y),2)+
            pow((goal.x-c.x),2)+pow((goal.y-c.y),2);
}

point PFinder::getPointByXY(size_t x,size_t y){
    for(auto p:_map)
        if(p.x==x && p.y==y)return p;
    throw string("erreur, not found, fct getPointByXY");
}

vector<point> PFinder::getCurrentEntourage(){
    vector<point> v(0);
    size_t cx=current.x;
    size_t cy=current.y;
#ifdef DEBUG
    cout<<"cx :"<<cx<<endl;
    cout<<"cy :"<<cy<<endl;
#endif
    try{
    v.push_back(getPointByXY(cx-1,cy-1));
    v.push_back(getPointByXY(cx-1,cy));
    v.push_back(getPointByXY(cx-1,cy+1));
    v.push_back(getPointByXY(cx,cy-1));
    v.push_back(getPointByXY(cx,cy));
    v.push_back(getPointByXY(cx,cy+1));
    v.push_back(getPointByXY(cx+1,cy-1));
    v.push_back(getPointByXY(cx+1,cy));
    v.push_back(getPointByXY(cx+1,cy+1));
    }
    catch(string c){
        cout<<c<<endl;
        exit(-1);
    }
    return v;

}

point PFinder::getCurrent(){
    return current;
}

void PFinder::NextStep(){
    vector<point> v=getCurrentEntourage();

    auto best=calcP(current);
    point Np=current;
    for(auto i:v){
        //calculer dist <>goal et <>init
        if(!i.visited && !i.obs){
            //cout<<i.obs<<endl;
            nb++;
            auto v=calcP(i);
            if(best>v){
                    best=v;
                    Np=i;
                    i.visited=true;
                   }
            }
        if(i.obs)cout<<"found obs!!"<<endl;
    }
    current=Np;
#ifdef DEBUG
    cout<<"Next Point :"<<current.x << ":"<<current.y<<endl;
#endif

}

vector<point> PFinder::findPath(){
    while(current.x != goal.x || current.y != goal.y) {
        NextStep();
        cout<<"current ="<<current.x<<":"<<current.y<<endl;
#ifdef DEBUG
    cout<<"calling NextStep!!!"<<endl;
#endif
    }
    cout<<"gut"<<endl;
    return _map;
}


void PFinder::showMap(){
    cout<<"The Map :"<<endl;

}
