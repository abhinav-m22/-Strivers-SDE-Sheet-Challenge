#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   // int cnt1 = 0, cnt2 = 0, cnt0 = 0;
   // for(int i = 0; i < n; i++){
   //    if(arr[i] == 0) cnt0++;
   //    else if(arr[i] == 1) cnt1++;
   //    else cnt2++;
   // }
   
   // int i = 0;
   // while(cnt0){
   //    arr[i++] = 0;
   //    cnt0--;
   // }

   // while(cnt1){
   //    arr[i++] = 1;
   //    cnt1--;
   // }

   // while(cnt2){
   //    arr[i++] = 2;
   //    cnt2--;
   // }

   int low = 0, mid = 0, high = n-1;

   while(mid <= high){
      if(arr[mid] == 0){
         swap(arr[low], arr[mid]);
         mid++;
         low++;
      }
      else if(arr[mid] == 1){
         mid++;
      }
      else{
         swap(arr[high], arr[mid]);
         high--;
      }
   }
}