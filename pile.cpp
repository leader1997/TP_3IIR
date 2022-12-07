#include <iostream>

using namespace std;

// [1,5,6,9,*,*,*]
// -> tab
// -> sommet: 3
// -> taille|max: 7

class pile{
    private:
        int *tab;
        int max;//taille du tableau
        int sommet;
    public:
        pile();
        pile(int );
        pile(pile&);

        ~pile();

        void affiche();
        void empiler(int );
        void depiler();
};

pile::pile(){
    cout<<"PILE PAR DEFAULT"<<endl;
    max=50;
    sommet=0;
    tab=new int[max];
}

pile::pile(int max){
    cout<<"PILE PARAMETRE"<<endl;
    this->max=max;
    sommet=0;
    tab=new int[max];
}

pile::pile(pile &p){
    cout<<"PILE PAR COPIE"<<endl;
    max=p.max;
    sommet=p.sommet;

    tab=new int[max];

    for(int i=0;i<p.sommet;i++){
        tab[i]=p.tab[i];
    }
}

pile::~pile(){
    cout<<"DESTRUCTEUR"<<endl;
    delete [] tab;
}

void pile::affiche(){

    cout<<"PILE : sommet="<<sommet<<", max="<<max<<endl;

    for(int i=0;i<sommet;i++){
       cout<<i<<"->"<< tab[i]<<endl;
    }
}

void pile::empiler(int item){
    if(sommet==max){
        cout<<"pas d'espace!!"<<endl;
    }else{
        tab[sommet]=item;
    }
    sommet++;
}

void pile::depiler(){
    if(sommet==0){
        cout<<"RIEN A DEPILER"<<endl;
    }else{
        sommet--;
    }
}

int main()
{
    pile *p1=new pile();

    p1->depiler();
    p1->empiler(3);
    p1->empiler(99);
    p1->empiler(9);
    p1->empiler(43);

    pile *p2=new pile(*p1);

    pile p3;

    pile p4(p3);

    p3.affiche();

    delete p1;

    return 0;
}
