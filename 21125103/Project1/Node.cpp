/*
code cai template likedlist dung chung

Cac struct

Date
Score // sau

Student
Class
(Khoa K20, K21) // chac ko can :>

Course
Semester
SchoolYear

*/

#include <iostream>

using namespace std;

// Node class
template <typename T>
struct Node {
    T data;
    Node<T>* pNext;

    Node() : pNext(nullptr) {}
    Node(const T& item, Node<T>* ptr = nullptr) :
        data(item), pNext(ptr) {}
};

// Linked list class
template <typename T>
struct LinkedList {
    Node<T>* pHead;
    Node<T>* pTail;

    LinkedList() {
        // Create the dummy head node
        pHead = pTail = new Node<T>();
    }
    ~LinkedList() {
        while (pHead->pNext != nullptr) {
            Node<T>* temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
        delete pHead;
    }

    // class iterator
    struct iterator {
        Node<T>* nodePtr;
        iterator(Node<T> *newPtr) : nodePtr(newPtr) {}
        iterator() : nodePtr(nullptr) {}

        bool operator!=(const iterator& itr) const {
            return nodePtr != itr.nodePtr;
        }

        T& operator*() const {
            return nodePtr->pNext->data;
        }

        iterator operator++(int) {
            nodePtr = nodePtr->pNext;
            return *this;
        }

        iterator operator++() {
            nodePtr = nodePtr->pNext;
            return *this;
        }
    };

    iterator begin() const {
        return iterator(pHead);
    }

    iterator end() const {
        return iterator(pTail);
    }

    iterator insert(iterator position, const T& value) {
        Node<T>* newNode = new Node<T>(value, position.nodePtr->pNext);
        if (position.nodePtr == pTail) {
            pTail = newNode;
        }
        position.nodePtr->pNext = newNode;
        return position;
    }

    iterator push_back(const T& value) {
        return insert(end(), value);
    }

    iterator erase(iterator position) {
        Node<T> *toDelete = position.nodePtr->pNext;
        position.nodePtr->pNext = position.nodePtr->pNext->pNext;
        if (toDelete == pTail) {
            pTail = position.nodePtr;
        }
        delete toDelete;
        return position;
    }

    iterator find(const T& value) {
        iterator cur(pHead);
        while (cur != end()) {
            if (*cur == value) {
                return cur;
            }
            ++cur;
        }
        return cur;
    }
};


int main() {
    LinkedList<int> v;

    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    for (auto x : v) {
        cout << x << ' ' << endl;
    }

    if (v.find(5) != v.end()) {
        cout << *v.find(5) << '\n';
    }

    return 0;
}

struct Date;
struct Student;
struct Class;
struct Course;
struct Semester;
struct SchoolYear;

struct Date {
	int day, month, year;
	// format dd/mm/yyyy
	// read a day from stream
	void readFromStream(istream &f);
	// write a day to stream
	void writeToStream(ostream &f);
	// compare two days
	bool operator < (const Date &oth);
};

struct Student {
	string id, firstName, lastName, gender, socialID;
    Date dateOfBirth;
	Class* pClass;
};

struct Class {
	string id, name;
	LinkedList<Student*> pStudent;
};

struct Course {
	string id, code, name, lecturer;
    Date start_date, end_date;
	Semester* pSemester;
	LinkedList<Student*> pStudents;
	int maxNumberOfStudents;
	int numberofCredits;
};

struct Semester {
	string id, name;
	SchoolYear* pSchoolYear;
	LinkedList<Course*> pCourse; 	
};

struct SchoolYear {
	string id, name;
	LinkedList<Semester*> pSemester;
};

struct User {
    //lam sau, tam thoi se dang nhap kieu list sv/staff ra roi chon)
};

/// luu du lieu: Student Class Course Semester SchoolYear folder rieng, moi folder luu rieng tung cai ten la <ID>.txt, 
// co them 1 file list het ID ra de doc luc dau cho de. 
/// doc du lieu: doc id truoc roi moi doc cac thong tin khac
/// luu du lieu ngay sau moi lan thay doi
