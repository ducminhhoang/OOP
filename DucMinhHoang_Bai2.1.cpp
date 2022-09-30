#include <iostream>
#include <iomanip>
using namespace std;

class CanBo{
	private:
		int id;
		char name[20];
		char date[13];
		int dayWork;
	public:
		void nhap(){
			cout << "Nhap ma can bo: ";              				   			cin>>id;
			cout << "Nhap ho ten: ";      					fflush(stdin);   	gets(name);
			cout << "Nhap ngay sinh: ";   					fflush(stdin);   	gets(date); 
			cout << "Nhap so ngay lam viec trong thang:";			   			cin>>dayWork;
		}
		
		long tinhLuong(){
			return dayWork*250000;
		}
		
		void xuat(){
			cout << setw(10) << "Ma CB" << setw(20) << "Ho ten" << setw(15) << "Ngay sinh" << setw(10) << "So ngay lam" << setw(20) << "Luong" << endl;
			cout << setw(10) << id << setw(20) << name << setw(15) << date << setw(10) << dayWork << setw(20) << tinhLuong() << endl; 
		}
};

int main(){
	CanBo cb1;
	cb1.nhap();
	cb1.xuat();
	
	return 0;
}
