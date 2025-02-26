/**
 * @作者：彭俊杰
 * @描述：通过模块化，编写了冒泡排序函数、选择排序函数、输出棒图函数，然后分别通过调用这些函数完成任务要求的数组排序与对应输出
 * @时间：2023-11-30 23：15：10
 **/
#include <stdio.h>					//调用stdio库
#include <string.h>					//调用stdlib库
#define N 49						//调用time库

void bubbleSort(int cnimport[], char country[][12], int cnexport[], int ieRatio[], int n)	//定义冒泡排序函数
{
	int i, j, temp, temp1;								//定义辅助整型参数
	float temp2;										//定义辅助浮点型参数
	char tempCountry[12];								//定义辅助字符型数组
	for (i = 0; i < n - 1; i++)							//遍历数组长度-1
	{
		for (j = 0; j < n - i - 1; j++)					//遍历剩下未排序的数组长度
		{
			if (cnimport[j] < cnimport[j + 1])			//将相邻进口值作大小对比
			{
				//通过中间变量交换进口值
				temp = cnimport[j];
				cnimport[j] = cnimport[j + 1];
				cnimport[j + 1] = temp;
				
				//通过中间数组同步交换国家值
				strcpy(tempCountry, country[j]);
				strcpy(country[j], country[j + 1]);
				strcpy(country[j + 1], tempCountry);
				
				//通过中间变量同步交换出口值
				temp1 = cnexport[j];
				cnexport[j] = cnexport[j + 1];
				cnexport[j + 1] = temp1;
				
				//通过中间变量同步交换进出口比率
				temp2 = ieRatio[j];
				ieRatio[j] = ieRatio[j + 1];
				ieRatio[j + 1] = temp2;
			}
		}
	}
}

void selectionSort(int cnexport[], char country[][12], int cnimport[], int ieRatio[], int n)	//定义选择排序函数
{
	int i, j, maxIndex, temp,temp1;					//定义辅助整型参数
	char tempCountry[12];							//定义辅助字符型数组
	float temp2;									//定义辅助浮点型参数
	for (i = 0; i < n - 1; i++)						//遍历数组长度-1
	{
		maxIndex = i;								//令最大值的索引为i
		for (j = i + 1; j < n; j++)					//遍历剩下的数组元素
		{
			if (cnexport[j] > cnexport[maxIndex])	//比较元素大小
			{
				maxIndex = j;						//更新最大值索引
			}
		}
		//通过中间变量交换出口值
		temp = cnexport[i];
		cnexport[i] = cnexport[maxIndex];
		cnexport[maxIndex] = temp;
		
		//通过中间数组同步交换国家名
		strcpy(tempCountry, country[i]);
		strcpy(country[i], country[maxIndex]);
		strcpy(country[maxIndex], tempCountry);
		
		//通过中间变量同步交换进口值
		temp1 = cnimport[i];
		cnimport[i] = cnimport[maxIndex];
		cnimport[maxIndex] = temp1;
		
		//通过中间变量同步交换进出口比率
		temp2 = ieRatio[i];
		ieRatio[i] = ieRatio[maxIndex];
		ieRatio[maxIndex] = temp2;
	}
}

void shuchu(int num){								//定义一个输出棒图的函数
	for (int i = 0; i < num; i++) {					//遍历此时的num
		printf("*");								//输出长度为num的棒图
	}
	printf("\n");									//进行换行
}

int main(){											//定义一个主程序
	int i,j;										//定义遍历参数i与j
	//定义四个数组
	char country[N][12] = {"美国", "日本", "韩国", "德国", "越南", "澳大利亚", "马来西亚", "巴西", "俄罗斯", "泰国", "印度", "印度尼西亚", "荷兰", "英国", "新加坡", "沙特阿拉伯", "墨西哥", "法国", "菲律宾", "加拿大", "意大利", "阿联酋", "智利", "南非", "西班牙", "瑞士", "波兰", "比利时", "秘鲁", "伊拉克", "土耳其", "阿曼", "巴基斯坦", "尼日利亚", "哈萨克斯坦", "孟加拉国", "新西兰", "安哥拉", "爱尔兰", "以色列", "科威特", "捷克", "瑞典", "哥伦比亚", "埃及", "乌克兰", "缅甸", "丹麦", "阿根廷"};
	int cnimport[N] = {17970081, 20550277, 21344326, 11991430, 9231942, 16352908, 9830508, 11000670, 7960907, 6183263, 2814551, 6392283, 1400494, 2567686, 3881973, 5696861, 1913928, 3910500, 2476131, 3048978, 3032373, 2857327, 3957795, 3295561, 1228866, 3788005, 554183, 857188, 2423903, 2665311, 504897, 2859710, 358448, 303163, 1129056, 104693, 1615598, 2102743, 1762666, 753454, 1775554, 605328, 987409, 561778, 170358, 977446, 812208, 697291, 712432};
	int cnexport[N] = {57607523, 16581426, 14880548, 11517540, 13789507, 6638009, 7865488, 5361123, 6755117, 6935458, 9750751, 6064749, 10243171, 8702212, 5510346, 3032124, 6743974, 4593066, 5151026, 5151026, 4362921, 4375166, 2629229, 2111525, 3612557, 623357, 3657787, 3038163, 1330132, 1068987, 2915179, 356515, 2424040, 2263626, 1395926, 2409441, 856063, 249142, 532132, 1529400, 436847, 1510814, 1103495, 1435442, 1826461, 940443, 1052395, 1087242, 1068798};
	float ieRatio[N];
	for (i = 0; i < N; i++){																								//遍历ieRatio数组
		ieRatio[i]=cnimport[i]*100.0/cnexport[i]*1.0;																		//通过cnimport数组和cnexport数组得到对应ieRatio的值
	}
	printf("    2021年中国与各国进出口贸易额（单位：万美元）\n---------------------------------------------------\n");		//输出美化语句
	printf("[序号]  国家          进口值          出口值     进出口比率\n");												//输出美化语句
	for (i = 0; i < N; i++)																									//遍历国家数量
		printf("[%-2d]    %-12s%8d        %8d      %8.4lf%%\n", i + 1, country[i], cnimport[i], cnexport[i],ieRatio[i]);	//输出标准格式
	
	getchar();
	//冒泡排序板块
	bubbleSort(cnimport, country, cnexport, ieRatio, N);																	//调用冒泡排序函数
	printf("\n按进口值排序：\n");																							//输出按照进口值排序美化语句
	printf("[序号]    进口值        国家          出口值     进出口比率\n");												//输出美化语句
	for (i = 0; i < N; i++){																								//遍历国家数量
		printf("[%-2d]    %8d        %-12s%8d      %8.4lf%%    ", i + 1, cnimport[i], country[i], cnexport[i],ieRatio[i]);	//输出标准格式
		int num = (int)(cnimport[i]*100.0/cnimport[0]);																		//通过计算等比例缩小进口值
		shuchu(num);																										//输出对应棒图
	}
	
	getchar();
	//选择排序1板块
	selectionSort(cnexport, country, cnimport, ieRatio, N);																	//调用选择排序函数
	printf("\n按出口值排序：\n");																							//输出按照出口值排序美化语句
	printf("[序号]    出口值        国家          进口值     进出口比率\n");												//输出美化语句
	for (i = 0; i < N; i++){																								//遍历国家数量
		printf("[%-2d]    %8d        %-12s%8d      %8.4lf%%    ", i + 1, cnexport[i], country[i], cnimport[i],ieRatio[i]);	//输出标准格式
		int num = (int)(cnexport[i]*100.0/cnexport[0]);																		//通过计算等比例缩小出口值
		shuchu(num);																										//输出对应棒图
	}
		
	getchar();
	//选择排序2板块
	selectionSort(ieRatio, country, cnimport, cnexport, N);																	//调用选择排序函数
	printf("\n按进出口比率排序：\n");																						//输出按照进出口比率排序美化语句
	printf("[序号]进出口比率        国家          进口值         出口值\n");												//输出美化语句
	for (i = 0; i < N; i++){																								//遍历国家数量
		printf("[%-2d] %10.4lf%%        %-12s%8d       %8d    ", i + 1, ieRatio[i], country[i], cnimport[i],cnexport[i]);	//输出标准格式
		int num = (int)(ieRatio[i]*100.0/ieRatio[0]);																		//通过计算等比例缩小进出口比率
		shuchu(num);																										//输出对应棒图
	}
	return 0;																												//若程序正确运行则返回0
}
