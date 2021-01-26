#include "GameProcess.h"

int GameProcess::GetCash()
{
    return this->Cash;
}

void GameProcess::SetCash(int Cash)
{
    this->Cash = this->Cash + Cash;
}

void GameProcess::Rolling()
{
    Queue FirstQ(this->Size);
    Queue SecondQ(this->Size);
    Queue ThirdQ(this->Size);

	char Array[6] = { 164,167,181,158,142,144 };

    for (int i = 0; i < this->Size; i++)
    {
        FirstQ.Add(Array[i]);
        SecondQ.Add(Array[i]);
        ThirdQ.Add(Array[i]);
    }
    bool Operation = true;
    int max ;

    while (Operation)
    {
        int FirstN = rand() % 5, TimeF = 0;
        int SecondN = rand() % 5, TimeS = 0;
        int ThirdN = rand() % 5, TimeT = 0;

        if (FirstN >= SecondN && FirstN >= ThirdN)
        {
            max = FirstN;
        }
        else if (SecondN >= FirstN && SecondN >= ThirdN)
        {
            max = SecondN;
        }
        else if (ThirdN >= FirstN && ThirdN >= SecondN)
        {
            max = ThirdN;
        }

        for (int i = 0; i < max; i++)
        {
            if (TimeF != FirstN)
            {
                FirstQ.Extract();
                TimeF++;
            }

            if (TimeS != SecondN)
            {
                SecondQ.Extract();
                TimeS++;
            }

            if (TimeT != ThirdN)
            {
                ThirdQ.Extract();
                TimeT++;
            }
            FirstQ.Show();
            SecondQ.Show();
            ThirdQ.Show();

            cout << endl << "Your cash: " << this->Cash << endl;
            Sleep(1000);
            system("cls");
        }
        
        FirstQ.Show();
        SecondQ.Show();
        ThirdQ.Show();
        cout << endl << "Your cash: " << this->Cash << endl;
        int Prize = 0;

        if(FirstQ.GetFirstElement() == SecondQ.GetFirstElement() == ThirdQ.GetFirstElement())
        {
            Prize = rand() % 1000 + 500;
            cout << "You won a super prize in amount: " << Prize << endl;
            SetCash(Prize);
        }
        else
        {
            cout << "There is no prize , next will good luck!" << endl;
        }
        

        while (true)
        {
            int check;
            cout << endl << "If U want to try one more time enter 1 or to exit enter 2" << endl;
            cin >> check;

            if (check == 1)
            {
                Operation = true;
                system("cls");
                break;
            }
            else if (check == 2)
            {
                Operation = false;
                system("cls");
                break;
            }
            else
            {
                cout << "Invalid code!" << endl;
                system("cls");
            }
        }
    }


}
