#include<iostream>
#include<cstring>
using namespace std;

class String
{
private:
	char *s;
	int len;
	// String(const String& a) //Copy Contructor
	// {
	// 	len = a.len;
	// 	s = new char[len+1];
	// 	strcpy(s, a.s);
		
	// 	cout<<"Copy Contructor called\n";
	// }
	// void operator=(const String &a)//Assignment operator
	// {
	// 	delete [] s;
	// 	len = a.len;
	// 	s = new char[len+1];
	// 	strcpy(s, a.s);
	// 	cout<<"Assignment operator invoked\n";
	// }
public:
	String(const char *str = "")
	{
		len = strlen(str);
		s = new char[len+1];
		strcpy(s, str);
		cout<<"Normal Contructor called\n";
	}
	String(const String& a) //Copy Contructor
	{
		len = a.len;
		s = new char[len+1];
		strcpy(s, a.s);
		
		cout<<"Copy Contructor called\n";
	}
	void operator=(const String &a)//Assignment operator
	{
		delete [] s;
		len = a.len;
		s = new char[len+1];
		strcpy(s, a.s);
		cout<<"Assignment operator invoked\n";
	}
	~String()
	{
		delete [] s; 
		delete &len;
		
		cout<<"Destructor called\n";
	}
	void print() 
	{
		cout << s << endl;
	}
	void setString(char *str){
		delete [] s;
		len = strlen(str);
		s = new char[len+1];
		strcpy(s, str);
	}
};

int main()
{
	String str1("Md");
	String str2("Tariq");
	String str3(str2);

	str1.print();
	str2.print();
	str3.print();
	cout<<"-------------\n\n";

	//Advantage of copy contructor
	String str4("Zaman");
	str3 = str4;
	// str2 = str4; same result

	str1.print();
	str2.print();
	str3.print();
	cout<<"-------------\n\n";

	//Advantage of assignment operator
	char c[] = "ABC";
	str4.setString(c);

	str1.print();
	str2.print();
	str3.print();
	str4.print();
	return 0;
}