/*
Thanh vien:
- 2351050041 - Mao Duc Hai
- 2351050044 - Huynh Thanh Hieu
- 2351050073 - Ta Hoang Khang

!!! LUU Y
Neu chay trong Visual Studio 2015 khong compile duoc thi thay giup em thuc hien 1 trong nhung cac cach sau:
1. Chuyen sang chay tren Visual Studio 2022
2. Compile truc tiep tren terminal (Dung phien ban g++ moi)
3. Chay trong phan mem DevC, Visual Studio Code (VSCode)
4. Chay trong bat ky phan mem nao ho tro run code trong terminal
*/
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Ngay
{
	int ngay, thang, nam;

	Ngay()
	{
		ngay = 1, thang = 1, nam = 2000;
	}
};

struct SinhVien
{
	int hang, day;
	string hoLot, ten, queQuan, MSSV, nganhHoc;
	Ngay ngaySinh;

	SinhVien()
	{
		hang = 1, day = 1,
		hoLot = "", ten = "", queQuan = "", MSSV = "", nganhHoc = "";
		ngaySinh.ngay = 1, ngaySinh.thang = 1, ngaySinh.nam = 2000;
	}

	// Ham de in thong tin 1 sinh vien
	void printInfo()
	{
		cout << "Hang: " << hang << "\n";
		cout << "Day: " << day << "\n";
		cout << "MSSV: " << MSSV << "\n";
		cout << "Ho lot: " << hoLot << "\n";
		cout << "Ten: " << ten << "\n";
		cout << "Ngay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << endl;
		cout << "Nganh hoc: " << nganhHoc << "\n";
		cout << "Que quan: " << queQuan << "\n";
	}
};

struct DSSV
{
	int n, row, col;
	SinhVien *ds;

	DSSV()
	{
		n = 0, row = 0, col = 0;
		ds = nullptr;
	}
};

void inputSV(DSSV &dssv)
{
	ifstream inData;
	inData.open("SoDoSinhVien.txt", ios::in);
	if (!inData.is_open())
	{
		cout << "Mo file that bai\n";
		return;
	}
	inData >> dssv.row;
	inData.ignore();
	inData >> dssv.col;
	inData.ignore();
	dssv.n = dssv.row * dssv.col;

	// Cap phat bo nho va nhap du lieu tu file
	dssv.ds = new SinhVien[dssv.n];
	for (int i = 0; i < dssv.n; i++)
	{
		inData >> dssv.ds[i].hang;
		inData.ignore();
		inData >> dssv.ds[i].day;
		inData.ignore();
		getline(inData, dssv.ds[i].MSSV, ',');
		getline(inData, dssv.ds[i].hoLot, ',');
		getline(inData, dssv.ds[i].ten, ',');
		inData >> dssv.ds[i].ngaySinh.ngay;
		inData.ignore();
		inData >> dssv.ds[i].ngaySinh.thang;
		inData.ignore();
		inData >> dssv.ds[i].ngaySinh.nam;
		inData.ignore();
		getline(inData, dssv.ds[i].nganhHoc, ',');
		getline(inData, dssv.ds[i].queQuan);
	}
	inData.close();
}

// Ham tra ve chuoi da in thuong
string toLower(const string a)
{
	string result = a;
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] >= 'A' && result[i] <= 'Z')
			result[i] += 32;
	}
	return result;
}

int main()
{
	DSSV dssv;
	inputSV(dssv);
	while (true)
	{
		int choice;
		cout << "1. In sinh vien ngoi day thu n\n";
		cout << "2. In sinh vien ngoi hang thu n\n";
		cout << "3. In sinh vien ngoi vi tri hang thu n, day thu m\n";
		cout << "4. In sinh vien co khuon dang ten\n";
		cout << "5. In sinh vien sinh vao thang m\n";
		cout << "6. In sinh vien hoc nganh k\n";
		cout << "7. In sinh vien que quan q\n";
		cout << "8. In sinh vien co khuon dang dau MSSV\n";
		cout << "9. In sinh vien co khuon dang cuoi MSSV\n";
		cout << "10. In thong tin cac sinh vien co the gian lan\n";
		cout << "0. Ket thuc chuong trinh\n";
		cout << "Nhap vao lua chon: ";
		cin >> choice;
		cin.ignore();

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

				cout << "\n===== THONG TIN CAC SINH VIEN THEO DAY " << n << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].day == n)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
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
					if (n <= 0 || n > 7)
						cout << "Hang nhap khong hop le, nhap lai\n";
				} while (n <= 0 || n > 7);

				cout << "\n===== THONG TIN CAC SINH VIEN THEO HANG " << n << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].hang == n)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 3:
			{
				int hang, day;
				do
				{
					cout << "Nhap vao so hang va so day can tim: ";
					cin >> hang >> day;
					if (hang <= 0 || hang > 10 || day <= 0 || day > 7)
						cout << "So hang va day khong hop le, nhap lai\n";
				} while (hang <= 0 || hang > 7 || day <= 0 || day > 10);

				cout << "\n===== THONG TIN CAC SINH VIEN THEO DAY " << day << " VA HANG " << hang << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].hang == hang && dssv.ds[i].day == day)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 4:
			{
				string name;
				cout << "Nhap khuon dang ten: ";
				getline(cin, name);
				cout << "===== THONG TIN CAC SINH VIEN CO KHUON DANG TEN " << name << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].ten.find(name) != string::npos || dssv.ds[i].hoLot.find(name) != string::npos)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 5:
			{
				int m;
				do
				{
					cout << "Nhap so thang can tim: ";
					cin >> m;
					cin.ignore();
				} while (m < 1 || m > 12);
				cout << "===== THONG TIN CAC SINH VIEN SINH VAO THANG " << m << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].ngaySinh.thang == m)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 6:
			{
				string k;
				cout << "Nhap ten nganh: ";
				getline(cin, k);
				cout << "===== THONG TIN CAC SINH VIEN HOC NGANH " << k << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (toLower(dssv.ds[i].nganhHoc) == toLower(k))
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 7:
			{
				string que;
				cout << "Nhap que quan: ";
				getline(cin, que);
				cout << "===== THONG TIN CAC SINH VIEN CO QUE QUAN O " << que << " =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					if (toLower(dssv.ds[i].queQuan) == toLower(que))
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
				}
				break;
			}

			case 8:
			{
				char t[21];
				cout << "Nhap khuon dang dau MSSV can tim: ";
				cin.getline(t, 21);

				int count = 0;
				cout << "===== CAC SINH VIEN CO KHUON DANG DAU MSSV =====\n";
				// Duyet mang ky tu nguoi dung nhap vao, dem so ky tu trung so voi do dai mang ky tu
				// Neu bang do dai mang thi in thong tin sinh vien
				for (int i = 0; i < dssv.n; i++)
				{
					for (int j = 0; j < strlen(t); j++)
					{
						if (t[j] == dssv.ds[i].MSSV[j])
							++count;
					}
					if (count == strlen(t))
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
					count = 0;
				}
				break;
			}

			case 9:
			{
				char t[21];
				cout << "Nhap khuon dang cuoi MSSV can tim: ";
				cin.getline(t, 21);

				int count = 0;
				cout << "===== CAC SINH VIEN CO KHUON DANG CUOI MSSV =====\n";
				for (int i = 0; i < dssv.n; i++)
				{
					int index = dssv.ds[i].MSSV.length() - 1;
					for (int j = strlen(t) - 1; j >= 0; j--)
					{
						if (t[j] == dssv.ds[i].MSSV[index--])
							++count;
					}
					if (count == strlen(t))
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
					count = 0;
				}
				break;
			}

			case 10:
			{
				int hang, day;
				do
				{
					cout << "Nhap so hang va so day cua sinh vien can kiem tra: ";
					cin >> hang >> day;
					if (hang <= 0 || day <= 0 || hang > 10 || day > 7)
						cout << "So hang va day khong hop le, nhap lai\n";
				} while (hang <= 0 || day <= 0 || hang > 7 || day > 10);
				hang -= 1;
				day -= 1;

				// Chuyen ds 1 chieu thanh 2 chieu
				SinhVien **dssv2Chieu = new SinhVien *[dssv.row];
				for (int i = 0; i < dssv.row; i++)
					dssv2Chieu[i] = new SinhVien[dssv.col];

				for (int i = 0; i < dssv.n; i++)
					dssv2Chieu[dssv.ds[i].hang - 1][dssv.ds[i].day - 1] = dssv.ds[i];

				SinhVien svCanKT = dssv2Chieu[hang][day];
				SinhVien dsSVGianLan[8];

				int size = 0;
				switch (svCanKT.hang)
				{
					case 1:
					{
						if (svCanKT.day == 1)
						{
							dsSVGianLan[size++] = dssv2Chieu[hang][day + 1];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day + 1];
						}

						else if (svCanKT.day == 10)
						{
							dsSVGianLan[size++] = dssv2Chieu[hang][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day];
						}

						else
						{
							dsSVGianLan[size++] = dssv2Chieu[hang][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang][day + 1];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day];
							dsSVGianLan[size++] = dssv2Chieu[hang + 1][day + 1];
						}
						break;
					}

					case 7:
					{
						if (svCanKT.day == 1)
						{
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day];
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day + 1];
							dsSVGianLan[size++] = dssv2Chieu[hang][day + 1];
						}

						else if (svCanKT.day == 10)
						{
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day];
							dsSVGianLan[size++] = dssv2Chieu[hang][day - 1];
						}

						else
						{
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day];
							dsSVGianLan[size++] = dssv2Chieu[hang - 1][day + 1];
							dsSVGianLan[size++] = dssv2Chieu[hang][day - 1];
							dsSVGianLan[size++] = dssv2Chieu[hang][day + 1];
						}
						break;
					}

					default:
					{
						dsSVGianLan[size++] = dssv2Chieu[hang - 1][day - 1];
						dsSVGianLan[size++] = dssv2Chieu[hang - 1][day];
						dsSVGianLan[size++] = dssv2Chieu[hang - 1][day + 1];
						dsSVGianLan[size++] = dssv2Chieu[hang][day - 1];
						dsSVGianLan[size++] = dssv2Chieu[hang][day + 1];
						dsSVGianLan[size++] = dssv2Chieu[hang + 1][day - 1];
						dsSVGianLan[size++] = dssv2Chieu[hang + 1][day];
						dsSVGianLan[size++] = dssv2Chieu[hang + 1][day + 1];
					}
				}

				cout << "\n===== CAC SINH VIEN CO VI TRI CO THE GIAN LAN ======\n";
				for (int i = 0; i < size; i++)
				{
					if (dsSVGianLan[i].queQuan == svCanKT.queQuan || dsSVGianLan[i].nganhHoc == svCanKT.nganhHoc)
					{
						dsSVGianLan[i].printInfo();
						cout << "==========================================\n";
					}
				}
				for (int i = 0; i < dssv.row; i++)
					delete[] dssv2Chieu[i];
				delete[] dssv2Chieu;
				dssv2Chieu = nullptr;
				break;
			}

			case 0:
				cout << "Ket thuc chuong trinh\n";
				delete[] dssv.ds;
				dssv.ds = nullptr;
				return 0;
			default:
				cout << "Lua chon khong hop le!\n";
		}

		char isContinue;
		cout << "Tiep tuc? (Nhap 0 de dung): ";
		cin >> isContinue;
		cin.ignore();
		if (isContinue == '0')
		{
			cout << "Ket thuc chuong trinh\n";
			delete[] dssv.ds;
			dssv.ds = nullptr;
			return 0;
		}
	}
}
