#include <iostream>
#include <math.h>

using namespace std;

class point{
    private:
            int x;
            int y;

    public:

            point();
            point(int ,int );
            point(const point &);

            ~point();

            friend float distance(const point &,const point&);

            int get_x();
            void set_x(int);

            int get_y();
            void set_y(int);

            void affiche();
            float distance(const point &);

};


point::point(){
    cout<<"CONSTRUCTEUR PAR DEFAUT"<<endl;
    x=0;
    y=0;
}

point::point(int x,int y){
    cout<<"CONSTRUCTEUR PARAM2TRE"<<endl;
    this->x=x;
    this->y=y;
}

point::point(const point &p){
    cout<<"CONSTRUCTEUR COPIE"<<endl;
    *this=p;
    /*x=p.x;
    y=p.y;*/
}

point::~point(){
    cout<<"Destructeur Appelé"<<endl;
}

int point::get_x(){
    return x;
}

void point::set_x(int x){
    this->x=x;
}

int point::get_y(){
    return y;
}

void point::set_y(int y){
    this->y=y;
}


void point::affiche(){
    cout<<"X ="<<x<<endl<<"Y ="<<y<<endl<<endl;
}

float point::distance(const point &p){
    return sqrt(pow(x-p.x,2)+pow(y-p.y,2));
}

float distance(const point &p1,const point &p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

int main()
{

    point a;
    a.affiche();

    point b(5,1);
    b.affiche();

    point c(b);
    b.set_x(0);

    b.affiche();
    c.affiche();

    cout<<"DISTANCE:"<<b.distance(c)<<endl;
    cout<<"DISTANCE:"<<distance(b,c)<<endl;

    return 0;
}
