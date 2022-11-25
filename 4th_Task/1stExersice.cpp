#include <iostream>
#include <string>
 
using namespace std;

struct Lesson; 
 
struct Student
{
    int age;
    string name;
    int NoL; /* Number of Lessons */
    Lesson* arr[10];
    
};

struct Lesson
{
	string name;
	int NoS; /* Number of Students */
	Student* arr[10];
};


void Output(Lesson Les){
	cout << "Lesson name: "<< Les.name<<"\nStudents:"<< endl;
	for(int i = 0; i<Les.NoS; i++){
    	cout<< Les.arr[i]->name<<"\n";
	};
	cout<<"\n";
};

void Output(Student Stud){
	cout << "Name: " << Stud.name << "\tAge: " << Stud.age << "\nLessons:" << endl;
    for(int i = 0; i<Stud.NoL; i++){
    	cout<< Stud.arr[i]->name<<"\n";
	};
	cout<<"\n";
};

int main()
{
    Student Vlad;
    Lesson Prog;
    Lesson AnMeh;
    Lesson Matan;
    Student Serega;
        
    Vlad.name = "Vlad";
    Vlad.age = 18;
    Vlad.NoL = 2;
	Vlad.arr[0] = &AnMeh;
	Vlad.arr[1] = &Matan;
	
	Serega.name = "Sergey";
    Serega.age = 19;
    Serega.NoL = 2;
	Serega.arr[0] = &Prog;
	Serega.arr[1] = &AnMeh;
    
    Prog.name = "Proga";
    Prog.NoS= 1;
    Prog.arr[0] = &Serega;

    AnMeh.name = "AnalMech";
   	AnMeh.NoS = 2;
   	AnMeh.arr[0] = &Vlad;
   	AnMeh.arr[1] = &Serega;
    
    Matan.name = "Matan";
    Matan.NoS= 1;
    Matan.arr[0] = &Vlad;
    
    Output(Vlad);
	Output(AnMeh);
	Output(Serega);
	Output(Prog);
}
