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


//检测时间


int main() {
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
	std::string downloadCommand = "part.yt-dlp\\yt-dlp -o \"" + name + "\" " + url;// +" >nul 2>nul";
	system(downloadCommand.c_str());
	//假设下载的视频文件名为downloaded_video.mp4
	//3.运行视频
	std::string command3 = "part.mpv\\mpv \"" + name + "\""; 
	system(command3.c_str());
	//4.删除视频
	std::cout << "是否删除视频文件？（y/n） ";
	char choice[4];
	std::cin >> choice;
	if ('y' == choice[0]) {
		std::cout << "正在删除文件..." << std::endl;
		std::string deleteCommand = "del \"" + name + "\"";
		system(deleteCommand.c_str());
	}






	return 0;
}

