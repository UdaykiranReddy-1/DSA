#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NumberOfDaysForProfit(vector<int> prices){
    int size = prices.size();
    vector<int> nge(size,0);
    stack<int> st;

    for(int i=0;i<size;i++){
        while(!st.empty() && prices[st.top()] < prices[i]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> result(size);
    for(int i=0;i<size;i++){
        if(nge[i] == 0) result[i] =  0;
        else{
            result[i] = nge[i] - i;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    vector<int> output = NumberOfDaysForProfit(prices);

    for(int i=0;i<n;i++){
        cout << output[i] << " ";
    }
    return 0;
}