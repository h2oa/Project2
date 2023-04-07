void setup()
{
    pinMode(0, OUTPUT); // khai báo các digital pin
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    for (int i = 0; i <= 7; i++) {
        digitalWrite(i, HIGH); // pin i bật
        delay(500); // đợi 500 mili giây
        digitalWrite(i, LOW); // pin i tắt
        delay(500); // đợi 500 mili giây
    }
}
