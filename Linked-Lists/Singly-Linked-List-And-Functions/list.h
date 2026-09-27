#ifndef List
#define List

struct node
{
    int info;
    node *link;
};

struct func{
    node *arr[50];
    int nextfree;
    node *q;
    node *tmp;

    func();

    void create_list(int n, int data);

    void addatstart(int n, int data);
    void addatmiddle(int n, int data, int pos);
    void addatend(int n, int data);

    void delatstart(int n);
    void delatmiddle(int n, int data);
    void delatend(int n);

    void display(int n);
    void count(int n);
    void show(node *head, int k);

    void rev(int n);
    void search(int n, int data);

    node* copy_list(node *head);
    node* concat(node *first, node *second);
    int count_list(node *head);
    void bubble_sort(node *head, int order);
    int choose_list();

    void concatenate();
    void concatuser();
    void split();
    void splitparts();

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