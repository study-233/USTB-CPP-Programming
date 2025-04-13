/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
char orlights[10];
char lights[10];
char result[10];

int Getbit(char c,int i){       // 读取第i位
    return ( c >> i ) & 1 ;
}

void Setbit(char & c,int i,int v){      //设置第i位
    if(v) c |= (1 << i) ;
    else c &= ~(1 << i) ;
}

void Flipbit(char & c,int i){       //翻转第i位
    c ^= (1 << i) ;
}

void Output(int t,char result[]){       //输出
    cout << "PUZZLE #"<< t << endl;
    for(int i = 0;i < 5; i++){
         for(int j = 0;j < 6; j++){
            cout<< Getbit(result[i],j);
            if(j<5)
                cout<<" ";
         }
         cout << endl;
    }
}
int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                int s;
                cin>>s;
                Setbit(orlights[i],j,s);
            }
        }
        for(int n=0;n<64;n++){
            int switchs=n;      //假设第一行开关状态
            memcpy(lights,orlights,sizeof(orlights));
            for(int i=0;i<5;i++){
                result[i]=switchs;
                for(int j=0;j<6;j++){
                    if(Getbit(switchs,j)){      //翻转左右的灯
                        if(j>0)
                            Flipbit(lights[i],j-1);
                        Flipbit(lights[i],j);
                        if(j<5)
                            Flipbit(lights[i],j+1);
                    }
                }
                if(i<5)         
                    lights[i+1] ^= switchs;      //翻转下一行的灯

                switchs = lights[i];        //下一行开关状态
            }

            if(lights[4] == 0){
                Output(t,result);
                break;
            }
        }
    }

    return 0;
}
