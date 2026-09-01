class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        
        // Theo đề bài, phần tử cuối cùng luôn bị thay bằng -1
        // Mình dùng biến rightMax này để lưu "kỷ lục" số lớn nhất bên phải
        int rightMax = -1; 
        
        // Đi lùi từ cuối mảng lên đầu
        for (int i = n - 1; i >= 0; i--) {
            // Giữ lại số hiện tại nháp ra ngoài, vì lát nữa nó sẽ bị ghi đè mất
            int currentVal = arr[i];
            
            // Ghi đè số hiện tại bằng "kỷ lục" lớn nhất đang giữ
            arr[i] = rightMax;
            
            // So sánh số vừa nháp ra với kỷ lục cũ. 
            // Nếu nó to hơn, nó sẽ thành kỷ lục mới cho các số đứng trước nó.
            // Chú ý: std::max lúc này hoàn toàn hợp lệ vì ta dùng để so 2 số.
            rightMax = max(rightMax, currentVal); 
        }
        
        return arr;
    }
};