#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct lista
{
    struct lista *ur,*an;
    char lit;
};
typedef struct lista lista;
void move(int n, int nr_carac,int *cursor_int,lista *cap,lista **cursor)
{   lista *p;
    int i,j;
    p=*cursor;
    if (((*cursor_int)+n)>=nr_carac)
        {
            for(i=*cursor_int;i<nr_carac-1;i++)
                    p=p->ur;                    // cazul in care depaseste la dreapta
            *cursor_int=nr_carac;
            *cursor=p;
        }

        else
            if((*cursor_int+n)<=0)
            {
                p=cap;
                *cursor_int=0;
                *cursor=p;              // cazul in care depaseste la stanga
            }


    if (((*cursor_int+n)<=nr_carac)&&(n>=0))
        {
            for(i=*cursor_int;i<n+*cursor_int;i++)
            p=p->ur;
            *cursor_int=*cursor_int+n;      //cazul in care mutam la dreapta si nu depaseste
            *cursor=p;
        }

            else
                {
                    if(((*cursor_int+n)>0)&&(n<=0))
                    {
                        for(i=*cursor_int;i>n+*cursor_int;i--)
                            p=p->an;                      //cazul in care mutam la stanga si nu depaseste
                        *cursor_int=*cursor_int+n;
                        *cursor=p;

                    }
                }

}
void insert(char string[30],int nr_carac,int cursor_int,lista **cap,lista **cursor)
{
    int i;
    lista *q,*p;

    p=(*cursor)->an;
    if(nr_carac==0)
        {
            p=(*cursor);
            p->lit=string[0];
            p->an=NULL;
            p->ur=NULL;
            *cap=p;
            for(i=1;i<strlen(string);i++)
                {
                    q=(lista*)malloc(sizeof(lista));
                    q->lit=string[i];
                    q->ur=NULL;
                    q->an=p;
                    p->ur=q;                            //cazul in care nu avem nimic in lista
                    nr_carac++;
                    p=q;
                }
            *cursor=p;
        }
        else
            if ((cursor_int>0)&&(cursor_int<nr_carac))
                {
                    for(i=0;i<strlen(string);i++)
                        {
                            q=(lista*)malloc(sizeof(lista));
                            q->lit=string[i];
                            p->ur->an=q;
                            q->ur=p->ur;
                            q->an=p;                    //cazul in care inseram la mijloc
                            p->ur=q;
                            nr_carac++;
                            p=q;

                        }

                }
       else
        if(cursor_int==nr_carac)
        {
            p=(*cursor);
            for(i=0;i<strlen(string);i++)
                {
                    q=(lista*)malloc(sizeof(lista));
                    q->lit=string[i];
                    q->ur=NULL;
                    q->an=p;
                    p->ur=q;                            //cazul in care inseram la sfarsit
                    nr_carac++;
                    p=q;
                }
            *cursor=p;

        }
           else
                if(cursor_int==0)
                    {
                    q=(lista*)malloc(sizeof(lista));
                    q->lit=string[0];
                    q->ur=*cap;
                    q->an=NULL;
                    (*cap)->an=q;          //am schimbat capul listei
                    (*cap)=q;
                    p=(*cursor)->an;
                    for(i=1;i<strlen(string);i++)
                        {
                            q=(lista*)malloc(sizeof(lista));
                            q->lit=string[i];
                            p->ur->an=q;
                            q->ur=p->ur;
                            q->an=p;
                            p->ur=q;
                            nr_carac++;
                            p=q;
                        }
                    }

}
void backspace(int *nr_carac,int *cursor_int,lista **cap,lista **cursor)
{
    lista *t;
    if ((*cursor_int>1)&&(*cursor_int<*nr_carac))
        {
            t=(*cursor)->an->an;
            t->ur=*cursor;
            (*cursor)->an=t;     /// la mijloc
            (*cursor_int)--;
            (*nr_carac)--;

        }
        else
            if(*cursor_int==*nr_carac)
                {
                    t=(*cursor)->an;
                    t->ur=NULL;
                    *cursor=t;             ///la sfarsit
                    (*cursor_int)--;
                    (*nr_carac)--;
                }
                    else
                        if(*cursor_int==1)
                        {
                            *cap=*cursor;               ///la inceput
                            (*cap)->an=NULL;

                        }
}
void del(int aux2,int *nr_carac,int *cursor_int,lista **cap,lista **cursor)
{
    int i;
    lista *p,*q;
 if((*cursor_int==0)&&(aux2<*nr_carac))
    {
        for(i=0;i<aux2;i++)
            {
                *cursor=(*cursor)->ur;
                (*cursor)->an=NULL;                 //cazul in care stergem la inceput si modificam capul
                *cap=*cursor;
            }
        (*nr_carac)=(*nr_carac)-aux2;
    }
    else
        if((*cursor_int==0)&&(aux2>=*nr_carac))
            {
                (*cap)->ur=NULL;                       //cazul in care stergem tot din lista
                (*nr_carac)=0;
            }
            else
                if ((*cursor_int>0)&&(*cursor_int<*nr_carac)&&(aux2<*nr_carac))
                    {
                        q=*cursor;
                        p=(*cursor)->an;
                        for(i=0;i<aux2;i++,q=q->ur);
                        p->ur=q;
                        q->an=p;         //cazul in care ne aflam la mijloc si fara elementul final
                        *cursor=q;
                        (*nr_carac)=(*nr_carac)-aux2;
                    }
                    else
                        if((*cursor_int>0)&&(*cursor_int<*nr_carac)&&(aux2>*nr_carac))
                            {
                                (*cursor)=(*cursor)->an;
                                (*cursor)->ur=NULL;
                                *nr_carac=*cursor_int;
                            }
}
void copy(int aux3,int *nr_carac,int *cursor_int,lista **cap,lista **cursor,lista **cap2)
{
    lista *p,*q,*r;
    int i;
    if((*cursor_int>=0)&&(*cursor_int<*nr_carac))
    {
        p=*cursor;
        q=(lista*)malloc(sizeof(lista));
        q->ur=NULL;
        q->an=NULL;
        q->lit=p->lit;
        *cap2=q;
        i++;
        for(i=1,p=(*cursor)->ur;(i<aux3)&&(p!=NULL);i++,p=p->ur)
            {
                r=(lista*)malloc(sizeof(lista));
                r->ur=NULL;
                q->ur=r;
                r->an=q;
                r->lit=p->lit;
                q=r;
            }
    }
}
void undo(char ult_op[15],int *nr_carac,int *cursor_int,lista **cap,lista **cursor,int aux,char string[30],char ajut,char *pastee,lista **cap3,int aux2)
{
    int i,j,nr=1;
    lista *p,*q;
    char *sirajut,g;
    if(strcmp("move",ult_op)==0)
        move(-aux,*nr_carac,cursor_int,*cap,cursor);
    if(strcmp("insert",ult_op)==0)
        for(i=0;i<strlen(string);i++)
            backspace(nr_carac,cursor_int,cap,cursor);
    if(strcmp("paste",ult_op)==0)
        for(i=0;i<strlen(pastee);i++)
            backspace(nr_carac,cursor_int,cap,cursor);
    if(strcmp("del",ult_op)==0)
        {
            sirajut = (char*)malloc (nr * sizeof (char));
            q=*cap3;
            for(j=0;(j<aux2)&&(q!=NULL);j++)
                {
                    sirajut = (char*)realloc (sirajut,nr++);
                    g=(q->lit);
                    sirajut[j]=g;                      //am bagat intr un sir de caractere ce am de copiat si m-am folosit de insert
                    q=q->ur;
                }
            sirajut[j]='\0';
            insert(sirajut,*nr_carac,*cursor_int,cap,cursor);
            (*nr_carac)=(*nr_carac)+strlen(sirajut);
            for(i=0;i<strlen(sirajut);i++)(*cursor)=(*cursor)->an;
        }
    if(strcmp("backspace",ult_op)==0)
        {
            if ((*cursor_int>0)&&(*cursor_int<*nr_carac))
                {
                    p=(*cursor)->an;
                    q=(lista*)malloc(sizeof(lista));
                    q->lit=ajut;
                    p->ur->an=q;
                    q->ur=p->ur;
                    q->an=p;
                    p->ur=q;
                    (*nr_carac)++;
                    p=q;
                }
            else
                if(*cursor_int==*nr_carac)
                {
                    p=*cursor;
                    q=(lista*)malloc(sizeof(lista));
                    q->lit=ajut;
                    q->ur=NULL;
                    q->an=p;
                    p->ur=q;
                    (*nr_carac)++;
                    p=q;
                }
                *cursor=p->ur;
                (*cursor_int)++;
        }
}
void redo(char ult_op[15],char penult_op[15],int *nr_carac,int *cursor_int,lista **cap,lista **cursor,char string[30],int aux,int aux2)
{
 if(strcmp("undo",ult_op)==0)
    {
    if(strcmp("insert",penult_op)==0)
        {
            insert(string,*nr_carac,*cursor_int,cap,cursor);
            *cursor_int=*cursor_int+strlen(string);
            *nr_carac=*nr_carac+strlen(string);
        }
    if(strcmp("move",penult_op)==0)
        move(aux,*nr_carac,cursor_int,*cap,cursor);
    if(strcmp("backspace",penult_op)==0)
        backspace(nr_carac,cursor_int,cap,cursor);
    if(strcmp("del",penult_op)==0)
        {
         move(-aux2,*nr_carac,cursor_int,*cap,cursor);
         del(aux2,nr_carac,cursor_int,cap,cursor);
        }
    }
}
void main(int argc,char *argv[])
{
    FILE *date,*operatii,*rezultate;
    lista *p,*q,*cap,*cursor,*cap2,*cap3;
    char car,g,ajut,op[15],ult_op[15],penult_op[15],string[30],*pastee;
    int i,j,nr_op,aux,aux2,aux3,nr=1,caract=1;
    int nr_carac=0,cursor_int=0,nr_carac2=0;

    p=(lista*)malloc(sizeof(lista));
        if((date=fopen(argv[1],"r"))==NULL);
            fscanf(date,"%c",&p->lit);
            p->ur=NULL;
            p->an=NULL;
            cap=p;
            car=p->lit;
            nr_carac++;
    while(fscanf(date,"%c",&car)==1)
        {
            q=(lista*)malloc(sizeof(lista));
            q->ur=NULL;
            p->ur=q;
            q->an=p;      // programul baga caracter cu caracter in lista
            q->lit=car;
            nr_carac++;
            p=q;
        }
    fclose(date);
    if((operatii=fopen(argv[2],"r"))==NULL);
    fscanf(operatii,"%d",&nr_op);
    p=cap;
    cursor=cap;
    for(i=1;i<=nr_op;i++)
    {
        fscanf(operatii,"%s",op);
        if(strcmp("move",op)==0)
            {
                fscanf(operatii,"%d",&aux);
                if((cursor_int==nr_carac)&&(aux<0))
                            {
                                cursor=cap;
                                cursor_int=0;                                         // am intampinat o problema cand ma aflam cu cursorul  pe ultima
                                move (nr_carac+aux,nr_carac,&cursor_int,cap,&cursor);   // pozitie asa ca in loc sa mut;a stanga cu 5 am resetat cursorul
                            }                                                               // la cap si am mutat la dreapta cu nr_caractere -5 :)
                    else
                        move(aux,nr_carac,&cursor_int,cap,&cursor);
            }
        if(strcmp("insert",op)==0)
            {
                fscanf(operatii,"%s",string);
                insert(string,nr_carac,cursor_int,&cap,&cursor);
                cursor_int=cursor_int+strlen(string);
                nr_carac=nr_carac+strlen(string);
            }
        if(strcmp("del",op)==0)
            {
                fscanf(operatii,"%d",&aux2);
                copy(aux2,&nr_carac,&cursor_int,&cap,&cursor,&cap3);
                del(aux2,&nr_carac,&cursor_int,&cap,&cursor);
            }
        if(strcmp("copy",op)==0)
            {
                fscanf(operatii,"%d",&aux3);
                copy(aux3,&nr_carac,&cursor_int,&cap,&cursor,&cap2);
            }
        if(strcmp("paste",op)==0)
       {
            pastee = (char*)malloc (nr * sizeof (char));
            q=cap2;
            for(j=0;(j<aux3)&&(q!=NULL);j++)
                {
                    pastee = (char*)realloc (pastee,nr++);
                    g=(q->lit);
                    pastee[j]=g;                      //am bagat intr un sir de caractere ce am de copiat si m-am folosit de insert
                    q=q->ur;
                }
            pastee[j]='\0';
            insert(pastee,nr_carac,cursor_int,&cap,&cursor);
            cursor_int=cursor_int+aux3;
            nr_carac=nr_carac+aux3;
       }
        if(strcmp("backspace",op)==0)
            {
                if(cursor_int==nr_carac) ajut=cursor->lit;
                    else ajut=(cursor->an)->lit;
                backspace(&nr_carac,&cursor_int,&cap,&cursor);
            }

        if(strcmp("undo",op)==0)
                {
                undo(ult_op,&nr_carac,&cursor_int,&cap,&cursor,aux,string,ajut,pastee,&cap3,aux2);
                strcpy(penult_op,ult_op);
                }
        if(strcmp("redo",op)==0) redo(ult_op,penult_op,&nr_carac,&cursor_int,&cap,&cursor,string,aux,aux2);
        strcpy(ult_op,op);
    }
    fclose(operatii);
    if((rezultate=fopen(argv[3],"w"))==NULL);
    for(p=cap,i=0;(p!=NULL)&&(i<nr_carac);p=p->ur,i++)
        fprintf(rezultate,"%c",p->lit);
    fclose(rezultate);
    free(p);
    free(q);
    free(cap);
    free(cursor);
}
