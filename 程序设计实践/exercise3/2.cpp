/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Student{
public:
    string name;
    int id;
    static int counter;

    Student(string name_) : name(name_),id(counter++) {}
    void printStuent(){
        cout<<id<<"-"<<name<<" ";
    }
};
int Student::counter = 0; 

class Major{
public:
    string name;
    int id;
    static int counter;

    vector<Student*> students;

    Major(string name_):name(name_),id(counter++){}

    void printMajor(){
        cout << "Major " << id << "-" << name << ": ";
        for(auto student : students) {
            cout << student->id << "-" << student->name << " ";
        }
        cout << endl;
    }


};
int Major::counter = 0; 

int main(){
    //freopen("E:\CPPCODE\in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    vector<Student*> students;
    vector<Major*> majors;
    string command, name;
    while (cin >> command) {
        if (command == "s") {
            cin >> name;
            students.push_back(new Student(name));
        } 
        else if (command == "m") {
            cin >> name;
            majors.push_back(new Major(name));
        }
        else if (command == "n") {
            for(auto Student : students)
                Student->printStuent();
            cout<<endl;
        }
        else if (command == "l") {
            for(auto Major : majors)
                Major->printMajor();
        }
        else if (command == "a") {
            int student_id, major_id;
            cin>>student_id>>major_id; 
            Student* student = students[student_id];
            Major* major = majors[major_id];
            major->students.push_back(student);
        }

        else if (command == "d") {
            int student_id, major_id;
            cin >> student_id >> major_id;
            Student* student = students[student_id];
            Major* major = majors[major_id];
            major->students.erase(remove(major->students.begin(), major->students.end(), student), major->students.end());

            
        }
        else if (command == "v") {
            int student_id, old_major_id, new_major_id; 
            cin >> old_major_id >> student_id >> new_major_id;
            Student* student = students[student_id];
            Major* old_major = majors[old_major_id];
            Major* new_major = majors[new_major_id];
            new_major->students.push_back(student);
            old_major->students.erase(remove(old_major->students.begin(), old_major->students.end(), student), old_major->students.end());
        }
        else if (command == "e")
            break;
    }

    // Clean up dynamic allocation
    for(auto Student : students)
        delete Student;
    for(auto Major : majors)
        delete Major;   
    return 0;
}
