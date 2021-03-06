#include <iostream>
#include <string>
#include "CipherInterface.h"
#include "DES.h"
#include "AES.h"

using namespace std;

int main(int argc, char** argv)
{
	/**
	 * TODO: Replace the code below	with your code which can SWITCH
	 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
	 * THE LAST BLOCK IF NECESSARY.
	 *
	 * NOTE: due to the incomplete skeleton, the code may crash or
	 * misbehave.
	 */
	
	//cipher name
	string cipherName = argv[1];
	/*
	//key
	string keyInput = argv[2];

	//ENC or DEC
	string functype = argv[3];

	// input file
	string inputFile = argv[4];

	//output file
	string outputFile = argv[5];
	*/
	//DES cipher
	if(cipherName == "DES")
	{
	
	/* Create an instance of the DES cipher */	
	CipherInterface* cipher = new DES(); 
		
	/* Error checks */
	if(!cipher)
	{
		fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
		__FILE__, __FUNCTION__, __LINE__);
		exit(-1);
	}
	
	/* Set the encryption key
	 * A valid key comprises 16 hexidecimal
	 * characters. Below is one example.
	 * Your program should take input from
	 * command line.
	 */
	cipher->setKey((unsigned char*)"0123456789abcdef");
	
	/* Perform encryption */
	const unsigned char* cipherText = {cipher->encrypt((unsigned char*)"aaaabbbb")};

	cout <<"The cipher text is " << cipherText << endl;
	
	/* Perform decryption */
	cout<< cipher->decrypt(cipherText) << endl;
	
	return 0;
	
	}
	
	//AES cipher
	else if(cipherName == "AES")
	{
		// Create an instance of the AES cipher 	
		CipherInterface* cipher = new AES(); 

		/* Error checks */
		if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",	
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}

		//set encryption key
		cout <<"Setting key." << endl;
		cipher->setKey((unsigned char*)"000112233445566778899aabbccddeeff");
		cout<<"Successfully set key." << endl;

		//perform encryption
		
		unsigned char* ciphertext = cipher->encrypt((unsigned char*)"helloworld123456");
		cout << "Ciphertext: " << ciphertext << endl;

		//set decryption key
		cout <<"Setting key." << endl;
		cipher->setKey((unsigned char*)"100112233445566778899aabbccddeeff");
		cout<<"Successfully set key." << endl;

		//perform decryption
		
		cout << "Plaintext: " << cipher->decrypt(ciphertext) << endl;
		return 0;
	}
	else
	{
		cout << cipherName << " is not a valid type of cipher" << endl;
		return 0;
	}
	
}
