char* eAccReady_EVENT(char *AccX,char *AccY,char *AccZ){
	initLevelsFunctions();
	blkLed2_toStr(2,"20","21","1");
	detectarCiclo_toStr(2,%A,getForce_toStr(3))"1"AccPower_toStr(2,"0")resample_toStr(2)pFSKD_toStr(2)blkLed1_toStr(2,"100","200","1")setTime1_toStr(2,"5000","T")"2"AccPower_toStr(2,"0")resample_toStr(2)pFSKD_toStr(2)blkLed1_toStr(2,"100","200","1")setTime1_toStr(2,"5000","T");
	resetLevelsFunctions();
}
char* onReset_EVENT(){
	initLevelsFunctions();
	blkLed2_toStr(2,"20","100","1");
	AccPower_toStr(2,"1");
	resetLevelsFunctions();
}
char* errorFSK_EVENT(){
	initLevelsFunctions();
	blkLed2_toStr(2,"200","500","5");
	setTime1_toStr(2,"5000","T");
	resetLevelsFunctions();
}
char* etOut1_EVENT(){
	initLevelsFunctions();
	initDetector_toStr(2);
	AccPower_toStr(2,"1");
	resetLevelsFunctions();
}

