int32_t resampleAux(int16_t* lista, int listaSize, int16_t* resampledList, int nResamples)
{   
    int i;
    if ((nResamples-1)==0){
        nResamples = 64;
    }
    double razon = (double)(listaSize - 1) / (nResamples);
    int32_t valorMedio = 0;
    for (i = 0; i < nResamples; i++)
    {
        double num = i * razon;
        int j = (int)num; // Parte entera del índice.
        double r = i * razon - floor(i * razon); // Fracción del índice.
             resampledList[i] = lista[j] + ((lista[j + 1] - lista[j]) * r);
        valorMedio += resampledList[i];
    }
    return valorMedio;
}
void balance(int16_t* lista, int listaSize,int16_t vMedio)
{
    int32_t resto = vMedio & 63;
    int32_t acc = 0;
    vMedio = vMedio / 64;
    for (int i = 0 ; i < 64; i++)
    {
        acc += resto;
        if (acc >= 64)
        {
            lista[i]--;
            acc -= 64;
        }
        lista[i] = lista[i] - (vMedio);
    }
}
void resample()
{
    int32_t vm;
    vm = resampleAux(bufferAcel_g,bufferIndex_g,resampledAcc,nResamples);
    balance(resampledAcc,nResamples,vm);
    vm = resampleAux(bufferFuer_g,bufferIndex_g,resampledForc,nResamples);
}
