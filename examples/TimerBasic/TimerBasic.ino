#include <ZzzTimer.h>

ZzzTimer timer(5000); //every 5000ms = 5seconds

/** Callback invoked by timer at given interval */
void ding() {
	Serial.print("Timer event: ");
	Serial.print(millis());
	Serial.println();
}

void setup() {
	Serial.begin(115200);
	delay(250); //to ensure correctly initialized

	timer.setCallback(ding);
}

void loop() {
	//call periodically
	timer.update();
}

