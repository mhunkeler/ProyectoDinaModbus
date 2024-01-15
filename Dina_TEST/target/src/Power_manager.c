void deepSleep(void)
{
    _DSEN = 1;
    _DSEN = 1; //debe hacerce dos veces
    Sleep();
}
