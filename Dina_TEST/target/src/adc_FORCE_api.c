uint16_t getForce(void)
{
    return readADC();
}
void init_ForceApi(void)
{
    Force_Init();
}
void ApiForce_OFF(void)
{
    Force_OFF();
}
