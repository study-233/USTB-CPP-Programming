#include<iostream>
#include<string>
using namespace std;

int main(){

  string lake[4] = {"Dongting", "Hongze", "Poyang", "Tai"}; // 湖的名称
  for (int a = 0; a < 4; ++a) { 
    for (int b = 0; b < 4; ++b) {
      if (a == b) continue; 
      for (int c = 0; c < 4; ++c) { 
        if (a == c || b == c) continue; 
        for (int d = 0; d < 4; ++d) { 
          if (a == d || b == d || c == d) continue; 

          int truth_count[4]{ 0 }; // 各人说真话的次数,顺序为A、B、C、D
          if (a == 3) ++truth_count[0];     
          if (b == 0) ++truth_count[0];    
          if (c == 1) ++truth_count[0];    
          if (b == 3) ++truth_count[1];     
          if (a == 0) ++truth_count[1];     
          if (c == 2) ++truth_count[1];    
          if (d == 1) ++truth_count[1];    
          if (b == 0) ++truth_count[2];    
          if (a == 1) ++truth_count[2];     
          if (c == 3) ++truth_count[3];    
          if (b == 2) ++truth_count[3];    
          if (a == 1) ++truth_count[3];    
          if (d == 0) ++truth_count[3];   
          
          if (truth_count[0] == 1 && truth_count[1] == 1 && truth_count[2] == 1 && truth_count[3] == 1) { // 4个人每人仅答对了一个
            int rank[] = { a, b, c, d }; 
            string rank_lake[4];
            for (int i = 0; i < 4; ++i) {
              rank_lake[rank[i]] = lake[i]; // 湖的排名
            }
            for (int i = 0; i < 4; ++i) {
              cout << rank_lake[i] << " Lake" << endl; // 输出从小到大排列的湖泊名称
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}