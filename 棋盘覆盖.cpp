#include <iostream>
#include <cmath> 
using namespace std; 

int t = 0; 
int board[100][100] = {0}; 
void ChessBoard(int tr, int tc, int dr, int dc, int size){
	int s, t1;                         //t1表示本次覆盖所用L型骨牌的编号 
									   // s为子棋盘的边长 ，tr，tc为子棋盘左上角的坐标 
	if(size == 1)					   //棋盘只有一个方格且是特殊方格 
		return;
	t1 = ++t;                          // L型骨牌编号 
	s = size/2;                        //划分棋盘 
	
	if(dr < tr + s && dc < tc + s)      //特殊方格在左上角子棋盘中 
		ChessBoard(tr,tc,dr,dc,s);
	else{                                //用t1号L型骨牌覆盖右下角，再递归处理子棋盘 
		board[tr+s-1][tc+s-1] = t1;
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	
	if(dr < tr + s && dc >= tc + s)       //特殊方格在右上角子棋盘中
		ChessBoard(tr,tc+s,dr,dc,s);
	else{
		board[tr+s-1][tc+s] = t1;         //用t1号L型骨牌覆盖左下角
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	
	if(dr >= tr + s && dc < tc + s)        //特殊方格在左下角子棋盘中
		ChessBoard(tr+s,tc,dr,dc,s);
	else{
		board[tr+s][tc+s-1] = t1;           //用t1号L型骨牌覆盖右上角
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	
	if(dr >= tr + s && dc >= tc + s)        //特殊方格在右下角子棋盘中
		ChessBoard(tr+s,tc+s,dr,dc,s);
	else{
		board[tr+s][tc+s] = t1;             //用t1号L型骨牌覆盖左上角 
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	}
	
}
int main(int argc, char *argv[]) {
	 
    int size, x, y,k;    // 大小，黑色方格位置
    cout << "请输入棋盘大小:"<<endl;
    cin >> k ;
    cout << "输入黑色方格位置(x,y),左上角为（1,1）:"<<endl; 
    cin >> x >> y;
    size = pow(2,k);
    board[x][y] = 0;   //黑色方块 
    // 分治法填满棋盘
    ChessBoard(0, 0, x-1, y-1, size);
    // 输出该棋盘 
	//三个相同的数字表示一个骨牌，大小顺序为先后填充的顺序 
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << board[i][j] << "\t";
        }
        cout << endl << endl << endl;
    }
    
	return 0;
}
