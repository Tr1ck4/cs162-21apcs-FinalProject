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

#include <bits/stdc++.h>
using namespace std;


template <typename T> struct LinkedList {
    T a;
    /// chuwa code :(
};

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

int main() {
    /// Sad :<
}