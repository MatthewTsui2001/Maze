#include <iostream>
#include<vector>
#include <fstream>
#include <iomanip>
/**
 * This method will print out a vector of any type
 * input: m the vector that will be printed out
 * output: none
*/
template <typename T>
void print(const std::vector<std::vector<T>> & m){
    for(unsigned i=0; i<m.size(); i++){
        for(unsigned j=0; j<m[i].size();j++){
            if(m[i][j]!=-1){
                std::cout<<" "<<m[i][j]<<" ";
            }
            else{
                std::cout<<m[i][j]<<" ";
            }
        }
        std::cout<<std::endl;
    }
}

/**
 * This method will recursively run through each index of the matrix and find a path to the end
 * input:m the vector of a maze
 * input: path a vector of the path that is taken
 * input: noPath true if there is no path found false if path is found
 * input: total a int value checking if the negative ones and ones in the path are the same
 * output: none
*/
void find_path(const std::vector<std::vector<int>> & m, std::vector<std::vector<char>> & path,bool & noPath,int total=0,unsigned x=0,unsigned y=0){
    //base case when we reach the bottom right of the matrix
    if(x==m.size()-1 && y==m[0].size()-1){
        total+=m[x][y];
        //if total is zero it means we had the same number of 1 and -1
        if(total==0){
            path[x][y]='X';
            //path was found so print everything out
            std::cout<<"path matrix"<<std::endl;
            print(path);
            noPath=false;
            return;
        }
    }
    if(noPath && x!=0 && path[x-1][y]=='-'){//Up
        path[x][y]='^';
        total+=m[x][y];
        find_path(m,path,noPath,total,x-1,y);
        path[x][y]='-';
        total-=m[x][y];
    }
    if(noPath && x!=m.size()-1 && path[x+1][y]=='-'){//down
        path[x][y]='v';
        total+=m[x][y];
        find_path(m,path,noPath,total,x+1,y);
        path[x][y]='-';
        total-=m[x][y];
    }
    if(noPath && y!=0 && path[x][y-1]=='-'){//left
        path[x][y]='<';
        total+=m[x][y];
        find_path(m,path,noPath,total,x,y-1);
        path[x][y]='-';
        total-=m[x][y];
    }
        if(noPath && y!=m[0].size() && path[x][y+1]=='-'){//right
        path[x][y]='>';
        total+=m[x][y];
        find_path(m,path,noPath,total,x,y+1);
        path[x][y]='-';
        total-=m[x][y];
    }

}

/**
 * This method will call the find_path method 
 * input:m the vector that needs to be checked for paths
 * output: none
*/
void find_path(const std::vector<std::vector<int>> & m){
    //creating a vector of the path taken with the same size of m and storing every index with '-'
    std::vector<std::vector<char>> path(m.size(),std::vector<char>(m[0].size(),'-'));
    //creating a bool to tell when a path was found
    bool noPath = true;
    find_path(m,path,noPath);
    //if no path was found then print out no path was found
    if(noPath){
        std::cout<<"No path found"<<std::endl;
    }
}

/**
 * This method will read in from a text file and store the information in a vector of ints
 * input: file the name of the text file
 * output: m the matrix from the text file
*/
std::vector<std::vector<int>> readIn(std::string file){
    std::ifstream fin;
    fin.open(file);
    //storing the rows and columns
    int row,col;
    fin >> row;
    fin >> col;

    //creating vector and storing the indexes
    std::vector<std::vector<int> > m(row,std::vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col ; j++){
            fin >> m[i][j];
        }
    }
    return m;
}


int main(){
    //asking the user for the name of the file
    std::string file;
    std::cout<<"Please enter a file name"<<std::endl;
    std::cin>>file;

    //getting information from the file
    std::vector<std::vector<int>> m = readIn(file);
    //print the path
    print(m);
    //check for paths
    find_path(m);
    return 0;
}