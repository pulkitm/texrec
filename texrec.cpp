/*Credits : Google for tesseract and pre trained data (tessdata)*/

#include<iostream>
#include<fstream>
#include<tesseract/baseapi.h>
#include<leptonica/allheaders.h>
#include<tesseract/renderer.h>
using namespace std;
using namespace tesseract;
int main(int argc,char* args[]){
	
	TessBaseAPI *api = new TessBaseAPI();
	

	if(api->Init(NULL,"eng")){
		cout<<"Can not initialize OCR"<<endl;
		exit(1);
	}
	

	cout<<"Enter Image location: ";
	char loc[1000];
	cin>>loc;
	cout<<endl;


	Pix *image = pixRead(loc);
	api->SetImage(image);
	string res = api->GetUTF8Text();
	
	cout<<"\nOCR done!\nWhat next?\n"<<endl;
	cout<<"1. Display Recognized Text on screen\n2. Write Recognized Text to file\n3. Generate Text recognizable pdf\n"<<endl;
	cout<<"Enter option: ";
	

	int choice;
	cin>>choice;
	while(choice>3||choice<1){
		cout<<"Invalid option! Try Again\n"<<endl;
		cout<<"Enter option: ";
		cin>>choice;
	}


	if(choice==1){

		cout<<endl<<res<<endl;

	}
	else if(choice==2){
		
		ofstream fout;
		fout.open("Result.txt");
		fout << res <<endl;
		fout.close();

		cout<<endl<<"Output written to Result.txt\n"<<endl;
	}
	else{
    	
    	char output_base[] = "Result";
    	char datapath[] = "tessdata";
    	int timeout_ms = 5000;
    	char* retry_config = nullptr;
    	bool textonly = false;

    	if(api->Init(datapath,"eng")){
			cout<<"Can not initialize OCR"<<endl;
			exit(1);
		}

		TessPDFRenderer *renderer = new TessPDFRenderer(output_base, api->GetDatapath(), textonly);

		bool succeed = api->ProcessPages(loc , retry_config, timeout_ms, renderer);

		if (!succeed) {
      		cout<<"Error during processing.\n"<<endl;
      		exit(1);
    	}

    	cout<<endl<<"Result.pdf Generated\n"<<endl;
	}

	api->End();
	delete api;
	pixDestroy(&image);
	return 0;
}
