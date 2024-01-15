char* eFSKD_EVENT(){
	initLevelsFunctions();
	blkLed4_toStr(2,"100","200","2");
	loadCal_toStr(2);
	procesar_toStr(2);
	resetLevelsFunctions();
}
char* onReset_EVENT(){
	initLevelsFunctions();
	blkLed4_toStr(2,"100","200","3");
	resetLevelsFunctions();
}

