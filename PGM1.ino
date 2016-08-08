void Stop_PGM1(){
    running_pgm1 = false;        // On indique que le PGM ne tourne pas
    Led_Manager_setLed(1, LOW);  // On indique l'état sur la LED associée
}
void Initialize_PGM1(){
    running_pgm1 = true;         // On indique que le PGM tourne
    Led_Manager_setLed(1, HIGH);
}
void PGM1(){ 
}
