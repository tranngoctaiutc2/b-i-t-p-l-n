#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include "support.h"
#include "bus.h"
#include "ticket.h"
#include "utils.h"

using namespace std;

// ADD BUS
void Bus::addBus()
{
   fstream busFileStream;

    system("cls");
        setColor(3,4);
		gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                  THEM XE                    ||"; // thêm xe bus
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,5);
//	fstream busFileStream;
	busFileStream.open("buses.txt", ios::out| ios::app);
	setColor(5,6);
	gotoxy(10,7);
    gotoxy(10,7);
        cout << "NHAP SO XE:-> ";
       cin.ignore();
       setColor(3,4);
       cin.getline(busNo, 10);
       setColor(5,6);
    gotoxy(10,8);
     gotoxy(10,8);
    cout << "DIEM KHOI HANH:-> ";
    setColor(3,4);
    cin.getline(source, 20);
     setColor(5,6);
    gotoxy(10,9);
    gotoxy(10,9);
    cout << "DIEM DEN:-> ";
    setColor(3,4);
    cin.getline(destination, 20);
    setColor(5,6);
    gotoxy(10,10);
    gotoxy(10,10);
    cout << "THOI GIAN DI:-> ";
    setColor(3,4);
    cin.getline(sourceTime, 20);
    setColor(5,6);
    gotoxy(10,11);
    gotoxy(10,11);
    cout << "THOI GIAN DEN:-> ";
    setColor(3,4);
    cin.getline(destinationTime, 20);
    setColor(5,6);
    gotoxy(10,12);
    gotoxy(10,12);
    cout << "GIA VE:-> ";
    setColor(5,6);
    cin >> busFare;
    busFileStream.write((char *)this, sizeof(*this));
    busFileStream.close();
    gotoxy(10,14);
    textcolor(6);
    cout << "THEM XE THANH CONG...!!! "<<endl;
    _getch();
    setColor(0,7);
}

// SHOW BUS DETAILS
void Bus::showBusDetails()
{
	system ("cls");
	gotoxy(10,5);
    gotoxy(10,6);
    setColor(5,6);
    cout << " SO XE:-> " << getBusNo();
    setColor(5,6);
    gotoxy(10,7);
    setColor(5,6);
    cout << " DIEM DI:-> " << getSource();
    setColor(5,6);
    gotoxy(10,8);
    setColor(5,6);
    cout << " DIEM DEN:-> " << getDestination();
    setColor(5,6);
    gotoxy(10,9);
    setColor(5,6);
    cout << " THOI GIAN DI:-> " << getSourceTime() << " - " << getDestinationTime();
    setColor(5,6);
    gotoxy(10,10);
    setColor(5,6);
    cout << " SO GHE:-> " << getMaxSeats();
    setColor(5,6);
    gotoxy(10,11);
    setColor(5,6);
    cout << " GHE NGOI:-> " << (getMaxSeats() - getBookedSeats());
    cout << fixed << setprecision(2);
    setColor(5,6);
    gotoxy(10,12);
    setColor(5,6);
    cout << " GIA TIEN:-> " << getBusFare();
    gotoxy(10,13);
    _getch();
    setColor(0,7);
    
}

// VIEW ALL BUS INFO
void Bus::showAllBus()
{
    system("cls");

    fstream busFileStream;
    Bus a;
//	list l;
//	node* p=new node;
    busFileStream.open("buses.txt", ios::in| ios::app);
    if (!busFileStream){
	
    gotoxy(10,20);
    textcolor(4);
        cout << "File Not Found...!!!\n";
        _getch();
        setColor(0,7);
    }else
    {
    	setColor(3,4);
      gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||              DANH SACH XE                   ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         

        busFileStream.read((char *)this, sizeof(*this));

        while (!busFileStream.eof())
        {
        	
            
            busFileStream.read((char *)this, sizeof(*this));
            showBusDetails();
        }
        busFileStream.close();
    }
}


// VIEW BUS INFO
void Bus::viewBusDetails()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream busFileStream;
    setColor(3,4);
    gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                  THONG TIN                  ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         setColor(5,6);
         gotoxy(10,5);
         gotoxy(10,5);
    cout << "NHAP SO XE:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(bNo, 10);
    setColor(0,7);

    system("cls");
    gotoxy(10,1);
    setColor(3,4);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 THONG TIN                   ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,5);
         setColor(0,7);

    busFileStream.open("buses.txt", ios::in);
    if (busFileStream.fail())
    {
    	gotoxy(10,20);
    	textcolor(4);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getBusNo(), bNo) == 0)
            {
                showBusDetails();
                chk = 1;
            }
            busFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,10);
        	textcolor(4);
			cout << "KHONG TIM THAY...!!\n";
			_getch();
			setColor(0,7);
        }
        busFileStream.close();
    }
}

// EDIT BUS
void Bus::editBus()
{
    system("cls");

    char bNo[10];
    int chk = 0;

    fstream busFileStream, tempFileStream;
    setColor(3,4);

    gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||             XE DA DUOC CHINH                ||";
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         setColor(5,6);
         gotoxy(10,5);
          gotoxy(10,5);
    cout << "NHAP SO XE:-> ";
    cin.ignore();
     setColor(3,4);
    cin.getline(bNo, 10);
    setColor(0,7);

    busFileStream.open("buses.txt", ios::in);

    if (busFileStream.fail())
    {
    	gotoxy(10,20);
    	textcolor(4);
		cout << "Can't Open File...!!\n";
		_getch();
		setColor(0,7);
    }

    else
    {
        tempFileStream.open("temp.txt", ios::out );

        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getBusNo(), bNo) == 0)
            {
                system("cls");
                setColor(3,4);
        gotoxy(10,1);
        cout<< "-------------------------------------------------";
        gotoxy(10,2);
        cout<< "||                 CHINH SUA                   ||";
        gotoxy(10,3);
        cout<< "||                                             ||";
        gotoxy(10,4);
        cout<< "-------------------------------------------------" ;
        gotoxy(10,5);

                showBusDetails();
                char s[20], d[20], sTime[20], dTime[20];
                double fare;
                setColor(5,6);
                gotoxy(10,7);
                gotoxy(10,7);
                cout << "NHAP DIEM DI:-> ";
                setColor(3,4);
                cin.getline(s, 20);
                setColor(5,6);
                gotoxy(10,8);
                gotoxy(10,8);
                cout << "NHAP DIEM DEN:-> ";
                setColor(3,4);
                cin.getline(d, 20);
                setColor(5,6);
                gotoxy(10,9);
                gotoxy(10,9);
                cout << "THOI GIAN KHOI HANH:-> ";
                setColor(3,4);
                cin.getline(sTime, 20);
                setColor(5,6);
                gotoxy(10,10);
                gotoxy(10,10);
                cout << "THOI GIAN DEN:-> ";
                setColor(3,4);
                cin.getline(dTime, 20);
                setColor(5,6);
                gotoxy(10,11);
                gotoxy(10,11);
                cout << "NHAP VE XE:-> ";
                cin.ignore();
                setColor(3,4);
                cin >> fare;
                setColor(0,7);
                setSource(s);
                setDestination(d);
                setSourceTime(sTime);
                setDestinationTime(dTime);
                setBusFare(fare);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            busFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
        	gotoxy(10,20);
        	textcolor(4);
            cout << "CAP NHAP TUYEN XE THANH CONG...!!\n";
            _getch();
            setColor(0,7);
        }
        else
        {
        	gotoxy(10,20);
        	textcolor(4);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }

        busFileStream.close();
        tempFileStream.close();
        remove("buses.txt");
        rename("temp.txt", "buses.txt");
    }
}

// DELETE BUS
void Bus::deleteBus()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream busFileStream, tempFileStream;
    setColor(3,4);
    gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||             TUYEN XE BI HUY                 ||";
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         setColor(5,6);
         gotoxy(10,5);
         gotoxy(10,5);
    cout << "NHAP SO XE:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(bNo, 10);
    setColor(0,7);

    busFileStream.open("buses.txt", ios::in | ios::app);

    if (busFileStream.fail())
    {
    	gotoxy(10,20);
    	textcolor(4);
        cout << "Can't Open File...!!";
        _getch();
        setColor(0,7);
    }

    else
    {
        tempFileStream.open("temp.txt", ios::out | ios::app);
        busFileStream.read((char *)this, sizeof(*this));
        while (!busFileStream.eof())
        {
            if (strcmp(getBusNo(), bNo) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                chk = 1;
            }
            busFileStream.read((char *)this, sizeof(*this));
        }

        if (chk == 0)
        {
        	gotoxy(10,20);
        	textcolor(4);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }
        else
        {
        	gotoxy(10,20);
        	textcolor(4);
            cout << "TUYEN XE DA BI HUY...!!\n";
            _getch();
            setColor(0,7);
        }

        busFileStream.close();
        tempFileStream.close();
        remove("buses.txt");
        rename("temp.txt", "buses.txt");
    }
}
