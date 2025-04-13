#include <iostream>
using namespace std;
int main()
{
    int year,month,day,sum=0,days=0;
    cin>>year>>month>>day;
    while(month>1)
    {
        switch (month-1)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                days=31; break;
            case 4:case 6:case 9:case 11:
                days=30; break;
            case 2:if(((year%4==0)&&!(year%100==0)) || year%400==0 )
                        days=29;
                    else days=28;
        }
        sum+=days;
        month--;
    }
    sum+=day;
    cout<<sum;
}