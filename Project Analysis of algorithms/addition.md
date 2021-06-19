> Bổ sung sau khi thuyết trình tại lớp

**1. Tỉ suất tăng**

- Kích thước đầu vào n nhỏ thì các giải thuật phần lớn đều có 
thời gian thực thi như nhau.
- Nhưng với n → ∞ thì sự khác biệt về thời gian thực thi ngày 
càng rõ. 

**2. Ước lượng độ phức tạp bằng phương pháp cộng**
- Cho 2 chương trình:
  - P1 có thời gian thực hiện T1(n) = O(f1(n))
  - P2 có thời gian thực hiên T2(n) = O(f1(n))
- Quy tắc cộng:
  - Thời gian thực thi P1 và P2 nối tiếp nhau:T(n) = T1(n) + T2(n) = O(max(f1(n),f2(n)))
  - Thời gian thực thi P1 và P2 lồng nhau:T(n) = T1(n) x T2(n) = O(f1(n) x f2(n))
