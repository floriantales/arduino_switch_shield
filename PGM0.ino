void Stop_PGM0(){
    running_pgm0 = false;        // On indique que le PGM ne tourne pas
    Led_Manager_setLed(0, LOW);  // On indique l'état sur la LED associée
}
void Initialize_PGM0(){
    running_pgm0 = true;         // On indique que le PGM tourne
    Led_Manager_setLed(0, HIGH);
}
void PGM0(){ 
}
