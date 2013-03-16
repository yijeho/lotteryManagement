#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void showMenu(void);
void lotteryPractice(void);

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
    int numbers[6];
    int lotteryNumbers[6];
    
    cout << "=========================" << endl;
    cout << "LOTTERY PRACTICE"          << endl;
    cout << "=========================" << endl;
    cout << "INSERT YOUR SIX NUMBERS"   << endl;
    cout << "=> "                       << endl;
    for(int i=0;i<6;i++)
    {
        lotteryNumbers[i] = rand()%50 + 1;
        cin >> numbers[i];
    }
    
}