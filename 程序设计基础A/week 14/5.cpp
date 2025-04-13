#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    string phone_number;
public:
    Person(string name, string phone_number) : name(name), phone_number(phone_number) {}
};

class Student: virtual public Person {
protected:
    string major1;
public:
    Student(string name, string phone_number, string major1)
    : Person(name, phone_number), major1(major1) {}
};

class Teacher: virtual public Person {
protected:
    string course;
public:
    Teacher(string name, string phone_number, string course)
    : Person(name, phone_number), course(course) {}
};

class StudentTeacher : public Student, public Teacher {
public:
    StudentTeacher(string name, string phone_number, string major1, string course)
    : Person(name, phone_number), Student(name, phone_number, major1), Teacher(name, phone_number, course) {}

    void display() {
        cout << name << '\n' << phone_number << '\n'<< major1 << '\n' << course << '\n';
    }
};

int main() {
    string name,phone_number,major1,course;
    cin>>name>>phone_number>>major1>>course;
    StudentTeacher st(name, phone_number, major1, course);
    st.display();
    return 0;
}