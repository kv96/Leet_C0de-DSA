class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string str1 = "";
        string str2 = "";
        for(int i = 0 ; i < num1.size() - 1 ; i++)
        {
            str1 += num1[i];
        }
        for(int i = 0 ; i < num2.size() - 1 ; i++)
        {
            str2 += num2[i];
        }
        string a1 , b1 , a2 , b2;
        int j;
        for(int i = 0 ; i < str1.size() ; i++)
        {
            if(str1[i] == '+')
            {
                j = i;
                break;
            }
            a1 += str1[i];
        }
        for(int i = j+1 ; i < str1.size() ; i++)
        {
            b1 += str1[i];
        }
        int k;
        for(int i = 0 ; i < str2.size() ; i++)
        {
            if(str2[i] == '+')
            {
                k = i;
                break;
            }
            a2 += str2[i];
        }
        for(int i = k+1 ; i < str2.size() ; i++)
        {
            b2 += str2[i];
        }
        int na1 = 0 , nb1 = 0 , na2 = 0 , nb2 = 0;
        int p1 = 1;
        int l4 = (a1[0] == '-') ? 1 : 0;
        for(int i = a1.size()-1 ; i >= l4 ; i--)
        {
            na1 = (a1[i] - '0') * p1 + na1;
            p1 *= 10;
        }
        int p2 = 1;
        int l3 = (a2[0] == '-') ? 1 : 0;
        for(int i = a2.size()-1 ; i >= l3 ; i--)
        {
            na2 = (a2[i] - '0') * p2 + na2;
            p2 *= 10;
        }
        int p3 = 1;
        int l1 = (b2[0] == '-') ? 1 : 0;
        for(int i = b2.size() - 1 ; i >= l1 ;i--)
        {
            nb2 = (b2[i] - '0') * p3 + nb2;
            p3 *= 10;
        }
        int p4 = 1;
        int l2 = (b1[0] == '-') ? 1 : 0;
        for(int i = b1.size() - 1 ; i >= l2 ;i--)
        {
            nb1 = (b1[i] - '0') * p4 + nb1;
            p4 *= 10;
        }
        string result = "";
        
        if(b1[0] == '-')
            nb1 = -1 * nb1;
        if(b2[0] == '-') 
            nb2 = -1 * nb2;
        if(a1[0] == '-')
            na1 = -1 * na1;
        if(a2[0] == '-') 
            na2 = -1 * na2;
        int real = (na1 * na2) - (nb1 * nb2);
        int img = (nb1 * na2) + (na1 * nb2);
        result = to_string(real) + "+" + to_string(img) + "i";
        return result;

    }
};