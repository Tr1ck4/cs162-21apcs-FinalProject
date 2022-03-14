#include <iostream>
using namespace std;
struct HS
{
    char ID[10];
};
struct HK
{
    char ID[10];
    char*teacher;
    char time[6];
    char date[13];
    char*name;
};
void update(HK*&Hoc_ky);
void update(HK*&Hoc_ky)
{
    int level;
    cout << "PRESS 1 TO UPDATE ID\nPRESS 2 TO UPDATE STUDENT LIST\nPRESS 3 TO CHANGE TEACHER\nPRESS 4 TO CHANGE TO SCHEDULE";
    cin >> level;
    switch(level)
    {
        case 1:
        {
            cout << "Which HP to change";
            char*input;
            
        }
        case 2:
        {

        }
        case 3 :
        {

        }
        case 4 :
        {

        }
    };
}