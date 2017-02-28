#include <iostream>
#include <random>

int main()
{
    
	std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(0, 1);


int i, j, z, starcount;
auto arr1 = new std::string[100][100];
auto arr2 = new std::string[100][100];

for (i = 0; i < 100; i++){
     for (j = 0; j < 100; j++){
     	   if (dis(gen)<=0.5){
     	   		arr1[i][j] = "+";
     	   		arr2[i][j] = "+";
     	   }else if (dis(gen)>0.5){
     	   		arr1[i][j] = "-";
     	   		arr2[i][j] = "-";
     	   } else {
     	   	    arr1[i][j] = "-";
     	   		arr2[i][j] = "-";
     	   }
     }
}

for (i = 0; i < 100; i++){
     for (j = 0; j < 100; j++){
           std::cout << arr1[i][j];
     }
     std::cout << "\n";
}



for (z = 0; z<5000; z++)
{


for (i = 0; i < 100; i++){
     for (j = 0; j < 100; j++){
           std::cout << arr1[i][j];
     }
     std::cout << "\n";
}




for (i = 0; i < 100; i++){
     for (j = 0; j < 100; j++){
           starcount = 0;
     	   if (i>0 and j>0){
     	   	   if (arr1[i-1][j-1] == "+"){
           			starcount++;
           	   }
     	   }
        
     	   if (i>0){
     	   	   if (arr1[i-1][j] == "+"){
           			starcount++;
          	   }
     	   }

     	   if (j>0){
     	   	   if (arr1[i][j-1] == "+"){
           		    starcount++;
           	   }
     	   }


     	   if (i<99 and j<99){
     	   	   if (arr1[i+1][j+1] == "+"){
           			starcount++;
           	   }
     	   }
        
     	   if (i<99){
     	   	   if (arr1[i+1][j] == "+"){
           			starcount++;
          	   }
     	   }

     	   if (j<99){
     	   	   if (arr1[i][j+1] == "+"){
           		    starcount++;
           	   }
     	   }

     	   if (i>0 and j<99){
     	   	   if (arr1[i-1][j+1] == "+"){
           			starcount++;
           	   }
     	   }


     	   if (i<99 and j>0){
     	   	   if (arr1[i+1][j-1] == "+"){
           			starcount++;
           	   }
     	   }



//Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
//Any live cell with two or three live neighbours lives on to the next generation.
//Any live cell with more than three live neighbours dies, as if by overpopulation.
//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.



     	   if (arr1[i][j] == "+"){
     	   		if (starcount < 2){
     	   			arr2[i][j] = "-";
     	   		} else if (starcount == 2 or starcount == 3){
     	   			arr2[i][j] = "+";
     	   		} else if (starcount > 3){
     	   			arr2[i][j] = "-";
     	   		}
     	   } else if (arr1[i][j] == "-"){
     	   		if (starcount == 3){
     	   			arr2[i][j] = "+";
     	   		} else if (starcount != 3){
     	   			arr2[i][j] = "-";
     	   		}
     	   }

     }
}


for (i = 0; i < 100; i++){
     for (j = 0; j < 100; j++){
           arr1[i][j] = arr2[i][j];
     }
}

system ("clear");


}

}
