#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include<FL/Fl_Button.H>//needed to use Fl_Button
#include<iostream>
using namespace std;

int a=3,b=3;

char *int2charstar (int v) {
 char *s = new char[sizeof(int)];
 sprintf(s,"%d",v);
 return s;
};

class mybutton : public Fl_Button{

int ad1,ad2;

public:

int add;
mybutton(int x, int y, int w, int h, const char *l);
int handle(int e);

};

 mybutton *button[4][4],*bufm;
        
mybutton :: mybutton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {

 ad1 = (x-100)/100;  ad2 = (y-100)/100;  add = ad2*4+ad1+1; 
 
 };

int mybutton :: handle(int e){

  if(e==FL_PUSH){
  
  if(a==ad2){

  label("");   
  if(b<ad1){  
  for(int c=0;c<ad1-b;c++){  button[a][b+c]->label(int2charstar(button[a][b+c+1]->add)); 
  button[a][b+c]->add = button[a][b+c+1]->add; };
  };
  if(b>ad1){
  for(int c=0;c<b-ad1;c++){  button[a][b-c]->label(int2charstar(button[a][b-c-1]->add)); 
  button[a][b-c]->add = button[a][b-c-1]->add; };
  };
  b=ad1; a=ad2;  
  
  };
  
  if(b==ad1){

  label("");  
  if(a<ad2){  
  for(int c=0;c<ad2-a;c++){  button[a+c][b]->label(int2charstar(button[a+c+1][b]->add)); 
  button[a+c][b]->add = button[a+c+1][b]->add; };
  };
  if(a>ad2){
  for(int c=0;c<a-ad2;c++){  button[a-c][b]->label(int2charstar(button[a-c-1][b]->add)); 
  button[a-c][b]->add = button[a-c-1][b]->add; };
  };  
  b=ad1; a=ad2;  
  
  };
  
  
  }; return 1;
  
  };


int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (600,600,"DEMO"); // outer window

       bufm = button[0][0];
        
        for(int j=0;j<3;j++){
        for(int i=0;i<4;i++){
         
   button[j][i] = new mybutton(100+i*100,100+j*100,100,100,int2charstar(i+j*4+1));
        
        
        };  };
        
        for(int i=0;i<4;i++){
         
   button[3][i] = new mybutton(100+i*100,100+3*100,100,100,int2charstar(i+13));
        
        
        };
        
   button[3][3] = new mybutton(100+3*100,100+3*100,100,100,"");     
        
        
        
        
        
        window->end();//this will end the editing of window, we cant change window 
        //anymore
    	window->show();//this will show the window
    	
    	int q = Fl::run();  // the process waits from here on for events
    	
    	cout<<"exiting....\n";
    	
    	return q;
}

//compile : fltk-config --compile  name.cpp
//run : ./name

