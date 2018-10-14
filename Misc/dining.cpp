//share variable

Semaphore mutex =1;
const int n = 5;
int state[n];
Semaphore self[n] = {};

void test(k){
    if(state([k+n-1]%n)!="Hungry" && state[k]=="Hungry" && state[((k+1)%n)]!=Hungry){
        state[k]= eat;
        self[k].V();
    }
}

void philospher(){
    while(1){
        mutex.p();
        state[i] = "Hungry";
        test(i);
        mutex.v();
        self[i].p();

        mutex.p();
        test(k+n-1)%n;
        test (k+1)%n;
        mutex.v();
    }
}

