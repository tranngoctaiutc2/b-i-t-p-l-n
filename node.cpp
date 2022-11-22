#include<iostream>
#include"node.h"
#include <string>
#include <cstring>
#include <fstream>
using namespace std;
void ListBus::Last(NodeBus* x){
	if(head==NULL){
		head=x;
	}
	else{
		NodeBus* p=new NodeBus();
		p=head;
		while(1){
			if(p->GetNext()==NULL){
				p->SetNext(x);
				break;
			}
			
			p=p->GetNext();
		}
	}
}

void ListBus::addBus(){
	Bus b;
	b.addBus();
	NodeBus* d;
	d=new NodeBus(b);
	this->Last(d);
}

void ListBus::ReadFileBus(){
	fstream f;
	NodeBus* d;
	Bus e;
	f.open("buses.txt",ios::in);
	f.read(reinterpret_cast<char*>(&e),sizeof(Bus));
	if(!f){
		cout<<"File khong ton tai"<<endl;
	}
	while(!f.eof()){
		
		d=new NodeBus(e);
		this->Last(d);
		f.read(reinterpret_cast<char*>(&e), sizeof(Bus));
	}
	f.close();
}

void ListBus::showAllBus(){
	system("cls");
	NodeBus* p=new NodeBus();
	p=this->head;
	while(p!=NULL){
		p->z.showBusDetails();
		p=p->GetNext();
	}
}
