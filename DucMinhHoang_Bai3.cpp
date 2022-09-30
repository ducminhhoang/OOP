#include <iostream>
#include <iomanip>

using namespace std;

class Person
{
	private:
		char name[20];
		char date[15];
		char hometown[20];
	public:
		void nhap();
		void xuat();
};

void Person::nhap()
{
	cout << "Nhap ho ten: ";		fflush(stdin);		gets(name);
	cout << "Nhap ngay sinh: ";		fflush(stdin);		gets(date);
	cout << "Nhap que quan: ";		fflush(stdin);		gets(hometown);
}
void Person::xuat()
{
	cout << setw(20) << name << setw(15) << date << setw(20) << hometown;  
}

class Student:public Person
{
	private:
		char id[5], major[10];
		int course;
	public:
		int getCourse(){
			return course;
		}
		void nhap();
		void xuat();
};

void Student::nhap()
{
	Person::nhap();
	cout << "Nhap ma sinh vien: ";	fflush(stdin);		gets(id);
	cout << "Nhap nganh: ";			fflush(stdin);		gets(major);
	cout << "Nhap khoa hoc: ";							cin >> course;
}
void Student::xuat()
{
	Person::xuat();
	cout << setw(10) << id << setw(20) << major << setw(10) << course << endl;
}

class LopHoc
{
	private:
		char id[10], name[10], dayOpen[15];
		Student *x;
		int n;
		Person teacher;
	public:
		void nhap();
		void xuat();
		void arrangeUpByCourse();
};

void LopHoc::nhap()
{
	cout << "Nhap ma lop hoc: ";	fflush(stdin);		gets(id);
	cout << "Nhap ten lop hoc: ";	fflush(stdin);		gets(name);
	cout << "Nhap ngay mo: ";		fflush(stdin);		gets(dayOpen);
	cout << "Nhap so sinh vien: ";						cin>>n;
	x = new Student[n];
	for (int i=0; i<n; i++)
	{
		cout << "NHAP SINH VIEN " << i+1 << " : " << endl;
		cout << "------------------" << endl;
		x[i].nhap();
	}
	cout << "Nhap thong tin giao vien lop: " << endl;
	cout << "------------------------------" << endl;
	teacher.nhap();
}
void LopHoc::xuat()
{
	cout << "--------------------------THONG TIN LOP HOC--------------------------" << endl;
	cout << "Ma lop hoc: " << id << endl;
	cout << "Lop: " << name << endl;
	cout << "Ngay mo lop: " << dayOpen << endl;
	cout << "So sinh vien trong lop: " << n << endl;
	cout << "------Thong tin giao vien--------" << endl;
	cout << setw(20) << "Ho ten SV" << setw(15) << "Ngay sinh" << setw(20) << "Que quan" << endl;
	teacher.xuat();
	cout << endl;
	cout << "---------------------------------" << endl;
	cout << "DANH SACH HOC SINH" << endl;
	cout << setw(20) << "Ho ten SV" << setw(15) << "Ngay sinh" << setw(20) << "Que quan" << setw(10) << "Ma SV" << setw(20) << "Nganh" << setw(10) << "Khoa hoc" << endl;
	for (int i=0; i<n; i++)
	{
		x[i].xuat();
	}
}

void LopHoc::arrangeUpByCourse()
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (x[i].getCourse() > x[j].getCourse())
			{
				Student sTemp = x[i];
				x[i] = x[j];
				x[j] = sTemp;
			}
		}
	}
}

main()
{
	LopHoc lop;
	lop.nhap();
	lop.arrangeUpByCourse();
	lop.xuat();
}
