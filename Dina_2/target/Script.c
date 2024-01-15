// Script

const char eAccReady[] = "#blkLed2(«20»,«21»,«1»)#detectarCiclo(%A,#getForce())«1»«#AccPower(«0»)#ApiForce_OFF()#resample()#pFSKD()#blkLed1(«100»,«200»,«1»)#setTime1(«1000»,«T»)»«3»«#AccPower(«0»)#ApiForce_OFF()#resample()#pFSKD()#blkLed1(«100»,«200»,«1»)#setTime1(«1000»,«T»)»";

const char onReset[] = "#blkLed2(«20»,«100»,«10»)#setTime2(«2000»,«T»)";

const char errorFSK[] = "#blkLed2(«200»,«500»,«5»)";

const char etOut1[] = "#RadioSleep()";

const char sleepFSK[] = "#deepSleep()";

const char etOut2[] = "#initDetector()#AccPower(«1»)";

