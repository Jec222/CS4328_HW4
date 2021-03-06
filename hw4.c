#include<stdio.h>
#include <stdlib.h>

#define MAX_REFEREANCE_STRING 20

int LRU(int time[], int n);

int main(void)
{
    int no_of_frames, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);
	
	//printf("Enter number of pages: ");
	//scanf("%d", &no_of_pages);
	
	printf("Generating referance string ");
	
    for(i = 0; i < MAX_REFEREANCE_STRING; ++i)
	{
    	//scanf("%d", &pages[i]);
        pages[i] = rand()%5;

    }
	for(i = 0; i < no_of_frames; ++i)
	{
    	frames[i] = -1;
    }
    
    for(i = 0; i < MAX_REFEREANCE_STRING; ++i)
	{
    	flag1 = flag2 = 0;
    	
    	for(j = 0; j < no_of_frames; ++j)
		{
    		if(frames[j] == pages[i])
			{
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0)
		{
			for(j = 0; j < no_of_frames; ++j)
			{
	    		if(frames[j] == -1)
				{
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	
    	if(flag2 == 0)
		{
    		pos = LRU(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
    	
    	printf("\n");
    	
    	for(j = 0; j < no_of_frames; ++j)
		{
    		printf("%d\t", frames[j]);
    	}
	}
	
	printf("\n\nTotal Page Faults For LRU = %d", faults);

    int  temp[10],k,max,flag3;

    faults = 0;

    for(i = 0; i < no_of_frames; ++i)
	{
        frames[i] = -1;
    }
    
    for(i = 0; i < MAX_REFEREANCE_STRING; ++i)
	{
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j)
		{
            if(frames[j] == pages[i])
			{
                flag1 = flag2 = 1;
                break;
            }
        }
        
        if(flag1 == 0)
		{
            for(j = 0; j < no_of_frames; ++j)
			{
                if(frames[j] == -1)
				{
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0)
		{
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j)
			{
            	temp[j] = -1;
            	
            	for(k = i + 1; k < MAX_REFEREANCE_STRING; ++k)
				{
            		if(frames[j] == pages[k])
					{
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j)
			{
            	if(temp[j] == -1)
				{
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0)
			{
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j)
				{
            		if(temp[j] > max)
					{
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j)
		{
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults For OPT = %d", faults);
    
    return 0;
}
 
int LRU(int time[], int n)
{
	int i, minimum = time[0], pos = 0;
 
	for(i = 1; i < n; ++i)
    {
		if(time[i] < minimum)
        {
			minimum = time[i];
			pos = i;
		}
	}
	
	return pos;
}