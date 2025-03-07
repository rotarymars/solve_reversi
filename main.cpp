#include <iostream>
#include <vector>
#include <set>

void remove_except_n(std::set<int>&s,int n){
  for(auto it=s.begin();it!=s.end();){
    if(*it!=n){
      it=s.erase(it);
    }
    else{
      ++it;
    }
  }
  return;
}

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
      std::vector<int>numbercnt(9,0);
      for(int j=0;j<9;++j){
        if(board[i][j].size()==1){
          already.insert(*board[i][j].begin());
        }
        for(auto&k:board[i][j]){
          ++numbercnt[k-1];
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
      for(int j=0;j<9;++j){
        if(numbercnt[j]==1){
          for(int k=0;k<9;++k){
            if(board[i][k].contains(1+j)){
              remove_except_n(board[i][k], 1+j);
            }
          }
        }
      }
    }
    for(int i=0;i<9;++i){
      std::set<int>already;
      std::vector<int>numbercnt(9,0);
      for(int j=0;j<9;++j){
        if(board[j][i].size()==1){
          already.insert(*board[j][i].begin());
        }
        for(auto&k:board[j][i]){
          ++numbercnt[k-1];
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
      for(int j=0;j<9;++j){
        if(numbercnt[j]==1){
          for(int k=0;k<9;++k){
            if(board[k][i].contains(1+j)){
              remove_except_n(board[k][i], 1+j);
            }
          }
        }
      }
    }
    for(int i=0;i<3;++i){
      for(int j=0;j<3;++j){
        std::set<int>already;
        std::vector<int>numbercnt(9,0);
        for(int k=dh[i];k<dh[i]+3;++k){
          for(int l=dw[j];l<dw[j]+3;++l){
            if(board[k][l].size()==1){
              already.insert(*board[k][l].begin());
            }
            for(auto&m:board[k][l]){
              ++numbercnt[m-1];
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
        for(int k=0;k<9;++k){
          if(numbercnt[k]==1){
            for(int l=dh[i];l<dh[i]+3;++l){
              for(int m=dw[j];m<dw[j]+3;++m){
                if(board[l][m].contains(1+k)){
                  remove_except_n(board[l][m], 1+k);
                }
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