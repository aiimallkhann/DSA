#ifndef LIST_H
#define LIST_H

struct node{
	int info;
	node* link;
	node* back;	
};

struct func{
	 node *arr[50] = {};
    int nextfree = 3;
    node *q = nullptr;
    node *tmp = nullptr;

    void addatstart(int n, int data);//
    void addatmiddle(int n, int data, int pos);//
    void addatend(int n, int data);//

    void delatstart(int n);//
    void delatpos(int n, int data, int pos);//
    void delatend(int n);//

    void display(int n);//
    void count(int n); //

    void rev(int n);//
    void copyList(int n);//
    void search(int n, int data);//
    void concat(int first, int second);//
    void bubble_sort(node *head, int order);
    int choose_list();//

    void concatenate();
    void concatuser();//
    void split(int n);
    void splitparts(int n);

    int occurrences(node *head, int data);
    void stats(node *head);
    void even_odd();
    void digits(int num);
    void merge_lists();

    void deleteoccurrence(int n, int data);
    void insertmiddletwice(int n, int data, int pos);
    void fivedigit(int num);
    void nthlargestsmallest(int n, int rank, int choice);
    void mergedremoval();
    void reversedalt(int n);
    void searchall(int n, int data);

    void menu();
};

#endif