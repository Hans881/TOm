#include<Bangtal.h>
#include<stdio.h>
#pragma comment(lib,"Bangtal.lib")
#include<iostream>
#include<cstdlib>
#include<ctime>


//���� ������
SceneID scene0, scene1;
//�� ���� ��ŸƮ��ư ����
ObjectID p[4][4];
ObjectID startbutton;
TimerID timer1;

//�� ĭ�� x��ǥ y��ǥ ����
int cX[4] = { 272,272 + 165,272 + 330,272 + 495 };
int cY[4] = { 512,512 - 165,512 - 330,512 - 495 };
//�� ���� x,y��ǥ ����
int pX[4][4];
int pY[4][4];

//1.�������� �̵�
void moveleft() {

	//�̵� �� px[3]-165�� px[k]�� ã�� px[k]�� px[k]+165�� �ٲٰ� px[3]�� px[3]-165�� �ٲ۴�.

	for (int i = 0; i < 4; i++) {
		//���� � x��ǥ�� px[3][3]-165�̸� 
		for (int k = 0; k < 4; k++) {
			if (pY[i][k] == pY[3][3]) {
				if (pX[i][k] == pX[3][3] - 165) {
					//�� ��ǥ�� px[3][3]����  �ٲٰ� 
					pX[i][k] = pX[3][3];
					//3,3�� �������� �̵���Ų��.
					pX[3][3] = pX[3][3] - 165;
					//�׸��� �� ��ǥ��� ��ġ��Ų��.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}
	


	}

}
//2.���������� �̵�
void moveright() {

	//�̵� �� px[3]+165�� px[k]�� ã�� px[k]�� px[k]-165�� �ٲٰ� px[3]�� px[3]+165�� �ٲ۴�.

	for (int i = 0; i < 4; i++) {
		//���� � x��ǥ�� px[3][3]-165�̸� 

		for (int k = 0; k < 4; k++) {
			if (pY[i][k] == pY[3][3]) {
				if (pX[i][k] == pX[3][3] + 165) {
					//�� ��ǥ�� px[3][3]����  �ٲٰ� 
					pX[i][k] = pX[3][3];
					//3,3�� ���������� �̵���Ų��.
					pX[3][3] = pX[3][3] + 165;
					//�׸��� �� ��ǥ��� ��ġ��Ų��.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}




	}


}

//3.���� �̵�
void moveup() {
	//�̵� �� pY[3]+165�� pY[k]�� ã�� pY[k]�� pY[k]-165�� �ٲٰ� pY[3]�� pY[3]+165�� �ٲ۴�.

	for (int i = 0; i < 4; i++) {
		//���� � y��ǥ�� pY[3][3]-165�̸� 

		for (int k = 0; k < 4; k++) {
			if (pX[i][k] == pX[3][3]) {
				if (pY[i][k] == pY[3][3] + 165) {
					//�� ��ǥ�� pY[3][3]����  �ٲٰ� 
					pY[i][k] = pY[3][3];
					//3,3�� �������� �̵���Ų��.
					pY[3][3] = pY[3][3] + 165;
					//�׸��� �� ��ǥ��� ��ġ��Ų��.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}



	}



}

//4.�Ʒ��� �̵�
void movedown() {
	//�̵� �� pY[3]-165�� px[k]�� ã�� pY[k]�� pY[k]+165�� �ٲٰ� pY[3]�� pY[3]-165�� �ٲ۴�.

	for (int i = 0; i < 4; i++) {
		//���� � y��ǥ�� pY[3][3]+165�̸� 

		for (int k = 0; k < 4; k++) {
			if (pX[i][k] == pX[3][3]) {
				if (pY[i][k] == pY[3][3] - 165) {
					//�� ��ǥ�� pY[3][3]����  �ٲٰ� 
					pY[i][k] = pY[3][3];
					//3,3�� �Ʒ������� �̵���Ų��.
					pY[3][3] = pY[3][3] - 165;
					//�׸��� �� ��ǥ��� ��ġ��Ų��.
					locateObject(p[i][k], scene1, pX[i][k], pY[i][k]);
					locateObject(p[3][3], scene1, pX[3][3], pY[3][3]);
					k = 5;
					i = 5;

				}
			}


		}



	}



}




//���� ��ư�� �������� �Լ�
//���� ��ġ �ʿ�
//�������� 1,2�� ����
//1�� ������ x��ǥ �ٲٱ�,
	//x��ǥ�� 1���� ��� ���������� ��ĭ�̵�
	//x��ǥ�� 2,3���� ��� ���� Ȥ�� ���������� ��ĭ�̵�(�������� 1,2�̱�)
	//x��ǥ�� 4���� ��� �������� ��ĭ �̵�
//2�� ������ y��ǥ �ٲٱ�
void pressbutton() {
	enterScene(scene1);


	

	//���۹�ư�� ������ ����� �������� �����δ�.
	for (int i = 0; i <150; i++) {
		//0�̸� x�� �����̰�
		//1�̸� y�� �����δ�.
		
		
		int num1;
		num1 = rand() % 2;
		
		
		//�������� 0�̸� x�� �����δ�.
		if (num1 == 0) {
			//1��ĭ�̸� ����������
			if (pX[3][3] == cX[0]) {
				moveright();
			}
			//2��,3��ĭ�̸� ���̳� ����
			else if (pX[3][3] == cX[1] || pX[3][3] == cX[2]) {
				int num2;
				num2 = rand() % 2;
				//0�̳����� ����
				if (num2 == 0) {
					moveleft();

				}
				//1�� ������ ������
				else {
					moveright();

				}

			}
			//4��ĭ�̸� ����
			else {
				moveleft();

			}
			

		}
		else if( num1 == 1 ) {
			//1��ĭ�̸� �Ʒ�������
			if (pY[3][3] == cY[0]) {
				movedown();
			}
			//2��,3��ĭ�̸� ���̳� ����
			else if (pY[3][3] == cY[1] || pY[3][3] == cY[2]) {
				int num2;
				num2 = rand() % 2;

				//0�̳����� �Ʒ���
				if (num2 == 0) {
					movedown();

				}
				//1�� ������ ����
				else {
					moveup();

				}

			}
			//4��ĭ�̸� ����
			else {
				moveup();

			}



		}
		hideObject(startbutton);
	}

	

}









void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

	//���� ��ư�� ������ �������� ���´�.
	if (object == startbutton) {
		pressbutton();
		
	}
	
	int cnt = 0;

	
	for (int i = 0; i < 4; i++) {

		for (int k = 0; k < 4; k++) {

		




			if (object == p[i][k]) {
				//���1<��>. �Ͼ���--> Ŭ���� ��� �Ʒ� ������ 
				//x��ǥ�� ����, y��ǥ�� +165 �ΰ��
				//���� �����δ�.
				if (pX[i][k] == pX[3][3] && pY[i][k] == pY[3][3] + 165) {
					moveup();
				}
				
				//���2<�Ʒ�> �Ͼ���--> Ŭ���� ��� ���� ������
				//x��ǥ�� ���� y��ǥ�� -165 �ΰ��
				//�Ʒ��� �����δ�.
				else if (pX[i][k]== pX[3][3] && pY[i][k] == pY[3][3] - 165) {
					movedown();

				}
				//���3<����> �Ͼ���-->Ŭ���� ����� �����ʿ� ������
				//y��ǥ�� ���� x��ǥ�� +165�϶�
				//�������� �����δ�.
				else if (pY[i][k] == pY[3][3] && pX[i][k] == pX[3][3] + 165) {
					moveright();

				}
				//���4<����> �Ͼ���-->Ŭ���� ����� ���ʿ� ������
				//y��ǥ�� ���� x��ǥ�� -165�϶�
				//���������� �����δ�.
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
			//���ʿ��� �������� cnt�� 32�̳� �������� ���η� �Űܼ� ������ �ϼ��� ��� cnt=31��..
			if (cnt == 32||cnt==31) {
				setObjectImage(startbutton, "restart.png");
				showObject(startbutton);
				enterScene(scene0);

			}
		
		
		}
	}

	//���� Ŭ���� ������ ��ǥ�� y�� ������� p[3,3]�� �̿��Ͽ� �ִٸ�
	//Ŭ���� ������ py�� py[3]�� ��ǥ�� �ٲ��ش�.




}




int main() {
	

	srand(time(0));
	//���콺 �ݹ�
	setMouseCallback(mouseCallback);

	scene0 = createScene("�����̵� ����", "����.jpg");
	scene1 = createScene("�����̵� ����", "���.png");
	//������ ������ ������ �迭�� ����
	//�������� ������
	p[0][0] = createObject("��", "p11.png");
	p[0][1] = createObject("��", "p12.png");
	p[0][2] = createObject("��", "p13.png");
	p[0][3] = createObject("��", "p14.png");
	p[1][0] = createObject("��", "p21.png");
	p[1][1] = createObject("��", "p22.png");
	p[1][2] = createObject("��", "p23.png");
	p[1][3] = createObject("��", "p24.png");
	p[2][0] = createObject("��", "p31.png");
	p[2][1] = createObject("��", "p32.png");
	p[2][2] = createObject("��", "p33.png");
	p[2][3] = createObject("��", "p34.png");
	p[3][0] = createObject("��", "p41.png");
	p[3][1] = createObject("��", "p42.png");
	p[3][2] = createObject("��", "p43.png");
	p[3][3] = createObject("��ĭ", "p445.png");

	//x=����, y=����
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			pX[y][x] = cX[x];
			pY[y][x] = cY[y];
			locateObject(p[y][x], scene1, pX[y][x], pY[y][x]);
			showObject(p[y][x]);
		}

	}
	startbutton = createObject("���� ��ư", "start.png");
	locateObject(startbutton, scene0, 550, 100);
	showObject(startbutton);

	startGame(scene0);


}