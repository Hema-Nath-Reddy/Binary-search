#include<iostream>
#include<algorithm>
using namespace std;
int search(int a[], int key, int start, int end){
	if(start<=end){
		int middle=(start+end)/2;
		if(a[middle]==key){
			return middle;
		}else if(a[middle]<key){
			search(a,key,middle+1,end);
		}else if(a[middle]>key){
			search(a,key,0,middle-1);
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
    sort(a,a+size);
    cout<<"Enter the key element: ";
    int key;
    cin>>key;
   	int result=search(a,key,0,size-1);
    if(result==-1){//if the returned value is -1, then it means that the element is not present.
        cout<<key<<" is not present in the array."<<endl;
    }else{
        cout<<"The index of "<<key<<" is "<<result<<endl;
    }
    return 0;
}
