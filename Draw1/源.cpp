#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include<algorithm>
#include <vector>
#include <string>
#include<fstream>
#include<sstream>
#include<iomanip>

using namespace std;
//���ļ��ж�ȡĳ���༶�������
string read(string s,string word[33][20]){
	ifstream f(s+".txt", ios::in);
	if (!f){ cout << "���ļ�ʧ��" << endl; return "ERROR"; }
	string number,str;
	string temp; int t = 1;
	int n = 0;
	while (!f.eof()){
		getline(f,str);
		istringstream is(str);
//			cout << str << endl;
		int j = 0;
			while (is >> temp)
			{
				word[n][j] = temp;
				++j;
			}
			++n;
//		++t;
	}
	f.close();
//	cout << t<<endl;
	return "0";
}
//С����̨˳��
void sort()
{
	srand((unsigned)time(0));
	vector<int>v;
	for (int i = 1; i<6; ++i)
	{
		v.push_back(i);

	}
	int j = 0;
	cout << "С����̨˳��:" << endl;
	for (int i = 0; i<5; ++i){
		j = rand() % v.size();
		cout << v[j] << " ";
		v.erase(v.begin() + j);

	}
	//   shuffle_order_engine(v.begin,v.end,rand());
	system("pause");
}
int draw(string word[][20],string number){
	int flag = 100;
	for (int i = 0; i < 22; ++i)
	{
		if (word[i][1].find(number + "��") != string::npos){ flag = i; break; }
//		cout << word[i][1] << endl;
	}
//	cout << flag << endl;//�жϸ���λ����һ��
	if (flag == 100)
	{
		cout << "���޴���" << endl;
		return 0;
	}
	int renshu = 0;
	for (int i = 6; i <= 8; ++i)
	{
		string temp = to_string(i);
		if (word[flag][1].find(temp) != string::npos){ renshu = i; break; }
	}
	//�ж������ж�����
	if (renshu == 0){ cout << "ERROR" << endl; return 0; };
//	cout << renshu << endl;
	srand((unsigned)time(0));
	int r = rand()%renshu+1;
	while ("150420207" == word[flag + 1][r])r = rand() % renshu + 1;
//	cout <<r << endl;
	string xuehao = word[flag + 1][r];
	string name = word[flag + 2][r];
	cout << xuehao << "-" << name << endl;
}
void main(){
	sort();
	while (1)
	{
		string word[33][20] = { "0" };
		string classnumber;
		cout << "�������ţ�" << endl;
		cin >> classnumber;
		string flag = read(classnumber, word);
		if ("ERROR" == flag)continue;
		for (int i = 0; i < 19; ++i){
			for (int j = 0; j < 20; ++j)
			{
				cout <<setw(10) << word[i][j];
			}
			cout << endl;
		}
		while (1)
		{
			int group = 0;
			string Groupchange[5] = { "һ", "��", "��", "��", "��" };
			cout << "���������(����0�˳�)��" << endl;
			cin >> group;//���1-5
			if (group == 0)break;
			while (group < 0 || group>5)
			{
				cout << "������������ţ�" << endl; cin >> group;
			}
			draw(word, Groupchange[group - 1]);
		}
		
	}
	system("pause");
}