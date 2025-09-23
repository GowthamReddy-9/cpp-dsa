//GFG:Fractional Knapsack
//https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Partition function for quicksort
    int partition(vector<int>& val, vector<int>& wt, int low, int high) {
        double pivot = (double)val[high] / wt[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            double r = (double)val[j] / wt[j];
            if (r > pivot) {
                i++;
                swap(val[i], val[j]);
                swap(wt[i], wt[j]);
            }
        }
        swap(val[i + 1], val[high]);
        swap(wt[i + 1], wt[high]);
        return i + 1;
    }
    
    void quickSort(vector<int>& val, vector<int>& wt, int low, int high) {
        if (low < high) {
            int pi = partition(val, wt, low, high);
            quickSort(val, wt, low, pi - 1);
            quickSort(val, wt, pi + 1, high);
        }
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // Sort val and wt in-place by ratio (val/wt)
        quickSort(val, wt, 0, n - 1);
        
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            if (wt[i] <= capacity) {
                ans += val[i];
                capacity -= wt[i];
            } else {
                ans += (double)val[i] / wt[i] * capacity;
                break;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> val={60, 100, 120};
    vector<int> wt={10, 20, 30};
    int capacity=50;
    Solution sol;
    cout<<fixed<<setprecision(6)<<(double)sol.fractionalKnapsack(val,wt,capacity);
    return 0;
}