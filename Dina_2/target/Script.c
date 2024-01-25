// Script

const char eAccReady[] = "#detectarCiclo(%A,#getForce())«1»«#AccPower(«0»)#ApiForce_OFF()#resample()#pFSKD()#setTime1(«1000»,«T»)»«3»«#AccPower(«0»)#ApiForce_OFF()#resample()#pFSKD()#setTime1(«1000»,«T»)»";

const char onReset[] = "#blkLed2(«20»,«180»,«10»)#setTime2(«2000»,«T»)";

const char errorFSK[] = "";

const char etOut1[] = "#RadioSleep()";

const char sleepFSK[] = "#deepSleep()";

const char etOut2[] = "#initDetector()#AccPower(«1»)";

