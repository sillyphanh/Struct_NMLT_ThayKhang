#include <iostream>
using namespace std;
struct DonThuc
{
	float fHeSo;
	int iSoMu;
};
typedef struct DonThuc DONTHUC;
void Nhap(DONTHUC&);
void Xuat(DONTHUC);
int main()
{
	DONTHUC x;
	Nhap(x);
	cout << "\nDon thuc vua nhap la: ";
	Xuat(x);
	return 0;
}
void Nhap(DONTHUC& x)
{
	cout << "Nhap he so: ";
	cin >> x.fHeSo;
	cout << "Nhap so mu: ";
	cin >> x.iSoMu;
}
void Xuat(DONTHUC x)
{
	cout << "\nHe so: " << x.fHeSo;
	cout << "\nSo mu: " << x.iSoMu;
}