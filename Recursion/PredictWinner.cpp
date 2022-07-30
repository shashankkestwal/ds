#include <bits/stdc++.h>
using namespace std;

bool PredictTheWinner(vector<int>& nums) {
        int score1 = 0;
        int score2 = 0;
        while( nums.size() != 0) {
            if(nums.size() == 1) break;
            cout << nums.size() << endl;
            int choose1, choose2;
            if(nums[0] > nums[nums.size()-1] ) {
                choose1 = nums[0];
                nums.erase(nums.begin());
            } else {
                choose1 =  nums[nums.size()-1];
                nums.pop_back();
            }
            cout << "player 1 chose " << choose1 << endl;
            if(nums[0] > nums[nums.size()-1] ) {
                choose2 = nums[0];
                nums.erase(nums.begin());
            } else {
                choose2 =  nums[nums.size()-1];
                nums.pop_back();
            }
            cout << "player 2 chose " << choose2 << endl;
            if(choose1  > choose2) {
                score1++;
                cout << "Player 1 wins" << endl;
            }

            else {
                score2++;
                cout << "Player 2 wins" << endl;
            }
            cout << endl << endl;
        }
        if(score1 >= score2) {
            cout << "player 1 is winner";
            return true;
        }
        cout << "player 2 is winner" ;
        return false;
    }


int main() {
    vector<int> nums = {1,5,233,7};
    PredictTheWinner(nums);
    return 0;
}