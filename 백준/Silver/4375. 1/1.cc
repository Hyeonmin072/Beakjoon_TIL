#include <iostream>
using namespace std;

int main()
{
    int input;

    int sum = 1;
    int count = 1;

    while (cin >> input)
    {
        while (true)
        {
            if (sum % input == 0)
            {
                break;
            }

            sum = (sum * 10) + 1;
            sum %= input;
            count++;
        }  
        cout << count << endl;
        sum = 1;
        count = 1;
    }
    }