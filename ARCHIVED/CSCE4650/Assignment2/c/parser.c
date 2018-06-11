#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
 
//True if the string is a keyword
bool isKeyword(char* str){
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") || 
        !strcmp(str, "break") || 
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto")){
        return (true);
	}
    return (false);
}
 
//True if the string is an int
bool isInteger(char* str){
    int i, len = strlen(str);
 
    if (len == 0){
        return (false);
	}
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0)){
            return (false);
		}
    }
    return (true);
}

//True if the string is an identifier.
bool validIdentifier(char* str){
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' || 
        str[0] == '6' || str[0] == '7' || str[0] == '8' || 
        str[0] == '9' || isDelimiter(str[0]) == true){
        return (false);
	}
    return (true);
}
 
//True if the string is a real number
bool isRealNumber(char* str){
    int i, 
	int len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0){
        return (false);
	}
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' && str[i] != '.' || 
            (str[i] == '-' && i > 0)){
            return (false);
		}
        if (str[i] == '.'){
            hasDecimal = true;
		}
    }
    return (hasDecimal);
}
 
//Extracts substring
char* subString(char* str, int left, int right){
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

//True if the character is a delimeter
bool isDelimiter(char ch){
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}'){
        return (true);
	}
    return (false);
}
 
//True if the character is an operator
bool isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '='){
		return (true);
	}
    return (false);
}
 
//Parses input string.
void parse(char* str){
    int left = 0, right = 0;
    int len = strlen(str);
 
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
 
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);
 
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);
 
            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);
 
            else if (isRealNumber(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);
 
            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
 
            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }//end while loop
    return;
}

int main(int argc, char *argv[]){ 
	char str[100];
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if(!argv[1]){
		printf("useage: <./a.out> <file you want to parse>\n\n");
		printf("example: ./a.out Test1.java\n");
		exit(1);
	}

	fp = fopen(argv[1],"r");
	if(fp == NULL){
		exit(EXIT_FAILURE);
	}
	while((read = getline(&line, &len, fp)) != -1){
		parse(line); // calling the parse function
	}
    return (0);
}
