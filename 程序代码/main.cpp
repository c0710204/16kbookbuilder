#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
string repl(string str1,string searchString,string replaceString)
{
    string::size_type pos = 0;   
    while((pos = str1.find(searchString, pos)) != string::npos) {
        str1.replace(pos, searchString.size(), replaceString);
        pos++;
    }
    return str1;
}
int main(int argc, char *argv[])
{
	ifstream cin1(argv[1],ios::in);
	string str1;
	getline(cin1,str1);
	cout<<str1<<endl;
	cin1.close();	
	//******************
	str1=repl(str1," ","\0");
	string str0=argv[1];
	string str01=repl(str0,".txt","\0");
	string str02=str01+"-"+str1;
	string str03=repl(str02," ","\0");
	string str04=repl(str03," ","\0");
	cout<<str04<<endl;
    //**********************
    //&#183:
		str04=repl(str04,"&#183:","¡¤");
	//&#183;
		str04=repl(str04,"&#183;","¡¤");
    //******************
	cout<<str0<<endl;
	string str3="copy \""+str0+"\" \"../bookdir_ok/"+str04+".txt\"";
	cout<<str3<<endl;
	system(str3.c_str());
	
	//system("pause");
    return EXIT_SUCCESS;
}
