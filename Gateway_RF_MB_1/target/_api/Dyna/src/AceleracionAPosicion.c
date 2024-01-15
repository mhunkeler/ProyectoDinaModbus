void procesarPosicion(int16_t aceleracion_u16[],const int tam_array, float time, float _posicion[]) {
    float proPosAcc = 0;
    float proPosAcc2 = 0;
    for (int i = 0; i < tam_array; i++) {
        aceleracion[i] = (float)aceleracion_u16[i];
    }
    float dt = time /1000 / tam_array;
    for (int i = 0; i < tam_array; i++) {
        proPosAcc += aceleracion[i]; // * dt;
        velocidad[i] = proPosAcc;
        proPosAcc2 += proPosAcc;
    }
    float velOffset = proPosAcc2 / tam_array;;
    for (int i = 0; i < tam_array; i++) {
        velocidad[i] -= velOffset;
    }
    float minPosicion = velocidad[0];
    float maxPosicion = velocidad[0] + 1;
    proPosAcc = 0;
    for (int i = 1; i < tam_array; i++) {
        proPosAcc += velocidad[i]; // * dt;
        _posicion[i] = proPosAcc;
        if (_posicion[i] < minPosicion) {
            minPosicion = _posicion[i];
        }
        if (_posicion[i] > maxPosicion){
            maxPosicion = _posicion[i];
        }
   }
    if (metodoAcc == 0)
    {
        for (int i = 0; i < tam_array; i++) {
            _posicion[i] -= minPosicion;
            posicion[i] = (_posicion[i]*(float)carrera)/(maxPosicion-minPosicion);
        }
    }
    else
    {
        for (int i = 0; i < tam_array; i++)
        {
            _posicion[i] -= minPosicion;
        }
        for (int i = 0; i < tam_array; i++)
        {
            posicion[i] = _posicion[i]*dt*dt*9.8/32.0/(float)ajusteAcc*100.0/2.54;
        }
    }
}
void loadCal()
{
    carrera = hold_regs[0];
    offsetAcc = hold_regs[1];
    spanAcc = hold_regs[2];
    offsetFuerza = hold_regs[3];
    spanFuerzaN = hold_regs[4];
    spanFuerzaD = hold_regs[5];
    metodoAcc = hold_regs[6];
    ajusteAcc = hold_regs[7];
}
void ajusteFuerza(int16_t tam_array)
{
            for (int i = 0; i < tam_array; i++)
        {
            resampledForc[i] -= offsetFuerza;
            resampledForc[i] = (int16_t) ((float)(resampledForc[i]-offsetFuerza) * (float)spanFuerzaN / (float)spanFuerzaD )  ;
        }
}
void cargarenMODBUS(float _posicion[], int16_t _fuerza[], union sourfaceCardInfo_U _info){
    for (int i = 0; i < 64; i++) {
        input_regs[i] = (int16_t)_posicion[i];
    }
    for (int i = 0; i < 64; i++) {
        input_regs[64 + i] = (int16_t)_fuerza[i];
    }
    for (int i = 0; i <32; i++) {
        input_regs[128 + i] = _info.data[i];
    }
}
void cargarenMODBUS2(int16_t _posicion[], int16_t _fuerza[], union sourfaceCardInfo_U _info){
    for (int i = 0; i < 64; i++) {
        input_regs[i] = (int16_t)_posicion[i];
    }
    for (int i = 0; i < 64; i++) {
        input_regs[64 + i] = (int16_t)_fuerza[i];
    }
    for (int i = 0; i <32; i++) {
        input_regs[128 + i] = _info.data[i];
    }
}
void procesar()
{
    ajusteFuerza(64);
    if (sourfaceCardInfo.status == 1)
    {
        procesarPosicion(resampledAcc,64, (float) sourfaceCardInfo.period, posicion);
        cargarenMODBUS(posicion, resampledForc, sourfaceCardInfo);
    }
    else
    {
        cargarenMODBUS(resampledAcc, resampledForc, sourfaceCardInfo);
    }
}
