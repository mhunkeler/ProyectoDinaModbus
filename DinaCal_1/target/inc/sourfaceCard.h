union sourfaceCardInfo_U
{
    struct
    {
        uint16_t GPM;
        uint16_t status;
        uint16_t period;
    };
    uint16_t data[16];
} sourfaceCardInfo;
int16_t resampledAcc[64];
uint16_t resampledForc[64];
