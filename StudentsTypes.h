#include <string>
#include <iostream>

//Class Strategy

class Strategy
{
public:
	virtual int Session()=0;//сдача экзамена студентом
	virtual int nextTry()=0;//пересдача экзамена студентом
};

//Class Normal

class Normal:public Strategy
{
public:
	int Session() override;
	int nextTry() override;
};


//Class Social

class Social:public Strategy 
{
public:
	int Session() override;
	int nextTry() override;
};


//Class Smart

class Smart:public Strategy
{
public:
	int Session() override;
	int nextTry() override;
};
