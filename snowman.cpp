
#include <iostream>
#include <string>
#include <vector>
#include <array>
//#include <stdio.h>

#include "snowman.hpp"
#include <stdexcept>

using namespace std;
namespace ariel
{
  string snowman(int snownum)
  {
    const int truesize = 8;
    const int place5 = 5;
    const int place6= 6;
    const int place7 = 7;
    string snow;
    const array<string, 4> Hat = {" _===_ \n", "  ___  \n ..... \n", "   _   \n  /_\\  \n",
                                       "  ___  \n (_*_) \n"};
    const array<string, 4> Nose = {",", ".", "_", " "};
    const array<string, 4> Eye = {".", "o", "O", "-"};
    const array<string, 4>LeftArm_Up = {" ", "\\", " ", " "};
    const array<string, 4> LeftArm_Down = {"<", " ", "/", " "};
    const array<string, 4> RightArm_Up = {" ", "/", " ", " "};
    const array<string, 4> RightArm_Down = {">", " ", "\\", " "};
    const array<string, 4> Torso = {" : ", "] [", "> <", "   "};
    const array<string, 4> Base = {" : ",  "\" \"" , "___", "   "};
    
    vector<int> ans = splitdigit(snownum);
    for (int i = 0; i < ans.size(); i++)
    {
      if (ans.size() != truesize || ans[i] > 4|| ans[i] <= 0 )
      {
        throw invalid_argument("recive error input");
        // return "";

        // cout<<" bat input"<< snow;
      }
      }
      
      snow+=Hat.at(ans[0]-1);
      snow+=LeftArm_Up.at(ans[4]-1)+"("+Eye.at(ans[2]-1) + Nose.at(ans[1]-1)+Eye.at(ans[3]-1)+")" + RightArm_Up.at(ans[place5]-1)+"\n";
      snow+=LeftArm_Down.at(ans[4]-1)+"("+Torso.at(ans[place6]-1)+")"+ RightArm_Down.at(ans[place5]-1)+"\n";
      snow+=" ("+Base.at(ans[place7]-1)+")";



    
    return snow;

  }
     
  vector<int> splitdigit(int number)
  {
    const int d=10;
    int n = reversenum(number);
    vector<int> ans;
    while (n >= d)
    {
      ans.push_back(n % d);
      n /= d;
    }
    ans.push_back(n);
    return ans;
  }


  int reversenum(int num)
  {
    const int d=10;
    int rev_num = 0;
    while (num > 0)
    {
      rev_num = rev_num * d + num % d;
      num = num / d;
    }
    return rev_num;
  }

}; // namespace ariel