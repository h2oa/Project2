#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

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
  int switchState = digitalRead(switchPin); // liên tục kiểm tra trạng thái slideswitch xóa 1 phần tử trong loop
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