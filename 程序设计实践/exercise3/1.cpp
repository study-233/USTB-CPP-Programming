/**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Course {
public:
    Course(string name_, Course *prerequisite_)
    : name(name_), id(counter++), prerequisite(prerequisite_) { }
    
    void printCourse() {
        cout << "Course " << id << "-" << name << " has prerequisites: ";
        if(prerequisite) {
            cout << prerequisite->name << " ";
            for(Course* pre = prerequisite->prerequisite; pre; pre = pre->prerequisite) {
                cout << pre->name << " ";
            }
        } else {
            cout << "none";
        }
        cout << endl;
    }

    string name;
    static int counter;
    int id;
    Course* prerequisite;
};

int Course::counter = 0;

int main() {
    vector<Course*> courses;
    string command, name;
    int preId;
    while (cin >> command) {
        if (command == "c") {
            cin >> name >> preId;
            courses.push_back(new Course(name, (preId==-1 ? nullptr : courses[preId])));
        } else if (command == "s") {
            for(auto course : courses)
                course->printCourse();
        } else if (command == "e")
            break;
    }

    // Clean up dynamic allocation
    for(auto course : courses)
        delete course;

    return 0;
}