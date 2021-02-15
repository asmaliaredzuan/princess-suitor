#include <iostream>
#include <cassert>
#ifndef _SUITOR_H_
#define _SUITOR_H_
using namespace std;

class Suitor
{
	private:
		struct Node
		{
			int num;
			Node *link;
		};
		
		Node *head;
		Node *current;
		Node *prev;
		Node *next;
		
	public:
		Suitor() : head(0), current(0), prev(0), next(0) { };
		
		~Suitor() {pop_all}
		
		void pop_all()
		{
			while (!empty())
			{
				Node *victim = head;
				head = head-> next;
				delete victim;
			}
		}
		
		Suitor (const Suitor &other) : head (0), current(0)
		{
			push_all (other);
		}
		
		void push_all(const Suitor &other)
		{
			for (Node *np=other.head; np; np=np->next)
			{
				push_back(np->num);
			}
		}
		
		void push_back (int num)
		{
			Node *p =new Node;
			p->num=num;
			p->next=0;
			current->next=p;
			current=p;
		}
		
		Suitor &operator=(const Suitor &rhs)
		{
			if (this==&rhs) {return *this}
		}
		
		Suitor operator++(const Suitor *p)
		{
			if (p==p->next)
			p=fisrt;
			p=p->next;
		}
		
		
		void linkedlist(int suitors)
		{
			head = new Node;
			head->num=1;
			head ->link=head;
			current=head;
			
			for (int i=2; i<= suitors; i++)
			{
				Node *newNode = new Node;
				newNode->num=i;
				newNode->link=head;
				current->link= newNode;
				current=newNode;
			}
			
			current= head;
			
			do
			{
				current=current->link;
				prev = current;
				current= current->link;
				next=current->link;
				prev->link=next;
				cout << current->num << " is eliminated!" << endl;
				delete current;
				current=next;
			}
			
			while(current!=current->link);
			
			cout << current->num << " is the lucky winner!" << endl;
			delete current;
		}
};

#endif
