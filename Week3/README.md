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

## II. Giao tiếp với LCD của Arduino

### 1. Phần cứng

- 1 Arduino UNO R3
- 1 màn hình LCD
- 1 công tắc trượt (slideswitch)
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
