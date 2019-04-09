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
//#define ROADNUM   600
//#define MAXCOST  10000
//#define CARNUM   100000
//
//int dist[CROSSNUM][CROSSNUM];
//string path[CROSSNUM][CROSSNUM];
//
//template<class T>
//struct Graph
//{
//	T vertex[CROSSNUM];
//	T road[2000][2000];
//	int arc[2000][2000];
//	int vertexNum, arcNum;
//};
//
//int CarTimes[300];
//
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
//	for (int i = 1; i <= s; i++) {
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
//int OnebyOne(int time, int plan, int team) {
//	int start;
//	if (plan > CarTimes[team])
//		CarTimes[team] = plan;
//	start = CarTimes[team];
//	CarTimes[team] += time;
//	return start;
//}
//
//
//
//
//
//
//int main()
//{
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
//	ifstream road("F:\\cppwork\\competition\\car_road_cross\\road.txt");
//	ifstream cross("F:\\cppwork\\competition\\car_road_cross\\cross.txt");
//	ifstream car("F:\\cppwork\\competition\\car_road_cross\\car.txt");
//
//	ofstream mycout("F:\\cppwork\\competition\\car_road_cross\\answer.txt");
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
//	//map<int, int>::iterator it;
//	//it = CrossMap.begin();
//	//for (it; it != CrossMap.end(); it++)
//	//{
//	//	// map的迭代器，可以用 first 访问std::pair的第一个成员(Type1)，second 访问第二个成员 (Type2)
//	//	cout << it->first << ":" << it->second << endl;
//	//}
//	//cout << "=================================" << endl;
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
//		row =CrossMap[roadArray[k][4]];
//		col =CrossMap[roadArray[k][5]];
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
//		int end   = CrossMap[carArray[m][2]];
//		int carNum = carArray[m][0];
//		int speed = carArray[m][3];
//		int planTime = carArray[m][4];
//
//
//		int cartime = Time(path[start][end], roadArray, carArray[m][3], carNum);
//		int startTime = OnebyOne(cartime, planTime,carNum%300);
//
//		dispatch[m] = "(" + to_string(carNum) + "," + to_string(startTime) + "," + path[start][end];
//		dispatch[m].erase(dispatch[m].length() - 1, 1);
//		dispatch[m] += ")";
// 		mycout << dispatch[m] << endl;
//
//	}
//
//	mycout.close();
//	system("pause");
//	return 0;
//}
//
//
