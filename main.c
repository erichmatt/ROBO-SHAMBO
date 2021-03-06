//Why the fuck did they fuck with a good thing? Now I gotta download a buncha shit to use github? fuck it.
//This is a simple homemade game of rock paper scissors
//It uses a digispark running at 16.5MHz on the microneucleus bootloader
//It is glitchy to upload. You'll need a USB 2.0 hub, new 3.0 hubs haven't worked for me.

// constants won't change. They're used here to
// set pin numbers and values for musical tones

const int c   = 261;
const int d   = 294;
const int e   = 329;
const int f   = 349;
const int g   = 391;
const int gS  = 415;
const int a   = 440;
const int aS  = 455;
const int b   = 466;
const int cH  = 523;
const int cSH = 554;
const int dH  = 587;
const int dSH = 622;
const int eH  = 659;
const int fH  = 698;
const int fSH = 740;
const int gH  = 784;
const int gSH = 830;
const int aH  = 880;

const int speakerPin = 0;	// PWM pin for speaker on the digispark it's pin P0
const int buttonPin  = 1;	// the number of the button pin P1
const int rockPin    = 2;	// the number of the ROCK LED pin P2
const int paperPin   = 3;	// the number of the PAPER LED pin P3
const int scissorPin = 4;	// the number of the SCISSOR LED pin P4

int buttoncounter = 0;		// integer value for storing how many times the game start reed switch has been actuated
int counter       = 0;		// integer value for storing the counter for making muzak
int buttonState   = 0;      // variable for reading the pushbutton status
int RPSval        = 0;		// variable for storing the button state modulo as to display canned rock paper scissor routine

void setup();
void beep(int note, int duration);
void firstSection();

void loop() { // this is the main program that keeps looping over and over
	buttonState = digitalRead(buttonPin);

	if (buttonState == HIGH) {
		RPSval = random(4);

		firstSection(); // runs the program above that plays the muzak
		digitalWrite(scissorPin, LOW); // makes sure all the lights are off after the muzak plays
		digitalWrite(paperPin,   LOW);
		digitalWrite(rockPin,    LOW);
	}

	switch (RPSval) {
		case 0:
			digitalWrite(scissorPin, HIGH);
			digitalWrite(paperPin, LOW);
			digitalWrite(rockPin, LOW);
			break;
		case 1:
			digitalWrite(scissorPin, HIGH);
			digitalWrite(paperPin, LOW);
			digitalWrite(rockPin, LOW);
			break;
		case 2:
			digitalWrite(rockPin, HIGH);
			digitalWrite(paperPin, LOW);
			digitalWrite(scissorPin, LOW);
			break;
		case 3:
			digitalWrite(paperPin, HIGH);
			digitalWrite(scissorPin, LOW);
			digitalWrite(rockPin, LOW);
			break;
	}
}

void setup() {
	// Seeds the randomizer based on initial state
	randomSeed(analogRead(0));
	// initialize the LED pin as outputs or inputs:
	pinMode(speakerPin, OUTPUT);
	pinMode(rockPin,    OUTPUT);
	pinMode(paperPin,   OUTPUT);
	pinMode(scissorPin, OUTPUT);
	pinMode(buttonPin,  INPUT);
}

void beep(int note, int duration) { // sub program that the main progam calls on to make muzak
	tone(speakerPin, note, duration); // tell the microcontroller to output a PWM signal on pin P0 set to whatever value 'note' is set to for however long 'duration' is set to

	counter = random(3);
	switch (counter) {
		case 0:
			digitalWrite(rockPin, HIGH);
			delay(duration);
			digitalWrite(rockPin, LOW);
			break;
		case 1:
			digitalWrite(scissorPin, HIGH);
			delay(duration);
			digitalWrite(scissorPin, LOW);
			break;
		case 2:
			digitalWrite(paperPin, HIGH);
			delay(duration);
			digitalWrite(paperPin, LOW);
			break;
	}

	//Stop tone on buzzerPin
	noTone(speakerPin);
	delay(50);
}

void firstSection() { // this is the first little ditty of the Star Wars Imperial March
	beep(a,  500);
	beep(a,  500);
	beep(a,  500);
	beep(f,  350);
	beep(cH, 150);
	beep(a,  500);
	beep(f,  350);
	beep(cH, 150);
	beep(a,  650);

	delay(500);

	beep(eH, 500);
	beep(eH, 500);
	beep(eH, 500);
	beep(fH, 350);
	beep(cH, 150);
	beep(gS, 500);
	beep(f,  350);
	beep(cH, 150);
	beep(a,  650);

	delay(500);
}
