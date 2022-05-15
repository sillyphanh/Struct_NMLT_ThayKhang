#include <iostream>
using namespace std;
struct PhanSo
{
	int iTu;
	int iMau;
};
typedef struct PhanSo PHANSO;

void Nhap(PHANSO[][100], int&, int&);
void Nhap(PHANSO&);
void Xuat(PHANSO[][100], int, int);
void Xuat(PHANSO);
PHANSO LonNhat(PHANSO[][100], int, int);
PHANSO NhoNhat(PHANSO[][100], int, int);
int DemNhoNhat(PHANSO[][100], int, int);
PHANSO AmLonNhat(PHANSO[][100], int, int);
void HoanVi(PHANSO&, PHANSO&);
void SapTang(PHANSO[][100], int, int);
int ktToiGian(PHANSO);
void Xuat(PHANSO);
void HoanVi(PHANSO&, PHANSO&);
void SapTang(PHANSO[], int);
void Xuat(PHANSO[], int);
void LietKe(PHANSO[][100], int, int);

int main()
{
	PHANSO x[100][100];
	int m, n;
	Nhap(x, m, n);
	cout << "\Ma tran phan so vua nhap la: \n";
	Xuat(x, m, n);

	cout << "\nPhan so lon nhat la: ";
	cout<<LonNhat(x, m, n).iTu<<"/"<< LonNhat(x, m, n).iMau;
	
	cout << "\nSo phan so nho nhat la: " << DemNhoNhat(x, m, n);
	
	cout << "\nPhan so am lon nhat la: ";
	cout << AmLonNhat(x, m, n).iTu << "/" << AmLonNhat(x, m, n).iMau;
	
	cout << "\nMa tran tang dan: \n";
	SapTang(x, m, n);
	Xuat(x, m, n);

	cout << "\nCac phan so toi gian sap xep theo tang dan: \n";
	LietKe(x, m, n);

	return 0;
}
//Bai 227
void Nhap(PHANSO& x)
{
	cout << "Nhap tu so: ";
	cin >> x.iTu;
	cout << "Nhap mau so: ";
	cin >> x.iMau;
}
void Nhap(PHANSO a[][100], int& m, int& n)
{
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "\nNhap a[" << i << "][" << j << "]:\n";
			Nhap(a[i][j]);
		}
}

//Bai 228
void Xuat(PHANSO x)
{
	cout << x.iTu << "/" << x.iMau;
}
void Xuat(PHANSO a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "A[" << i << "][" << j << "]:";
			Xuat(a[i][j]);
			cout << endl;
		}
}

//Bai 229
int ucln(int x, int y)
{
	if (y == 0)
		return x;
	return ucln(y, x % y);
}
int SoSanh(PHANSO a, PHANSO b)
{
	if ((float)(a.iTu) / a.iMau > (float)(b.iTu) / b.iMau)
		return 1;
	return 0;
}
PHANSO LonNhat(PHANSO a[][100], int m, int n)
{
	PHANSO lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (SoSanh(a[i][j], lc) == 1)
			lc = a[i][j];
		return lc;
}

//Bai 230
PHANSO NhoNhat(PHANSO a[][100], int m, int n)
{
	PHANSO lc = a[0][0];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (SoSanh(a[i][j], lc) == 0)
				lc = a[i][j];
	return lc;
}
int DemNhoNhat(PHANSO a[][100], int m, int n)
{
	PHANSO lc = NhoNhat(a, m, n);
	int dem = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		if (SoSanh(a[i][j], lc) == 0)
		dem++;
	return dem;
}

//Bai 231
int ktAm(PHANSO x)
{
	if ((x.iMau < 0 && x.iTu > 0) || (x.iMau > 0 && x.iTu < 0))
		return 1;
	return 0;
}
PHANSO AmLonNhat(PHANSO a[][100], int m, int n)
{
	PHANSO lc = a[0][0];
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < n; j++)
			if (ktAm(a[i][j]))
			{
				
				float x = abs((float)a[i][j].iTu / a[i][j].iMau);
				float y = abs((float)lc.iTu / lc.iMau);
				if (x < y)
					lc = a[i][j];
			}
	}
	return lc;
}

//Bai 232
void HoanVi(PHANSO& x, PHANSO& y)
{
	PHANSO temp = x;
	x = y;
	y = temp;
}
void SapTang(PHANSO a[][100], int m, int n)
{
	for (int i = 0; i <= m * n - 2; i++)
		for (int j = i + 1; j <= m * n - 1; j++)
		if (SoSanh(a[i / n][i % n], a[j / n][j % n]) == 1)
		HoanVi(a[i / n][i % n], a[j / n][j % n]);
}

//Bai 233
int ktToiGian(PHANSO x)
{
	int c = ucln(x.iTu, x.iMau);
	if (c == 1)
		return 1;
	return 0;
}
void SapTang(PHANSO a[], int m)
{
	for (int i = 0; i < m-1; i++)
	{
		for (int j = i + 1; j < m; j++)
			if ((float)a[i].iTu/a[i].iMau > (float)a[j].iTu / a[j].iMau)
			{
				PHANSO temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
}
void Xuat(PHANSO a[], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << "A[" << i << "]:";
		cout << a[i].iTu << "/" << a[i].iMau << endl;
	}
		
}
void LietKe(PHANSO a[][100], int m, int n)
{
	PHANSO b[1000];
	int k = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		if (ktToiGian(a[i][j]))
		b[k++] = a[i][j];
	SapTang(b, k);
	Xuat(b, k);
}
