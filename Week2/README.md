# Thao tác với Button trong Arduino

## I. Cấu tạo

![image](https://user-images.githubusercontent.com/114990730/231932871-01b147f2-907e-43a6-8905-80b8a2c4d2c6.png)

Gồm 4 chân, chia thành 2 cặp (A-B, C-D).

- Hai chân cùng cặp được nối với nhau.
- Hai chân khác cặp không được nối với nhau.
- Khi nhấn nút, cả 4 chân được nối với nhau, cho phép dòng điện đi từ một chân bất kỳ đến các chân còn lại.

## II. Bật tắt đèn led với button.

### 1. Phần cứng

- 1 Arduino Uno R3.
- 1 Breadboard Small.
- 1 đèn led.
- 2 điện trở 220 ôm.
- 1 button.

### 2. Mô tả lắp đặt

![image](https://user-images.githubusercontent.com/114990730/231933013-7d8a9e93-c5c7-41f2-a484-b69e2b92c51f.png)

- Chân âm của đèn led nối với GND (nối đất).
- Chân dương của đèn led nối với điện trở và nối với pin 12.
- 1 chân của button nối với điện trở và nối đất, nối tiếp chân này vào pin 2.
- Chân ở cặp còn lại của button nối với nguồn 5V.

### 3. Chương trình

```
// https://github.com/lengochoahust/Project2/blob/main/Week2/button.cpp
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
```

# Xử lý bất đồng bộ trong Arduino

## I. Bài toán

Dùng Arduino điều khiển 2 đèn LED, trong đó 1 đèn LED bật tắt tự động sau 3 giây, còn 1 đèn LED được điều khiển bằng button.

## II. Giải quyết

### 1. Phần cứng

- 1 Arduino Uno R3.
- 1 Breadboard Small.
- 2 đèn led.
- 3 điện trở 220 ôm.
- 1 button.

### 2. Mô tả lắp đặt

![image](https://user-images.githubusercontent.com/114990730/232051630-c28cde39-a6ae-45d7-b606-aaf98a3ba2e3.png)

- Led 1 (Tự động bật tắt): Chân âm nối đất, chân dương nối với điện trở và nối vào pin 8.
- Led 2 (Bật tắt qua button): Chân âm nối đất, chân dương nối với điện trở và nối vào pin 4.
- Button: 1 chân nối với điện trở và nối đất, đồng thời nối với pin 6; 1 chân trong cặp còn lại nối vào nguồn 5V.

### 3. Chương trình

Đoạn chương trình sau xuất hiện vấn đề bất đồng bộ:

```
const int ledAutoPin = 4; // led bật tắt tự động
const int buttonPin = 6;
const int ledButtonPin = 8; // led bật tắt theo button

int buttonState = 0; // trạng thái button

void setup() {
    pinMode(ledAutoPin, OUTPUT);
    pinMode(ledButtonPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    // bất đồng bộ cần xử lý
    digitalWrite(ledAutoPin, HIGH);
    delay(3000);
    digitalWrite(ledAutoPin, LOW);
    delay(3000);

    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        digitalWrite(ledButtonPin, HIGH);
    } else {
        digitalWrite(ledButtonPin, LOW);
    }
}
```

Lý do là vì khi sử dụng hàm `delay()` sẽ khiến chương trình ở trạng thái dừng hoạt động xử lý, nên dù nhấn button thì arduino cũng không nhận được tín hiệu bật tắt.

Xử lý:

- Không sử dụng hàm `delay()`.
- Thay vào đó, sử dụng hàm `millis()` chỉ thời điểm hiện tại để xử lý khoảng thời gian 3s sẽ bật tắt đèn led tự động.

Chương trình hoạt động:

```
// 
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
```
