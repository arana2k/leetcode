// DAY 1 (121. Best Time to Buy and Sell Stock)===============================================================================

int maxProfit(vector<int> &prices)
{
    int mn = INT_MAX, ans = 0;
    for (int x : prices)
    {
        ans = max(ans, x - mn);
        mn = min(mn, x);
    }
    return ans;
}
