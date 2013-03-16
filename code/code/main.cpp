/*
 * The lottery managing application.
 * Private purpose only.
 * no commercial.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define MAX_ARR 6

void showMenu(void);
void insertPurchasedNum(void);
void statisticsView(void);
void lotteryPractice(void);
void practiceStatistics(void);


int getRandomNumber(int nth, int *numAdr);
bool duplicationProtect(int *numAdr, int place, int cmpNum);
bool rangeProtect(int num);
void numSort(int *numAdr);
int cmpNumSets(int *pNum, int *pNum2);

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
        cout << "4. lottery practice statistics"            << endl;
        cout << "5. exit"                                   << endl;
        cout << "goTo => ";
        cin  >> getMenu;
        if(getMenu > 0 && getMenu < 5) break;
    }
    switch(getMenu)
    {
        case 1: insertPurchasedNum();
            break;
        case 2: statisticsView();
            break;
        case 3: lotteryPractice();
            break;
        case 4: practiceStatistics();
            break;
        case 5: return;
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
        lotteryNumbers[i] = getRandomNumber(i, lotteryNumbers);
        cin >> numbers[i];
        //du
        if(numbers[i] < 1 || numbers[i] > 50)
        {
            cout << "RANGE ERROR. TRY AGAIN" << endl;
            cout << "=> ";
            i=-1;
        }
    }
    numSort(numbers);
    numSort(lotteryNumbers);
    cout << "=========================" << endl;
    cout << "LOTTERY RESULT"            << endl;
    cout << "=========================" << endl;
    cout << "YOUR NUMBER : "            << endl;
    for(int i=0;i<MAX_ARR;i++)
        cout << numbers[i] << setw(3);
    cout << endl;
    cout << "LOTTERY NUMBER : "         << endl;
    for(int i=0;i<MAX_ARR;i++)
        cout << lotteryNumbers[i] << setw(3);
    cout << endl;
    
    cout << cmpNumSets(numbers,lotteryNumbers);
}

int getRandomNumber(int nth, int *numAdr)
{
    int newNumber = rand()%50 + 1;
    while(1)
        if(duplicationProtect(numAdr, nth, newNumber)) break;
    return newNumber;
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

int cmpNumSets(int *pNum, int *pNum2)
{
    int cnt=0;
    for(int i=0;i<MAX_ARR;i++)
        if(!duplicationProtect(pNum, MAX_ARR, *(pNum2 + i))) cnt++;
    return cnt;
}











