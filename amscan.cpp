AMScan::AMScan(int ppin) : inputpin(ppin)
{
}

AMScan::startrecv(int pduration)
{
        duration = pduration;
        data = (bool*)malloc(sizeof(bool)*40*pduration);
        for(int i = 0; i<40*pduration; i++)
        {
                *(data+i) = digitalRead(inputpin);
                delayMicroseconds(25);
        }
}

AMScan::printMS()
{
        for(int i = 0; i<duration; i++)
        {
                for(int j = 0; j<40; j++)
                {
                        std::cout << (*(data+i*40+j) ? "II" : "__");
                }
                std::cout << std::endl;
        }
}
