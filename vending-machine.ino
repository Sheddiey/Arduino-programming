#include <Key.h>
#include <Keypad.h>
#include <SoftwareSerial.h>
#include <keypad.h>

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 3; //three columns

char keys[ROW_NUM] [COLUMN_NUM] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
  Serial.println("Press 1 for Meyer Lemon");
  Serial.println("Press 2 for Fino Lemon");
  Serial.println("Press 3 for Primofiori Lemon");
  delay(1000);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}


void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    if (key == '1') {
      digitalWrite(13, HIGH);
      delay(2000);
      digitalWrite(13, LOW);
      delay(2000);
    }

    if (key == '2') {
      digitalWrite(12, HIGH);
      delay(2000);
      digitalWrite(12, LOW);
      delay(2000);
    }

    if (key == '3') {
      digitalWrite(11, HIGH);
      delay(2000);
      digitalWrite(11, LOW);
      delay(2000);
    }
  }
}

