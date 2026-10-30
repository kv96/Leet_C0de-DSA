// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//        string temp = "";
//         int i = 0;
        
//         while (i < s.length()) {
//             // Check if the substring ahead matches 'part'
//             if (s.substr(i, part.length()) == part) {
//                 // Skip the index past the matched 'part'
//                 i += part.length(); 
//             } 
//             else {
//                 // No match, safely push the single character
//                 temp.push_back(s[i]);
//                 i++;
//             }
//         }
        
//         // Recursively clean up new 'part' occurrences formed by merged ends
//         if (temp.length() != s.length()) {
//             return removeOccurrences(temp, part);
//         }
        
//         s = temp;
//         return s;
//     }
// };

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }

};