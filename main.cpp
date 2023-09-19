#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <unistd.h>
#include <filesystem>
#include <format>
using namespace std;
string menu_massage; 
//global score
void Delete_stu() ;
void search();
class Student{
    public:
        string name;
        int roll_number;
        map<string , int> lesson_grade;
        void create_student();
        void calculate_grade();
};
vector<Student> list1 ;
void show_menu(){
    system("clear");
    cout << menu_massage  ; 
    cout << "------MENU------" << endl << endl ;
    cout << "1-<Add student>" << endl;
    cout << "2-<Search student>" << endl ;
    cout << "3-<Delete student>" << endl << endl;
    string option_txt = "[Choose your option]" ;
    for(int i = 0 ; i<=option_txt.size() ; i++){
        cout << option_txt[i] ;
        usleep(50000);
    }
    
    int option ; 
    cin >> option ;
    if(option == 1){
        Student a;
        a.create_student();
    }
    if(option == 2) {
        search();
    }
    if(option == 3) {
        Delete_stu();
    }
}
void Student::create_student(){
    system("clear");
    cout << "Enter roll number: " ;
    cin >> this->roll_number;
    cout << "Enter student name: " ; 
    cin >> this->name ; 
    cout << "Enter math grade of this student: " ; 
    int mathgrade; 
    cin >> mathgrade ; 
    cout <<  "Enter chemestry grade of this student: " ;
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
void search(){
    system("clear");
    cout <<endl << "Enter roll number: " ;
    string number ;
    cin >> number ; 
    ifstream file(number+".txt");
    string item; 
    int counter =0;
    while(file >> item ){
        counter +=1 ; 
        if(counter==1){
            cout << "roll number: " << item <<endl; 
        }else if(counter ==2){
            cout << "name: " << item << endl ;
        }else if(counter == 3){
            cout << "math grade: " << item << endl;
        }else if(counter == 4){
            cout << "chemestry grade: " << item << endl;
        }
    }
    string temp;
    cin >> temp ; 
}
//delete function 
void Delete_stu(){
    string rollnumber;
    system("clear");
    cout << "Enter the roll number: " ;
    cin >> rollnumber;
    rollnumber = rollnumber + ".txt";
    
    if (remove(rollnumber.c_str()) == 0){
        menu_massage = "-----------------------------\n|successfully deleted 1 user| \n------------------------------ \n\n" ; 

        
    }else{
        menu_massage = "----------------------------\n|roll number does not exist|\n----------------------------\n\n" ;
        
    }

}

int main(){
    while (true){
        show_menu();
    }

}