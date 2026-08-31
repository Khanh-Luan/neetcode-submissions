class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Cuốn sổ phân loại: 
        // - "Khóa" (Key) là chuỗi đã sắp xếp ABC.
        // - "Giá trị" (Value) là 1 mảng chứa các chữ gốc chưa sắp xếp.
        unordered_map<string, vector<string>> res;
        
        // Bốc từng chữ s trong mảng strs ra để kiểm tra
        for (const auto& s : strs) {
            // Copy ra 1 bản nháp để lát đem đi sắp xếp (phải giữ lại bản gốc s để cuối cùng còn trả về)
            string sortedS = s;
            
            // Xếp chữ trong bản nháp theo bảng chữ cái. VD: "eat", "tea", "ate" -> Xếp xong đều thành "aet"
            sort(sortedS.begin(), sortedS.end());
            
            // Lấy chữ nháp "aet" làm thẻ tên, nhét chữ gốc s vào nhóm đó.
            // (Nếu nhóm "aet" chưa có, nó tự tạo mới. Nếu có rồi thì nó nối đuôi thêm vào).
            res[sortedS].push_back(s);
        }
        
        // Tạo cái rổ to (mảng 2 chiều) để gom kết quả đem nộp
        vector<vector<string>> result;
        
        // Duyệt qua từng nhóm đã chia trong cuốn sổ res ở trên
        for (auto& pair : res) {
            // pair.first là cái thẻ tên (VD: "aet")
            // pair.second là nguyên cái mảng chứa các chữ gốc (VD: ["eat", "tea", "ate"])
            // Mình chỉ cần lấy cái mảng chữ gốc (pair.second) ném vào rổ kết quả
            result.push_back(pair.second);
        }
        
        // Nộp bài!
        return result;
    }
};
