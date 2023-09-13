#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student{
    public:
        string name;
        int roll_number;
        map<string , int> lesson_grade;
        void create_student();
        //void get_data();
        //void calculate_grade();


};

void Student::create_student(){
    map<string ,int> lesson_grade;
    cout << "Enter student name: " ; 
    cin >> this->name ; 
    cout << endl << "Enter math grade of this student: " ; 
    int mathgrade; 
    cin >> mathgrade ; 
    cout <<endl <<  "Enter chemestry grade of this student: " ;
    int chemestrygrade ; 
    cin >> chemestrygrade ; 
    this->lesson_grade["math"] = mathgrade ; 
    this->lesson_grade["chemestry"] = chemestrygrade;
    
    

}
