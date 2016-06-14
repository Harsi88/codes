#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct listl{
    char *s;
    struct listl *next;
}listl;


typedef struct ht {
    int size;       /* the size of the table */
    listl **tab; /* the table elements */
} ht;

//---------------------------------------------------

ht *myhtcreate(int size)
{
    ht *newht;
    int i;

    if (size<1) return NULL;

	// We try to allocate space for the table
    if ((newht = malloc(sizeof(ht))) == NULL) {
        return NULL;
    }

    // try to allocate memory for each table
    if ((newht->tab = malloc(sizeof(listl *) * size)) == NULL) {
        return NULL;
    }

    // Initialize the elements of th e table
    for(i=0; i<size; i++) newht->tab[i] = NULL;

    newht->size = size;

    return newht;
}

//-----------------------------------------------

unsigned int myhash(ht *myht, char *str)
{
    unsigned int hv;
    hv = 0;
    for(; *str != '\0'; str++) hv = *str + (hv << 5) - hv;
    return hv % myht->size;
}



//-------------------------------------------------



listl *mylookup(ht *myht, char *str)
    {
        listl *list;
        unsigned int hv = myhash(myht, str);

        for(list = myht->tab[hv]; list != NULL; list = list->next) {
            if (strcmp(str, list->s) == 0) return list;
        }
        return NULL;
  }

//----------------------------------------------

int myadd(ht *myht, char *str)
    {
        listl *newlist;
        listl *currlist;
        unsigned int hv = myhash(myht, str);

        if ((newlist = malloc(sizeof(listl))) == NULL) return -1;

        currlist = mylookup(myht, str);

        if (currlist != NULL) return 1; // item exists

        newlist->s = strdup(str);// effectively copies str to "S" field of the node in the list

        newlist->next = myht->tab[hv];
        return 0;
        myht->tab[hv] = newlist;
    }

//------------------------------------------------

void mydel(ht *myht)
    {
        int i;
        listl *mylist, *temp;

        if (myht==NULL) return;


        for(i=0; i<myht->size; i++) {
            mylist = myht->tab[i];
            while(mylist!=NULL) {
                temp = mylist;
                mylist = mylist->next;
                free(temp->s);
                free(temp);
            }
        }

        //deallocate the table also
        free(myht->tab);
        free(myht);
    }


//-----------------------------------------------



int main(int argc, char* argv[]){

char s[50],ss[50],ch[2];
unsigned int c,ctemp;
FILE *fp;
int i,count=0,tsize=0,addcode;

ht *myht;
listl *temp;


if(argc<2) {printf("Need the source file to build the table! Exiting!\n");return 0;}

if(argc>2) printf("Extra source file specified.. ignoring %s \n",argv[2]);

fp=fopen(argv[1],"r");
if(fp==NULL) {printf("Error opening target file %s! Exiting!!\n", argv[1]);return 0;}

printf("Enter the size of the table (10-100)\n");
scanf("%d",&tsize);

printf("Creating the table..\n");

myht=myhtcreate(tsize);


count=0;
while((c=getc(fp))!=EOF){

	if(isalpha(c)) {ss[count]=c;++count;}
	if(!isalpha(c) && count<1) count=0;
	if(!isalpha(c) && count>1){
				printf("Found -> '");
				for(i=0;i<count;i++){
					s[i]=tolower(ss[i]);
					printf("%c",s[i]);
					}
				s[count]='\0';
				count=0;

				addcode=myadd(myht,&s[0]);
				if(addcode==-1) return 0;
				if(addcode==0) printf("' & added!\n");
				if(addcode==1) printf("' & exists..\n");
				}
}

fclose(fp);

printf("Entire file has been parsed!\n\n");

ch[0]='y';

ctemp=getchar(); // to flush the input stream.

while(ch[0]=='y'){
	count=0;
	c=0;
	printf("Enter the string to search for (only alphabets)\n");
	while((c=getchar())!=10){
		printf("%d\n",c);
		if(isalpha(c)) s[count]=tolower(c);
		++count;
		}
	s[count]=0; // adding the nul character.
	if(count>1) { // only if the input word is more than one character
		temp=mylookup(myht,&s[0]);
		if(temp==NULL) printf("Does not exist..\n");
		else printf("Exists at %p\n",temp);
		}

	printf("More (y/n)\n");
	scanf("%s",ch);
	ctemp=getchar(); // to flush the input stream.

}


printf("Deleting the table.. before exit!\n");
mydel(myht);

return 0;

}


