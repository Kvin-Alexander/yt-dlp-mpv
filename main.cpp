#include<iostream>
#include<cstdlib>
#include<string>

/*
1.�û�������ַ
2.yt-dlp������ַ��������Ƶ
3.����mpv����
4.�ر�mpv���ں�ɾ����Ƶ
*/


int main() {
	//1.�û�������ַ
	std::cout << "��������Ƶ��ַ:";
	std::string url;
	std::cin >> url;
	//2.yt-dlp������ַ��������Ƶ
	std::string downloadCommand = "part.yt-dlp\\yt-dlp -o \"downloaded_video.%(ext)s\" " + url + " >nul 2>nul";
	system(downloadCommand.c_str());
	//�������ص���Ƶ�ļ���Ϊdownloaded_video.mp4
	std::string name = "downloaded_video.mp4";
	//3.������Ƶ
	//fs::current_path(originalPath);
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
	else {
		std::cout << "�ļ������ڵ�ǰĿ¼�£��ļ���Ϊdownloaded_video.mp4" << std::endl;
	}






	return 0;
}