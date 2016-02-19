/* This is C++ code for File I/O */
#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains FILE input/output functions

using namespace std;		//Use namespace declaration to allow all elements in the std namespace to be accessed in an unqualified manner (without the std:: prefix).

//Function to compare string from User and file
int FindString(char User_buf[], char File_buf[])
{
   int i = 0;
 
   while (User_buf[i] == File_buf[i])		// Search until both strings data are equal
   {
      if (User_buf[i] == '\0' || File_buf[i] == '\0')		// Break if any string is terminated with null pointer
         break;
         
      i++;		// Increment buffer position
   }
 
   if (User_buf[i] == '\0' && File_buf[i] == '\0')			//Return 0 if both the strings has terminated on same position after breaking from while loop
      return 0;
   else
      return -1;		//Return 1 if both the strings are not equal
}

int main()
{
	char word[20];  		// This array will save user input
	int array_size = 1024; 	// Define the size of character array
	char array[24];			// This array will save buffer from text file	
	int flag;				// Saves return value for integer type string compare function.
	
	ifstream inFile;		// Open a file in read mode.
	inFile.open("words.txt"); 	//Opening an input stream for file words.txt

	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
	stream could not be opened.*/
	if(inFile.is_open())
	{
		cout << "File Opened" << endl;		//File opened successfully
		
		filebuf* pbuf = inFile.rdbuf();									// Get pointer to associated buffer object
		size_t buf_size = pbuf->pubseekoff (0,inFile.end,inFile.in);	// Get file size using buffer's members
		pbuf->pubseekpos (0,inFile.in);									// Change position to the 0th character
		char* buffer=new char[buf_size];								// Allocate memory to contain file data
		cout << "Size of file : " << buf_size << endl;					// Printout size of file
		
		//Ask user to enter a word to search in the file
		cout << "Please enter the word to  search in file : ";
		cin.getline(word,19); 		//Reading user input of max 19 characters because our word array size is 20
		
		int word_size = 0;			// Define the size of User input character array	
		//This loop is calculating the length of input word
		for(int i = 0; word[i] != '\0'; i++)
		{
			word_size++;
		}
		
		//This loop runs until the end of file (eof) does not occur
		while(!inFile.eof())
		{
			inFile.getline(array,array_size); 		//Reading line from file to array
			
			cout<<"String from file = " << array<<endl;
			
			flag = FindString(word, array);			// Function to compare two strings character by character
			
			if (flag == 0)							//Function return 0 if strings are equal
        	{
	            cout <<"String found = "<< array<<endl;
	            break;								// Break from while loop to close the file and abort further reading
	        }
	        else 
	      	  cout << "string not found"<< endl;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
		exit(1);									// File cannot be opened, exit the program
	}
}
