#include<iostream>
#include<cstdlib>
#include<string>
#include<chrono>
#include<ctime>
#include<algorithm>

/*
1.�û�������ַ
2.yt-dlp������ַ��������Ƶ
3.����mpv����
4.�ر�mpv���ں�ɾ����Ƶ
*/

//������Ƶ��
std::string executeCommand_video(std::string url) {
	std::string command = "part.yt-dlp\\yt-dlp -g -f bestvideo \""  + url + "\"";

	char buffer[512];
	std::string result;

	FILE* pipe = _popen(command.c_str(),"r");
	if (!pipe) return "";

	while (fgets(buffer, sizeof(buffer), pipe)){
		result += buffer;
	}
	std::cout << result << std::endl;
	_pclose(pipe);

	if (!result.empty() && result.back() == '\n') {
		result.pop_back();
	}

	result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
	result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());

	return result;
}

//������Ƶ��
std::string executeCommand_audio(std::string url) {
	std::string command = "part.yt-dlp\\yt-dlp -g -f bestaudio \"" + url + "\"";
	char buffer[512];
	std::string result;
	FILE* pipe = _popen(command.c_str(), "r");
	if (!pipe) return "";
	while (fgets(buffer, sizeof(buffer), pipe)) {
		result += buffer;
	}
	std::cout << result << std::endl;
	_pclose(pipe);
	if (!result.empty() && result.back() == '\n') {
		result.pop_back();
	}
	result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
	result.erase(std::remove(result.begin(), result.end(), '\r'), result.end());

	return result;
}

//part.yt-dlp.stream
/*std::string streamVideo(std::string url) {
	std::string streamurl_video,streamurl_audio;
	streamurl_video = executeCommand_video(url);
	streamurl_audio = executeCommand_audio(url);
}*/

//part.mpv
void playVideo(std::string streamurl_video,std::string streamurl_audio) {
	std::string command = "part.mpv\\mpv \"" + streamurl_video + "\" --audio-file=\"" + streamurl_audio + "\"";
	system(command.c_str());
}

//part.delete
void downloadVideo(std::string url,std::string name) {
	std::cout << "�Ƿ�������Ƶ?(y/n)";
	char choice[4];
	std::cin >> choice;
	if ('y' == choice[0]) {
		std::string command = "part.yt-dlp\\yt-dlp --quiet --no-progress -o \"" + name + "\" " + url + "";
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
	//2.yt-dlp������ַ
	std::string streamurl_video,streamurl_audio;
	//streamurl = streamVideo(url);
	streamurl_video = executeCommand_video(url);
	streamurl_audio = executeCommand_audio(url);
	//3.������Ƶ
	playVideo(streamurl_video,streamurl_audio);
	//4.��Ƶ����
	downloadVideo(url, name);


	return 0;
}

