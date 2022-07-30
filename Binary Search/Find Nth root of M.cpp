public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	   int i=1;
	   int j=m;
	   while(i<=j){
	       unsigned long long int mid= i+(j-i)/2;
	       unsigned long long int t = pow(mid,n);
	       //cout<<t<<" "<<mid<<endl;
	       if(t==m)
	        return mid;
	       if(t>m||t==0)
	        j = mid-1;
	       else
	        i = mid+1;
	   }
	   return -1;
	}
