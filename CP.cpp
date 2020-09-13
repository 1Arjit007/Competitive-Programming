/*1.The #include line at the beginning of the code is a feature of the g++ compiler that allows us to include the entire standard library.
Thus, it is not needed to separately include libraries such as iostream, vector, and algorithm, but rather theyare available automatically.*/
  #include<bits/stdc++.h>
  using namespace std;
  int main() {
  // solution comes here
  }

//2.Input and output is sometimes a bottleneck in the program.
//The following lines at the beginning of the code make input and output more efficient:
   #include<bits/stdc++.h>
   using namespace std;
   int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // solution comes here
   }  

// 3.Sometimes the program should read a whole input line, possibly containing spaces.
// This can be accomplished by using the getline function:
   string s;
  getline(cin, s);

//4.If the amount of data is unknown, the following loop is useful:
  while (cin >> x) {
    // code
  }
