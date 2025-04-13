#include<iostream>
using namespace std;
class Bed{
public:
   void watch() {
      std::cout << "Watching\n";
   }
};
class Sofa{
public:
   void sleep() {
      std::cout << "Sleeping\n";
   }
};
class SleeperSofa:public Bed,public Sofa{
    public:
        void foldout(){
            cout<<"Fold out\n";
        }
};
int main() {
   SleeperSofa mysleeper;
   mysleeper.watch();
   mysleeper.foldout();
   mysleeper.sleep();
   return 0;
}