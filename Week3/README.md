# Tương tác Arduino với màn hình LCD

## I. Cấu tạo màn hình LCD

![image](https://user-images.githubusercontent.com/114990730/232100003-3866e3d7-be67-47ea-afd4-c485fb473d04.png)

- GND: nối đất.
- VCC: cực dương.
- V0 (Constrast Voltage): Điều khiển độ sáng màn hình.
- Register Select (RS): Lựa chọn thanh ghi trong LCD để xử lý chương trình (RS = 0 chọn thanh ghi lệnh, RS = 1 chọn thanh ghi dữ liệu).
- Read/Write (RW): RW = 0 ghi dữ liệu, RW = 1 đọc dữ liệu.
- Enable (E): Cho phép ghi vào LCD.
- DB0 - DB7: 8 chân nhận dữ liệu.
- Backlight Anode (+) và Backlight Cathode (-): Nguồn dương và nguồn âm của đèn màn hình LCD.

## II. 
