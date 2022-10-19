#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
          ans = max(ans, min(height[l], height[r]) * (r - l));
          if (height[l] < height[r]){
            ++l;}
          else{
            --r;
          }
        }
    return ans;
    }

int main(){
    vector<int> arr={10,20,4,8,92,1,87};
    cout<<"Max Area = "<<maxArea(arr);
    return 0; 
}
