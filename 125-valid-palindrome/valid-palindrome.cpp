class Solution {
public:

    //to check that letter is valid or not
    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }

    //now convert into lower case
    int toLower(char ch){
        if(ch >= 'a' && ch <= 'z'){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    //now check that string is palindrome or not
    bool checkPlaindrome(string s){
        int start = 0;
        int end = s.length() - 1;
        while(start <= end){
            if(s[start] != s[end]){
                return 0;
            }
            else{
                start++;
                end--;
            }
        }
        return 1;
    }


    //check that the string is palindrome or not
    bool isPalindrome(string s) {
        //create an empty string
        string temp = "";

        for(int i = 0; i < s.length(); i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }

        for(int i = 0; i < temp.length(); i++){
            temp[i] = toLower(temp[i]);
        }

        return checkPlaindrome(temp);
    }
};