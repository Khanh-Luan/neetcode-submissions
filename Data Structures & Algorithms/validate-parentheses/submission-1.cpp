class Solution {
public:
    bool isValid(string s) {

        // Lặp liên tục để tìm và xóa các cặp ngoặc hợp lệ
        // (), {}, []
        while (true) {

            // pos dùng để lưu vị trí tìm thấy cặp ngoặc
            //
            // string::npos:
            // - Là giá trị đặc biệt có nghĩa là "KHÔNG TÌM THẤY"
            // - Ví dụ: s.find("()") == string::npos
            //   => trong chuỗi s không có "()"
            size_t pos = string::npos;


            // =================================================
            // 1. TÌM CẶP NGOẶC ()
            // =================================================

            // s.find("()"):
            // Tìm chuỗi con "()" bên trong chuỗi s
            //
            // Nếu tìm thấy:
            //     trả về vị trí bắt đầu của "()"
            //
            // Nếu không tìm thấy:
            //     trả về string::npos
            if ((pos = s.find("()")) != string::npos) {

                // s.erase(pos, 2):
                // Xóa 2 ký tự bắt đầu từ vị trí pos
                //
                // Ví dụ:
                // s = "([])"
                // pos = 1
                //
                // Xóa "[]" hoặc "()" tùy trường hợp
                //
                // Với "()":
                // s = "(())"
                // tìm "()" ở vị trí 1
                // erase(1, 2)
                // => s = "()"
                s.erase(pos, 2);

                // Đã xóa được một cặp ngoặc
                // => quay lại đầu vòng while để tìm tiếp
                continue;
            }


            // =================================================
            // 2. TÌM CẶP NGOẶC {}
            // =================================================

            // Tìm chuỗi con "{}" trong s
            if ((pos = s.find("{}")) != string::npos) {

                // Xóa 2 ký tự "{}"
                // bắt đầu tại vị trí pos
                s.erase(pos, 2);

                // Quay lại đầu vòng while
                // để tiếp tục tìm các cặp ngoặc khác
                continue;
            }


            // =================================================
            // 3. TÌM CẶP NGOẶC []
            // =================================================

            // Tìm chuỗi con "[]" trong s
            if ((pos = s.find("[]")) != string::npos) {

                // Xóa 2 ký tự "[]"
                s.erase(pos, 2);

                // Tiếp tục kiểm tra chuỗi sau khi xóa
                continue;
            }


            // =================================================
            // 4. KHÔNG CÒN CẶP NGOẶC NÀO ĐỂ XÓA
            // =================================================

            // Nếu chương trình chạy đến đây:
            // - Không tìm thấy "()"
            // - Không tìm thấy "{}"
            // - Không tìm thấy "[]"
            //
            // => thoát vòng while
            break;
        }


        // Nếu sau khi xóa tất cả các cặp ngoặc hợp lệ
        // mà chuỗi trở thành chuỗi rỗng ""
        // => tất cả ngoặc đều hợp lệ
        //
        // s.empty():
        // - true  nếu s không còn ký tự nào
        // - false nếu s vẫn còn ký tự
        return s.empty();
    }
};

