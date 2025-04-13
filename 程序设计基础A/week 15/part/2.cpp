#include<iostream>
using  namespace  std;

struct  Node  {
        int  data;
        Node  *next;
};

class  List  {
protected:
    Node *node;
public:
    List() {
        node = new Node();
        node->next = NULL;
    }

    virtual void Insert(int val) {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = node->next;
        node->next = newNode;
    }

    void Delete(int val) {
        Node *temp = node;
        while (temp->next != NULL) {
            if (temp->next->data == val) {
                Node *delNode = temp->next;
                temp->next = temp->next->next;
                delete delNode;
                break;
            }
            temp = temp->next;
        }
    }


        void  Print()
        {
                if  (node->next==0)
                        return;
                Node  *n=node->next;
                for  (;n!=0;n=n->next)
                        cout  <<  n->data  <<  "  ";
                cout  <<  endl;
        }
};

class  Set  :  public  List  {
public:
    virtual void Insert(int val)  {
        Node *temp = node;
        while (temp->next != NULL) {
            if (temp->next->data == val)
                return;
            temp = temp->next;
        }
        List::Insert(val);
    }

};

int  main()
{
        List  *p,list1;
        Set  set1;
        p=&list1;
        char  opt;  
        while  (cin  >>  opt){
              if  (opt  ==  '?')  break;
              int  num;
              cin  >>  num;
              if  (opt  ==  'i'){
                          p->Insert(num);
              }
              else  if  (opt  ==  'd'){
                          p->Delete(num);
              }
        }
        p->Print();
        
        p=&set1;
        while  (cin  >>  opt){
              if  (opt  ==  '?')  break;
              int  num;
              cin  >>  num;
              if  (opt  ==  'i'){
                          p->Insert(num);
              }
              else  if  (opt  ==  'd'){
                          p->Delete(num);
              }
        }
        p->Print();
        return  0;
}