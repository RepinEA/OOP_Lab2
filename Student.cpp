#include "Student.h" 


Student::Student(const std::string& fname,const std::string& iname,const std::string& oname,int mark)
{
	FName=fname;
	IName=iname;
	OName=oname;
	this->mark=mark;
}

Student::~Student()
{

}

const std::string& Student::getFName()
{
	return FName;
}

const std::string& Student::getIName()
{
	return IName;
}

const std::string& Student::getOName()
{
	return OName;
}

void Student::addGroup(Group& group)
{
	this->groups.push_back(&group);
}

void Student::removeGroup(Group& group)
{
	for(std::vector<Group*>::iterator it = groups.begin(); it!=groups.end(); it++)    
	{
		if(*it==&group)
		{
			groups.erase(it);
			return;
		}
	}
}

int Student::getMark()
{
	return mark;
}

void Student::setMark(int Mark)
{
	this->mark=Mark;
}

const std::vector<Group*>& Student::getGroups()
{
	return groups;
}

std::ostream& operator<<(std::ostream& stream, Student& student)
{
	stream << "-----------------------------------------------------------------------------------------------" << std::endl;
	stream << "Имя студента: " << student.getIName() << " " << student.getFName() << " " << student.getMark() << std::endl;
	stream << "Успеваемость студента: " << static_cast<unsigned>(student.getMark()) << std::endl;
	stream << "Номера групп, в которых находится студент: ";

	std::vector<Group*> gr =student.getGroups();

	for (unsigned i = 0; i < gr.size(); i++)
	{
		stream << gr[i]->getNumber() << " ";
	}
	stream << std::endl;

	stream << "-----------------------------------------------------------------------------------------------" << std::endl;

	return stream;
}

