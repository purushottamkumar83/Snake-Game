 #include<stdio.h>
 #include<conio.h>
 #include<stdlib.h>
 int height=20,width=20,score;
 int x,y,fruitX,fruitY,gameover,s;
 int ax[100],ay[100],tail=0;
 void get()
 {
 	score=0;
 	gameover=0;
 	x=height/2;
 	y=width/2;
 	step1:
	 fruitX=rand()%32;
 	if(fruitX==0)
 	goto step1;
 	step2:
 	fruitY=rand()%20;
 	if(fruitY==0)
	 goto step2;
 }
 void border()
 {
 	int i,j,k;
 	system("cls");
 	for(i=0;i<height;i++)
 	{
 		for(j=0;j<width;j++)
 		{
 			if(i==0||i==width-1||j==0||j==height-1)
 			{
 				printf("#");
			 }
 			else
 			{
			 if(i==x && j==y)
			 printf("O");
			 else if(i==fruitX && j==fruitY)
			 printf("+");
			 else
              {
                  int u=0;
                  for(k=0;k<tail;k++)
                  {
                      if(i==ax[k] && j==ay[k])
                    {
                    printf("*");
                    u=1;
                    }
                  }
                  if(u==0)
                  printf(" ");
		      }
 			}
 		}
            printf("\n");
    }
	     printf("SCORE=%d",score);
}
 void input()
 {
  if(kbhit())
  {
      switch(getch())
      {
      case 'a':
        s=1;
        break;
      case 'd':
          s=2;
          break;
      case 'w':
        s=3;
        break;
      case 'z':
        s=4;
        break;
      case 'x':
        gameover=1;
        break;
        }
  }
 }
 void move()
 {
     int bx,by,cx,cy,l;
     bx=ax[0];
     by=ay[0];
     ax[0]=x;
     ay[0]=y;
     for(l=1;l<tail;l++)
     {
         cx=ax[l];
         cy=ay[l];

         ax[l]=bx;
         ay[l]=by;
         bx=cx;
         by=cy;
     }
     switch(s)
     {
      case 1:
          y--;
          break;
      case 2:
          y++;
          break;
      case 3:
          x--;
          break;
      case 4:
          x++;
          break;
      default:
          break;
     }
        if(x<0||x>width||y<0||y>height)
        gameover=1;
        for(l=0;l<tail;l++)
        {
            if(x==ax[l] && y==ay[l])
                gameover=1;
        }
        if(x==fruitX&&y==fruitY)
        {
          step3:
	        fruitX=rand()%20;
 	        if(fruitX==0)
 	        goto step3;
          step4:
 	        fruitY=rand()%20;
 	        if(fruitY==0)
	        goto step4;
	        score+=10;
	        tail++;
        }
 }
 int main()
 {
    int m,n;
    char c;
    step5:
 	get();
 	while(!gameover)
    {
 	border();
 	input();
 	move();
 	for(m=0;m<1000;m++)
    {
        for(n=0;n<=10000;n++)
        {

        }
    }
    }
    printf("\n press y to continue again");
    scanf("%c",&c);
    if(c=='y'||c=='Y')
        goto step5;
 	return 0;
 }
