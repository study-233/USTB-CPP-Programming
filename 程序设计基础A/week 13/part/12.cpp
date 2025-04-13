#include<iostream>
#include <algorithm>

using namespace std;

const int MAXLENGTH = 10; // 此处定义一个常量MAXLENGTH为10

class CSet {
public:
   int* data; // 升序保存集合元素
   int size; // 集合大小

   // 用数组a的前size个元素初始化集合
   CSet(int a[], int size) {
       this->size = size <= MAXLENGTH? size: MAXLENGTH;
       data = new int[MAXLENGTH];
       for (int i = 0; i < this->size; i++) {
            data[i] = a[i];
       }
       sort(data, data + this->size);
    }

   // 拷贝构造函数
   CSet(const CSet &set) {
       size = set.size;
       data = new int[size];
       for (int i = 0; i < size; i++) {
            data[i] = set.data[i];
       }
   }

   // 添加元素，成功则返回true
   bool AddElem(int e) {
        if (size < MAXLENGTH) {
            data[size++] = e;
            sort(data, data + size);
            return true;
        } else {
            return false;
        }
   }

   // 求两个集合的交集并返回
   CSet Intersection(CSet &set) {
        int inter[MAXLENGTH];
        int inter_size = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < set.size; j++) {
                if (data[i] == set.data[j]) {
                    inter[inter_size++] = data[i];
                    break;
                }
            }
        }
        return CSet(inter, inter_size);
    }

   // 打印集合元素
   void Print()  {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
   int a[8] = {2, 3, 4, 5, 6, 7, 8, 9};
   int b[10] = {1, 3, 4, 6, 8, 9, 11, 14, 16, 18};
   int x, y;
   cin >> x >> y;
   CSet s1(a, x), s2(b, y);
   s1.Print();
   s2.Print();
   s1.AddElem(11);
   s1.Print();
   (s1.Intersection(s2)).Print();
   return 0;
}