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

// Struct DSSV de de quan ly so hang, cot
struct DSSV
{
	int n;
	SinhVien *ds;

	void allocateMemory()
	{
		ds = new SinhVien[n];
	}

	void freeMemory()
	{
		delete[] ds;
	}
};

void inputSV(DSSV &dssv)
{
	ifstream inData;
	inData.open("SoDoSinhVien.txt", ios::in);
	int row, col;
	inData >> row;
	inData.ignore();
	inData >> col;
	inData.ignore();
	dssv.n = row * col;
	// Cap phat bo nho va nhap du lieu tu file
	dssv.allocateMemory();
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
		cout << "4. In thong tin sinh vien co khuon dang ten\n";
		cout << "10. In thong tin cac sinh vien co the gian lan\n";
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

				cout << "===== THONG TIN CAC SINH VIEN THEO DAY " << n << " =====\n";
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

				cout << "===== THONG TIN CAC SINH VIEN THEO HANG " << n << " =====\n";
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
				cout << "===== THONG TIN CAC SINH VIEN THEO DAY " << day << " VA HANG " << hang << " =====\n";

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
					// ! Can chinh sua
					if (dssv.ds[i].ten == name || dssv.ds[i].hoLot == name)
					{
						dssv.ds[i].printInfo();
						cout << "==========================================\n";
					}
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

				SinhVien svCanKT;
				for (int i = 0; i < dssv.n; i++)
				{
					if (dssv.ds[i].hang == hang && dssv.ds[i].day == day)
						svCanKT = dssv.ds[i];
				}

				SinhVien dsSVGianLan[8];
				int size = 0;
				switch (svCanKT.hang)
				{
					case 1:
					{
						if (svCanKT.day == 1)
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}

						else if (svCanKT.day == 10)
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}

						else
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}
						break;
					}

					case 7:
					{
						if (svCanKT.day == 1)
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}

						else if (svCanKT.day == 10)
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}

						else
						{
							for (int i = 0; i < dssv.n; i++)
							{
								if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day + 1)
									dsSVGianLan[size++] = dssv.ds[i];
								else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day - 1)
									dsSVGianLan[size++] = dssv.ds[i];
							}
						}
						break;
					}

					default:
					{
						for (int i = 0; i < dssv.n; i++)
						{
							if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day - 1)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang - 1 && dssv.ds[i].day == svCanKT.day + 1)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day - 1)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang && dssv.ds[i].day == svCanKT.day + 1)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day - 1)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day)
								dsSVGianLan[size++] = dssv.ds[i];
							else if (dssv.ds[i].hang == svCanKT.hang + 1 && dssv.ds[i].day == svCanKT.day + 1)
								dsSVGianLan[size++] = dssv.ds[i];
						}
					}
				}

				cout << "===== CAC SINH VIEN CO VI TRI CO THE GIAN LAN ======\n";
				for (int i = 0; i < size; i++)
				{
					dsSVGianLan[i].printInfo();
					cout << "==========================================\n";
				}
				break;
			}

			case 0:
				cout << "Ket thuc chuong trinh\n";
				dssv.freeMemory();
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
			dssv.freeMemory();
			return 0;
		}
	}
}
