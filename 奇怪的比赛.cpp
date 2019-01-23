#include<iostream>  
using namespace std;  
int ans[12];  
int count = 0;
//进行深度搜索，sum代表当前分数，u代表当前答案编号   
void DFS(int sum,int u,int score){  
    //递归出口，当该回答11题的时候（即已经答完10题）   
    if(u==11){  
        if(sum==score){  
            for(int i=1 ;i<11 ;i++){  
                cout<<ans[i];  
            }   
        cout<<endl;
        count++;   
        }                                       
    }  
    else{  
        //答错情况   
        
        ans[u]=0;  
        DFS(sum-u,u+1,score);  
        //答对情况   
        ans[u]=1;  
        DFS(sum*2,u+1,score);  
    }  
}  
int main(){  
    //初始分数10 从1题开始  
	int score;
	cin>>score; 
    DFS(10,1,score);  
    if(count==0)
    	cout<<"No Answer"<<endl;
    return 0;  
} 
