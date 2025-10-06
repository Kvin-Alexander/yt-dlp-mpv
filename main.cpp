#include<iostream>
#include<cstdlib>
#include<string>
#include<chrono>
#include<ctime>

/*
1.�û�������ַ
2.yt-dlp������ַ��������Ƶ
3.����mpv����
4.�ر�mpv���ں�ɾ����Ƶ
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
	std::cout << "�Ƿ�ɾ����Ƶ?(y/n)";
	char choice[4];
	std::cin >> choice;
	if ('y' == choice[0]) {
		std::string command = "del \"" + name + "\"";
		system(command.c_str());
	}
}


int main() {
	//���ʱ��
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm local_time;
	localtime_s(&local_time, &now_c);
	char timeStr[32];
	strftime(timeStr, sizeof(timeStr), "%Y-%m-%d-%H%M%S", &local_time);
	std::string name = std::string(timeStr) + ".mp4";
	//1.�û�������ַ
	std::cout << "��������Ƶ��ַ:";
	std::string url;
	std::cin >> url;
	//2.yt-dlp������ַ��������Ƶ
	downloadVideo(url, name);
	//3.������Ƶ
	playVideo(name);
	//4.ɾ����Ƶ
	deleteVideo(name);


	return 0;
}

