#include <iostream>
#include <string>
#include <stack>
using namespace std;

//中缀转后缀表达式 数字后通过空格来断开
string Mid2Last(string express)
{
    stack<char> char_stack;
    string LastExpress;
    
    for (int e=0;e<express.length();++e)
    {
        //遇到数字，直接输出到LastExpress
        if(express[e] >= '0' and express[e] <= '9')
        {
            //添加数字 直到遇到 空格
            while(express[e] >= '0' and express[e] <= '9')
            {
                LastExpress+=express[e];
                e++;
            }
//            assert(express[e] == ' ');
            LastExpress+=' ';
        }
        else if (express[e] == ' ' )
            ;
        //如果栈为空，遇到符号，直接压入栈
        else if(char_stack.empty())
        {
            char_stack.push(express[e]);
        }
        //如果遇到左括号，无条件直接压入栈
        else if (express[e]=='(')
        {
            char_stack.push(express[e]);
        }
        //+ - 是最低优先级的运算符，如果遇到，则到弹出所有元素 或 遇到‘（’停止，并且压入此次遇到的+-符号
        else if(express[e] == '+' or express[e] =='-')
        {
            while (!char_stack.empty() and char_stack.top() != '(' )
            {
                LastExpress+=char_stack.top();
                assert(char_stack.empty()==0);
                char_stack.pop();
            }
            char_stack.push(express[e]);
        }
        //当遇到 * /号 的时候，将栈中除了 + -（号以外的符号都弹出，并且将此次符号压入栈
        else if(express[e]=='*' or express[e]== '/')
        {
            while ( char_stack.top()!='(' and( char_stack.top()=='*' or char_stack.top()=='/' or char_stack.top()=='^') )
            {
                LastExpress+=char_stack.top();
                assert(char_stack.empty()==0);
                char_stack.pop();
            }
            char_stack.push(express[e]);
        }
        //当遇到最高优先级的指数运算符的时候，除非栈中是自己，则直接加入栈中
        else if(express[e]=='^')
        {
            if(char_stack.top()!='^')
                char_stack.push(express[e]);
            else
            {
                LastExpress+=char_stack.top();
                char_stack.pop();
                char_stack.push(express[e]);
            }
        }
        //当遇到右括号时，弹出所有符号，直到遇到左括号或者空栈
        else if(express[e]==')')
        {
            while(char_stack.top()!='(' and !char_stack.empty())
            {
                LastExpress+=char_stack.top();
                char_stack.pop();
            }
            //弹出左括号
            assert(char_stack.top()=='(');
            char_stack.pop();
        }
        
    }
    //当遍历中缀表达式后，将栈中所有元素弹出到LastExpress
    while(!char_stack.empty() )
    {
        LastExpress+=char_stack.top();
        assert(char_stack.empty()==0);
        char_stack.pop();
    }
    return LastExpress;
}

//后缀表达式求值
int LastExpress2Value(string LastExpress)
{
    stack<int> num_stack;
//    int value=0;
    
    for(int m=0,temp_num=0,temp_num2;m<LastExpress.length();m++)
    {
        if(LastExpress[m] >= '0' and LastExpress[m] <= '9')
        {
            temp_num=0;
            //直到遇到空格，一直计算字符串表达的值
            while(LastExpress[m] != ' ' )
            {
                assert(LastExpress[m] >= '0' and LastExpress[m] <= '9');
                temp_num=temp_num*10+(LastExpress[m++]-'0');
            }
            num_stack.push(temp_num);
            assert(LastExpress[m]== ' ');
        }
        else
        {
            switch (LastExpress[m]) {
                case '+':
                {
                    temp_num2=num_stack.top();
                    num_stack.pop();
                    temp_num=num_stack.top();
                    num_stack.pop();
                    temp_num=temp_num+temp_num2;
                    num_stack.push(temp_num);
                    break;
                }
                case '-':
                {
                    temp_num2=num_stack.top();
                    num_stack.pop();
                    temp_num=num_stack.top();
                    num_stack.pop();
                    temp_num=temp_num-temp_num2;
                    num_stack.push(temp_num);
                    break;
                }
                case '*':
                {
                    temp_num2=num_stack.top();
                    num_stack.pop();
                    temp_num=num_stack.top();
                    num_stack.pop();
                    temp_num=temp_num*temp_num2;
                    num_stack.push(temp_num);
                    break;
                }
                case '/':
                {
                    temp_num2=num_stack.top();
                    num_stack.pop();
                    temp_num=num_stack.top();
                    num_stack.pop();
                    temp_num=temp_num/temp_num2;
                    num_stack.push(temp_num);
                    break;
                }
                    break;
            }
        }
    }
    return num_stack.top();
}


//中缀表达式转后缀
int main()
{
    string express={"( 2 + 3 ) * 6 + 4 / 2"};
//    cout << "请输入中缀表达式： " <<endl;
//    getline(cin,express);
    
    string ex;
    ex=Mid2Last(express);
    cout << ex <<endl;
//    ex=LastExpress2Value(ex);
    cout << LastExpress2Value(ex) << endl ;

}
