#include<iostream>
#include<cstdlib>
#include<string>
#include<chrono>
#include<ctime>

/*
1.用户输入网址
2.yt-dlp解析网址，下载视频
3.调用mpv播放
4.关闭mpv窗口后删除视频
*/

//part.yt-dlp
void downloadVideo(std::string url, std::string name) {
	std::string command = "part.yt-dlp\\yt-dlp -o \"" + name + "\" " + url;
	system(command.c_str());
}

//part.mpv
void playVideo(std::string name) {
	std::string command = "part.mpv\\mpv \"" + name + "\"";
	system(command.c_str());
}

//part.delete
void deleteVideo(std::string name) {
	std::cout << "是否删除视频?(y/n)";
	char choice[4];
	std::cin >> choice;
	if ('y' == choice[0]) {
		std::string command = "del \"" + name + "\"";
		system(command.c_str());
	}
}


int main() {
	//检测时间
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm local_time;
	localtime_s(&local_time, &now_c);
	char timeStr[32];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d-%H%M%S", &local_time);
	std::string name = std::string(timeStr) + ".mp4";
	//1.用户输入网址
	std::cout << "请输入视频网址:";
	std::string url;
	std::cin >> url;
	//2.yt-dlp解析网址，下载视频
	downloadVideo(url, name);
	//3.运行视频
	playVideo(name);
	//4.删除视频
	deleteVideo(name);


	return 0;
}

