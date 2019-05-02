//this指针能不能为空
//#include <iostream>
//using namespace std;
//
//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void show()
//	{
//		cout << "show" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;  //this指针为空
//	//p->PrintA(); //解引用this指针，但此时this指针为空指针，程序崩溃
//	p->show();
//	getchar();
//	return 0;
//}

//拷贝构造问题
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 2019,int month = 1,int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d) //拷贝构造要加引用，不然就循环拷贝
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2019, 1, 3);
//	Date d2(d1);
//
//	d1.Print();
//	d2.Print();
//	
//	getchar();
//	return 0;
//}

//class和struct的区别
//#include <iostream>
//using namespace std;
//
//class Student
//{
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//public:
//	void show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//
//struct Person
//{
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//public:
//	void show()
//	{
//		cout << "show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	Student s;
//	s.show();
//	//s.Func(); //class成员默认是私有的
//
//	Person p;
//	p.Func(); //struct成员默认是私有的
//	p.show();
//
//	getchar();
//	return 0;
//}

//类的内存大小怎么算
//#include <iostream>
//using namespace std;
//
//class A
//{
//
//};
//
//class B
//{
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//};
//
//class C
//{
//	void Func()
//	{
//		cout << "Func()" << endl;
//	}
//private:
//	char _a;
//	int i = 0;
//};
//
//int main()
//{
//	A a; // 没有成员变量内存大小默认为1
//	cout << sizeof(a) << endl;
//
//	B b; // class内存大小只跟成员变量有关
//	cout << sizeof(b) << endl;
//
//	C c; //类存在内存对齐
//	cout << sizeof(c) << endl;
//	getchar();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 10) //这个关键字不允许A a3 = 11 这种构造行为，禁止单参数构造函数的隐式类型转换
//		:_a(a) //初始化列表是定义成员变量的地方
//	{
//		++i;
//	}
//
//	A(const A& a)
//	{
//		++i;
//		_a = a._a;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//	static int count() //静态成员函数，没有this指针，不能访问非静态成员
//	{
//		return i;
//	}
//
//private:
//	int _a;
//	static int i; //静态成员变量，类里面声明，类外面定义
//};
//
//int A::i = 0;
//
//void Test()
//{
//	A(); //匿名对象，即用即销毁，过了这一行就调析构
//	A a1;
//	A a4 = A(60); //匿名对象，拷贝构造
//	A a2(a1);
//	A(20).Print();
//	A a3 = 11; //隐式类型转换 1. 用11构造一个匿名对象 2. 匿名对象拷贝构造a3  3. 会被编译器优化，直接拿11去构造a3
//	cout << A::count() << endl;
//}
//
//int main()
//{
//	Test();
//	getchar();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class B
//{
//public:
//	B(int b)
//		:_b(b)
//	{
//	}
//private:
//	int _b;
//};
//
//class A
//{
//private:
//	int _a = 1;
//	B _b = 1;
//	int* a = (int*)malloc(4);
//};
//
//int main()
//{
//	A aa;
//	return 0;
//}

#include <iostream>
using namespace std;

class A
{
public:
	A(int a = 10)
		:_a(a)
	{
	}
	void print()
	{
		cout << _a << endl;
	}
private:
	int _a;
};

int main()
{
	A a(5);
	a.print();

	return 0;
}