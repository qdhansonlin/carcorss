//#include<iostream>
//#include<fstream>
//#include<string>
//#include<sstream>
//#include<vector>
//#include<algorithm>
//#include<functional>
//#include<map>
//using  namespace std;
//#define CROSSNUM  200
//#define ROADNUM   270
//#define MAXCOST  100000
//#define CARNUM   62000
//
//#define PARALLEL  70
//#define PARAMETER 100
//
//
//int dist[CROSSNUM][CROSSNUM];
//string path[CROSSNUM][CROSSNUM];
//
//template<class T>
//struct Graph
//{
//	T vertex[CROSSNUM];
//	T road[CROSSNUM][CROSSNUM];
//	int arc[CROSSNUM][CROSSNUM];
//	int vertexNum, arcNum;
//};
//
//int CarTimes[50];
//int AllTime = 0;
//
//void Floyd(Graph<string> G)
//{
//
//	for (int i = 1; i < G.vertexNum; i++)
//		for (int j = 1; j < G.vertexNum; j++)
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
//	for (int k = 1; k < G.vertexNum; k++) {
//		for (int i = 1; i < G.vertexNum; i++) {
//			for (int j = 1; j < G.vertexNum; j++) {
//				if (dist[i][k] + dist[k][j] < dist[i][j])
//				{
//					dist[i][j] = dist[i][k] + dist[k][j];
//					path[i][j] = path[i][k] + path[k][j];
//				}
//			}
//		}
//	}
//}
//
//
//
////int Time(string path, int array[][7], int speed, int roadNum) {
////	string str;
////	int roadway[100];
////	int s = 0;
////	int realSpeed;
////	int time = 0;
////	for (int i = 0; i < path.length(); i++) {
////		if (path[i] == ',') {
////			roadway[s] = atoi(str.c_str());
////			str = "";
////			s++;
////			continue;
////		}
////		str += path[i];
////	}
////
////	for (int i = 1; i <= s; i++) {
////		for (int j = 1; j <= roadNum; j++) {
////			if (roadway[i] == array[j][0]) {
////				realSpeed = speed > array[j][2] ? array[j][2] : speed;
////				time += array[j][1] / realSpeed;
////			}
////		}
////
////	}
////	return time;
////}
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
//
//
//
//
//
//int main(/*int argc, char *argv[]*/)
//{
//	//std::cout << "Begin" << std::endl;
//
//	//if (argc < 5) {
//	//	std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
//	//	exit(1);
//	//}
//
//	//std::string carPath(argv[1]);
//	//std::string roadPath(argv[2]);
//	//std::string crossPath(argv[3]);
//	//std::string answerPath(argv[4]);
//
//	//std::cout << "carPath is " << carPath << std::endl;
//	//std::cout << "roadPath is " << roadPath << std::endl;
//	//std::cout << "crossPath is " << crossPath << std::endl;
//	//std::cout << "answerPath is " << answerPath << std::endl;
//
//	ifstream road("F:\\cppwork\\competition\\car_road_cross\\road.txt");
//	ifstream cross("F:\\cppwork\\competition\\car_road_cross\\cross.txt");
//	ifstream car("F:\\cppwork\\competition\\car_road_cross\\car.txt");
//	ofstream mycout("F:\\cppwork\\competition\\car_road_cross\\answer.txt");
//
//	int row, col, cost;
//	Graph<string> G;
//
//	int roadNum = 0;
//	int carNum = -1;
//	int AvenueNum = -1;
//	int crossnum = -1;
//
//	string str, str2, str3;
//
//
//	int roadArray[ROADNUM][7];
//	int carArray[CARNUM][5];
//	string dispatch[CARNUM];
//
//	string temp[ROADNUM];
//
//
//
//
//	map<int, int>CrossMap;
//
//	while (!cross.eof()) {
//		crossnum++;
//		if (crossnum == 0) {
//			cross >> str2;
//			continue;
//		}
//		else {
//
//			for (int i = 0; i < 5; i++) {
//				cross >> str2;
//				if (i == 0) {
//					str2.erase(0, 1);
//					int size = str2.length();
//					str2.erase(size - 1, 1);
//					int tempnum = atoi(str2.c_str());
//					CrossMap[tempnum] = crossnum;
//				}
//
//			}
//		}
//	}
//	G.vertexNum = crossnum + 1;
//
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
//		row = CrossMap[roadArray[k][4]];
//		col = CrossMap[roadArray[k][5]];
//		cost = roadArray[k][1];
//		G.arc[row][col] = cost;
//		G.road[row][col] = temp[k];
//		if (roadArray[k][6] == 1) {
//			G.arc[col][row] = cost;
//			G.road[col][row] = temp[k];
//		}
//	}
//
//	Floyd(G);
//
//	for (int m = 1; m <= carNum; m++) {
//		int start = CrossMap[carArray[m][1]];
//		int end = CrossMap[carArray[m][2]];
//		int carNum = carArray[m][0];
//		int speed = carArray[m][3];
//		int planTime = carArray[m][4];
//
//		if (m%PARALLEL == 0) {
//			AllTime++;
//			Floyd(G);
//		}
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
//		//int cartime = Time(path[start][end], roadArray, carArray[m][3], AvenueNum);
//		int index[ROADNUM];
//
//
//		for (int j = 1; j < s; j++) {
//			for (int k = 1; k <= AvenueNum; k++) {
//				if (roadway[j] == roadArray[k][0]) {
// 					index[j] = k;
//				}
//			}
//
//		}
//		for (int z = 1; z < s-1; z++) {
//			int to   = CrossMap[roadArray[index[z]][5]];
//			int from = CrossMap[roadArray[index[z]][4]];
//			int nextto = CrossMap[roadArray[index[z+1]][5]];
//			int nextfrom = CrossMap[roadArray[index[z+1]][4]];
//			int space = roadArray[index[z]][1] * roadArray[index[z]][3] / roadArray[index[z]][2];
//			if (to == nextto || to == nextfrom) {
//				G.arc[from][to] += PARAMETER / space;
//			}
//			else {
//				G.arc[to][from] += PARAMETER / space;
//			}
//
//
//		}
//
//
//
//
//		planTime = planTime > AllTime ? planTime : AllTime;
//
//
//
//
//		dispatch[m] = "(" + to_string(carNum) + "," + to_string(planTime) + "," + path[start][end];
//		dispatch[m].erase(dispatch[m].length() - 1, 1);
//		dispatch[m] += ")";
//		mycout << dispatch[m] << endl;
//
//	}
//
//	mycout.close();
//	return 0;
//}
//
//
