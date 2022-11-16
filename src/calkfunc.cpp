#include <iostream>
#include <fstream>
#include <stack>
#include "calkmake.h"




int solve(int x, int y, char znak){
    int flag = 0;
    if (znak == '+') return x+y;
    else if (znak == '-') return x-y;
    else if (znak == '*') return x*y;
    else if (znak == '/') return x/y;
    return 0;
}

int grade(char znak){
	if(znak == '+' || znak == '-') return 1;
	if(znak == '*' || znak == '/') return 2;
	return 0;
}

int calk(std::string str){

    
    char s[1000];
    int len = 0;
    if(str == "--file"){
        std::ifstream in("expression.txt");
        if (in.is_open()){
            in.getline(s, 1000);
            while (s[len] != '\0') len++;           
        }
        in.close();
        if(len==0){
            std::cout<<"Nothing was read\n";
            exit(0);
        }
    }
    else{
        
        char symbol;
        while (std::cin.get(symbol)) {
            if(len==0 && symbol == '\n'){
                std::cout<<"Nothing was read\n";
                exit(0);
            }
            if (symbol == '\n') {
                break;
            }
            s[len] = symbol;
            len++;
        }
    }
    
    int ans = 0;


    std::stack <int> numbers;
    std::stack <char> operations;

    for(int i = 0; i < len; i++){
         
        if(s[i] == ' '){
            continue;
        }

        else if(s[i] == '('){
            operations.push(s[i]);
        }
        
        else if(isdigit(s[i])){
            int number = 0;
            while((i < len) && isdigit(s[i]))
            {
                number = (number*10) + (s[i]-'0');
                i++;
            } 
            numbers.push(number);
            i--;
        }

        else if(s[i] == ')')
        {
            while(!operations.empty() && operations.top() != '(')
            {
                int number2 = numbers.top();
                numbers.pop();
                 
                int number1 = numbers.top();
                numbers.pop();
                 
                char znak = operations.top();
                operations.pop();
                if (znak=='/' && number2==0) {
                    std::cout<<"Ошибка. Деление на 0."<<std::endl;
                    exit(0);
                }
                else numbers.push(solve(number1, number2, znak));
            }

            if(!operations.empty()){
                operations.pop();
            }
        }
        
        else
        {
            while(!operations.empty() && (grade(operations.top()) >= grade(s[i]))){
                int number2 = numbers.top();
                numbers.pop();
                 
                int number1 = numbers.top();
                numbers.pop();
                 
                char znak = operations.top();
                operations.pop();
                 
                if (znak=='/' && number2==0) {
                    std::cout<<"Ошибка. Деление на 0."<<std::endl;
                    exit(0);
                }
                else numbers.push(solve(number1, number2, znak));
            }
            
            operations.push(s[i]);
        }
    }

    while(!operations.empty()){
        int number2 = numbers.top();
        numbers.pop();
                 
        int number1 = numbers.top();
        numbers.pop();
                 
        char znak = operations.top();
        operations.pop();
                 
        if (znak=='/' && number2==0) {
            std::cout<<"Ошибка. Деление на 0."<<std::endl;
            exit(0);
        }
        else numbers.push(solve(number1, number2, znak));
    }
    
    return numbers.top();
}