# Thao tác với Button trong Arduino

## I. Cấu tạo

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

- Chân âm của đèn led nối với GND (nối đất).
- Chân dương của đèn led nối với điện trở và nối với pin 12.
- 1 chân của button nối với điện trở và nối đất, nối tiếp chân này vào pin 2.
- Chân ở cặp còn lại của button nối với nguồn 5V.

### 3. Chương trình

https://github.com/lengochoahust/Project2/blob/main/Week2/button.cpp
