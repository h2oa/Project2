int PIN_LED = 13;
int BUTTON_PIN = 2;

// khai báo biến kiểu volatile
// tránh sai số trong quá trình thực hiện ngắt
volatile int status = LOW;

void setup()
{ 
    pinMode(PIN_LED, OUTPUT);
    // Treo chân ngắt 0, chân số 2 lên mức cao.
    digitalWrite(BUTTON_PIN, HIGH);
  	// khai báo ngắt 0, chương trình con changestatus
    attachInterrupt(0, changestatus, CHANGE);
} 

void loop()
{
    digitalWrite(PIN_LED, status);
}

void changestatus()
{ 
    status = !status; // đảo trang thái
}
