#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include<string>
using namespace std;


template <class T>
class Node
{
public:
    Node<T>* next;
    Node<T>* prev;
    T data;
};


template <class T>
class List
{
public:
    List();//默认构造函数
    ~List();//析构函数
    void append(T e);//向链表添加数据
    void remove(int index);//移除某个结点
    void insert(int a, T n); //在第n个结点后加
    void get(int n); //返回第n个结点的数据
    void set(int a, T n); //将第n个节点的数据改成a
    void show();//显示链表
private:
    Node<T>* head;
    Node<T>* tail;
    int length;
};

//默认构造函数
template <typename T>
List<T>::List()
{
    head = new Node<T>;
    tail = new Node<T>;
    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->prev = head;
    length = 0;
}

template <typename T>
void List<T>::append(T e)
{
    Node<T>* temp = this->tail;
    tail->data = e;
    tail->next = new Node<T>;
    Node<T>* p = tail;
    tail = tail->next;
    tail->prev = p;
    tail->next = nullptr;
    length++;
}

template <typename T>
void List<T>::remove(int index)
{
    if (index > this->length)
        return;
    Node<T>* p = head;
    int x = 0;
    while (p->next != nullptr)
    {
        p = p->next;
        x++;
        if (x == index)
        {
            Node<T>* temp = p->prev;
            temp->next = p->next;
            p->next->prev = temp;
            delete p;
            length--;
            return;
        }
    }
}

template<class T>
void List<T>::insert(int a, T n)
{
    if (a > this->length)
        return;
    Node<T>* p = head;
    int x = 0;
    while (p->next != nullptr)
    {
        if (a == 0)
        {
            Node<T>* temp = new Node<T>;
            temp->data = n;
            temp->next = p->next;
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            length++;
            return;
        }
        p = p->next;
        x++;
        if (x == a)
        {
            Node<T>* temp = new Node<T>;
            temp->data = n;
            temp->next = p->next;
            temp->prev = p;
            p->next->prev = temp;
            p->next = temp;
            length++;
            return;
        }
    }
}

template<class T>
void List<T>::get(int n)
{
    if (n > this->length) {
        cout << "error" << endl;
        return;
    }
    Node<T>* p = head;
    int x = 0;
    while (p->next != nullptr)
    {
        p = p->next;
        x++;
        if (x == n)
        {
            cout << p->data << endl;
            return;
        }
    }
}

template<class T>
void List<T>::set(int a, T n)
{
    if (a > this->length)
        return;
    Node<T>* p = head;
    int x = 0;
    while (p->next != nullptr)
    {
        p = p->next;
        x++;
        if (x == a)
        {
            p->data = n;
            return;
        }
    }
}

template <typename T>
void List<T>::show()
{
    Node<T>* p = head->next;
    while (p != tail)
    {
        cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

template <typename T>
List<T>::~List()
{
    if (length == 0)
    {
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        return;
    }
    while (head->next != nullptr)
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

int main() {
    char ch;
    int t;
    cin >> t;
    while (t--) {
        cin >> ch;
        int n;
        cin >> n;
        if (ch == 'I') {
            List<int> list;
            while (n--) {
                int data;
                cin >> data;
                list.append(data);
            }
            int opt;
            int num;
            cin >> opt >> num;
            list.insert(opt, num);
            cin >> opt;
            list.get(opt);
            cin >> opt;
            list.remove(opt);
            cin >> opt >> num;
            list.set(opt, num);
            list.show();
        }
        else if (ch == 'S') {
            List<string> list;
            while (n--) {
                string data;
                cin >> data;
                list.append(data);
            }
            int opt;
            string str;
            cin >> opt >> str;
            list.insert(opt, str);
            cin >> opt;
            list.get(opt); 
            cin >> opt;
            list.remove(opt);
            cin >> opt >> str;
            list.set(opt, str);
            list.show();
        }
        else if (ch == 'D') {
            List<double> list;
            while (n--) {
                double data;
                cin >> data;
                list.append(data);
            }
            int opt;
            double num;
            cin >> opt >> num;
            list.insert(opt, num); 
            cin >> opt;
            list.get(opt);
            cin >> opt;
            list.remove(opt);            
            cin >> opt >> num;
            list.set(opt, num);
            list.show();
        }
    }
    return 0;
}
