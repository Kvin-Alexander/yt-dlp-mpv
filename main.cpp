#include<iostream>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<vector>

/*
1.�û�������ַ
2.yt-dlp������ַ��������Ƶ
3.����mpv����
4.�ر�mpv���ں�ɾ����Ƶ
*/


int main() {
	//std::vector<std::string> videoFiles;
	/*std::cout << "������������Ƶ����(����.mp4):";
	std::string name;
	std::cin >> name;*/

	//1.�û�������ַ
	std::cout << "��������Ƶ��ַ:";
	std::string url;
	std::cin >> url;
	//2.yt-dlp������ַ��������Ƶ
	std::string downloadCommand = "yt-dlp -o \"downloaded_video.%(ext)s\" " + url;
	system(downloadCommand.c_str());
	//�������ص���Ƶ�ļ���Ϊdownloaded_video.mp4
	std::string name = "downloaded_video.mp4";
	//3.������Ƶ
	std::string command = "mpv \"" + name + "\"";
	system(command.c_str());
	//4.ɾ����Ƶ
	std::string deleteCommand = "del \"" + name + "\"";
	system(deleteCommand.c_str());



	return 0;
}