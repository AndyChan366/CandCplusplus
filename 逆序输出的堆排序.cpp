#include<iostream>
#include<vector>
using namespace std;

// �ݹ鷽ʽ����С����(len��arr�ĳ��ȣ�index�ǵ�һ����Ҷ�ӽڵ���±�)
void adjust(vector<int> &arr, int len, int index){
    int left = 2*index + 1; 
    int right = 2*index + 2;
    int maxIdx = index;
    if(left<len && arr[left] < arr[maxIdx])     maxIdx = left;
    if(right<len && arr[right] < arr[maxIdx])     maxIdx = right;
    if(maxIdx != index){
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);
    }
}
 
// ������
void heapSort(vector<int> &arr, int size){
    // ����С���ѣ������һ����Ҷ�ӽڵ����ϣ�
    for(int i=size/2 - 1; i >= 0; i--){
        adjust(arr, size, i);
    }
    // ����С����
    for(int i = size - 1; i >= 1; i--){
        swap(arr[0], arr[i]);           // ����ǰ��С�ķ��õ�����ĩβ
        adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
    }
}
 
int main(){
    vector<int> arr;
    for(int i=0;i<4;i++){
    	int t;
    	cin>>t;
    	arr.push_back(t);
	}
    heapSort(arr, arr.size());
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

