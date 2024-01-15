// Script

const char eAccReady[] = "#blkLed2(«20»,«21»,«1»)#detectarCiclo(%A,#getForce())«1»«#AccPower(«0»)#resample()#pFSKD()#blkLed1(«100»,«200»,«1»)#setTime1(«5000»,«T»)»«2»«#AccPower(«0»)#resample()#pFSKD()#blkLed1(«100»,«200»,«1»)#setTime1(«5000»,«T»)»";

const char onReset[] = "#blkLed2(«20»,«100»,«1»)#AccPower(«1»)";

const char errorFSK[] = "#blkLed2(«200»,«500»,«5»)#setTime1(«5000»,«T»)";

const char etOut1[] = "#initDetector()#AccPower(«1»)";

