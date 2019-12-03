
  #include<iostream>
  #include<fstream>
  #include<string.h>
  #include<stdlib.h>
  #include<limits.h>
  using namespace std;
  
  int  password = 1234;
  int const  v = 7;
  float adjacent[v][v];
  float weightage[9];
  
  struct paths{
    char pathc[50];
    float weight;
   }path[6];
   
  void enterdistance()
   {
      int dist;
      fstream obj;
      obj.open("dist.txt");
      cout<<"\n Enter distance between "
          <<"\n1.Nescafe to Nandini     : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n2.Nescafe to LHC-B       : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n3.Nandini to GB          : ";
      cin>>dist;
      obj<<dist<<"%"; 
      cout<<"\n4.LHC-B to Main Building : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n5.Main Building to GB    : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n6.GB to underpass        : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n7.Main Building to LHC-C : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n8.GB to LHC-C\t          : ";
      cin>>dist;
      obj<<dist<<"%";
      cout<<"\n9.Underpass to LHC-C     : ";
      cin>>dist;
      obj<<dist<<"%";
      obj.close();    
    }

  void editNo()
   {
      int gno,bno,gno1,gno2,gno3,bno1,bno2,bno3;
      ofstream obj;
      obj.open("East-West.txt");
      cout<<"\n Enter the no of girls and boys in "
          <<"\n 1. Mechanical   :  ";
      cin>>gno>>bno;
      cout<<"\n 2. Chemical     :  ";
      cin>>gno1>>bno2;
      obj<<gno+gno1<<"%"<<bno+bno1<<"$";
      cout<<"\n 3. I YEAR       :  ";
      cin>>gno>>bno;
      cout<<"\n 4. Metallurgy   :  ";
      cin>>gno1>>bno2;
      obj<<gno+gno1<<"%"<<bno+bno1<<"$"; 
      cout<<"\n 5. Cvil         :  ";
      cin>>gno>>bno;
      obj<<gno<<"%"<<bno<<"$";
      cout<<"\n 6.Mining       :  ";
      cin>>gno>>bno;
      obj<<gno<<"%"<<bno<<"$";     
      cout<<"\n 7.IT            :  ";
      cin>>gno>>bno;
      cout<<"\n 8.CS            :  ";
      cin>>gno1>>bno2;
      cout<<"\n 9. EEE          :  ";
      cin>>gno2>>bno2;
      cout<<"\n10 EC            :  ";
      cin>>gno3>>bno3;
      obj<<gno+gno1+gno3+gno2<<"%"<<bno+bno1+bno2+bno3<<"$";
      obj.close();
    } 

  void enterTraffic()
    {
      int traffic;
      ofstream obj;
      obj.open("traffic.txt");
      cout<<"\n enter the maximum traffic\n\t5-low\n\t10-medium\n\t15-high "
          <<"\n1.Nescafe to Nandini    :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n2.Nescafe to LHC-B      :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n3.Nandini to GB\t       :  ";
      cin>>traffic;
      obj<<traffic<<"%"; 
      cout<<"\n4.LHC-B to Main Building:  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n5.Main Building to GB   :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n6.GB to underpass       :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n7.Main Building to LHC-C:  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n8.GB to LHC-C           :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      cout<<"\n9.Underpass to LHC-C    :  ";
      cin>>traffic;
      obj<<traffic<<"%";
      obj.close();     
    }

  void admin()
   {
     int n;
     do{  
         cout<<"\n1.Enter Distance Between Nodes"<<"\n2.Edit Number Of Students"<<"\n3.Enter traffic"<<"\n0.Exit"; 
         cin>>n;
         switch(n)
           {
             case 1: enterdistance();
                     break;
             case 2: editNo();
                     break;
             case 3: enterTraffic();
                     break;
             default: cout<<"\n Check your input";
           }
        }while(n!= 0);
    }

   int minDistance(float dist[], bool sptSet[]) 
     { 
       float min = INT_MAX; int min_index; 
       for (int w= 0; w < v; w++) 
       if (sptSet[w] == false && dist[w] <= min) 
       min = dist[w], min_index = w; 
       return min_index; 
     } 

   float dijkstra1(float graph[7][7],int src) 
    { 
       float dist[v];
       bool sptSet[v]; 
       for (int i = 0; i < v; i++) 
         dist[i] = INT_MAX, sptSet[i] = false; 
       dist[src] = 0; 
       for (int count = 0; count < v - 1; count++)
        { 
           int u = minDistance(dist, sptSet); 
           sptSet[u] = true; 
           for (int w = 0; w < v; w++) 
              if (!sptSet[w] && graph[u][w] && dist[u] != INT_MAX && dist[u] + graph[u][w] < dist[w]) 
                  dist[w] = dist[u] + graph[u][w]; 
         } 
       return dist[v-1];
    }

  void user1(int time)
   {
     char c,s[4];
     float pathdist[9];float sb[5];float sg[5];int i=-1;
     float pathst[9],pathtr[9]; 
     fstream objs;
     objs.open("East-West.txt");
     while(!objs.eof())
      {  
         i++;
         do{
            if(!objs.eof())
               {     
                  objs>>c;
                  if(c!='%')
                  strncat(s,&c,1);}
            else 
                break;
           }while(c!='%');
            sg[i]=atoi(s);
       s[0] = '\0';
  
     do
      {
         if(!objs.eof())
            {
                objs>>c; 
                if(c!='$')
                strncat(s,&c,1);}
          else 
             break;
       }while(c!= '$');
      sb[i]=atoi(s);
      s[0]='\0';
    }
  objs.close();
  
  pathst[0]= sb[0] + sb[4]+sb[2]+sb[3];
  pathst[1]=pathst[0] + sb[1]+30;
  pathst[2] = pathst[0]- sb[1];
  pathst[3] = pathst[1]- sb[1];
  pathst[4]= pathst[3]-30;
  pathst[5]= pathst[2]+ sg[4];
  pathst[6]= pathst[5];
  pathst[7]= pathst[6];
  pathst[8]= pathst[7];
  
  fstream objd;
  objd.open("dist.txt");
  i =-1;

  while(!objd.eof())
   {
      i++;
      do{  
          if(!objd.eof())
           {
              objd>> c; 
              strncat(s,&c,1); }
          else
            break; 
        }while(c!='%');
   pathdist[i]=atoi(s);
   s[0]='\0';
  
   }
   objd.close();


  fstream objt;
   objt.open("traffic.txt");
   
   i =0;
   while(!objt.eof())
     {
        do
         {
            if(!objt.eof()){
               objt>> c;  
                 if(c!='%')
                 strncat(s,&c,1);} 
            else 
               break;
          }while(c!='%');
       pathtr[i]=atoi(s);
       s[0]= '\0';
       i++;
      }  
   objt.close();
   
   float stconst=200,dtconst=0.005,trconst=0.2;
   switch(time)
   {
    case 8 : for(int i= 0;i<9;i++){
             weightage[i] =  8*stconst/pathst[i]  + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;} 
             break;
    case 9 : for(int i= 0;i<9;i++){
         weightage[i] =  stconst*10/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
        }
             break;
    case 10: for(int i= 0;i<9;i++)
             weightage[i] =  stconst*6/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;
    case 11: for(int i= 0;i<9;i++)
           weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;     
    case 1:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;         
    case 2:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*13/pathst[i] + trconst*pathtr[i] + dtconst*3*pathdist[i]/2.5;
             break;
    case 3:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;     
    case 4:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*12/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;     
   }
  
   adjacent[0][1]= weightage[1];
   adjacent[0][2]= weightage[0];
   adjacent[1][0]= weightage[1];
   adjacent[1][3]= weightage[3];
   adjacent[2][0]= weightage[0];
   adjacent[2][4]= weightage[2];
   adjacent[3][1]= weightage[3];
   adjacent[3][4]= weightage[4];
   adjacent[3][6]= weightage[6];
   adjacent[4][2]= weightage[2];
   adjacent[4][3]= weightage[4];
   adjacent[4][5]= weightage[5];
   adjacent[4][6]= weightage[7];
   adjacent[5][4]= weightage[5];
   adjacent[5][6]= weightage[8];
   adjacent[6][3]= weightage[6];
   adjacent[6][4]= weightage[7];
   adjacent[6][5]= weightage[8];
   
   strcpy(path[0].pathc,"Nescafe- LHCB - MB to LHCC via Main Gate");
   path[0].weight=weightage[1]+weightage[3]+weightage[6];
   strcpy(path[1].pathc,"Nescafe- LHCB - MB - GB to LHCC via Reddy's Gate");
   path[1].weight=weightage[1]+weightage[3]+weightage[4] + weightage[7];
   strcpy(path[2].pathc,"Nescafe- LHCB - MB - GB to LHCC through underpass");
   path[2].weight= weightage[1]+weightage[3]+weightage[4]+weightage[5]+weightage[8];  
   strcpy(path[3].pathc,"Nescafe- Nandini - GB - MB to LHCC via Main Gate");
   path[3].weight= weightage[0]+weightage[2]+weightage[7]; 
   strcpy(path[4].pathc,"Nescafe- Nandini -GB  to LHCC via Reddy's Gate");
   path[4].weight= weightage[0]+weightage[2]+weightage[4] + weightage[6];
   strcpy(path[5].pathc,"Nescafe- Nandini - GB to LHCC through underpass");
   path[5].weight= weightage[0]+weightage[2]+weightage[5] + weightage[8];
   float d_weight=dijkstra1(adjacent, 0);
   for(int k=0;k<v-1;k++){
   
     if(d_weight==path[k].weight)
      {
        cout<<"\n optimal path : "<<path[k].pathc;
        break;
      }
    }
  }

float dijkstra2(float graph[7][7],int src) 
    { 
       float dist[v];
       bool sptSet[v]; 
       for (int i = 0; i < v; i++) 
         dist[i] = INT_MAX, sptSet[i] = false; 
       dist[src] = 0; 
       for (int count = 0; count < v - 1; count++)
        { 
           int u = minDistance(dist, sptSet); 
           sptSet[u] = true; 
           for (int w = 0; w < v; w++) 
              if (!sptSet[w] && graph[u][w] && dist[u] != INT_MAX && dist[u] + graph[u][w] < dist[w]) 
                  dist[w] = dist[u] + graph[u][w]; 
         } 
       return dist[0];
    }
 void user2(int time)
   {
     char c,s[4];
     float pathdist[9];float sb[5];float sg[5];int i=-1;
     float pathst[9],pathtr[9]; 
     fstream objs;
     objs.open("East-West.txt");
     while(!objs.eof())
      {  
         i++;
         do{
            if(!objs.eof())
               {     
                  objs>>c;
                  if(c!='%')
                  strncat(s,&c,1);}
            else 
                break;
           }while(c!='%');
            sg[i]=atoi(s);
       s[0] = '\0';
  
     do
      {
         if(!objs.eof())
            {
                objs>>c; 
                if(c!='$')
                strncat(s,&c,1);}
          else 
             break;
       }while(c!= '$');
      sb[i]=atoi(s);
      cout<<"\n"<<sb[i];
      s[0]='\0';
    }
  objs.close();
  cout<<"\n read from students";
  
  pathst[0]= sb[0] + sb[4]+sb[2]+sb[3];
  pathst[1]=pathst[0] + sb[1]+30;
  pathst[2] = pathst[0]- sb[1];
  pathst[3] = pathst[1]- sb[1];
  pathst[4]= pathst[3]-30;
  pathst[5]= pathst[2]+ sg[4];
  pathst[6]= pathst[5];
  pathst[7]= pathst[6];
  pathst[8]= pathst[7];
  
  fstream objd;
  objd.open("dist.txt");
  i =-1;

  while(!objd.eof())
   {
      i++;
      do{  
          if(!objd.eof())
           {
              objd>> c; 
              strncat(s,&c,1); }
          else
            break; 
        }while(c!='%');
   pathdist[i]=atoi(s);
   cout<<"\n"<<pathdist[i];
   s[0]='\0';
  
   }
   objd.close();
   cout<<"\n read distance";

  fstream objt;
   objt.open("traffic.txt");
   if(!objt.is_open())
   i =0;
   while(!objt.eof())
     {
        do
         {
            if(!objt.eof()){
               objt>> c;  
               strncat(s,&c,1);} 
            else 
               break;
          }while(c!='%');
       pathtr[i]=atoi(s);
       cout<<"\n"<<pathtr[i];
       s[0]= '\0';
       i++;
      }  
   objt.close();
   cout<<"\nread traffic";
   
   float stconst=250,dtconst=0.005,trconst=0.2;
   switch(time)
   {
    case 9 : for(int i= 0;i<9;i++){
         weightage[i] = 8*stconst/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
	    }
             break;
    case 10: for(int i= 0;i<9;i++)
             weightage[i] =  8*stconst*4/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;
    case 11: for(int i= 0;i<9;i++)
           weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;     
    case 12:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*13/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;         
    case 2:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;
    case 3:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;     
    case 4:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break; 
	case 5:  for(int i= 0;i<9;i++)
         weightage[i] =  stconst*8/pathst[i] + 2*trconst*pathtr[i] + 3*dtconst*pathdist[i]/2;
             break;    
   }
  
   adjacent[0][1]= weightage[1];
   adjacent[0][2]= weightage[0];
   adjacent[1][0]= weightage[1];
   adjacent[1][3]= weightage[3];
   adjacent[2][0]= weightage[0];
   adjacent[2][4]= weightage[2];
   adjacent[3][1]= weightage[3];
   adjacent[3][4]= weightage[4];
   adjacent[3][6]= weightage[6];
   adjacent[4][2]= weightage[2];
   adjacent[4][3]= weightage[4];
   adjacent[4][5]= weightage[5];
   adjacent[4][6]= weightage[7];
   adjacent[5][4]= weightage[5];
   adjacent[5][6]= weightage[8];
   adjacent[6][3]= weightage[6];
   adjacent[6][4]= weightage[7];
   adjacent[6][5]= weightage[8];
   
   strcpy(path[0].pathc,"LHCC to MB via Main Gate to LHCB-Nescafe");
   path[0].weight=weightage[1]+weightage[3]+weightage[6];
   strcpy(path[1].pathc,"LHCC to GB via Reddy's Gate to MB-LHCB-Nescafe");
   path[1].weight=weightage[1]+weightage[3]+weightage[4] + weightage[7];
   cout<<"\n"<<path[1].weight;
   strcpy(path[2].pathc,"LHCC to GB through underpass to MB-LHCB-Nescafe");
   path[2].weight= weightage[1]+weightage[3]+weightage[4]+weightage[5]+weightage[8];  
   strcpy(path[3].pathc,"LHCC to MB via Main Gate to GB-Nandini-Nescafe");
   path[3].weight= weightage[0]+weightage[2]+weightage[7]; 
   strcpy(path[4].pathc,"LHCC to GB via Reddy's Gate to Nandini-Nescafe");
   path[4].weight= weightage[0]+weightage[2]+weightage[4] + weightage[6];
   strcpy(path[5].pathc,"LHCC to GB through underpass to Nandini Nescafe");
   path[5].weight= weightage[0]+weightage[2]+weightage[5] + weightage[8];
   float d_weight=dijkstra2(adjacent, 6);
   cout<<"\n d weigh="<<d_weight;
    cout<<"\n path weightage done";
   for(int k=0;k<v-1;k++){
    cout<<"\n"<<path[k].weight;
    cout<<"\n"<<d_weight;
     if(d_weight==path[k].weight)
      { 
        cout<<"\n optimal path : "<<path[k].pathc;
        break;
      }
    }
  }

  int main()
  {
   int n;
    do{
    cout<<"\n 1.ADMINISTRATOR"<<"\n 2.USER"<<"\n 0.QUIT";
    cin>>n;
    switch(n)
       {
       case 1:   int pass;
             cout<<"\n Enter password   :   ";
                 cin>>pass;
                 if(password ==pass)
                 admin();
               break;
        case 2:   int t;
		          cout<<"\n select\n1.East to West campus\n2.West to East campus";
				  cin>>t; 
		          int time;
                   cout<<"\n Enter time       :  ";
                   cin>>time;
                   switch(t){
		             case 1 :user1(time);
		                     break;
		            case 2 :user2(time);
		                    break;
		                }
                 break;
        default:   cout<<"\n Check your input :  ";
       }
    }while(n!= 0);
  }

