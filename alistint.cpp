#include "alistint.h"
#include <cstdlib>
#include <iostream>

using namespace std;

AListInt::AListInt()
{
	size_ = 10;
	filled=0;
	list = new int[size_];
}

AListInt::AListInt(int cap)
{
	size_ = cap;
	filled=0;
	list = new int[size_];
}

AListInt::~AListInt()
{
	delete [] list;
}

int AListInt::size()const
{
	return size_;
}

bool AListInt::empty()const
{
	return size_==0;
}
void AListInt::insert(int pos, const int& val){
	if (size_+1 == filled-1){
		resize();
	}
	for (int i= filled-1; i >= pos; i--){
		list[i+1]=list[i];
	}	
	list[pos] = val;
	filled++;
}

void AListInt::remove (int pos){
	for (int i = pos; i < filled-1; i++){
		list[i]= list[i+1];
	}
	list[filled-1] = 0;

	filled --;
}

 void AListInt::set (int position, const int& val){
	list[position] = val;
}

int& AListInt::get (int position){
	return list[position];
}

int const & AListInt::get (int position) const{
 	return list[position];
}

int AListInt:: is_filled(){
	return filled;
	}
  
void AListInt::resize(){
	int* oldArray = list;
	list = new int[2*size_];

	for(int i = 0; i < size_; i++){
		list[i] = oldArray[i];
	}
	
	size_= size_*2;
	delete [] oldArray;
};



int main(){
	cout<< endl;
	cout << "Calling AList with the default constructor" << '\n' << endl;
	AListInt * list = new AListInt;

	cout << "Filling out the array." << endl;
	cout << "Expected output: 7, 8, 9, 10, 11, 12, 13, 14" << endl;
	cout << "Actual output:   ";

	int testy=7;
	for (int i=0; i<8; i++){
		list->insert(i,testy);
		testy++;
	}

	for (int i=0; i < 8; i++){
		cout<< list->get(i);
		if (i < 7){
		cout <<", ";
		}
	}
	cout << '\n' << endl;

	cout << "Calling Alist with the secondary constructor" << '\n' << endl;
	AListInt * list2 = new AListInt(11);
	cout << "Filling out the array" << endl;
	cout << "Expected output: 15, 14, 13, 12, 11, 10, 9, 8, 7, 6 " << endl;
	cout << "Actual output:   ";
	
	for (int i=0; i < 10; i++){
		list2->insert(i, testy);
		testy--;
	}
	for (int i=0; i < 10; i++){
		cout<< list2->get(i);
		if (i < 9){
		cout <<", ";
		}
	}
	cout << '\n' << endl;

	cout << "What's the size of the first list? "<< endl;
	cout << "Expected output: 10"<< endl;
	cout << "Actual output:   " << list->size();
	cout << '\n' << endl;

	cout << "What's the size of the second list?" << endl;
	cout << "Expected output: 11" << endl;
	cout << "Actual output:   " << list2->size();
	cout << '\n' << endl;

	cout << "Adding to the first list" << endl;
	for (int i=list->is_filled(); i < list->is_filled()+10; i++){
		list->insert(i, testy);
		testy--;
	}
	cout << "Expected output: " << endl;
	cout << "Actual output: ";
	for (int i=0; i < list->size(); i++){
		cout<< list->get(i);
		if (i < list->size()-1){
		cout <<", ";
		}
	}
	cout << '\n' << endl;

	return 0;
}




