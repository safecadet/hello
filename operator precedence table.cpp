#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"ENTER NUMBER OF OPERATORS\n";
	cin>>n;
	cout<<"ENTER OPERATORS";
	string op[n];
	for (int i=0;i<n;i++){
		cin>>op[i];
	}
	
	cout<<"ENTER PRECEDENCE\n";
//	cout<<"OPERATORS ARE \n+  -  *  /  ^  i  $\n";
for(int i=0;i<n;i++){
 cout<< "  "<<op[i];
}
	string p[n][n];
	for(int i=0;i<n;i++){
		cout<<"\n"<<op[i];
		for(int j=0;j<n;j++){
			cin>>p[i][j];
		}
	}
	
	vector<int> a[2*n],at[2*n];
	int deg[2*n],val[2*n];
	for(int i=0;i<2*n;i++){
		deg[i]=0;
		val[i]=-1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(p[i][j]==".>"){
				a[i].push_back(n+j);
				at[n+j].push_back(i);
				deg[i]++;
			}
			else if(p[i][j]=="<."){
				a[n+j].push_back(i);
				at[i].push_back(n+j);
				deg[n+j]++;
			}
		}
	}
	queue<int>q;
	for(int i=0;i<2*n;i++){
		if(deg[i]==0){
			q.push(i);
			val[i]=0;
		}
	}
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(int i=0;i<at[f].size();i++){
			int v=at[f][i];
			val[v]=max(val[v],val[f]+1);
			deg[v]--;
			if(deg[v]<=0){
				q.push(v);
			}
		}
	}
	bool flag=true;
	for(int i=0;i<2*n;i++){
		if(val[i]==-1){
			flag=false;
		}
	}
	if(!flag){
		cout<<"THERE DOES NOT EXIST ANY PRECEDENCE FUNCTION !!";
	}
	else{cout<< "      ";
		for(int i=0;i<n;i++){
        cout<<op[i]<<" ";
}
		//cout<< "\n    + - * / ^ i";
		cout<< "\nf : ";
		for(int i=0;i<n;i++){
			cout<<val[i]<<" ";
		}
		cout<<"\ng : ";
		for(int i=0;i<n;i++){
			cout<<val[n+i]<<" ";
		}
	}
}
