class Solution {
private:
    void recursiveSolution(string digits, vector<string> &ans, string output, string mapping[], int index){

        //base case 
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        //now mapp the letter with character
        int numbers = digits[index] - '0';

        //to make thet number to character
        string value = mapping[numbers];

        //to continue this again and again use loop
        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            recursiveSolution(digits, ans, output, mapping, index + 1);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        
        //ans a vector which will atore ans's value
        vector<string> ans;
        
        //to check that string is empty
        if(digits.empty()){
            return ans;
        }

        //output string which will helps in mapping
        string output = "";

        //now starts actual mapping of numbers with letters
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int index = 0;

        //now function call
        recursiveSolution(digits, ans, output, mapping, index);

        return ans;
    }
};