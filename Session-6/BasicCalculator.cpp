class Solution {
public:
    int calculate(string a) {
        stack<int> s;
        
        int sum = 0;
        int sign = 1;
        for(int i = 0 ; i < a.length() ; i++){
            // a[i] == number
            if(a[i]<='9' and a[i]>='0'){
                int no = 0;
                // "900+10"
                while(i<a.length() and a[i]<='9' and a[i]>='0'){
                    no = 10*no + (a[i] - '0');
                    i++;
                }
                i--;
                sum+=sign*no;
            }
            else if(a[i] == '+'){
            // a[i] == '+'
                sign = 1;    
            }
            else if(a[i] == '-'){
            // a[i] == '-'
                sign = -1;
            }
            else if(a[i] == '('){
            // a[i] == '('
                s.push(sum);
                s.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(a[i] == ')'){
            // a[i] == ')'
                sum = sum*s.top();
                s.pop();
                sum+=s.top();
                s.pop();
            }
            // ignore the spaces
        }
        return sum;
    }
};