// print_filelist_txt.cpp : 遍历一个文件夹下的文件，把文件名称列表打印在txt文档中。
//

#include <iostream>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

string dirpath = "F:\\工作任务\\Result\\C8053-new-pnt(1)\\ch\\";

int main()
{
	_finddata_t file;
	long lf;
	char suffixs[] = "*.pnt";          //要寻找的文件类型
	vector<string> fileNameList;   //文件夹下.pnt类型文件的名字向量
	char *p;
	p = (char *)malloc((dirpath.size() + 1) * sizeof(char));
	strcpy(p, dirpath.c_str());

	 ofstream in;
     in.open("ch.txt",ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建


	 static ofstream fout;
	   fout.open("F:\\工作任务\\Result\\C8053-new-pnt(1)\\ch\\ch.txt");

	//获取文件名向量
	if ((lf = _findfirst(strcat(p, suffixs), &file)) == -1l)
	{
		cout << "文件没有找到!\n";
	}
	else
	{
		cout << "\n文件列表:\n";

		do {
			fout << file.name << endl;
			cout << file.name << endl;
			//str是用来保存文件名的字符串string
			string str(file.name);
          	cout << endl;
		} while (_findnext(lf, &file) == 0);//如果发现下一个文件的名字成功的话
	}
	fout.close();
	_findclose(lf);

	system("PAUSE");
	return 0;
}