#pragma once

#include "Student.h"
#include <vector>
#include <iterator>
#include <algorithm>

enum sortsTypes {byMarks,byLexicographic};//типы сортировок для функции sortStudents

class Student;

class Group
{
private: 
	int Number;//номер группы
	std::vector<Student*> students;//студенты групп
public:
	Group(int number);//конструктор
	const std::vector<Student*>& getStudents();//получить студентов группы
	bool addStudent(Student& student);//добавить студента в группу
	int getNumber();//получить номер группы
	bool tryToRemoveStudent(Student& student);//удалить студента из группы
	Student& getStudentByName(const std::string& FName,const std::string& IName,const std::string& OName);//получить студента по ФИО
	void sortStudents(sortsTypes sort);//сортировка студентов
};

std::ostream& operator<<(std::ostream& stream, Group& group);//перегрузка оператора вывода