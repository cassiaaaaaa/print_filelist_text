// print_filelist_txt.cpp : ����һ���ļ����µ��ļ������ļ������б��ӡ��txt�ĵ��С�
//

#include <iostream>
#include <string>
#include <io.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

string dirpath = "F:\\��������\\Result\\C8053-new-pnt(1)\\ch\\";

int main()
{
	_finddata_t file;
	long lf;
	char suffixs[] = "*.pnt";          //ҪѰ�ҵ��ļ�����
	vector<string> fileNameList;   //�ļ�����.pnt�����ļ�����������
	char *p;
	p = (char *)malloc((dirpath.size() + 1) * sizeof(char));
	strcpy(p, dirpath.c_str());

	 ofstream in;
     in.open("ch.txt",ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�


	 static ofstream fout;
	   fout.open("F:\\��������\\Result\\C8053-new-pnt(1)\\ch\\ch.txt");

	//��ȡ�ļ�������
	if ((lf = _findfirst(strcat(p, suffixs), &file)) == -1l)
	{
		cout << "�ļ�û���ҵ�!\n";
	}
	else
	{
		cout << "\n�ļ��б�:\n";

		do {
			fout << file.name << endl;
			cout << file.name << endl;
			//str�����������ļ������ַ���string
			string str(file.name);
          	cout << endl;
		} while (_findnext(lf, &file) == 0);//���������һ���ļ������ֳɹ��Ļ�
	}
	fout.close();
	_findclose(lf);

	system("PAUSE");
	return 0;
}