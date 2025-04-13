#include<iostream>
#include<string>
using  namespace  std;

class  Person  {
protected:
        string  name;
        static  int  count;
        int  number;
        int  level;
        float  salary;
public:
        Person(string  name);
        string  GetName(){
                return  name;
        }
        int  GetNum(){
                return  number;
        }
        virtual  ~Person(){}
        virtual  float  MonthSalary()  =  0;
        virtual  void  SetSales(float  sales)  {}
        virtual  void  SetSumSales(float  sales)  {}
};

class  Manager  :  public  Person  {

public:
    Manager(string name): Person(name) { salary = 8000; level = 4; } 
    float  MonthSalary() {return salary;}

};

class  Partime_Technician  :  public  Person  {
public:
    Partime_Technician(string name): Person(name) { level = 3; salary = 20 * 8 * 100; }
    float  MonthSalary() {return salary;}

};

class  Sales_Manager  :  public  Person  {
private:
    float sales;
public:
    Sales_Manager(string name):Person(name),sales(0){
        level = 3;
        salary = 5000;
    }
    void SetSumSales(float sales) {
        this->sales = sales;
        salary += sales * 0.005;
    }
    float  MonthSalary() {return salary;}

};

class  Partime_Sales  :  public  Person  {
private:
    float sales;
public:
        Partime_Sales(string name):Person(name),sales(0){
            level = 1;
        }
        void SetSales(float sales)  {
            this->sales = sales;
            salary = sales * 0.04;
        }
    float MonthSalary() {return salary;}

};
int Person::count=0;
Person::Person(string  name):name(name),number(++count),salary(0){}
int  main()
{
        int  numOfPersons;
        cout  <<  "Input  the  number  of  persons:  "<<endl;
        cin  >>  numOfPersons;
        Person  **  personArray  =  new  Person*  [numOfPersons];
        int  i  =  0;
        while  (i  <  numOfPersons){
              cout  <<  "Input  the  person's  name:  "<<endl;
              string  aName;
              cin  >>  aName;
              cout  <<"Input  the  person's  type:  "  <<endl;
              int  opt;
              cin  >>  opt;
              switch(opt){
                    case  1:  {
                personArray[i] = new Manager(aName);

                                          cout  <<"A  Manager  is  added."<<endl;
                                          break;
                                    }
                    case  2:  {
                personArray[i] = new Partime_Technician(aName);

                                        cout  <<"A  Partime_Technician  is  added."<<endl;
                                        break;
                    }
                    case  3:  {
                cout << "Input sum of sales:\n";
                int sales;
                cin >> sales;
                personArray[i] = new Sales_Manager(aName);
                personArray[i]->SetSumSales(sales);
                                        cout  <<"A  Sales_Manager  is  added."<<endl;
                                        break;
                    }
                    case  4:  {
                cout << "Input his/her sales:\n";
                int sales;
                cin >> sales;
                personArray[i] = new Partime_Sales(aName);
                personArray[i]->SetSales(sales);
                                        cout  <<"A  Partime_Sales  is  added."<<endl;
                                        break;
                    }
              }
        }
        cout  <<  "The  persons  are:  "<<endl;
        for  (i  =  0;  i  <  numOfPersons;  ++i){
        cout << personArray[i]->GetNum() << " " << personArray[i]->GetName() << " " << personArray[i]->MonthSalary() << endl;
        }
        
        for  (i  =  0;  i  <  numOfPersons;  ++i){
                delete  
personArray[i];

        }
        
        

        return  0;
}