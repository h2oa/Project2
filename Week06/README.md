# I. Tổng quan đề tài `Arduino và ứng dụng máy tính cầm tay calculator`.

Ứng dụng mô phỏng một máy tính cầm tay calculator thực hiện các phép tính cộng, trừ, nhân, chia (dự kiến trong phạm vi nhỏ hơn 100).

# II. Thiết bị phần cứng chuẩn bị

- 1 Arduino UNO R3.
- 1 Keypad 4x4.
- 1 LCD 16X2 I2C.
- Các dây nối.

# III. Mô tả chức năng sử dụng các thiết bị phần cứng

## 1. Keypad 4x4

![image](https://github.com/lengochoahust/Project2/assets/114990730/19a9027a-8570-41d4-929f-5f076fe6f6f9)

Ngoài các phím số, các phím A, B, C, D, \*, # có chức năng:

|Phím|Chức năng đại diện|
|-|-|
|A|Cộng|
|B|Trừ|
|\*|Nhân|
|D|Chia|
|C|Xóa|
|#|Bằng (hiện kết quả)|

## 2. Màn hình LCD 16x2 I2C

![image](https://github.com/lengochoahust/Project2/assets/114990730/84d2c4a2-984a-43af-bc23-1442434951c5)

Hiển thị số, phép tính và kết quả

# IV. Chức năng yêu cầu

## 1. Thực hiện chức năng nhập xuất đối với keypad 4x4

Trong ứng dụng này, keypad đóng vai trò thiết bị nhập.

Chương trình yêu cầu các chữ số nhập vào bằng keypad sẽ hiển thị dưới dạng chuỗi số trên màn hình LCD.

## 2. Xử lý số liệu ban đầu

Chương trình cần cho phép Arduino nhận dạng được phép tính chúng ta nhập vào tương ứng với phép tính nào trong Cộng, Trừ, Nhân, Chia, khi nào thì thực hiện phép tính và in ra kết quả.

## 3. Tính toán số liệu

Sau khi xác định các số cần tính toán cũng như loại phép tính cần thực hiện, chương trình yêu cầu bước tính toán số liệu tương ứng với từng loại phép tính Cộng, Trừ, Nhân, Chia.

## 4. Xóa dữ liệu

Sau khi thực hiện tính toán và trả về kết quả, chúng ta mong muốn thực hiện phép tính mới. Lúc này cần thực hiện việc xóa (giải phóng) dữ liệu, bởi chúng ta không mong muốn các số liệu cũ có thể gây ra khó khăn đối với số liệu mới.

Chương trình yêu cầu Arduino thực hiện xóa dữ liệu khi người dùng bấm nút C trên keypad.
