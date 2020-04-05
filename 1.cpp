#include<Bangtal.h>
#include<stdio.h>
#pragma comment(lib,"Bangtal.lib")
#include<iostream>
#include<cstdlib>
#include<ctime>


//먼저 장면생성
SceneID scene0, scene1;
//각 블럭과 스타트버튼 선언
ObjectID p[4][4];
ObjectID startbutton;
TimerID timer1;

//각 칸의 x좌표 y좌표 정의
int cX[4] = { 272,272 + 165,272 + 330,272 + 495 };
int cY[4] = { 512,512 - 165,512 - 330,512 - 495 };
//각 블럭의 x,y좌표 정의
int pX[4][4];
int pY[4][4];

//1.왼쪽으로 이동
void moveleft() {

	//이동 시 px[3]-165인 px[k]를 찾아 px[k]를 px[k]+165로 바꾸고 px[3]를 px[3]-165로 바꾼다.

	for (int i = 0; i < 4; i++) {
		//만약 어떤 x좌표가 px[3][3]-165이면 
		for (int k = 0; k < 4; k++) {
			if (pY[i][k] == pY[3][3]) {
				if (pX[i][k] == pX[3][3] - 165) {
					//그 좌표를 px[3][3]으로  바꾸고 
					pX[i][k] = pX[3][3];
					//3,3은 왼쪽으로 이동시킨다.
					pX[3][3] = pX[3][3] - 165;
					//그리고 그 좌표대로 위치시킨다.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}
	


	}

}
//2.오른쪽으로 이동
void moveright() {

	//이동 시 px[3]+165인 px[k]를 찾아 px[k]를 px[k]-165로 바꾸고 px[3]를 px[3]+165로 바꾼다.

	for (int i = 0; i < 4; i++) {
		//만약 어떤 x좌표가 px[3][3]-165이면 

		for (int k = 0; k < 4; k++) {
			if (pY[i][k] == pY[3][3]) {
				if (pX[i][k] == pX[3][3] + 165) {
					//그 좌표를 px[3][3]으로  바꾸고 
					pX[i][k] = pX[3][3];
					//3,3은 오른쪽으로 이동시킨다.
					pX[3][3] = pX[3][3] + 165;
					//그리고 그 좌표대로 위치시킨다.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}




	}


}

//3.위로 이동
void moveup() {
	//이동 시 pY[3]+165인 pY[k]를 찾아 pY[k]를 pY[k]-165로 바꾸고 pY[3]를 pY[3]+165로 바꾼다.

	for (int i = 0; i < 4; i++) {
		//만약 어떤 y좌표가 pY[3][3]-165이면 

		for (int k = 0; k < 4; k++) {
			if (pX[i][k] == pX[3][3]) {
				if (pY[i][k] == pY[3][3] + 165) {
					//그 좌표를 pY[3][3]으로  바꾸고 
					pY[i][k] = pY[3][3];
					//3,3은 위쪽으로 이동시킨다.
					pY[3][3] = pY[3][3] + 165;
					//그리고 그 좌표대로 위치시킨다.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}



	}



}

//4.아래로 이동
void movedown() {
	//이동 시 pY[3]-165인 px[k]를 찾아 pY[k]를 pY[k]+165로 바꾸고 pY[3]를 pY[3]-165로 바꾼다.

	for (int i = 0; i < 4; i++) {
		//만약 어떤 y좌표가 pY[3][3]+165이면 

		for (int k = 0; k < 4; k++) {
			if (pX[i][k] == pX[3][3]) {
				if (pY[i][k] == pY[3][3] - 165) {
					//그 좌표를 pY[3][3]으로  바꾸고 
					pY[i][k] = pY[3][3];
					//3,3은 아래쪽으로 이동시킨다.
					pY[3][3] = pY[3][3] - 165;
					//그리고 그 좌표대로 위치시킨다.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}



	}



}




//시작 버튼을 눌렀을때 함수
//랜덤 배치 필요
//랜덤으로 1,2중 선택
//1이 나오면 x좌표 바꾸기,
	//x좌표가 1번일 경우 오른쪽으로 한칸이동
	//x좌표가 2,3번일 경우 왼쪽 혹은 오른쪽으로 한칸이동(랜덤으로 1,2뽑기)
	//x좌표가 4번일 경우 왼쪽으로 한칸 이동
//2가 나오면 y좌표 바꾸기
void pressbutton() {
	enterScene(scene1);


	

	//시작버튼을 누르면 블록을 무작위로 움직인다.
	for (int i = 0; i <150; i++) {
		//0이면 x를 움직이고
		//1이면 y를 움직인다.
		
		
		int num1;
		num1 = rand() % 2;
		
		
		//나머지가 0이면 x를 움직인다.
		if (num1 == 0) {
			//1번칸이면 오른쪽으로
			if (pX[3][3] == cX[0]) {
				moveright();
			}
			//2번,3번칸이면 왼이나 오로
			else if (pX[3][3] == cX[1] || pX[3][3] == cX[2]) {
				int num2;
				num2 = rand() % 2;
				//0이나오면 왼쪽
				if (num2 == 0) {
					moveleft();

				}
				//1이 나오면 오른쪽
				else {
					moveright();

				}

			}
			//4번칸이면 왼쪽
			else {
				moveleft();

			}
			

		}
		else if( num1 == 1 ) {
			//1번칸이면 아래쪽으로
			if (pY[3][3] == cY[0]) {
				movedown();
			}
			//2번,3번칸이면 왼이나 오로
			else if (pY[3][3] == cY[1] || pY[3][3] == cY[2]) {
				int num2;
				num2 = rand() % 2;

				//0이나오면 아래쪽
				if (num2 == 0) {
					movedown();

				}
				//1이 나오면 위쪽
				else {
					moveup();

				}

			}
			//4번칸이면 위쪽
			else {
				moveup();

			}



		}
		hideObject(startbutton);
	}

	

}









void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	//시작 버튼을 누르면 무작위로 섞는다.
	if (object == startbutton) {
		pressbutton();
		
	}
	
	int cnt = 0;

	
	for (int i = 0; i < 4; i++) {

		for (int k = 0; k < 4; k++) {

		




			if (object == p[i][k]) {
				//경우1<위>. 하얀블록--> 클릭한 블록 아래 있을때 
				//x좌표는 같고, y좌표는 +165 인경우
				//위로 움직인다.
				if (pX[i][k] == pX[3][3] && pY[i][k] == pY[3][3] + 165) {
					moveup();
				}
				
				//경우2<아래> 하얀블록--> 클릭한 블록 위에 있을때
				//x좌표는 같고 y좌표는 -165 인경우
				//아래로 움직인다.
				else if (pX[i][k]== pX[3][3] && pY[i][k] == pY[3][3] - 165) {
					movedown();

				}
				//경우3<왼쪽> 하얀블록-->클릭한 블록의 오른쪽에 있을때
				//y좌표는 같고 x좌표는 +165일때
				//왼쪽으로 움직인다.
				else if (pY[i][k] == pY[3][3] && pX[i][k] == pX[3][3] + 165) {
					moveright();

				}
				//경우4<왼쪽> 하얀블록-->클릭한 블록의 왼쪽에 있을때
				//y좌표는 같고 x좌표는 -165일때
				//오른쪽으로 움직인다.
				else if (pY[i][k] == pY[3][3] && pX[i][k] == pX[3][3] - 165) {
					moveleft();

				}
			}
			
			if (pX[k][i] == cX[i]) {
				cnt++;
			}
			if (pY[k][i] == cY[k]) {
				cnt++;
			}
			//윗쪽에서 내릴때는 cnt가 32이나 마지막에 가로로 옮겨서 퍼즐을 완성할 경우 cnt=31임..
			if (cnt == 32||cnt==31) {
				setObjectImage(startbutton, "restart.png");
				showObject(startbutton);
				enterScene(scene0);

			}
		
		
		}
	}

	//만약 클릭한 지점의 좌표가 y축 방면으로 p[3,3]과 이웃하여 있다면
	//클릭한 지점의 py와 py[3]의 좌표를 바꿔준다.




}




int main() {
	

	srand(time(0));
	//마우스 콜백
	setMouseCallback(mouseCallback);

	scene0 = createScene("슬라이드 퍼즐", "원본.jpg");
	scene1 = createScene("슬라이드 퍼즐", "배경.png");
	//각각의 퍼즐을 이차원 배열로 설정
	//왼쪽위가 기준점
	p[0][0] = createObject("톰", "p11.png");
	p[0][1] = createObject("톰", "p12.png");
	p[0][2] = createObject("톰", "p13.png");
	p[0][3] = createObject("톰", "p14.png");
	p[1][0] = createObject("톰", "p21.png");
	p[1][1] = createObject("톰", "p22.png");
	p[1][2] = createObject("톰", "p23.png");
	p[1][3] = createObject("톰", "p24.png");
	p[2][0] = createObject("톰", "p31.png");
	p[2][1] = createObject("톰", "p32.png");
	p[2][2] = createObject("톰", "p33.png");
	p[2][3] = createObject("톰", "p34.png");
	p[3][0] = createObject("톰", "p41.png");
	p[3][1] = createObject("톰", "p42.png");
	p[3][2] = createObject("톰", "p43.png");
	p[3][3] = createObject("빈칸", "p445.png");

	//x=가로, y=세로
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			pX[y][x] = cX[x];
			pY[y][x] = cY[y];
			locateObject(p[y][x], scene1, pX[y][x], pY[y][x]);
			showObject(p[y][x]);
		}

	}
	startbutton = createObject("시작 버튼", "start.png");
	locateObject(startbutton, scene0, 550, 100);
	showObject(startbutton);

	startGame(scene0);


}