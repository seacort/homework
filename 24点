#include <iostream>
#include <string>
using namespace std;

int str2num(string str)
{
    if(str == "joker" or str == "JOKER")
        return -1;
    else if (str[0] >= '2' and str[0] <= '9')
        return (int)(str[0]-'0');
    else if (str == "10")
        return 10;
    else if(str == "A")
        return  1;
    else if(str == "J")
        return  11;
    else if(str == "Q")
        return  12;
    else if(str == "K")
        return  13;
    else
        return -1;
}

int suan(int a ,int b,int sign)
{
    if(sign == 0)
        return a+b;
    else if (sign == 1)
        return a-b;
    else if (sign == 2)
        return a*b;
    else if (sign == 3 and a%b == 0)
        return (int)(a/b);
    else
        return 253;
}

bool ans24(int a,int b,int c,int d)
{
    int num[4]={a,b,c,d},ans=0,L[3];
    
    for( L[0]=0;L[0]<4;L[0]++)
    {
        for( L[1]=0;L[1]<4;L[1]++)
        {
            for( L[2]=0;L[2]<4;L[2]++)
            {
                ans=suan(a, b, L[0]);
                ans=suan(ans, c, L[1]);
                ans=suan(ans, d, L[2]);
                if(ans == 24 )
                {
                    for(int i=0;i<4;i++)
                    {
                        if(num[i]>=2 and num[i]<=10)
                            cout <<num[i];
                        else if (num[i] == 1)
                            cout <<"A";
                        else if (num[i] == 11)
                            cout <<"J";
                        else if (num[i] == 12)
                            cout <<"Q";
                        else if (num[i] == 13)
                            cout <<"K";
                        
                        if(i<=2)
                        {
                            if(  L[i]==0)
                                cout <<"+";
                            else if ( L[i]==1)
                                cout <<"-";
                            else if ( L[i]==2)
                                cout <<"*";
                            else if ( L[i]==3)
                                cout <<"/";
                        }
                    }
                    cout <<endl;
                    return true;
                }
            }
        }
    }
    return false;
}




int main()
{
    string a,b,c,d;
    cin >>a>>b>>c>>d;
    cin.get();
    int num[4]={str2num(a),str2num(b),str2num(c),str2num(d)};
    //1
    for(int i=0;i<4;i++)
    {
        if(num[i]==-1)
        {
            cout <<"ERROR"<<endl;
            return 0;
        }
        //2
        for(int m=0;m<4;m++)
        {
            if(m == i)continue;
           //3
            for(int n=0;n<4;n++)
            {
                if(n == i or n==m)continue;
                //4
                for(int p=0;p<4;p++)
                {
                    if(p == i or p == m or p == n)continue;
                    if(ans24(num[i],num[m],num[n],num[p]))
                        return 0;
                }
            }
        }
    }
    cout <<"NONE"<<endl;

}
 

