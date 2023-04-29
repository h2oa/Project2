# Tương tác Arduino với màn hình LCD

## I. Cấu tạo

### 1. Cấu tạo màn hình LCD

![image](https://user-images.githubusercontent.com/114990730/233759270-4bb97e18-5331-42a6-b250-bc7322ffc453.png)

![image](https://user-images.githubusercontent.com/114990730/232100003-3866e3d7-be67-47ea-afd4-c485fb473d04.png)

- GND: nối đất.
- VCC: cực dương.
- V0 (Constrast Voltage): Điều khiển độ sáng màn hình.
- Register Select (RS): Lựa chọn thanh ghi trong LCD để xử lý chương trình (RS = 0 chọn thanh ghi lệnh, RS = 1 chọn thanh ghi dữ liệu).
- Read/Write (RW): RW = 0 ghi dữ liệu, RW = 1 đọc dữ liệu.
- Enable (E): Cho phép ghi vào LCD.
- DB0 - DB7: 8 chân nhận dữ liệu.
- Backlight Anode (+) và Backlight Cathode (-): Nguồn dương và nguồn âm của đèn màn hình LCD.

## II. Giao tiếp với LCD của Arduino (không sử dụng I2C)

### 1. Phần cứng

- 1 Arduino UNO R3
- 1 màn hình LCD
- 1 biến trở.
- 1 breadboard small
- Các dây nối

### 2. Mô tả lắp đặt

![image](https://user-images.githubusercontent.com/114990730/233641689-3420ec20-ca59-4afe-81ba-8b095756578b.png)

- Cấp nguồn dương (5V) vào chân VCC và nguồn âm (nối đất GND) vào chân VCC của màn hình LCD.
- Cấp nguồn dương và nguồn âm vào 2 đèn led của màn hình LCD, đồng thời nối 2 chân led này vào 2 chân tương ứng của slideswitch.
- Kết nối chân V0 của màn hình LCD với slideswitch để điều khiển bật đèn màn hình.
- Chân RW nối với chân GND để ghi dữ liệu vào LCD.
- Nối chân RS và E với 2 chân pin của Arduino để giao tiếp với Arduino. (ở đây dùng pin 11 và 12)
- Điều khiển màn hình LCD ở chế độ 4 bit, kết nối 4 chân DB7, DB6, DB5, DB4 với 4 chân pin của Arduino. (ở đây dùng pin 2, 3, 4, 5)

### 3. Chương trình

Lập trình với màn hình LCD cần sử dụng thư viện `<LiquidCrystal.h>`.

```

```

## III. Module I2C Arduino

LCD có quá nhiều nhiều chân gây khó khăn trong quá trình đấu nối và chiếm dụng nhiều chân trên vi điều khiển. Dẫn đến sự ra đời của Module I2C Arduino.

Thay vì phải mất 6 chân vi điều khiển để kết nối với LCD 16×2 (RS, EN, D7, D6, D5 và D4) thì module IC2 bạn chỉ cần tốn 2 chân (SCL, SDA) để kết nối.

Module I2C hỗ trợ các loại LCD sử dụng driver HD44780(LCD 16×2, LCD 20×4, …) và tương thích với hầu hết các vi điều khiển hiện nay.

Ưu điểm

- Tiết kiệm chân cho vi điều khiển.
- Dễ dàng kết nối với LCD.

Thông số kĩ thuật

- Điện áp hoạt động: 2.5-6V DC.
- Hỗ trợ màn hình: LCD1602,1604,2004 (driver HD44780).
- Giao tiếp: I2C.
- Địa chỉ mặc định: 0X27 (có thể điều chỉnh bằng ngắn mạch chân A0/A1/A2).
- Tích hợp Jump chốt để cung cấp đèn cho LCD hoặc ngắt.
- Tích hợp biến trở xoay điều chỉnh độ tương phản cho LCD.

## IV. Giao tiếp với LCD của Arduino (sử dụng I2C)

![image](https://user-images.githubusercontent.com/114990730/233786247-611acf6e-51c9-435d-8eab-7bcb94acd810.png)

### 1. Phần cứng

- 1 Arduino UNO R3
- 1 màn hình LCD kèm I2C
- Các dây nối

### 2. Sơ đồ lắp đặt

![image](https://user-images.githubusercontent.com/114990730/233791014-cfacdbdb-38b1-4654-99f7-1275c1f4c6a4.png)

### 3. Chương trình

```
// https://github.com/lengochoahust/Project2/blob/main/Week3/lcd_i2c.cpp
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
    lcd.begin(16, 2);
    lcd.print("hello world");
}

void loop()
{
    lcd.setCursor(0, 1);
    lcd.print(seconds);
    delay(1000); // Wait for 500 millisecond(s)
    seconds += 1;
}
```
