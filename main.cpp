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


//���ʱ��


int main() {
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
	std::string downloadCommand = "part.yt-dlp\\yt-dlp -o \"" + name + "\" " + url;// +" >nul 2>nul";
	system(downloadCommand.c_str());
	//�������ص���Ƶ�ļ���Ϊdownloaded_video.mp4
	//3.������Ƶ
	std::string command3 = "part.mpv\\mpv \"" + name + "\""; 
	system(command3.c_str());
	//4.ɾ����Ƶ
	std::cout << "�Ƿ�ɾ����Ƶ�ļ�����y/n�� ";
	char choice[4];
	std::cin >> choice;
	if ('y' == choice[0]) {
		std::cout << "����ɾ���ļ�..." << std::endl;
		std::string deleteCommand = "del \"" + name + "\"";
		system(deleteCommand.c_str());
	}






	return 0;
}

