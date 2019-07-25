#include "TXLib.h"

class MyCoordSys
    {

    private:
    POINT pos, size;
    double scale;

    public:
    void Circle    (double  x,  double y, double r);
    void Pixel     (double  x,  double y, COLORREF color);
    void Rectangle (double x0, double y0, double x1, double y1);
    void Line      (double x0, double y0, double x1, double y1);
    void TextOut   (double  x,  double y, const char text[]);
    double MyX     (double x);
    double MyY     (double y);
    bool PointVisible (double x, double y);

    }

//=============================================================================

void MyX (double x)
    {
    return x*scale + pos.x;
    }

//=============================================================================

void MyY (double y)
    {
    return -(y*scale) + pos.y;
    }

//=============================================================================

void Circle (double  x,  double y, double r)
    {
    if (PointVisible (x, y)) txCircle (MyX (x), MyY (y), r*scale);
    }

//=============================================================================

void Pixel (double  x,  double y, COLORREF color)
    {
    if (PointVisible (x, y)) txSetPixel (MyX (x), MyY (y), color);
    }

//=============================================================================

void Rectangle (double x0, double y0, double x1, double y1)
    {
    if (PointVisible (x0, y0) && PointVisible (x1, y1)) txRectangle (MyX (x0), MyY (y0), MyX (x1), MyY (y1));
    }

//=============================================================================

void Line (double x0, double y0, double x1, double y1)
    {
    if (PointVisible (x0, y0) && PointVisible (x1, y1))  txLine (MyX (x0), MyY (y0), MyX (x1), MyY (y1));
    }

//=============================================================================

void TextOut (double  x,  double y, const char text[])
    {
    if (PointVisible (x, y)) txTextOut (MyX (x), MyY (y), text);
    }

//=============================================================================

bool PointVisible (double x, double y)
    {
    return (MyX (x) > pos.x && MyX (x) < pos.x+size.x && MyY (y) > pos.y && MyY (y) < pos.y+size.y)
    }

//=============================================================================
