#include <bits/stdc++.h>

using namespace std;

bool less_than(pair<int,int> a,pair <int,int> b)
{   if(a.first<b.first)
        return true;
    else 
        return false;
}

int main()
{   long long int n;
    long long int M;
    cin>>n>>M;
    vector <long long int> output;
    vector <pair<long long int,long long int> >free;
    free.push_back(make_pair(0,M));
    vector<vector<pair<long long int,long long int> > >alloc(n);
    vector <vector<long long int> > req;
    long long int req_no=0;
    char ch='A';
    long long int pid=0;
    long long int i,k,j;
    bool found,pend;
    bool found1;

    while(ch!='H')
    {    cin>>ch;
    	 if(ch=='H')  
            break;
            cin>>pid;

    	 switch(ch)
         {
    	       case 'A':
    	       long long int size;
    	       cin>>size;
    	       found=false;

    	       for(i=0;i<free.size();++i)
    	       {	if(free[i].second>=size){
    	       	       found=true;
    	       	       output.push_back(free[i].first);
    	       	       alloc[pid].push_back(make_pair(free[i].first,size));
    	       	       free[i].first+=size;
    	       	       free[i].second-=size;
    	       	       //sort(free.begin(),free.end());
                        if(free[i].second==0)
                              {  free.erase(free.begin()+i);
                               // i--;
                              }
    	       	       
                       break;


    	        }}

    	        if(!found)
                {       long long int req_no=output.size();
                        vector <long long int> v{req_no,pid,size};
    	        	    output.push_back(-1);
                        req.push_back(v);
    	        	    
    	            }

    	       break;

    	     case 'D':
    	        long long int add;
    	        cin>>add;
    	        found=false;
   	        if(alloc[pid].size()==0)
    	        	found=false;
    	        else
    	        {
    	          for(i=0;i<alloc[pid].size();++i)
    	          {      if(alloc[pid][i].first==add)
    	        	    {   found=true;
    	        	  	    output.push_back(0);
    	        	  	  vector <pair<long long int,long long int> >::iterator x=upper_bound(free.begin(),free.end(),alloc[pid][i],less_than);
                          free.insert(x,alloc[pid][i]);   //INSERTION SORT
                          alloc[pid].erase(alloc[pid].begin()+i);
                         // i--;
                         /*vector <pair<long long int,long long int> >::iterator y=x;
                          y--;
    	        	  	 if(x==free.begin()+1)
                         {     if(free[0].first+free[0].second==free[1].first)
                              {   free[0].second+=free[1].second;
                                  free.erase(free.begin()+1);    
                              } 

                         }
                         if(x+1==free.end())
                         {
                            if(free[free.size()-2].first+free[free.size()-2].second==free[free.size()-1].first)
                              {   free[free.size()-2].second+=free[free.size()-1].second;
                                  free.erase(free.begin()+free.size()-1);
                                  
                                  
                              }
                         }
                         else
                         {  if((*x).first+(*x).second==(*(x+1)).first)
                              {   (*x).second+=(*(x+1)).second;
                                  free.erase(x+1);
                                  
                                  
                              }
                              if((*y).first+(*y).second==(*x).first)
                              {   (*y).second+=(*x).second;
                                  free.erase(x);
                                  
                                  
                              }
                         }*/
                        long long int l;
                        for( l=0;l<free.size()-1;++l)
                        {     if(free[l].first+free[l].second==free[l+1].first)
                              {   free[l].second+=free[l+1].second;
                                  free.erase(free.begin()+l+1);
                                  l--;
                                  
                              }
                              
                        }
                        /* for(l=0;l<free.size();++l){
                        if(free[l].second==0)
                                {free.erase(free.begin()+l);
                                l--;
                            }
                      }*/
                      for(k=0;k<req.size();k++)
                        {
                            
                            for(j=0;j<free.size();++j)
                            {

                                if(free[j].second>=req[k][2]){
                                    output[req[k][0]]=free[j].first;
                                    alloc[req[k][1]].push_back(make_pair(free[j].first,req[k][2]));
                                    //output.push_back(free[j].first);
                                    free[j].first+=req[k][2];
                                    free[j].second-=req[k][2];
                                    req.erase(req.begin()+k);
                                    k--;

                                    if(free[j].second==0)
                                   { free.erase(free.begin()+j);
                                     //j--;
                                }
                                    break;
                                }
                            }
    	        	    }
    	           break; 
                }
            }}

                if(!found)
                	output.push_back(1);

    	        break;


    	      case 'T':
    	       found=false;
    	       pend=false;
               //pending check
    	        for(i=0;i<req.size();++i)
    	        {
    	        	if(pid==req[i][1])
    	        	{
    	        	    pend=true;

                        req.erase(req.begin()+i);
                        i--;
    	        		//output.push_back(-1);
    	        	}
    	        }
    	       //pending check
    	        if(alloc[pid].size()==0)
    	        	found=false;
    	        else{
                    found=true;
    	          for(i=0;i<alloc[pid].size();++i)
    	          {    //vector<pair<long long int,long long int>>a; //empty
    	          	   //alloc[pid][i]=a;
                        free.insert(upper_bound(free.begin(),free.end(),alloc[pid][i],less_than),alloc[pid][i]);
                 }//sort(free.begin(),free.end());
                  long long int l;
                  for( l=0;l<free.size()-1;++l)
                        {     if(free[l].first+free[l].second==free[l+1].first)
                              {   free[l].second+=free[l+1].second;
                                  free.erase(free.begin()+l+1);
                                  l--;
                                  //l--;

                              } 
                        }
                       /* for(l=0;l<free.size();++l){
                        if(free[l].second==0)
                                {free.erase(free.begin()+l);
                                l--;
                            }
    	          	  }*/
    	          	   alloc[pid].clear();
                    for(k=0;k<req.size();k++)
                        {
                            
                            for(j=0;j<free.size();++j)
                            {

                                if(free[j].second>=req[k][2]){
                                    output[req[k][0]]=free[j].first;
                                    alloc[req[k][1]].push_back(make_pair(free[j].first,req[k][2]));
                                    //output.push_back(free[j].first);
                                    free[j].first+=req[k][2];
                                    free[j].second-=req[k][2];
                                    req.erase(req.begin()+k);
                                    k--;
                                    if(free[j].second==0)
                                    {   free.erase(free.begin()+j);
                                       //  j--;
                                    }
                                   break; 
                                }
                            }
                          
                }}
                if(!found)
                    {  /* if(pend==true)
                            output.push_back(-1);
                        else*/
                	       output.push_back(1);
                }
                if(found)
                {    output.push_back(0);

                }

    	         break;
  }}
            for( i=0;i<output.size();++i)
            	cout<<output[i]<<endl;

    return 0;
}