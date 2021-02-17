#include "fractal.h"


//int r = 1;
//double q =1;
//double n = 10;

//const int m = 33000;
//double knx[m];
//double kny[m];

//void traf(double x, double y, double z)
//{



//    knx[r+4] = xA;
//    kny[r+4] = yA;

//    knx[r+3] = xB;
//    kny[r+3] = yB;


//    double xC = knx[r] = xA+yA-yB;
//    double yC = kny[r] = yA+xB-xA;

//    double xD = knx[r+2] = xB+yA-yB;
//    double yD = kny[r+2] = yB+xB-xA;

//    knx[r+1] = (xC+xD*q*q + (yC-yD)*q)/(1+q*q);
//    kny[r+1] = (yC + yD*q*q + (xD-xC)*q)/(1+q*q);
//}


//void fractal()
//{
//    traf(-0.15, -0.5, 0.15, 0);
//    for(int i = 0; i < 5*(pow(2,n)-1); i+=5)
//    {
//        traf(knx[i], kny[i], knx[i+1], kny[i+1], 5*r);
//        traf(knx[i+1], kny[i+1], knx[i+2], kny[i+2], 5*(r+1));

//        r = r + 2;

//    }
//}


//void drawing()


void drawF(int x, int y, int len, double angle)
{
    double x1, y1;
    x1 = x + len*sin(angle*PI*2 / 360.0);
    y1 = y + len *cos (angle + PI*2/360.0);
    my_addLine(frame, x1, y2);
}
