#pragma once

#include "StudentGroup.h"
#include <vector>
#include <string>

enum studentsType {normal,smart,social};

class Group;
class Social;
class Normal;
class Smart;

class Student
{

public:
	Student(const std::string& fname,const std::string& iname,const std::string& oname,int mark);
	virtual ~Student();
	const std::string& getFName();//получить имя
	const std::string& getIName();//получить фамилию
	const std::string& getOName();//получить отчество
    void addGroup(Group& group);//добавить группу в список групп
	void removeGroup(Group& group);//удалить группу из *групп* студента
	const std::vector<Group*>& getGroups();//получить группы студента
	int getMark();//получить успеваемость студента
	void setMark(int Mark);//задать успеваемость студента
	virtual void Session(Student& st)=0;//сдача экзамена студентом
	virtual void nextTry(Student& st)=0;//пересдача экзамена студентом
	Student *state;//через этот указатель вызывается поведение студента,которое зависит от его типа.

private:
	std::vector<Group*> groups;//группы студента
	std::string  FName;// имя студента
	std::string  IName;// фамилию студента
	std::string  OName;// отчество студента
	int mark;//успеваемость студента
};


std::ostream& operator<<(std::ostream& stream, Student& student);//перегрузка оператора вывода