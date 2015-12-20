#ifndef AMSCAN_H
#define AMSCAN_H

#include <wiringPi.h>

class AMScan
{
private:

        int inputpin;
        bool* data;
        int duration;

public:
        AMScan(int ppin);

        void startrecv();

        void printMS();
};

#endif
