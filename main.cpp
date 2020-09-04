#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void shoot(bool& targetAlive, double accuracy);
int startDuel ();


int main() {

    srand  (time(NULL));
    int win;
    double Aaron = 0, Bob = 0, Charlie = 0;
    for (int i=0; i < 1000; i++) {
        // counting times each person hit target
        win = startDuel();
        if (win == 0) {
            Aaron++;
        } else if (win == 1) {
            Bob++;
        } else if (win == 2) {
            Charlie++;
        }
    }

    cout << "If Aaron intentionally miss on his first shot, we have: " << endl;
    cout << "Aaron  win with: " << (Aaron/10) << "%" << endl;
    cout << "Bob win with: " << (Bob/10) << "%" << endl;
    cout << "Charlie win with: " << (Charlie/10) << "%" << endl;
    return 0;
}

void shoot(bool& targetAlive, double accuracy)
{


        double r = ((rand() % 10) + 1) * 0.1; // getting random number between 0 and 1
        if (accuracy > r)
        {
            targetAlive = false;
        }
       else
       {
           targetAlive = true;
        }


}
int startDuel ()
{
    bool aliveAaron = true, aliveBob = true, aliveCharlie = true;
    while ((aliveAaron && aliveBob) || (aliveAaron && aliveCharlie) || (aliveBob && aliveCharlie))
    {
        if (aliveAaron)
        {
            if (aliveCharlie)
            {

                shoot(aliveCharlie, (1.0) / 3);
            }
            else if (aliveBob)
            {
                shoot(aliveBob, (1.0) / 3);
            }

        }

        if (aliveBob)
        {
            if (aliveCharlie)
            {
                shoot(aliveCharlie, (1.0) / 2);
            }
            else if (aliveAaron)
            {
                shoot(aliveAaron, (1.0) / 2);
            }

        }
        if (aliveCharlie)
        {
            if (aliveBob)
            {
                shoot(aliveBob, (1.0));
            }
            else if (aliveAaron)
            {
                shoot(aliveAaron, (1.0));
            }
        }



    }
    if (aliveAaron) return 0;
    else if (aliveBob) return 1;
    else if (aliveCharlie) return 2;

}
