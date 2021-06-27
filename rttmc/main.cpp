#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <thread>
#pragma warning(disable : 4996)

using namespace std;
float fullTime(int& l_hour, int& l_minute);
float timeConverter(string ls_time);
void makeCommand(int mcTime);
void getCurrentTime(int& l_hour, int& l_minute);
void startServer();
void timeAdjust();
void threadTimeLoop();
int main(){
	timeAdjust();
	startServer();
	std::thread t(&threadTimeLoop);
	cin.get();
}
float fullTime(int& l_hour, int& l_minute) {
	float dumb = float(l_hour) + (float(l_minute) / 60);
	return dumb;

}
float timeConverter(string ls_time) {
	if (ls_time.find(":") == 1) ls_time.insert(0, "0");

	int l_hour = 0;
	int l_minute = 0;
	string shour = ls_time.substr(0, 2);
	l_hour = stoi(shour); 
	if (l_hour == 12) l_hour = 0; 
	string sminute = ls_time.substr(3, 2);
	l_minute = stoi(sminute);
	char timeMod = ls_time[6];

	if (ls_time[6] == 'p' || ls_time[6] == 'P') {
		l_hour += 12;
	}

	return fullTime(l_hour, l_minute);
}
void makeCommand(int mcTime) {
	ifstream passwordFile; 
	passwordFile.open("ReconPassword.txt");
	string rconPass;
	std::getline(passwordFile, rconPass);
	passwordFile.close(); 

	ofstream commandFile;
	commandFile.open("timeset.bat");
	string command = "mcrcon -p " + rconPass + " \"time set " + to_string(mcTime) + "\"";
	commandFile << command; 
	commandFile.close();
}
void startServer() {
	system("serverStart.bat");
}
void getCurrentTime(int& l_hour,int& l_minute) {
	const std::time_t now = std::time(nullptr);
	const std::tm calendar_time = *std::localtime(std::addressof(now));
	l_hour = calendar_time.tm_hour;
	l_minute = calendar_time.tm_min;
}
void timeAdjust() {
	int hour = 0;
	int minute = 0; 
	getCurrentTime(hour, minute);
	float f_time = fullTime(hour, minute);
	float timePercent = f_time / 24;
	int mcTime = (timePercent * 24000) + 18000;
	if (mcTime > 24000) {
		mcTime -= 24000;
	}
	makeCommand(mcTime);
}
void threadTimeLoop() {
	std::chrono::seconds interval(60);
	for (;;) {
		timeAdjust();
		system("timeset.bat");
		std::this_thread::sleep_for(interval);
	}
}