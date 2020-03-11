#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<cstring>

using std::string;
string countAndSay(int n) {
        if (n==1) return '1';
        else
        {
            string middle_result = "1";
            string result;
            for(int i=2;i<=n;i++)
            {
                int label_n=0;
//                char temp = middle_result[0];
                for(;label_n<i;label_n++)
                {
                    if(label_n+1=i)
                    {
                        result+=std::to_string(label_n) + std::to_string(middle_result[label_n]);
                    }
                    else
                    {
                        continue;
                    }
                }
                middle_result = result;
            }
        }

    }

int main(){

//    char buf[10] = "124";
//    float f = atof(buf); //转换
//    printf("%f\n", f);
//    f = strtod(buf, NULL); //转换
//    printf("%f\n", f);
    return 0;
}
