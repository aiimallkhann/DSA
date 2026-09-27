#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;

func::func()
{
    for (int i = 0; i < 50; i++)
        arr[i] = nullptr;
    nextfree = 15;
    q = nullptr;
    tmp = nullptr;
}

void func::addatstart(int n, int data)
{
    node *tmp = new node;
    tmp->info = data;
    tmp->link = arr[n];
    arr[n] = tmp;
}

void func::addatmiddle(int n, int data, int pos)
{
    node *q = arr[n];
    for (int i = 0; i < pos - 1; i++)
    {
        q = q->link;
        if (q == nullptr)
        {
            cout << "There are less than " << pos << " elements\n";
            return;
        }
    }
    node *tmp = new node;
    tmp->info = data;
    tmp->link = q->link;
    q->link = tmp;
}

void func::addatend(int n, int data)
{
    node *tmp = new node;
    tmp->info = data;
    tmp->link = nullptr;

    if (arr[n] == nullptr)
    {
        arr[n] = tmp;
        return;
    }

    node *q = arr[n];
    while (q->link != nullptr)
        q = q->link;
    q->link = tmp;
}


void func::delatmiddle(int n, int data)
{
    q = arr[n];
    while (q->link != nullptr)
    {
        if (q->link->info == data)
        {
            tmp = q->link;
            q->link = tmp->link;
            delete tmp;
            return;
        }
        q = q->link;
    }
    cout << "Element " << data << " not found in List " << n << "\n";
}

void func::delatstart(int n)
{
    node *tmp = arr[n];
    arr[n] = arr[n]->link;
    delete tmp;
}

void func::delatend(int n)
{
    if (arr[n]->link == nullptr)
    {
        delete arr[n];
        arr[n] = nullptr;
        return;
    }
    node *q = arr[n];
    while (q->link->link != nullptr)
        q = q->link;
    delete q->link;
    q->link = nullptr;
}


void func::display(int n)
{
    node *q = arr[n];
    cout << "List " << n << " : ";
    if (q == nullptr)
    {
        cout << "Empty\n";
        return;
    }
    while (q != nullptr)
    {
        cout << q->info << " ";
        q = q->link;
    }
    cout << "\n";
}

void func::count(int n)
{
    cout << "List " << n << " has " << count_list(arr[n]) << " element(s)\n";
}

void func::rev(int n)
{
    if (arr[n] == nullptr)
    {
        cout << "List " << n << " is empty\n";
        return;
    }

    node *copy = copy_list(arr[n]);

    if (copy->link != nullptr)
    {
        node *p1 = copy;
        node *p2 = p1->link;
        node *p3 = p2->link;
        p1->link = nullptr;
        p2->link = p1;
        while (p3 != nullptr)
        {
            p1 = p2;
            p2 = p3;
            p3 = p3->link;
            p2->link = p1;
        }
        copy = p2;
    }

    int newlist = nextfree;
    arr[newlist] = copy;
    nextfree++;

    cout << "Original List " << n << " (unchanged) -> ";
    display(n);
    cout << "Reversed copy created as List " << newlist << " -> ";
    display(newlist);
}

void func::search(int n, int data)
{
    node *q = arr[n];
    int pos = 1;
    while (q != nullptr)
    {
        if (q->info == data)
        {
            cout << "Item " << data << " found at position " << pos << " in List " << n << "\n";
            return;
        }
        q = q->link;
        pos++;
    }
    cout << "Item " << data << " not found in List " << n << "\n";
}


node* func::copy_list(node *head)
{
    node *q = head;
    node *newhead = nullptr;
    while (q != nullptr)
    {
        node *newnode = new node;
        newnode->info = q->info;
        newnode->link = nullptr;
        if (newhead == nullptr)
            newhead = newnode;
        else
        {
            node *p = newhead;
            while (p->link != nullptr)
                p = p->link;
            p->link = newnode;
        }
        q = q->link;
    }
    return newhead;
}

node* func::concat(node *first, node *second)
{
    node *newhead = copy_list(first);
    node *q = second;
    while (q != nullptr)
    {
        node *newnode = new node;
        newnode->info = q->info;
        newnode->link = nullptr;
        if (newhead == nullptr)
            newhead = newnode;
        else
        {
            node *p = newhead;
            while (p->link != nullptr)
                p = p->link;
            p->link = newnode;
        }
        q = q->link;
    }
    return newhead;
}


int func::count_list(node *head)
{
    int cnt = 0;
    node *q = head;
    while (q != nullptr)
    {
        cnt++;
        q = q->link;
    }
    return cnt;
}

void func::bubble_sort(node *head, int order)
{
    if (head == nullptr)
        return;

    int n = count_list(head);

    if (order == 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            node *p = head;
            for (int j = 0; j < n - 1 - i; j++)
            {
                node *q = p->link;
                if (p->info > q->info)
                {
                    int t = p->info;
                    p->info = q->info;
                    q->info = t;
                }
                p = p->link;
            }
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            node *p = head;
            for (int j = 0; j < n - 1 - i; j++)
            {
                node *q = p->link;
                if (p->info < q->info)
                {
                    int t = p->info;
                    p->info = q->info;
                    q->info = t;
                }
                p = p->link;
            }
        }
    }
}

int func::choose_list()
{
    int k;
    cout << "Which list (1 or 2) : ";
    cin >> k;
    while (k != 1 && k != 2)
    {
        cout << "Enter 1 or 2 : ";
        cin >> k;
    }
    return k;
}


void func::concatenate()
{
    if (arr[1] == nullptr || arr[2] == nullptr)
    {
        cout << "Please create List 1 and List 2 first\n";
        return;
    }
    arr[3] = concat(arr[1], arr[2]);
    arr[4] = concat(arr[2], arr[1]);
    display(3);
    display(4);
}

void func::concatuser()
{
    if (arr[1] == nullptr || arr[2] == nullptr)
    {
        cout << "Please create List 1 and List 2 first\n";
        return;
    }

    int total1 = count_list(arr[1]);
    int total2 = count_list(arr[2]);

    int k1, k2;
    cout << "How many nodes to take from List 1 (max " << total1 << ") : ";
    cin >> k1;
    cout << "How many nodes to take from List 2 (max " << total2 << ") : ";
    cin >> k2;

    if (k1 < 0 || k1 > total1 || k2 < 0 || k2 > total2)
    {
        cout << "Invalid number of nodes requested\n";
        return;
    }

    int newlist = nextfree;
    arr[newlist] = nullptr;
    nextfree++;

    node *q = arr[1];
    for (int i = 0; i < k1; i++)
    {
        addatend(newlist, q->info);
        q = q->link;
    }

    q = arr[2];
    for (int i = 0; i < k2; i++)
    {
        addatend(newlist, q->info);
        q = q->link;
    }

    display(newlist);
}


void func::split()
{
    int k = choose_list();
    if (arr[k] == nullptr)
    {
        cout << "List " << k << " has not been created yet\n";
        return;
    }

    int total = count_list(arr[k]);
    int half = total / 2;
    cout << "Count = " << total << ", half = " << half << "\n";

    int firstlist, secondlist;
    if (k == 1)
    {
        firstlist = 5;
        secondlist = 6;
    }
    else
    {
        firstlist = 7;
        secondlist = 8;
    }

    arr[firstlist] = nullptr;
    arr[secondlist] = nullptr;

    node *q = arr[k];
    int i = 1;
    while (q != nullptr)
    {
        if (i <= half)
            addatend(firstlist, q->info);
        else
            addatend(secondlist, q->info);
        q = q->link;
        i++;
    }

    display(firstlist);
    display(secondlist);
}

void func::splitparts()
{
    int k = choose_list();
    if (arr[k] == nullptr)
    {
        cout << "List " << k << " has not been created yet\n";
        return;
    }

    int total = count_list(arr[k]);
    int p;
    cout << "Into how many parts : ";
    cin >> p;

    if (p <= 0 || p > total)
    {
        cout << "Invalid number of parts\n";
        return;
    }

    int size = total / p;
    int extra = total % p;

    node *q = arr[k];
    int firstindex = nextfree;

    for (int i = 0; i < p; i++)
    {
        int thissize = size;
        if (i < extra)
            thissize = thissize + 1;

        arr[nextfree] = nullptr;
        int partindex = nextfree;
        nextfree++;

        for (int j = 0; j < thissize; j++)
        {
            addatend(partindex, q->info);
            q = q->link;
        }
    }

    for (int i = firstindex; i < firstindex + p; i++)
        display(i);
}


int func::occurrences(node *head, int data)
{
    int cnt = 0;
    node *q = head;
    while (q != nullptr)
    {
        if (q->info == data)
            cnt++;
        q = q->link;
    }
    return cnt;
}


void func::stats(node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty\n";
        return;
    }
    int small = head->info;
    int large = head->info;
    int sum = 0;
    int cnt = 0;

    node *q = head;
    while (q != nullptr)
    {
        if (q->info < small)
            small = q->info;
        if (q->info > large)
            large = q->info;
        sum = sum + q->info;
        cnt++;
        q = q->link;
    }
    cout << "Smallest element : " << small << "\n";
    cout << "Largest element  : " << large << "\n";
    cout << "Sum of elements  : " << sum << "\n";
    cout << "Average          : " << (float)sum / cnt << "\n";
}


void func::even_odd()
{
    if (arr[1] == nullptr)
    {
        cout << "Please create List 1 first\n";
        return;
    }

    arr[9]  = nullptr;
    arr[10] = nullptr;

    node *q = arr[1];
    while (q != nullptr)
    {
        if (q->info % 2 == 0)
            addatend(9, q->info);
        else
            addatend(10, q->info);
        q = q->link;
    }

    arr[11] = copy_list(arr[1]);
    bubble_sort(arr[11], 1);

    arr[12] = copy_list(arr[1]);
    bubble_sort(arr[12], 0);

    display(9);
    display(10);
    display(11);
    display(12);
}

void func::digits(int num)
{
    node *list13 = nullptr;

    if (num == 0)
    {
        node *newnode = new node;
        newnode->info = 0;
        newnode->link = nullptr;
        list13 = newnode;
    }

    while (num != 0)
    {
        node *tmp = new node;
        tmp->info = num % 10;
        tmp->link = list13;
        list13 = tmp;
        num = num / 10;
    }
    arr[13] = list13;
    display(13);
}


void func::merge_lists()
{
    int choice;
    cout << "1. Merge List 1 and List 2\n";
    cout << "2. Use List 3 (concatenated)\n";
    cout << "3. Use List 4 (concatenated)\n";
    cout << "Enter choice : ";
    cin >> choice;

    node *result = nullptr;
    if (choice == 1)
    {
        if (arr[1] == nullptr || arr[2] == nullptr)
        {
            cout << "Please create List 1 and List 2 first\n";
            return;
        }
        result = concat(arr[1], arr[2]);
    }
    else if (choice == 2)
    {
        if (arr[3] == nullptr)
        {
            cout << "List 3 has not been created yet. Run Concatenate first\n";
            return;
        }
        result = copy_list(arr[3]);
    }
    else if (choice == 3)
    {
        if (arr[4] == nullptr)
        {
            cout << "List 4 has not been created yet. Run Concatenate first\n";
            return;
        }
        result = copy_list(arr[4]);
    }
    else
    {
        cout << "Invalid choice\n";
        return;
    }

    arr[14] = result;
    cout << "Before sorting -> ";
    display(14);
    bubble_sort(arr[14], 1);
    cout << "After sorting  -> ";
    display(14);
}


void func::deleteoccurrence(int n, int data)
{
    while (arr[n] != nullptr && arr[n]->info == data)
    {
        node *tmp = arr[n];
        arr[n] = arr[n]->link;
        delete tmp;
    }

    if (arr[n] == nullptr)
        return;

    node *q = arr[n];
    while (q->link != nullptr)
    {
        if (q->link->info == data)
        {
            node *tmp = q->link;
            q->link = tmp->link;
            delete tmp;
        }
        else
            q = q->link;
    }
}

void func::insertmiddletwice(int n, int data, int pos)
{
    if (arr[n] == nullptr)
    {
        cout << "List " << n << " has not been created yet\n";
        return;
    }
    addatmiddle(n, data, pos);
    addatmiddle(n, data, pos + 1);
}

void func::fivedigit(int num)
{
    if (num < 10000 || num > 99999)
    {
        cout << "Please enter a 5 digit number\n";
        return;
    }

    int d[5];
    int temp = num;
    for (int i = 4; i >= 0; i--)
    {
        d[i] = temp % 10;
        temp = temp / 10;
    }

    int newlist = nextfree;
    arr[newlist] = nullptr;
    nextfree++;

    for (int i = 0; i < 5; i++)
        addatend(newlist, d[i]);

    addatend(newlist, d[0]);

    display(newlist);
}

void func::nthlargestsmallest(int n, int rank, int choice)
{
    if (arr[n] == nullptr)
    {
        cout << "List " << n << " is empty\n";
        return;
    }

    int total = count_list(arr[n]);
    if (rank < 1 || rank > total)
    {
        cout << "Invalid rank, List " << n << " has only " << total << " element(s)\n";
        return;
    }

    node *copy = copy_list(arr[n]);
    if (choice == 1)
        bubble_sort(copy, 0);
    else
        bubble_sort(copy, 1);

    node *q = copy;
    for (int i = 1; i < rank; i++)
        q = q->link;

    if (choice == 1)
        cout << rank << " largest element in List " << n << " is " << q->info << "\n";
    else
        cout << rank << " smallest element in List " << n << " is " << q->info << "\n";
}

void func::mergedremoval()
{
    if (arr[1] == nullptr || arr[2] == nullptr)
    {
        cout << "Please create List 1 and List 2 first\n";
        return;
    }

    int newlist = nextfree;
    arr[newlist] = nullptr;
    nextfree++;

    node *q = arr[1];
    while (q != nullptr)
    {
        if (occurrences(arr[newlist], q->info) == 0)
            addatend(newlist, q->info);
        q = q->link;
    }

    q = arr[2];
    while (q != nullptr)
    {
        if (occurrences(arr[newlist], q->info) == 0)
            addatend(newlist, q->info);
        q = q->link;
    }

    display(newlist);
}

void func::reversedalt(int n)
{
    if (arr[n] == nullptr)
    {
        cout << "List " << n << " is empty\n";
        return;
    }

    node *copy = copy_list(arr[n]);

    if (copy->link != nullptr)
    {
        node *p1 = copy;
        node *p2 = p1->link;
        node *p3 = p2->link;
        p1->link = nullptr;
        p2->link = p1;
        while (p3 != nullptr)
        {
            p1 = p2;
            p2 = p3;
            p3 = p3->link;
            p2->link = p1;
        }
        copy = p2;
    }

    int newlist = nextfree;
    arr[newlist] = copy;
    nextfree++;

    int k;
    cout << "Display every which element (2 = every other, 3 = every third, ...) : ";
    cin >> k;

    if (k <= 0)
    {
        cout << "Invalid step value\n";
        return;
    }

    cout << "Reversed List " << newlist << " (every " << k << " element) : ";
    node *q = arr[newlist];
    int pos = 1;
    while (q != nullptr)
    {
        if ((pos - 1) % k == 0)
            cout << q->info << " ";
        q = q->link;
        pos++;
    }
    cout << "\n";
}

void func::searchall(int n, int data)
{
    node *q = arr[n];
    int pos = 1;
    bool found = false;

    while (q != nullptr)
    {
        if (q->info == data)
        {
            cout << "Item " << data << " found at position " << pos << " in List " << n << "\n";
            found = true;
        }
        q = q->link;
        pos++;
    }

    if (!found)
        cout << "Item " << data << " not found in List " << n << "\n";
}


void func::menu()
{
    int choice, n, data, pos, listno, rank, opt;

    while (1)
    {
        cout << " 1. Create List (1 or 2)\n";
        cout << " 2. Add at beginning\n";
        cout << " 3. Add at a position (middle)\n";
        cout << " 4. Add at end\n";
        cout << " 5. Delete an element (by value)\n";
        cout << " 6. Delete at beginning\n";
        cout << " 7. Delete at end\n";
        cout << " 8. Display a list\n";
        cout << " 9. Count elements\n";
        cout << "10. Reverse a list\n";
        cout << "11. Search an element\n";
        cout << "12. Concatenate (List 3, List 4)\n";
        cout << "13. Split (List 5/6 or 7/8)\n";
        cout << "14. Count occurrences\n";
        cout << "15. Min/Max/Sum/Average\n";
        cout << "16. Even/Odd + Sort (List 9-12)\n";
        cout << "17. Digits of a number (List 13)\n";
        cout << "18. Merge + Bubble Sort (List 14)\n";
        cout << "19. Concatenate by user given count\n";
        cout << "20. Split into user given parts\n";
        cout << "21. Delete all occurrences of a value\n";
        cout << "22. Insert a node twice at a position\n";
        cout << "23. Five digit insertion\n";
        cout << "24. Nth largest / smallest\n";
        cout << "25. Merge and remove duplicates\n";
        cout << "26. Reverse alternate (custom step)\n";
        cout << "27. Search all occurrences\n";
        cout << " 0. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Create List 1 or List 2 : ";
            cin >> listno;
            if (listno != 1 && listno != 2)
            {
                cout << "Only List 1 or List 2 can be created this way\n";
                break;
            }
            cout << "How many nodes : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Enter element : ";
                cin >> data;
                addatend(listno, data);
            }
            break;

        case 2:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element : ";
            cin >> data;
            addatstart(listno, data);
            break;

        case 3:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element : ";
            cin >> data;
            cout << "Enter position after which to insert : ";
            cin >> pos;
            addatmiddle(listno, data, pos);
            break;

        case 4:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element : ";
            cin >> data;
            addatend(listno, data);
            break;

        case 5:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element to delete : ";
            cin >> data;
            delatmiddle(listno, data);
            break;

        case 6:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            delatstart(listno);
            break;

        case 7:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            delatend(listno);
            break;

        case 8:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            display(listno);
            break;

        case 9:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            count(listno);
            break;

        case 10:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            rev(listno);
            break;

        case 11:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element to search : ";
            cin >> data;
            search(listno, data);
            break;

        case 12:
            concatenate();
            break;

        case 13:
            split();
            break;

        case 14:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element to count : ";
            cin >> data;
            n = occurrences(arr[listno], data);
            cout << data << " occurs " << n << " time(s) in List " << listno << "\n";
            break;

        case 15:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            stats(arr[listno]);
            break;

        case 16:
            even_odd();
            break;

        case 17:
            cout << "Enter a number : ";
            cin >> n;
            digits(n);
            break;

        case 18:
            merge_lists();
            break;

        case 19:
            concatuser();
            break;

        case 20:
            splitparts();
            break;

        case 21:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element to delete all occurrences of : ";
            cin >> data;
            deleteoccurrence(listno, data);
            display(listno);
            break;

        case 22:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element : ";
            cin >> data;
            cout << "Enter position after which to insert : ";
            cin >> pos;
            insertmiddletwice(listno, data, pos);
            display(listno);
            break;

        case 23:
            cout << "Enter a 5 digit number : ";
            cin >> n;
            fivedigit(n);
            break;

        case 24:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter n (rank) : ";
            cin >> rank;
            cout << "1. Largest\n2. Smallest\nEnter choice : ";
            cin >> opt;
            nthlargestsmallest(listno, rank, opt);
            break;

        case 25:
            mergedremoval();
            break;

        case 26:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            reversedalt(listno);
            break;

        case 27:
            cout << "Enter list number : ";
            cin >> listno;
            if (arr[listno] == nullptr)
            {
                cout << "List " << listno << " has not been created yet\n";
                break;
            }
            cout << "Enter element to search : ";
            cin >> data;
            searchall(listno, data);
            break;

        case 0:
            cout << "Program ended\n";
            exit(0);

        default:
            cout << "Invalid choice\n";
        }
    }
}