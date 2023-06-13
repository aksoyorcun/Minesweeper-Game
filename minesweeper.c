#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SIZE 10 // Mayın Tarlasınının Boyutu 10x10
#define MINES 10 // Mayın Sayısını Temsil Eder 

int minessweeper[SIZE][SIZE]; // ANA TABLO
int BACKUP_minessweeper[SIZE][SIZE]; // ARAYÜZ TABLOSU
int FLAGS[SIZE][SIZE]; //Bayrak konumları
int remainingCells= (SIZE*SIZE)-MINES; //Kalan hücreler
int gameovertable[SIZE][SIZE]; 

void initializeGame()
{
    int i,j;
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            minessweeper[i][j] = 0;
            BACKUP_minessweeper[i][j]=0;
            FLAGS[i][j]=0;
        }
    }
}


void placeMines()
{
    int i,j,count=0;
    srand(time(0));
    while(count<MINES)
    {
        i = rand() % SIZE;  // i değeri 0-9 arasında rastgele atanır
        j = rand() % SIZE;  // j değeri 0-9 arasında rastgele atanır
        if(minessweeper[i][j] != -1)
        {
            minessweeper[i][j] = -1;
            count++;
        }
    }
}


void calculateNumbers()
{
    int i,j,count;
    for (i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE;j++)
        {
            if(minessweeper[i][j]==0)
            {
                count = 0;
                if(i>0 && j>0 && minessweeper[i-1][j-1]==-1)
                    count++;
                if(i>0 && minessweeper[i-1][j]==-1)
                    count++;
                if(i>0 && j<SIZE-1 && minessweeper[i-1][j+1]==-1)
                    count++;
                if(j<SIZE-1 && minessweeper[i][j+1] ==-1)
                    count++;
                if(j>0 && minessweeper[i][j-1] ==-1)
                    count++;
                if(i<SIZE-1 && j>0 && minessweeper[i+1][j-1]==-1)
                    count++;
                if(i<SIZE-1 && minessweeper[i+1][j]==-1)
                    count++;
                if(i<SIZE-1 && j<SIZE-1 && minessweeper[i+1][j+1]==-1)
                    count++;
                minessweeper[i][j] = count;
            }
        }
    }
}

void printTable()
{
    int i,j;
    printf("  ");
    for (i=0; i<SIZE; i++)
    {
        printf("%d ",i);  // X koordinatları tablonun üstüne bastırıldı.
    }
    printf("\n");

    for(i=0; i<SIZE; i++)
    {
        printf("%d ",i); // Y koordinatları tablonun sol kısmına bastırıldı.
        for(j=0; j<SIZE; j++)
        {
            if(BACKUP_minessweeper[i][j]==0)
            {
                printf(". "); // Başlangıç olarak tablonun her yeri . olarak gösterildi.
            }
            else if(FLAGS[i][j]==1)
            {
                printf("F "); //bayraklar gösterildi
            }
            else
            printf("%d ",minessweeper[i][j]); // Sayılar gösterildi.
        }
        printf("\n");
    }
}

void placeFlag(int i, int j)
{
    if(i<0 || j<0 || i>= SIZE || j>= SIZE)
        return;
    if(FLAGS[i][j]==0 && BACKUP_minessweeper[i][j]==0)
    {
        FLAGS[i][j] = 1;
        BACKUP_minessweeper[i][j] = 1;
    }
    else if(BACKUP_minessweeper[i][j]==1 && minessweeper[i][j]!=-1)
    {
        printf("You can not place flag where there is no bomb\n\n");
        return;
    }
    else
    {
        FLAGS[i][j] = 0;
        BACKUP_minessweeper[i][j] = 0;
    }

}


void selectedCell(int x, int y)
{
    if(x<0 || y<0 || x>= SIZE || y>= SIZE)
    return;
    if(BACKUP_minessweeper[x][y]==1)
    {
        return;
    }
        
    
    BACKUP_minessweeper[x][y]=1;
    remainingCells-=1;

    if (minessweeper[x][y] == 0) 
    {
        selectedCell(x-1 , y-1);
        selectedCell(x-1 , y);
        selectedCell(x-1 , y+1);
        selectedCell(x , y-1);
        selectedCell(x , y +1);
        selectedCell(x+1 , y-1);
        selectedCell(x+1 , y);
        selectedCell(x+1 , y+1);
    }
}

void gameOverTable()
{
    int i,j;
    printf("  ");
    for (i=0; i<SIZE; i++)
    {
        printf("%d ",i);  // X koordinatları tablonun üstüne bastırıldı.
    }
    printf("\n");

    for(i=0; i<SIZE; i++)
    {
        printf("%d ",i); // Y koordinatları tablonun sol kısmına bastırıldı.
        for(j=0; j<SIZE; j++)
        {
            if(BACKUP_minessweeper[i][j]==1)
            {
                printf("%d ",minessweeper[i][j]);
            }
            else if(BACKUP_minessweeper[i][j]==0)
            {
                if(minessweeper[i][j]==-1)
                {
                    printf("* ");
                }
                else
                {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}
            
                

int main()
{
    initializeGame();
    placeMines();
    calculateNumbers();
    time_t startTime = time(NULL);

    while(1)
    {
        printTable();
        int x,y;
        int choice;
        printf("Enter column and row : ");
        scanf("%d %d", &y, &x);
        printf("Enter 1 to place a flag, 0 to select\n ");
        scanf("%d", &choice);
        if(choice == 1)
        {
            placeFlag(x,y);
            continue;
        }

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) 
        {
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (minessweeper[x][y] == -1) 
        {
            gameOverTable();
            printf("Game over! You hit a mine.\n");
            break;
        }

        selectedCell(x,y);

        if(remainingCells == 0)
        {
            printf("Congratulations! You won the game!\n");
            break;
        } 

    }

        
    time_t endTime = time(NULL);
    double seconds = difftime(endTime, startTime);
    printf("You completed the game in %.2f seconds. \n", seconds);


}