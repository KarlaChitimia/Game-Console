#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define up_arrow 72
#define down_arrow 80
#define left_arrow 75
#define right_arrow 77
#define enter_key 13

int da;
char apk[256];

int main()
{
    char q;
    int key = 1;

    printf("CONSOLE GAMES");
    printf("\n\n->Installed Games\n  Library\n  Statistics\n  Shut Down\n");

    while(1)
    {
        key = meniu1(key);
        if(key == -1)
            break;
    }

    system("cls");
    printf("   Are you sure wanna exit? \n\n");
}


void print_option(int key_press, int main_menu_key)
{
    switch(key_press)
    {

    case 1:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n->Installed Games\n  Library\n  Statistics\n  Shut Down\n");
        break;
    case 2:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Installed Games\n->Library\n  Statistics\n  Shut Down\n");
        break;
    case 3:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Installed Games\n  Library\n->Statistics\n  Shut Down\n");
        break;
    case 4:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Installed Games\n  Library\n  Statistics\n->Shut Down\n");
        break;


    }
}


int meniu1(int key)
{
    int stop = 0;
    char q;
    while(1)
    {
        q = getch();
        switch(q)
        {

        case up_arrow:
            if(key > 1)
                key --;
            print_option(key, 0);
            break;

        case down_arrow:
            if(key < 5)
                key ++;
            print_option(key, 0);
            break;

        case enter_key:
            if(key == 1)
            {
                system("cls");
                print5(1);

                while(1)
                {
                    key = meniu5(key);
                    if(key == -1)
                        break;
                }
            }
            if(key == 2)
            {
                system("cls");
                print3(1);

                while(1)
                {
                    key = meniu3(key);
                    if(key == -1)
                        break;
                }
            }
            if(key == 3)
            {
                Statistics();
            }

        case '\b':
            stop = 1;
            key = -1;
            break;
        }
        if(stop == 1)
        {
            return key;
        }
    }
}


void print2(int key, int option)
{
    int i = 1;
    char s[256], x[256];
    if(option == 1)
    {
        system("cls");
        printf("Installed Games\n\n");
        FILE *fo = fopen("Jocuri_Ordonate_Alfabetic.txt", "r");
        while(fgets(s, 200, fo))
        {

            FILE *fi = fopen("installed.txt", "r");
            while(fgets(x, 256, fi))
            {

                if(strstr(s,x)!= NULL)
                {

                    if(i == key)
                    {
                        strcpy(apk, x);

                        printf("->%s--->Size %d GB\n", x, dimensiune());
                        i++;
                    }
                    else
                    {
                        printf("  %s",x);
                        i++;
                    }
                }
            }
            fclose(fi);

        }

    }
    if(option == 2)
    {
        system("cls");
        printf("Installed Games\n\n");
        FILE *fo =  fopen("Jocuri_Ordonate_Crescator.txt", "r");
        while(fgets(s, 200, fo))
        {

            FILE *fi = fopen("installed.txt", "r");
            while(fgets(x, 256, fi))
            {

                if(strstr(s, x)!= NULL)
                {

                    if(i == key)
                    {
                        strcpy(apk, x);

                        printf("->%s--->Size %d GB\n", x, dimensiune());
                        i++;
                    }
                    else
                    {
                        printf("  %s", x);
                        i++;
                    }
                }
            }
            fclose(fi);

        }
    }
    if(option == 3)
    {
        system("cls");
        printf("Installed Games\n\n");
        FILE *fo = fopen("Jocuri_Ordonate_Descrescator.txt", "r");
        while(fgets(s, 200, fo))
        {

            FILE *fi = fopen("installed.txt", "r");
            while(fgets(x, 256, fi))
            {

                if(strstr(s, x)!= NULL)
                {

                    if(i == key)
                    {
                        strcpy(apk, x);

                        printf("->%s--->Size %d GB\n", x, dimensiune());
                        i++;
                    }
                    else
                    {
                        printf("  %s", x);
                        i++;
                    }
                }
            }
            fclose(fi);

        }
    }
    if(option == 4)
    {
        system("cls");
        printf("Installed Games\n\n");
        FILE *fo = fopen("Jocuri_Ordonate_iAlfabetic.txt", "r");
        while(fgets(s, 200, fo))
        {

            FILE *fi = fopen("installed.txt", "r");
            while(fgets(x, 256, fi))
            {

                if(strstr(s, x)!=NULL)
                {

                    if(i == key)
                    {
                        strcpy(apk, x);

                        printf("->%s--->Size %d GB\n", x, dimensiune());
                        i++;
                    }
                    else
                    {
                        printf("  %s", x);
                        i++;
                    }
                }
            }
            fclose(fi);

        }
    }

}




int meniu2(int key,int option )
{
    int stop = 0, nu;

    nu = no_game();
    key = 1;

    char q;
    while(1)
    {
        q = getch();
        switch(q)
        {

        case up_arrow:
            if(key > 1)
                key --;
            print2(key,option);
            break;

        case down_arrow:
            if(key < nu)
                key ++;
            print2(key,option);
            break;

        case enter_key:
        {
            system("cls");
            printf("Do you want to uninstall this game?");
            system("pause");
            uninstall(key);
        }

        break;

        case '\b':
            system("Cls");

            print5(1);

            while(1)
            {
                key = meniu5(key);
                if(key == -1)
                    break;
            }
            stop = 1;
            key = -1;
            break;
        }
        if(stop == 1)
        {
            return key;
        }
    }
}


void print3(int key)
{

    system("CLS");
    printf("AVAILABLE GAMES\n\n");
    FILE *meniu = fopen("Available games.txt", "r");

    int i = 1;
    char s[256];

    while(fgets(s, 256, meniu))
    {
        char *buffer = strtok(s, ",");

        if(i == key)
        {
            strcpy(apk,buffer);
            printf("->%s --> Size  %d GB\n", buffer,dimensiune());
        }
        else
            printf("  %s", buffer);
        i++;
    }

    fclose(meniu);
}


int meniu3(int key)
{
    int stop = 0;
    char q;

    key = 1;
    while(1)
    {
        q = getch();
        switch(q)
        {

        case up_arrow:
            if(key > 1)
                key--;
            print3(key);
            break;

        case down_arrow:
            if(key < 15)
                key++;
            print3(key);
            break;

        case enter_key:
        {
            system("cls");
            printf("Do you want to install this game?");
            system("pause");
            da=key;
            install();
        }

        break;

        case '\b':
            system("cls");
            printf("CONSOLE GAMES");
            printf("\n\n->Installed Games\n  Library\n  Statistics\n  Shut Down\n");

            while(1)
            {
                key = meniu1(key);
                if(key == -1)
                    break;
            }
            stop = 1;
            key = -1;
            break;
        }
        if(stop == 1)
        {
            return key;
        }
    }
}


void install()
{
    system("cls");
    int key = 1, ok = 1;

    FILE *meniu = fopen("Available games.txt", "r");

    int i = 1;
    char s[256], joc[256];

    while(fgets(s, 256, meniu))
    {
        char *buffer = strtok(s, ",");

        if(i == da)
        {
            strcpy(joc, buffer);
        }
        i++;
    }


    FILE *flv = fopen("GB.txt", "r");
    int n=0;
    fscanf(flv, "%d", &n);

    fclose(flv);
    strcpy(apk, joc);
    int x = dimensiune();
    n += x;
    if(n > 1024)
    {
        printf("Dimensiune depasita");
        system("pause");
        system("cls");
        print3(1);

        while(1)
        {
            key = meniu3(key);
            if(key == -1)
                break;
        }

        return 0;
    }
    else
    {
        FILE *plm = fopen("installed.txt","r");
        while(fgets(s, 256, plm))
        {
            if(strstr(joc, s) !=NULL)
                ok = 0;
        }
        if(ok == 1)
        {
            FILE *finst = fopen("installed.txt", "a");
            fprintf(finst, "%s", joc);
            fclose(finst);
        }
        else
        {
            system("cls");
            printf("App already installed\n\n\n");
            system("pause");
            print3(1);
            fclose(meniu);
            while(1)
            {
                key = meniu3(key);
                if(key == -1)
                    break;
            }
            return 0;
        }



        FILE *zumbra  = fopen("GB.txt", "w");
        fprintf(zumbra, "%d", n);
        fclose(zumbra);
        int nu = no_game();
        nu++;

        FILE *bau = fopen("no game.txt", "w");
        fprintf(bau, "%d", nu);
        fclose(bau);

        system("cls");
        printf("Installing the aplication. Please wait\n\n\n");
        Sleep(4000);
        printf("\n\n Game successfully installed\n\n");
        system("pause");

        system("cls");
        print3(1);

        while(1)
        {
            key = meniu3(key);
            if(key == -1)
                break;
        }

    }
}


int no_game()
{
    FILE *finst = fopen("no game.txt", "r");
    int nu;

    fscanf(finst, "%d", &nu);
    fclose(finst);

    return nu;
}


int dimensiune()
{
    int dim=0;

    if(strcmp(apk, "Red Dead Redemption\n") == 0)
        dim = 97;
    if(strcmp(apk, "Grand Theft Auto 5\n")==0)
        dim = 91;
    if(strcmp(apk, "Metal Gear Solid V: The Phantom Pain\n") == 0)
        dim = 50;
    if(strcmp(apk, "Celeste\n") == 0)
        dim = 76;
    if(strcmp(apk, "Resident Evil 2\n") == 0)
        dim = 63;
    if(strcmp(apk, "Inside\n") == 0)
        dim = 88;
    if(strcmp(apk, "Forza Horizon 4\n") == 0)
        dim = 101;
    if(strcmp(apk, "The Witcher 3: Wild Hunt\n") == 0)
        dim = 73;
    if(strcmp(apk, "Overwatch\n") == 0)
        dim = 33;
    if(strcmp(apk, "Yakuza 0\n") == 0)
        dim = 56;
    if(strcmp(apk, "Stardew Valley\n") == 0)
        dim = 20;
    if(strcmp(apk, "Injustice 2\n") == 0)
        dim = 33;
    if(strcmp(apk, "Fallout 4\n") == 0)
        dim = 78;
    if(strcmp(apk, "DOOM Eternal\n") == 0)
        dim = 104;
    if(strcmp(apk, "Apex Legends\n") == 0)
        dim = 84;
    return dim;
}


void uninstall(int key)
{
    FILE *f1 = fopen("installed.txt","r");
    FILE *f2 = fopen("installed2.txt","w");
    int i = 1;
    char s[256];

    while(fgets(s, 256, f1))
    {
        char *buffer = strtok(s, ",");

        if(i != key)
        {
            fprintf(f2,"%s", buffer);
        }
        else
            strcpy(apk, buffer);
        i++;
    }
    fclose(f1);
    fclose(f2);
    FILE *f3 = fopen("installed2.txt","r");
    FILE *f4 = fopen("installed.txt","w");
    while(fgets(s, 256, f3))
    {
        fprintf(f4, "%s", s);
    }
    fclose(f3);
    fclose(f4);

    FILE *p1 = fopen("no game.txt", "r");
    int no=0;

    fscanf(p1, "%d", &no);
    fclose(p1);

    no--;
    FILE *p2 = fopen("no game.txt", "w");
    fprintf(p2, "%d", no);
    fclose(p2);

    FILE *p3 = fopen("GB.txt","r");
    int n=0;
    fscanf(p3, "%d", &n);
    fclose(p3);
    n-=dimensiune();
    FILE *p4 = fopen("GB.txt", "w");
    fprintf(p4, "%d", n);
    fclose(p4);

    system("cls");
    printf("Uninstalling the app. Please wait...\n\n");
    Sleep(3000);
    system("cls");
    printf("App uninstalled succesfully\n\n");
    system("pause");

    system("cls");
    print_option(1, 0);

    while(1)
    {
        key = meniu1(key);
        if(key == -1)
            break;
    }


}


void Statistics()
{
    FILE *p3 = fopen("GB.txt","r");
    int n = 0;
    fscanf(p3, "%d", &n);
    fclose(p3);

    FILE *p1 = fopen("no game.txt", "r");
    int no = 0;

    fscanf(p1, "%d", &no);
    fclose(p1);

    system("Cls");

    printf("You have %d games intalled\n\n",no);
    printf("The total size is %d gigabytes\n\n",n);

    system("pause");
    system("cls");
    printf("CONSOLE GAMES");
    printf("\n\n->Installed Games\n  Library\n  Statistics\n  Shut Down\n");
    int key = 1;
    while(1)
    {
        key = meniu1(key);
        if(key == -1)
            break;
    }


}


void print5(int key_press)
{

    switch(key_press)
    {

    case 1:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n->Sort by name asc\n  Sort by size asc\n  Sort by size desc\n  Sort by name desc\n");
        break;
    case 2:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Sort by name asc\n->Sort by size asc\n  Sort by size desc\n  Sort by name desc\n");
        break;
    case 3:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Sort by name asc\n  Sort by size asc\n->Sort by size desc\n  Sort by name desc\n");
        break;
    case 4:
        system("cls");
        printf("CONSOLE GAMES");
        printf("\n\n  Sort by name asc\n  Sort by size asc\n  Sort by size desc\n->Sort by name desc\n");
        break;

    }


}


int meniu5(int key)
{
    int stop = 0, nu;
    key = 1;

    char q;
    while(1)
    {
        q = getch();
        switch(q)
        {

        case up_arrow:
            if(key > 1)
                key--;
            print5(key);
            break;

        case down_arrow:
            if(key < 4)
                key++;
            print5(key);
            break;

        case enter_key:
        {
            int option;
            option = key;

            system("cls");
            print2(1, option);

            while(1)
            {
                key = meniu2(key, option);
                if(key == -1)
                    break;
            }

        }

        break;

        case '\b':
            system("Cls");

            printf("CONSOLE GAMES");
            printf("\n\n->Installed Games\n  Library\n  Statistics\n  Shut Down\n");

            while(1)
            {
                key = meniu1(key);
                if(key == -1)
                    break;
            }
            stop = 1;
            key = -1;
            break;
        }
        if(stop == 1)
        {
            return key;
        }
    }
}
