/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int lightcoins[12]={0};
    int heavycoins[12]={0};
    string left;
    string right;
    string state;
    int T;
    cin>>T;
    while (T--){
        for(int i=0;i<3;i++){
            cin>>left>>right>>state;
            switch (state[0]){
                case 'u':
                    for(int j=0;j<4;j++){
                        lightcoins[left[j]-'A']++;
                        heavycoins[right[j]-'A']++;                        
                    }
                    break;
                
                case 'd':
                    for(int j=0;j<4;j++){
                        lightcoins[right[j]-'A']++;
                        heavycoins[left[j]-'A']++; 
                    }
                    break;
                case 'e':
                    for(int j=0;j<4;j++){
                        lightcoins[left[j]-'A']--;
                        lightcoins[right[j]-'A']--;
                        heavycoins[left[j]-'A']--;
                        heavycoins[right[j]-'A']--;
                    }
                    break;           
            }
        }
        int lightindex=0;
        int heavyindex=0;
        int p=0,q=0;
        for(int i=0;i<12;i++){
            if(p < lightcoins[i]){
                p = lightcoins[i];
                lightindex = i;
            }
            if(q < heavycoins[i]){
                q = heavycoins[i];
                heavyindex = i;
            }
        }
        sort(lightcoins,lightcoins+12);
        sort(heavycoins,heavycoins+12);
        if(lightcoins[11]!=lightcoins[10]){
            cout<<char(lightindex +'A')<<" is the couterfeit coin and it is light"<<endl;
        }
        else    
            cout<<char(heavyindex+'A')<<" is the couterfeit coin and it is heavy"<<endl;

    }
    
    return 0;
}
