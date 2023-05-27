# I. Cấu tạo keypad 4x4

![image](https://github.com/lengochoahust/Project2/assets/114990730/75205dc4-6a77-4bc2-a388-78f9ec42d50f)

Với 16 nút bấm nhưng keypad chỉ cần sử dụng 8 chân nối đại diện cho 4 hàng và 4 cột (R1-R4, C1-C4).

Để kiểm tra một nút có được nhấn hay không, keypad sử dụng phương pháp quét được mô tả bằng đoạn mã giả như sau:

Với mỗi hàng (R1 đến R4), Chọn ra hàng Ri

- Cấp cực âm (0v) cho hàng Ri
- Nếu điện áp ở chân Cj bất kì là dương (INPUT PULLUP) => chưa nhấn
- Nếu điện áp ở chân Cj bất kì là âm (INPUT PULLUP) => đang nhấn

# II. Các hàm trong thư viện Keypad.h

- void begin(makeKeymap(userKeymap)): Khởi tạo internal keymap bằng userKeymap
- char waitForKey(): Hàm này sẽ đợi mãi cho đến khi ai đó nhấn một phím. Lưu ý rằng nó sẽ chặn tất cả các mã khác cho đến khi một phím được nhấn (nghĩa là đèn LED không nhấp nháy, màn hình LCD không cập nhật, ...)
- char getKey(): Trả về phím được nhấn, nếu có. Chức năng này không chặn.
- KeyState getState(): Trả về trạng thái hiện tại của bất kỳ phím nào. 4 trạng thái là IDLE, PRESSED, RELEASED và HOLD.
- boolean keyStateChanged(): Tính năng mới có trong phiên bản 2.0: Cho biết khi nào phím thay đổi từ trạng thái này sang trạng thái khác. Ví dụ: thay vì chỉ kiểm tra phím hợp lệ, có thể kiểm tra thời điểm nhấn phím.
- setHoldTime(unsigned int time): Đặt số lượng mili giây mà người dùng sẽ phải giữ một nút cho đến khi trạng thái HOLD được kích hoạt.
- setDebounceTime(unsigned int time): Đặt số lượng mili giây mà bàn phím sẽ đợi cho đến khi bàn phím chấp nhận một lần nhấn phím/sự kiện phím mới (keypress/keyEvent).
- addEventListener(keypadEvent): Kích hoạt một sự kiện nếu bàn phím được sử dụng.

# IIi. Sơ đồ lắp đặt

|4x4 Keypad|Arduino|
|-|-|
|R1|D9|
|R2|D8|
|R3|D7|
|R4|D6|
|C1|D5|
|C2|D4|
|C3|D3|
|C4|D2|

|I2C LCD Display|Arduino|
|-|-|
|VCC|5V|
|GND|GND|
|SCL|A5|
|SDA|A4|

