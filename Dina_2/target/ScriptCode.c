char* eAccReady_EVENT(char *AccX,char *AccY,char *AccZ){
	initLevelsFunctions();
	blkLed2_toStr(2,"20","21","1");
	detectarCiclo_toStr(2,%A,getForce_toStr(3))"1"AccPower_toStr(2,"0")ApiForce_OFF_toStr(2)resample_toStr(2)pFSKD_toStr(2)blkLed1_toStr(2,"100","200","1")setTime1_toStr(2,"1000","T")"3"AccPower_toStr(2,"0")ApiForce_OFF_toStr(2)resample_toStr(2)pFSKD_toStr(2)blkLed1_toStr(2,"100","200","1")setTime1_toStr(2,"1000","T");
	resetLevelsFunctions();
}
char* onReset_EVENT(){
	initLevelsFunctions();
	blkLed2_toStr(2,"20","100","10");
	setTime2_toStr(2,"2000","T");
	resetLevelsFunctions();
}
char* errorFSK_EVENT(){
	initLevelsFunctions();
	blkLed2_toStr(2,"200","500","5");
	resetLevelsFunctions();
}
char* etOut1_EVENT(){
	initLevelsFunctions();
	RadioSleep_toStr(2);
	resetLevelsFunctions();
}
char* sleepFSK_EVENT(){
	initLevelsFunctions();
	deepSleep_toStr(2);
	resetLevelsFunctions();
}
char* etOut2_EVENT(){
	initLevelsFunctions();
	initDetector_toStr(2);
	AccPower_toStr(2,"1");
	resetLevelsFunctions();
}

