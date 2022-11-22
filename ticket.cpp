#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "support.h"
#include "ticket.h"
#include "bus.h"
#include "utils.h"

using namespace std;

// GENERATE TICKET
void Ticket::generateTicket(char *n, Bus b)
{
    strcpy(name, n);
    strcpy(pnrNo, generatePNR(99999).c_str());
    strcpy(date, getCurrentDate().c_str());
    bus = b;
}

// DISPLAY TICKET DETAILS
void Ticket::displayTicket()
{
	setColor(5,6);
    gotoxy(10,6);
	setColor(3,4);    
    cout << " TEN HANH KHACH:-> " << getName();
    setColor(5,6);
    gotoxy(10,7); 
	setColor(3,4);   
    cout << " MA VE PNR :-> " << getPnrNo();
    setColor(5,6);
    gotoxy(10,8);
	setColor(3,4);    
    cout << " SO XE:-> " << bus.getBusNo();
    setColor(5,6);
    gotoxy(10,9);  
	setColor(3,4); 
    cout << " CHO NGOI:-> " << bus.getBookedSeats();
    setColor(5,6);
    gotoxy(10,10);
    setColor(3,4);
    cout << " NGAY DAT VE:-> " << getDate();
    setColor(5,6);
    gotoxy(10,11);
    setColor(3,4);
    cout << " DIEM DI:-> " << bus.getSource();
    setColor(5,6);
    gotoxy(10,12);
    setColor(3,4);
    cout << " DIEM DEN:-> " << bus.getDestination();
    setColor(5,6);
    gotoxy(10,13);
    setColor(3,4);
    cout << " THOI GIAN XUAT PHAT:-> " << bus.getSourceTime();
    setColor(5,6);
    gotoxy(10,14);
    setColor(3,4);
    cout << " THOI GIAN DU KIEN DEN:-> " << bus.getDestinationTime();
    setColor(5,6);
    cout << fixed << setprecision(2);
    gotoxy(10,15);
    setColor(3,4);
    cout << " GIA VE:-> " << bus.getBusFare();
    setColor(5,6);
    gotoxy(10,16);
    cout << "-------------------------------------------------";
    cout <<endl;
    _getch();
    setColor(0,7);
    
}

// BOOK TICKET
void Ticket::bookTicket()
{
    system("cls");

    char from[20], to[20];
    int chk = 0;

    Bus b;
    fstream busFileStream, ticketFileStream, tempFileStream;
	setColor(3,4);
    gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 VE XE                       ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,6);
         setColor(0,7);

    busFileStream.open("buses.txt", ios::in | ios::app);
    if (busFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
         setColor(0,7);
    }

    else
    {
    	setColor(0,6);
    	gotoxy(10,5);
    	gotoxy(10,5);
        cout << "DIEM DI:-> ";
        cin.ignore();
        cin.getline(from, 20);
        gotoxy(10,6);
        gotoxy(10,6);
        cout << "DIEM DEN:-> ";
        cin.getline(to, 20);
        setColor(0,7);
    

        system("cls");
        setColor(3,4);
        gotoxy(10,1);
         cout<< "-------------------------------------------------";
         gotoxy(10,2);
         cout<< "||                 DANH SACH XE                ||"; 
         gotoxy(10,3);
         cout<< "||                                             ||";
         gotoxy(10,4);
         cout<< "-------------------------------------------------" ;
         gotoxy(10,6);
		 setColor(0,6);
        busFileStream.read((char *)&b, sizeof(b));
        while (!busFileStream.eof())
        {
            if (strcmpi(b.getSource(), from) == 0 && strcmpi(b.getDestination(), to) == 0)
            {
                b.showBusDetails();
                chk = 1;
            }
            busFileStream.read((char *)&b, sizeof(b));
        }

        busFileStream.close();

        if (chk == 0)
        {
        	gotoxy(10,10);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
             setColor(0,7);
        }
        else
        {
            char bNo[10];
            int booked = 0;
            setColor(5,6);
            gotoxy(10,15);
            gotoxy(10,15);
			cout << "NHAP SO XE:-> ";
            cin.getline(bNo, 10);
            setColor(0,7);

            busFileStream.open("buses.txt", ios::in | ios::app);
            tempFileStream.open("temp.txt", ios::out | ios::app);

            busFileStream.read((char *)&b, sizeof(b));
            while (!busFileStream.eof())
            {
                if (strcmpi(b.getSource(), from) == 0 && strcmpi(b.getDestination(), to) == 0 && strcmp(b.getBusNo(), bNo) == 0)
                {
                    if (b.getBookedSeats() >= 32)
                    {
                    	gotoxy(10,20);
                        cout << "khong co cho ngoi...!!\n";
                        break;
                    }
                    else
                    {
                        system("cls");
                        setColor(3,4);
                        gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                   VE XE                     ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
						setColor(0,6);
                        char n[20];
                        
                        gotoxy(10,6);
                        gotoxy(10,6);
                        cout << "NHAP TEN KHACH HANG :-> ";
                        cin.getline(n, 20);
                        b.setBookedSeats();
                        generateTicket(n, b);
                        ticketFileStream.open("tickets.txt", ios::out | ios::app);
                        ticketFileStream.write((char *)this, sizeof(*this));
                        ticketFileStream.close();
                        tempFileStream.write((char *)&b, sizeof(b));

                        booked = 1;
                        system("cls");
                        setColor(3,4);
                          gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                  VE DUOC DAT                ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
						setColor(0,6);
                        displayTicket();
                        gotoxy(10,20);
                        cout << "VE DUOC DAT THANH CONG...!!\n";
                        _getch();
                        setColor(0,7);
                    }
                }
                else
                {
                    tempFileStream.write((char *)&b, sizeof(b));
                }
                busFileStream.read((char *)&b, sizeof(b));
            }

            if (booked == 1)
            {
                busFileStream.close();
                tempFileStream.close();
                remove("buses.txt");
                rename("temp.txt", "buses.txt");
            }
        }
        busFileStream.close();
    }
}

// CANCEL TICKET
void Ticket::cancelTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream busFileStream, ticketFileStream, tempFileStream, busTempFileStream;
    
					setColor(3,4);
                   gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                  VE XE                      ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);
    cout << "NHAP MA VE PNR:->";
    cin.ignore();
    setColor(3,4);
    cin.getline(pnr, 10);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    tempFileStream.open("temp.txt", ios::out | ios::app);

    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) != 0)
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                Bus b;
                busFileStream.open("buses.txt", ios::in | ios::app);
                busTempFileStream.open("bustemp.txt", ios::out | ios::app);

                busFileStream.read((char *)&b, sizeof(b));
                while (!busFileStream.eof())
                {
                    if (strcmp(b.getBusNo(), bus.getBusNo()) == 0)
                    {
                        b.setCancelTicket();
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    busFileStream.read((char *)&b, sizeof(b));
                }
                busFileStream.close();
                busTempFileStream.close();
                remove("buses.txt");
                rename("bustemp.txt", "buses.txt");
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            ticketFileStream.close();
            tempFileStream.close();
            gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }
        else
        {
            ticketFileStream.close();
            tempFileStream.close();
            remove("tickets.txt");
            rename("temp.txt", "tickets.txt");
            gotoxy(10,20);
            cout << "Ticket Cancelled...!!\n";
            _getch();
            setColor(0,7);
        }
    }
}

// EDIT TICKET
void Ticket::editTicket()
{
    system("cls");

    char pnr[10];
    int chk = 0;

    fstream ticketFileStream, tempFileStream;
	setColor(3,4);
   gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                CHINH SUA VE                 ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);
    cout << "MA VE PNR:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(pnr, 10);
    setColor(0,7);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);

    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
    }

    else
    {
        tempFileStream.open("temp.txt", ios::out | ios::app);

        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
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

                displayTicket();
                char n[20];
                setColor(5,6);
                gotoxy(10,6);
                gotoxy(10,6);
                cout << "NHAP TEN HANH KHACH :-> ";
                setColor(3,4);
                cin.getline(n, 20);
                setName(n);
                tempFileStream.write((char *)this, sizeof(*this));

                chk = 1;
            }
            else
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }

        if (chk = 1)
        {
        	gotoxy(10,20);
            cout << "CAP NHAT THONG TIN...!!\n";
            _getch();
            setColor(0,7);
        }
        else
        {
        	gotoxy(10,20);
		
            cout << "VE XE KHONG TIM DUOC...!!\n";
            _getch();
            setColor(0,7);
        }

        ticketFileStream.close();
        tempFileStream.close();
        remove("tickets.txt");
        rename("temp.txt", "tickets.txt");
    }
}

// SHOW TICKET BY PNR
void Ticket::showTicketsByPNR()
{
    system("cls");

    char pnr[10];
    int chk = 0;
    fstream ticketFileStream;
					setColor(3,4);
                    gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                 DANH SACH VE                ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);
    cout << "Nhap ma ve PNR:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(pnr, 10);
    setColor(0,7);

    system("cls");
					setColor(3,4);
                    gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                 DANH SACH                   ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!";
        _getch();
        setColor(3,4);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(getPnrNo(), pnr) == 0)
            {
                displayTicket();
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY NAME
void Ticket::showTicketsByName()
{
    system("cls");

    char n[20];
    int chk = 0;
    fstream ticketFileStream;
					setColor(3,4);
                    gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||               DANH SACH                     ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);
                    cout << "NHAP TEN KHACH HANG:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(n, 20);
    setColor(0,7);

    system("cls");
	setColor(3,4);
    gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||                 DANH SACH                   ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);


    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(getName(), n) == 0)
            {
                displayTicket();
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY BUS
void Ticket::showTicketsByBus()
{
    system("cls");

    char bNo[10];
    int chk = 0;
    fstream ticketFileStream;
					setColor(3,4);
                    gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||              DANH SACH VE                   ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);

    cout << "NHAP SO XE:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(bNo, 10);
    setColor(0,7);

    system("cls");
				setColor(3,4);
                gotoxy(10,1);
                cout<< "-------------------------------------------------";
                gotoxy(10,2);
                cout<< "||                 DANH SACH                   ||"; 
                gotoxy(10,3);
                cout<< "||                                             ||";
                gotoxy(10,4);
                cout<< "-------------------------------------------------" ;
                gotoxy(10,6);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmp(bus.getBusNo(), bNo) == 0)
            {
                displayTicket();
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY SOURCE
void Ticket::showTicketsBySource()
{
    system("cls");

    char s[20];
    int chk = 0;
    fstream ticketFileStream;
	setColor(3,4);
   gotoxy(10,1);
                    cout<< "-------------------------------------------------";
                    gotoxy(10,2);
                    cout<< "||           DANH SACH VE                      ||"; 
                    gotoxy(10,3);
                    cout<< "||                                             ||";
                    gotoxy(10,4);
                    cout<< "-------------------------------------------------" ;
                    gotoxy(10,6);
                    setColor(5,6);

    cout << "XUAT PHAT TU:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(s, 20);
    setColor(0,7);

    system("cls");
	setColor(3,4);
     gotoxy(10,1);
                cout<< "-------------------------------------------------";
                gotoxy(10,2);
                cout<< "||                 DANH SACH                   ||"; 
                gotoxy(10,3);
                cout<< "||                                             ||";
                gotoxy(10,4);
                cout<< "-------------------------------------------------" ;
                gotoxy(10,6);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(bus.getSource(), s) == 0)
            {
                displayTicket();
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
            setColor(0,7);
        }
        ticketFileStream.close();
    }
}

// SHOW TICKET BY DESTINATION
void Ticket::showTicketsByDestination()
{
    system("cls");

    char d[20];
    int chk = 0;
    fstream ticketFileStream;
	setColor(3,4);
     gotoxy(10,1);
                cout<< "-------------------------------------------------";
                gotoxy(10,2);
                cout<< "||         DANH SACH VE                        ||"; 
                gotoxy(10,3);
                cout<< "||                                             ||";
                gotoxy(10,4);
                cout<< "-------------------------------------------------" ;
                gotoxy(10,6);
                setColor(5,6);
    cout << "DIEM DEN:-> ";
    cin.ignore();
    setColor(3,4);
    cin.getline(d, 20);
    setColor(0,7);

    system("cls");
	setColor(3,4);
     gotoxy(10,1);
                cout<< "-------------------------------------------------";
                gotoxy(10,2);
                cout<< "||                 DANH SACH                   ||"; 
                gotoxy(10,3);
                cout<< "||                                             ||";
                gotoxy(10,4);
                cout<< "-------------------------------------------------" ;
                gotoxy(10,6);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if (strcmpi(bus.getDestination(), d) == 0)
            {
                displayTicket();
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
        	gotoxy(10,20);
            cout << "KHONG TIM THAY...!!\n";
            _getch();
        setColor(0,7);
        }
        ticketFileStream.close();
    }
}

// SHOW ALL BOOKINGS
void Ticket::showAllTickets()
{
    system("cls");

    fstream ticketFileStream;

    system("cls");
	setColor(3,4);
     gotoxy(10,1);
                cout<< "-------------------------------------------------";
                gotoxy(10,2);
                cout<< "||                 DANH SACH                   ||"; 
                gotoxy(10,3);
                cout<< "||                                             ||";
                gotoxy(10,4);
                cout<< "-------------------------------------------------" ;
                gotoxy(10,6);

    ticketFileStream.open("tickets.txt", ios::in | ios::app);
    if (ticketFileStream.fail())
    {
    	gotoxy(10,20);
        cout << "Can't Open File...!!\n";
        _getch();
        setColor(0,7);
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            displayTicket();
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        ticketFileStream.close();
    }
}