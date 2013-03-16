/*
 * The lottery managing application.
 * Private purpose only.
 * no commercial.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_ARR 6

void showMenu(void);
void lotteryPractice(void);
int getRandomNumber(void);
bool duplicationProtect(int *numAdr, int place, int cmpNum);
void numSort(int *numAdr);

int main()
{
    srand((unsigned int)time(NULL));
    showMenu();
    return 0;
}

void showMenu(void)
{
    int getMenu;
    
    while(1)
    {
        cout << "==================================="       << endl;
        cout << "LOTTO REPOSITORY"                          << endl;
        cout << "==================================="       << endl;
        cout << "1. insert purchased numbers"               << endl;
        cout << "2. statistics view"                        << endl;
        cout << "3. lottery practice"                       << endl;
        cout << "4. exit"                                   << endl;
        cout << "goTo => ";
        cin  >> getMenu;
        if(getMenu > 0 && getMenu < 5) break;
    }
    switch(getMenu)
    {
        case 3: lotteryPractice();
            break;
        case 4: return;
            break;
    }
}

void lotteryPractice(void)
{
    int numbers[MAX_ARR];
    int lotteryNumbers[MAX_ARR];
    
    cout << "=========================" << endl;
    cout << "LOTTERY PRACTICE"          << endl;
    cout << "=========================" << endl;
    cout << "INSERT YOUR SIX NUMBERS"   << endl;
    cout << "=> "                              ;
    for(int i=0;i<MAX_ARR;i++)
    {
        lotteryNumbers[i] = rand()%50 + 1;
        cin >> numbers[i];
    }
    numSort(numbers);

}

int getRandomNumber(void)
{
    return 0;
}

bool duplicationProtect(int *numAdr, int place, int cmpNum)
{
    for(int i=0;i<place;i++)
        if(*(numAdr + i) == cmpNum)
            return false;
    return true;
}


void numSort(int *numAdr)
{
    for(int i=0;i<MAX_ARR-1;i++)
        for(int j=i+1;j<MAX_ARR;j++)
            if(*(numAdr + i) > *(numAdr + j))
            {
                int tmp;
                tmp = *(numAdr + j);
                *(numAdr + j) = *(numAdr + i);
                *(numAdr + i) = tmp;
            }
}













