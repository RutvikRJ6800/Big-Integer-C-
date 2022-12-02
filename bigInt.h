#include <iostream>
using namespace std;

string * array;
string * temparray;
string * stringStack;



char stack[3000];
int top=-1;
int stop=-1;

bool isempty(){
    if(top==-1)return true;
    else return false;
}
int getPrecedence(char c){
    if(c=='x')return 3;
    else if(c=='+')return 2;
    else return 2;
}

int push(char a){
    if(top==2999){
        return -1;
    }
    else{
        stack[++top]=a;
    }
    return 1;
}

int pop(){
    if(top==-1)return -1;
    else{
        top--;
        return 1;
    }
}

// string stack function
bool isEMPTY(){
    if(stop==-1)return true;
    else return false;
}

int PUSH(string a){
    if(stop==2999){
        return -1;
    }
    else{
        stringStack[++stop]=a;
    }
    return 1;
}

int POP(){
    if(stop==-1)return -1;
    else{
        stop--;
        return 1;
    }
}

void reverse(string &s){
    int j=s.size()-1;
    for(int i=0; i<j; i++){
        char tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        j--;
    }
}

string sub(string s1, string s2){
    int n1=s1.size();
    int n2=s2.size();

    string res="";
    if(n1==n2){
        int carry=0;
        for(int i=n1-1; i>=0; i--){
            int diff=(s1[i]-'0')-(s2[i]-'0') - carry;
            if(diff<0){
                diff = 10+diff;
                carry=1;
            }
            else
            carry=0;
            res.push_back(diff+'0'); 
        }
    }
    else{
        int d=n1-n2, carry=0;
        for(int i=n2-1; i>=0; i--){
            int diff=((s1[i+d]-'0')-(s2[i]-'0')) - carry;
            if(diff<0){
                diff = 10+diff;
                carry=1;
            }
            else
            carry=0;
            res.push_back(diff+'0'); 
        }

        for(int i=d-1; i>=0; i--){
           if(s1[i]=='0' && carry){
            res.push_back('9');
            continue;
           }
           int diff=(s1[i]-'0')-carry;
           if(i>0 || diff > 0){
               res.push_back(diff+'0');
           }
           carry=0;
        }
    }
    reverse(res);
    int i;
    for(i=0; i<res.size(); i++){
        if(res[i]!='0')break;
    }
    if(i==res.size())return "0";
    else if(i!=0){
        string newRes="";
        while(i<res.size()){
            newRes+=res[i];
            i++;
        }
        return newRes;
    }
    return res;
}

string add(string s1, string s2){
    if(s1.size()>s2.size()){
        s1.swap(s2);
    }

    int n1=s1.size();
    int n2=s2.size();
    int diff=n2-n1, carry=0;
    
    string res="";
    for(int i=n1-1; i>=0; i--){
        int sum=(s1[i]-'0')+(s2[i+diff]-'0')+carry;
        res.push_back(sum%10 + '0');
        carry=sum/10;
    }
    for(int i=diff-1; i>=0; i--){
        int sum=((s2[i]-'0')+carry);
        res.push_back(sum%10 + '0');
        carry=sum/10;
    }
    if(carry)res.push_back((carry+'0'));
    reverse(res);
    int i;
    for(i=0; i<res.size(); i++){
        if(res[i]!='0')break;
    }
    if(i==res.size())return "0";
    else if(i!=0){
        string newRes="";
        while(i<res.size()){
            newRes+=res[i];
            i++;
        }
        return newRes;
    }
    return res;

}

string multiplication(string s1, string s2){
    int n1=s1.size();
    int n2=s2.size();

    string ans="0";

    int appendzeros=0;
    for(int i=n2-1; i>=0; i--){
        string temp="";
        int carry=0;
        int multiplier=s2[i]-'0';

        for(int j=n1-1; j>=0; j--){
            int tempresult = (multiplier * (s1[j]-'0')) + carry;
            temp+=((tempresult%10)+'0');
            carry=tempresult/10;
        }

        if(carry)temp+=(carry+'0');
        reverse(temp);
        int tmpzero=appendzeros;
        appendzeros++;
        while(tmpzero--){
            temp+='0';
        }
        ans = add(ans,temp);
    }
    return ans;
}

bool lessT(string a,string b){
    int na=a.size(), nb=b.size();
    if(na<nb){return true;}
    else if(na>nb) return false;
    else{
        // a and b are of equal size
        int idx=0;
        while(idx < na){
            if(a[idx]<b[idx])return true;
            else if(a[idx]>b[idx])return false;
            idx++;
        }
        return false;
    }
}
 
bool isGreater(string a, string b){
    int na=a.size(),nb=b.size();
    if(na>nb){return true;}
    else if(na<nb) return false;
    else{
        // a and b are of equal size
        int idx=0;
        while(idx < na){
            if(a[idx]<b[idx])return false;
            else if(a[idx]>b[idx])return true;
            idx++;
        }
        return false;
    }
}

string division(string a,string b){
    if(lessT(a,b)) return "0";
    if(b=="1")return a;
    if(a==b) return "1";
    // int idx=0;
    // int lenA=a.size();
    string temp="",ans="0";
    // temp+=a[idx];
    // idx++;
    // cout<<"a"<<endl;
    // while(lessT(temp,b)){
    //     // cout<<"b";
    //     temp+=a[idx];
    //     idx++;
    // }
    // cout<<temp;

    // while(lenA>idx){
    //     string q="1";
    //     string R=b;

    //     while(lessT(R,temp)){
    //         q=add(q,"1");
    //         R=multiplication(b,q);
    //         // cout<<R<<endl;
    //     }
    //     q=sub(q,"1");
    //     cout<<"q: "<<q<<endl;
    //     R=multiplication(b,q);
    //     temp = sub(temp,R);
    //     ans+=q;

    //     while(lessT(temp,b) && idx < lenA){
    //         temp+=a[idx];
    //         idx++;
    //     }
    // }

    while(!lessT(a,b)){
        ans=add(ans,"1");
        a=sub(a,b);
    }

    return ans;

}

string case1(string expression){
    int length=expression.size(),cnt=0;
    for(int i=0; i<length; i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='x'){
            cnt++;
        }
    }
    // int char* 

    return "";
}

string factorial(string s1){
    string tmp="2";
    string ans ="1";
    string st="1";
    // s1=add(s1,st);

    while(tmp!=s1){
        ans=multiplication(ans,tmp);
        tmp=add(tmp,st);

    }
    ans=multiplication(ans,tmp);
    return ans;
}

string modulo(string a, string b){
    while(!lessT(a,b)){
        a=sub(a,b);
    }
    return a;
}

string exponent(string a, string b){
    if(b=="1")return a;
    string ans="1";
    string bmod2="";
    while(isGreater(b,"0")){
        bmod2=modulo(b,"2");
        if(bmod2=="1"){
            ans=multiplication(ans,a);
        }
        b=division(b,"2");
        a = multiplication(a,a);
    }
    return ans;
}

string gcd(string a, string b){
    if(isGreater(b,a)){
        string temp=a;
        a=b;
        b=temp;
    }

    while(modulo(a,b)!="0"){
        // cout<<"a: "<<a<<"b: "<<b;
        a=modulo(a,b);
        if(isGreater(b,a)){
        string temp=a;
        a=b;
        b=temp;
        }
        
        // cout<<"new a: "<<a<<"new b: "<<b;
    }
    return b;
}

int findLength(string a){
    int size=a.size(),cnt=0;
    for(int i=0; i<size; i++){
        if(a[i]=='+' || a[i]=='-' || a[i]=='x')cnt++;
    }
    return 2*cnt+1;
}

string * convPostfix(string a,int size){
    string* array=new string[size];
    string* temparray=new string[size];
    int na=a.size(),i=0,arridx=0;
    string temp="";
    while(i<na){
        if(a[i]=='+' || a[i]=='-' || a[i]=='x'){
            array[arridx++]=temp;
            string op="";
            op+=a[i];
            array[arridx++]=op;
            temp="";
        }
        else{
            temp+=a[i];
        }
        i++;
    }
    array[arridx]=temp;
    
    arridx=0;

    
    top=-1;
    for(int i=0; i<size; i++){
        if(array[i].size()==1 && (array[i][0]=='+' ||array[i][0]=='x'||array[i][0]=='-')){
                while(!isempty() && getPrecedence(stack[top])>=getPrecedence(array[i][0])){
                    temparray[arridx++]=stack[top];
                    pop();
                }
                push(array[i][0]); 
        }
        else
        temparray[arridx++]=array[i];
    }
    while (!isempty()){
        temparray[arridx++]=stack[top];
        pop();
    }
    
    
    return temparray;
    

}

string evaluatePostfix(string * s,int size){
    // string* array=new string[size];
    stringStack = new string[size];
    stop=-1;

    int i=0;
    while(i<size){
        if(s[i].size()==1 && (s[i][0]=='+' ||s[i][0]=='x'|| s[i][0]=='-')){
            if(isEMPTY())return "111111";
            string b=stringStack[stop];
            POP();
            string a=stringStack[stop];
            POP();
            if(s[i][0]=='+'){
                PUSH(add(a,b));
            }
            else if(s[i][0]=='-'){
                PUSH(sub(a,b));
            }
            else if(s[i][0]=='x'){
                PUSH(multiplication(a,b));
            }
        }
        else{
            PUSH(s[i]);
        }
        i++;
    }

    string ans=stringStack[stop];
    POP();
    return ans;
    // return "";
}

void printmenu(){
    /*
    1. Addition, Subtraction & Multiplication
    2. Exponentiation
    3. GCD
    4. Factorial
    */
    cout << "1. Addition, Subtraction & Multiplication\n";
    cout << "2. Exponentiation\n";
    cout << "3. GCD\n";
    cout << "4. Factorial\n";

}
