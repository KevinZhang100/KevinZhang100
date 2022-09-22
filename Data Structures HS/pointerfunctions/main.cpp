/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//PointerFunctions
//Author: Kevin Zhang
//Compete various methods using pointers 
#include <iostream>
#include <string>
using namespace std;

void swap(int *a, int *b) { //Swapping the two integers with pointers
    int *aa = a;
    a = b;
    b = aa;
}
 
void letterCount(string s, int* numVowels, int* numConsonants) { //calculate number of vowels and consonants in a string
    int vows = 0;
    int cons = 0;
    char *str = &s.at(0); //get the first letter
    for (int i = 0; i < s.length(); i++){ //loop through string
        if (*(str+i) == 'A' || *(str+i) == 'E' || *(str+i) == 'I' || *(str+i) == 'O' || *(str+i) == 'U' ){ //if the letter is a vowel add one to vowels
            vows++;
        }
        else {
            cons++;
        }
    
    }
    *numVowels = vows;
    *numConsonants = cons;
    
}
    
void arrayInfo(int* arrPtr, int length) { //print the int and its memory location
  for (int i = 0; i < length; i++) {
		cout << "Element: " << *(arrPtr + i) << " Memory Location: " << (arrPtr+i) << endl; //prints element and memory location for each index of array
	}
}

int main()
{
     int loop = 0; //loop because convinence
    while (loop == 0) {
        int tri;
        cout << "Enter 1 for swap, 2, for letter count, 3 for array info: \n";  //allows you to select one of 3 options
        cin >> tri;
        if (tri == 1){ 
            int a, b;
			cout << "Enter int a and int b with space in between: \n"; //enter the 2 ints
			cin >> a >> b;
			cout << "Original: " << a << " " << b << endl; //displays original as reference
			swap(a, b);
			cout << "Swaped: " << a << " " << b << endl; //displays after swapped
        }
        
        if (tri == 2){
            string s;
			int numVowels = 0;
			int numConsonants = 0;
			cout << "Enter string with captials: \n";
			cin >> s;
			letterCount(s, &numVowels, &numConsonants); //need pointers 
			cout << "Entered String: " << s << endl; //print out everything
			cout << "Vowels: " << numVowels << endl;
			cout << "Consonants: " << numConsonants << endl;
        
        }
        
        if (tri == 3){
           int length;
			cout << "Enter length: \n"; //get length
			cin >> length;
			int arr [length]; //create the array
			cout << "Enter all the ints for the array: \n"; //let user enter all the ints of array
			for (int i = 0; i < length; i++) {
				cin >> arr[i];
			}
			int* arrayPtr = arr; //used to call method
			arrayInfo(arrayPtr, length); 
        }
        
        else {
            cout << "Not very correct thing to enter\n"; //In case of wrong output
        }
        
        
        cout << "Enter 0 to try again or any other int to stop: \n";
        cin >> loop;
    }
    return 0;
}




