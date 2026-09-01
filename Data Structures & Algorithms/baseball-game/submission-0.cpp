class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        // vector<int> stack:
        // Tạo một vector để lưu các điểm hợp lệ.
        // Ta dùng vector này giống như một STACK (ngăn xếp).
        vector<int> stack;

        for (const string& op : operations) {

            if (op == "+") {

                // .back()
                // Lấy phần tử CUỐI CÙNG trong vector.
                //
                // Ví dụ:
                // stack = {5, 10}
                // stack.back() -> 10
                int top = stack.back();


                // .pop_back()
                // XÓA phần tử CUỐI CÙNG trong vector.
                //
                // Trước: {5, 10}
                // Sau:   {5}
                stack.pop_back();


                // Lấy phần tử cuối hiện tại (10 đã bị xóa nên còn 5)
                // rồi cộng với top (10)
                //
                // newTop = 10 + 5 = 15
                int newTop = top + stack.back();


                // .push_back(x)
                // THÊM x vào CUỐI vector.
                //
                // stack đang là {5}
                // thêm 10 -> {5, 10}
                stack.push_back(top);


                // Thêm điểm mới vào cuối
                //
                // {5, 10} -> {5, 10, 15}
                stack.push_back(newTop);


            } else if (op == "D") {

                // .back()
                // Lấy phần tử cuối cùng.
                //
                // Ví dụ:
                // stack = {5, 10}
                // stack.back() = 10
                //
                // 2 * 10 = 20
                //
                // .push_back()
                // thêm 20 vào cuối:
                // {5, 10, 20}
                stack.push_back(2 * stack.back());


            } else if (op == "C") {

                // .pop_back()
                // Xóa phần tử cuối cùng.
                //
                // Ví dụ:
                // stack = {5, 10, 20}
                // sau pop_back():
                // stack = {5, 10}
                stack.pop_back();


            } else {

                // op là một chuỗi số, ví dụ:
                // "5", "-3", "10"
                //
                // stoi() = string to integer
                // Chuyển chuỗi thành số nguyên.
                //
                // stoi("5")   -> 5
                // stoi("-3")  -> -3
                // stoi("100") -> 100
                //
                // Sau đó push_back() thêm số đó vào stack.
                stack.push_back(stoi(op));
            }
        }


        // accumulate()
        // Tính TỔNG tất cả phần tử trong một khoảng.
        //
        // accumulate(stack.begin(), stack.end(), 0)
        //
        // stack.begin() -> vị trí bắt đầu
        // stack.end()   -> vị trí kết thúc
        // 0             -> giá trị ban đầu của tổng
        //
        // Ví dụ:
        // stack = {5, 10, 15}
        //
        // accumulate(...) = 0 + 5 + 10 + 15
        //                   = 30
        //
        // => return 30
        return accumulate(stack.begin(), stack.end(), 0);
    }
};