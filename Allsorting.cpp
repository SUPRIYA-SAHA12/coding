#include<iostream>
using namespace std;
# define Max 100

class AllSorting{
      int arr[Max];
      int size;
  public:
         void inputValue(int n){
             size=n;
             cout<<"enter the value for sorting:"<<endl;
             for(int i=0;i<n;i++){
                cin>>arr[i];
             }
          }
          void display(){
             cout<<"Array is:"<<endl;
             for(int i=0;i<size;i++)
                       cout<<arr[i]<<" ";
              cout<<"\n";

             }

             void quicksort(int low,int high){
                    if(low<high){
                  int pivot=partition(low,high);
                  quicksort(low,pivot-1);
                  quicksort(pivot+1,high);
                    }
                  }
                  int partition(int low,int high){
                      int pivot_item=arr[low];
                  int left=low;
                  int right=high;
                  while(left<right){
                        while(arr[left]<=pivot_item){
                                left++;
                        }
                        while(arr[right]>pivot_item){
                               right--;
                        }
                        if(left<right){
                                    int temp=0;
                                  temp=arr[left];
                                   arr[left]=arr[right];
                                   arr[right]=temp;

                            }
                        }
                        arr[low]=arr[right];
                        arr[right]=pivot_item;

                        return right;

                  }
                  int getMax(int n){
                  int max=arr[0];
                  for(int i=1;i<n;i++){
                  if(arr[i]>max){
                    max=arr[i];
                     }
                  }
                  return max;
                  }
                  void countSort(int n,int exp){
                      int i, count[10]={0},output[n];
                      for(i=0;i<n;i++){
                        count[(arr[i]/exp)%10]++;
                      }
                      for(int i=1;i<=10;i++){
                      count[i]+=count[i-1];
                      }
                      for(i=n-1;i>=0;i--){
                         output[count[(arr[i]/exp)%10]-1]=arr[i];
                             count[(arr[i]/exp)%10]--;
                      }
                      for(i=0;i<n;i++){
                            arr[i]=output[i];
                      }
                  }

                  void radixSort(int n){
                      int m=getMax(n);
                    for(int exp=1;m/exp>0;exp*=10){
                           countSort(n,exp);
                    }
                  }
                  void MargeSort(int temp[], int low,int high){
                      if(low<high){
                           int mid=(low+high)/2;
                           MargeSort(temp,low,mid);
                           MargeSort(temp,mid+1,high);
                           marge(temp,low,mid,high);

                      }
                  }
                  void marge( int temp[],int low,int mid,int high){

                          int  left_end=mid-1;

                         int  temp_pos=low;
                         int size1=high-low+1;
                         while(low<=left_end && mid<=high){
                                   if(arr[low]<=arr[mid]){
                                           temp[temp_pos]=arr[low];
                                                  temp_pos=temp_pos+1;
                                                  low=low+1;
                                   }
                                   else{
                                        temp[temp_pos]=arr[mid];
                                         temp_pos=temp_pos+1;
                                          mid=mid+1;
                                   }

                         }
                         while(low<=left_end){
                                  temp[temp_pos]=arr[low];
                                    temp_pos=temp_pos+1;
                                    low=low+1;

                         }
                         while(mid<=high){
                                temp[temp_pos]=arr[mid];
                                         temp_pos=temp_pos+1;
                                          mid=mid+1;

                         }
                         for(int i=0;i<=size1;i++){
                            arr[high]=temp[high];
                            high=high-1;

                         }
                  }
                  void BubbleSort(int n){
                  int i,j;
                  for( i=0;i<n;i++){
                    for(j=0;j<n-i-1;j++){
                          if(arr[j]>arr[j+1])
                          {

                              int temp=arr[j+1];
                                arr[j+1]=arr[j];
                                arr[j]=temp;
                          }
                    }
                  }
                  }
                  void selectionSort(int n){
                         int i,j,min1,temp;
                         for(i=0;i<n-1;i++){
                            min1=i;
                            for(j=i+1;j<n;j++){
                                if(arr[j]<arr[min1])
                                        min1=j;
                            }
                            temp=arr[min1];
                            arr[min1]=arr[i];
                            arr[i]=temp;
                         }
                  }
                  void insertionSort(int n){
                     int i,j,temp;
                     for(i=1;i<n-1;i++){
                        temp=arr[i];
                        j=i;
                        while(j>0 && arr[j-1]>temp){
                            arr[j]=arr[j-1];
                            j--;
                        }
                        arr[j]=temp;

                            }
                     }


                          };



      int main(){
           AllSorting obj;

          int n; int temp[Max];

     cout<<"enter the number of element:"<<endl;
     cin>>n;

     obj.inputValue(n);
     obj.display();
     while (true) {
        cout << "\nChoose a sorting method:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Radix Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Input new array\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "After Bubble Sort:\n";
                obj.BubbleSort(n);
                obj.display();
                break;
            case 2:
                cout << "After Selection Sort:\n";
                obj.selectionSort(n);
                obj.display();
                break;
            case 3:
                cout << "After Insertion Sort:\n";
                obj.insertionSort(n);
                obj.display();
                break;
            case 4: {
                int temp[Max];
                cout << "After Merge Sort:\n";
                obj.MargeSort(temp, 0, n - 1);
                obj.display();
                break;
            }
            case 5:
                cout << "After Radix Sort:\n";
                obj.radixSort(n);
                obj.display();
                break;
            case 6:
                cout << "After Quick Sort:\n";
                obj.quicksort(0, n - 1);
                obj.display();
                break;
            case 7:
                cout << "Re-enter the number of elements: ";
                cin >> n;
                obj.inputValue(n);
                obj.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}






































































