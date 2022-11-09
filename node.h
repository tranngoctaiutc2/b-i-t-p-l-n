#ifndef NODE_H
#define NODE_H
#include<iostream>
#include"bus.h"

using namespace std;

struct Node{
	Bus data;
	Node* next;
}typedef node;


struct List{
	Node* head;
	Node* tail;
}typedef list;


void Tao(struct List &l){
	l.head=NULL;
	l.tail=NULL;
}
class ListBus:public Bus{
	protected:
		node x;
		list y;
		Bus z;
	public:
		node* CreateNode(Bus z);//TAO NODE 
		void Last(list &y,node* x);//THEM NODE VAO CUOI
		void NodeBus(list &y);
//		void showAllBus(list &l);
};


#endif //NODE_H
