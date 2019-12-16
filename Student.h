#pragma once

#include <vector>
#include <string>
#include "StudentGroup.h"
#include "StudentsTypes.h"

enum studentsType {normal,smart,social};

class Strategy;
class Social;
class Normal;
class Smart;
class Group;

class Student
{

public:
	Student(const std::string& fname,const std::string& iname,const std::string& oname,int mark,studentsType stype);
	~Student();
	const std::string& getFName();//получить имя
	const std::string& getIName();//получить фамилию
	const std::string& getOName();//получить отчество
    void addGroup(Group& group);//добавить группу в список групп
	void removeGroup(Group& group);//удалить группу из *групп* студента
	const std::vector<Group*>& getGroups();//получить группы студента
	int getMark();//получить успеваемость студента
	void setMark(int Mark);//задать успеваемость студента
	void changeRole(studentsType stype); //смена типа студента
	void Session();//в этом методе будет вызываться метод из выбранной стратегии. 
	void nextTry();//в этом тоже

private:
	std::vector<Group*> groups;//группы студента
	std::string  FName;// имя студента
	std::string  IName;// фамилию студента
	std::string  OName;// отчество студента
	int mark;//успеваемость студента
	Strategy *strategy;//выбранная стратегия. 
};


std::ostream& operator<<(std::ostream& stream, Student& student);//перегрузка оператора вывода
