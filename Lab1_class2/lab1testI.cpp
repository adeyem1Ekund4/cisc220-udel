/*
 * lab1testI.cpp
 *
 *  Created on: Feb 8, 2023
 *      Author: Adeyemi Ekundayo
 */

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
	using namespace std;
/********************************************************
Function Declarations
Make sure the function Declarations (here) match the function definitions you will be
writing. Note: function declaration goes above main, function definition gets written below main
*/
void func1(string s, int ct);
void func2(string s, int len);
void func3(string s, int len);
int func4(int arr[], int len);
int func5(int arr[], int val, int len);
void func6(int arr[], int ind, int len);
void func7(string s, int arr[], int len, int i1, int i2,bool do_pr);
void func8(string s, int len, int arr[], int len2);
void func9(string s7,int f9arr1[],int f9arr2[], int len1,int len2);
void func10(string str10,int f10arr[],int len);
void func11(string s7,int len,int msize);
void func12(string s,int len,int msize);
void func11a(char mat[5][5],int xcoord[],int ycoord[], int len);



//COUT (PRINTING) Info:
/* How to write output on one line versus separate lines:
* cout << "hi"<< endl;
* pipes "hi" into a buffer, and the endl flushes the buffer and moves to
* the next line. If you want to wait until all the characters are in the
* buffer before you flush it and move to the next line, skip the endl;
* so you'd have
* cout << "hi";
* and then whenever you want to flush the buffer, you would just add the
* line,
* cout << endl;
* One final point: you can always add something after each thing that isn't
* an endl;. YOu can add a comma:
* cout << x << ",";
* or a tab:
* cout << x <<"\t";
* or even a star:
* cout << x <<"*";
*
********************** MAIN START ****************************************/
/* Copy and paste the main into your .cpp file. Ctrl-shift-v to maintain formatting*/
int main() {
	string alpha= "abcdefghijklmnopqrstuvwxyz";
	cout << "Hello World!" << endl;
/*****************************************************/
 /* for func1 */
	string str0 = "coffee! ";

	int x = 4;
	func1(str0,x);
/*****************************************************/
 /* for func2 */
	string string1 = "kceacruanmpedle sluastethev"; // 28 characters total
	func2(string1,28);
/*****************************************************/
 /* for func3 */
	string string2 = "speliknuweorrubs tergudeunfe cestmanlbowctoshac";
	func3(string2,47);
/*****************************************************/
 /* for func4 */
	int f4arr1[6] = {17, 10, 5, 20, 18, 2};
	int f4arr2[8] = {7, 21, 9, 6, 2, 39, 3, 25};
	int f4arr3[4] = {-2,1,7,2};
	int f4arr4[5] = {5, 8, 2, 13, 7};
	int f4arr5[7] = {12, -4, -2, 3, -7, -5, -3};
		cout <<alpha[func4(f4arr1,6)]<<alpha[func4(f4arr2,8)]<<alpha[func4(f4arr3,4)]<<alpha[func4(f4arr4,5)]<<alpha[func4(f4arr5,7)]<<endl;
/*****************************************************/
 /* for func5 */
	string string5 = "vapkfslifbhnoueweoihsakbix";

	int f5arr1[14] = {57,16, 46, 41,75,31,64,21,18,13,66,68,81,10};
	int f5arr2[20] = {22,66,67,85,90,92,70,81,42,79,32,27,99,25,49,74,68,12,55,94};
	int f5arr3[17] = {96,64,10,73,4,14,71,37,77,52,54,93,19,26,89,84,47};
	int f5arr4[13] = {28,49,44,19,37,42,26,78,12,88,67,51,66};
	int f5arr5[29] = {11,32,82,90,97,84,30,77,46,6,69,41,79,48,17,65,25,53,33,16,5,7,21,94,38,27,95,100,92};
	int f5arr6[15] = {84,30,77,46,6,69,1,79,48,17,65,25,53,33,16};
		cout << string5[func5(f5arr1,48,14)] << string5[ func5(f5arr2,24,20)]<<string5[func5(f5arr3,80,17) ] << string5 [func5(f5arr4,39,13) ] << string5[func5(f5arr5,36,29) ] << string5 [func5(f5arr6,27,15) ]<< endl;
/*****************************************************/
 /* for func6 */
	string string6= "leztiwrqekrktfmwrbfhyljmuekpvonitapsxp";

	int f6arr1[10] = {17,4,32,12,8,6,14,24,21,11};
	int f6arr2[7] = {21,33,13,18,5,8,35};
	int f6arr3[4] = {15,19,32,4};
	int f6arr4[5] ={35,20,27,24,6};
/**/
	func6(f6arr1,7,10);
		for (int i = 0; i < 10; i++) {
		cout << string6[f6arr1[i]];
	}
		cout << " ";
	func6(f6arr2,0,7);
		for (int i = 0; i < 7; i++) {
		cout << string6[f6arr2[i]];
	}
		cout << " ";
	func6(f6arr3,1,4);
		for (int i = 0; i < 4; i++) {
		cout << string6[f6arr3[i]];
	}
		cout << " ";
	func6(f6arr4,2,5);
		for (int i = 0; i < 5; i++) {
		cout << string6[f6arr4[i]];
	}
		cout << endl;
/*****************************************************/
 /* for func7 */
		string s7 = "skldhbeoieldoodwac hkq cocu iaoe crhpogusyiahhifcet";
			int f7arr[27] = {25,45,48,12,10,16,50,9,32,17,19,36,27,33,30,24,20,28,7,6,18,14,37,39,38,42,44};
	func7(s7, f7arr, 27, 18,2,false); /* won't decode */
	func7(s7,f7arr,27,12,25,true); /* will decode */
 /*****************************************************/
 /* for func8 */
		string s6 = "xezuhnbl_uiplypdhqlb";
			int len = 20;
			int f8arr[] = {2351,92837,482,65,1039,233,23095,1,2037,693842,283};
			int len2 = 11;
	func8(s6,len,f8arr,len2);
 /*****************************************************/
 /* for func9 */
	 	string s9 = "slckfoiold,eryt coteidkfzlvkaljwoeihy dnivgphweugaltzsdxls,gfxnbcm wakrm qblanuaksdhzlkjets, anuakd shojqhwtis uzcdoalbicsoiabasboihs";
			int f9arr1[30] = {2,7,9,10,15,24,36,37,42, 44,51,57,66,68,70,74,76,80,88,89,92,94,98,101,102,113, 115, 120, 122, 124};
			int f9len1 = 30;
			int f9arr2[17] = {8,16,17,39,40,58,67,71,72,75,77,90,91,93, 99,107,110};
			int f9len2 = 17;
	func9(s9,f9arr1,f9arr2,f9len1,f9len2);
 /*****************************************************/
 /* for func10 */
		string str10 = "alettioe twhaaabosi hkcxl";
			int f10arr[23] = {22,11,13,22,5,13,8,3,3,11,7,14,3,19,11,5,1,3,12,9,4,2,22};
	func10(str10,f10arr,23);
 /*************************************************/
/* for func11a: */
			char mat[5][5] = {{'d','k','e','l','p'},{'a','y','a','m','r'},{'a','i','r','k','f'},{'s','e','w','o','z'},{'r','e','c','u','x'}};

			int xcoord[6] = {3,1,2,2,0,4};
			int ycoord[6] = {2,0,4,4,3,1};
			int len_a = 6;
	func11a(mat,xcoord,ycoord, len_a);
 /*****************************************************/
 /* for func11 */
		string s11 = "mboehdkuxkwpmnfzicosyfmeuqlaitcvwdgn";
		len = 36;
	func11(s11,len,6);
 /*****************************************************/
 /* for func12 */
		string str12 = "gboehdpixkwpangzicjsygmeaqlaltmvwdgeabndckswoshbk";
		len = 49;
	func12(str12,len,7);
}
/*******************************END MAIN *****************************************/
/***********************************************************************************/

/**********************************************************************************/
/*****************************************************/

void func1(string s, int ct) {
	for(int i=0;i<ct;i++){
		cout<<s<< endl;
	}
}

void func2(string s, int len) {
	int i = 1;
	while(i<len){
		cout << s[i];
		i++;
		i++;
	}
	cout << endl;
}

void func3(string s, int len) {
	for(int i=len-1;i>=0;i--){
		cout << s[i];
		i--;
	}
	cout << endl;
}

int func4(int arr[], int len) {
	int add = 0;
	for(int i=0;i< len;i++){
	add = add + arr[i];
	}
	return add/len;
}

int func5(int arr[], int val, int len) {
	int loop = arr[0];
	int sole = 0;
	for(int x = 0;x<len;x++){
		if(abs(val-arr[x])<abs(val-loop)){

			sole = x;
			loop = arr[x];
		}
	}
	return sole;
}

void func6(int arr[], int ind, int len) {
	int tmp = arr[0];
	int tmp2 = 0;
	int tmp3 = 0;
	for(int i = 0;i<len;i++){
		if(arr[i]<tmp){
			tmp = arr[i];
			tmp2 = i;
		}
	}
	tmp3 = arr[ind];
	arr[ind] = arr[tmp2];
	arr[tmp2] = tmp3;
}

void func7(string s, int arr[], int len, int i1, int i2,bool do_pr){
	int x;
	int y;
	if(i1<i2){
		x=i1;
		y=i2;
	}
	else{
		x=i2;
		y=i1;
	}
	int last = arr[y];
	for(int i = y;i>x;i--){
		arr[i]=arr[i-1];
	}
	arr[x]=last;
	if(do_pr==true){
		for(int j=0;j<len;j++){
			cout << s[arr[j]];
		}
		cout<<endl;
	}
}

void func8(string s, int len, int arr[], int len2) {
	int sum = 0;
	int avg;
	for(int i =0;i<len2;i++){
		int n = arr[i];
		while(n !=0){
			sum = sum + n % 10;
			n = n / 10;
		}
		avg = sum % len;
		cout << s[avg];
		sum = 0;
	}
	cout << endl;
}

void func9(string s9,int arr1[],int arr2[], int len1,int len2){
	int count = 0;
	int index = 0;
	int newarray[len1 + len2];
	for(int i = 0;i<len1;i++){
		newarray[count++]=arr1[i];
	}
	for(int j = 0;j<len2;j++){
		newarray[count++]=arr2[j];
		}
	for(int x = 0;x<len1+len2;x++){
			for(int y = x+1;y<len1+len2;y++){
				if(newarray[x]>newarray[y]){
		int current = newarray[x];
			newarray[x]=newarray[y];
			newarray[y]=current;
				}
			}
		}
	for(int z = 0;z<len1+len2;z++){
		index = newarray[z];
		cout << s9[index];
	}
	cout << endl;
}

void func10(string str10, int arr[], int len) {
	int index;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if(arr[i] == arr[j]) {
				for(int x = j; x < len; x++) {
					arr[x] = arr[x + 1];
				}
				len--;
				j--;
			}

		}
	}
	for(int y = 0; y < len; y++) {
		index = arr[y];
		cout << str10[index];
	}
	cout << endl;
}

void func11a(char mat[5][5], int xarr[], int yarr[], int len) {
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
				cout<<mat[i][j]<< " ";
			}
		cout << endl;
	}
}

void func11(string s7,int len,int msize) {
	char arr[msize][msize];
	int num = 0;
	for(int i=0;i<msize;i++){
		for(int x=0;x<msize;x++){
			arr[x][i]=s7[num];
			num +=1;
		}
	}
	for(int y=0;y<msize;y++){
		cout<<arr[y][y];
	}
	cout << endl;
}

void func12(string s,int len,int msize){
	char mat[msize][msize];
		int length = 0;
		for(int i=0;i<msize;i++){
			for(int j=0;j<msize;j++){
				mat[i][j]=s[length++];

			}
		}
		int x = msize - 1;
		for(int i=0;i<msize;i++){
			cout<<mat[i][x];
			x--;
		}
		cout << endl;
}
