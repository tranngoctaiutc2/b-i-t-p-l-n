#include <iostream>
#include <string.h>
#include<windows.h>
#include "support.h"
#include "bus.cpp"
#include "ticket.cpp"
#include "utils.h"
#include "node.cpp"
using namespace std;

// GLOBAL FUNCTION
void mainMenu();
void userMenu();
void adminMenu();
void adminLogin();
void viewBookingsMenu();
void welcomeScreen();
//void fullscreen();
//MAIN FUNCTION
int main()
{
	SetWindowSize(80,30);
	SetConsoleOutputCP(65001);
    system("cls");
//	fullscreen();
	setColor(0,4);
    welcomeScreen();
	return 0;
}


//  WELCOME SCREEN FUNCTION
void welcomeScreen()
{
	system("cls");
	gotoxy(10,5);
    cout << "------------------------------------------------";
    gotoxy(10,6);
    cout << "||                                            ||";
    gotoxy(10,7);
    cout << "                   CHUONG TRINH                 ";
    gotoxy(10,8);
    cout << "||                                            ||";
    gotoxy(10,9);
    cout << "                  QUAN LI NHA XE 	             ";
    gotoxy(10,10);
    cout << "||                                            ||";
    gotoxy(10,11);
    cout << "                      NHOM 20                   ";
    gotoxy(10,12);
    cout << "------------------------------------------------";
    gotoxy(10,13);
    _getch();
    mainMenu();
}

// MAIN MENU
void mainMenu()
{
    int choice;

    while (1)
    {
        system("cls");
        

        // MENU ITEMS
        setColor(3,7);
        gotoxy(10,1);
        cout<< "-------------------------------------------------";
        gotoxy(10,2);
        cout<< "||                  GIAO DIEN                  ||";
        gotoxy(10,3);
        cout<< "||                                             ||";
        gotoxy(10,4);
        cout<< "-------------------------------------------------" ;
        setColor(5,6);
        gotoxy(10,5);
        gotoxy(10,7);
        cout << "-------------------------------------------------";
        gotoxy(10,8);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,8);
        cout << " 1. NGUOI DUNG";
        setColor(5,6);
        gotoxy(10,9);
        cout << "-------------------------------------------------";
        gotoxy(10,10);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,10);
        cout << " 2. QUAN LI";
		setColor(5,6);                                 
        gotoxy(10,11);
        cout << "-------------------------------------------------";
        gotoxy(10,12);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,12);
        cout << " 3. THOAT";
		setColor(5,6);                                       
        gotoxy(10,13);
        cout << "-------------------------------------------------";
        gotoxy(10,14);
        setColor(5,6);
        cout << "NHAP LUA CHON:-> ";
        cin >> choice;
        _getch();
        setColor(0,7);

        switch (choice)
        {
        case 1:
            userMenu();
            break;

        case 2:
            adminLogin();
            break;

        case 3:
            system("cls");
            gotoxy(10,10);
            cout << "Chuong trinh dong...!!! "<<endl;
            cout << " Cam on da su dung...!!!      ";
            exit(0);

        default:
        	gotoxy(10,10);
            cout << " Lua chon loi!!! ";
            system("pause");
            mainMenu();
        }
    }
}

// ADMIN LOGIN
void adminLogin()
{
    string adminUname, adminPass;
    system("cls");
	gotoxy(10,1);
	setColor(3,4);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 QUAN LI                     ||";
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         setColor(5,6);
     gotoxy(10,7);
    cout << "NHAP AdminID:-> ";
    cin >> adminUname;
    gotoxy(10,8);
    cout << "NHAP Password:-> ";
    cin >> adminPass;
    setColor(0,7);

    if (adminUname == "admin" && adminPass == "pass")
    {
        adminMenu();
    }
    else
    {
    	 gotoxy(10,10);
        cout << "AdminID hoac password bi sai...!!! ";
        system("pause");
        adminLogin();
    }
}

// USER MENU
void userMenu()
{

    int choice;

    while (1)
    {
        system("cls");

        Ticket t;

        // MENU ITEMS
         gotoxy(10,1);
         setColor(3,4);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 NGUOI DUNG                  ||";
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         setColor(5,6);
        gotoxy(10,5);
        gotoxy(10,7);
        cout << "-------------------------------------------------";
        gotoxy(10,8);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,8);
        cout << " 1. DAT VE";
        setColor(5,6);
        gotoxy(10,9);
        cout << "-------------------------------------------------";
        gotoxy(10,10);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,10);
        cout << " 2. XEM VE DA DAT";
		setColor(5,6);                                 
        gotoxy(10,11);
        cout << "-------------------------------------------------";
        gotoxy(10,12);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,12);
        cout << " 3. HUY VE";
        setColor(5,6);
        gotoxy(10,13);
        cout << "-------------------------------------------------";
		gotoxy(10,14);
        cout<< "                                                 ";
        SetBGColor(0);
        gotoxy(10,14);
        cout << " 4. TRO LAI";
		setColor(5,6);                                       
        gotoxy(10,15);
        cout << "-------------------------------------------------";
        gotoxy(10,16);
        setColor(0,7);
        cout << "Enter your choice:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        	setColor(0,7);
            t.bookTicket();
            system("pause");
            break;

        case 2:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 3:
            t.cancelTicket();
            system("pause");
            break;

        case 4:
            system("cls");
            setColor(0,7);
            mainMenu();
            break;

        default:
        	 gotoxy(10,10);
            cout << "  Choose valid option!!! ";
            system("pause");
            break;
            userMenu();
        }
    }
}

// ADMIN MENU FUNCTION
void adminMenu()
{
    Bus b;
    Ticket t;
	ListBus* l;
	l=new ListBus();
    int choice;

    while (1)
    {
        system("cls");
		setColor(0,6);
        gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||            GIAO DIEN QUAN LI                ||";
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,5);

        cout << "-------------------------------------------------";
        gotoxy(10,7);
        cout << " 1. THEM XE                                      ";
         gotoxy(10,8);
        cout << "-------------------------------------------------";
         gotoxy(10,9);
        cout << " 2. DANH SACH XE                                 ";
         gotoxy(10,10);
        cout << "-------------------------------------------------";
         gotoxy(10,11);
        cout << " 3. XEM THONG TIN TUYEN XE                       ";
         gotoxy(10,12);
        cout << "-------------------------------------------------";
         gotoxy(10,13);
        cout << " 4. DIEU CHINH THONG TIN TUYEN XE                ";
         gotoxy(10,14);
        cout << "-------------------------------------------------";
         gotoxy(10,15);
        cout << " 5. HUY TUYEN XE                                 ";
         gotoxy(10,16);
        cout << "-------------------------------------------------";
         gotoxy(10,17);
        cout << " 6. DAT VE XE                                    ";
         gotoxy(10,18);
        cout << "-------------------------------------------------";
         gotoxy(10,19);
        cout << " 7. DIEU CHINH VE                                ";
         gotoxy(10,20);
        cout << "-------------------------------------------------";
         gotoxy(10,21);
        cout << " 8. XOA VE                                       ";
         gotoxy(10,22);
        cout << "-------------------------------------------------";
         gotoxy(10,23);
        cout << " 9. DANH SACH VE DA DAT                          ";
         gotoxy(10,24);
        cout << "-------------------------------------------------";
         gotoxy(10,25);
        cout << " 10. TRO LAI                                        ";
         gotoxy(10,26);
        cout << "-------------------------------------------------";
         gotoxy(10,27);

        cout << "NHAP LUA CHON:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            l->addBus();
            system("pause");
            break;

        case 2:
        	l->ReadFileBus();
            l->showAllBus();
            l->Create();
            system("pause");
            break;

        case 3:
            b.viewBusDetails();
            system("pause");
            break;


        case 4:
            b.editBus();
            system("pause");
            break;


        case 5:
            b.deleteBus();
            system("pause");
            break;


        case 6:
            t.bookTicket();
            system("pause");
            break;

        case 7:
            t.editTicket();
            system("pause");
            break;

        case 8:
            t.cancelTicket();
            system("pause");
            break;

        case 9:
            viewBookingsMenu();
            break;


        case 10:
            system("cls");
            mainMenu();
            
            break;
        default:
        	 gotoxy(10,10);
            cout << "  KHONG HO TRO LUA CHON!!! ";
            system("pause");
            adminMenu();
        }
    }
}

// VIEW BOOKINGS MENU FUNCTION
void viewBookingsMenu()
{
    Ticket t;

    int choice;

    while (1)
    {
        system("cls");
		setColor(0,6);
        gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 DANH SACH VE                ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,5);


        cout << "-------------------------------------------------";
        gotoxy(10,7);
        cout << " 1. MA VE PNR                                    ";
        gotoxy(10,8);
        cout << "-------------------------------------------------";
        gotoxy(10,9);
        cout << " 2. TEN HANH KHACH                               ";
        gotoxy(10,10);
        cout << "-------------------------------------------------";
        gotoxy(10,11);
        cout << " 3. SO XE                                        ";
        gotoxy(10,12);
        cout << "-------------------------------------------------";
        gotoxy(10,13);
        cout << " 4. KHOI HANH                                    ";
        gotoxy(10,14);
        cout << "-------------------------------------------------";
        gotoxy(10,15);
        cout << " 5. DIEM DEN                                     ";
        gotoxy(10,16);
        cout << "-------------------------------------------------";
        gotoxy(10,17);
        cout << " 6. TAT CA VE                                    ";
        gotoxy(10,18);
        cout << "-------------------------------------------------";
        gotoxy(10,19);
        cout << " 7. TRO LAI                                      ";
        gotoxy(10,20);
        cout << "-------------------------------------------------";
        gotoxy(10,21);

        cout << "NHAP LUA CHON:-> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            t.showTicketsByPNR();
            system("pause");
            break;

        case 2:
            t.showTicketsByName();
            system("pause");
            break;

        case 3:
            t.showTicketsByBus();
            system("pause");
            break;

        case 4:
            t.showTicketsBySource();
            system("pause");
            break;

        case 5:
            t.showTicketsByDestination();
            system("pause");
            break;

        case 6:
            t.showAllTickets();
            system("pause");
            break;

        case 7:
            system("cls");
            setColor(0,7);
            adminMenu();
            break;

        default:
        	gotoxy(10,10);
            cout << "  DANG CAT NHAT THEM!!!";
            system("pause");
            viewBookingsMenu();
        }
    }
}
