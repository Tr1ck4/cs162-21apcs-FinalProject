#include "Node.cpp"
#include <iostream>
void update(LinkedList<Semester*> pSemester)
{
    int level;
    cout << "PRESS 1 TO UPDATE ID\nPRESS 2 TO UPDATE STUDENT LIST\nPRESS 3 TO CHANGE TEACHER\nPRESS 4 TO CHANGE TO SCHEDULE";
    cin >> level;
    switch(level)
    {
        case 1:
        {
            cout << "Which HP to change";
            string ID;
            cin >> ID;
            while(pHead!= nullptr)
            {
                if (pHead->id == ID)
                {
                    cout << "Change to : ";
                    cin >> ID;
                    pHead->id = ID;
                    update(pHead);
                    break;
                }
            }
            //Nhập Mã môn học vào, nếu loop qua linked list không tìm thấy coi như not found. Sẽ có 2 option : 1 là thêm, 2 là skip qua
            cout << "Hoc Phan khong tim thay\n";//Bước skip
            update(pHead);//Nhảy lại menu 
        }
        case 2:
        {
            cout << "ID of student : ";
            string input;
            cin>> input;
            
        }
        case 3 :
        {
            cout << "Giao vien moi : ";
            string name;
            cin >> name;
            while(pHead!=nullptr)
            {
                if (pHead->pCourse)
            }
        }
        case 4 :
        {

        }
    };
}