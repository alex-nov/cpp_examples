#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        print( prices );

        int buy = prices[ 0 ];
        int profit, currentProfit, totalProfit;
        profit = currentProfit = totalProfit = 0;
        for( auto & price : prices )
        {
            currentProfit = price - buy;
            cout << "curProfit=" << currentProfit << endl;
            buy = std::min( buy, price );
            if( currentProfit > profit )
            {
                profit = currentProfit;
            }
            else if( profit > 0 )
            {
                totalProfit += profit;
                cout << "price=" << price << " profit=" << profit << " totalProfit=" << totalProfit << endl;
                currentProfit = profit = 0;
                buy = price;
            }
        }
        if(currentProfit > 0) totalProfit += currentProfit;
        return totalProfit;
    }

    void print( vector<int>& nums  )
    {
      for( auto & a : nums )
      cout << a << " ";
      cout << std::endl << std::endl;
    }

};



int main()
{
  std::vector< int > prices{7,1,5,3,6,4};
  std::vector< int > prices1{1,2,3,4,5};
  std::vector< int > prices2{7,5,4,2,1};
  Solution n;
  cout << "maxProfit=" << n.maxProfit( prices ) << endl;
  cout << "maxProfit=" << n.maxProfit( prices1 ) << endl;
  cout << "maxProfit=" << n.maxProfit( prices2 ) << endl;
  
  return 0;
}
