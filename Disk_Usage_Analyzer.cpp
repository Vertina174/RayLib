#define _XOPEN_SOURCE 500
#include<iostream>
#include<ftw.h> // for nftw
#include<vector>
#include<string.h>
#include<cstring> // because nftw uses cstrings
#include<map>
using namespace std;
// Stores the length of the longest file path.
// Used to scale the progress bar.
int maxlength=0; 

// Multimaps store files sorted by size.
// Key   = size
// Value = {unit, filepath}
multimap<float  , pair<string, string>, greater<int>> bytes;
multimap<float  , pair<string, string>, greater<int>> kb;
multimap<float  , pair<string, string>, greater<int>> mb;
multimap<float  , pair<string, string>, greater<int>> gb;

// Callback function called by nftw() for every file/directory.
int Data_fetch(const char *path, const struct stat *sb, int typeflag, struct FTW *ftwbuffer){
    size_t filesize=sb->st_size;

    // Track longest path for progress bar scaling.
    if(maxlength<strlen(path)){
        
        maxlength=strlen(path);
    }
     // Categorize files by size
    if(filesize<1023){
        bytes.insert({filesize,{"BYTES", path}});
    }
    else if(filesize>=1024 && filesize<1048576){
        kb.insert({filesize/1024.0, {"KB", path}});
    }
    else if(filesize>=1048576 && filesize<1073741824){
mb.insert({filesize/(1024.0*1024.0), {"MB", path}});
    }
    else{
        gb.insert({filesize/(1024.0*1024.0*1024.0), {"GB", path}});
    }
    return 0; // continue traversal as 0 indicate successful calling  
}

// Draws a text progress bar.
void progress_bar(int progress){
    int limit=4*1024;
    int bar=limit/(maxlength+15);
for(int i=0; i<limit; i+=bar){
    if(progress>0){
        progress-=bar;
        cout<<"#";}
    else
        cout<<"_";
}
}

// Print all Collected Files
void display(){
    
for(const auto& x: gb){ // Display GB files First (if any)
     cout<<"[";
    progress_bar(3*1024+x.first);
    cout<<"]"<<endl;
    cout<<x.first<<"\t"<<x.second.first<<"\t"<<x.second.second<<endl;
}

for(const auto& x: mb){ // Display mb files secondly (if any)
    cout<<"[";
    
    progress_bar(500+x.first);
    cout<<"]"<<endl;
cout<<x.first<<"\t"<<x.second.first<<"\t"<<x.second.second<<endl;
}

for(const auto& x: kb){ // Display kilobytes files 
    cout<<"[";
    progress_bar(240);
    cout<<"]"<<endl;
cout<<x.first<<"\t"<<x.second.first<<"\t"<<x.second.second<<endl;
}
for(const auto& x: bytes){ // display bytes-sized files
    cout<<"[";
    progress_bar(1);
    cout<<"]"<<endl;
cout<<x.first<<"\t"<<x.second.first<<"\t"<<x.second.second<<endl;
}
}
int main(){
    // Clear Terminal(for windows environment only)
     // "." = current directory
    // Data_fetch = callback
    // 10 = max open file descriptors
system("cls");
nftw(".", Data_fetch,10,0);
cout<<"Current directory Files: \n\n";
    display();
    
return 0;
} 