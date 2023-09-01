// Problem Link : - https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?company[]=Synopsys&company[]=Synopsys&page=1&query=company[]Synopsyspage1company[]Synopsys&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-two-sorted-arrays

// Problem Article : https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/

#incldue<bits/stdc++.h>
using namespace std;

class Merge{
private:
public:
    // TC = O(min(m,n)+O(m+n(log(m+n))))
    // SC = O(1)
    // approach use concpet of arrange 2 sorted array and then sort them combine them as final answer
    int method1(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = n-1;
        int j=0;
        while(i>=0 and j<n)
        {
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else
                break;
        }
        for(int i=m;i<(m+n);i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
        return;
    }

    // more optimized
    // gap method 
    int method2(vector<int>& nums1, int n, vector<int>& nums2, int m){
        int gap = (m+n)/2 + (m+n)%2;
        while(gap>1){
            int i = 0,j = gap;
            while(j<n+m){
                int el1 = (i<n)?i:i-n;
                int el2 = (j<n)?j:j-n;
                if(el1<n and el2<n and nums1[el1]>nums1[el2])
                    swap(nums1[el1],nums2[el2]);
                else if(el1<n and el2>=n and nums1[el1]>nums2[el2-n]){
                    swap(nums1[el1],nums2[el2-n]);
                }
                else if(el1>=n and el2<n and nums2[el1-n]>nums2[el2]){
                    swap(nums1[el1-n],nums2[el2]);
                }
                else if(nums1[el1-n]>nums2[el2-n]){
                    swap(nums1[el1-n],nums2[el2-n]);
                }
                i++;
                j++;
            }
            if(gap==1) break;
            gap = gap/2+gap%2;
        }
        for(int i=n;i<m+n;i++)
            nums1[i] = nums2[i-n];
        return;
    }
};
int main(){

    return 0;
}