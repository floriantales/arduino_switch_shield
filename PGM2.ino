void Stop_PGM2(){
    running_pgm2 = false;        // On indique que le PGM ne tourne pas
    Led_Manager_setLed(2, LOW);  // On indique l'état sur la LED associée
}
void Initialize_PGM2(){
    running_pgm2 = true;         // On indique que le PGM tourne
    Led_Manager_setLed(2, HIGH);
}
void PGM2(){ 
}
