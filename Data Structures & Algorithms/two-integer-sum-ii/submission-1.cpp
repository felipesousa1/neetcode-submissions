class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while (i < j){
            int soma = numbers[i] + numbers[j];
            if (soma == target){
                return {i+1, j+1};
            }
            else if (soma < target){
                i++;
            }
            else j--;
        }
    }

};
