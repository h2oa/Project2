# Ví dụ với các hàm trong thư viện Keypad.h

## 1. Khởi tạo

- Keypad(makeKeymap(userKeymap), row[], col[], rows, cols)

```cpp
#include <Adafruit_LiquidCrystal.h>
#include <Wire.h> 
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
```

## 2. char waitForKey()

```cpp
#include <Keypad.h>

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

char waitForKey() {
  char key = keypad.getKey();
  
  while (!key) {
    key = keypad.getKey();
  }
  
  return key;
}

void setup() {
  // Khởi tạo và cài đặt các thiết lập ban đầu
  
}

void loop() {
  // Code xử lý
  
  char pressedKey = waitForKey();
  // Thực hiện các xử lý với phím đã nhấn
  
  // Code xử lý khác
  
}
```

## 3. char getKey()

```cpp
#include <Keypad.h>

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

void setup() {
  // Khởi tạo và cài đặt các thiết lập ban đầu
  
}

void loop() {
  // Code xử lý
  
  char pressedKey = keypad.getKey();
  
  if (pressedKey) {
    // Xử lý khi có phím được nhấn
    
    // In giá trị phím lên Serial Monitor
    Serial.println(pressedKey);
  }
  
  // Code xử lý khác
  
}
```

## 4. boolean keyStateChanged()

```cpp
#include <Keypad.h>

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

char previousKey = '\0'; // Biến lưu trữ giá trị phím trước đó

boolean keyStateChanged() {
  char currentKey = keypad.getKey();
  
  if (currentKey != previousKey) {
    previousKey = currentKey;
    return true; // Trạng thái của phím đã thay đổi
  }
  
  return false; // Trạng thái của phím không thay đổi
}

void setup() {
  // Khởi tạo và cài đặt các thiết lập ban đầu
  
}

void loop() {
  // Code xử lý
  
  if (keyStateChanged()) {
    // Trạng thái của phím đã thay đổi
    
    char pressedKey = keypad.getKey();
    // Xử lý với giá trị phím mới
    
    // In giá trị phím lên Serial Monitor
    Serial.println(pressedKey);
  }
  
  // Code xử lý khác
  
}
```

## 5. setHoldTime(unsigned int time)

```cpp
#include <Keypad.h>

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

void setup() {
  // Khởi tạo và cài đặt các thiết lập ban đầu
  keypad.setHoldTime(1000); // Thiết lập thời gian giữ phím là 1000ms (1 giây)
}

void loop() {
  // Code xử lý
  
  char pressedKey = keypad.getKey();
  
  if (pressedKey) {
    if (keypad.keyStateChanged()) {
      // Phím được nhấn hoặc trạng thái phím đã thay đổi
      
      if (keypad.getState() == HOLD) {
        // Phím đang được giữ
        // Xử lý khi phím đang giữ
      } else if (keypad.getState() == PRESSED) {
        // Phím vừa được nhấn
        // Xử lý khi phím vừa được nhấn
      } else if (keypad.getState() == RELEASED) {
        // Phím vừa được thả
        // Xử lý khi phím vừa được thả
      } else if (keypad.getState() == IDLE) {
        // Trạng thái IDLE
      }
    }
  }
  
  // Code xử lý khác
  
}
```
