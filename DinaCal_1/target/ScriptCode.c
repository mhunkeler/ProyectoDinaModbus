char* onReset_EVENT(){
	initLevelsFunctions();
	setTime1_toStr(2,"1000","A");
	strcpy(acel,"----");
	AccPower_toStr(2,"1");
	resetLevelsFunctions();
}
char* etOut1_EVENT(){
	initLevelsFunctions();
	strcpy(fuerza,getForce_toStr(3));
	pRS232_toStr(2,"C:","F:"fuerza"\tA:"acel);
	blkLed1_toStr(2,"120","250","1");
	resetLevelsFunctions();
}
char* eAccReady_EVENT(char *AccX,char *AccY,char *AccZ){
	initLevelsFunctions();
	strcpy(acel,%A);
	resetLevelsFunctions();
}

