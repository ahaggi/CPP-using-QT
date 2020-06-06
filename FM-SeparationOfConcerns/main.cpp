#include <iostream>
#include <cstdlib>
using namespace std;

void rollDice(int& dice1, int& dice2);
void rollDice(int* dice1, int* dice2);

void doubleOrBust(int* bet);

int main()
{
    srand(time(0));

    int money = 1000;
    int quit = 1;
    int gameType = 0;

    int keepRolling = 0;
    int sum = 0;

    while(money > 0 && quit != 0){
        int bet = 0;
        int dice1 = 0, dice2 = 0;

        int compDice1 = 0, compDice2 = 0;

        cout << "You have " << money << " dollars to bet on next game." << endl;

        cout << "Which type of game would you like to play? 0=craps, 1=black jack dice, 2=powers of two!" << endl;
        cin >> gameType;

        do {
            cout << "Your bet: ";
            cin >> bet;
        } while(bet > money);

        switch (gameType) {
        case 0:
            rollDice(dice1, dice2);
            cout << "Dice1 = " << dice1 << ", Dice2 = " << dice2 << endl;
            if(dice1 + dice2 == 7 || dice1 + dice2 == 11){
                money += bet*2;
                cout << "You won " << 2*bet << " $" << endl;
            } else {
                money -= bet;
                cout << "Sorry, you lost..." << endl;
                if (money == 0){
                    cout << "You are out of money!" << endl;
                }
            }
            break;
        case 1:
            rollDice(dice1, dice2);
            rollDice(compDice1, compDice2);

            sum = (dice1 + dice2);

            cout << "You rolled: " << sum << endl;
            cout << "The house rolled: " << compDice1 + compDice2 << endl;

            do {
                cout << "Would you like to roll again? 0=no 1=yes" << endl;
                cin >> keepRolling;
                rollDice(dice1, dice2);
                sum += (dice1+dice2);
                cout << "Your sum is now: " << sum << endl;
            } while (keepRolling && sum <= 21);

            if(21 < sum)
            {
                cout << "Sorry, you went bust" << endl;
                money -= bet;
            }
            else if(sum <= (compDice1 + compDice2))
            {
                cout << "Sorry, the house beat you" << endl;
                money -= bet;
            }
            else
            {
                cout << "Congratulations you won!" << endl;
                money += bet;
            }
            break;

        case 2:
            rollDice(dice1, dice2);

            sum = (dice1 + dice2);

            cout << "You rolled: " << sum << endl;
            if(!((sum-1) & sum))
            {
                cout << "You won! " << sum << " is a power of two" << endl;
                money += bet;
            }
            else
            {
                cout << "You lost " << sum << " is not a power of two" << endl;
                money -= bet;
            }

            break;

        default:
            cout << "Sorry that is not a game" << endl;
            break;
        }

        cout << "Do you want to play again? 0=no, 1=yes : ";
        cin >> quit;
    }

    cout << "Game over!\n" << "You quit with " << money << " dollars at hand" << endl;

    return 0;
}

void rollDice(int& dice1, int& dice2){
    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;
}

void rollDice(int* dice1, int* dice2){
    *dice1 = rand()%6 + 1;
    *dice2 = rand()%6 + 1;
}
