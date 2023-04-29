const int buttonPin = 2;
const int ledPin = 12;

int buttonState = 0; // trạng thái của button

void setup() {
    pinMode(buttonPin, INPUT); // INPUT đọc giá trị từ button
    pinMode(ledPin, OUTPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin); // đọc trạng thái button và lưu vào biến buttonState
    if (buttonState == HIGH) { // nếu button được nhấn
        digitalWrite(ledPin, HIGH); // bật đèn led
    } else {
        digitalWrite(ledPin, LOW); // tắt đèn led
    }
}
