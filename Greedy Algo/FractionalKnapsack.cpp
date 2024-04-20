#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double optimal(vector<pair<int, int>> &items, int n, int W) {
    // Calculate profit-to-weight ratio and sort items based on this ratio in descending order
    vector<pair<double, pair<int, int>>> itemRatios;
    for (auto &item : items) {
        double ratio = (double)item.second / item.first; // profit / weight
        itemRatios.push_back({ratio, {item.first, item.second}});
    }

    sort(itemRatios.rbegin(), itemRatios.rend()); // Sort in descending order

    double profit = 0;
    for (int i = 0; i < n && W > 0; ++i) {
        if (itemRatios[i].second.first <= W) { // If the whole item can be taken
            W -= itemRatios[i].second.first;
            profit += itemRatios[i].second.second;
        } else { // Take fraction of the item
            profit += itemRatios[i].first * W; // ratio * remaining weight
            break;
        }
    }

    return profit;
}

int main() {
    vector<pair<int, int>> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50; // Adjusted weight for demonstration
    double ans = optimal(items, items.size(), W);
    cout << "The maximum possible profit is: " << ans;
    return 0;
}
