// L1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "Student.h"


using namespace std;


int main()
{
	
	setlocale(LC_ALL, "Russian");
	
	Student* FirstStudent = new Student("Репин", "Иван", "Дмитриевич", 0, social);
	Student* Second= new Student("Колесников", "Дмитрий", "Андреевич", 0, normal);
	Student* Thrid= new Student("Ветров", "Иван", "Михайлович", 0, smart);
	
	FirstStudent->Session();
	cout<<"Сдача экзамена студентом из студ.совета: "<< FirstStudent->getFName() <<" : "<<FirstStudent->getMark()<<endl;
	FirstStudent->nextTry();
	cout<<"Его волшебная пересдача: "<< FirstStudent->getFName() <<" : " <<FirstStudent->getMark()<<endl;

	cout<<endl;

	Second->Session();
	cout<<"Сдача экзамена обычным рандомным студентом: "<< Second->getFName() <<" : "<<Second->getMark()<<endl;
	Second->nextTry();

	cout<<"Его рандомная пересдача: "<< Second->getFName() <<" : "<<Second->getMark()<<endl;

	cout<<endl;

	Thrid->Session();
	cout<<"Сдача экзамена умным студентом: "<< Thrid->getFName() <<" : "<<Thrid->getMark()<<endl;
	Thrid->nextTry();
	cout<<"Его пересдача: " << Thrid->getFName() << " : " << Thrid->getMark() << endl;

	cout<<endl;

	Second->changeRole(social);
	Second->nextTry();
	cout<<"Превращение обычного студента в умного и его пересдача: "<< Second->getFName() <<" : " << Second->getMark() << endl;



	Group group7091(7091);
	Group group8032(8032);
	
	group7091.addStudent(*FirstStudent);
	group7091.addStudent(*Second);
	group7091.addStudent(*Thrid);
	
	cout<<endl<<"Работоспособность прошлых методов первой лабораторной"<<endl;
	//group7091.tryToRemoveStudent(*Thrid);

	group7091.sortStudents(byMarks);
	vector<Group*> gr;
	
	for (unsigned i = 0; i < (group7091.getStudents().size()); i++)
	{
		cout << "------------------------------------------------------------------------------" << endl;
		cout << "Имя студента: " << group7091.getStudents()[i]->getIName() << " " << group7091.getStudents()[i]->getFName() << " " << group7091.getStudents()[i]->getOName() << endl;
		cout << "Успеваемость студента: " << static_cast<unsigned>(group7091.getStudents()[i]->getMark()) << endl;
		cout << "Номера групп, в которых находится студент: ";
		gr=group7091.getStudents()[i]->getGroups();
		for (unsigned j = 0; j < gr.size(); j++)
		{
			cout << gr[j]->getNumber() << " ";
		}
		cout << endl;

		cout << "------------------------------------------------------------------------------" << endl;
		gr.clear();
	}
	


	system("Pause");
	return 0;
}
