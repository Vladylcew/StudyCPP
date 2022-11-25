#include <iostream>
#include <string>
#include <vector>
 
using namespace std;

struct Lesson; 
 
struct Student {
    vector<Lesson*> lesson_list;
    string name;
    int age;

    Student(string n, int x){
        name = n;
        age = x;
    }
    void add_lesson(Lesson* tmp);
};


struct Lesson {
    vector<Student*> student_list;
    string name;

    Lesson(string n) {
        name = n;
    }
    void add_student(Student* tmp);
};


void Output(Lesson Les){
	cout << "Lesson name: "<< Les.name<<"\nStudents:"<< endl;
	for(int i = 0; i<Les.student_list.size(); i++){
    	cout<< Les.student_list[i]->name<<"\n";
	};
	cout<<"\n";
};

void Output(Student Stud){
	cout << "Name: " << Stud.name << "\tAge: " << Stud.age << "\nLessons:" << endl;
    for(int i = 0; i< Stud.lesson_list.size(); i++){
    	cout<< Stud.lesson_list[i]->name<<"\n";
	};
	cout<<"\n";
};

void Student::add_lesson(Lesson* tmp)
{
    lesson_list.push_back(tmp);
    tmp->student_list.push_back(this);
}


void Lesson::add_student(Student* tmp)
{
    student_list.push_back(tmp);
    tmp->lesson_list.push_back(this);
}

void NewStud(vector<Lesson> &lessons, vector<Student> &students){
	cout << "Write name:\n";
	string n;
	cin >> n;
	cout<< "Write age: \n";
	int a;
	cin >> a;
	students.push_back(Student(n,a));
	cout << "Write number of lessons: \n";
	int y = -1;
	while(y < 0 or y >lessons.size()){
		cin >>y ;
		if (y > lessons.size()){
			cout<<"Write number that less, that whole number of lessons ("<<lessons.size()<<")\n";
		};
	};
	cout<<"Choose the lessons:\n";
	for(int i = 0;i<lessons.size();i++)
			{
		    	cout << i+1<<". "<< lessons[i].name<<"\n";	
			};
	for(int i = 0; i < y;i++){
		int z;
		cin >> z;
		students[students.size()-1].add_lesson(&lessons[z-1]); 
	};

}

void NewLes(vector<Lesson> &lessons, vector<Student> &students){
	cout << "Write name:\n";
	string n;
	cin >> n;
	lessons.push_back(Lesson(n));
	cout << "Write number of students: \n";
	int y = -1;
	while(y < 0 or y >students.size()){
		cin >>y ;
		if (y > students.size()){
			cout<<"Write number that less, that whole number of students ("<<students.size()<<")\n";
		};
	};
	cout<<"Choose the students:\n";
	for(int i = 0;i<students.size();i++)
			{
		    	cout << i+1<<". "<< students[i].name<<"\n";	
			};
	for(int i = 0; i < y;i++){
		int z;
		cin >> z;
		lessons[lessons.size()-1].add_student(&students[z-1]); 
	};

}

int main()
{	
	vector<Student> students;
    vector<Lesson> lessons;

    students.push_back( Student("Vlad",18));
    
    students.push_back(Student("Serega",19));
    
    lessons.push_back(Lesson("Prog"));
    lessons.push_back(Lesson("AnMeh"));
    lessons.push_back(Lesson("Matan"));
	
	    
	students[0].add_lesson(&lessons[1]);
	students[0].add_lesson(&lessons[2]);
	
	students[1].add_lesson(&lessons[1]);
	students[1].add_lesson(&lessons[0]);
    
    
	
	int x = -1;
	while(x != 0)
	{	
		cout << "Choose the command:\n"<<
		"1. See list of Lessons\n"<<
		"2. See list of Students\n"<<
		"3. Add new Student\n"<<
		"4. Add new Lesson\n"<<
		"0. Exit\n";
	    
	    cin >> x;
	    int y = -1;
	    switch (x) 
		{ 
		  case 1:
		    cout<< "Choose what data you want to see:\n";
		    for(int i = 0;i<lessons.size();i++)
			{
		    	cout << i+1<<". "<< lessons[i].name<<"\n";	
			};
			cout << lessons.size()+1<<". See all\n"<<
			"0. Back\n";
			cin >> y;
			if (y == 0)
			{
				break;
			};
			if (y == lessons.size()+1)
			{
				for(int i=0;i<lessons.size();i++)
				{
		    		Output(lessons[i]);
				};
				break;	
			};
			Output(lessons[y-1]);
		    break;
		  case 2:
		    cout<< "Choose what data you want to see:\n";
		    for(int i = 0;i<students.size();i++)
			{
		    	cout << i+1<<". "<< students[i].name<<"\n";	
			};
			cout << students.size()+1<<". See all\n"<<
			"0. Back\n";
			cin >> y;
			if (y == 0)
			{
				break;
			};
			if (y == students.size()+1)
			{
				for(int i=0;i<students.size();i++)
				{
		    		Output(students[i]);
				};
				break;	
			};
			Output(students[y-1]);
		    break; 
		  case 3:
		  	NewStud(lessons,students);
		  	break;
		  case 4:
		  	NewLes(lessons,students);
			break;	
		};
	};
}
