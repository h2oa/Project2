# Arduino và vào ra theo kiểu ngắt với button

## I. Vì sao cần ngắt?

Ở ví dụ về button trong các tuần trước, em đã tìm hiểu và lập trình vào ra theo kiểu "thăm dò liên tục" - tức là liên tục đọc trạng thái của button để thực hiện công việc bằng hàm `digitRead()`.

Điều này sẽ gây ra nhiều khó khăn khi số lượng lệnh trong vòng lặp `loop()` tăng lên do chương trình phải thực hiện hết các lệnh rồi lại thêm đợi chờ tín hiệu button từ chúng ta.

## II. Các loại ngắt và sơ đồ ngắt với button trong Arduino UNO

Trong Arduino UNO, chúng ta được hỗ trợ 2 loại ngắt như sau:

- Ngắt số 0 được nối với chân số 2.
- Ngắt số 1 được nối với chân số 3.

Để sử dụng ngắt chúng ta cần phải kết nối nút nhấn hoặc cảm biến vào hai chân này để tạo tín hiệu ngắt cho bộ xử lý. Sơ đồ:

![image](https://user-images.githubusercontent.com/114990730/235280238-b2500583-9862-42af-b8bd-8014ad2b1efd.png)

## III. Hàm `attachInterrupt()` và `detachInterrupt()`

### 1. `attachInterrupt()`

Khai báo 1 ngắt.

Cú pháp: `attachInterrupt(interrupt, ISR, mode)`

Các tham số:

- `interrupt`: Lựa chọn ngắt muốn dùng, với Arduino Uno có 2 lựa chọn là:

```
0: Ứng với ngắt số 0 trong Arduino (chân số 2).
1: Ứng với ngắt số 1 trong Arduino (chân số 3).
```

- `ISR`: Chương trình phục vụ ngắt. Chương trình này sẽ được thực hiện khi có ngắt xảy ra.

- `mode`: Kiểu kích hoạt ngắt:

```
LOW: Ngắt sẽ được kích hoạt khi trạng thái chân ở mức thấp.
HIGH: Ngắt sẽ được kích hoạt khi trạng thái chân ở mức cao.
CHANGE: Ngắt khi có sự thay đổi trạng thái trên chân ngắt (trạng thái thay đổi từ mức điện áp thấp lên mức điện áp cao hoặc ngược lại, từ mức điện áp cao xuống mức điện áp thấp.
RISING: Ngắt sẽ được kích hoạt khi trạng thái của chân digital chuyển từ mức điện áp thấp sang mức điện áp cao.
FALLING: Ngắt sẽ được kích hoạt khi trạng thái của chân digital chuyển từ mức điện áp cao sang mức điện áp thấp.
```

- Giá trị trả về: Không có giá trị trả về

### 2. `detachInterrupt()`

- Mục đích: Tắt ngắt hiện tại.

- Cú pháp: `detachInterrupt(pin)`

- Các tham số:

```
pin: Lựa chọn ngắt mà bạn muốn tắt, dùng board Arduino Uno có 2 lựa chọn là:
0: Tắt ngắt số 0 trong Arduino (chân số 2).
1: Tắt ngắt số 1 trong Arduino (chân số 3).
```

- Giá trị trả về : Không có giá trị trả về.

## IV. Chương trình

Đoạn chương trình dưới đây sẽ làm sáng đèn led khi không nhấn nút và làm đèn led tắt đi khi người dùng nhấn nút, nếu vẫn giữ nút nhấn thì đèn led vẫn còn tắt. Sau khi thả nút nhấn, đèn led sẽ sáng trở lại.

```
int PIN_LED = 13;
int BUTTON_PIN = 2;

// khai báo biến kiểu volatile
// tránh sai số trong quá trình thực hiện ngắt
volatile int status = LOW;

void setup()
{ 
    pinMode(PIN_LED, OUTPUT);
    // Treo chân ngắt 0, chân số 2 lên mức cao.
    digitalWrite(BUTTON_PIN, HIGH);
  	// khai báo ngắt 0, chương trình con changestatus
    attachInterrupt(0, changestatus, CHANGE);
} 

void loop()
{
    digitalWrite(PIN_LED, status);
}

void changestatus()
{ 
    status = !status; // đảo trang thái
}
```
