#include  <iostream>
using  namespace  std;

struct    node    //结点结构
{
        int  data;
        node*  next;
};

node*  CreateList();    //建立链表函数声明
void    PrintList(node*);  //输出链表中结点信息函数声明
node*  head  =  NULL;    //全局指针变量存放链表头结点地址-头指针

/*创建链表:请输入一个整数值作为新结点的数据信息,输入0时建立链表结束*/
node*  CreateList()    //建立链表函数
{
        node*  s,  *  p=NULL;  //  s指向新结点，p指向链表中最后的结点  
        s  =  new  node;      //动态建立第一个新结点
      //  cout  <<  "请输入一个整数值作为新结点的数据信息,输入0时建立链表结束"  <<  endl;
      //  cout  <<  "第"  <<  n  +  1  <<  "个结点"  <<  endl;
        cin  >>  s->data;    //输入新结点数据
        head  =  NULL;      //头指针初始值为NULL
        if  (s->data  ==  0)    //第一个结点数据就为0，建立一个空链表
        {
                //cout  <<  "您建立的空链表"  <<  endl;
                delete    s;    //释放数据为0的结点
        }
        else  //建立非空链表
        {
                while  (s->data  !=  0)    //通过判断新结点数据来进行循环
                {
                        if  (head  ==  NULL)      head  =  s;  //头指针赋值
                        else    p->next  =  s;    //将新结点插入已有链表的最后
                        p  =  s;  //  p指向链表中最后的结点  
                      //  n  =  n  +  1;//结点个数增1
                        s  =  new  node;  //动态建立一个新结点
                      //  cout  <<  "请输入一个整数值作为新结点的数据信息,输入0时建立链表结束"  <<  endl;
                      //  cout  <<  "第"  <<  n  +  1  <<  "个结点"  <<  endl;
                        cin  >>  s->data;  //输入新结点数据
                }
                p->next  =  NULL;  //设置链表尾部为空
                delete    s;    //释放数据为0的结点
          //      cout  <<  endl  <<  "链表建立完成...";
          //      cout  <<  "建立的链表中共有"  <<  n  <<  "个节点"  <<  endl  <<  endl;
        }
        return  (head);  //返回头指针  
}

/*遍历链表*/
void    PrintList(node*  head)    //输出链表中结点信息函数,链表遍历
{
        node*  p  =  head;
        int  i  =  1;
        //cout  <<  endl  <<  "遍历链表..."  <<  endl;
        if  (head  !=  NULL)    //如果链表非空，即链表中有结点
                do                          //循环输出接点数据，直到移动到链表尾，即最后一个结点
                {
                        cout  <<    p->data  <<  endl;
                        p  =  p->next;
                }  while  (p  !=  NULL);
        else
        {
                cout  <<  "空链表!"  <<  endl;
        }
//        cout  <<  "链表中共有"  <<  n  <<  "个节点"  <<  endl;
}
//  查找单链表中倒数第K个结点
node*  RGetKthNode(node*  pHead,  unsigned  int  k)  //  函数名前面的R代表反向
{
if (pHead == NULL || k <= 0) return NULL;  // 边界检查
    
    node* p1 = pHead;
    node* p2 = pHead;
    for(unsigned int i = 1; i < k; ++i)  // p1向前移动k-1步
    {
        if(p1->next != NULL) p1 = p1->next;
        else return NULL;    // 如果k大于链表长度，则返回NULL
    }
    
    while(p1->next != NULL)   // p1和p2同时向前移动，直到p1到达末尾
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2;  // 当p1到达末尾时，p2刚好走到倒数第k个节点

}

int  main()
{
        node  *  head  =  CreateList();
        //PrintList(head);
        int  k;  cin  >>  k;
      node  *find  =  RGetKthNode(head,  k);
      if  (find  ==  NULL)  cout  <<  "无效";
      else  cout  <<  find->data;
      return  0;
}