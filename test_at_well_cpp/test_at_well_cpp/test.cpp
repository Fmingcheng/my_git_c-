//thisָ���ܲ���Ϊ��
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
//	A* p = nullptr;  //thisָ��Ϊ��
//	//p->PrintA(); //������thisָ�룬����ʱthisָ��Ϊ��ָ�룬�������
//	p->show();
//	getchar();
//	return 0;
//}

//������������
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
//	Date(const Date& d) //��������Ҫ�����ã���Ȼ��ѭ������
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

//class��struct������
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
//	//s.Func(); //class��ԱĬ����˽�е�
//
//	Person p;
//	p.Func(); //struct��ԱĬ����˽�е�
//	p.show();
//
//	getchar();
//	return 0;
//}

//����ڴ��С��ô��
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
//	A a; // û�г�Ա�����ڴ��СĬ��Ϊ1
//	cout << sizeof(a) << endl;
//
//	B b; // class�ڴ��Сֻ����Ա�����й�
//	cout << sizeof(b) << endl;
//
//	C c; //������ڴ����
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
//	A(int a = 10) //����ؼ��ֲ�����A a3 = 11 ���ֹ�����Ϊ����ֹ���������캯������ʽ����ת��
//		:_a(a) //��ʼ���б��Ƕ����Ա�����ĵط�
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
//	static int count() //��̬��Ա������û��thisָ�룬���ܷ��ʷǾ�̬��Ա
//	{
//		return i;
//	}
//
//private:
//	int _a;
//	static int i; //��̬��Ա�����������������������涨��
//};
//
//int A::i = 0;
//
//void Test()
//{
//	A(); //�������󣬼��ü����٣�������һ�о͵�����
//	A a1;
//	A a4 = A(60); //�������󣬿�������
//	A a2(a1);
//	A(20).Print();
//	A a3 = 11; //��ʽ����ת�� 1. ��11����һ���������� 2. �������󿽱�����a3  3. �ᱻ�������Ż���ֱ����11ȥ����a3
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