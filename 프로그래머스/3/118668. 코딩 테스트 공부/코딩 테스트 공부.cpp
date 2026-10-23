#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[155][155];


int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int max_alp = 0;
    int max_cop = 0;
    
    
    for(int i = 0 ; i < problems.size(); ++i){
        for(int j = 0; j < 2; ++j){
            if(j == 0){
                max_alp = max(max_alp,problems[i][j]);
            }
            else if(j == 1){
                max_cop = max(max_cop, problems[i][j]);
            }
        }
    }
    
    
    
    for(int cur_alp = 0; cur_alp <= max_alp; ++cur_alp){
        for(int cur_cop = 0; cur_cop <= max_cop; ++cur_cop){
            dp[cur_alp][cur_cop] = 10000;
        }
    }
    
    if(alp > max_alp) alp = max_alp;
    if(cop > max_cop) cop = max_cop;
    
    
    dp[alp][cop] = 0;
    
    
    for(int cur_alp = alp; cur_alp <= max_alp; ++cur_alp){
        for(int cur_cop = cop; cur_cop <= max_cop; ++cur_cop){
            for(int i = 0; i < problems.size(); ++i){
                if(problems[i][0] > cur_alp || problems[i][1] > cur_cop) continue;
                int next_alp = cur_alp + problems[i][2];
                int next_cop = cur_cop + problems[i][3];
                
                if(next_alp > max_alp){
                    next_alp = max_alp;
                }
                if(next_cop > max_cop){
                    next_cop = max_cop;
                }
                
                dp[next_alp][next_cop] = min(dp[next_alp][next_cop],dp[cur_alp][cur_cop] + problems[i][4]);
            }
            int next_alp = cur_alp + 1;
            int next_cop = cur_cop + 1;
            
            if(next_alp > max_alp){
                next_alp = max_alp;
            }
            if(next_cop > max_cop){
                next_cop = max_cop;
            }
            
            dp[next_alp][cur_cop] = min(dp[next_alp][cur_cop], dp[cur_alp][cur_cop] + 1);
            dp[cur_alp][next_cop] = min(dp[cur_alp][next_cop], dp[cur_alp][cur_cop] + 1);
        }
    }
    
    answer = dp[max_alp][max_cop];
    
    return answer;
}