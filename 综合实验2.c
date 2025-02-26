/**
 * @作者：彭俊杰
 * @描述：通过冒泡排序与选择排序实现数据的从大到小/从小到大排序，并输出棒图
 * @时间：2023-11-30 22：49：10
 **/
#include <stdio.h>									//调用stdio库
#include <stdlib.h>									//调用stdlib库
#include <time.h>									//调用time库

void shuchu(int num){								//定义输出棒图函数，参数为整型num
	for (int i=0;i<num;i++) {						//遍历num
		printf("*");								//每次输出一个*
	}
	printf("\n");									//一次棒图输出结束后换行
}

int main(){											//定义一个主函数
	int rArray[20]={0};								//定义一个长度为10的一维整型数组
	//char cArray[51]={'\0'};可以不需要此行代码
	srand((unsigned)time(NULL));					//定义随机函数的初始种子
	for (int i=0;i<20;i++){							//遍历数组长度产生随机整数
		rArray[i]=rand()%50+1;						//通过rand函数与计算公式将随机数控制在1~50
	}
	printf("可视化棒图如下：\n");					//输出美化语句
	printf("\n");									//输出换行符，使程序界面更加美观
	for (int i=0;i<20;i++){							//遍历数组长度
		printf("[%-2d]    %2d   ",i,rArray[i]);		//输出标准格式
		shuchu(rArray[i]);							//调用输出函数将棒图补充到后面
	}
	printf("\n");									//输出换行符，使程序界面更加美观
	printf("等待键盘打印回车继续程序……");			//输出提示语句
	getchar();										//读入回车键才继续往下执行
	printf("\n");									//输出换行符，使程序界面更加美观
	printf("冒泡排序后的可视化棒图如下：\n");		//输出美化语句
	printf("\n");									//输出换行符使程序界面美观
	for (int i=0;i<20;i++){							//遍历数组长度
		for (int j=0;j<20;j++){						//再次遍历数组长度进行冒泡排序对比
			if (rArray[j]<=rArray[j+1]){			//相邻元素进行大小对比，将大的元素往前放
				int k=rArray[j];					//通过中间变量k进行元素对调
				rArray[j]=rArray[j+1];
				rArray[j+1]=k;
			}
		}
	}
	for (int i=0;i<20;i++){							//遍历数组长度
		printf("[%-2d]    %2d   ",i,rArray[i]);		//输出标准格式
		shuchu(rArray[i]);							//调用输出函数将棒图补充到后面
	}
	printf("\n");									//输出换行符，使程序界面更加美观
	printf("等待键盘打印回车继续程序……");			//输出提示语句
	getchar();										//读入回车键才继续往下执行
	printf("\n");									//输出换行符，使程序界面更加美观
	printf("选择排序后的可视化棒图如下：\n");		//输出美化语句
	printf("\n");									//输出换行符使程序界面美观
	for (int j=0;j<20;j++){							//遍历数组长度
		int min=rArray[j];							//先定义最小值为数组第一个元素
		for (int i=j;i<20;i++){						//遍历数组长度
			if (rArray[i]<min){						//将此元素与min值对比
				min=rArray[i];						//更新min值
			}
		}
		for (int i=j;i<20;i++){						//遍历数组长度
			if (rArray[i]==min){					//找出等于min值的位置
				rArray[i]=rArray[j];				//将此时的最小值与第一个元素对调
				rArray[j]=min;
			}
		}
	}
	for (int i=0;i<20;i++){							//遍历数组长度
		printf("[%-2d]    %2d   ",i,rArray[i]);		//输出标准格式
		shuchu(rArray[i]);							//调用输出函数将棒图补充到后面
	}
	printf("\n");									//输出换行符，使程序界面更加美观
	printf("等待键盘打印回车结束程序");				//输出提示语句
	return 0;										//若程序正确运行则返回0
}


