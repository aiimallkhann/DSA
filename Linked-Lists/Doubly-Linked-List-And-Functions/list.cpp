#include <iostream>
#include "list.h"

using namespace std;

void func::addatstart(int n, int data){
	node* temp = new node;
	temp->info = data;
	temp->link = arr[n];
	
	if (arr[n] == nullptr){
		arr[n] = temp;
		arr[n]->back = nullptr;
		arr[n]->link = nullptr;
	}
	
	else
	{
		arr[n]->back = temp;
		arr[n] = temp;
	}
}

void func::addatend(int n, int data){
	node* temp = new node;
	node* q = new node;
	temp->info = data;
	temp->link = nullptr;
	q = arr[n];
	
	if (arr[n] == nullptr){
		arr[n] = temp;
		arr[n]->back = nullptr;
		arr[n]->link = nullptr;
	}
	
	else
	{
	while (q->link != nullptr){
		q = q->link;
	}
	q->link = temp;
	temp->back = q;
	}
}

void func::addatmiddle(int n, int data, int pos)
{
    node* temp = new node;
    temp->info = data;
    temp->link = nullptr;

    node* q = arr[n];

    if (arr[n] == nullptr)
    {
        cout << "List has less than " << pos << " elements.\n";
        delete temp;
        return;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        if (q == nullptr)
        {
            cout << "Position " << pos << " not found in list.\n";
            delete temp;
            return;
        }

        q = q->link;
    }

    temp->link = q->link;
    temp->back = q;

    if (q->link != nullptr)
        q->link->back = temp;

    q->link = temp;
}

void func::delatstart(int n)
{
    node* temp = arr[n];

    if (arr[n] == nullptr)
    {
        return;
    }

    else if (arr[n]->link == nullptr)
    {
        arr[n] = nullptr;
        delete temp;
    }

    else
    {
        arr[n] = arr[n]->link;
        arr[n]->back = nullptr;
        delete temp;
    }
}

void func::delatend(int n){
	node* q = arr[n];
	node* temp = arr[n];
	
	if (arr[n] == nullptr)
    {
        return;
    }

    else if (arr[n]->link == nullptr)
    {
        arr[n] = nullptr;
        delete temp;
    }
	
	else
	{
	while (q->link->link != nullptr){
		q=q->link;
	}
	temp = q->link;
	q->link = nullptr;
	delete temp;
	}
}
void func::delatpos(int n, int data, int pos){
	node* q = arr[n];
	node* temp = arr[n];
	if (arr[n] == nullptr)
    {
        return;
    }

    else if (arr[n]->link == nullptr)
    {
        arr[n] = nullptr;
        delete temp;
    }
    else if (pos == 1)
    {
        arr[n] = arr[n]->link;
        arr[n]->back = nullptr;
        delete temp;
    }
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			if (q == nullptr)
			{
				cout << "Position not found in list.\n";
				return;
			}
			q = q->link;
		}
		temp = q->link;
		if (temp == nullptr)
        {
            cout << "Position not found in list.\n";
            return;
        }
		q->link = temp->link;
		if (temp->link != nullptr)
        {
            temp->link->back = q;
        }
		delete temp;
	}
}
void func::display(int n)
{
	node* q = arr[n];
	while (q != nullptr)
	{
		cout << q->info << " ";
		q = q->link;
	}
}
void func::count(int n)
{
	node* q = arr[n];
	int count = 0;
	while (q != nullptr)
	{
		count++;
		q = q->link;	
	}
	cout << "Total number of elements in list = " << count << endl;
}

void func::copyList(int n)
{
    node* q = arr[n];
    node* temp = nullptr;
    node* prev = nullptr;

    arr[nextfree] = nullptr;

    while (q != nullptr)
    {
        temp = new node;
        temp->info = q->info;
        temp->link = nullptr;
        temp->back = prev;

        if (arr[nextfree] == nullptr)
        {
            arr[nextfree] = temp;
        }
        else
        {
            prev->link = temp;
        }

        prev = temp;
        q = q->link;
    }

    nextfree++;
}

void func::rev(int n)
{
	// NULL <-|1 |ADD| -> <-|2 |ADD| -> <-|3 |ADD| -> NULL
    copyList(n);

    int newlist = nextfree - 1;

    node* q = arr[newlist];
    node* prev = arr[newlist];
    node* temp = arr[newlist];

    while (q->link != nullptr)
    {
        temp = q->link;

        q->link = q->back;
        q->back = temp;

        prev = q;
        q = temp;
    }

    q->link = q->back;
    q->back = nullptr;
    arr[newlist] = q;
}
void func::search(int n, int data)
{
	node* q = arr[n];
	int index = 0;
	if (arr[n] == nullptr)
	{
		cout << "List not created.\n";
	}
	while (q != nullptr)
	{
		if (q->info == data)
		{
			cout << "Element found at " << index << " index.\n";
			return;
		}
		q = q->link;
		index++;
	}
}

void func::concat(int first, int second)
{
    copyList(first);
    int newlist1 = nextfree - 1;

    copyList(second);
    int newlist2 = nextfree - 1;
    
    node* q = arr[newlist1];
    while (q != nullptr)
    {
    	q = q->link;
	}
	q->link = arr[newlist2]->link;
}

int func::choose_list()
{
    int n;

    for (int i = 0; i < 50; i++)
    {
        if (arr[i] != nullptr)
        {
            cout << "List " << i << " exists" << endl;
        }
    }

    cout << "Choose list: ";
    cin >> n;
    
    return n;
}

void func::concatuser()
{
    int one, two;

    one = choose_list();

    if (arr[one] == nullptr)
    {
        cout << "List does not exist.\n";
        return;
    }

    two = choose_list();

    if (arr[two] == nullptr)
    {
        cout << "List does not exist.\n";
        return;
    }

    if (one == two)
    {
        cout << "Choose two different lists.\n";
        return;
    }

    concat(one, two);
}
void func::split(int n)
{
	// NULL <- |1|ADD| -> <- |2|ADD| -> <- |3|ADD| -> NULL
	int mid = count_list(arr[n])/2;
	copyList(n);

    int newlist = nextfree - 1;
	node* q = arr[newlist];
	for (int i = 0; i < mid; i++)
	{
		q = q->link;
	}
	node* sec = q->link;
	
}






