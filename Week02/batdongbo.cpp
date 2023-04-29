const int ledAutoPin = 4; // led bật tắt tự động
const int buttonPin = 6;
const int ledButtonPin = 8; // led bật tắt theo button

int buttonState = 0; // trạng thái button
int ledAutoState = 0; // trạng thái của đèn led tự động
unsigned long oldTime = 0;

void setup() {
    pinMode(ledAutoPin, OUTPUT);
    pinMode(ledButtonPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // bất đồng bộ cần xử lý
    // digitalWrite(ledAutoPin, HIGH);
    // delay(3000);
    // digitalWrite(ledAutoPin, LOW);
    // delay(3000);
    
    // ledAutoState = digitalRead(ledAutoPin);
    if ((unsigned long)(millis() - oldTime) > 3000) {
        if (digitalRead(ledAutoPin) == LOW) {
            digitalWrite(ledAutoPin, HIGH);
        } else {
            digitalWrite(ledAutoPin, LOW);
        }
        oldTime = millis();
    }

    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        digitalWrite(ledButtonPin, HIGH);
    } else {
        digitalWrite(ledButtonPin, LOW);
    }
}
