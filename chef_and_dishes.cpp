
/*

Chef has N dishes, numbered 1 through N. For each valid i, dish i is described by a string Di

containing only lowercase vowels, i.e. characters 'a', 'e', 'i', 'o', 'u'.

A meal consists of exactly two dishes. Preparing a meal from dishes i
and j (i≠j) means concatenating the strings Di and Dj in an arbitrary order into a string M describing the meal. 
Chef likes this meal if the string M

contains each lowercase vowel at least once.

Now, Chef is wondering - what is the total number of (unordered) pairs of dishes 
such that he likes the meal prepared from these dishes?

INPUT ::

1
3
aaooaoaooa
uiieieiieieuuu
aeioooeeiiaiei


OUTPUT ::

2

EXPLANATION ::

A meal prepared from dishes 1 and 2
(for example "aaooaoaooauiieieiieieuuu") contains all vowels.
A meal prepared from dishes 1
and 3
(for example "aaooaoaooaaeioooeeiiaiei") does not contain 'u'.
A meal prepared from dishes 2
and 3 (for example "uiieieiieieuuuaeioooeeiiaiei") contains all vowels


*/


// THIS QUESTION IS SOLVED USING BIT MASKING            

#include<C:/MinGW/lib/gcc/mingw32/9.2.0/include/c++/mingw32/bits/stdc++.h>
using namespace std;
int main(void){
    
   int t;
   cin>>t;
   
   while(t-->0){
       
       int len;
       cin>>len;
       vector<string> str;
       
       for(int i=0;i<len;i++) {
           string s;
           cin>>s;
           str.push_back(s);
       }
       int n=1<<5;
       vector<int> arr(n,0);
       for(int i=0;i<str.size();i++){
           string s=str[i];
           int num=0;
            for(int i=0;i<s.length();i++){
               
                if(s[i]=='a'){
                    int d=1<<0;
                    num=num|d;
                }
                else if(s[i]=='e'){
                 int d=1<<1;
                 num=num|d;
                }
                 else if(s[i]=='i'){
                 int d=1<<2;
                 num=num|d;
                } else if(s[i]=='o'){
                 int d=1<<3;
                 num=num|d;
                } else if(s[i]=='u'){
                 int d=1<<4;
                 num=num|d;
                }
                
            }
            
            arr[num]+=1;
       }
       
       
   
       
       long long int count=0;
       for(int i=1;i<n;i++){
           for(int j=i+1;j<n;j++){
               
               if((i|j)==31){
                   count+=(arr[i]*arr[j]);
               }
               
           }
       }
       
       long long int f=arr[31];
      count+=((f*(f-1))/2);
       
       cout<<count<<endl;
   }
    
}

