//#include<iostream>
//#include<fstream>
//#include<string>
//#include<sstream>
//#include<vector>
//#include<algorithm>
//#include<functional>
//#include<map>
//using  namespace std;
//#define MaxSize  1000
////����֮�����ľ���
//#define MAXCOST  1000
//#define CARNUM   15000
//
//
//
//
////���� ӵ��Ԥ�⹫ʽ��ֵ
//#define THRESHOLD 10
//
////���� ��ʽ�ı���
//#define Alpha    0.5
//#define Beta     0.15
//#define Gamma    0.35
////���� ���Ƶ�ƽ���ĵ�·�ݻ�
//#define AVE_VOL  10
//
//int dist[MaxSize][MaxSize];// ����ڵ�����������õ����·��
//string path[MaxSize][MaxSize];// vi��vj�����·��
//
//template<class T>
//struct Graph
//{
//	T vertex[MaxSize];// ���ͼ�ж��������
//	T road[MaxSize][MaxSize];//���·�����Ƶ�����
//	int arc[MaxSize][MaxSize];// ���ͼ�бߵ�����
//	int vertexNum, arcNum;// ͼ�ж������ͱ���
//};
//
//map<int, int> RoadDens;
//
//
//
//
//
//int AllTime=0;
////int CarTimes[310];
///*
//
//���������㷨�������·��
//
//*/
//void Floyd(Graph<string> G)
//{
//	// ��ʼ��
//	for (int i = 0; i < G.vertexNum; i++)
//		for (int j = 0; j < G.vertexNum; j++)
//		{
//			if (i == j) { dist[i][j] = 0; path[i][j] = ""; }
//			dist[i][j] = G.arc[i][j];
//			if (dist[i][j] != MAXCOST) {
//
//				path[i][j] = G.road[i][j] + ",";
//			}
//			else
//				path[i][j] = " ";
//		}
//	// ����n�ε���
//	for (int k = 0; k < G.vertexNum; k++)
//		for (int i = 0; i < G.vertexNum; i++)
//			for (int j = 0; j < G.vertexNum; j++)
//				if (dist[i][k] + dist[k][j] < dist[i][j])
//				{
//					dist[i][j] = dist[i][k] + dist[k][j];
//					path[i][j] = path[i][k] + path[k][j];
//				}
//}
//
//
//
//
///*
//
//����ÿ���������·���µ�����ʱ��
//
//*/
//int Time(string path, int array[][7], int speed, int carNum) {
//	string str;
//	int roadway[100];
//	int s = 0;
//	int realSpeed;
//	int time = 0;
//	for (int i = 0; i < path.length(); i++) {
//		if (path[i] == ',') {
//			roadway[s] = atoi(str.c_str());
//			str = "";
//			s++;
//			continue;
//		}
//		str += path[i];
//	}
//
//	for (int i = 0; i < s; i++) {
//		for (int j = 1; j <= carNum; j++) {
//			if (roadway[i] == array[j][0]) {
//				realSpeed = speed > array[j][2] ? array[j][2] : speed;
//				time += array[j][1] / realSpeed;
//			}
//		}
//
//	}
//	return time;
//}
//
//
//
//
//
//
////int OnebyOne(int time, int plan, int team) {
////	int start;
////	if (plan > CarTimes[team])
////		CarTimes[team] = plan;
////	start = CarTimes[team];
////	CarTimes[team] += time;
////	return start;
////}
//
////����Ԥ��ģ�ͺ���
//
////ע�⣺prestart����������ÿ��·һ���ģ�û�а���·����·���������������
//double Density(int speed, int length, int channel,int PreStart,int CurrentCount, double OldDensity) {
//	int  vol = channel * length / speed;
//	double vol2 = static_cast<double>(vol);
//	double Count = static_cast<double>(CurrentCount);
//	double part1 = Count / vol2;
//	double density = Alpha * part1 + OldDensity * Beta + PreStart * Gamma;
//	return density;
//}
//
//
//
///*
//
//������
//
//*/
//int main()
//{
//	//ͼ���������������Լ����峤��
//	int row, col, cost;
//	//ͼ����
//	Graph<string> G;
//
//	//˫����2��·�ĵ�·������
//	int roadNum = 0;
//	//����������
//	int carNum = -1;
//	//����˫��ĵ�·����
//	int AvenueNum = -1;
//	//·��������
//	int crossnum = -1;
//
//
//
//
//
//
//
//	//   //��ȡroad��cross��car�ļ�
//	   //ifstream road("F:\\cppwork\\competition\\car_road_cross\\road.txt");
//	   //ifstream cross("F:\\cppwork\\competition\\car_road_cross\\cross.txt");
//	   //ifstream car("F:\\cppwork\\competition\\car_road_cross\\car.txt");
//
//	   //ofstream mycout("F:\\cppwork\\competition\\car_road_cross\\answer.txt");
//
//		   //��ȡroad��cross��car�ļ�
//	ifstream road("F:\\SDK\\SDK_C++\\config\\road.txt");
//	ifstream cross("F:\\SDK\\SDK_C++\\config\\cross.txt");
//	ifstream car("F:\\SDK\\SDK_C++\\config\\car.txt");
//
//	ofstream mycout("F:\\SDK\\SDK_C++\\config\\answer.txt");
//
//	//��ʱ����
//	string str, str2, str3;
//
//	//�����·��Ϣ����
//	int roadArray[MaxSize][7];
//	//����ĳ�����Ϣ����
//	int carArray[CARNUM][5];
//	//����������
//	string dispatch[CARNUM];
//
//	//��·�����ַ���
//	string temp[MaxSize];
//
//	/*
//	��ȡcross������
//	*/
//	while (!cross.eof())
//	{
//		cross >> str2;
//		int size = str2.length();
//		if (str2[size - 1] == ')')
//			crossnum++;
//	}
//	G.vertexNum = crossnum + 1;
//
//
//	/*
//	��ȡcar.txt���õ�������Ϣ
//	*/
//	while (!car.eof()) {
//		carNum++;
//		if (carNum == 0) {
//			car >> str3;
//			continue;
//		}
//		else {
//
//			for (int i = 0; i < 5; i++) {
//				car >> str3;
//				if (i == 0) {
//					str3.erase(0, 1);
//				}
//				int size = str3.length();
//				str3.erase(size - 1, 1);
//				carArray[carNum][i] = atoi(str3.c_str());
//			}
//		}
//	}
//
//	/*
//	��ȡroad.txt���õ����ȣ���˫�����ӵĶϵ���Ϣ
//	*/
//	while (!road.eof()) {
//		AvenueNum++;
//		if (AvenueNum == 0) {
//			road >> str;
//			continue;
//		}
//		else {
//
//			for (int i = 0; i < 7; i++) {
//				road >> str;
//				if (i == 0) {
//					str.erase(0, 1);
//				}
//				int size = str.length();
//				str.erase(size - 1, 1);
//				roadArray[AvenueNum][i] = atoi(str.c_str());
//				if (i == 0) {
//					temp[AvenueNum] = str;
//				}
//			}
//		}
//	}
//
//
//
//	//��˫��·����Ϊ2��·
//	for (int i = 1; i <= AvenueNum; i++) {
//		roadNum++;
//		if (roadArray[i][6] == 1)
//			roadNum++;
//	}
//	G.arcNum = roadNum;
//
//	/*
//	��ʼ��ͼG
//	*/
//	for (row = 0; row < G.vertexNum; row++)
//	{
//		for (col = 0; col < G.vertexNum; col++)
//		{
//			G.arc[row][col] = MAXCOST;
//		}
//	}
//
//
//	/*
//	����ͼG
//	*/
//	for (int k = 1; k <= AvenueNum; k++)
//	{
//		row = roadArray[k][4];
//		col = roadArray[k][5];
//		cost = roadArray[k][1];
//		G.arc[row][col] = cost;
//		G.road[row][col] = temp[k];
//		//˫�������һ��·
//		if (roadArray[k][6] == 1) {
//			G.arc[col][row] = cost;
//			G.road[col][row] = temp[k];
//		}
//	}
//	Floyd(G);
//
//	map<int, double> oldDensity;
//	
//	for (int p = 1; p <= AvenueNum; p++) {
//		oldDensity[roadArray[p][0]] = 0;
//	}
//
//
//
//
//	int CarHadStart = 0;
//	bool ifStart[CARNUM];
//	int PreStart[MaxSize];
//	double NowDensity;
//
//
//	for (int i = 0; i < MaxSize; i++)
//		PreStart[i] = 0;
//
//
//
//	for (int i = 0; i < CARNUM; i++)
//		ifStart[i] = false;
//
//
//	while (CarHadStart != carNum) {
//		
//		int realTime[CARNUM];
//		
//		for (int m = 1; m <= carNum; m++) {
//			if (ifStart[m] == false) {
//
//				int start = carArray[m][1];
//				int end = carArray[m][2];
//				int carNum = carArray[m][0];
//				int CarSpeed = carArray[m][3];
//				int planTime = carArray[m][4];
//
//
//
//				string str4;
//				int roadway[100];
//				int PathNum = 0;
//				int time = 0;
//				for (int i = 0; i < path[start][end].length(); i++) {
//					if (path[start][end][i] == ',') {
//						roadway[PathNum] = atoi(str4.c_str());
//
//						str4 = "";
//						PathNum++;
//						continue;
//					}
//					str4 += path[start][end][i];
//				}
//
//
//				if ((planTime <= AllTime) && (ifStart[m] == false)) {
//
//					int num = 0;
//					int PreRoad[MaxSize];
//
//					for (int i = 0; i < PathNum; i++) {
//						for (int j = 1; j <= AvenueNum; j++) {
//							if (roadArray[j][0] == roadway[i]) {
//								int CurrentCount = RoadDens[roadway[i]];
//								NowDensity = Density(roadArray[j][2], roadArray[j][1], roadArray[j][3], PreStart[j], CurrentCount, oldDensity[roadArray[j][0]]);
//								oldDensity[roadArray[j][0]] = NowDensity;
//								PreRoad[i] = j;
//
//							}
//						}
//						if (NowDensity >= THRESHOLD)
//							break;
//						else
//							num++;
//					}
//					if (num == PathNum) {
//						CarHadStart++;
//						for (int i = 0; i < PathNum; i++) {
//							PreStart[PreRoad[i]]++/* = PreStart[PreRoad[i]] + AVE_VOL / (roadArray[PreRoad[i]][1] * roadArray[PreRoad[i]][3]/ roadArray[PreRoad[i]][2])*/;
//						}
//						ifStart[m] = true;
//						realTime[m] = AllTime;
//						dispatch[m] = "(" + to_string(carNum) + "," + to_string(realTime[m]) + "," + path[start][end];
//						dispatch[m].erase(dispatch[m].length() - 1, 1);
//						dispatch[m] += ")";
//						mycout << dispatch[m] << endl;
//						cout << dispatch[m] << endl;
//					}
//				}
//
//			}
//
//
//
//			}
//			
//
//		//��ʼ��ÿ��·���ܶ�map����Ӧ��������
//		for (int p = 1; p <= AvenueNum; p++) {
//			RoadDens[roadArray[p][0]] = 0;
//		}
//	
//	//����������ͼ��ӵ����Ϣ
//		for (int j = 0; j < carNum; j++) {
//			
//			if (ifStart[j]) {
//				int start = carArray[j][1];
//				int end = carArray[j][2];
//				string str5;
//				int roadway[100];
//				int PathNum = 0;
//				//int realSpeed;
//
//				for (int i = 0; i < path[start][end].length(); i++) {
//					if (path[start][end][i] == ',') {
//						roadway[PathNum] = atoi(str5.c_str());
//						str5 = "";
//						PathNum++;
//						continue;
//					}
//					str5 += path[start][end][i];
//				}
//				int finalTime = Time(path[start][end], roadArray, carArray[j][3], carNum);
//				int cur = 0;
//				int index;
//				int tempTime = AllTime - realTime[j];
//				if (tempTime < finalTime) {
//					while (tempTime > 0) {
//						for (int i = 1; i < roadNum; i++) {
//							if (roadArray[i][0] == roadway[cur])
//								index = i;
//						}
//						tempTime -= roadway[cur] / roadArray[index][2];
//						cur++;
//
//					}
//					RoadDens[roadway[cur]] = RoadDens[roadway[cur]] + 1;
//				}
//			}
//		}
//
//		for (int i = 0; i < MaxSize; i++)
//			PreStart[i] = 0;
//
//		AllTime++;
//
//	}
//
//
//
//
//
//
//
//	mycout.close();
//	system("pause");
//	return 0;
//
//
//}
