#include <iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int array[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && (year % 400 == 0 || year % 4 == 0 && year % 100 != 0))
			return 29;
		return array[month];
	}
	// 四个成员函数
	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month<13 &&
			day>0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}
	}

	Date(const Date& d) //拷贝构造
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	bool operator==(const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !((*this) == d);
	}

	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		if (_year == d._year &&
			_month > d._month)
			return true;
		if (_year == d._year &&
			_month == d._month &&
			_day > d._day)
			return true;
		return false;
	}

	bool operator<(const Date& d)
	{
		return !((*this) > d && (*this) == d);
	}

	bool operator>=(const Date& d)
	{
		return !((*this) < d);
	}

	bool operator<=(const Date& d)
	{
		return !((*this) > d);
	}
	////d1 + 10
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return (*this);
	}

	Date& operator+=(int day)
	{
		if (_day + day > GetMonthDay(_year, _month))
		{
			int c = (_day + day) - GetMonthDay(_year, _month);
			_month++;
			while (c > GetMonthDay(_year,_month))
			{
				_month++;
				if (_month > 12)
				{
					_year++;
					_month = 1;
				}
				c -= GetMonthDay(_year, _month);
			}

			_day = c;

		}
		else
		{
			_day += day;
		}
		return (*this);
	}

	Date& operator-=(int day)
	{
		if (_day - day < 0)
		{
			day = day - _day;
			_month--;
			while (day > GetMonthDay(_year, _month))
			{
				_month--;
				if (_month < 1)
				{
					_year--;
					_month = 12;
				}
				day -= GetMonthDay(_year, _month);
			}
			_day = GetMonthDay(_year, _month) - day;
		}
		else
		{
			_day -= day;
		}
		return (*this);
	}

	//Date operator+(int day)
	//Date operator-(int day)

	//// 前置
	Date& operator++()
	{
		if ((++_day) > GetMonthDay(_year, _month))
		{
			_month++;
			_day = 1;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return (*this);
	}

	Date& operator--()
	{
		if ((--_day) < 1)
		{
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		return (*this);
	}

	//// 后置

	Date& operator++(int)
	{
		Date tmp(*this);
		if ((++_day) > GetMonthDay(_year, _month))
		{
			_month++;
			_day = 1;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}
		return tmp;
	}

	Date operator--(int)
	{
		Date tmp(*this);
		if ((--_day) < 1)
		{
			_month--;
			if (_month < 1)
			{
				_year--;
				_month = 12;
			}
			_day = GetMonthDay(_year, _month);
		}
		return tmp;
	}

	//// d1-d2
	int operator-(const Date& d)
	{

	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2017, 12, 31);

	d1++;
	d1.Print();
	//cout<< (d1 == d2) <<endl;//必须要加括号
	//cout<< (d1 != d2) <<endl;
	//cout<< (d2 < d1) <<endl;
	getchar();
	return 0;
}