#include <bits/stdc++.h>
using namespace std;

int main()
{   

    //string is pass by value not pass by reference hence receive as &s in function
    char ch[10];

    cin >> ch;
    // the limit of the ch over here is 9 characters as 1 character is reserved for null character
    //the delimeter of normal char array is enter,space,tab,etc...to deal with that use this to read the entire line
    cin.getline(ch, 10);

    // '\0' depicts the termination of char array

    cout << ch;

    /* calculating length of char array*/

    // char ch[100];
    // cin.getline(ch,100);

    // int length=0;;

    // while(ch[length]!='\0')
    // {
    //     length++;

    // }
    // cout<<length<<endl;

    //else use utility function strlen(ch)

    /* reversing a char array*/

    //  char ch[100];
    //  cin.getline(ch,100);

    // reverse(ch,ch+strlen(ch));

    // int i=0;
    // int j=strlen(ch)-1;

    // while(i<=j)
    // {
    //     swap(ch[i],ch[j]);
    //     i++;
    //     j--;
    // }

    // cout<<ch;  

    /* Converting lowercase to uppercase */

    //   char ch[100];
    //  cin.getline(ch,100);

    //  for(int i=0;i<strlen(ch);i++)
    //  {
    //     if(ch[i]>=97 && ch[i]<=122)
    //     {
    //         ch[i]=ch[i]-32;
    //     }
    //  }

    //  cout<<ch;

    /* replace @ with space*/

    // char ch[100];
    // cin.getline(ch,100);

    // for(int i=0;i<strlen(ch);i++)
    //  {
    //     if(ch[i]=='@' )
    //     {
    //         ch[i]=' ';
    //     }
    //  }

    //  cout<<ch;

    /* Check Palindrome*/
    //  char ch[100];
    //  cin.getline(ch,100);

    // int i=0;
    // int j=strlen(ch)-1;

    // while(i<=j)
    // {
    //     if(ch[i]==' ')
    //     {
    //         i++;
    //     }

    //     if(ch[j]==' ')
    //     {
    //         j--;
    //     }
    //     //to manage spaces within the statements
    //     if(ch[i]==ch[j])
    //     {
    //         i++;
    //         j--;
    //     }

    //     else
    //     {
    //         cout<<"not palindrome";
    //         return 0;
    //     }

    // }

    //  cout<<"palindrome";

    /* accesing elements in a string */
    // string str;
    //cin>>name;
    //cout<<name
    // getline(cin,str);

    // int i=0;
    // while(str[i]!='\0')
    // {

    //     cout<<str[i]<<"";
    //     i++;
    // }
    // in string also there is a concept of null character,but may give error in certain compilers

    /* member functions in strings */
    // str.length()-->gives size of the elements in the string
    // str.empty()-->to check whether a string is empty or not
    // str.at(index_number)-->to check value at index
    // str.front()
    // str.back() -->last character element in the string
    // str.append(str2)--> to concatenate
    // str.erase(4,3)--> from 4th index remove 3 elements
    // str.insert(5,str2)--> insert at 5th index
    // str.push_back()
    // str.pop_back()
    // str.find(str1)==string::npos then substring is not present
    // str.compare(str2)==0 then same string else not
    // str.substr(19,5)--> from 19th index returns 5 characters as a substring

    return 0;
}