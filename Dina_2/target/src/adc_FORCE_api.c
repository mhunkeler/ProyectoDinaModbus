uint16_t getForce(void)
{
    readADC();
    return fuerzas_m[indexCardF++];
}
void init_ForceApi(void)
{
    Force_Init();
}
void ApiForce_OFF(void)
{
    Force_OFF();
}
