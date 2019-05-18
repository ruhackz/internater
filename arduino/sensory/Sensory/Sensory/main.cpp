#include <iostream>

using namespace std;

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    if (x >= 880){
        return 1000;
    }
    else if (x <= 5){
        return 0;
    }
    else return x;
}

int main()
{
    while (true) {
        int val;
        cout << "What is your name? ";
        cin >> val;
        long a = map(val, 5, 880, 0, 100);
        cout << a << "!\n";
    }
}
