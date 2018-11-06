#include<iostream>

//incomplete
 int P;
 int R;

void calculateNeed(int need[P][R], int maxm[P][R],  int allot[P][R]) 
{ 
    // Calculating Need of each Process
    for (int i = 0 ; i < P ; i++) 
        for (int j = 0 ; j < R ; j++) 
  
            // Need of instance = maxm instance - allocated instance 
            need[i][j] = maxm[i][j] - allot[i][j]; 
} 
  
// Function to find the system is in safe state or not 
bool isSafe(int processes[], int avail[], int maxm[][],  int allot[][]) 
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
        {   
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


using namespace std;

int main(){
cout<<"\n Enter number of processes: ";
cin>>P;
cout<<"\n Enter number of resources: ";
cin>>R;
int Process[P];
int avail[R];
cout<<" Enter the available resources for "<<R<<" resources";
for(int i= 0;i<R; i++){
    cin>> avail[i];
}
int current[P][R];
int maxi[P][R];
for(int i=0;i<P;i++){
    cout<<"\n Enter the current allocation for Process P"<<i+1;
    for(int j=0;j<R;j++){
        cin>>current[i][j];
    }
}
for(int i=0;i<P;i++){
    cout<<"\n Enter the Maximum allocation for Process P"<<i+1;
    for(int j=0;j<R;j++){
        cin>>maxi[i][j];
    }
}

isSafe()

}