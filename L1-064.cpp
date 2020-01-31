/**
 * 从这道题目我们学习了分词技术的使用方式，首先应当通过手工遍历的方式将所有的字符串都分开，之后再进行相关操作。
 * 
 * 
 * */
#include<iostream>
#include<string>
#include<vector>
#include<ctype.h>
using namespace std;
int isnumber(char c){
    return c >= '0' && c <= '9';
}
int main(void){
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    while(N --){
        getline(cin, line);
        //先输出一下
        cout << line << endl << "AI: ";
        //首先实现分词技术
        vector<string> mem;
        //先将大小写转换
        for(int i = 0; i < line.length(); i ++){
            if(line[i] == '?') line[i] = '!';
            else if(isupper(line[i]) && line[i] != 'I') line[i] = tolower(line[i]);
        }
        //下面开始分词
        for(int i = 0; i < line.length();){
            string sep = "";
            //我们通过开始字母来判读需要做的处理
            if(isalpha(line[i])){
                //如果是字母，则我们读入到最后一个字母
                while(i < line.length() && isalpha(line[i])) sep += line[i++];

            }else if(isnumber(line[i])){
                //如果是数字 则我们要读入什么呢？自然是将其变成数字串
                while(i < line.length() && isnumber(line[i])) sep += line[i++];

            }else if(line[i] == ' '){
                //如果是空格 则将后面所有的空格都跳过
                sep = " ";
                while(i < line.length() && line[i] == ' ') i ++;
            }else{
                //如果是分隔符，要删除前面的空格
                sep += line[i++];
                if(!mem.empty() && mem.back() == " ") mem.pop_back();
            }
            //左后去除开始和结束位置的空格
            if(sep == " " && (mem.empty() || i == line.length())) continue;
            mem.push_back(sep);
        }
        //下面我们将文本替换
        for(int i = 0; i < mem.size(); i ++){
            if(mem[i] == "I" || mem[i] == "me") mem[i] = "you";
            else if(mem[i] == "you"){
                //看一下其前面的一个字符既不是字母也不是数字
                if(i - 1 >= 0 && !isalpha(mem[i - 1][0]) && !isnumber(mem[i - 1][0]) && mem[i - 1].length() == 1){
                    //再看其前面一个单词情况
                    if(i - 2 >= 0){
                        if(mem[i - 2] == "could" || mem[i - 2] == "can"){
                            mem[i] = mem[i - 2];
                            mem[i - 2] = "I";
                        }
                    }
                }
            }
        }
        for(string s : mem){
            cout << s;
        }
        cout << endl;
    }
    return 0;
}