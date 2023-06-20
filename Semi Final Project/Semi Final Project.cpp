
#include <iostream>
#include<string>
using namespace std;
void split(string user_input, string &part1, string &part2, string &part3);
void sp(string user_input, int& count);
void order(string &part2, string &part3);
string upper(string words);
string reverse(string word);
string add(string x, string y);

char space = ' ';
int  sp_pos[50];

int main()
{
	int sp_count = 0;
	string input;
	string partA = " ", partB = " ", partC = " ";
	getline(cin, input);                           //Taking user input

	if (input == "\0" || input == " ")             //Error handling
	{
		cout << "Error!!" << endl << "No Data enterd" << endl << "Exiting the program" << endl;
		return 0;
	}

	sp(input, sp_count);         //Calculate spaces number and position in the input string
	
	split(input, partA, partB, partC);             //Splitting the input
	 
	//Error handling

	if (partA != "print" && partA != "PRINT" && partA != "Print" && partA != "shuffle" && partA != "SHUFFLE" && partA != "Shuffle"
		&& partA != "upper" && partA != "UPPER" && partA != "Upper" && partA != "reverse" && partA != "REVERSE" && partA != "Reverse"
		&& partA != "add" && partA != "ADD" && partA != "Add" && partA != "order" && partA != "ORDER" && partA != "Order" 
		&& partA!="Middle" && partA != "middle" && partA != "MIDDLE")
	{
		cout << "UNDEFINED COMMAND" << endl;
		return 0;
	}
	if (partB == " ")
	{
		cout << "INCORRECT NUMBER OF WORDS" << endl;
		return 0;
	}
	if ((partA == "print" || partA == "PRINT" || partA == "Print" || partA == "shuffle" || partA == "SHUFFLE" || partA == "Shuffle"
		|| partA == "upper" || partA == "UPPER" || partA == "Upper" || partA == "reverse" || partA == "REVERSE" || partA == "Reverse") && partC != " ")
	{
		cout << "INCORRECT NUMBER OF WORDS" << endl;
		return 0;
	}
	if ((partA == "add" || partA == "ADD" || partA == "Add" || partA == "order" || partA == "ORDER" || partA == "Order") && partC == " ")
	{
		cout << "INCORRECT NUMBER OF WORDS" << endl;
		return 0;
	}

	//Command 7 /\ Bonus Command

	if (sp_count > 2 && (partA == "Middle" || partA == "middle" || partA == "MIDDLE"))
	{
		string mid, first;
		int first_length;
		if (sp_count % 2 == 0)
		{
			first = input.substr(0, sp_pos[sp_count / 2]);
			first_length = first.length();
			mid = input.substr(sp_pos[sp_count/2]+1, sp_pos[sp_count/2 +2]-first_length);
			cout <<mid<< endl;
		}
		else {
			int x = ceil(sp_count / 2.0);
			first = input.substr(0, sp_pos[x]);
			first_length = first.length();
			mid = input.substr(sp_pos[x]+1, sp_pos[x + 1] - first_length);
			cout << mid << endl;
		}
	}

	//Command 1

	if (partA == "Print" || partA == "print" || partA == "PRINT")
	{
		cout << partB;
	}

	//Command 2

	if (partA == "Reverse" || partA == "reverse" || partA == "REVERSE")
	{
		cout << reverse(partB);
	}

	//Command 4
	if (partA == "upper" || partA == "UPPER" || partA == "Upper")
	{
		cout << upper(partB);
	}

	//Command 5

	if (partA == "add" || partA == "ADD" || partA == "Add")
	{
		cout << add(partB, partC);
	}

	//Command 6

	if (partA == "Order" || partA == "order" || partA == "ORDER")
	{
		order(partB,partC);
		cout <<"The correct order is "<< partB << " " << partC << endl;
	}
	
	return 0;
}

void split(string user_input, string &part1, string &part2, string &part3)
{
	int tot_len = user_input.length();
	part1 = user_input.substr(0, user_input.find_first_of(space));
	int len_part1 = part1.length();
	if (user_input.length() > len_part1 + 1)
	{
		size_t index1 = user_input.find(space, len_part1 + 2);
		part2 = user_input.substr(len_part1 + 1, index1 - len_part1 - 1);
		int len_part2 = part2.length();
		if (user_input.length() > (len_part1 + len_part2 + 1))
			part3 = user_input.substr(len_part1 + len_part2 + 2);
		else part3 = " ";
	}
	else return;
}

void sp(string user_input, int& count)
{
	int j = 1;
	int tot_len = user_input.length();
	for (int i = 0; i < tot_len - 1; i++)
	{
		if (user_input[i] == space)
		{
			count++;
			sp_pos[j] = i;
			j++;
		}
	}
	return;
}

void order(string &part2,string&part3)
{
	string temp;
	for (int i = 0; i < part2.length(); i++)
	{
		part2[i]=tolower(part2[i]);
	}
	for (int i = 0; i < part3.length(); i++)
	{
		part3[i]=tolower(part3[i]);
	}
	if (part2 < part3)
		return;
	if (part2 > part3)
	{
		temp = part2;
		part2 = part3;
		part3 = temp;
	}
	if (part2 == part3)
	{
		cout << "The two words are the same" << endl;
	}
	{
		int i = 0;
		part2[i] = toupper(part2[i]);
		part3[i] = toupper(part3[i]);
	}
}
string upper(string words)
{
	for (int i = 0; i <= words.length(); i++)
	{
		words[i] = toupper(words[i]);
	}
	return words;
}

string reverse(string word)
{
	int l = word.length();
	char arrayofword[1000];
	for (int i = 0; i <= l; i++)
	{
		arrayofword[l - i] = word[i];
	}
	for (int i = 0; i <= l; i++)
	{
		word[i] = arrayofword[i + 1];
	}
	return word;
}

string add(string x, string y)
{
	string sum2;
	int n1, n2,sum1;
	try {
		n1 = stoi(x);
		n2 = stoi(y);
	}
	catch (...) {
		cout << "Error!! Please enter a number with add command" << endl;
		
	}
		sum1 = n1 + n2;
		sum2 = to_string(sum1);
		return sum2;
	
	
	///*if ((n1 == 0 && x != "0") || (n2 == 0 && y != "0"))
	//{
	//	return "error (you should enter numbers with add command)";
	//}*/
	//else
	//{
	//	return sum2;
	//}
	
}
