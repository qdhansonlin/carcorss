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
//#define MAXCOST  10000
//#define CARNUM   20000
//
//#define THRESHOLD 50
//
//int dist[MaxSize][MaxSize];
//string path[MaxSize][MaxSize];
//
//template<class T>
//struct Graph
//{
//	T vertex[MaxSize];
//	T road[MaxSize][MaxSize];
//	int arc[MaxSize][MaxSize];
//	int vertexNum, arcNum;
//};
//
//int AllTime = 0;
//int SelfTime[CARNUM];
//
//void Floyd(Graph<string> G)
//{
//
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
////int OnebyOne(int time, int plan,int team) {
////	int start;
////	if (plan > carTime[team])
////		carTime[team] = plan;
////	start = carTime[team];
////	carTime[team] += time;
////	return start;
////}
//
//
//
//
//
//
//int main(/*int argc, char *argv[]*/)
//{
//	std::cout << "Begin" << std::endl;
//
//	/*if (argc < 5) {
//		std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
//		exit(1);
//	}
//
//	std::string carPath(argv[1]);
//	std::string roadPath(argv[2]);
//	std::string crossPath(argv[3]);
//	std::string answerPath(argv[4]);
//
//	std::cout << "carPath is " << carPath << std::endl;
//	std::cout << "roadPath is " << roadPath << std::endl;
//	std::cout << "crossPath is " << crossPath << std::endl;
//	std::cout << "answerPath is " << answerPath << std::endl;*/
//
//	int row, col, cost;
//	Graph<string> G;
//
//	int roadNum = 0;
//	int carNum = -1;
//	int AvenueNum = -1;
//	int crossnum = -1;
//
//
//	ifstream road("F:\\SDK\\SDK_C++\\config\\road.txt");
//	ifstream cross("F:\\SDK\\SDK_C++\\config\\cross.txt");
//	ifstream car("F:\\SDK\\SDK_C++\\config\\car.txt");
//
//	ofstream mycout("F:\\SDK\\SDK_C++\\config\\answer.txt");
//
//	string str, str2, str3;
//
//
//	int roadArray[MaxSize][7];
//	int carArray[CARNUM][5];
//	string dispatch[CARNUM];
//
//	string temp[MaxSize];
//
//	map<int, int> roadPRiority;
//	for (int i = 1; i <= AvenueNum; i++)
//		roadPRiority[roadArray[i][0]] = 0;
//
//
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
//
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
//
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
//	for (int i = 1; i <= AvenueNum; i++) {
//		roadNum++;
//		if (roadArray[i][6] == 1)
//			roadNum++;
//	}
//	G.arcNum = roadNum;
//
//
//	for (row = 0; row < G.vertexNum; row++)
//	{
//		for (col = 0; col < G.vertexNum; col++)
//		{
//			G.arc[row][col] = MAXCOST;
//		}
//	}
//
//
//
//	for (int k = 1; k <= AvenueNum; k++)
//	{
//		row = roadArray[k][4];
//		col = roadArray[k][5];
//		cost = roadArray[k][1];
//		G.arc[row][col] = cost;
//		G.road[row][col] = temp[k];
//		if (roadArray[k][6] == 1) {
//			G.arc[col][row] = cost;
//			G.road[col][row] = temp[k];
//		}
//	}
//	Floyd(G);
//
//
//
//	for (int m = 1; m <= carNum; m++) {
//		int start = carArray[m][1];
//		int end = carArray[m][2];
//		int carNum = carArray[m][0];
//		int speed = carArray[m][3];
//		int planTime = carArray[m][4];
//		int realTime = 0;
//
//		string str;
//		int roadway[100];
//		int s = 0;
//		int realSpeed;
//		int time = 0;
//		for (int i = 0; i < path[start][end].length(); i++) {
//			if (path[start][end][i] == ',') {
//				roadway[s] = atoi(str.c_str());
//				str = "";
//				s++;
//				continue;
//			}
//			str += path[start][end][i];
//		}
//
//
//		if (m <= 30) {
//			/*int cartime = Time(path[start][end], roadArray, carArray[m][3], carNum);
//			int startTime = OnebyOne(cartime, planTime, m % 30);*/
//			realTime = carArray[m][4];
//			AllTime = AllTime > realTime ? AllTime : realTime;
//			for (int i = 0; i < s; i++) {
//				roadPRiority[roadway[i]]++;
//			}
//		}
//		else {
//			int temp=0;
//			for (int i = 0; i < s; i++) {
//				temp+=roadPRiority[roadway[i]];
//			}
//			SelfTime[m] = AllTime;
//			while (SelfTime[m] < planTime) {
//				SelfTime[m]++;
//			}
//			while (temp > SelfTime[m] *THRESHOLD) {
//				SelfTime[m]++;
//			}
//			for (int i = 0; i < s; i++) {
//				roadPRiority[roadway[i]]++;
//			}
//			realTime = SelfTime[m];
//		}
//		dispatch[m] = "(" + to_string(carNum) + "," + to_string(realTime) + "," + path[start][end];
//		dispatch[m].erase(dispatch[m].length() - 1, 1);
//		dispatch[m] += ")";
//		mycout << dispatch[m] << endl;
//
//	}
//
//	mycout.close();
//	system("pause");
//	return 0;
//}
//
//
