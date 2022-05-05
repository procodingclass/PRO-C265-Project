#include <RTClib.h>

RTC_DS1307 rtc;

int hours, minutes;
byte buzzerPin = 10;

void setup() {

  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

  if (!rtc.begin()) {
    Serial.println("RTC not initialised");
    while (true);
  }
  Serial.println("RTC found");
  Serial.print("Enter the hour for alarm to ring : ");
  while (!Serial.available());
  hours = Serial.readString().toInt();
  Serial.println(hours);

  Serial.print("Enter the minutes for alarm to ring : ");
  while (!Serial.available());
  minutes = Serial.readString().toInt();
  Serial.println(minutes);


}

void loop() {

  //  RTC date and time
  DateTime dt = rtc.now();
  if (hours == dt.hour() && minutes == dt.minute()) {
    //play the buzzer
    // Serial.println("Snooze...");
    for (int j = 0; j < 3; j++) {
      digitalWrite(buzzerPin, HIGH);
      delay(random(2, 10));
      digitalWrite(buzzerPin, LOW);
      delay(4);
    }
  }

  //  for better working of simulator
  delay(70);
}



