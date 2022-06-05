#pragma once
class PrivateAccessError {
private :
	int a;
	void f();
	PrivateAccessError();
public :

	void setA(int);
	int getA();

	int b;
	PrivateAccessError(int x);
	void g();
};