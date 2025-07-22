#include<iostream>
using namespace std;

class Student{

    string name;
    int id;
    double cgpa;
    public:
    /*Student(string name, int id, double cgpa){
        this->name = name;
        this->id = id;
        this->cgpa = cgpa;


    }*/
    // member initializer list
    // can be used only in constructor
    Student(string n, int id, double c): name(n), id(id), cgpa(c){}

    void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"CGPA: "<<cgpa<<endl;
    }
    void updateCgpa(double new_cgpa){
    if(new_cgpa<=4) cgpa = new_cgpa;
    else cout<<"Cannot set CGPA";
    }
};

int main(){

   Student* s1 = new Student("Ratul", 697, 2.43);
   s1->updateCgpa(3.76);
   s1->display();




}
