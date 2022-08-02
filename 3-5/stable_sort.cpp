#include<iostream>
using namespace std;

struct Card { char suit, value;};

void bubble(struct Card A[], int N){
	for (int i = 0; i < N; i++){
		for (int j = N - 1; j > i; j--){
			if (A[j].value < A[j - 1].value){
				char ts = A[j].suit;
				char tv = A[j].value;
				A[j].suit = A[j - 1].suit;
				A[j].value = A[j - 1].value;
				A[j - 1].suit = ts;
				A[j - 1].value = tv;
			}
		}
	}
}

void selection(struct Card A[], int N){
	int i, j, minj;
	Card t;

	for (i = 0; i < N; i++){
		minj = i;
		for (j = i; j < N; j++){
			if (A[j].value < A[minj].value){
				minj = j;
			}
		}
		t = A[i];
		A[i] = A[minj];
		A[minj] = t;
	}
}

void print(struct Card A[], int N) {
	for (int i = 0; i < N; i++){
		if (i > 0)
			cout << " ";
		cout << A[i].suit << A[i].value;
	}
	cout << endl;
}

bool isStable(struct Card C1[], struct Card C2[], int N){
	for (int i = 0; i < N; i++){
		if (C1[i].suit != C2[i].suit) return false;
	}
	return true;
}


int main(){
	Card C1[100], C2[100];
	int N;
	char ch;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> C1[i].suit >> C1[i].value;
	}

	print(C1, N);

	for (int i = 0; i < N; i++){
		C1[i] = C2[i];
	}

	bubble(C1, N);
	selection(C2, N);
	
	print(C1, N);
	cout << "Stable" << endl;
	print(C2, N);
	if (isStable(C1, C2, N)){
		cout << "Stable" << endl;
	}else{
		cout << "Not stable" << endl;
	}
	return 0;
}



