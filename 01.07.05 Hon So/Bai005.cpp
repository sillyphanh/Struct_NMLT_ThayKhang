#include <iostream>
using namespace std;
struct HonSo
{
	int iNguyen;
	int iTu;
	int iMau;
};
typedef struct HonSo HONSO;
void Nhap(HONSO&);
void Xuat(HONSO);
int main()
{
	HONSO m;
	Nhap(m);
	cout << "\nHon so vua nhap la: ";
	Xuat(m);
	return 0;
}
void Nhap(HONSO& m)
{
	cout << "Nhap phan nguyen: ";
	cin >> m.iNguyen;
	cout << "Nhap phan tu: ";
	cin >> m.iTu;
	cout << "Nhap phan mau: ";
	cin >> m.iMau;
}
void Xuat(HONSO m)
{
	cout << "\nNguyen: " << m.iNguyen;
	cout << "\nTu: " << m.iTu;
	cout << "\nMau: " << m.iMau;
}