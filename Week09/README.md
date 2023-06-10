# I. Demo tương tác bấm nút keypad 4x4 với màn hình hiển thị LCD trong arduino

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

## II. Chương trình cho phép nhập nhiều phím, in ra khi gặp phim # (dấu =)

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


