#include <iostream>
using namespace std;
struct SoPhuc
{
	int iThuc;
	int iAo;
};
typedef struct SoPhuc SOPHUC;
void Nhap(SOPHUC&);
void Xuat(SOPHUC);

void Nhap(SOPHUC[][100], int&, int&);
void Xuat(SOPHUC[][100], int, int);

SOPHUC ThucAoDuongDau(SOPHUC[][100],int, int);
SOPHUC ThucAoAmCuoi(SOPHUC[][100], int, int);
int ktDong(SOPHUC[][100], int, int, int);
int DemDong(SOPHUC[][100], int, int);
SOPHUC ThucLonNhat(SOPHUC[][100], int, int);

int main()
{
	SOPHUC a[100][100];
	int m, n;
	Nhap(a, m, n);
	Xuat(a, m, n);
	
	cout << "\nSo phuc dau tien co thuc > 0 va ao > 0: ";
	cout << ThucAoDuongDau(a, m, n).iThuc << "+" << ThucAoDuongDau(a, m, n).iAo << "i";
	
	cout << "\nSo phuc cuoi cung co thuc < 0 va ao < 0: ";
	if (ThucAoAmCuoi(a, m, n).iThuc == 0 && ThucAoAmCuoi(a, m, n).iAo == 0)
		cout << "Khong ton tai";
	else
	cout << ThucAoAmCuoi(a, m, n).iThuc << "+" << ThucAoAmCuoi(a, m, n).iAo << "i";
	
	cout << "\nSo dong co thuc trai dau ao: " << DemDong(a, m, n);
	cout << "\nSo phuc co phan thuc lon nhat: ";
	cout << ThucLonNhat(a, m, n).iThuc << "+" << ThucLonNhat(a, m, n).iAo << "i";
}
//Bai 234
void Nhap(SOPHUC& x)
{
	cout << "Nhap phan thuc: ";
	cin >> x.iThuc;
	cout << "Nhap phan ao: ";
	cin >> x.iAo;
}
//Bai 235
void Xuat(SOPHUC x)
{
	if (x.iThuc == 0)
	{
		if (x.iAo == 0)
			cout << 0;
		else
			cout << x.iAo << "i";
	}
	else
	{
		if (x.iAo == 0)
			cout << x.iThuc;
		else
			cout << x.iThuc << "+" << x.iAo << "i";
	}
	
}
void Nhap(SOPHUC a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
		cout << "Nhap a[" << i << "][" << j << "]:\n";
		Nhap(a[i][j]);
		}
}
void Xuat(SOPHUC a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
		cout << "A[" << i << "][" << j << "]:";
		Xuat(a[i][j]);
		cout << endl;
		}
}

//Bai 236
SOPHUC ThucAoDuongDau(SOPHUC a[][100], int m,int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		if (a[i][j].iThuc > 0 && a[i][j].iAo > 0)
		return a[i][j];
	return { 0,0 };
}
//Bai 237
SOPHUC ThucAoAmCuoi(SOPHUC a[][100], int m,int n)
{
	for (int i = m - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
		if (a[i][j].iThuc < 0 && a[i][j].iAo < 0)
		return a[i][j];
	return { 0,0 };
}
//Bai 238
int ktDong(SOPHUC a[][100], int m, int n, int d)
{
	int flag = 1;
	for (int j = 0; j < n; j++)
		if (a[d][j].iThuc * a[d][j].iAo >= 0)
		flag = 0;
	return flag;
}
int DemDong(SOPHUC a[][100], int m, int n)
{
	int dem = 0;
	for (int i = 0; i < m; i++)
		if (ktDong(a, m, n, i))
		dem++;
	return dem;
}
//Bai 239
SOPHUC ThucLonNhat(SOPHUC a[][100], int m, int n)
{
	SOPHUC lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j].iThuc > lc.iThuc)
				lc = a[i][j];
	return lc;
}