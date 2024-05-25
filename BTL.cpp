#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;
};

struct SinhVien
{
	int hang, day;
	string hoLot, ten, queQuan, MSSV, nganhHoc;
	Ngay ngaySinh;
};

// Struct DSSV de de quan ly so hang, cot
struct DSSV
{
	int row = 0, col = 0;
	SinhVien **ds;

	void allocateMem()
	{
		ds = new SinhVien *[this->row];
		for (int i = 0; i < this->row; i++)
			ds[i] = new SinhVien[col];
	}

	void freeMem()
	{
		for (int i = 0; i < row; i++)
			delete[] ds[i];
		delete[] ds;
	}
};

void inputSV(DSSV &dssv)
{
	ifstream inData;
	inData.open("SoDoSinhVien.txt", ios::in);
	inData >> dssv.row;
	inData.ignore();
	inData >> dssv.col;
	inData.ignore();

	dssv.allocateMem();
	for (int i = 0; i < dssv.row; i++)
	{
		for (int j = 0; j < dssv.col; j++)
		{
			inData >> dssv.ds[i][j].hang;
			inData.ignore();
			inData >> dssv.ds[i][j].day;
			inData.ignore();
			getline(inData, dssv.ds[i][j].MSSV, ',');
			getline(inData, dssv.ds[i][j].hoLot, ',');
			getline(inData, dssv.ds[i][j].ten, ',');
			inData >> dssv.ds[i][j].ngaySinh.ngay;
			inData.ignore();
			inData >> dssv.ds[i][j].ngaySinh.thang;
			inData.ignore();
			inData >> dssv.ds[i][j].ngaySinh.nam;
			inData.ignore();
			getline(inData, dssv.ds[i][j].nganhHoc, ',');
			getline(inData, dssv.ds[i][j].queQuan);
		}
	}
	inData.close();
}

int main()
{
	DSSV dssv;
	inputSV(dssv);
	while (true)
	{
		int choice;
		cout << "1. In thong tin sinh vien ngoi day thu n\n";
		cout << "2. In thong tin sinh vien ngoi hang thu n\n";
		cout << "3. In thong tin sinh vien ngoi vi tri hang thu n, day thu m\n";
		cout << "Nhap vao lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int n;
			do
			{
				cout << "Nhap vao day thu: ";
				cin >> n;
				if (n <= 0 || n > 10)
					cout << "Day nhap khong hop le, nhap lai\n";
			} while (n <= 0 || n > 10);

			cout << "===== THONG TIN CAC SINH VIEN THEO DAY " << n << " =====\n";
			for (int i = 0; i < dssv.row; i++)
			{
				for (int j = 0; j < dssv.col; j++)
				{
					if (dssv.ds[i][j].day == n)
					{
						cout << "Hang: " << dssv.ds[i][j].hang << "\n";
						cout << "Day: " << dssv.ds[i][j].day << "\n";
						cout << "MSSV: " << dssv.ds[i][j].MSSV << "\n";
						cout << "Ho lot: " << dssv.ds[i][j].hoLot << "\n";
						cout << "Ten: " << dssv.ds[i][j].ten << "\n";
						cout << "Ngay sinh: " << dssv.ds[i][j].ngaySinh.ngay << "/" << dssv.ds[i][j].ngaySinh.thang << "/" << dssv.ds[i][j].ngaySinh.nam << endl;
						cout << "Nganh hoc: " << dssv.ds[i][j].nganhHoc << "\n";
						cout << "Que quan: " << dssv.ds[i][j].queQuan << "\n";
						cout << "==========================================\n";
					}
				}
			}
			break;
		}

		case 2:
		{
			int n;
			do
			{
				cout << "Nhap vao hang thu: ";
				cin >> n;
				if (n <= 0 || n > 10)
					cout << "Hang nhap khong hop le, nhap lai\n";
			} while (n <= 0 || n > 10);

			cout << "===== THONG TIN CAC SINH VIEN THEO HANG " << n << " =====\n";
			for (int i = 0; i < dssv.row; i++)
			{
				for (int j = 0; j < dssv.col; j++)
				{
					if (dssv.ds[i][j].hang == n)
					{
						cout << "Hang: " << dssv.ds[i][j].hang << "\n";
						cout << "Day: " << dssv.ds[i][j].day << "\n";
						cout << "MSSV: " << dssv.ds[i][j].MSSV << "\n";
						cout << "Ho lot: " << dssv.ds[i][j].hoLot << "\n";
						cout << "Ten: " << dssv.ds[i][j].ten << "\n";
						cout << "Ngay sinh: " << dssv.ds[i][j].ngaySinh.ngay << "/" << dssv.ds[i][j].ngaySinh.thang << "/" << dssv.ds[i][j].ngaySinh.nam << endl;
						cout << "Nganh hoc: " << dssv.ds[i][j].nganhHoc << "\n";
						cout << "Que quan: " << dssv.ds[i][j].queQuan << "\n";
						cout << "==========================================\n";
					}
				}
			}
			break;
		}

		case 3:
		{
			int hang, day;
			cout << "Nhap vao so hang va so day can tim: ";
			cin >> hang >> day;
			cout << "===== THONG TIN CAC SINH VIEN THEO DAY " << day << " VA HANG " << hang << " =====\n";

			for (int i = 0; i < dssv.row; i++)
			{
				for (int j = 0; j < dssv.col; j++)
				{
					if (dssv.ds[i][j].hang == hang && dssv.ds[i][j].day == day)
					{
						cout << "Hang: " << dssv.ds[i][j].hang << "\n";
						cout << "Day: " << dssv.ds[i][j].day << "\n";
						cout << "MSSV: " << dssv.ds[i][j].MSSV << "\n";
						cout << "Ho lot: " << dssv.ds[i][j].hoLot << "\n";
						cout << "Ten: " << dssv.ds[i][j].ten << "\n";
						cout << "Ngay sinh: " << dssv.ds[i][j].ngaySinh.ngay << "/" << dssv.ds[i][j].ngaySinh.thang << "/" << dssv.ds[i][j].ngaySinh.nam << endl;
						cout << "Nganh hoc: " << dssv.ds[i][j].nganhHoc << "\n";
						cout << "Que quan: " << dssv.ds[i][j].queQuan << "\n";
						cout << "==========================================\n";
					}
				}
			}
			break;
		}

		case 0:
			cout << "Ket thuc chuong trinh\n";
			dssv.freeMem();
			return 0;
		default:
			cout << "Lua chon khong hop le!\n";
		}
		char isContinue;
		cout << "Tiep tuc? (Nhap 0 de dung): ";
		cin >> isContinue;
		if (isContinue == '0')
		{
			cout << "Ket thuc chuong trinh\n";
			dssv.freeMem();
			return 0;
		}
	}
}
