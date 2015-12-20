#include <amscan.h>

int main()
{
        AMScan* scanner = new AMScan(0);

        scanner->startrecv();

        scanner->printMS();

        return 0;
}
