#ifndef NODE_H
#define NODE_H
#include<iostream>
#include"bus.h"
#include<fstream>
#include"utils.h"
using namespace std;

class NodeBus:public Bus{
	private:
		Bus z;
		NodeBus* nextbus;
	public:
		NodeBus(){
			this->z=Bus();
			this->nextbus=NULL;
		}
		NodeBus(Bus z){
			this->z=z;
			this->nextbus=NULL;
		}
		Bus dataBus(){
			return z;
		}
		NodeBus* GetNext(){
			return nextbus;
		}
		void SetNext(NodeBus* nextbus){
			this->nextbus=nextbus;
		}
		void SetNext(){
			this->nextbus=NULL;
		}
		NodeBus* MakeNode(Bus z){
			NodeBus* p=new NodeBus();
			p->z=z;
			p->nextbus=NULL;
			return p;
		}
		friend class ListBus;
};

class ListBus{
	private:
		NodeBus* head;
	public:
		ListBus(){
			this->head= NULL;
		}
		~ListBus(){
			NodeBus* p=new NodeBus();
			p=head;
			while(p!=NULL){
				NodeBus* q=new NodeBus();
				q=p;
				delete q;
				p=p->nextbus;
			}
		}
		void sethead(NodeBus* head){
			this->head =head;
		}
		void Create(){
			this->head=NULL;
		}
		void Last(NodeBus* x);
		void ReadFileBus();
		void addBus();
		void showAllBus();
};

#endif //NODE_H
