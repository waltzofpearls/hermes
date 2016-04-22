String readString;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hi There!");
  delay(1000);

  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill 
    if (Serial.available() > 0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    } 
  }

  if (readString.length() > 0) {
    Serial.println(readString);
  }

  readString = "";
}
