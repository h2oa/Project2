# Arduino và vào ra theo kiểu ngắt với Timer/Counter - bộ định tuyến

## I. Tổng quan về Timer/Counter

Timer/Counter là một trong những ngoại vi hoạt động độc lập và không thể thiếu trong bất kì vi điều khiển nào.

Timer/Counter là một bộ đếm xung clock (có thể là xung nhịp nội bên trong vi điểu khiển hoặc xung clock bên ngoài).

Nó tương tự như việc đếm giờ, thay vì ngồi canh đồng hồ và đếm từng giây thì chúng ta có thể đặt báo thức và làm những công việc khác.

Quá trình hoạt động của Timer/Counter được quản lý bởi thanh ghi, chúng gồm thanh ghi chứa giá trị Timer/Counter đếm được và thanh ghi điều khiển các hoạt động đếm của nó.

## II. Các loại Timer/Counter trong Arduino UNO R3

Chip `ATMega328p` (vi điều khiển của board Arduino Uno) bao gồm các Timer/Counter sau:

- Timer/Counter 0: Là bộ timer 8 bit được sử dụng nhiều trong các hàm delay(), millis(), micros(). Chúng ta nên hạn chế sử dụng bộ timer này vì rất dễ gây ảnh hưởng đến những hàm trên.

- Timer/Counter 1: Là bộ timer 16 bit được sử dụng trong thư viện servo.

- Timer/Counter 2: Là một bộ timer 8 bit tương tự như Timer/Counter 0 và được sử dụng trong hàm tone().

## III. Một số khái niệm cần nắm khi làm việc với Timer/Counter

`BOTTOM`: Giá trị nhỏ nhất mà Timer/Counter có thể đạt được. Mặc định bằng 0.

`MAX`: Giá trị lớn nhất mà thanh ghi giá trị của Timer/Counter có thể chứa được. Tùy thuộc vào độ rộng của thanh ghi giá trị mà chúng ta có được giá trị MAX khác nhau. Ví dụ như Timer/Counter 0 là bộ timer 8 bit tức là giá trị tối đa (MAX) của nó là $2^8 - 1 = 255$ và đối với timer 16 bit là $2^16 - 1 = 65535$.

`TOP`: Giá trị mà khi Timer/Counter đạt đến nó sẽ thay đổi trạng thái, giá trị này phải bé hơn hoặc bằng 255 (đối với timer 8 bit) và 65535 (đối với timer 16 bit).
Ví dụ: Trong Timer/Counter 0 chúng ta sẽ có giá trị MAX là 255, nếu không không thiết lập giá trị TOP thì timer sẽ đếm từ 0 đến 255 và sau đó quay trở lại 0, nếu chúng ta thiết lập giá trị TOP thì timer sẽ đếm từ 0 đến giá trị TOP và quay về 0.

`Ngắt Timer`: Bất cứ khi nào Timer đếm đến giá trị TOP hoặc Timer bị tràn (đếm đến giá trị MAX) thì đều xảy ra ngắt.

## IV. Thư viện `TimerOne`

Thư viện `TimerOne` sẽ sử dụng bộ Timer/Counter 1 (16 bit). Link download: https://github.com/PaulStoffregen/TimerOne

Các hàm cần chú ý trong thư viện:

- `initialize(microseconds)` Khởi động ngắt Timer với một chu kì xác định. Đối số `microseconds` chỉ chu kỳ ngắt của Timer (tính bằng micro giây). Mặc định giá trị microseconds = 1 000 000 tương ứng với 1s.
- `start()`: Khởi động lại Timer sau quá trình thay đổi, chỉnh sửa.
- `startBottom()`: Cho Timer đếm lại từ 0 (giá trị BOTTOM).
- `read()`: Đọc giá trị Timer đếm được ở thời điểm hiện tại.
- `stop()`: Dừng Timer.
- `attachInterrupt()`: Thêm chương trình phục vụ ngắt khi xảy ra sự kiện ngắt Timer.
- `detachInterrupt()`: Hủy hàm ngắt Timer.
- `pwm(pin, duty)`: Xuất xung PWM ra một chân xác định. Các đối số:
 + pin: Lựa chọn chân xuất PWM.
 + duty: Chu kì xung PWM.
- `disablePwm(char pin)`: Hủy băm xung PWM. Đối số: pin: Lựa chọn chân để hủy PWM

## V. Ví dụ điều khiển đèn LED bằng Timer

Bài toán: Sử dụng Timer để điều khiển LED trên board nháy sau mỗi 1s.

```
// https://github.com/lengochoahust/Project2/blob/main/Week05/timer.cpp
#include <TimerOne.h> // Thư viện TimerOne

const int ledPin = 13; // Định nghĩa chân kết nối LED
const long interval = 1000; // Định nghĩa thời gian chờ giữa các lần bật/tắt LED (tính theo mili giây)
boolean ledState = false; // Biến để lưu trạng thái của LED (bật hoặc tắt)

void setup() {
  pinMode(ledPin, OUTPUT); // Thiết lập chân LED là chân xuất tín hiệu
  Timer1.initialize(interval * 1000); // Khởi tạo bộ định thời với thời gian chờ giữa các lần bật/tắt LED
  Timer1.attachInterrupt(timerISR); // Gán hàm xử lý ngắt cho bộ định thời
}

void timerISR() { // Hàm xử lý ngắt bộ định thời
  ledState = !ledState; // Đảo trạng thái của LED
  digitalWrite(ledPin, ledState); // Bật/tắt LED theo trạng thái mới
}

void loop() { // Vòng lặp chính
  // Không làm gì ở đây, việc bật/tắt LED được thực hiện bởi bộ định thời
}
```
