#include <iostream>
#include "Fungsionalitas.h"

using namespace std;

int main()
{
    ListB B;
    ListJ J;
    ListR R;

    createlistB(B);
    createlistJ(J);
    createlistR(R);

    menu(R,B,J);

    return 0;
}
