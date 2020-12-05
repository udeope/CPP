//============================================================================
// Name        : p022.cpp
// Author      : crt
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std ;


class A
{
public:
	int a1_ ;

protected:
	int a2_ ;

private:
	int a3_ ;

public:
	A() ;
	virtual ~A() ;

};


class B : public A
{
public:
	B() ;
	virtual ~B() ;
	void dump() ;
};


A::A()
{
	a1_ = 1 ;
	a2_ = 2 ;
	a3_ = 3 ;
}

A::~A()
{

}

B::B()
:A()
{
}

B::~B()
{
}

void B::dump()
{
	cout << "[1] a1: " << a1_ << endl ;
	cout << "[2] a2: " << a2_ << endl ;
	cout << "[3] a3: " << a3_ << endl ;

}

int main()
{
	B objB ;

	cout << "[4] B.a1_: " << objB.a1_ << endl ;
	cout << "[5] B.a2_: " << objB.a2_ << endl ;
	cout << "[6] B.a3_: " << objB.a3_ << endl ;
}






