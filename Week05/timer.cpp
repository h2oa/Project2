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
