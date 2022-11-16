#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int v,e;
	cout<<"Please enter the number of vertices (V): ";
	cin>>v;
	cout<<"Please enter the number of edges (E): ";
	cin>>e;
 
	vector<vector<int> > adjlist(v);
	vector<vector<int> > parents(v);
	cout<<"Please enter the edges (0-based): "<<endl;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		adjlist[x].push_back(y);
		parents[y].push_back(x);
	}
 
	vector<vector<int> > matrix(v,vector<int>(v,1));
	for(int i=0;i<v;i++){
		if(i==0){
			matrix[0][i]=1;
		}
		else{
			matrix[0][i]=0;
		}
 
	}
 
	bool change=true;
	while(change){
		change=false;
		for(int i=1;i<v;i++){
			vector<int> new_dominator(v,1);
			for(int j=0;j<parents[i].size();j++){
				int p=parents[i][j];
				vector<int> parent_dominator=matrix[p];
				for(int k=0;k<v;k++){
					new_dominator[k]&=parent_dominator[k];
				}
			}
			new_dominator[i]=1;
			if(new_dominator!=matrix[i]){
				change=true;
			}
			matrix[i]=new_dominator;
		}
	}
	cout<<endl;
	cout<<"The dominators are: "<<endl;
	for(int i=0;i<v;i++){
		cout<<i<<" : ";
		for(int j=0;j<v;j++){
			if(matrix[i][j]==1){
				cout<<j<<" ";
			}
		}
		cout<<endl;
 
	}
}
