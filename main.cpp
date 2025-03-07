#include <iostream>
#include <vector>
#include <set>

int main() {
  std::vector<std::vector<std::set<int>>>board(9,std::vector<std::set<int>>(9,{1,2,3,4,5,6,7,8,9}));
  for(int i=0;i<9;++i){
    for(int j=0;j<9;++j){
      char c;
      std::cin>>c;
      if(c=='?'){
        continue;
      }
      for(int k=1;k<=9;++k){
        if(c!='0'+k){
          board[i][j].erase(k);
        }
      }
    }
  }
  int dh[]={0,3,6},dw[]={0,3,6};
  bool flag;
  do
  {
    flag=false;
    for(int i=0;i<9;++i){
      std::set<int>already;
      for(int j=0;j<9;++j){
        if(board[i][j].size()==1){
          already.insert(*board[i][j].begin());
        }
      }
      for(int j=0;j<9;++j){
        if(board[i][j].size()!=1){
          for(auto&k:already){
            auto it=board[i][j].find(k);
            if(it==board[i][j].end()){
              continue;
            }
            board[i][j].erase(k);
            flag=true;
          }
        }
      }
    }
    for(int i=0;i<9;++i){
      std::set<int>already;
      for(int j=0;j<9;++j){
        if(board[j][i].size()==1){
          already.insert(*board[j][i].begin());
        }
      }
      for(int j=0;j<9;++j){
        if(board[j][i].size()!=1){
          for(auto&k:already){
            auto it=board[j][i].find(k);
            if(it==board[j][i].end()){
              continue;
            }
            board[j][i].erase(k);
            flag=true;
          }
        }
      }
    }
    for(int i=0;i<3;++i){
      for(int j=0;j<3;++j){
        std::set<int>already;
        for(int k=dh[i];k<dh[i]+3;++k){
          for(int l=dw[j];l<dw[j]+3;++l){
            if(board[k][l].size()==1){
              already.insert(*board[k][l].begin());
            }
          }
        }
        for(int k=dh[i];k<dh[i]+3;++k){
          for(int l=dw[j];l<dw[j]+3;++l){
            if(board[k][l].size()!=1){
              for(auto&m:already){
                auto it=board[k][l].find(m);
                if(it==board[k][l].end()){
                  continue;
                }
                board[k][l].erase(m);
                flag=true;
              }
            }
          }
        }
      }
    }
  } while (flag);
  for(int i=0;i<9;++i){
    for(int j=0;j<9;++j){
      char c=(board[i][j].size()==1?'0'+*board[i][j].begin():'?');
      if(j==0)[[unlikely]]{
        std::cout<<c;
      }
      else{
        std::cout<<' '<<c;
      }
    }
    std::cout<<'\n';
  }
}