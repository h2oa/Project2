# Xây dựng các chương trình con
## I. Demo tương tác bấm nút keypad 4x4 với màn hình hiển thị LCD trong arduino

```cpp
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd(0);

const byte rows = 4; // Số hàng của ma trận keypad
const byte cols = 4; // Số cột của ma trận keypad

char keymap[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, rows, cols);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("START");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lcd.clear(); // Xóa màn hình
    lcd.setCursor(0, 0); // Đặt con trỏ ở hàng đầu tiên, cột đầu tiên
    lcd.print("Key Pressed:"); // In chuỗi "Key Pressed:" lên màn hình LCD
    lcd.setCursor(0, 1); // Đặt con trỏ ở hàng thứ hai, cột đầu tiên
    lcd.print(key); // In giá trị của phím được nhấn lên màn hình LCD
  }
}
```

![image](https://github.com/lengochoahust/Project2/assets/114990730/7447622b-6b4a-4bd8-a675-4fdb437700d9)

## II. Chương trình nhập, xuất

### 1. Cho phép nhập nhiều phím, in ra khi gặp phim # (dấu =)

```cpp
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>
#include <Key.h>

Adafruit_LiquidCrystal lcd(0);
String input = "";

const byte rows = 4; // Số hàng của ma trận keypad
const byte cols = 4; // Số cột của ma trận keypad

char keymap[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, rows, cols);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Start");
  delay(1000);
}

void loop() {
  lcd.clear();
  char key = keypad.getKey();
  if (key != NO_KEY) {
    input = input + String(key);
  }
  if (key == '#') {
    lcd.print(input);
    input = "";
    delay(1000);
  }
}
```

![image](https://github.com/lengochoahust/Project2/assets/114990730/5e29695e-d0c5-4abe-811d-e8cba57a37c3)

### 2. Cải tiến, nhập và in ra song song

```cpp
void loop() {
  char key = keypad.getKey();
  int firstNum, secondNum, answer;
  if (key != NO_KEY && key != '#') { // không lưu dấu # vào input
    input = input + String(key);
    pos++;
    lcd.print(key);
    lcd.setCursor(pos, 0);
  }
}
```

## III. Lấy giá trị từng số hạng và nhận biết phép tính cần thực hiện

```cpp
void loop() {
  lcd.clear();
  char key = keypad.getKey();
  if (key != NO_KEY && key != '#') { // không lưu dấu # vào input
    input = input + String(key);
  }
  if (key == '#') {
    byte length = String(input).length(); // độ dài input
    String num1 = "", num2 = "";
    byte firstNumState = 0, secondNumState = 0, symbolState = 0;
    char symbol;
    for (int i = 0; i < length; i = i + 1) {
      char chr = String(input).charAt(i);
      if (firstNumState == 1 && symbolState == 1) {
        num2 = num2 + chr; // lấy số hạng 2
      }
      if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
        symbol = chr; // lưu dấu phép tính vào symbol
        firstNumState = 1; // báo hiệu đã xong num1
        symbolState = 1; // báo hiệu đã có symbol
      }
      if (firstNumState == 0) {
        num1 = num1 + chr; // lấy số hạng 1
      }
    }
    // in ra số hạng 1
    lcd.setCursor(0, 0);
    lcd.print("Number 1:");
    lcd.setCursor(0, 1);
    lcd.print(num1);
    delay(2000);
    lcd.clear();
    // in ra số hạng 2
    lcd.setCursor(0, 0);
    lcd.print("Number 2:");
    lcd.setCursor(0, 1);
    lcd.print(num2);
    delay(2000);
    lcd.clear();
    // in ra dấu phép tính
    lcd.setCursor(0, 0);
    lcd.print("Symbol:");
    lcd.setCursor(0, 1);
    lcd.print(symbol);
    delay(2000);
    lcd.clear();
    input = ""; // xóa dữ liệu
  }
}
```

## IV. Tính toán phép tính

```cpp
// thực hiện phép tính
switch (symbol)
{
  case '+':
    answer = firstNum + secondNum;
    lcd.setCursor(0, 0);
    lcd.print("Answer:");
    lcd.setCursor(0, 1);
    lcd.print(answer);
    delay(3000);
    break;
  case '-':
    answer = firstNum - secondNum;
    lcd.setCursor(0, 0);
    lcd.print("Answer:");
    lcd.setCursor(0, 1);
    lcd.print(answer);
    delay(3000);
    break;
  case '*':
    answer = firstNum * secondNum;
    lcd.setCursor(0, 0);
    lcd.print("Answer:");
    lcd.setCursor(0, 1);
    lcd.print(answer);
    delay(3000);
    break;
  case '/':
    answer = firstNum / secondNum;
    lcd.setCursor(0, 0);
    lcd.print("Answer:");
    lcd.setCursor(0, 1);
    lcd.print(answer);
    delay(3000);
    break;
}
```

## V. Xóa dữ liệu sau khi thực hiện xong phép tính

```cpp
// xóa dữ liệu
if (key == 'C') {
  lcd.clear();
  input = ""; // xóa dữ liệu
  pos = 0;
}
```

## VI. Chương trình đầy đủ cuối cùng

```cpp
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>
#include <Key.h>

Adafruit_LiquidCrystal lcd(0);
String input = "";
int pos = 0;
const int switchPin = 12, switchClearDataPin = 13;
int oldState = 0;
float firstNum, secondNum, answer;


const byte rows = 4; // Số hàng của ma trận keypad
const byte cols = 4; // Số cột của ma trận keypad

char keymap[rows][cols] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','.'},
  {'*','0','#','/'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, rows, cols);

void setup()
{
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(switchClearDataPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Calculator");
  lcd.setCursor(0, 1);
  lcd.print("Arduino");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (digitalRead(switchClearDataPin) == HIGH) {
    clearData();
  }
  int switchState = digitalRead(switchPin);
  if (switchState != oldState) {
    input = input.substring(0, input.length() - 1);
    oldState = switchState;
    pos = pos - 1;
    lcd.setCursor(pos, 0);
    lcd.print(" ");
    lcd.setCursor(pos, 0);
    cal();
  } else {
    cal();
  }
}

void cal() {
  char key = keypad.getKey();
  if (key != NO_KEY && key != '#') { // không lưu dấu # vào input
    input = input + String(key);
    pos++;
    lcd.print(key);
    lcd.setCursor(pos, 0);
  }
  if (key == '#') {
    byte length = String(input).length(); // độ dài input
    String num1 = "", num2 = "";
    byte firstNumState = 0, secondNumState = 0, symbolState = 0;
    char symbol;
    for (int i = 0; i < (length); i = i + 1) {
      char chr = String(input).charAt(i);
      if (firstNumState == 1 && symbolState == 1) {
        num2 = num2 + chr; // lấy số hạng 2
      }
      if (chr == '+' || chr == '-' || chr == '*' || chr == '/') {
        symbol = chr; // lưu dấu phép tính vào symbol
        firstNumState = 1; // báo hiệu đã xong num1
        symbolState = 1; // báo hiệu đã có symbol
      }
      if (firstNumState == 0) {
        num1 = num1 + chr; // lấy số hạng 1
      }
    }
    // xử lý lấy số hạng
    firstNum = getNum(num1);
    secondNum = getNum(num2);
    // thực hiện phép tính
    switch (symbol) {
      case '+':
        answer = firstNum + secondNum;
        lcd.setCursor(0, 1);
        // lcd.print("Answer:");
        lcd.setCursor(0, 1);
        lcd.print(answer);
        break;
      case '-':
        answer = firstNum - secondNum;
        lcd.setCursor(0, 1);
        // lcd.print("Answer:");
        lcd.setCursor(0, 1);
        lcd.print(answer);
        break;
      case '*':
        answer = firstNum * secondNum;
        lcd.setCursor(0, 1);
        // lcd.print("Answer:");
        lcd.setCursor(0, 1);
        lcd.print(answer);
        break;
      case '/':
      	if (secondNum != 0) {
          answer = firstNum / secondNum;
          lcd.setCursor(0, 1);
          // lcd.print("Answer:");
          lcd.print(answer);
          break;
        } else {
          lcd.setCursor(0, 1);
          lcd.print("Math ERROR!");
          break;
        }
    }
  }
}

// xóa dữ liệu
void clearData() {
  lcd.clear();
  input = "";
  pos = 0;
}

// xử lý lấy số hạng thập phân
float getNum(String str) {
  String naturalPart = "", decimalPart = "";
  byte length = String(str).length();
  byte naturalState = 0;
  for (int i = 0; i < (length); i = i + 1) {
    char chr = String(str).charAt(i);
    if (naturalState == 1) {
      decimalPart = decimalPart + chr; // lấy phần thập phân
    }
    if (chr == '.') {
      naturalState = 1; // báo hiệu đã xong phần nguyên
    }
    if (naturalState == 0) {
      naturalPart = naturalPart + chr; // lấy phần nguyên
    }
  }
  byte count10 = String(decimalPart).length();
  float mul = 1;
  for (int i = 0; i < count10; i++) {
    mul = mul / 10.0;
  }
  float ans;
  ans = (String(naturalPart).toInt() + String(decimalPart).toInt() * mul);
  return ans;
}
```
