#include <DHT.h>
#include <Adafruit_Sensor.h>

#define DHTPIN 2

const int okButton = 3;
const int upButton = 4;
const int leftButton = 5;
const int rightButton = 6;
const int downButton = 7;

float temp;
float hum;
int interOkButton = 2;
int interUpButton = 2;
int interLeftButton = 2;
int interRightButton = 2;
int interDownButton = 2;

DHT dht(DHTPIN, DHT11);
void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(okButton, OUTPUT);
  pinMode(upButton, OUTPUT);
  pinMode(leftButton, OUTPUT);
  pinMode(rightButton, OUTPUT);
  pinMode(downButton, OUTPUT);
}

void loop() 
{
  delay(50);
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  int OkButtonState = digitalRead(okButton);
  int UpButtonState = digitalRead(upButton);
  int LeftButtonState = digitalRead(leftButton);
  int RightButtonState = digitalRead(rightButton);
  int DownButtonState = digitalRead(downButton);


  if (isnan(temp) || isnan(hum))
  {
    Serial.println("Error");
    return;
  }

  // Serial.print("Temperature is: ");
  // Serial.println(temp);
  // Serial.print("Humidity is: ");
  // Serial.println(hum);

  if (OkButtonState != interOkButton)
  {
    Serial.print("Ok ");
    Serial.println(OkButtonState);
  }
  if (UpButtonState != interUpButton)
  {
    Serial.print("Up ");
    Serial.println(UpButtonState);
  }
  if(LeftButtonState != interLeftButton)
  {
    Serial.print("Left ");
    Serial.println(LeftButtonState);
  }
  if(RightButtonState != interRightButton)
  {
    Serial.print("Right ");
    Serial.println(RightButtonState);
  }
  if(DownButtonState != interDownButton)
  {
    Serial.print("Down ");
    Serial.println(DownButtonState);
  }
  interOkButton = OkButtonState;
  interUpButton = UpButtonState;
  interLeftButton = LeftButtonState;
  interRightButton = RightButtonState;
  interDownButton = DownButtonState;
}
