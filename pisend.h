#ifndef AMSCAN_H
#define AMSCAN_H

#include <wiringPi.h>

class AMScan
{
private:

        int inputpin;
        bool* data;
        int frequency;

public:
        AMScan(int ppin, int pfreq);

        void startrecv();
        void endrecv();

};

#endif
