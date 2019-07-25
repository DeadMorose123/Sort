#include "TXLib.h"

int main ()
    {
    POINT pos = {100,100};
    POINT size = {900, 900};

    txCreateWindow (1000, 1000);
    txSetFillColor (TX_GREEN);
    txRectangle (pos.x, pos.y, pos.x+size.x, pos.y+size.y);

    for (int x = 0; x < 10000; x++)
        {
        int y = x*x;

        if (-(y/1000) + size.y + pos.y > size.y && x+pos.x < size.x) txCircle (x+pos.x, -(y/100) + size.y + pos.y, 5);

        }

    }
