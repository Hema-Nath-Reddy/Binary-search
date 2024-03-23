#include<iostream>
#include<algorithm>
using namespace std;
int search(int size, int a[], int key){
	sort(a,a+size);
	int start=0;
	int finish=size-1;
	while(start<=finish){
		int middle=(start+finish)/2;
		if(a[middle]==key){
			return middle;
		}else if(a[middle]<key){
			start=middle+1;
		}else if(a[middle]>key){
			finish=middle-1;
		}
	}
	return -1;
}
int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin>>size;
    if(size<=0){//if condition if the user inputs a non-positive value for the size of the array.
        do{
            cout<<"Size of the array cannot be less than 0. Input a proper value: ";
            cin>>size;
        }while(size<=0);//do-while loop that runs until the user inputs a positive value for the size of the array.
    }
    int a[size];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<"Enter the key element: ";
    int key;
    cin>>key;
   
    if(search(size,a,key)==-1){//if the returned value is -1, then it means that the element is not present.
        cout<<key<<" is not present in the array."<<endl;
    }else{
        cout<<"The index of "<<key<<" is "<<search(size,a,key)<<endl;
    }
    return 0;
}

