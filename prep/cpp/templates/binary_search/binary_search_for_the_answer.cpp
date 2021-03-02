int __placeholder__(long long numStages){
    //logic for problem - varies from problem - problem
}

bool check(long long numStages) {
    //calls__placeholder__ and takes val from function call and makes it to fits constraint
}

// search function for when false switches to true. at pos=0, we are false, at pos=max, we are true, function returns fast index when check is true
long long search(){ 
    long long pos = 0; long long max = 2E9; //change val of max
    long long a;
    for(a = max; a >= 1; a /= 2) {
        //cout << "search:: pos:" <<  pos << ", a:" << a << endl << flush;
        while(!check(pos+a)) pos += a;
    }
    pos += 1; // move position to next as we want to return first true position (not last false position) 
            // if we want last false do pos -= 1; 

    //cout << "search2:: pos:" <<  pos << ", a:" << a << endl << flush;

    return pos;
}