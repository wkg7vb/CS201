#pragma once
#include <string>
#include <iostream>
#include "patient.h"
using namespace std;

class Node
{
	public:
		Node() { next = NULL; };
		Node(patient theData, Node* Link) { data = theData; next = Link; };

		patient data;
		Node* next;
};

class queue
{
	public:
		queue(string depName);			//default constructor
		void push_back(patient &pat);	//add node to back
		void push_front(patient &pat);	//add node to front
		void pop();						//remove first node
		void erase(patient &pat);		//remove specific node
		void printAll();				//outputs all nodes
		int size() const;				//returns count
		bool is_empty() const;			//determines if the queue is empty based on count
		string getDName();				//gets department name

	private:
		Node* head;
		Node* tail;
		int count;
		string departmentName;
};