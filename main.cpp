#include<iostream>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<vector>

/*
1.用户输入网址
2.yt-dlp解析网址，下载视频
3.调用mpv播放
4.关闭mpv窗口后删除视频
*/


int main() {
	//std::vector<std::string> videoFiles;
	/*std::cout << "请输入完整视频名称(例子.mp4):";
	std::string name;
	std::cin >> name;*/

	//1.用户输入网址
	std::cout << "请输入视频网址:";
	std::string url;
	std::cin >> url;
	//2.yt-dlp解析网址，下载视频
	std::string downloadCommand = "yt-dlp -o \"downloaded_video.%(ext)s\" " + url;
	system(downloadCommand.c_str());
	//假设下载的视频文件名为downloaded_video.mp4
	std::string name = "downloaded_video.mp4";
	//3.运行视频
	std::string command = "mpv \"" + name + "\"";
	system(command.c_str());
	//4.删除视频
	std::string deleteCommand = "del \"" + name + "\"";
	system(deleteCommand.c_str());



	return 0;
}