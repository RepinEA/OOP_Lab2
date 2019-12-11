#pragma once

#include "Student.h"
#include <vector>
#include <string>
#include <iostream>

//Class Normal

class Normal:public Student
{
public:
	Normal(const std::string& fname,const std::string& iname,const std::string& oname,int mark):Student(fname,iname,oname,mark)
	{
		this->state=this;
	};
	~Normal(){};
	void Session(Student& st) override;
	void nextTry(Student& st) override;

};

void Normal::Session(Student& st)
{
	st.setMark(  2 + rand()%(5- 2+1)   );
}

void Normal::nextTry(Student& st)
{
	st.setMark( 2 + rand()%(5- 2+1) );
}

//Class Social

class Social:public Normal 
{
public:
	Social(const std::string& fname,const std::string& iname,const std::string& oname,int mark):Normal(fname,iname,oname,mark)
	{
		this->state=this;
	};
	~Social(){};
	void nextTry(Student& st) override;
};

void Social::nextTry(Student& st)
{
	st.setMark(  3 + rand()%(4- 3+1)   );
}

//Class Smart

class Smart:public Student
{
public:
	Smart(const std::string& fname,const std::string& iname,const std::string& oname,int mark):Student(fname,iname,oname,mark)
	{
		this->state=this;
	};
	~Smart(){};
	void Session(Student& st) override;
	void nextTry(Student& st) override;
};

void Smart::Session(Student& st)
{
	st.setMark( 4 + rand()%(5- 4+1)  );
}

void Smart::nextTry(Student& st)
{
	st.setMark(5);
}


void changeRole(Student& st,studentsType stype) //смена типа студента
{

	if(stype==smart)
	{
		if (&st!=st.state) delete st.state; 
		st.state=new Smart(st.getFName(),st.getIName(),st.getOName(),st.getMark());
		return;
	}

	if(stype==social)
	{
		if (&st!=st.state) delete st.state; 
		st.state=new Social(st.getFName(),st.getIName(),st.getOName(),st.getMark());
		return;
	}

	if(stype==normal)
	{
		if (&st!=st.state) delete st.state; 
		st.state=new Normal(st.getFName(),st.getIName(),st.getOName(),st.getMark());
		return;
	}
}