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

//5.A common mistake when using the type long long is that the type int is still
//used somewhere in the code. For example, the following code contains a subtle error:
  int a = 123456789;
  long long b = a*a;
  cout << b << "\n"; // -1757895751

//6.The problem can be solved by changing the type of a to
//long long or by changing the expression to (long long)a*a.

// 7.Modular Arithmetic Sometimes, the answer to a problem is a very large number,
// but it is enough to output it “modulo m”, i.e., the remainder when the answer is
// divided by m (e.g., “modulo 109 + 7”).

// 8.(a + b) mod m = (a mod m + b mod m) mod m
//   (a − b) mod m = (a mod m − b mod m) mod m
//   (a · b) mod m = (a mod m · b mod m) mod m

//9.For example, the following code calculates n!, the factorial of n, modulo m:
  long long x = 1;
  for (int i = 1; i <= n; i++) {
      x = (x*i)%m;
    }
  cout << x << "\n";

//10.An easy way to make sure there are no negative remainders is to first calculate the
//remainder as usual and then add m if the result is negative:
  x = x%m;
  if (x < 0) x += m;

//11.In most cases, double is enough, but long double is more accurate.

//12.the following code prints the value of x with 9 decimal places:
  printf("%.9f\n", x);

//13.It is risky to compare floating point numbers with the == operator, because it is
//possible that the values should be equal but they are not because of precision errors.

//14.A better way to compare floating point numbers is to assume that two numbers are
//equal if the difference between them is less than ε, where ε is a small number. For
//example, in the following code ε = 10−9:
  if (abs(a-b) < 1e-9)
  {
    // a and b are equal
  }

// 15.Type Names The command typedef can be used to give a short name to a data
// type. For example, the name long long is long, so we can define a short name
// ll as follows:
  typedef long long ll;
  typedef vector<int> vi;
  typedef pair<int,int> pi;

// 16.Macros Another way to shorten code is to define macros.
  #define F first
  #define S second
  #define PB push_back
  #define MP make_pair

//17.A macro can also have parameters, which makes it possible to shorten loops and
// other structures. For example, we can define the following macro:
  #define REP(i,a,b) for (int i = a; i <= b; i++)

//18.Subset
  vector<int> subset;
  void search(int k) 
  {
    if (k == n+1) 
    {
      // process subset
    } 
    else 
    {
      // include k in the subset
      subset.push_back(k);
      search(k+1);
      subset.pop_back();
      // don’t include k in the subset
      search(k+1);
    }
  }
//19.Generating Permutations
  vector<int> permutation;
  bool chosen[n+1];
  void search() 
  {
    if (permutation.size() == n)
    {
      // process permutation
    } 
    else 
    {
      for (int i = 1; i <= n; i++) 
      {
        if (chosen[i]) 
          continue;
        chosen[i] = true;
        permutation.push_back(i);
        search();
        chosen[i] = false;
        permutation.pop_back();
      }
    }
}

//20. C++ standard library also has the function next_permutation
// that can be used to generate permutations. The function is given a permutation, and
// it produces the next permutation in lexicographic order. The following code goes
// through the permutations of {1, 2,..., n}:

  for (int i = 1; i <= n; i++)
  {
    permutation.push_back(i);
  }
  do 
  {
  // process permutation
  } while (next_permutation(permutation.begin(),permutation.end()));

//21.N-Queen Problem
  void search(int y)
  {
    if (y == n) 
    {
      count++;
      return;
    }
    for (int x = 0; x < n; x++) 
    {
      if (col[x] || diag1[x+y] || diag2[x-y+n-1]) 
        continue;
      col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
      search(y+1);
      col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
  }

//22. Bit Manipulation
//The bits in the representation are indexed from right to left. To convert a bit representation bk ... b2b1b0 into a number, the formula
//bk2k +···+ b222 + b121 + b020.

//23.There is a connection between the representations: a signed number −x equals an unsigned number 2n − x.

//24.If a number is larger than the upper bound of the bit representation, the number
//will overflow. In a signed representation, the next number after 2n−1 − 1 is −2n−1,
//and in an unsigned representation, the next number after 2n − 1 is 0.

  int x = 2147483647
  cout << x << "\n"; // 2147483647
  x++;
  cout << x << "\n"; // -2147483648

//25.And Operation The and operation x & y produces a number that has one bits in
//positions where both x and y have one bits.

  10110 (22)
  & 11010 (26)
  = 10010 (18) .

//26.Using the and operation, we can check if a number x is even because x & 1 = 0
// if x is even, and x & 1 = 1 if x is odd. More generally, x is divisible by 2^k exactly
// when x & (2^k − 1) = 0.
    
//27.Or Operation The or operation x | y produces a number that has one bits in positions
// where at least one of x and y have one bits.
   10110 (22)
  | 11010 (26)
  = 11110 (30) .
    
// 28.Xor Operation The xor operation x ˆ y produces a number that has one bits in
// positions where exactly one of x and y have one bits.
  10110 (22)
  ˆ 11010 (26)
  = 01100 (12)

//29.Not Operation The not operation ~x produces a number where all the bits of x have
// been inverted. The formula ~x = −x −1 holds, for example, ~29 = −30. 
    x = 29 00000000000000000000000000011101 ~x = −30 11111111111111111111111111100010
 
// 30.Bit Shifts The left bit shift x << k appends k zero bits to the number, and the right bit
// shift x >> k removes the k last bits from the number.
//   For example, 14 << 2 = 56,
// because 14 and 56 correspond to 1110 and 111000. Similarly, 49 >> 3 = 6, because
// 49 and 6 correspond to 110001 and 110. Note that x << k corresponds to multiplying
// x by 2^k , and x >> k corresponds to dividing x by 2^k rounded down to an integer.

// 31.Bit Masks A bit mask of the form 1 << k has a one bit in position k, and all other
// bits are zero, so we can use such masks to access single bits of numbers.
//     In particular,
// the kth bit of a number is one exactly when x & (1 << k) is not zero. The following
// code prints the bit representation of an int number x:

  for (int k = 31; k >= 0; k--) {
  if (x&(1<<k)) cout << "1";
  else cout << "0";
  }

    
    
    


