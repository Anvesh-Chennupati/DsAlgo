#include<iostream> 

using namespace std; 

//Please comment execution 2 for running execution 1 and uncomment execution 1 block
//Execution 1  
// declaring number of processes
// const int P = 4; 
  
// // declaring Number of resources 
// const int R = 5; 
  
//Execution 1

//Execution 2

// Number of processes 
const int P = 5; 
  
// Number of resources 
const int R = 3; 
//Execution 2


// Function to find the need of each process 
void calculateNeed(int need[P][R], int maxm[P][R],  int allot[P][R]) 
{ 
    // Calculating Need of each Process
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
  
            // Need of instance = maxm instance - allocated instance 
            need[i][j] = maxm[i][j] - allot[i][j]; 
} 
  
// Function to find the system is in safe state or not 
bool isSafe(int processes[], int avail[], int maxm[][R],  int allot[][R]) 
{ 
    int need[P][R]; 
   
    // calculating the need of a process
    calculateNeed(need, maxm, allot); 
    //Display current states
    cout<<"\nProcess\t Allocated resources \t\t Maximum Requirement \t\t Need"<<endl;
    for(int i =0;i<P;i++){
        cout<<"P"<<i+1<<": \t";
        for(int j=0;j<R;j++){
            cout<<" RS"<<j+1<<": "<<allot[i][j];
        }cout<<"\t\t";
        for(int j=0;j<R;j++){
            cout<<" RS"<<j+1<<": "<<maxm[i][j];
        }
        cout<<"\t\t";
        for(int j=0;j<R;j++){
            cout<<" RS"<<j+1<<": "<<need[i][j];
        }
        cout<<endl;
    }
    // Marking all processes as not finished 
    bool finish[P] = {0}; 
  
    // To store safe sequence of process execution
    int safeSeq[P]; 
  
    // Make a copy of available resources 
    int work[R]; 
    for (int i = 0; i < R ; i++) 
        work[i] = avail[i]; 
    cout<<"\nAvailable Resources are: ";
    for (int i = 0; i < R ; i++) 
        cout<<"RS"<<i+1<<": "<<work[i]<<" ";
    cout<<"\n";
    // While all processes are not finished 
    // or system is not in safe state. 
    int count = 0; 
    while (count < P) 
    { 
        // Finding a process which is not finish and  whose needs can be satisfied with current  work[] resources. 
        bool found = false;
        int p; 
        int nsp;
        for (p = 0; p < P; p++) 
        { 
            // First check if a process is finished, 
            // if no, go for next condition 
            if (finish[p] == 0) 
            { 
                // Check if for all resources of 
                // current P need is less 
                // than work 
                int j; 
                for (j = 0; j < R; j++) 
                    if (need[p][j] > work[j]) 
                        {nsp = p;
                        break;} 
  
                // If all needs of p were satisfied. 
                if (j == R) 
                { 
                    // Add the allocated resources of 
                    // current P to the available/work 
                    // resources i.e.free the resources 
                    cout<<"\nProcess P"<<p+1<<" Finished.";
                    for (int k = 0 ; k < R ; k++) 
                        work[k] += allot[p][k];
                    cout<<"\nCurrent Available Resources are: ";
                    for (int i = 0; i < R ; i++) 
                        cout<<"RS"<<i+1<<": "<<work[i]<<" ";
                    cout<<"\n";
    
  
                    // Add this process to safe sequence. 
                    safeSeq[count++] = p; 
  
                    // Mark this p as finished 
                    finish[p] = 1; 
  
                    found = true; 
                } 
            } 
        } 
  
        // If we could not find a next process in safe 
        // sequence. 
        if (found == false) 
        {   //cout<<"\n Resource requirements of P"<<nsp +1<<" cannot be Satisfied."<<endl;
            cout << "System is not in safe state"; 
            return false; 
        } 
    } 
  
    // If system is in safe state then 
    // safe sequence will be as below 
    cout << "\nSystem is in safe state.\nSafe"
         " sequence of Processes execution is: "; 
    for (int i = 0; i < P ; i++) 
        cout <<"P"<< safeSeq[i]+1 << " "; 
  
    return true; 
} 
  
// Driver code 
int main() 
{ 
    //Execution 1;
    // int processes[] = {0, 1, 2, 3}; 
  
    // // Available instances of resources 
    // int avail[] = {0,0,2, 1, 1}; 
  
    // // Maximum R that can be allocated 
    // // to processes 
    // int maxm[][R] = {{1,1,2,1,3}, 
    //                  {2,2,2,1,0}, 
    //                  {2,1,3,1,0}, 
    //                  {1,1,2,2,1}}; 
  
    // // Resources allocated to processes 
    // int allot[][R] = {{1,0,2,1,1}, 
    //                   {2,0,1,1,0}, 
    //                   {1,1,0,1,0}, 
    //                   {1,1,1,1,0}}; 
  //Execution 1;


    //Execution 2;
    int processes[] = {0, 1, 2, 3, 4}; 
  
    // Available instances of resources 
    int avail[] = {3, 3, 2}; 
  
    // Maximum R that can be allocated 
    // to processes 
    int maxm[][R] = {{7, 5, 3}, 
                     {3, 2, 2}, 
                     {9, 0, 2}, 
                     {2, 2, 2}, 
                     {4, 3, 3}}; 
  
    // Resources allocated to processes 
    int allot[][R] = {{0, 1, 0}, 
                      {2, 0, 0}, 
                      {3, 0, 2}, 
                      {2, 1, 1}, 
                      {0, 0, 2}}; 
  
    //execution 2
    // Check system is in safe state or not 
    isSafe(processes, avail, maxm, allot); 
  
    return 0; 
} 