#pragma once
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

/* Structure to represent a Singly Linked List */
struct node {
	int data;
	node* next;
};

// Linked List written in OOPS Way
class LinkedList{
	public:
		node* head;

		// Default Constructor
		LinkedList(){
			head = NULL;
		}

		// Member Functions
		int listLength();
		void printList();

		// Insertion
		void insertBeg(int val);
		void insertLast(int val);
		void insertMid(int val);

		// Deletion
	// LinkedList (const LinkedList& obj){
    //     cout << "Copy Constructor Called" << endl;
    //     val = obj.val;
    //     next = obj.next;
    // }
};



#endif /* LINKEDLIST_H_ */
