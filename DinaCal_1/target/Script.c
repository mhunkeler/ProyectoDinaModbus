// Script

const char onReset[] = "#setTime1(«1000»,«A»)#acel=«----»;#AccPower(«1»)";

const char etOut1[] = "#fuerza=#getForce();#pRS232(«C:»,«F:»#fuerza;«\tA:»#acel;)#blkLed1(«120»,«250»,«1»)";

const char eAccReady[] = "#acel=%A;";

