// ###########################################
// ###########  VARIABLES
// ###########################################

//### Forcement le meme pour les bouttons et les leds:
#define NUMBER_OF_SHIFT_CHIPS   2              // How many shift register chips are daisy-chained.
#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8 // Width of data (how many ext lines).

//### FONCT_Switch_Manager
#define PULSE_WIDTH_USEC   1      // Width of pulse to trigger the shift register to read and latch.
#define DEBOUNCE 5                // Debounce time in ms
#define BYTES_VAL_T unsigned int  // You will need to change the "int" to "long" if the NUMBER_OF_SHIFT_CHIPS is higher than 2

const byte Button_ClockPin = 4;  // Connects to the Clock pin
const byte Button_LatchPin = 5;  // Connects to Parallel Latch pin
const byte Button_DataPin = 6;   // Connects to the Data pin

const byte bitButton[] = {2,3,10,11,0,1,8,9,6,7,14,15,4,5,12,13};                // Matrice de correspondance physique bit/button - exemple BitButton[Mon Button 1] = Bit registre numero 10
boolean pressed[DATA_WIDTH], justpressed[DATA_WIDTH], justreleased[DATA_WIDTH];  // The buttons states

//### FONCT_Led_Manager
const byte Led_ClockPin = 7;  // Connects to the Clock pin
const byte Led_LatchPin = 8;  // Connects to Serial Latch pin
const byte Led_DataPin = 9;   // Connects to the Data pin

boolean registers[DATA_WIDTH];                                 // Stock les valeurs du registe
const byte bitLed[] = {10,11,2,3,8,9,0,1,14,15,6,7,12,13,4,5};  // Matrice de correspondance physique bit/led - exemple BitLed[Ma Led 1] = Bit registre numero 10

//### PROGRAMMES 1 2 et 3 (Variables utilisées pour la gestion des boutons par exemple ou les leds etc ...)
boolean running_pgm0 = false;  // Gestion de l'état des pgm (running or not)
boolean running_pgm1 = false;
boolean running_pgm2 = false;


// ###########################################
// ###########  SETUP
// ###########################################
void setup()
{
  // Uncomment for debugging mode
  //Serial.begin(9600);

  // Init Button pins
  pinMode(Button_ClockPin, OUTPUT);
  pinMode(Button_LatchPin, OUTPUT);
  pinMode(Button_DataPin, INPUT);
  digitalWrite(Button_ClockPin, LOW);
  digitalWrite(Button_LatchPin, HIGH);
  
  // Init Led pins
  pinMode(Led_ClockPin, OUTPUT);
  pinMode(Led_LatchPin, OUTPUT);
  pinMode(Led_DataPin, OUTPUT);
  digitalWrite(Led_ClockPin, LOW);
  digitalWrite(Led_LatchPin, HIGH);
  digitalWrite(Led_DataPin, LOW);
 
  // Init Led Registers : reset all register pins
  Led_Manager_setAllLed(LOW);
}


// ###########################################
// ###########  DEBUT DU PROGRAMME
// ###########################################
void loop()
{ 
  // On lance l'analyse du clavier. Datas dans pressed justpressed justreleased
  Switch_Manager_checkButtons();
  
  // Tests des combinaisons de touches
  if (justpressed[0]){
    if (!running_pgm0){    // Si le programme ne tourne pas on active sinon on ne fait rien
      Stop_All_PGM();      // ON arrête tout
      Initialize_PGM0();   // On initialise le PGM
    }
  }
  if (justpressed[1]){
    if (!running_pgm1){
      Stop_All_PGM();
      Initialize_PGM1();
    }
  }
  if (justpressed[2]){
    if (!running_pgm2){
      Stop_All_PGM();
      Initialize_PGM2();
    }
  }
  if (justpressed[15]){
      Stop_All_PGM();
  }

  // ON LANCE LES PROGRAMMES ACTIFS
  if (running_pgm0) PGM0();
  if (running_pgm1) PGM1();
  if (running_pgm2) PGM2();
}
