#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class Student{
    public:
        string name;
        int roll_number;
        map<string , int> lesson_grade;
        void create_student();
        void search();
        void calculate_grade();


};
void show_menu(){
    system("cls");
    cout << "------MENU------" << endl << endl ;
    cout << "1-<Add student>" << endl;
    cout << "2-<Search student>" << endl ;
    cout << "3-<Grade calculation>" << endl << endl;
    string option_txt = "[Choose your option]" ;
    for(int i = 0 ; i<=option_txt.size() ; i++){
        cout << option_txt[i] ;
        _sleep(50) ;
    }
    
    int option ; 
    cin >> option ;
    if(option == 1){
        Student a;
        a.create_student();
    }
}
void Student::create_student(){
    cout << "Enter roll number: " ;
    cin >> this->roll_number;
    cout << endl << "Enter student name: " ; 
    cin >> this->name ; 
    cout << endl << "Enter math grade of this student: " ; 
    int mathgrade; 
    cin >> mathgrade ; 
    cout <<endl <<  "Enter chemestry grade of this student: " ;
    int chemestrygrade ; 
    cin >> chemestrygrade ; 
    this->lesson_grade["math"] = mathgrade ; 
    this->lesson_grade["chemestry"] = chemestrygrade;
    ofstream file(to_string(this->roll_number)+".txt"); //line1:roll number / line2:name
    file << to_string(this->roll_number)+"\n" ; 
    file << this->name+"\n" ; 
    file << to_string(this->lesson_grade["math"])+"\n" ; 
    file << to_string(this->lesson_grade["chemestry"])+"\n" ;
    file.close();
    
}
void Student::search(){
    cout << "Enter roll number: " ; 

}
int main(){
    while (true){
        show_menu();
    }

}