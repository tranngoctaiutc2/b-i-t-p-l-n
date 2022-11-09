#include<iostream>
//#include"bus.cpp"
#include"node.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

node* CreateNode(Bus x){
	node* p;
	p=new node;
	p->data=x;
	p->next=NULL;
	return p;
}


void Last(list &l,node* x){
	if(l.head==NULL){
		l.head=l.tail=x;
	}
	else{
		l.tail->next=x;
		l.tail=x;
	}
}


void NodeBus(list &y,Bus b){
	node* q;
	
	b.addBus();
	q=new node;
    q=CreateNode(b);
    Last(y,q);
    free(q);
	

//    cout << "\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!! \n";	
}


