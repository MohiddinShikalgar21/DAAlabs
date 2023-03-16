#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){  
    int map[26] = {0};
    while(*ransomNote){
        map[*ransomNote - 'a']++;
        ransomNote++;
    }
    while(*magazine){
        map[*magazine - 'a']--;
        magazine++;
    }
    for(int i=0; i < 26; i++) {
        if (map[i] > 0) return false; }
    
    return true;
}

int main(){
    char *s1= "aa";
    char * s2="aab";
    if(canConstruct(s1,s2)) printf("Y");
    else printf("N");
}