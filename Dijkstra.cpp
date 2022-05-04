#include<iostream>
#include <vector>
using namespace std;
const int inf = 100000;
const int n = 6;
vector<int> path[n];
int dis[n];
int L[n][n] = { 0, 7, 9, inf, inf, 14,
                7, 0, 10, 15, inf, inf,
                9, 10, 0, 11, inf, 2,
                inf, 15, 11, 0, 6, inf,
                inf, inf, inf, 6, 0, 9,
                14, inf, 2, inf, 9, 0
              };               
int main(){
	for (int i = 0; i < n; i++){             
		dis[i] = L[0][i];
		path[i].push_back(1);
		path[i].push_back(i+1);
	}
	for (int i = 1; i < n; i++){
		for (int j = 0; j < n; j++){
			//dis[i] = min(dis[i],dis[j] + L[j][i]);
			if (dis[i] > dis[j] + L[j][i]){             
                dis[i] = dis[j] + L[j][i];		
				path[i].clear();                         
				path[i].insert(path[i].end(), path[j].begin(),path[j].end());
				path[i].push_back(i+1);
			}
		}
		for (int m = 0; m < i; m++){              
			for(int j = 0; j < n; j++){
				if (dis[m] > dis[j] + L[j][m]){
					dis[m] = dis[j] + L[j][m];
					path[m].clear();                     
					path[m].insert(path[m].end(), path[j].begin(), path[j].end());
					path[m].push_back(m + 1);
				}
			}
		}
	}
	vector<int>::iterator ite;
	for (int i = 0; i < n; i++){
		cout<<"1"<<"to"<<i+1<<"shortest length:"<<dis[i]<<endl<<"Path:";
	    for (ite = path[i].begin(); ite !=path[i].end();++ite) {
		    if (ite == path[i].begin())
			    cout << *ite;
		    else
			    cout << "->"<< *ite ;
	}
	    cout << endl;
	}
	return 0;
}


