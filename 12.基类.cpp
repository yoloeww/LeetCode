#include<iostream>
using namespace std;
#include<string>
class Person
{ 
protected:
	string _name; // 姓名
	string _sex;  // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	// sobj = pobj;  错误

	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj
		Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;

	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
		ps2->_No = 10;
}
