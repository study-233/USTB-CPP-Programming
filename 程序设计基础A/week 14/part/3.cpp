#include<iostream>
using  namespace  std;

class  Bed  {
public:
        Bed(){}
        void  Sleep()
        {
                cout  <<  "Sleeping"  <<  endl;
        }
};

class  Sofa  {
public:
        Sofa(){}
        void  WatchTV()
        {
                cout  <<  "Watching"  <<  endl;
        }
};

class SleeperSofa:public Bed,public Sofa{
    public:
        void foldout(){
            cout<<"Fold out\n";
        }
};



int  main()
{
        SleeperSofa  ss;
   ss.WatchTV();
   ss.foldout();
   ss.Sleep();

        
        return  0;
}